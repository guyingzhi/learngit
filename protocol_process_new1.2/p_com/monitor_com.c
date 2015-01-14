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

char	gs_monitor_nbbs[20];			/* �ػ�������ڲ���ʶ�� */
int		gi_monitor_socket;				/* �ػ����������Socket�� */
int		gi_monitor_port;				/* �ػ�����ļ����˿� */


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
		sprintf(as_error,"\nδ������������!\n\n");
		return -1;
	}

	strcpy(gs_cxbh,argv[1]);
	gi_monitor_port = atoi(argv[2]);

	f_str_decode(argv[3],ls_str);
	f_str_cracked(ls_str,ls_tmp);
	strcpy(gs_monitor_nbbs,ls_tmp);	

	
	/* �����ػ����������߳�,�������ػ������͵����� */ 
	
	lsize = 1024 * 1024 * 2;
	pthread_attr_init(&lattr);  
	pthread_attr_setstacksize(&lattr,lsize); 	/* �趨ÿ��ջ��СΪ2M */

	li_i = pthread_create(&hThread ,&lattr ,f_monitor_recv_thread ,NULL);
	if(li_i != 0)
	{
		pthread_attr_destroy(&lattr);
		sprintf(as_error,"�����߳�f_monitor_recv_threadʧ��!");
		return -1;
	}
	pthread_detach(hThread);
	
	pthread_attr_destroy(&lattr);
	
	return 1;
}


/* �ػ����������ά���߳� */
void f_monitor_heartbeat()
{
	int		li_i;
	char	ls_tmp[32],ls_data[256];

 	do
	{
		sleep(60);

		/* ���ػ�������������Ϣ 000002|������|1|������|�����ڲ���ʶ| */

		if (gi_monitor_socket != -1)
		{
			f_get_xh(ls_tmp);
			sprintf(ls_data,"#^&!12345678#^&!000002|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
			li_i = strlen(ls_data+16);		/* �������ݵ��ܳ��� */
			sprintf(ls_tmp,"%08d",li_i);
			memcpy(ls_data+4,ls_tmp,8);
			sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

			socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
		}

	}while(1);

}

/* ���ػ����������� */
void f_send_monitor_heartbeat()
{
	int		li_i;
	char	ls_tmp[32],ls_data[256];

	/* ���ػ�������������Ϣ 000002|������|1|������|�����ڲ���ʶ| */

	if (gi_monitor_socket != -1)
	{
		f_get_xh(ls_tmp);
		sprintf(ls_data,"#^&!12345678#^&!000002|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
		li_i = strlen(ls_data+16);		/* �������ݵ��ܳ��� */
		sprintf(ls_tmp,"%08d",li_i);
		memcpy(ls_data+4,ls_tmp,8);
		sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

		socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
	}
}

/* �رպ��ػ�����֮������� */
void f_monitor_end()
{
	if (gi_monitor_socket!=-1)
	{
		close(gi_monitor_socket);
		gi_monitor_socket = -1;
	}
}



/* �ػ��������ݴ��� */
void f_monitor_process(char *as_data,int ai_len)
{
	int		li_i,li_n,li_ywbsm;
	char	*p,ls_data[1024*128],ls_tmp[256],ls_cmd[64];

	p = as_data + 16;

	li_ywbsm = atoi(p);

	switch (li_ywbsm)
	{
		case 3:		/* �ػ�������Ӧ�ó���ѯ��״̬ */
		{
			/* 000002|������|1|������|�����ڲ���ʶ|Ӧ�ó�����| 
				����������Ϣ�ظ�
			*/

			if (gi_monitor_socket != -1)
			{
				f_get_xh(ls_tmp);
				sprintf(ls_data,"#^&!12345678#^&!000002|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
				li_i = strlen(ls_data+16);		/* �������ݵ��ܳ��� */
				sprintf(ls_tmp,"%08d",li_i);
				memcpy(ls_data+4,ls_tmp,8);
				sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

				socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
			}

			break;
		}
		case 4:		/* �˳�Ӧ�ó��� */
		{
			/* �յ���000004|������|1|������|�����ڲ���ʶ|Ӧ�ó�����|
			   �ظ���000004|������|1|������|�����ڲ���ʶ| */

			if (gi_monitor_socket != -1)
			{
				f_get_xh(ls_tmp);
				sprintf(ls_data,"#^&!12345678#^&!000004|%s|1|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs);
				li_i = strlen(ls_data+16);		/* �������ݵ��ܳ��� */
				sprintf(ls_tmp,"%08d",li_i);
				memcpy(ls_data+4,ls_tmp,8);
				sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));

				socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp);
			}

			sleep(2);

			f_exit();

			break;
		}
		case 22:	/* �ػ������ѯ��Ӧ�ó������ϸ��Ϣ */
		{
			/* �յ���000022|������|1|������|�����ڲ���ʶ|Ҫ��ѯ��Ӧ�ó�����|�ڲ�����|�����г��������Socket��|
			   �ظ���000022|������|1|������|�����ڲ���ʶ|�����г��������Socket��|Ӧ�ó��򷵻ص���Ϣ����| */

		
			memcpy(ls_data,as_data,16+22);
			
			msg_get_field(p,6,ls_cmd);		/* �ڲ����� */
			msg_get_field(p,7,ls_tmp);		/* �����г��������Socket�� */
			
			sprintf(ls_data+16+22,"%s|%s|%s|",gs_cxbh,gs_monitor_nbbs,ls_tmp);


			/* ���þ��庯��������Ҫ���ص����� */
			
			//f_debug_process(ls_cmd,ls_data+strlen(ls_data));
		
			strcat(ls_data,"|");
			li_i = strlen(ls_data+16);		/* ���������ܳ��� */
			sprintf(ls_tmp,"%08d",li_i);
			memcpy(ls_data+4,ls_tmp,8);
			sprintf(ls_data+16+li_i,"%c*^!#",check_crc(ls_data+16,li_i));
		
			if (socket_tcp_send(gi_monitor_socket,ls_data,li_i+21,ls_tmp)<0)
			{
				//if(gi_save_log)
					tracelog("000022 �������ݸ��ػ�����������: %s",ls_tmp);
			}
			break;
		}
	}
}


/* �����ػ������͹��������� */
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
				tracelog("�����ػ�����ʧ�� %s",ls_str);
			sleep(30);
			continue;
		}

		set_socket_buffer(gi_monitor_socket,1024*4,1024*1024);
		set_tcp_timeout(gi_monitor_socket,600,5,3);	/* ����TCP��ʱ��⣬��ʱʱ��Ϊ2Сʱ */


		/* ���͵�¼��Ϣ 000001|������|1|������|�����ڲ���ʶ|����汾��Ϣ| */
		
		strcpy(ls_data,"#^&!12345678#^&!");
		f_get_xh(ls_tmp);
		sprintf(ls_data+16,"000001|%s|1|%s|%s|%s|",ls_tmp,gs_cxbh,gs_monitor_nbbs,gs_version);
		li_n = strlen(ls_data+16);	/* �������ݵ��ܳ��� */
		sprintf(ls_tmp,"%08d",li_n);
		memcpy(ls_data+4,ls_tmp,8);
		sprintf(ls_data+16+li_n,"%c*^!#",check_crc(ls_data+16,li_n));

		if (socket_tcp_send(gi_monitor_socket,ls_data,li_n+21,ls_str)<0)
		{
			//if(gi_save_log)
				tracelog("���ػ������͵�¼��Ϣ���󣬳����˳�: %s",ls_str);
			f_exit();
		}

		li_max = 0;
		do
		{
	 	 	 printf("\n");

			/* �����ȴ������ݷ��͹���������0��ʾ�����ж� */
			if ((li_n = recv(gi_monitor_socket,ls_str,1024,0))<=0)	/* �����ж� */
			{
				if (li_n==-1){
					//if(gi_save_log)
						tracelog("�ػ����������ж�,����%d,errno=%d : %s",li_n,errno,strerror(errno));
				} else {
					//if(gi_save_log)
						tracelog("�ػ����������ж�,����%d",li_n);
				}
				close(gi_monitor_socket);
				gi_monitor_socket = -1;

				sleep(30);
				break;
			}

			/* ���ݷ��봦������ */
			memcpy(ls_data+li_max,ls_str,li_n);
			li_max += li_n;

			/* ���洦����յ������� */

			li_n = f_process_recv_data(ls_data,&li_max,f_monitor_process);

		} while(1);

	} while(1);	
}


