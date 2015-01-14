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


/* ���� TCP ����˼��� */
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
		sprintf(as_error,"��ȡSOCKET��ʧ��,���� %d %s",li_socket,strerror(errno));
		return -1;
	}

	li_port = ai_port;
	if (li_port<=0 || li_port>=65535)
	{
		sprintf(as_error,"�����˿ڷ�Χ���� %d",li_port);
		return -1;
	}

	bzero(&sin,sizeof(struct sockaddr_in)); 

	sin.sin_family = AF_INET;
	sin.sin_port = htons(li_port);
	
	if (strncmp(ls_ip,"ALL",3)==0)		/* ��������IP */
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	else								/* ����ָ��IP */
		sin.sin_addr.s_addr = inet_addr(ls_ip);

	li_i = 1;
	if ((li_re=setsockopt(li_socket,SOL_SOCKET,SO_REUSEADDR,(void*)&li_i,sizeof(li_i)))< 0)
	{
		sprintf(as_error,"��SOCKET������ SO_REUSEADDR  ʧ�ܣ����� %d %s",li_re,strerror(errno));
		return -1;
	}

	if((li_re=bind(li_socket,(struct sockaddr *)&sin,sizeof(sin)))<0)
	{
		sprintf(as_error,"�󶨼�����ַ����,IP %s Port %d,���� %d %s",ls_ip,li_port,li_re,strerror(errno));
		return -1;
	}

	if((li_re=listen(li_socket,20))<0)
	{
		sprintf(as_error,"��������ʧ��,IP %s Port %d,���� %d %s",ls_ip,li_port,li_re,strerror(errno));
		return -1;
	}
	
	*ai_socket = li_socket;

	return 1;
}

/* ���� UDP ����˼��� */
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
		sprintf(as_error,"��ȡSOCKET��ʧ��,���� %d %s",li_socket,strerror(errno));
		return -1;
	}

	li_port = ai_port;
	if (li_port<=0 || li_port>=65535)
	{
		sprintf(as_error,"�����˿ڷ�Χ���� %d",li_port);
		return -1;
	}

	bzero(&sin,sizeof(struct sockaddr_in)); 

	sin.sin_family = AF_INET;
	sin.sin_port = htons(li_port);

	if (strncmp(ls_ip,"ALL",3)==0)		/* ��������IP */
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	else								/* ����ָ��IP */
		sin.sin_addr.s_addr = inet_addr(ls_ip);

	li_i = 1;
	if ((li_re=setsockopt(li_socket,SOL_SOCKET,SO_REUSEADDR,(void*)&li_i,sizeof(li_i)))< 0)
	{
		sprintf(as_error,"��SOCKET������ SO_REUSEADDR  ʧ�ܣ����� %d %s",li_re,strerror(errno));
		return -1;
	}

	if((li_re=bind(li_socket,(struct sockaddr *)&sin,sizeof(sin)))<0)
	{
		sprintf(as_error,"�󶨼�����ַ����,IP %s Port %d,���� %d %s",ls_ip,li_port,li_re,strerror(errno));
		return -1;
	}

	*ai_socket = li_socket;

	return 1;
}


/* TCP �ͻ������� */
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
		sprintf(as_error,"��ȡSOCKET��ʧ��,���� %d %s",li_socket,strerror(errno));
		return -1;
	}

	li_port = ai_port;
	if (li_port<=0 || li_port>=65535)
	{
		sprintf(as_error,"�����˿ڷ�Χ���� %d",li_port);
		close(li_socket);
		return -1;
	}

	bzero(&sin,sizeof(sin));

	if (strncmp(ls_ip,"ALL",3)==0)		/* ����IP */
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	else								/* ָ��IP */
		sin.sin_addr.s_addr = inet_addr(ls_ip);

	sin.sin_family = AF_INET;
	sin.sin_port = htons(li_port);

	if((li_re=connect(li_socket,(struct sockaddr*)&sin,sizeof(sin)))<0)
	{
		sprintf(as_error,"���ӷ����� IP=%s Port=%d ʧ��,���� %d %s",ls_ip,li_port,li_re,strerror(errno));
		close(li_socket);
		return -1;
	}

	*ai_socket = li_socket;

	return 1;
}


/************ TCP ���ݷ��� ***************

	���أ�	 1	���ͳɹ�
			-1	����ʧ��
*/
int socket_tcp_send(int ai_socket,char *as_data,int ai_len,char *as_error)
{
	int		li_re,li_send=0,li_n=0;
	
	as_error[0] = 0;

	if (ai_len<0)
	{
		sprintf(as_error,"�������ݳ��ȴ���len=%d",ai_len);
		return -1;
	}

	if (ai_socket<0)
	{
		sprintf(as_error,"Socket����Ŵ���: =%d",ai_socket);
		return -1;
	}

	while (ai_len>0)
	{
		li_re = send(ai_socket,as_data+li_send,ai_len,0);

		li_n++;

		if (li_re<0)
		{
			sprintf(as_error,"Socket TCP ����ʧ�� len=%d send=%d,errno=%d %s",ai_len,li_send,errno,strerror(errno));
			return -1;
		}

		li_send += li_re;
		ai_len  -= li_re;

		if (ai_len>0)
			usleep(1000 * 10);	/* ���� 10 ���� */

	};

	return 1;
}


/************ UDP ���ݷ��� ***************

	���أ�	 1	���ͳɹ�
			-1	����ʧ��
*/
int socket_udp_send(char *as_ip,int ai_port,char *as_data,int ai_len,char *as_error)
{
	int		li_socket,li_re,li_send=0,li_n=0;
	struct sockaddr_in	sin;
	
	as_error[0] = 0;
	
	if (ai_len<0)
	{
		sprintf(as_error,"�������ݳ��ȴ���len=%d",ai_len);
		return -1;
	}

	if ((li_socket = socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		sprintf(as_error,"��ȡSocket�Ŵ���,errno=%d %s\n",errno,strerror(errno));
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
			sprintf(as_error,"Socket UDP ����ʧ�� len=%d send=%d,errno=%d %s\n",ai_len,li_send,errno,strerror(errno));
			close(li_socket);
			return -1;
		}

		li_send += li_re;
		ai_len  -= li_re;
	};

	close(li_socket);
	return 1;
}



/********** ����TCP��keepalive����,������TCP����������Ч�� **************
	
	ai_keepIdle		������ ai_keepIdle ����û���κ���������,�����̽�� 
	ai_keepInterval	̽��ʱ������ʱ����Ϊ,һ��Ϊ5��
	ai_keepCount	̽�Ⳣ�ԵĴ���.�����1��̽������յ���Ӧ��,������ٷ�
*/
void set_tcp_timeout(int ai_socket,int ai_keepidle,int ai_keepinterval,int ai_keepcount)
{
	int 	li_keepAlive;
	int 	li_keepIdle;
	int 	li_keepInterval;
	int 	li_keepCount;

	li_keepAlive	= 1;   /* ����keepalive���� */
	li_keepIdle		= ai_keepidle;    
	li_keepInterval	= ai_keepinterval;
	li_keepCount	= ai_keepcount;   

	setsockopt(ai_socket, SOL_SOCKET, SO_KEEPALIVE, (void *)&li_keepAlive, sizeof(li_keepAlive));
	
	setsockopt(ai_socket, SOL_TCP, TCP_KEEPIDLE, (void*)&li_keepIdle, sizeof(li_keepIdle));
	setsockopt(ai_socket, SOL_TCP, TCP_KEEPINTVL, (void *)&li_keepInterval, sizeof(li_keepInterval));
	setsockopt(ai_socket, SOL_TCP, TCP_KEEPCNT, (void *)&li_keepCount, sizeof(li_keepCount));
	
}

/* ����Socket�Ľ��ܺͷ��ͻ�������С */
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
		sprintf(as_error,"�����ļ� %s ʱ,Socket������Ч",as_filename);
		return -1;
	}

	if ((ls_data = (char *)malloc(1024*64))==NULL)
	{
		sprintf(as_error,"�����ļ� %s ʱ,��̬�����ڴ�ռ�ʧ��",as_filename);
		return -1;
	}

	sprintf(ls_data,"%s%s",as_filepath,as_filename);

	if((fp = fopen(ls_data,"rb")) == NULL)
	{
		sprintf(as_error,"�����ļ� %s ʱ�򿪴���",as_filename);
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
			sprintf(as_error,"��ȡ�ļ�����");
			li_filelen = -1;
			break;
		}
/*
000100|xxxx(12λ)|1|xxx|�ļ���|�ļ��ܳ���|�����ݰ�����|�ļ��ܷ�����|���η������(0��ʼ����)|�����ļ���������(���ƫ����100)
*/
		f_get_xh(ls_tmp);
		sprintf(ls_data+16,"000100|%s|1|%s|%s|%d|%d|%d|%d|",ls_tmp,gs_cxbh,as_filename,li_filelen,li_len,li_n,li_i);
		sprintf(ls_tmp,"%08d",100+li_len);	/* �������ݵ��ܳ��� */
		memcpy(ls_data+4,ls_tmp,8);
		sprintf(ls_data+16+100+li_len,"%c*^!#",check_crc(ls_data+16,100+li_len));

		if (socket_tcp_send(ast_conn->fileno,ls_data,100+li_len+21,ls_error)<0)
		{
			sprintf(as_error,"�����ļ� %s (%dB,%d/%d)����: %s",as_filename,li_filelen,li_i,li_n,ls_error);
			li_filelen = -1;
			break;
		}

		ast_conn->sendbw++;
		ast_conn->sendll += 100+li_len+21;
		
		usleep(1000 * 5);	/* ���� 5 ���� */
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

