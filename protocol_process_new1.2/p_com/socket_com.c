/* 2010-01-18 wanghd */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include "sys/socket.h"
#include "netinet/in.h"
#include "netinet/tcp.h"
#include "netdb.h"
#include "common.h"


/* 启动 TCP 服务端监听 */
int socket_tcp_listen(int *ai_socket,char *as_ip,int ai_port,char *as_error)
{
	int		li_socket,li_port,li_i,li_re;
	char	ls_ip[32];
	struct sockaddr_in	sin;


	as_error[0] = 0;
	strcpy(ls_ip,as_ip);
	strupper(ls_ip);

	if ((li_socket = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		sprintf(as_error,"获取SOCKET号失败,返回 %d %s",li_socket,strerror(errno));
		return -1;
	}

	li_port = ai_port;
	if (li_port<=0 || li_port>=65535)
	{
		sprintf(as_error,"监听端口范围错误 %d",li_port);
		return -1;
	}

	bzero(&sin,sizeof(struct sockaddr_in)); 

	sin.sin_family = AF_INET;
	sin.sin_port = htons(li_port);
	
	if (strncmp(ls_ip,"ALL",3)==0)		/* 监听所有IP */
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	else								/* 监听指定IP */
		sin.sin_addr.s_addr = inet_addr(ls_ip);

	li_i = 1;
	if ((li_re=setsockopt(li_socket,SOL_SOCKET,SO_REUSEADDR,(void*)&li_i,sizeof(li_i)))< 0)
	{
		sprintf(as_error,"在SOCKET上设置 SO_REUSEADDR  失败，返回 %d %s",li_re,strerror(errno));
		return -1;
	}

	if((li_re=bind(li_socket,(struct sockaddr *)&sin,sizeof(sin)))<0)
	{
		sprintf(as_error,"绑定监听地址错误,IP %s Port %d,返回 %d %s",ls_ip,li_port,li_re,strerror(errno));
		return -1;
	}

	if((li_re=listen(li_socket,20))<0)
	{
		sprintf(as_error,"启动监听失败,IP %s Port %d,返回 %d %s",ls_ip,li_port,li_re,strerror(errno));
		return -1;
	}
	
	*ai_socket = li_socket;

	return 1;
}

/* 启动 UDP 服务端监听 */
int socket_udp_listen(int *ai_socket,char *as_ip,int ai_port,char *as_error)
{
	int		li_socket,li_port,li_i,li_re;
	char	ls_ip[32];
	struct sockaddr_in	sin;


	as_error[0] = 0;
	strcpy(ls_ip,as_ip);
	strupper(ls_ip);
	
	if ((li_socket = socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		sprintf(as_error,"获取SOCKET号失败,返回 %d %s",li_socket,strerror(errno));
		return -1;
	}

	li_port = ai_port;
	if (li_port<=0 || li_port>=65535)
	{
		sprintf(as_error,"监听端口范围错误 %d",li_port);
		return -1;
	}

	bzero(&sin,sizeof(struct sockaddr_in)); 

	sin.sin_family = AF_INET;
	sin.sin_port = htons(li_port);

	if (strncmp(ls_ip,"ALL",3)==0)		/* 监听所有IP */
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	else								/* 监听指定IP */
		sin.sin_addr.s_addr = inet_addr(ls_ip);

	li_i = 1;
	if ((li_re=setsockopt(li_socket,SOL_SOCKET,SO_REUSEADDR,(void*)&li_i,sizeof(li_i)))< 0)
	{
		sprintf(as_error,"在SOCKET上设置 SO_REUSEADDR  失败，返回 %d %s",li_re,strerror(errno));
		return -1;
	}

	if((li_re=bind(li_socket,(struct sockaddr *)&sin,sizeof(sin)))<0)
	{
		sprintf(as_error,"绑定监听地址错误,IP %s Port %d,返回 %d %s",ls_ip,li_port,li_re,strerror(errno));
		return -1;
	}

	*ai_socket = li_socket;

	return 1;
}


/* TCP 客户端连接 */
int socket_tcp_connect(int *ai_socket,char *as_ip,int ai_port,char *as_error)
{
	int		li_socket,li_port,li_re;
	char	ls_ip[32];
	struct sockaddr_in	sin;

	as_error[0] = 0;
	strcpy(ls_ip,as_ip);
	strupper(ls_ip);

	if ((li_socket = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		sprintf(as_error,"获取SOCKET号失败,返回 %d %s",li_socket,strerror(errno));
		return -1;
	}

	li_port = ai_port;
	if (li_port<=0 || li_port>=65535)
	{
		sprintf(as_error,"监听端口范围错误 %d",li_port);
		close(li_socket);
		return -1;
	}

	bzero(&sin,sizeof(sin));

	if (strncmp(ls_ip,"ALL",3)==0)		/* 所有IP */
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	else								/* 指定IP */
		sin.sin_addr.s_addr = inet_addr(ls_ip);

	sin.sin_family = AF_INET;
	sin.sin_port = htons(li_port);

	if((li_re=connect(li_socket,(struct sockaddr*)&sin,sizeof(sin)))<0)
	{
		sprintf(as_error,"连接服务器 IP=%s Port=%d 失败,返回 %d %s",ls_ip,li_port,li_re,strerror(errno));
		close(li_socket);
		return -1;
	}

	*ai_socket = li_socket;

	return 1;
}


/************ TCP 数据发送 ***************

	返回：	 1	发送成功
			-1	发送失败
*/
int socket_tcp_send(int ai_socket,char *as_data,int ai_len,char *as_error)
{
	int		li_re,li_send=0,li_n=0;
	
	as_error[0] = 0;

	if (ai_len<0)
	{
		sprintf(as_error,"发送数据长度错误，len=%d",ai_len);
		return -1;
	}

	if (ai_socket<0)
	{
		sprintf(as_error,"Socket句柄号错误: =%d",ai_socket);
		return -1;
	}

	while (ai_len>0)
	{
		li_re = send(ai_socket,as_data+li_send,ai_len,0);

		li_n++;

		if (li_re<0)
		{
			sprintf(as_error,"Socket TCP 发送失败 len=%d send=%d,errno=%d %s",ai_len,li_send,errno,strerror(errno));
			return -1;
		}

		li_send += li_re;
		ai_len  -= li_re;

		if (ai_len>0)
			usleep(1000 * 10);	/* 休眠 10 毫秒 */

	};

	return 1;
}


/************ UDP 数据发送 ***************

	返回：	 1	发送成功
			-1	发送失败
*/
int socket_udp_send(char *as_ip,int ai_port,char *as_data,int ai_len,char *as_error)
{
	int		li_socket,li_re,li_send=0,li_n=0;
	struct sockaddr_in	sin;
	
	as_error[0] = 0;
	
	if (ai_len<0)
	{
		sprintf(as_error,"发送数据长度错误，len=%d",ai_len);
		return -1;
	}

	if ((li_socket = socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		sprintf(as_error,"获取Socket号错误,errno=%d %s\n",errno,strerror(errno));
		return -1;
	}

	bzero(&sin,sizeof(struct sockaddr_in)); 
	sin.sin_family = AF_INET;
	sin.sin_port = htons(ai_port);
	sin.sin_addr.s_addr = inet_addr(as_ip);

	while (ai_len>0)
	{
		li_re = sendto(li_socket,as_data+li_send,ai_len,0,(struct sockaddr *)&sin,sizeof(struct sockaddr_in));

		li_n++;

		if (li_re<0)
		{
			sprintf(as_error,"Socket UDP 发送失败 len=%d send=%d,errno=%d %s\n",ai_len,li_send,errno,strerror(errno));
			close(li_socket);
			return -1;
		}

		li_send += li_re;
		ai_len  -= li_re;
	};

	close(li_socket);
	return 1;
}



/********** 设置TCP的keepalive属性,用于在TCP层检测连接有效性 **************
	
	ai_keepIdle		连接在 ai_keepIdle 秒内没有任何数据往来,则进行探测 
	ai_keepInterval	探测时发包的时间间隔为,一般为5秒
	ai_keepCount	探测尝试的次数.如果第1次探测包就收到响应了,则后则不再发
*/
void set_tcp_timeout(int ai_socket,int ai_keepidle,int ai_keepinterval,int ai_keepcount)
{
	int 	li_keepAlive;
	int 	li_keepIdle;
	int 	li_keepInterval;
	int 	li_keepCount;

	li_keepAlive	= 1;   /* 开启keepalive属性 */
	li_keepIdle		= ai_keepidle;    
	li_keepInterval	= ai_keepinterval;
	li_keepCount	= ai_keepcount;   

	setsockopt(ai_socket, SOL_SOCKET, SO_KEEPALIVE, (void *)&li_keepAlive, sizeof(li_keepAlive));
	
	setsockopt(ai_socket, SOL_TCP, TCP_KEEPIDLE, (void*)&li_keepIdle, sizeof(li_keepIdle));
	setsockopt(ai_socket, SOL_TCP, TCP_KEEPINTVL, (void *)&li_keepInterval, sizeof(li_keepInterval));
	setsockopt(ai_socket, SOL_TCP, TCP_KEEPCNT, (void *)&li_keepCount, sizeof(li_keepCount));
	
}

/* 设置Socket的接受和发送缓冲区大小 */
void set_socket_buffer(int ai_socket,int ai_recvbuff,int ai_sendbuff)
{
	int		li_i;

	li_i = ai_recvbuff;
	setsockopt(ai_socket, SOL_SOCKET, SO_RCVBUF, &li_i, sizeof(li_i));

	li_i = ai_sendbuff;
	setsockopt(ai_socket, SOL_SOCKET, SO_SNDBUF, &li_i, sizeof(li_i));
}


int f_file_send(st_conn *ast_conn,char *as_filepath,char *as_filename,char *as_error)
{
	int		li_filelen,li_len,li_n,li_i,li_max_pack_len=1024*63;
	char	*ls_data,ls_tmp[32],ls_error[256];
	FILE 	*fp ;


	as_error[0] = 0;
	
	if (ast_conn->enabled == 0)
	{
		sprintf(as_error,"发送文件 %s 时,Socket连接无效",as_filename);
		return -1;
	}

	if ((ls_data = (char *)malloc(1024*64))==NULL)
	{
		sprintf(as_error,"发送文件 %s 时,动态申请内存空间失败",as_filename);
		return -1;
	}

	sprintf(ls_data,"%s%s",as_filepath,as_filename);

	if((fp = fopen(ls_data,"rb")) == NULL)
	{
		sprintf(as_error,"发送文件 %s 时打开错误",as_filename);
		free(ls_data);
		return -1;
	}

	fseek(fp,0,SEEK_END);
  	li_filelen = ftell(fp);
  	rewind(fp);

	li_n = li_filelen / li_max_pack_len;

	if ((li_filelen % li_max_pack_len)>0)
		li_n++;
	
	ast_conn->isbusy = 1;
	ast_conn->lock_time = gi_seconds;
	ast_conn->lock_n++;
#if isUnix
	pthread_mutex_lock(&(ast_conn->mutx));
#endif

	strcpy(ls_data,"#^&!12345678#^&!");

	for (li_i=0;li_i<li_n;li_i++)
	{
		fseek(fp,li_i*li_max_pack_len,SEEK_SET); 

		if ((li_len = fread(ls_data+16+100, 1, li_max_pack_len, fp))<0)
		{
			sprintf(as_error,"读取文件错误");
			li_filelen = -1;
			break;
		}
/*
000100|xxxx(12位)|1|xxx|文件名|文件总长度|本数据包长度|文件总发包数|本次发包序号(0开始计数)|本包文件数据内容(相对偏移量100)
*/
		f_get_xh(ls_tmp);
		sprintf(ls_data+16,"000100|%s|1|%s|%s|%d|%d|%d|%d|",ls_tmp,gs_cxbh,as_filename,li_filelen,li_len,li_n,li_i);
		sprintf(ls_tmp,"%08d",100+li_len);	/* 数据内容的总长度 */
		memcpy(ls_data+4,ls_tmp,8);
		sprintf(ls_data+16+100+li_len,"%c*^!#",check_crc(ls_data+16,100+li_len));

		if (socket_tcp_send(ast_conn->fileno,ls_data,100+li_len+21,ls_error)<0)
		{
			sprintf(as_error,"发送文件 %s (%dB,%d/%d)错误: %s",as_filename,li_filelen,li_i,li_n,ls_error);
			li_filelen = -1;
			break;
		}

		ast_conn->sendbw++;
		ast_conn->sendll += 100+li_len+21;
		
		usleep(1000 * 5);	/* 休眠 5 毫秒 */
	}

#if isUnix
	pthread_mutex_unlock(&(ast_conn->mutx));
#endif

	ast_conn->isbusy = 0;
	ast_conn->unlock_time = gi_seconds;
	ast_conn->unlock_n++;

	fclose(fp);
	free(ls_data);

	return li_filelen;
}

