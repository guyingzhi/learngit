/* 2009-12-29 */

#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <signal.h>


#ifdef _WIN32
	#define	isUnix	0
#else
	#define	isUnix	1
#endif

#define INIFILE	"sys.ini"

#define MSG_SEPARATOR		"|"		/* �ֶηָ��� */
#define MSG_SEPARATOR_LEN	1		/* �ֶηָ������� */

#define  UP_450  "00_u_450"
#define  DN_450 "00_d_450"

#define __DEBUG__ 
#ifdef __DEBUG__  
#define DEBUG(format,...) printf(""format"", ##__VA_ARGS__)
#else  
#define DEBUG(format,...)  
#endif 

#define __DEBUGM__ 
#ifdef __DEBUGM__  
#define DEBUGM(format,...) printf("File: "__FILE__", Line: %05d: "format"", __LINE__, ##__VA_ARGS__)
#else  
#define DEBUGM(format,...)  
#endif 



typedef unsigned char	uchar;
typedef unsigned int	uint;
typedef unsigned long	ulong;
typedef unsigned short	ushort;


char	gs_version[32];				/* ����汾�� */


/* ����ʱ���ͽṹ�� */
typedef struct datetime_t
{
	char	year;	/* �洢�����1900��Ĳ�ֵ */
	char	mon;
	char	day;
	char	hour;
	char	min;
	char	sec;
} datetime;


/* ������Ϣ�ṹ�壬��¼ĳ��TCP������Ϣ */
typedef struct st_connect_t
{
	char		enabled;		/* ������Ч��	0 ��Ч  1 ��Ч */
	char		isbusy;			/* 0 ����  1 ����ʹ�� */
	int			fileno;			/* TCP���Ӻ� */
	datetime	ljsj;			/* TCP���һ������ʱ�� */
	unsigned int			recvll;			/* ������������(�ֽ�) */
	unsigned int			sendll;			/* ������������(�ֽ�) */
	unsigned int			recvbw;			/* ���ձ������� */
	unsigned int			sendbw;			/* ���ͱ������� */
	char		local_ip[16];	/* ��������IP��ַ */
	char		remote_ip[16];	/* Զ������IP��ַ */
	int			local_port;		/* �������Ӷ˿� */
	int			remote_port;	/* Զ�����Ӷ˿� */
	int			lock_n;			/* ������������ */
	int			unlock_n;		/* ���ͽ������� */
	int			lock_time;		/* ���һ�η�������ʱ�� */
	int			unlock_time;	/* ���һ�η��ͽ���ʱ�� */
	int			send_time;		/* ���һ�η�������ʱ�� */
	int			recv_time;		/* ���һ�ν�������ʱ�� */
#if isUnix
	pid_t		p_tid;			/* �������ڵ��̱߳��(OS�̺߳�) */
	pthread_mutex_t	mutx;		/* ��������ָʾ�������ݲ��� */
#endif
} st_conn;


/* ���ɹ�Լ֡��ʽ�ṹ�� */
//typedef struct str_frame_t
//{
//	uchar		*frame;		/* ������֡����ͷ */
//	char		gylx;		/* ��Լ���� 1 ���ɹ�Լ(2009)  2 ����376.1  3 ���ɹ�Լ(2012) */
//	int			l;			/* ���ĳ��� */
//	char		dir;		/* ������C�� DIR */
//	char		prm;		/* ������C�� PRM */
//	char		fcb;		/* ������C�� FCB����ACD��ͬ */
//	char		acd;		/* ������C�� ACD����FCB��ͬ */
//	char		fcv;		/* ������C�� FCV */
//	char		fun;		/* ������C�� ������ */
//	int			addr;		/* �ն˵�ַ��9λ��ʮ������ */
//	char		addrflag;	/* �ն����ַ��־ */
//	uchar		msa;		/* ��վ��ַ MSA */
//	uchar		afn;		/* Ӧ�ò㹦���� AFN */
//	char		tpv;		/* ֡������SEQ�е� TpV */
//	char		fir;		/* ֡������SEQ�е� FIR */
//	char		fin;		/* ֡������SEQ�е� FIN */
//	char		con;		/* ֡������SEQ�е� CON */
//	char		seq;		/* ֡������SEQ�е� PSEQ/RSEQ */
//	uchar		*data;		/* �û�������ͷ����֡������SEQ��ʼ */
//} str_frame;

typedef struct
{
	ushort fn[255];
	uchar cnt;
}str_fn;

typedef struct
{
	ushort pn[2040];
	ushort cnt;
}str_pn;




typedef struct {
	ushort	gy : 2; 	 /* ��Լ���� 01��2009��Լ 03��2012��Լ */
	ushort	len : 14;  /* �������ݳ��� */
}str_len;

typedef struct {	
	uchar	fun : 4;		/* ������C�� ������ */
	uchar	fcv_keep : 1;/* ������C�� FCV,����֡������Чλ,���б���*/
	uchar	fcb_acd : 1;	/* ������C�� FCB����ACD��ͬ,����֡����λ,����Ҫ�����λ*/
	uchar	prm : 1;		/* ������C�� PRM,������ʶλ */
	uchar	dir : 1;		/* ������C�� DIR,���䷽��λ */
}str_c;

typedef struct {
	uchar	gpaddr_v : 1;  	/* �ն����ַ��־ */
	uchar	msa : 7;  /* ��վ��ַ MSA */
}str_a3;

typedef struct {
	uchar	a1_low;  //BCD
	uchar	a1_high;  //BCD
	uchar	a2_low;  //BIN
	uchar	a2_high;  //BIN
	str_a3	a3;
}str_addr;

typedef struct {
	uchar	seq : 4;		/* ֡������SEQ�е� PSEQ/RSEQ,����֡��ţ���Ӧ֡��� */
	uchar	con : 1;		/* ֡������SEQ�е� CON,����ȷ�ϱ�־λ */
	uchar	fin : 1;		/* ֡������SEQ�е� FIN,ĩ֡��־ */
	uchar	fir : 1;		/* ֡������SEQ�е� FIR,��֡��־ */
	uchar	tpv : 1;		/* ֡������SEQ�е� TpV,֡ʱ���ǩ��Чλ */
}str_seq;

typedef struct {
	uchar	imp;  //��Ҫ�¼�������
	uchar	com;  //һ���¼�������
}str_ec;  //�����¼�������

typedef struct {
	uchar	sec;  //BCD
	uchar	min;
	uchar 	hour;
	uchar 	day;
}str_time;

typedef struct {
	uchar pfc;  //����֡֡��ż�����
	str_time  time;
	uchar delay_time;  //�����ʹ�����ʱʱ��MIN
}str_tp;

typedef struct {
	uchar	pw[16];  //��Ϣ��֤��
	str_ec    ec;
	str_tp	tp;
}str_aux;  //������Ϣ��

typedef struct {
	uchar     *frame_head;
	str_len	strl;
	str_c 	c;
	str_addr	addr;
	uchar	afn;
	str_seq	seq;
	str_fn	mul_fn;         /*FN*/
	str_pn	mul_pn;         /*PN*/
	str_aux	aux;
	uchar	dat[16383];
	uint        dat_len;
}str_encode_param;



char		gs_syslog[256];		/* ϵͳ��־·�� */
char		gs_datalog[256];	/* ��Լ������־·�� */
char		gs_filecache[256];	/* �ļ�����Ŀ¼ */

char		gs_cxbh[8];			/* ������ */
datetime	gdt_now;			/* ��ǰϵͳʱ�� */
datetime	gdt_start_datetime;	/* ��������ʱ�� */
int			gi_seconds;			/* �������������ߵ�����,��ϵͳ��ʱ������ */
int			gi_minutes;			/* �������������ߵķ�����,��ϵͳ��ʱ������ */

#if isUnix
	pthread_mutex_t	g_mux_tracelog;	/* �ź�����ָʾtracelog��־д����� */
	pthread_mutex_t	g_mux_datalog;	/* �ź�����ָʾdatalog��־д����� */
#endif








/* д��־�������÷�ͬ printf */
void tracelog(char *fmt , ...);

/*ʮ�������ַ�ת����*/
short hex_to_int(char ac_val);

/* �õ������Ƹ�ʽ�ĵ�ǰ���ڣ�ռ6�ֽ� */
void f_get_datetime(datetime *adt_datetime);
/* �õ� yyyy-mm-dd hh:mm:ss ��ʽ�ĵ�ǰ�����ַ��� */
void f_get_datetimestr(char *as_datetime);

/* �����������adt_in����� ai_n �º������adt_out,���������͵�����,ai_n��Ϊ��,����ֻ������Ч��ʱ����Ч */
int after_month(datetime *adt_in , datetime *adt_out , int ai_n );
/* �����������adt_in����� ai_n ���������ַ���adt_out,���������͵�����,ai_n��Ϊ��,����ֻ������Ч��ʱ����Ч */
int after_day(datetime *adt_in , datetime *adt_out , int ai_n );
/* �����������adt_in����� al_n ��������adt_out,���������͵�����,al_n��Ϊ�� */
int after_time(datetime *adt_in , datetime *adt_out , long al_n );

/* �����������ڼ��������,����ֻ������Ч��ʱ����Ч */
int	date_days(datetime adt_date1,datetime adt_date2);
/* ��������ʱ����������������ֻʱ����Ч�����ڲ�����Ч */
int time_seconds(datetime adt_time1,datetime adt_time2);
/* �Ƚ�����ʱ���С */
int datetime_cmp(datetime adt_time1,datetime adt_time2);


/* �ж��ַ����Ƿ�ȫ����������ɣ����� 0 ���� 1 �� */
int isnum(char *as_str);
/* ���� ad_x ����ai_nλС�����ֵ���������뷨 */
double f_round(double ad_x,int ai_n);
/** ȥ���ַ����еĿո� **/
char *strtrim(char *as_ss);
/** ���ַ����е�Сд��ĸת���ɴ�д��ĸ **/
char *strupper(char *as_ss);
/** ���ַ����еĴ�д��ĸת����Сд��ĸ **/
char *strlower(char *as_ss);

/**** ��ȡ�����ļ����� ****/
int getiniinfo(char *filename,char *section,char *key,char *value);

uchar ByteToBCDByte(uchar ac_byte);

/*ϵͳ�쳣�ص�����*/
void sys_dump(int signo);
void f_signal_init();

int get_frame_struct(str_encode_param *astr_frame, uchar *as_frame, int in_len);

extern char set_pthread_stack(int size,pthread_attr_t *thread_attr);


#endif



