/********************************************Copyright (h)*****************************************
**                                          北京艾普智城网络科技有限公司
**
**                                           http://www.ipole.com.cn/show/zn/index.jsp
**                                           tel :(010)-82825208
**--------------文件信息---------------------------------------------------------------------------
**文   件   名: redis_common.h
**创   建   人: 
**最后修改日期: 2014-11-04
**描        述: 
**-------------------------------------------------------------------------------------------------
** 修改人:
** 版  本:v1.0
** 日　期:2014-11-01
** 描　述:
**
**--------------当前版本修订-----------------------------------------------------------------------
**-------------------------------------------------------------------------------------------------
**************************************************************************************************/
#ifndef REDIS_COMMON_H_INCLUDED
#define REDIS_COMMON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "/usr/include/hiredis/hiredis.h"


/***redis域值结束符**/
#define REDIS_END					0xffff


/***********************************************************档案start************************************************************/
/***测量点信息域值定义**/
									
#define DM_MPED_ID				1
#define DM_CP_NO					2
#define DM_MPED_INDEX			3
#define DM_METER_ID				4
#define DM_CT						5
#define DM_PT					6
#define DM_T_FACTOR				7
#define DM_METER_CONST			8
#define DM_PORT_NO				9
#define DM_LONGITUDE				10
#define DM_LATIUDE				11


/***集中器信息域值定义**/
									
#define DC_CP_NO					1
#define DC_NAME					2
#define DC_CP_ADDR				3
#define DC_SUBS_ID					4
#define DC_LINE_ID					5
#define DC_TG_ID					6
#define DC_CP_TYPE_CODE			7
#define DC_STATUS_CODE			8
#define DC_MASTER_IP				9
#define DC_LOG_STATE				10
#define DC_LONGITUDE				11
#define DC_LATIUDE				12

/***********************************************************档案end************************************************************/



/************************************************************状态统计信息start**************************************************************/

/***正常终端信息域值定义**/
									

#define SC_NORMAL_SOCKET					1
#define SC_NORMAL_IP						2
#define SC_NORMAL_PORT					3
#define SC_NORMAL_STATE					4
#define SC_NORMAL_EPOLL_NO				5
#define SC_NORMAL_TERM_ADDR				6
#define SC_NORMAL__HEART_STATE			7
#define SC_NORMAL_TIMEOUT_TIMES			8
#define SC_NORMAL_INFOSYNC_TIME			9
#define SC_NORMAL_QZ_NO					10

#define SC_LOGIN_TIMES					11
#define SC_EVENT_REPORT_TIMES				12
#define SC_LOGIN_TIME						13
#define SC_OFFLINE_TIME					14
#define SC_LAST_REPORT_TIME				15
#define SC_ONLIE_TIME_SPAN				16
#define SC_UP_REPORT_COUNT				17
#define SC_UP_FLOW						18
#define SC_DOWN_REPORT_COUNT			19
#define SC_DOWN_FLOW						20
#define SC_NORMAL_LOG                            21


/***异常终端信息域值定义**/
									
#define SC_UNUSUAL_CAUSE					1
#define SC_UNUSUAL_IP						2
#define SC_UNUSUAL_HAPPEN_TIME			3
#define SC_UNUSUAL_QZ_NO					4

/***socket 连接信息域值定义**/
									
#define SS_NORMAL_SOCKET					1
#define SS_NORMAL_IP						2
#define SS_NORMAL_PORT					3
#define SS_NORMAL_STATE					4
#define SS_NORMAL_EPOLL_NO				5
#define SS_NORMAL_TERM_ADDR				6
#define SS_NORMAL__BUSY_STATE				7
#define SS_NORMAL_RECVBUF_INDX			8
#define SS_NORMAL_QZ_NO					9

/***异常socket 连接信息域值定义**/
									
#define SS_UNUSUAL_CAUSE					1
#define SS_UNUSUAL_IP						2
#define SS_UNUSUAL_HAPPEN_TIME			3
#define SS_UNUSUAL_QZ_NO					4

/***程序状态信息域值定义**/
									
#define SP_PLATFORM_IP					1
#define SP_DEPLOY_TIME					2
#define SP_START_TIME						3
#define SP_LAST_HEART_TIME				4
#define SP_REBOOT_TIMES					5
#define SP_VERSIONS						6

/************************************************************状态统计信息end**************************************************************/



/************************************************************web任务信息start**************************************************************/

/***web任务公共信息域值定义**/

#define WEB_TASK_NAME					1
#define WEB_TASK_END_ID					2
#define WEB_TASK_FILE_COUNT				3

/***实时召测类数据信息域值定义**/

#define WEB_TASK_DATABASE				4
#define WEB_TASK_LOCATION				5

/************************************************
	曲线召测类数据信息域值定义、
	冻结召测类数据信息域值定义、
	事件召测类数据信息域值定义
	只有公共信息域
**************************************************/


/************************************************
	参数设置类数据信息域值定义、
	参数召测类数据信息域值定义、
	控制类服务数据信息域值定义、
	复位类数据信息域值定义
**************************************************/
#define WEB_TASK_FN						4
#define WEB_TASK_STATE					5

/***透明转发类数据信息域值定义**/

#define WEB_TASK_TRANSPT_DATA			4


/************************************************************web任务信息end**************************************************************/

/************************************************************数据内容信息start**************************************************************/

/***实时类数据信息域值定义**/
#define COL_TIME							0
#define P_Z								1
#define P_A								2
#define P_B								3
#define P_C								4
#define Q_Z								5
#define Q_A								6
#define Q_B								7
#define Q_C								8
#define PF_Z								9
#define PF_A								10
#define PF_B								11
#define PF_C								12
#define U_A								13
#define U_B								14
#define U_C								15
#define I_A								16
#define I_B								17
#define I_C								18
#define I_0								19
#define REAL_AP							20
#define REAL_AP_A							21
#define REAL_AP_B							22
#define REAL_AP_C							23
#define PAP_R								24
#define PAP_R1							25
#define PAP_R2							26
#define PAP_R3							27
#define PAP_R4							28
#define PRP_R								29
#define PRP_R1							30
#define PRP_R2							31
#define PRP_R3							32
#define PRP_R4							33
#define RAP_R								34
#define RAP_R1							35
#define RAP_R2							36
#define RAP_R3							37
#define RAP_R4							38
#define RRP_R								39
#define RRP_R1							40
#define RRP_R2							41
#define RRP_R3							42
#define RRP_R4							43
#define RP1_R								44
#define RP4_R								45
#define RP2_R								46
#define RP3_R								47

/***冻结类数据信息域值定义**/





/************************************************************数据内容信息end**************************************************************/



/*REDIS一个数据单元长度*/
#define RDS_QUEUE_ELEMENT_LEN  2048
/*集群数量*/
#define REDIS_COLONY	20

/*每个集群REDIS库最大数量*/
#define REDIS_COUNT  60

/*每个库连接通道数量*/
#define REDIS_NUM  999

/*redis 信息同步间隔*/
#define REDIS_SYNC_TIME	20

/*redis 支持的队列数量*/
#define REDIS_QUEUE_COUNT	60

/*队列产生虚拟key值时循环最大值*/
#define REDIS_VIRTUAL_KEY		65535

/*redis 处理线程接收数据buff大小*/
#define REDIS_BUFF_MAXLEN	17*1024

/*redis队列阻塞时间*/
#define REDIS_LIST_TIMEOUT	10


/* redis连接信息 */
typedef struct str_redisconnect_info_t
{
    	redisContext *rediscontext;  /*redis连接句柄*/
    	char		enabled;		/* 连接有效性	0 无效  1 有效 */
	char		isbusy;			/* 0 空闲  1 正在使用 */
	#if isUnix
		pthread_mutex_t	mutx;		/* 互斥锁，指示发送数据操作 */
    	#endif
}str_redisconnect_info;

/* redis连接信息 */
typedef struct str_redis_info_t
{
	char ip[20];
	char username[30];
	char password[30];
    	int  port;
    	int  redis_type;         /* 0 文件队列，  1 共享数据缓存区 */
    	int  redis_enable;         /* 连接有效性	0 无效  1 有效 */
    	#if isUnix
		pthread_mutex_t	mux_connectredis;		/* 互斥锁，创建各连接线程时传递参数用 */
    	#endif
    	int  maxconnect;                        /*当前最大连接通道数*/
    	int  redis_conn_p;               /* 当前使用redis连接通道下标 */
    	int  redis_conn_green_p;               /* 当前使用redis连接通道下标 */
	int  redis_min_slot;/*redis槽最小值*/
	int  redis_max_slot;/*redis槽最大值*/
	int  redis_cmp_flag;/*节点比较结果0 没有这个redis数据；1没有变化；2 slot不同；3新添加节点*/
    	str_redisconnect_info connectinfo[REDIS_NUM];
}str_redis_info;
typedef struct str_virtual_key_name_t
{
	char virtual_key_name[30];
	char enable;
}str_virtual_key_name;
typedef struct str_key_name_t
{
	char host_key_name[30];
	char get_value_flag;/*1表示阻塞接收端队列名管理*/
	char enable;
	pthread_mutex_t	mux_key;
	void (*af_func)(char *as_data,int ai_len);
	str_virtual_key_name virtual_key_name[REDIS_COUNT];
	int count;/*轮到第几个虚拟队列*/
}str_key_name;

typedef struct str_redis_allinfo_t
{
	str_redis_info gstr_redis[REDIS_COUNT];
	str_key_name gstr_key[REDIS_QUEUE_COUNT];
	char enable;
	int redis_count;
	int redis_key_count;
}str_redis_allinfo;

/*管理线程使用数据结构*/
typedef struct str_redis_manageinfo_unit_t
{
	char enable;
	char host_ip[16];
	int  host_port;
	char host_username[30];
	char host_password[30];
    	char backup_ip[16];
	int  backup_port;
	char backup_username[30];
	char backup_password[30];
	redisContext *rediscontext;  /*redis连接句柄*/
	char host_flag;/*1表示连接到host*/
}str_redis_manageinfo_unit;

typedef struct str_redis_manageinfo_t
{
	str_redis_manageinfo_unit gstr_redis_manageinfo_unit[REDIS_COLONY];
	int colony_count;
	int redis_connectcount;
	int redis_queue_pthreadcount;
}str_redis_manageinfo;


// 互斥信号量属性结构体定义
typedef struct 
{
	char code_id[4];//程序编号
	char creat_time[21];//2014-10-10:11:23:45
}redis_mutex_info;

/*信息同步更新时使用数据结构*/
typedef struct redis_info_t
{
	char ip[20];
	char username[30];
	char password[30];
    	int  port;
	int maxslot;
	int minslot;
	char enable;
}redis_info;
/*线程信息传递结构体*/
typedef struct redis_pthread_info_t
{
	char key[50];
	int colonynum;
	int redisnum;
	int timeount;
	void (*af_func)(char *as_data,int ai_len);
}redis_pthread_info;


/***********************************************************************************************************************************************/

extern pthread_mutex_t	gt_redis_creatpthread_mux;		/* 互斥锁，创建线程时使用 */
extern str_redis_allinfo gstr_redis_info[REDIS_COLONY]; // 20个redis 集群 ，每个集群可包括60个redis实体，每个实体支持999个句柄
extern str_redis_manageinfo gstr_redis_manageinfo;

/***********************************************************************************************************************************************/
/*redis 互斥锁的操作接口*/
extern int redis_mutex_trylock(char *as_key,int ai_num, int ai_greenflag, redis_mutex_info *as_element,int ttl);// 试图获得REDIS互斥系统锁
extern int redis_mutex_destroy(char *as_key,int ai_num, int ai_greenflag);// 释放redis互斥系统锁
extern int redis_get_mutex_info(char *as_key,int ai_num, int ai_greenflag, redis_mutex_info *as_element);// 获得REDIS互斥锁信息

/*redis 初始化接口*/
extern int redis_colony_init();/* redis非阻塞连接， ai_type对应redis_type 0 文件队列，1 共享数据缓存区；as_dbbh ini字段名字；ai_num 连接通道数量*/

/*redis队列虚拟key创建*/
extern int creat_virtaul_key(char *as_key,int ai_num );/*创建虚拟队列key值*/

/*redis 所有连接释放接口*/
extern int redis_exit();/*释放redis 句柄*/

/*redis 单个连接释放接口*/
extern int redis_disconnect(redisContext *arc_rediscontext);/* 阻塞 关闭连接 传入一个句柄*/

/*redis 连接句柄连接接口*/
extern int redis_connect(str_redis_info *astr_redis, int ai_num, char *as_error);/* 连接redis数据库函数,ai_num连接数量1-999*/

/*redis 连接句柄重新连接接口*/
extern int redis_reconnect(int ai_num,int ai_type, redisContext *arc_rediscontext);// 非阻塞断线重连


/*redis 队列的操作接口*/

extern int lbrget_rdlist(char *as_key, int ai_num,int ai_overtime, void (*af_func)(char *as_data,int ai_len),char as_flag);/* 阻塞接收list数据函数*/
extern int lpush_rdlist(char *as_key,int ai_num, int ai_greenflag, char *as_element,char as_flag);/* 向队列插入数据 入：队列名（5_xx,5是gstr_redis下标），传入串,优先级*/


//extern int llen_rdlist(char *as_key, int ai_num,int ai_greenflag,);/*  非阻塞 查某个队列元素个数 入：队列名（5_xx,5是gstr_redis下标） 返回：数量*/

//extern int lrange_rdlist(char *as_key, int ai_num,int ai_greenflag,int ai_start, int ai_stop, char** as_element,int len, int *ai_elementcount);/* 获取列表键值 入：key（5_xx,5是gstr_redis下标） 取第一个：ai_start=0 ai_stop=0，取第一 二个：ai_start=0 ai_stop=1、、、取所有：ai_start=0 ai_stop=-1*/

//extern int lset_rdlist(char *as_key,int ai_num, int ai_greenflag, int ai_index, char *as_element);/* 插入、更新值 入 key，value*/


/*哈希表的操作接口*/
extern int create_hashtable_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element,char**as_value,int len);/*添加哈希表(对外)*/
extern int get_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int *ai_element,char**as_value,int len,int*count);/*根据key值和域值获取value(对外)*/
extern int get_all_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, char**as_value,int len,int*count);/*根据key值获取全部value(对外)*/
extern int get_all_hashfieldandvalue_rd(char *as_key,int ai_num, int ai_greenflag, char**as_value,int len,int*count);/*根据key值获取全部域值和value(对外)*/
extern int del_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int *ai_element);/*功能:删除哈希表中的某个或者某几个域(对外)*/
extern int change_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element,char**as_value,int len);/*修改哈希表中的某个或者某几个域的值(对外)*/
extern int add_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int ai_element,char*as_value);/*向已存在的哈希表中添加一个域的值(对外)*/
extern long long increase_int_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int ai_element,int ai_value);/*向已存在的哈希表中某个域的值增加某个整数值(对外)*/
extern float increase_float_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int ai_element,float af_value);/*向已存在的哈希表中某个域的值增加某个浮点数值(对外)*/
extern int scan_all_hashtable_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select);/*根据通配符扫描key值(所有/对外)*/
extern int scan_part_hashtable_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount);/*根据通配符扫描key值(单次扫描/对外)*/

/*redis中key值的操作接口*/
extern int delkey_rd(char *as_key,int ai_num, int ai_greenflag);/* 删除队列中某个元素 入：key*/
extern int exists_rd(char *as_key,int ai_num, int ai_greenflag);/*有没有队列 入：key 出：0 不存在 1存在*/
extern int set_keyttl(char *as_key,int ai_num, int ai_greenflag,int ai_time);/*对key值设置存在时间*/
extern int del_keyttl(char *as_key,int ai_num, int ai_greenflag);/*移除key值的超时时间*/
#endif
