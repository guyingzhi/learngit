/********************************************Copyright (h)*****************************************
**                                          ���������ǳ�����Ƽ����޹�˾
**
**                                           http://www.ipole.com.cn/show/zn/index.jsp
**                                           tel :(010)-82825208
**--------------�ļ���Ϣ---------------------------------------------------------------------------
**��   ��   ��: redis_common.h
**��   ��   ��: 
**����޸�����: 2014-11-04
**��        ��: 
**-------------------------------------------------------------------------------------------------
** �޸���:
** ��  ��:v1.0
** �ա���:2014-11-01
** �衡��:
**
**--------------��ǰ�汾�޶�-----------------------------------------------------------------------
**-------------------------------------------------------------------------------------------------
**************************************************************************************************/
#ifndef REDIS_COMMON_H_INCLUDED
#define REDIS_COMMON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "/usr/include/hiredis/hiredis.h"


/***redis��ֵ������**/
#define REDIS_END					0xffff


/***********************************************************����start************************************************************/
/***��������Ϣ��ֵ����**/
									
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


/***��������Ϣ��ֵ����**/
									
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

/***********************************************************����end************************************************************/



/************************************************************״̬ͳ����Ϣstart**************************************************************/

/***�����ն���Ϣ��ֵ����**/
									

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


/***�쳣�ն���Ϣ��ֵ����**/
									
#define SC_UNUSUAL_CAUSE					1
#define SC_UNUSUAL_IP						2
#define SC_UNUSUAL_HAPPEN_TIME			3
#define SC_UNUSUAL_QZ_NO					4

/***socket ������Ϣ��ֵ����**/
									
#define SS_NORMAL_SOCKET					1
#define SS_NORMAL_IP						2
#define SS_NORMAL_PORT					3
#define SS_NORMAL_STATE					4
#define SS_NORMAL_EPOLL_NO				5
#define SS_NORMAL_TERM_ADDR				6
#define SS_NORMAL__BUSY_STATE				7
#define SS_NORMAL_RECVBUF_INDX			8
#define SS_NORMAL_QZ_NO					9

/***�쳣socket ������Ϣ��ֵ����**/
									
#define SS_UNUSUAL_CAUSE					1
#define SS_UNUSUAL_IP						2
#define SS_UNUSUAL_HAPPEN_TIME			3
#define SS_UNUSUAL_QZ_NO					4

/***����״̬��Ϣ��ֵ����**/
									
#define SP_PLATFORM_IP					1
#define SP_DEPLOY_TIME					2
#define SP_START_TIME						3
#define SP_LAST_HEART_TIME				4
#define SP_REBOOT_TIMES					5
#define SP_VERSIONS						6

/************************************************************״̬ͳ����Ϣend**************************************************************/



/************************************************************web������Ϣstart**************************************************************/

/***web���񹫹���Ϣ��ֵ����**/

#define WEB_TASK_NAME					1
#define WEB_TASK_END_ID					2
#define WEB_TASK_FILE_COUNT				3

/***ʵʱ�ٲ���������Ϣ��ֵ����**/

#define WEB_TASK_DATABASE				4
#define WEB_TASK_LOCATION				5

/************************************************
	�����ٲ���������Ϣ��ֵ���塢
	�����ٲ���������Ϣ��ֵ���塢
	�¼��ٲ���������Ϣ��ֵ����
	ֻ�й�����Ϣ��
**************************************************/


/************************************************
	����������������Ϣ��ֵ���塢
	�����ٲ���������Ϣ��ֵ���塢
	���������������Ϣ��ֵ���塢
	��λ��������Ϣ��ֵ����
**************************************************/
#define WEB_TASK_FN						4
#define WEB_TASK_STATE					5

/***͸��ת����������Ϣ��ֵ����**/

#define WEB_TASK_TRANSPT_DATA			4


/************************************************************web������Ϣend**************************************************************/

/************************************************************����������Ϣstart**************************************************************/

/***ʵʱ��������Ϣ��ֵ����**/
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

/***������������Ϣ��ֵ����**/





/************************************************************����������Ϣend**************************************************************/



/*REDISһ�����ݵ�Ԫ����*/
#define RDS_QUEUE_ELEMENT_LEN  2048
/*��Ⱥ����*/
#define REDIS_COLONY	20

/*ÿ����ȺREDIS���������*/
#define REDIS_COUNT  60

/*ÿ��������ͨ������*/
#define REDIS_NUM  999

/*redis ��Ϣͬ�����*/
#define REDIS_SYNC_TIME	20

/*redis ֧�ֵĶ�������*/
#define REDIS_QUEUE_COUNT	60

/*���в�������keyֵʱѭ�����ֵ*/
#define REDIS_VIRTUAL_KEY		65535

/*redis �����߳̽�������buff��С*/
#define REDIS_BUFF_MAXLEN	17*1024

/*redis��������ʱ��*/
#define REDIS_LIST_TIMEOUT	10


/* redis������Ϣ */
typedef struct str_redisconnect_info_t
{
    	redisContext *rediscontext;  /*redis���Ӿ��*/
    	char		enabled;		/* ������Ч��	0 ��Ч  1 ��Ч */
	char		isbusy;			/* 0 ����  1 ����ʹ�� */
	#if isUnix
		pthread_mutex_t	mutx;		/* ��������ָʾ�������ݲ��� */
    	#endif
}str_redisconnect_info;

/* redis������Ϣ */
typedef struct str_redis_info_t
{
	char ip[20];
	char username[30];
	char password[30];
    	int  port;
    	int  redis_type;         /* 0 �ļ����У�  1 �������ݻ����� */
    	int  redis_enable;         /* ������Ч��	0 ��Ч  1 ��Ч */
    	#if isUnix
		pthread_mutex_t	mux_connectredis;		/* �������������������߳�ʱ���ݲ����� */
    	#endif
    	int  maxconnect;                        /*��ǰ�������ͨ����*/
    	int  redis_conn_p;               /* ��ǰʹ��redis����ͨ���±� */
    	int  redis_conn_green_p;               /* ��ǰʹ��redis����ͨ���±� */
	int  redis_min_slot;/*redis����Сֵ*/
	int  redis_max_slot;/*redis�����ֵ*/
	int  redis_cmp_flag;/*�ڵ�ȽϽ��0 û�����redis���ݣ�1û�б仯��2 slot��ͬ��3����ӽڵ�*/
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
	char get_value_flag;/*1��ʾ�������ն˶���������*/
	char enable;
	pthread_mutex_t	mux_key;
	void (*af_func)(char *as_data,int ai_len);
	str_virtual_key_name virtual_key_name[REDIS_COUNT];
	int count;/*�ֵ��ڼ����������*/
}str_key_name;

typedef struct str_redis_allinfo_t
{
	str_redis_info gstr_redis[REDIS_COUNT];
	str_key_name gstr_key[REDIS_QUEUE_COUNT];
	char enable;
	int redis_count;
	int redis_key_count;
}str_redis_allinfo;

/*�����߳�ʹ�����ݽṹ*/
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
	redisContext *rediscontext;  /*redis���Ӿ��*/
	char host_flag;/*1��ʾ���ӵ�host*/
}str_redis_manageinfo_unit;

typedef struct str_redis_manageinfo_t
{
	str_redis_manageinfo_unit gstr_redis_manageinfo_unit[REDIS_COLONY];
	int colony_count;
	int redis_connectcount;
	int redis_queue_pthreadcount;
}str_redis_manageinfo;


// �����ź������Խṹ�嶨��
typedef struct 
{
	char code_id[4];//������
	char creat_time[21];//2014-10-10:11:23:45
}redis_mutex_info;

/*��Ϣͬ������ʱʹ�����ݽṹ*/
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
/*�߳���Ϣ���ݽṹ��*/
typedef struct redis_pthread_info_t
{
	char key[50];
	int colonynum;
	int redisnum;
	int timeount;
	void (*af_func)(char *as_data,int ai_len);
}redis_pthread_info;


/***********************************************************************************************************************************************/

extern pthread_mutex_t	gt_redis_creatpthread_mux;		/* �������������߳�ʱʹ�� */
extern str_redis_allinfo gstr_redis_info[REDIS_COLONY]; // 20��redis ��Ⱥ ��ÿ����Ⱥ�ɰ���60��redisʵ�壬ÿ��ʵ��֧��999�����
extern str_redis_manageinfo gstr_redis_manageinfo;

/***********************************************************************************************************************************************/
/*redis �������Ĳ����ӿ�*/
extern int redis_mutex_trylock(char *as_key,int ai_num, int ai_greenflag, redis_mutex_info *as_element,int ttl);// ��ͼ���REDIS����ϵͳ��
extern int redis_mutex_destroy(char *as_key,int ai_num, int ai_greenflag);// �ͷ�redis����ϵͳ��
extern int redis_get_mutex_info(char *as_key,int ai_num, int ai_greenflag, redis_mutex_info *as_element);// ���REDIS��������Ϣ

/*redis ��ʼ���ӿ�*/
extern int redis_colony_init();/* redis���������ӣ� ai_type��Ӧredis_type 0 �ļ����У�1 �������ݻ�������as_dbbh ini�ֶ����֣�ai_num ����ͨ������*/

/*redis��������key����*/
extern int creat_virtaul_key(char *as_key,int ai_num );/*�����������keyֵ*/

/*redis ���������ͷŽӿ�*/
extern int redis_exit();/*�ͷ�redis ���*/

/*redis ���������ͷŽӿ�*/
extern int redis_disconnect(redisContext *arc_rediscontext);/* ���� �ر����� ����һ�����*/

/*redis ���Ӿ�����ӽӿ�*/
extern int redis_connect(str_redis_info *astr_redis, int ai_num, char *as_error);/* ����redis���ݿ⺯��,ai_num��������1-999*/

/*redis ���Ӿ���������ӽӿ�*/
extern int redis_reconnect(int ai_num,int ai_type, redisContext *arc_rediscontext);// ��������������


/*redis ���еĲ����ӿ�*/

extern int lbrget_rdlist(char *as_key, int ai_num,int ai_overtime, void (*af_func)(char *as_data,int ai_len),char as_flag);/* ��������list���ݺ���*/
extern int lpush_rdlist(char *as_key,int ai_num, int ai_greenflag, char *as_element,char as_flag);/* ����в������� �룺��������5_xx,5��gstr_redis�±꣩�����봮,���ȼ�*/


//extern int llen_rdlist(char *as_key, int ai_num,int ai_greenflag,);/*  ������ ��ĳ������Ԫ�ظ��� �룺��������5_xx,5��gstr_redis�±꣩ ���أ�����*/

//extern int lrange_rdlist(char *as_key, int ai_num,int ai_greenflag,int ai_start, int ai_stop, char** as_element,int len, int *ai_elementcount);/* ��ȡ�б��ֵ �룺key��5_xx,5��gstr_redis�±꣩ ȡ��һ����ai_start=0 ai_stop=0��ȡ��һ ������ai_start=0 ai_stop=1������ȡ���У�ai_start=0 ai_stop=-1*/

//extern int lset_rdlist(char *as_key,int ai_num, int ai_greenflag, int ai_index, char *as_element);/* ���롢����ֵ �� key��value*/


/*��ϣ��Ĳ����ӿ�*/
extern int create_hashtable_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element,char**as_value,int len);/*��ӹ�ϣ��(����)*/
extern int get_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int *ai_element,char**as_value,int len,int*count);/*����keyֵ����ֵ��ȡvalue(����)*/
extern int get_all_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, char**as_value,int len,int*count);/*����keyֵ��ȡȫ��value(����)*/
extern int get_all_hashfieldandvalue_rd(char *as_key,int ai_num, int ai_greenflag, char**as_value,int len,int*count);/*����keyֵ��ȡȫ����ֵ��value(����)*/
extern int del_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int *ai_element);/*����:ɾ����ϣ���е�ĳ������ĳ������(����)*/
extern int change_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element,char**as_value,int len);/*�޸Ĺ�ϣ���е�ĳ������ĳ�������ֵ(����)*/
extern int add_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int ai_element,char*as_value);/*���Ѵ��ڵĹ�ϣ�������һ�����ֵ(����)*/
extern long long increase_int_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int ai_element,int ai_value);/*���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ������ֵ(����)*/
extern float increase_float_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int ai_element,float af_value);/*���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ��������ֵ(����)*/
extern int scan_all_hashtable_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select);/*����ͨ���ɨ��keyֵ(����/����)*/
extern int scan_part_hashtable_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount);/*����ͨ���ɨ��keyֵ(����ɨ��/����)*/

/*redis��keyֵ�Ĳ����ӿ�*/
extern int delkey_rd(char *as_key,int ai_num, int ai_greenflag);/* ɾ��������ĳ��Ԫ�� �룺key*/
extern int exists_rd(char *as_key,int ai_num, int ai_greenflag);/*��û�ж��� �룺key ����0 ������ 1����*/
extern int set_keyttl(char *as_key,int ai_num, int ai_greenflag,int ai_time);/*��keyֵ���ô���ʱ��*/
extern int del_keyttl(char *as_key,int ai_num, int ai_greenflag);/*�Ƴ�keyֵ�ĳ�ʱʱ��*/
#endif
