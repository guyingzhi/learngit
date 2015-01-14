#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include "sys/socket.h"
#include "netinet/in.h"
#include "netinet/tcp.h"
#include "netdb.h"
#include "ck_xycl.h"

#define	VERSION		"V20141030 -SG"

void *f_monitor_recv_thread(void *pvParam);
void *f_thread_listen_mngr(void *pvParam);
void *f_thread_timer(void *pvParam);
void *f_thread_recv_mngr(void *pvParam);
void f_get_log_info();


//xycl_redis_info lxycl_redis;

main(int argc, char *argv[])
{
    int  li_i, li_j, li_k, li_m;
    char  ls_str[256] = {0};
    pthread_t  hThread;
    char  *inifile = INIFILE;

    if (f_system_init()<0)
        exit(0);

    /*if (f_monitor_start(argc,argv,ls_str)==-1)
    {
    	printf("%s",ls_str);
    	f_exit();
    }*/
    strcpy(gs_cxbh,argv[1]);
    strcat(gs_filecache,gs_cxbh);
    strcat(gs_filecache,"/");

    strcpy(gs_version,VERSION);
    for (li_i = 0; li_i < MAX_LOG_TERM; li_i++)
    {
        gi_logterm_arr[li_i] = 0;
    }
    gi_save_log = 0;
    gi_save_data = 0;    
    f_get_log_info();
    
    gi_mngr_socket_listen = -1;
    pthread_mutex_init(&g_mngr_mux_accept,NULL);

    /* 创建定时器线程 */
    li_i = pthread_create(&hThread ,NULL ,f_thread_timer ,NULL);
    if(li_i != 0)
    {
        if(gi_save_log)
            tracelog("创建线程f_thread_timer失败!");
        exit(0);
    }
    pthread_detach(hThread);

    /* 创建调度程序监听线程 */
    li_i = pthread_create(&hThread ,NULL ,f_thread_listen_mngr ,NULL);
    if(li_i != 0)
    {
        if(gi_save_log)
            tracelog("创建线程f_thread_listen_mngr失败!");
        exit(0);
    }
    pthread_detach(hThread);

   /*redis 初始化接口*/
    redis_colony_init();/* redis非阻塞连接， ai_type对应redis_type 0 文件队列，1 共享数据缓存区；as_dbbh ini字段名字；ai_num 连接通道数量*/
    sleep(3);
    /*redis队列虚拟key创建*/
    creat_virtaul_key(DN_450, 0);/*创建虚拟队列key值*/
    creat_virtaul_key(UP_450, 0);/*创建虚拟队列key值*/

    lbrget_rdlist(DN_450, 0, 5, encode_main, 1);/* 阻塞接收list数据函数*/

    if(gi_save_log)
        tracelog("服务正常启动--%s,版本 %s",gs_cxbh,gs_version);

    sleep(5);
    f_monitor_heartbeat();
}


void f_exit()
{
	int		li_i;


//	db_disconnect(DB_CJ);


	if (gi_mngr_socket_listen!=-1)
	{
		close(gi_mngr_socket_listen);
		gi_mngr_socket_listen = -1;
	}

	/* 关闭和调度服务之间的连接 */
	for (li_i=0;li_i<gi_mngr_conn_max;li_i++)
	{
		if ((gst_mngr_conn+li_i)->enabled)
		{
			close((gst_mngr_conn+li_i)->fileno);
			pthread_mutex_destroy(&((gst_mngr_conn+li_i)->mutx));
		}
	}

	pthread_mutex_destroy(&g_mngr_mux_accept);
//	pthread_mutex_destroy(&g_queue_in);
//	pthread_mutex_destroy(&g_queue_out);

	if(gi_save_log)
		tracelog("程序正常退出 %s",gs_cxbh);

	f_monitor_end();
	f_system_end();

	exit(0);
}


void *f_thread_timer(void *pvParam)
{
	int			li_i,li_n;
	char		ls_str[256] = {0};

	/* 下面作为定时器线程 */
	do
	{
		sleep(60);

		f_get_datetime(&gdt_now);
        //tracelog("gi_recindex = %d",gi_recindex);
        //tracelog("gi_recnum = %d",gi_recnum);




	}while(1);

	f_exit();
}

void f_get_log_info()
{
    char ls_tmp[1000]={0},ls_termadd[32]={0};
    char *p , *ls_n;
    int li_n,li_m,li_x,li_i;
    if (getiniinfo(INIFILE,"local_info","trace_errorlog",ls_tmp)>=0)
    {
        if (isnum(ls_tmp))
        {
            gi_save_log = atoi(ls_tmp);
        }
    }

    if (getiniinfo(INIFILE,"local_info","data_errorlog",ls_tmp)>=0)
    {
        if (isnum(ls_tmp))
        {
            gi_save_data = atoi(ls_tmp);
        }
    }

    if (getiniinfo(INIFILE,"local_info","log_term",ls_tmp)>=0)
    {
	p = ls_tmp;
        li_m = 0;
        li_x = 0;
        li_n = strlen(p);
        while (li_n > li_m)
	{
            ls_n = strstr(p,",");
            li_i = ls_n - p;
            li_m += li_i;
            memcpy(ls_termadd, p, li_i);
            ls_termadd[li_i] = 0;
            if (isnum(ls_termadd))
            {
                gi_logterm_arr[li_x] =  atoi(ls_termadd);
            }
            else
            {
                break;
            }
            li_x++;
            p = ls_n + 1;
            li_m++;
	}
    }
}

void *f_thread_listen_mngr(void *pvParam)
{
	int		li_i,li_fileno,li_port,li_len,li_re,li_n,li_m,li_x;
	char		ls_str[32]={0},ls_tmp[256]={0},ls_termadd[32]={0};
	char       *p, *ls_n;
	pthread_t	hThread;
	struct sockaddr_in	sin;

	sprintf(ls_str,"local_%s",gs_cxbh);

	if (getiniinfo(INIFILE,ls_str,"mngr_listen_port",ls_tmp)<0)
	{
		if(gi_save_log)
			tracelog("取监听端口失败");
		return;
	}
	li_port = atoi(ls_tmp);

	if (socket_tcp_listen(&gi_mngr_socket_listen,"all",li_port,ls_tmp)<0)
	{
		if(gi_save_log)
			tracelog("监听启动失败: %s",ls_tmp);
		return;
	}

	do
	{
		li_len = sizeof(sin);
		memset((char *)&sin, 0, li_len);

		if ((li_fileno = accept(gi_mngr_socket_listen,(struct sockaddr *)&sin,&li_len))<0)
		{
			if(gi_save_log)
				tracelog("调度程序连接时发生错误,返回%d，errno=%d : %s",li_fileno,errno,strerror(errno));
			sleep(60);
			continue;
		}

		pthread_mutex_lock(&g_mngr_mux_accept);

		for (li_i=0;li_i<gi_mngr_conn_max;li_i++)
			if (gst_mngr_conn[li_i].enabled==0)
				break;

		if (li_i==gi_mngr_conn_max)
			if (gi_mngr_conn_max>=MAX_MNGR_CONNECT)
			{
				if(gi_save_log)
					tracelog("连接数组溢出，最大 %d",gi_mngr_conn_max);
				li_i = 0;
			}
			else
				gi_mngr_conn_max++;

		gst_mngr_conn[li_i].enabled	= 1;
		gst_mngr_conn[li_i].fileno	= li_fileno;


		/* 调度连接成功，创建一个线程 */
		li_re = pthread_create(&hThread ,NULL ,f_thread_recv_mngr ,&li_i);
		if (li_re != 0)
		{
			gst_mngr_conn[li_i].enabled	= 0;
			close(li_fileno);
			pthread_mutex_unlock(&g_mngr_mux_accept);
			if(gi_save_log)
				tracelog("创建线程f_thread_recv_mngr失败,返回 %d",li_re);
			continue;
		}

		pthread_detach(hThread);
		if(gi_save_log)
			tracelog("接受调度程序连接,线程 %lu,fileno %d,地址 %d.%d.%d.%d",hThread,li_fileno,(sin.sin_addr.s_addr & 0xFF),(sin.sin_addr.s_addr & 0xFF00)>>8,(sin.sin_addr.s_addr & 0xFF0000)>>16,(sin.sin_addr.s_addr & 0xFF000000)>>24);

		pthread_mutex_lock(&g_mngr_mux_accept);		/* 阻塞，等待数据接收线程内部解锁 */
		pthread_mutex_unlock(&g_mngr_mux_accept);

	} while(1);
}



/*void f_process_nmgy(char *as_data,int ai_len)
{
    tracelog("f_process_nmgy!!!!");
	int		li_i;
	uchar	*p;
	str_frame lstr_frame;

	p = as_data;	// 规约数据


	if ((li_i = get_frame_struct(&lstr_frame,p))!=1)
	{
		tracelog("解析规约错误，返回 %d",li_i);
		return;
	}
    tracelog("lstr_frame.afn = %d,lstr_frame.gylx = %d",lstr_frame.afn,lstr_frame.gylx);
	switch(lstr_frame.afn)
	{
		case 0x05:
		case 0x09:
		case 0x0A:
		case 0x0C:
		case 0x0D:
		case 0x0E:
			decode_report(&lstr_frame);	// 解码处理
			break;
        case 0x00:
		case 0x0F:
            break;
		default:
			datalog("未定义的AFN类型",&lstr_frame);
			break;
	}
}*/


///* 处理队列中的数据 */
/*void *f_thread_queue_process(void *pvParam)
{
	int		li_j, li_count, li_res;
	char 	ls_str[255];
	char 	ls_value[1][RDS_QUEUE_ELEMENT_LEN]={0};

    li_j = *((int *)pvParam);
    pthread_mutex_unlock(&g_queue_thread);

	do
	{
		/* 出队，处理 */
/*		li_res = brpop_rdvalue(lxycl_redis.lstr_redis.connectinfo[li_j].rediscontext, "00_xycl_q", 5, (char **)ls_value, RDS_QUEUE_ELEMENT_LEN, &li_count);

             DEBUG("normal queue!\n");
		
		//解析
//        f_sendto_mngr(ls_value[1], strlen(ls_value[1]));
        memset(ls_value[0],0,strlen(ls_value[0]));


//        gc_queueout_type = 1;
//        //所有下行报文处理
//        f_process_myreport(ls_data, li_len);

	}while (1);
}*/

///* 处理队列中的数据 */
/*void *f_thread_queue_process_green(void *pvParam)
{
	int  li_res, li_j, li_count;
	char  ls_value[1][RDS_QUEUE_ELEMENT_LEN]={0};
	int  li_m;

	li_j = *((int *)pvParam);
	pthread_mutex_unlock(&g_queue_thread_green);	
	do
	{
		/* 出队，处理 */
/*		li_res = brpop_rdvalue(lxycl_redis.lstr_redis.connectinfo[li_j].rediscontext, DN_Q_HIGH_9, 5, (char **)ls_value, RDS_QUEUE_ELEMENT_LEN, &li_count);
		if (li_res < 0) {
			DEBUG("nothing have in redis, timeout!\n");
			continue;
		}
		li_m = strlen(ls_value[0]);
		if(li_m > 0) {
			/*f_process_recv_data(ls_value[0], &li_m, encode_main);
			memset(ls_value[0], 0, RDS_QUEUE_ELEMENT_LEN);*/

/*			encode_main(ls_value[0], li_m);
		}
	
	}while (1);
}*/

/* 接收调度程序发送过来的数据 */
void *f_thread_recv_mngr(void *pvParam)
{
	int	li_p,li_n,li_max=0;
	char	ls_data[FRAME_MAXLEN*6]={0},ls_str[FRAME_MAXLEN]={0};
	st_conn	*lst_conn;

	li_p = *(int *)pvParam;

	pthread_mutex_unlock(&g_mngr_mux_accept);

	lst_conn = &gst_mngr_conn[li_p];

	f_get_datetime(&(lst_conn->ljsj));
	pthread_mutex_init(&(lst_conn->mutx),NULL);
	lst_conn->isbusy	= 0;
	lst_conn->recvll	= 0;
	lst_conn->sendll	= 0;
	lst_conn->recvbw	= 0;
	lst_conn->sendbw	= 0;
	lst_conn->enabled	= 1;

	set_socket_buffer(lst_conn->fileno,1024*1024,1024*1024);
	set_tcp_timeout(lst_conn->fileno,7200,10,3);
	DEBUG("manage connect OK!\n");

	while(1)
	{
		/* 必须有，否则接收会延迟，不知为什么????? */
		/*printf("\n");*/
		//tracelog("recv阻塞等待有数据发送过来");

		/* 阻塞等待有数据发送过来，返回0表示连接中断 */
		if ((li_n = recv(lst_conn->fileno, ls_str, FRAME_MAXLEN, 0))<=0)		/* 连接中断 */
		{
			lst_conn->enabled = 0;

			if (li_n==-1){
				if(gi_save_log)
					tracelog("调度连接中断,返回 %d,errno=%d : %s",li_n,errno,strerror(errno));
			} else {
				if(gi_save_log)
					tracelog("调度连接中断,返回 %d",li_n);
			}
			close(lst_conn->fileno);
			lst_conn->fileno = -1;					/* 防止在其它地方非法关闭 */
			pthread_mutex_destroy(&(lst_conn->mutx));
			break;		/* 退出本线程 */
		}
		
		lst_conn->recvll += li_n;  //接收字节数

		/* 数据放入处理缓冲区 */
		if ((li_max + li_n) <= FRAME_MAXLEN*6){
			memcpy(ls_data+li_max, ls_str, li_n);
			li_max += li_n;
		} else {
			if (gi_save_log)
				tracelog("f_thread_recv_mngr recv buf is full!lose frame:%s", ls_str);
		}	

		DEBUG("\n\n######## RECV %02d-%02d-%02d %02d:%02d:%02d##########\n", gdt_now.year-100, gdt_now.mon, gdt_now.day, gdt_now.hour,  gdt_now.min, gdt_now.sec);
		DEBUG("%s\n", ls_str);
		//先解包
		li_n = f_process_recv_data(ls_data, &li_max, f_mngr_process);

		lst_conn->recvbw += li_n;  //解码报文数
	}
}


/*调度发来的报文处理*/
void f_mngr_process(char *as_data,int ai_len)
{
	int		li_ywbsm;
	char		ls_tmp[32]={0};

	if (gi_save_log)
    		tracelog("上行协议处理recv frame = %s ", as_data);

	memcpy(ls_tmp,as_data+16,6);  //取业务标识码
	ls_tmp[6] = 0;
	li_ywbsm  = atoi(ls_tmp);
	DEBUG("li_ywbsm = %d\n",li_ywbsm);
	switch (li_ywbsm){
		case 30:		/* 000030 调试程序查询某个应用程序信息 */
			/* 000030|任务编号|1|程序编号(Web)|要查询的应用程序编号|查询命令字符串| */
/*			p = as_data + 16;
			memcpy(ls_data,as_data,16+30);
			msg_get_field(p,5,ls_cmd);
			sprintf(ls_data+16+30,"%s|",ls_cmd);
			f_debug_process(ls_cmd,ls_data+strlen(ls_data));
			*/
			//f_debug_process(as_data,ai_len);
			break;
		case 100:		/* 000100 发送文件*/
//			f_process_000100(as_data + 16,ai_len);
			break;
		
		case 101:		/*000101前置服务向协议处理服务发送规约报文	*/
			f_process_000101(as_data + 16, ai_len);
			break;
		case 102:		/* 000102 调度服务向数据处理服务发送规约 */
			/*f_process_000102(as_data + 16,ai_len);*/
			break;
		case 110:  //规约透传
           		break;
        	case 200:  /*服务间心跳报文*/
        		f_process_000200(as_data + 16, ai_len);
           		break;
           	case 201:  /*终端在线状态变化通知  */
           		f_process_000201(as_data + 16, ai_len);
           		break;
		case 100401:	/* 终端事件召测 */
			break;
		case 100202:	/* 采集点曲线数据召测 */
		case 100203:	/* 总加组曲线召测 */
		case 100204:	/* 模拟量曲线数据召测 */

		case 200101:	/* 终端参数设置	*/
		case 200102:	/* 测量点参数设置 */
		case 200103:	/* 总加组参数设置 */
		case 200104:	/* 模拟量参数设置 */
		case 200105:	/* 控制轮次参数设置 */
		case 200106:	/* 任务参数设置 */
		case 200121:
		case 200122:
		case 200123:
		case 200124:
		case 200125:
		case 200126:
		case 300121:
//        case 300122:
//        case 300123:
		case 400201:
		case 400202:
		case 400221:
        /*case 400222:*/
//			queue_in(as_data+16,ai_len ,1);		/* 入队处理，类型为内部规约 */
			break;

		case 100101:
		case 100102:
//	    case 100103:
//	    case 100104:
//            f_get_SSSJ_report(as_data + 16,  ai_len);
			break;

		case 100301:	/* 终端冻结数据召测	*/
		case 100302:	/* 测量点冻结数据召测 */
		case 100303:	/* 总加组冻结数据召测 */
		case 100304:	/* 模拟量冻结数据召测 */
//            f_get_DJSJ_report(as_data + 16, ai_len);
			break;

		case 200201:
		case 200202:
		case 200203:
//        case 200204:
//        case 200205:
		case 200206:
//            f_get_CSZC_report(as_data + 16, ai_len);
			break;
		case 300101:	/* 终端控制 */
//		case 300102:	/* 电表控制 */
//		case 300103:	/* 总加组控制 */
//            f_get_KZ_report(as_data + 16, ai_len);
			break;
		case 300203:
//            f_process_300203(as_data, ai_len);
			break;
		case 400101:
//            f_process_400101(as_data, ai_len);
			break;
		case 400102:
//            f_process_400102(as_data, ai_len);
			break;
		case 400103:
//            f_process_400103(as_data, ai_len);
			break;
		case 400104:
//            f_process_400104(as_data, ai_len);
			break;
		case 400301:
//            f_process_400301(as_data, ai_len);
			break;
		default:
			if (gi_save_log)
				tracelog("接收调度业务标识码错误：%06d", li_ywbsm);
			break;
	}
}


///* 接收文件 */
//void f(char *as_data,int ai_len)
//{
//	char	*p,*msg[16],ls_file[256]={0};
//	int		li_i,li_len,li_n,li_replace;
//
//	p = as_data;
//
///* 000100|任务编号|1|程序编号|文件名|文件总长度|本数据包长度|文件总发包数|本次发包序号(0开始计数)|本包数据内容(相对于位置偏移量为100字节，即数据内容是从第100个字节开始的，前面部分无效) */
//
//	if (msg_get_array(p,msg,9)<0)
//		return;
//
//	li_len	= atoi(msg[6]);
//
//	if (atoi(msg[8])==0)		/* 第一个数据包，建立新文件 */
//		li_replace = 1;
//	else
//		li_replace = 0;
//
//	sprintf(ls_file,"%s%s",gs_filecache,msg[4]);
//
//	li_n = f_file_write(ls_file,p+100,li_len,li_replace);
//
//	if (li_n<0)
//	{
//		tracelog("第 %s 帧写入文件 %s 失败,总帧数 %s,总长度 %s",msg[8],msg[4],msg[7],msg[5]);
//	}
//	else if (li_n == atoi(msg[5]))
//	{
//		/* 文件发送完成 */
//	}
//
//	msg_free_array(msg);
//}
//
//

///* 入队操作
//



//	as_data		入队的数据
//	ai_len		入队的数据长度
//	ac_sjlx		入队的数据类型	1 内部报文	2 内蒙规约报文
//
// */
//int queue_in(char *as_data,int ai_len,char ac_sjlx)
//{
//	int		li_num;
//
//	if (ai_len<=0)
//		return 0;
//
//	li_num = (ai_len+2+INT_LEN) / QUEUE_UNIT_LEN;
//
//	if (((ai_len+2+INT_LEN) % QUEUE_UNIT_LEN) != 0)
//		li_num++;
//
//	pthread_mutex_lock(&g_queue_in);
//
//	if ((gi_queue_max+li_num)>MAX_QUEUE_UNIT)	/* 超出队列长度 */
//	{
//		gs_queue[gi_queue_max][0] = 0;								/* 空数据 */
//		gs_queue[gi_queue_max][1] = MAX_QUEUE_UNIT - gi_queue_max;	/* 空闲的单元个数 */
//
//		tracelog("数据处理队列满,开始循环，队列尾空闲 %d 个单元",MAX_QUEUE_UNIT - gi_queue_max);
//
//		gi_queue_max = 0;
//	}
//
//	gs_queue[gi_queue_max][0] = ac_sjlx;	/* 非0表示有数据在队列中,并标识出类型，为0时表示已处理完成 */
//	gs_queue[gi_queue_max][1] = li_num;		/* 本任务数据占用的队列单元数 */
//	memcpy(gs_queue[gi_queue_max]+2,(char*)&ai_len,INT_LEN);	/* 任务数据长度 */
//	memcpy(gs_queue[gi_queue_max]+2+INT_LEN,as_data,ai_len);			/* 任务数据 */
//
//	gi_queue_max += li_num;
//
//	if (gi_queue_max>=MAX_QUEUE_UNIT)
//		gi_queue_max = 0;
//
//	gi_queue_in_num++;		/* 统计总入队数量 */
//
//	pthread_mutex_unlock(&g_queue_in);
//
//	return 1;
//}
//
//
///* 数据出队操作 */
//int queue_out(char **as_data)
//{
//	int		li_len,li_max;
//	uchar	*p;
//
//	li_max = gi_queue_max;
//
//	do
//	{
//		if (gi_queue_p == li_max)		/*队列为空*/
//			return 0;
//
//		p = gs_queue[gi_queue_p];
//
//		if (p[0] == 0)			/* 空数据体，一般在队列末尾出现 */
//		{
//			if ((gi_queue_p = gi_queue_p + p[1]) >= MAX_QUEUE_UNIT);	/* 指向下一个数据体 */
//				gi_queue_p = 0;
//
//			continue;
//		}
//
//		*as_data = p;
//
//		if ((gi_queue_p = gi_queue_p + p[1]) >= MAX_QUEUE_UNIT)	/* 指向下一个数据体 */
//		{
//			gi_queue_p = 0;
//			tracelog("queue end");
//		}
//		gi_queue_out_num++;		/* 统计总出队数量 */
//
//		memcpy(&li_len,p+2,INT_LEN);
//
//		return li_len;
//
//	}while(1);
//
//	return 0;
//}


/* 获取一个调度的空闲连接 */
st_conn *f_get_conn_mngr()
{
	int		li_max,li_p;

	/* 查询一个空闲的连接 */
	li_max	= gi_mngr_conn_max;
	li_p	= gi_mngr_conn_p;

    if (li_max<=0)
	{	
		if(gi_save_log)
			tracelog("无连接的调度程序");
		return NULL;
	}

	for (;li_p<li_max;li_p++)
		if ((gst_mngr_conn+li_p)->enabled==1 && (gst_mngr_conn+li_p)->isbusy==0)
			break;

	if (li_p==li_max)
		for (li_p=0;li_p<li_max;li_p++)
			if ((gst_mngr_conn+li_p)->enabled==1 && (gst_mngr_conn+li_p)->isbusy==0)
				break;

	if (li_p==li_max)
		for (li_p=0;li_p<li_max;li_p++)
			if ((gst_mngr_conn+li_p)->enabled==1)
				break;

	if (li_p==li_max || li_max==0)
	{
		if(gi_save_log)
			tracelog("调度服务连接中断");
		return NULL;
	}

	gi_mngr_conn_p = (li_p + 1) % li_max;

	return gst_mngr_conn+li_p;
}


int f_sendto_mngr(char *as_data,int ai_len)
{
	int		li_re;
	char	ls_error[256]={0};
	st_conn	*lst_conn;
	int li_i;

	//printf("%s\n",as_data);
	//printf("\n\n\n");

	/* 查询一个空闲的连接 */
	if ((lst_conn=f_get_conn_mngr())==NULL)
		return -1;
	lst_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_conn->mutx));

	li_re = socket_tcp_send(lst_conn->fileno,as_data,ai_len,ls_error);

	if (li_re==1)
	{
		lst_conn->sendll += ai_len;
		lst_conn->sendbw++;
	}
	else
	{
		if(gi_save_log)
			tracelog("转发数据给调度服务发生错误: %s",ls_error);
	}
	lst_conn->isbusy = 0;

	pthread_mutex_unlock(&(lst_conn->mutx));

	return li_re;
}


int f_send_gy(uchar *as_data,int ai_len)
{
	int		li_i;
	uchar	ls_send_data[1024*65]={0};
	char	ls_tmp[32]={0};

/*	000103|任务编号|1|程序编号|规约类型|终端规约报文内容 */

	strcpy(ls_send_data,"#^&!12345678#^&!");

	f_get_xh(ls_tmp);
	sprintf(ls_send_data+16,"000103|%s|1|%s|1|",ls_tmp,gs_cxbh);		/* 共28字节 */

	li_i = 28 + ai_len ;	/* 数据内容的总长度 */
	sprintf(ls_tmp,"%08d",li_i);
	memcpy(ls_send_data+4,ls_tmp,8);
	memcpy(ls_send_data+16+28,as_data,ai_len);
	sprintf(ls_send_data+16+li_i,"%c*^!#",check_crc(ls_send_data+16,li_i));

	if (f_sendto_mngr(ls_send_data,li_i+21)<0)
	{
		if(gi_save_log)
			tracelog("报文发送给调度失败");
		return -1;
	}

	return 1;
}

int f_sendto_sjcl(char *file_in, int error_flag)
{	
	int ret;
	//存文件
/*	if (error_flag == ERROR_SUCCESS){
		ret = write_file(file_in->name, file_in);
		if (ret < 0){
			DEBUG("write file error = %d\n", ret);
		}
	}
*/

	//发送给REDIS
	//lpush_rdlist(UP_Q_HIGH_9, 1, file_in->info);
//	lpush_rdlist(UP_Q_HIGH_9, 1, recv_buf);

}

#if 0
/* 调试命令处理 */
void f_debug_process(char *as_cmd,char *as_data)
{
	int		li_i,li_n,li_ywbsm,li_m;
	int		li_sendbw,li_recvbw,li_sendll,li_recvll,li_zxsj;
	char	ls_tmp[256]={0},ls_catstr[1000]={0};
	str_frame lstr_frame;



	as_data[0] = 0;


	if (strncmp(as_cmd,"cmd_manager",11)==0)	/* 查询调度连接信息 */
    {
        li_n = 0;
        li_sendbw = li_recvbw = li_sendll = li_recvll = 0 ;
        for (li_i=0;li_i<gi_mngr_conn_max;li_i++)
            if ((gst_mngr_conn+li_i)->enabled)
            {
                li_n++;
                li_sendbw	+= (gst_mngr_conn+li_i)->sendbw;
                li_recvbw	+= (gst_mngr_conn+li_i)->recvbw;
                li_sendll	+= (gst_mngr_conn+li_i)->sendll;
                li_recvll	+= (gst_mngr_conn+li_i)->recvll;
                sprintf(ls_catstr,"调度连接通道 %3d,%04d-%02d-%02d %02d:%02d:%02d 连接,",li_n,(gst_mngr_conn+li_i)->ljsj.year+1900,(gst_mngr_conn+li_i)->ljsj.mon,(gst_mngr_conn+li_i)->ljsj.day,(gst_mngr_conn+li_i)->ljsj.hour,(gst_mngr_conn+li_i)->ljsj.min,(gst_mngr_conn+li_i)->ljsj.sec);
                strcat(as_data,ls_catstr);
                sprintf(ls_catstr,"发送报文数%10d,流量%10d,	接收报文数%10d,流量%10d\n",(gst_mngr_conn+li_i)->sendbw,(gst_mngr_conn+li_i)->sendll,(gst_mngr_conn+li_i)->recvbw,(gst_mngr_conn+li_i)->recvll);
                strcat(as_data,ls_catstr);
            }

        if (li_n<=0)
            strcat(as_data,"调度程序未连接\n");
        else
        {
            sprintf(ls_catstr,"\n调度程序通道合计：发送报文数%12d,流量%12d,	接收报文数%12d,流量%12d\n",li_sendbw,li_sendll,li_recvbw,li_recvll);
            strcat(as_data,ls_catstr);
        }
    }
    else if (strncmp(as_cmd,"cmd_queue",9)==0)	/* 查询队列使用情况 */
    {
//        sprintf(ls_catstr,"从 %04d-%02d-%02d %02d:%02d:%02d 到现在,队列使用情况如下：\n",gdt_start_datetime.year+1900,gdt_start_datetime.mon,gdt_start_datetime.day,gdt_start_datetime.hour,gdt_start_datetime.min,gdt_start_datetime.sec);
//        strcat(as_data,ls_catstr);
//        sprintf(ls_catstr,"队列最大单元数为 %10d, 每个单元长度为 %d\n",MAX_QUEUE_UNIT,QUEUE_UNIT_LEN);
//        strcat(as_data,ls_catstr);
//        sprintf(ls_catstr,"已使用的最大下标 %10d, 当前使用的下标 %d\n",gi_queue_max,gi_queue_p);
//        strcat(as_data,ls_catstr);
//        sprintf(ls_catstr,"累计总入队次数为 %10d, 总出队次数为   %d\n",gi_queue_in_num,gi_queue_out_num);
//        strcat(as_data,ls_catstr);
//        sprintf(ls_catstr,"last queue type: %d \n",gc_queueout_type);
//        strcat(as_data,ls_catstr);
//        if (gc_queueout_type == 1)
//        {
//        	gs_queueout_buf[gi_queueout_len] = 0;
//        	sprintf(ls_catstr,"last queue type: %s \n",gs_queueout_buf);
//        	strcat(as_data,ls_catstr);
//		}
//        if (gc_queueout_type == 2)
//        {
//			if ((li_m = get_frame_struct(&lstr_frame,gs_queueout_buf)) != 1)
//			{
//				tracelog("decode last queue out error:%d",li_m);
//			}
//			else
//			{
//				datalog("last queue out data:",&lstr_frame);
//			}
//		}
    }
    else if (strncmp(as_cmd,"cmd_test",8)==0)	/* 测试 */
    {

    }

}

#endif



