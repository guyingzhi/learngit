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

#define MSG_SEPARATOR		"|"		/* 字段分隔符 */
#define MSG_SEPARATOR_LEN	1		/* 字段分隔符长度 */

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


char	gs_version[32];				/* 程序版本号 */


/* 日期时间型结构体 */
typedef struct datetime_t
{
	char	year;	/* 存储相对于1900年的差值 */
	char	mon;
	char	day;
	char	hour;
	char	min;
	char	sec;
} datetime;


/* 连接信息结构体，记录某个TCP连接信息 */
typedef struct st_connect_t
{
	char		enabled;		/* 连接有效性	0 无效  1 有效 */
	char		isbusy;			/* 0 空闲  1 正在使用 */
	int			fileno;			/* TCP连接号 */
	datetime	ljsj;			/* TCP最后一次连接时间 */
	unsigned int			recvll;			/* 接收数据流量(字节) */
	unsigned int			sendll;			/* 发送数据流量(字节) */
	unsigned int			recvbw;			/* 接收报文数量 */
	unsigned int			sendbw;			/* 发送报文数量 */
	char		local_ip[16];	/* 本地连接IP地址 */
	char		remote_ip[16];	/* 远端连接IP地址 */
	int			local_port;		/* 本地连接端口 */
	int			remote_port;	/* 远端连接端口 */
	int			lock_n;			/* 发送上锁次数 */
	int			unlock_n;		/* 发送解锁次数 */
	int			lock_time;		/* 最后一次发送上锁时间 */
	int			unlock_time;	/* 最后一次发送解锁时间 */
	int			send_time;		/* 最后一次发送数据时间 */
	int			recv_time;		/* 最后一次接收数据时间 */
#if isUnix
	pid_t		p_tid;			/* 连接所在的线程编号(OS线程号) */
	pthread_mutex_t	mutx;		/* 互斥锁，指示发送数据操作 */
#endif
} st_conn;


/* 内蒙规约帧格式结构体 */
//typedef struct str_frame_t
//{
//	uchar		*frame;		/* 完整的帧数据头 */
//	char		gylx;		/* 规约类型 1 内蒙规约(2009)  2 国网376.1  3 内蒙规约(2012) */
//	int			l;			/* 报文长度 */
//	char		dir;		/* 控制域C中 DIR */
//	char		prm;		/* 控制域C中 PRM */
//	char		fcb;		/* 控制域C中 FCB，和ACD相同 */
//	char		acd;		/* 控制域C中 ACD，和FCB相同 */
//	char		fcv;		/* 控制域C中 FCV */
//	char		fun;		/* 控制域C中 功能码 */
//	int			addr;		/* 终端地址，9位的十进制数 */
//	char		addrflag;	/* 终端组地址标志 */
//	uchar		msa;		/* 主站地址 MSA */
//	uchar		afn;		/* 应用层功能码 AFN */
//	char		tpv;		/* 帧序列域SEQ中的 TpV */
//	char		fir;		/* 帧序列域SEQ中的 FIR */
//	char		fin;		/* 帧序列域SEQ中的 FIN */
//	char		con;		/* 帧序列域SEQ中的 CON */
//	char		seq;		/* 帧序列域SEQ中的 PSEQ/RSEQ */
//	uchar		*data;		/* 用户数据体头，从帧序列域SEQ后开始 */
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
	ushort	gy : 2; 	 /* 规约类型 01：2009规约 03：2012规约 */
	ushort	len : 14;  /* 报文数据长度 */
}str_len;

typedef struct {	
	uchar	fun : 4;		/* 控制域C中 功能码 */
	uchar	fcv_keep : 1;/* 控制域C中 FCV,下行帧计数有效位,上行保留*/
	uchar	fcb_acd : 1;	/* 控制域C中 FCB，和ACD相同,下行帧计数位,上行要求访问位*/
	uchar	prm : 1;		/* 控制域C中 PRM,启动标识位 */
	uchar	dir : 1;		/* 控制域C中 DIR,传输方向位 */
}str_c;

typedef struct {
	uchar	gpaddr_v : 1;  	/* 终端组地址标志 */
	uchar	msa : 7;  /* 主站地址 MSA */
}str_a3;

typedef struct {
	uchar	a1_low;  //BCD
	uchar	a1_high;  //BCD
	uchar	a2_low;  //BIN
	uchar	a2_high;  //BIN
	str_a3	a3;
}str_addr;

typedef struct {
	uchar	seq : 4;		/* 帧序列域SEQ中的 PSEQ/RSEQ,启动帧序号，响应帧序号 */
	uchar	con : 1;		/* 帧序列域SEQ中的 CON,请求确认标志位 */
	uchar	fin : 1;		/* 帧序列域SEQ中的 FIN,末帧标志 */
	uchar	fir : 1;		/* 帧序列域SEQ中的 FIR,首帧标志 */
	uchar	tpv : 1;		/* 帧序列域SEQ中的 TpV,帧时间标签有效位 */
}str_seq;

typedef struct {
	uchar	imp;  //重要事件计数器
	uchar	com;  //一般事件计数器
}str_ec;  //上行事件计数器

typedef struct {
	uchar	sec;  //BCD
	uchar	min;
	uchar 	hour;
	uchar 	day;
}str_time;

typedef struct {
	uchar pfc;  //启动帧帧序号计数器
	str_time  time;
	uchar delay_time;  //允许发送传输延时时间MIN
}str_tp;

typedef struct {
	uchar	pw[16];  //消息认证码
	str_ec    ec;
	str_tp	tp;
}str_aux;  //附加信息域

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



char		gs_syslog[256];		/* 系统日志路径 */
char		gs_datalog[256];	/* 规约数据日志路径 */
char		gs_filecache[256];	/* 文件缓存目录 */

char		gs_cxbh[8];			/* 程序编号 */
datetime	gdt_now;			/* 当前系统时间 */
datetime	gdt_start_datetime;	/* 程序启动时间 */
int			gi_seconds;			/* 程序启动后所走的秒数,由系统定时器计数 */
int			gi_minutes;			/* 程序启动后所走的分钟数,由系统定时器计数 */

#if isUnix
	pthread_mutex_t	g_mux_tracelog;	/* 信号量，指示tracelog日志写入操作 */
	pthread_mutex_t	g_mux_datalog;	/* 信号量，指示datalog日志写入操作 */
#endif








/* 写日志，参数用法同 printf */
void tracelog(char *fmt , ...);

/*十六进制字符转整数*/
short hex_to_int(char ac_val);

/* 得到二进制格式的当前日期，占6字节 */
void f_get_datetime(datetime *adt_datetime);
/* 得到 yyyy-mm-dd hh:mm:ss 格式的当前日期字符串 */
void f_get_datetimestr(char *as_datetime);

/* 从输入的日期adt_in计算出 ai_n 月后的日期adt_out,并返回整型的日期,ai_n可为负,参数只日期有效，时间无效 */
int after_month(datetime *adt_in , datetime *adt_out , int ai_n );
/* 从输入的日期adt_in计算出 ai_n 天后的日期字符串adt_out,并返回整型的日期,ai_n可为负,参数只日期有效，时间无效 */
int after_day(datetime *adt_in , datetime *adt_out , int ai_n );
/* 从输入的日期adt_in计算出 al_n 秒后的日期adt_out,并返回整型的日期,al_n可为负 */
int after_time(datetime *adt_in , datetime *adt_out , long al_n );

/* 计算两个日期间隔的天数,参数只日期有效，时间无效 */
int	date_days(datetime adt_date1,datetime adt_date2);
/* 计算两个时间间隔的秒数，参数只时间有效，日期部分无效 */
int time_seconds(datetime adt_time1,datetime adt_time2);
/* 比较两个时间大小 */
int datetime_cmp(datetime adt_time1,datetime adt_time2);


/* 判断字符串是否全是由数字组成，返回 0 不是 1 是 */
int isnum(char *as_str);
/* 返回 ad_x 保留ai_n位小数后的值，四舍五入法 */
double f_round(double ad_x,int ai_n);
/** 去除字符串中的空格 **/
char *strtrim(char *as_ss);
/** 把字符串中的小写字母转换成大写字母 **/
char *strupper(char *as_ss);
/** 把字符串中的大写字母转换成小写字母 **/
char *strlower(char *as_ss);

/**** 读取配置文件内容 ****/
int getiniinfo(char *filename,char *section,char *key,char *value);

uchar ByteToBCDByte(uchar ac_byte);

/*系统异常回调函数*/
void sys_dump(int signo);
void f_signal_init();

int get_frame_struct(str_encode_param *astr_frame, uchar *as_frame, int in_len);

extern char set_pthread_stack(int size,pthread_attr_t *thread_attr);


#endif



