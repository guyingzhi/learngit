#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include "sys/socket.h"
#include "netinet/in.h"
#include "netinet/tcp.h"
#include "netdb.h"
#include "common.h"

char	gs_monitor_nbbs[20];			/* 守护程序的内部标识码 */
int		gi_monitor_socket;				/* 守护程序的连接Socket号 */
int		gi_monitor_port;				/* 守护程序的监听端口 */


void *f_monitor_recv_thread(void *pvParam);
void  f_monitor_process(char *as_data,int ai_len);


int f_monitor_start(int argc,char *argv[],char *as_error)
{
	int			li_i;
	char		ls_str[256],ls_tmp[256],ls_data[256];
	pthread_t	hThread;
	pthread_attr_t 		lattr;
	size_t 				lsize;

	as_error[0] = 0;
	
	gi_monitor_socket = -1;
	
	if (argc<=3)
	{
		sprintf(as_error,"\n未设置启动参数!\n\n");
		return -1;
	}

	strcpy(gs_cxbh,argv[1]);
	gi_monitor_port = atoi(argv[2]);

	f_str_decode(argv[3],ls_str);
	f_str_cracked(ls_str,ls_tmp);
	strcpy(gs_monitor_nbbs,ls_tmp);	

	
	/* 创建守护程序连接线程,并接收守护程序发送的数据 */ 
	
	lsize = 1024 * 1024 * 2;
	pthread_attr_init(&lattr);  
	pthread_attr_setstacksize(&lattr,lsize); 	/* 设定每个栈大小为2M */

	li_i = pthread_create(&hThread ,&lattr ,f_monitor_recv_thread ,NULL);
	if(li_i != 0)
	{
		pthread_attr_destroy(&lattr);
		sprintf(as_error,"创建线程f_monitor_recv_thread失败!");
		return -1;
	}
	pthread_detach(hThread);
	
	pthread_attr_destroy(&lattr);
	
	return 1;
}


/* 守护程序的心跳维持线程 */
void f_monitor_heartbeat()
{
	int		li_i;
	char	ls_tmp[32],ls_data[256];

 	do
	{
		sleep(60);

		/* 向守护程序发送心跳信息 000002|任务编号|1|程序编号|程序内部标识| */

		if (gi_monitor_socket != -1)
		{
			f_get_xh(ls_tmp);
			sprintf(ls_data,"#^&!12345678#^&!000002|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
			li_i = strlen(ls_data+16);		/* 数据内容的总长度 */
			sprintf(ls_tmp,"%08d",li_i);
			memcpy(ls_data+4,ls_tmp,8);
			sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

			socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
		}

	}while(1);

}

/* 向守护程序发送心跳 */
void f_send_monitor_heartbeat()
{
	int		li_i;
	char	ls_tmp[32],ls_data[256];

	/* 向守护程序发送心跳信息 000002|任务编号|1|程序编号|程序内部标识| */

	if (gi_monitor_socket != -1)
	{
		f_get_xh(ls_tmp);
		sprintf(ls_data,"#^&!12345678#^&!000002|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
		li_i = strlen(ls_data+16);		/* 数据内容的总长度 */
		sprintf(ls_tmp,"%08d",li_i);
		memcpy(ls_data+4,ls_tmp,8);
		sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

		socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
	}
}

/* 关闭和守护程序之间的连接 */
void f_monitor_end()
{
	if (gi_monitor_socket!=-1)
	{
		close(gi_monitor_socket);
		gi_monitor_socket = -1;
	}
}



/* 守护程序数据处理 */
void f_monitor_process(char *as_data,int ai_len)
{
	int		li_i,li_n,li_ywbsm;
	char	*p,ls_data[1024*128],ls_tmp[256],ls_cmd[64];

	p = as_data + 16;

	li_ywbsm = atoi(p);

	switch (li_ywbsm)
	{
		case 3:		/* 守护程序向应用程序询问状态 */
		{
			/* 000002|任务编号|1|程序编号|程序内部标识|应用程序编号| 
				发送心跳信息回复
			*/

			if (gi_monitor_socket != -1)
			{
				f_get_xh(ls_tmp);
				sprintf(ls_data,"#^&!12345678#^&!000002|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
				li_i = strlen(ls_data+16);		/* 数据内容的总长度 */
				sprintf(ls_tmp,"%08d",li_i);
				memcpy(ls_data+4,ls_tmp,8);
				sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

				socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
			}

			break;
		}
		case 4:		/* 退出应用程序 */
		{
			/* 收到：000004|任务编号|1|程序编号|程序内部标识|应用程序编号|
			   回复：000004|任务编号|1|程序编号|程序内部标识| */

			if (gi_monitor_socket != -1)
			{
				f_get_xh(ls_tmp);
				sprintf(ls_data,"#^&!12345678#^&!000004|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
				li_i = strlen(ls_data+16);		/* 数据内容的总长度 */
				sprintf(ls_tmp,"%08d",li_i);
				memcpy(ls_data+4,ls_tmp,8);
				sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

				socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
			}

			sleep(2);

			f_exit();

			break;
		}
		case 22:	/* 守护程序查询本应用程序的详细信息 */
		{
			/* 收到：000022|任务编号|1|程序编号|程序内部标识|要查询的应用程序编号|内部命令|命令行程序的连接Socket号|
			   回复：000022|任务编号|1|程序编号|程序内部标识|命令行程序的连接Socket号|应用程序返回的信息内容| */

		
			memcpy(ls_data,as_data,16+22);
			
			msg_get_field(p,6,ls_cmd);		/* 内部命令 */
			msg_get_field(p,7,ls_tmp);		/* 命令行程序的连接Socket号 */
			
			sprintf(ls_data+16+22,"%s|%s|%s|",gs_cxbh,gs_monitor_nbbs,ls_tmp);


			/* 调用具体函数，生成要返回的数据 */
			
			//f_debug_process(ls_cmd,ls_data+strlen(ls_data));
		
			strcat(ls_data,"|");
			li_i = strlen(ls_data+16);		/* 数据内容总长度 */
			sprintf(ls_tmp,"%08d",li_i);
			memcpy(ls_data+4,ls_tmp,8);
			sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));
		
			if (socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp)<0)
			{
				//if(gi_save_log)
					tracelog("000022 发送数据给守护程序发生错误: %s",ls_tmp);
			}
			break;
		}
	}
}


/* 接收守护程序发送过来的数据 */
void *f_monitor_recv_thread(void *pvParam)
{
	int		li_n,li_max;
	char	ls_data[1024*16],ls_str[1024],ls_tmp[32];
	
	
	sleep(2);
	
	do
	{
		if (socket_tcp_connect(&gi_monitor_socket,"all",gi_monitor_port,ls_str) < 0)
		{
			gi_monitor_socket = -1;
			//if(gi_save_log)
				tracelog("连接守护程序失败 %s",ls_str);
			sleep(30);
			continue;
		}

		set_socket_buffer(gi_monitor_socket,1024*4,1024*1024);
		set_tcp_timeout(gi_monitor_socket,600,5,3);	/* 设置TCP超时检测，超时时间为2小时 */


		/* 发送登录信息 000001|任务编号|1|程序编号|程序内部标识|程序版本信息| */
		
		strcpy(ls_data,"#^&!12345678#^&!");
		f_get_xh(ls_tmp);
		sprintf(ls_data+16,"000001|%s|1|%s|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs,gs_version);
		li_n = strlen(ls_data+16);	/* 数据内容的总长度 */
		sprintf(ls_tmp,"%08d",li_n);
		memcpy(ls_data+4,ls_tmp,8);
		sprintf(ls_data+16+li_n,"%c*^!#",check_crc(ls_data+16,li_n));

		if (socket_tcp_send(gi_monitor_socket,ls_data,li_n+21,ls_str)<0)
		{
			//if(gi_save_log)
				tracelog("向守护程序发送登录信息错误，程序退出: %s",ls_str);
			f_exit();
		}

		li_max = 0;
		do
		{
	 	 	 printf("\n");

			/* 阻塞等待有数据发送过来，返回0表示连接中断 */
			if ((li_n = recv(gi_monitor_socket,ls_str,1024,0))<=0)	/* 连接中断 */
			{
				if (li_n==-1){
					//if(gi_save_log)
						tracelog("守护程序连接中断,返回%d,errno=%d : %s",li_n,errno,strerror(errno));
				} else {
					//if(gi_save_log)
						tracelog("守护程序连接中断,返回%d",li_n);
				}
				close(gi_monitor_socket);
				gi_monitor_socket = -1;

				sleep(30);
				break;
			}

			/* 数据放入处理缓冲区 */
			memcpy(ls_data+li_max,ls_str,li_n);
			li_max += li_n;

			/* 下面处理接收到的数据 */

			li_n = f_process_recv_data(ls_data,&li_max,f_monitor_process);

		} while(1);

	} while(1);	
}


