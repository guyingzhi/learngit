/********************************************Copyright (c)*****************************************
**                                          北京艾普智城网络科技有限公司
**
**                                           http://www.ipole.com.cn/show/zn/index.jsp
**                                           tel :(010)-82825208
**--------------文件信息---------------------------------------------------------------------------
**文   件   名: redis_common.c
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
#include "redis_common.h"
/**************************************变量定义***************************************************/
unsigned short crc16(const char *buf, int len) ;
unsigned int HASH_SLOT(char *key, int keylen) ;
int get_redisnum(char* as_key,int ai_num);
int brpop_rdvalue(redisContext *arc_rediscontext, char *as_key, int ai_overtime, char** as_value,int len, int *ai_valuecount);
void* f_thread_redis_list_deal(void *pvParam);/*redis队列阻塞接收处理线程*/
int redis_cfg_init();/* redis数据库初始化 ai_type对应redis_type 0 文件队列，1 共享数据缓存区；as_dbbh ini字段名字*/
str_redisconnect_info *f_get_redis_conn(int ai_num,int ai_redis, int ai_greenflag);/*查找一个空闲连接 ai_flag:0普通优先级，1高优先级*/
int hscan_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount);/*根据通配符扫描key值(单次扫描)*/
int hscanall_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select);/*根据通配符扫描key值(所有)*/
float hincrbyfloat_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element);/*向已存在的哈希表中某个域的值增加某个浮点数值*/
long long hincrby_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element);/*向已存在的哈希表中某个域的值增加某个整数值*/
int hsetnx_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*向已存在的哈希表中添加一个域的值*/
int hmchange_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*修改哈希表中的某个或者某几个域的值*/
int hdel_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*功能:删除哈希表中的某个或者某几个域*/
int hgetall_rd(char *as_key, int ai_num,int ai_greenflag, char**as_value,int len,int*count);/*根据key值获取全部域值和value*/
int hvals_rd(char *as_key,int ai_num, int ai_greenflag, char**as_value,int len,int*count);/*根据key值获取全部value*/
int hmget_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element,char**as_value,int len,int*count);/*根据key值和域值获取value*/
int hmset_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*添加哈希表*/






str_redis_allinfo gstr_redis_info[REDIS_COLONY];
str_redis_manageinfo gstr_redis_manageinfo;
static const unsigned short crc16tab[256]= {
    0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
    0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
    0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
    0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
    0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
    0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
    0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
    0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
    0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
    0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
    0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
    0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
    0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
    0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
    0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
    0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
    0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
    0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
    0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
    0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
    0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
    0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
    0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
    0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
    0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
    0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
    0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
    0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
    0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
    0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
    0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
    0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
};

pthread_mutex_t	gt_redis_creatpthread_mux;		/* 互斥锁，创建线程时使用 */
/************************************内部函数声明********************************************************/
/*CRC16校验*/
unsigned short crc16(const char *buf, int len) 
{
    int counter;
    unsigned short crc = 0;
    for (counter = 0; counter < len; counter++)
            crc = (crc<<8) ^ crc16tab[((crc>>8) ^ *buf++)&0x00FF];
    return crc;
}
/*根据key值获取哈希槽值*/
unsigned int HASH_SLOT(char *key, int keylen) 
{
    int s, e; /* start-end indexes of { and } */

    /* Search the first occurrence of '{'. */
    for (s = 0; s < keylen; s++)
        if (key[s] == '{') break;

    /* No '{' ? Hash the whole key. This is the base case. */
    if (s == keylen) return crc16(key,keylen) & 16383;

    /* '{' found? Check if we have the corresponding '}'. */
    for (e = s+1; e < keylen; e++)
        if (key[e] == '}') break;

    /* No '}' or nothing between {} ? Hash the whole key. */
    if (e == keylen || e == s+1) return crc16(key,keylen) & 16383;

    /* If we are here there is both a { and a } on its right. Hash
     * what is in the middle between { and }. */
    return crc16(key+s+1,e-s-1) & 16383;
}


/*根据key值获取本模块管理的redis物理连接池下标*/
int get_redisnum(char* as_key,int num)
{
	unsigned int li_slot = 0;
	int li_len = 0;
	int li_i = 0;
	li_len = strlen(as_key);
	li_slot = HASH_SLOT(as_key,li_len);
	for(li_i = 0;li_i < REDIS_COUNT;li_i++)
	{
		if( gstr_redis_info[num].gstr_redis[li_i].redis_enable == 1
			&&li_slot >= gstr_redis_info[num].gstr_redis[li_i].redis_min_slot
			&&li_slot <= gstr_redis_info[num].gstr_redis[li_i].redis_max_slot)
		{
			return li_i;
		}
	}
	return 0xffff;
}

 /** @函数名 :int redis_mutex_destroy(char *as_key, int ai_greenflag)
  *
  *  @函数功能: 设置KEY值存活时间
  * 							 
  *
  *  @param:  char *as_key：    redis句柄属性
  *		ai_num:		集群编号
  * 		  ai_greenflag：    通道标识
  * 		
  *  @return :0-n 存活时间  -1异常  -2 删除
  *  @retval
  *  @retval
  *  @note 
  */
int redis_get_ttl(char *as_key,int ai_num, int ai_greenflag)
{
  	char ls_tmp[15]={0}, ls_order[RDS_QUEUE_ELEMENT_LEN + 20]={0};
    	int li_i;
    	redisReply *reply;

    	str_redisconnect_info *lst_redis_conn;

    	li_i = get_redisnum(as_key,ai_num);
		
 	sprintf(ls_order,"ttl %s ",as_key);
   	if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
   	}
	lst_redis_conn->isbusy = 1;
	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
   
    	if (reply->type == REDIS_REPLY_INTEGER)
    	{
        		li_i = reply->integer;
    	}
    	else
    	{
        		li_i = -1;
    	}
    	lst_redis_conn->isbusy = 0;

    	freeReplyObject(reply);

    	pthread_mutex_unlock(&(lst_redis_conn->mutx));

    	return li_i;
}
/** @函数名 :int redis_set_ttl_mutex(char *as_key, int ai_greenflag,int ttl)
  *
  *  @函数功能: 设置KEY值存活时间
  * 							 
  *
  *  @param:  char *as_key：     redis句柄属性
  *		ai_num:		集群编号
  * 		  ai_greenflag：    通道标识
  * 		  int ttl:          互斥锁存活时间
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
  int redis_set_ttl_mutex(char *as_key,int ai_num, int ai_greenflag,int ttl)
  {
	char ls_tmp[15]={0}, ls_order[RDS_QUEUE_ELEMENT_LEN + 20]={0};
	char str[100];
	
    	int li_i;
    	redisReply *reply;
    	str_redisconnect_info *lst_redis_conn;

    	li_i = get_redisnum(as_key,ai_num);
	
	sprintf(str, "%d", ttl);
	printf("%s",str);
 	sprintf(ls_order,"expire %s %s",as_key,str);
	printf("ls_order = %s\n",ls_order);
	
    	if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;
	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
   
    	if (reply->type == REDIS_REPLY_INTEGER)
    	{
        		li_i = reply->integer;
    	}
    	else
    	{
        		li_i = -1;
    	}
    	lst_redis_conn->isbusy = 0;

    	freeReplyObject(reply);

    	pthread_mutex_unlock(&(lst_redis_conn->mutx));

    	return li_i;
  }
/** @函数名 :int brpop_rdvalue(redisContext *arc_rediscontext, char *as_key, int ai_overtime, char as_value,int len, int *ai_valuecount)
  *
  *  @函数功能: 带超时的阻塞接收队列元素
  * 							 
  *
  *  @param:  redisContext *arc_rediscontext ：redis句柄
  *           char *as_key     ：队列KEY值
  * 		  int ai_overtime  ：超时时间
  *           char as_value[][RDS_QUEUE_ELEMENT_LEN]：返回数据
  *           int *ai_valuecount ：返回元素个数
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int brpop_rdvalue(redisContext *arc_rediscontext, char *as_key, int ai_overtime, char** as_value,int len, int *ai_valuecount)
{
    redisReply *reply;
    char ls_order[512]={0}, ls_err[128];
    int li_i,li_k;
    int li_re;
    char* p = NULL;
    p = (char*)as_value;
    sprintf(ls_order,"BRPOP %s %d",as_key,ai_overtime);
    reply = redisCommand(arc_rediscontext, ls_order);
    if(reply == NULL)
	{
		return -1;
	}
   else if (reply->type == REDIS_REPLY_ARRAY)
    {
        li_k = 0;
        for(li_i=1; li_i<reply->elements; li_i++)
        {
            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
            {
                strcpy(p+(len*li_k), reply->element[li_i]->str);
                li_k++;
            }
        }

        *ai_valuecount = li_k;

    }
    else
    {
        freeReplyObject(reply);
        return -1;
    }

    freeReplyObject(reply);

    return 1;
}

/** @函数名 :int redis_cfg_init()
  *
  *  @函数功能: 初始化非阻塞redis句柄信息结构体
  * 							 
  *
  *  @param:  无
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int redis_cfg_init()
{
	char 	*inifile = INIFILE;
	char ls_ininame[50];
	char	ls_str1[256],ls_str2[256];
	char 	ls_tmpbuff[30];
	int li_i = 0;
	memset(gstr_redis_info,0,REDIS_COLONY*sizeof(str_redis_allinfo));
	memset(&gstr_redis_manageinfo,0,sizeof(str_redis_manageinfo));
	pthread_mutex_init(&gt_redis_creatpthread_mux,NULL);
	if(getiniinfo(inifile,"REDIS_INFO","redis_colony",ls_tmpbuff)<0)
	{
		return -1;
	}
	else
	{
		gstr_redis_manageinfo.colony_count = atoi(ls_tmpbuff);
		printf("gstr_redis_manageinfo.colony_count = %d\n",gstr_redis_manageinfo.colony_count);
	}
	if(getiniinfo(inifile,"REDIS_INFO","redis_point_connectcount",ls_tmpbuff)<0)
	{
		return -1;
	}
	else
	{
		gstr_redis_manageinfo.redis_connectcount = atoi(ls_tmpbuff);
		printf("gstr_redis_manageinfo.redis_connectcount = %d\n",gstr_redis_manageinfo.redis_connectcount);
	}
	if(getiniinfo(inifile,"REDIS_INFO","redis_queue_pthreadcount",ls_tmpbuff)<0)
	{
		return -1;
	}
	else
	{
		gstr_redis_manageinfo.redis_queue_pthreadcount = atoi(ls_tmpbuff);
		printf("gstr_redis_manageinfo.redis_queue_pthreadcount = %d\n",gstr_redis_manageinfo.redis_queue_pthreadcount);
	}
	for(li_i = 0;li_i < gstr_redis_manageinfo.colony_count;li_i++)
	{
		memset(ls_ininame,0,sizeof(ls_ininame));
		gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].enable = 1;
		sprintf(ls_ininame,"%d_DB_REDIS_CJ",li_i);
		if(getiniinfo(inifile,ls_ininame,"hostservername",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			strcpy(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_ip,ls_tmpbuff);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_ip = %s\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_ip);
		}
		if(getiniinfo(inifile,ls_ininame,"hostserverport",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_port = atoi(ls_tmpbuff);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_port = %d\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_port);
		}

		if(getiniinfo(inifile,ls_ininame,"hostlogid",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			strcpy(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_username,ls_tmpbuff);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_username = %s\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_username);
		}
		if(getiniinfo(inifile,ls_ininame,"hostpassword",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			if (f_pwd_decode(ls_tmpbuff,ls_str2)<=0)
			{
				return -1;
			}
			strcpy(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_password,ls_str2);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_password = %s\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_password);
		}

		if(getiniinfo(inifile,ls_ininame,"backupservername",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			strcpy(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_ip,ls_tmpbuff);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_ip = %s\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_ip);
		}
		if(getiniinfo(inifile,ls_ininame,"backupserverport",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_port = atoi(ls_tmpbuff);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_port = %d\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_port);
		}

		if(getiniinfo(inifile,ls_ininame,"backuplogid",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			strcpy(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_username,ls_tmpbuff);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_username = %s\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_username);
		}
		if(getiniinfo(inifile,ls_ininame,"backuppassword",ls_tmpbuff)<0)
		{
			return -1;
		}
		else
		{
			if (f_pwd_decode(ls_tmpbuff,ls_str2)<=0)
			{
				return -1;
			}
			strcpy(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_password,ls_str2);
			printf("gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_password = %s\n",gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_password);
		}
		gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = NULL;
		gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = -1;
	}
	
	return 1;
}


/** @函数名 :str_redisconnect_info *f_get_redis_conn(int ai_redis, int ai_greenflag)
  *
  *  @函数功能: 获取一个空闲REDIS连接句柄
  * 							 
  *
  *  @param:  int ai_redis         ：簇号
  *           int ai_greenflag     ：句柄标识 1 绿色 0 非绿色
  *  @return :redis 句柄
  *  @retval
  *  @retval
  *  @note 
  */
str_redisconnect_info *f_get_redis_conn(int ai_num,int ai_redis, int ai_greenflag)
{
	int		li_max,li_min,li_p;

	/* 查询一个空闲的连接 */

	if(ai_greenflag)
	{
	    li_max	= gstr_redis_info[ai_num].gstr_redis[ai_redis].maxconnect;

	    if(gstr_redis_info[ai_num].gstr_redis[ai_redis].maxconnect <=4)
	    {
	        li_min = 0;
	    }
	    else
	    {
	        li_min = gstr_redis_info[ai_num].gstr_redis[ai_redis].maxconnect * 3/4;
	    }

        li_p = gstr_redis_info[ai_num].gstr_redis[ai_redis].redis_conn_green_p;

        if(li_p < li_min)
        {
            li_p = li_min;
        }


	    if (li_max<=0)
        {
            return NULL;
        }

        for (; li_p<li_max; li_p++)
            if (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].enabled==1 && (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].isbusy==0))
                break;

        if (li_p==li_max)
            for (li_p=0; li_p<li_max; li_p++)
                if (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].enabled==1 && (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].isbusy==0))
                    break;

     //   if (li_p==li_max)
      //      for (li_p=0; li_p<li_max; li_p++)
       //         if (gstr_redis[ai_redis].connectinfo[li_p].enabled==1)
       //             break;

        if (li_p==li_max || li_max==0)
        {
            return NULL;
        }

        gstr_redis_info[ai_num].gstr_redis[ai_redis].redis_conn_green_p = (li_p + 1) % li_max;
	}
	else
	{
	    if(gstr_redis_info[ai_num].gstr_redis[ai_redis].maxconnect <=4)
	    {
	        li_max	= gstr_redis_info[ai_num].gstr_redis[ai_redis].maxconnect;
	    }
	    else
	    {
	        li_max	= gstr_redis_info[ai_num].gstr_redis[ai_redis].maxconnect * 3/4;
	    }

	    li_p = gstr_redis_info[ai_num].gstr_redis[ai_redis].redis_conn_p;

	    if (li_max<=0)
	        {
	            return NULL;
	        }

        for (;li_p<li_max;li_p++)
            if (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].enabled==1 && (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].isbusy==0))
                break;

        if (li_p==li_max)
            for (li_p=0;li_p<li_max;li_p++)
                if (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].enabled==1 && (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].isbusy==0))
                    break;

    //    if (li_p==li_max)
     //       for (li_p=0;li_p<li_max;li_p++)
      //          if (gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p].enabled==1)
       //             break;

        if (li_p==li_max || li_max==0)
        {
            return NULL;
        }

        gstr_redis_info[ai_num].gstr_redis[ai_redis].redis_conn_p = (li_p + 1) % li_max;
	}

	return &(gstr_redis_info[ai_num].gstr_redis[ai_redis].connectinfo[li_p]);
}
/** @函数名 :int redis_colonyinfo_free(int num)
  *
  *  @函数功能: redis 连接信息同步线程
  * 							 
  *
  *  @param: num 为集群编号
  * 		
  *  @return :成功为1；失败为-1
  *  @retval
  *  @retval
  *  @note 
  */
int redis_colonyinfo_free(int num)
{
	int li_i = 0;
	int li_j = 0;
	if(num < 0||num >=  REDIS_COLONY)return -1;
	if(gstr_redis_info[num].enable == 1)
	{
		gstr_redis_info[num].enable = 0;
		for(li_i = 0;li_i < REDIS_COUNT;li_i++)
		{
			if(gstr_redis_info[num].gstr_redis[li_i].redis_enable == 1)
			{
				pthread_mutex_lock(&(gstr_redis_info[num].gstr_redis[li_i].mux_connectredis));
				gstr_redis_info[num].gstr_redis[li_i].redis_enable = 0;
				for(li_j = 0;li_j < gstr_redis_info[num].gstr_redis[li_i].maxconnect;li_j++)
				{
					pthread_mutex_lock(&(gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].mutx));
					gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].enabled = 0;
					gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].isbusy = 0;
					redisFree(gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].rediscontext);
					
					pthread_mutex_unlock(&(gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].mutx));
				}
				gstr_redis_info[num].gstr_redis[li_i].maxconnect = 0;
				pthread_mutex_unlock(&(gstr_redis_info[num].gstr_redis[li_i].mux_connectredis));
			}
			
		}
		for(li_i = 0;li_i < REDIS_QUEUE_COUNT;li_i++)
		{
			gstr_redis_info[num].gstr_key[li_i].enable = 0;
			memset(gstr_redis_info[num].gstr_key[li_i].virtual_key_name,0,REDIS_COUNT*sizeof(str_virtual_key_name));
		}
		return 1;
	}
	return -1;
}

/** @函数名 :int redis_colonyinfo_init(redisContext *rediscontext,int num)
  *
  *  @函数功能: redis 连接信息同步处理函数
  * 							 
  *
  *  @param:rediscontext:redis连接句柄
  *					num :集群编号
  * 		
  *  @return :成功为1；失败为-1
  *  @retval
  *  @retval
  *  @note 
  */

int redis_colonyinfo_init(redisContext *rediscontext,int num)
{
	int li_i = 0;
	int li_j = 0;
	int li_k = 0;
	int li_count = 0;
	int slotdiffentflag = 0;
	int newpointflag = 0;
	char tmpname[50] = {0};
	redis_info redisinfo[REDIS_COUNT];
	redisReply *reply;
	char error = 0;
	unsigned int li_slot = 0;
	int size = 0;
	int ret = 0;
	pthread_t	hThread;
	pthread_attr_t 	lattr;
	redis_pthread_info pthreadinfo;
	
	
	reply = redisCommand(rediscontext, "CLUSTER SLOTS");
	if(reply == NULL)
	{ 
	            return -1;
	}
	/*解析redis节点信息*/
    	if (reply->type == REDIS_REPLY_ARRAY)
    	{
		printf("count = %d\n",reply->elements);
        		for(li_i=0; li_i<reply->elements; li_i++)
        		{
        			redisinfo[li_i].enable = 1;
					
            		if(reply->element[li_i]->type != REDIS_REPLY_NIL)
            		{
				redisinfo[li_i].minslot = reply->element[li_i]->element[0]->integer;
				redisinfo[li_i].maxslot = reply->element[li_i]->element[1]->integer;
				if(reply->element[li_i]->element[2]->type != REDIS_REPLY_NIL)
				{
					strcpy(redisinfo[li_i].ip,reply->element[li_i]->element[2]->element[0]->str);
					redisinfo[li_i].port = reply->element[li_i]->element[2]->element[1]->integer;
				}
            		}
			printf("集群节点%d 数据:\n",li_i);
			printf("minslot = %d\n",redisinfo[li_i].minslot);
			printf("maxslot = %d\n",redisinfo[li_i].maxslot);
			printf("ip = %s\n",redisinfo[li_i].ip);
			printf("port = %d\n",redisinfo[li_i].port);
			li_count++;
        		}
	}
	freeReplyObject(reply);
	/*redis节点信息管理*/
	if(gstr_redis_info[num].enable == 0)/*集群添加*/
	{
		gstr_redis_info[num].enable = 1;
		gstr_redis_info[num].redis_key_count = 0;
		for(li_i = 0;li_i < REDIS_QUEUE_COUNT;li_i++)
		{
			gstr_redis_info[num].gstr_key[li_i].enable = 0;
		}
		for(li_i = 0;li_i < li_count;li_i++)
		{
			gstr_redis_info[num].redis_count++;
			gstr_redis_info[num].gstr_redis[li_i].redis_enable = 1;
			gstr_redis_info[num].gstr_redis[li_i].redis_cmp_flag = 0;
			strcpy(gstr_redis_info[num].gstr_redis[li_i].ip,redisinfo[li_i].ip);
			gstr_redis_info[num].gstr_redis[li_i].port = redisinfo[li_i].port;
			strcpy(gstr_redis_info[num].gstr_redis[li_i].username,redisinfo[li_i].username);
			strcpy(gstr_redis_info[num].gstr_redis[li_i].password,redisinfo[li_i].password);
			gstr_redis_info[num].gstr_redis[li_i].redis_min_slot = redisinfo[li_i].minslot;
			gstr_redis_info[num].gstr_redis[li_i].redis_max_slot = redisinfo[li_i].maxslot;
			pthread_mutex_destroy(&(gstr_redis_info[num].gstr_redis[li_i].mux_connectredis));
			pthread_mutex_init(&(gstr_redis_info[num].gstr_redis[li_i].mux_connectredis),NULL);
			redis_connect(&gstr_redis_info[num].gstr_redis[li_i],gstr_redis_manageinfo.redis_connectcount,&error);
		}
		return 1;
	}
	else/*集群信息对比*/
	{
		for(li_i = 0;li_i < li_count;li_i++)
		{
			for(li_j = 0;li_j < REDIS_COUNT;li_j++)
			{
				if(gstr_redis_info[num].gstr_redis[li_j].redis_enable == 1
					&&strcmp(redisinfo[li_i].ip,gstr_redis_info[num].gstr_redis[li_j].ip) == 0
					&&redisinfo[li_i].port == gstr_redis_info[num].gstr_redis[li_j].port)
				{
					if(gstr_redis_info[num].gstr_redis[li_j].redis_max_slot == redisinfo[li_i].maxslot
						&&gstr_redis_info[num].gstr_redis[li_j].redis_min_slot == redisinfo[li_i].minslot)
					{
						gstr_redis_info[num].gstr_redis[li_j].redis_cmp_flag = 1;/*节点没有编号*/
						printf("节点%d 没有变化\n",li_j);
					}
					else
					{
						gstr_redis_info[num].gstr_redis[li_j].redis_cmp_flag = 2;/*节点槽发生了变化\n*/
						printf("节点%d槽发生了变化\n",li_j);
					}
					break;
				}
				
				
			}
			if(li_j == REDIS_COUNT)/*新增节点*/
			{
				for(li_k = 0;li_k < REDIS_COUNT;li_k++)
				{
					if(gstr_redis_info[num].gstr_redis[li_k].redis_enable == 0)
					{
						gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].redis_enable = 1;
						gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].redis_cmp_flag = 3;
						strcpy(gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].ip,redisinfo[li_i].ip);
						gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].port = redisinfo[li_i].port;
						strcpy(gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].username,redisinfo[li_i].username);
						strcpy(gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].password,redisinfo[li_i].password);
						gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].redis_min_slot = redisinfo[li_i].minslot;
						gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].redis_max_slot = redisinfo[li_i].maxslot;
						pthread_mutex_destroy(&(gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].mux_connectredis));
						pthread_mutex_init(&(gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count].mux_connectredis),NULL);
						redis_connect(&gstr_redis_info[num].gstr_redis[gstr_redis_info[num].redis_count],gstr_redis_manageinfo.redis_connectcount,&error);
						gstr_redis_info[num].redis_count++;
					}
				}
			}

		}
		/*对 对比后的结果进行处理*/
		for(li_i = 0;li_i < REDIS_COUNT;li_i++)
		{
			if(gstr_redis_info[num].gstr_redis[li_i].redis_enable == 1)
			{
				if(gstr_redis_info[num].gstr_redis[li_i].redis_cmp_flag == 0)
				{
					pthread_mutex_lock(&(gstr_redis_info[num].gstr_redis[li_i].mux_connectredis));
					gstr_redis_info[num].gstr_redis[li_i].redis_enable = 0;
					for(li_j = 0;li_j < gstr_redis_info[num].gstr_redis[li_i].maxconnect;li_j++)
					{
						pthread_mutex_lock(&(gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].mutx));
						gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].enabled = 0;
						redisFree(gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].rediscontext);
						pthread_mutex_unlock(&(gstr_redis_info[num].gstr_redis[li_i].connectinfo[li_j].mutx));
					}
					pthread_mutex_unlock(&(gstr_redis_info[num].gstr_redis[li_i].mux_connectredis));
					gstr_redis_info[num].redis_count--;
					/*删除节点后key值管理*/
					for(li_j = 0;li_j < REDIS_QUEUE_COUNT;li_j++)
					{
						if(gstr_redis_info[num].gstr_key[li_j].enable == 1)
						{
							pthread_mutex_lock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
							gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].enable = 0;
							pthread_mutex_unlock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
						}
					}
					
				}
				else if(gstr_redis_info[num].gstr_redis[li_i].redis_cmp_flag == 2)
				{
					for(li_j = 0;li_j < REDIS_QUEUE_COUNT;li_j++)
					{
						if(gstr_redis_info[num].gstr_key[li_j].enable == 1)
						{
							pthread_mutex_lock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
							if(gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].enable == 1)
							{
								li_slot = HASH_SLOT(gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].virtual_key_name,
									strlen(gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].virtual_key_name));
								if(!(li_slot >= gstr_redis_info[num].gstr_redis[li_i].redis_min_slot
									&&li_slot <= gstr_redis_info[num].gstr_redis[li_i].redis_max_slot))
								{
									for(li_k = 0;li_k < REDIS_VIRTUAL_KEY;li_k++)
									{
										
										sprintf(tmpname,"%s_%d",gstr_redis_info[num].gstr_key[li_j].host_key_name,li_k);
										li_slot = (crc16(tmpname, strlen(tmpname))&16383);
										if(gstr_redis_info[num].gstr_redis[li_i].redis_min_slot <= li_slot&&gstr_redis_info[num].gstr_redis[li_i].redis_max_slot >= li_slot)
										{
											break;
										}
									}
									strcpy(gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].virtual_key_name,tmpname);
									if(gstr_redis_info[num].gstr_key[li_j].get_value_flag == 1)
									{
										strcpy(pthreadinfo.key,gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].virtual_key_name);
										pthreadinfo.colonynum = num;
										pthreadinfo.redisnum = li_i;
										pthreadinfo.af_func = gstr_redis_info[num].gstr_key[li_j].af_func;
										size = 1024*1024;
										set_pthread_stack(size,&lattr);
										for(li_k = 0;li_k < gstr_redis_manageinfo.redis_queue_pthreadcount;li_k++)
										{	
											pthread_mutex_lock(&gt_redis_creatpthread_mux);
											ret = pthread_create(&hThread ,&lattr ,f_thread_redis_list_deal ,(void*)(&pthreadinfo));
											if(ret != 0)
											{
												pthread_mutex_unlock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
												pthread_mutex_unlock(&gt_redis_creatpthread_mux);
												exit(0);
											}
											pthread_mutex_lock(&gt_redis_creatpthread_mux);
											pthread_mutex_unlock(&gt_redis_creatpthread_mux);
											pthread_detach(hThread);
										}

									}
								}
							}
							pthread_mutex_unlock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
						}
					}
				}
				else if(gstr_redis_info[num].gstr_redis[li_i].redis_cmp_flag == 3)
				{
					for(li_j = 0;li_j < REDIS_QUEUE_COUNT;li_j++)
					{
						if(gstr_redis_info[num].gstr_key[li_j].enable == 1)
						{
							pthread_mutex_lock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
							
							for(li_k = 0;li_k < REDIS_VIRTUAL_KEY;li_k++)
							{
								
								sprintf(tmpname,"%s_%d",gstr_redis_info[num].gstr_key[li_j].host_key_name,li_k);
								li_slot = (crc16(tmpname, strlen(tmpname))&16383);
								if(gstr_redis_info[num].gstr_redis[li_i].redis_min_slot <= li_slot&&gstr_redis_info[num].gstr_redis[li_i].redis_max_slot >= li_slot)
								{
									break;
								}
							}
							gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].enable =1;
							strcpy(gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].virtual_key_name,tmpname);
							if(gstr_redis_info[num].gstr_key[li_j].get_value_flag == 1)
							{
								strcpy(pthreadinfo.key,gstr_redis_info[num].gstr_key[li_j].virtual_key_name[li_i].virtual_key_name);
								pthreadinfo.colonynum = num;
								pthreadinfo.redisnum = li_i;
								pthreadinfo.af_func = gstr_redis_info[num].gstr_key[li_j].af_func;
								size = 1024*1024;
								set_pthread_stack(size,&lattr);
								for(li_k = 0;li_k < gstr_redis_manageinfo.redis_queue_pthreadcount;li_k++)
								{	
									pthread_mutex_lock(&gt_redis_creatpthread_mux);
									ret = pthread_create(&hThread ,&lattr ,f_thread_redis_list_deal ,(void*)(&pthreadinfo));
									if(ret != 0)
									{
										pthread_mutex_unlock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
										pthread_mutex_unlock(&gt_redis_creatpthread_mux);
										exit(0);
									}
									pthread_mutex_lock(&gt_redis_creatpthread_mux);
									pthread_mutex_unlock(&gt_redis_creatpthread_mux);
									pthread_detach(hThread);
								}

							}
							pthread_mutex_unlock(&(gstr_redis_info[num].gstr_key[li_j].mux_key));
						}
					}
				}
			}
		}
		return 1;
	}
	return -1;
}

/** @函数名 :void*f_redisinfo_manage(void *pvParam)
  *
  *  @函数功能: redis 连接信息同步线程
  * 							 
  *
  *  @param:  pvParam 为NULL
  * 		
  *  @return :
  *  @retval
  *  @retval
  *  @note 
  */
void* f_redisinfo_manage(void *pvParam)
{
	int li_i = 0;
	int li_j = 0;
	int ret = 0;
	redis_info redisinfo[REDIS_COUNT];
	
	struct timeval timeout = { 1, 500000 }; // 1.5 seconds
	while(1)
	{
		for(li_i = 0; li_i < gstr_redis_manageinfo.colony_count;li_i++)
		{
			if(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].enable ==1&&gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext ==NULL
				&&gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag == -1)
			{
				gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = redisConnectWithTimeout(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_ip, 
				gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_port, timeout);
			        if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext == NULL || (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)->err)
			        {
			            if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)
			            {
				                redisFree(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext);
					       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = NULL;
			            }
				   	gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = redisConnectWithTimeout(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_ip, 
					gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_port, timeout);
				        if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext == NULL || (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)->err)
				        {
				            if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)
				            {
					                redisFree(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext);
						       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = NULL;
				            }
					   
					   redis_colonyinfo_free(li_i);
					   printf("主备连接均失败\n");
				            continue;
				        }
					gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 0;
					redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
					printf("主连接失败，备连接成功\n");
					continue;
			        }
				
				gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 1;
				redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
				printf("主连接成功\n");
			}
			else
			{
				ret = redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
				if(ret == -1)
				{
					  if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)
				            {
					                redisFree(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext);
						       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = NULL;
				            }
					  if(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag == 0)/*目前连接的是备用IP*/
					{
						gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = redisConnectWithTimeout(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_ip, 
						gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_port, timeout);
					        if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext == NULL || (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)->err)
					        {
					            	if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)
					            	{
						                redisFree(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext);
							       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = NULL;
							       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = -1;
					            	}
						   	gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = redisConnectWithTimeout(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_ip, 
							gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].backup_port, timeout);
						        if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext == NULL || (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)->err)
						        {
						            if (gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext)
						            {
							                redisFree(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext);
								       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext = NULL;
								       gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = -1;
						            }
							   
							   redis_colonyinfo_free(li_i);
							   printf("1主备连接均失败\n");
						            continue;
						        }
							gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 0;
							redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
							printf("1主连接失败，备连接成功\n");
							continue;
					        }
						
						gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 1;
						redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
						printf("1主连接成功\n");
					  }
				}
			}
		}
		sleep(REDIS_SYNC_TIME);
	}
}
/** @函数名 :int f_thread_redis_list_deal(void *pvParam)
  *
  *  @函数功能: 队列元素获取处理线程
  * 							 
  *
  *  @param:  pvParam     ：
  * 		 
  * 		
  *  @return :1表示成功，-1表示失败
  *  @retval
  *  @retval
  *  @note 
  */
void* f_thread_redis_list_deal(void *pvParam)
{
	char ls_data[1][REDIS_BUFF_MAXLEN];
	char ls_sendbuff[REDIS_BUFF_MAXLEN+30];
	int ls_framelen = 0;
	int ls_datalen = 0;
	int ls_sendlen = 0;
	char ls_str[100];
	int ls_indx = 0;
	int ls_ret = 0;
	int ls_count = 0;
	int li_i = 0;
	int li_sock = -1;
	str_redis_info astr_redis;
	redis_pthread_info pthreadinfo;
	pthreadinfo = *(redis_pthread_info*)(pvParam);
	printf("key = %s,colonynum = %d,redisnum = %d\n",pthreadinfo.key,pthreadinfo.colonynum,pthreadinfo.redisnum);
	pthread_mutex_unlock(&gt_redis_creatpthread_mux);
	if(pthreadinfo.key == NULL||pthreadinfo.colonynum >= REDIS_COLONY||pthreadinfo.redisnum >= REDIS_COUNT)
	{
		pthread_exit(NULL);
	}
	strcpy(astr_redis.ip,gstr_redis_info[pthreadinfo.colonynum].gstr_redis[pthreadinfo.redisnum].ip);
	astr_redis.port = gstr_redis_info[pthreadinfo.colonynum].gstr_redis[pthreadinfo.redisnum].port;
	strcpy(astr_redis.username,gstr_redis_info[pthreadinfo.colonynum].gstr_redis[pthreadinfo.redisnum].username);
	strcpy(astr_redis.password,gstr_redis_info[pthreadinfo.colonynum].gstr_redis[pthreadinfo.redisnum].password);
	astr_redis.maxconnect = 0;
	while(1)
	{
		
		if ((ls_indx = redis_connect(&astr_redis, 1, ls_str)) < 0)
		{
			astr_redis.maxconnect = 0;
			ls_ret = pthread_judge_key(pthreadinfo.key,pthreadinfo.colonynum,pthreadinfo.redisnum);
			if(ls_ret == -1)
			{
				pthread_exit(NULL);
			}
			sleep(30);				
			continue;
		}
		
		do
		{

			/* 阻塞等待有数据发送过来，返回0表示连接中断 */
			ls_ret =  brpop_rdvalue(astr_redis.connectinfo[ls_indx].rediscontext,pthreadinfo.key,pthreadinfo.timeount,(char**)ls_data,REDIS_BUFF_MAXLEN,&ls_count);
			if (ls_ret == 0)	/* 连接中断 */
			{
				redis_disconnect(astr_redis.connectinfo[ls_indx].rediscontext);
				
				astr_redis.maxconnect = 0;
				
				break;
			}
			else if(ls_ret == -1)
			{
				ls_ret = pthread_judge_key(pthreadinfo.key,pthreadinfo.colonynum,pthreadinfo.redisnum);
				if(ls_ret == -1)
				{
					pthread_exit(NULL);
				}
				continue;
			}
			else if(ls_ret == 1)
			{	
				printf("使用key值 = %s,接收的数据= %s，长度= %d\n",pthreadinfo.key,ls_data[0],strlen(ls_data[0]));
				pthreadinfo.af_func(ls_data[0],strlen(ls_data[0]));
			}

		} while(1);
	}
}
/** @函数名 :int redis_get_mutex(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能: 获取基于REDIS的系统锁
  * 							 
  *
  *  @param:  int ai_type：     redis句柄属性
  *		  ai_num:		集群编号
  * 		  ai_greenflag：    通道标识
  * 		  char *as_element：互斥锁属性
  * 		  int ttl:          互斥锁存活时间
  * 		
  *  @return :1 成功获得  0 获得锁失败
  *  @retval
  *  @retval
  *  @note 
  */
int redis_mutex_trylock(char *as_key, int ai_num,int ai_greenflag, redis_mutex_info *as_element,int ttl)
  {
	char ls_tmp[15]={0}, ls_order[RDS_QUEUE_ELEMENT_LEN + 20]={0};
    	int li_i;
    	redisReply *reply;
	datetime	ldt_now;
	f_get_datetime(&ldt_now);

    	str_redisconnect_info *lst_redis_conn;

    	li_i = get_redisnum(as_key,ai_num);
	if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
   	}
	lst_redis_conn->isbusy = 1;
	
	as_element->code_id[3] = '|';
	sprintf(as_element->creat_time,"%04d-%02d-%02d:%02d:%02d:%02d",ldt_now.year + 1900,ldt_now.mon,ldt_now.day,ldt_now.hour,ldt_now.min,ldt_now.sec);
	as_element->creat_time[19] = '|';
	as_element->creat_time[20] = 0;
 	sprintf(ls_order,"setnx %s %s",as_key,as_element->code_id);
	
	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	            return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	            lst_redis_conn->isbusy = 0;
	            pthread_mutex_unlock(&(lst_redis_conn->mutx));
	            return -1;
	        }
	}
   
    	if (reply->type == REDIS_REPLY_INTEGER)
    	{
       	 	li_i = reply->integer;
		if(1 == li_i)// 成功申请锁
		{
			// 设置键值存活时间
			if(1 == redis_set_ttl_mutex(as_key,ai_num,ai_greenflag,ttl))
			{
				// 设置存活时间成功
				li_i = 1;
			}
			else
			{
				// 删除KEY
				if(1 == exists_rd(as_key,ai_num,ai_greenflag))// 存在删除
				{
					if(1== delkey_rd(as_key,ai_num,ai_greenflag))
					{
						//
					}
					else
					{
						// 系统警告
					}
				}
				li_i = 0;
			}
		}
		else
		{
			li_i = 0;
		}
    }
    else
    {
        li_i = -1;
    }
    lst_redis_conn->isbusy = 0;

    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
  }
  
  /** @函数名 :int redis_get_mutex(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能: 获取基于REDIS的系统锁的信息
  * 							 
  *
  *  @param:  int ai_type：     redis句柄属性
  *		  ai_num:		集群编号
  * 		  ai_greenflag：    通道标识
  * 		  char *as_element：互斥锁属性
  * 		  int ttl:          互斥锁存活时间
  * 		
  *  @return :1 成功获得  0 获得锁失败
  *  @retval
  *  @retval
  *  @note 
  */
int redis_get_mutex_info(char *as_key, int ai_num,int ai_greenflag, redis_mutex_info *as_element)
{
	char ls_tmp[15]={0}, ls_order[RDS_QUEUE_ELEMENT_LEN + 20]={0};
    	int li_i = 0;
    	redisReply *reply;
	datetime	ldt_now;
	f_get_datetime(&ldt_now);

    	str_redisconnect_info *lst_redis_conn;

    	li_i = get_redisnum(as_key,ai_num);
	
 	sprintf(ls_order,"get %s",as_key);

    	if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;
	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	            lst_redis_conn->isbusy = 0;
	            pthread_mutex_unlock(&(lst_redis_conn->mutx));
	            return -1;
	        }
	}
   
    	if (reply->type == REDIS_REPLY_STRING)
    	{
       	 	li_i = reply->integer;
		memcpy(as_element->code_id,reply->str,4);
		as_element->code_id[3] = 0;
		memcpy(as_element->creat_time,reply->str + 4,25);
		as_element->creat_time[19] = 0;
    	}
    	else
    	{
        		li_i = -1;
    	}
    	lst_redis_conn->isbusy = 0;

    	freeReplyObject(reply);

    	pthread_mutex_unlock(&(lst_redis_conn->mutx));

    	return li_i;
  }
  
  /** @函数名 :int redis_mutex_destroy(char *as_key, int ai_greenflag)
  *
  *  @函数功能: 设置KEY值存活时间
  * 							 
  *
  *  @param:  char *as_key：     redis句柄属性
  *		  ai_num:		集群编号
  * 		  ai_greenflag：    通道标识
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int redis_mutex_destroy(char *as_key,int ai_num, int ai_greenflag)
{
     	int li_i = -1;
	int li_ret = 0;
	li_ret = redis_get_ttl(as_key, ai_num,ai_greenflag);
	if(li_ret>= 0)//存在需要删除
	{
		if(1== delkey_rd(as_key,ai_num,ai_greenflag))
		{
			// 
			li_i = 0;
		}
		else
		{
			// 系统警告
		}
	}
	else if(-1 ==li_ret)// 异常错误
	{
		if(1== delkey_rd(as_key,ai_num,ai_greenflag))
		{
			//
			li_i = 0;
		}
		else
		{
			// 系统警告
		}
	}
	else if(-2 ==li_ret)// 已经删除
	{
		
	}
	else
	{
		if(1== delkey_rd(as_key,ai_num,ai_greenflag))
		{
			//
			li_i = 0;
		}
		else
		{
			// 系统警告
		}
	}
	return li_i;
}
 
  /** @函数名 : int judge_key_isornot(char *as_key,int ai_num )
  *
  *  @函数功能: 判断key值是否存在
  * 							 
  *
  *  @param:  as_key :对外key值
  *			ai_num:集群编号
  * 		
  *  @return :大于等于0表示key值位置，-1表示没有
  *  @retval
  *  @retval
  *  @note 
  */
int judge_key_isornot(char *as_key,int ai_num)
{
	int li_i = 0;
	if(as_key == NULL||ai_num >= REDIS_COLONY)
	{
		return -1;
	}
	for(li_i = 0;li_i < REDIS_QUEUE_COUNT;li_i++)
	{
		if(gstr_redis_info[ai_num].gstr_key[li_i].enable == 1)
		{
			if(strcmp(as_key,gstr_redis_info[ai_num].gstr_key[li_i].host_key_name) == 0)
			{
				return li_i;
			}
		}
	}
	return -1;	
}

   /** @函数名 : int pthread_judge_key(char *as_key,int ai_num,int ai_redisnum)
  *
  *  @函数功能: 判断key值是否存在
  * 							 
  *
  *  @param:  as_key :对外key值
  *			ai_num:集群编号
  *			ai_redisnum: redis节点编号
  * 		
  *  @return :1表示有，-1表示没有
  *  @retval
  *  @retval
  *  @note 
  */
int pthread_judge_key(char *as_key,int ai_num,int ai_redisnum)
{
	int li_i = 0;
	
	if(as_key == NULL||ai_num >= REDIS_COLONY||ai_redisnum >= REDIS_COUNT)
	{
		return -1;
	}
	for(li_i = 0;li_i < REDIS_QUEUE_COUNT;li_i++)
	{
		if(gstr_redis_info[ai_num].gstr_key[li_i].enable == 1)
		{
			if(gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[ai_redisnum].enable == 1
				&&strcmp(as_key,gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[ai_redisnum].virtual_key_name) == 0)
			{
				return 1;
			}
		}
	}
	return -1;	
}
    /** @函数名 : int get_virtaul_key(char *as_key,int ai_num,char* as_virkey )
  *
  *  @函数功能: 初始化redis队列虚拟key值
  * 							 
  *
  *  @param:  as_key :对外key值
  *			ai_num:集群编号
  *			as_virkey返回的虚拟key值
  * 		
  *  @return :大于等于0表示redis节点下标，-1表示失败
  *  @retval
  *  @retval
  *  @note 
  */
int get_virtaul_key(char *as_key,int ai_num,char* as_virkey)
{
	int li_i = 0;
	int li_j = 0;
	int count = 0;
	if(as_key == NULL||ai_num >= REDIS_COLONY||as_virkey==NULL)
	{
		return -1;
	}
	for(li_i = 0;li_i < REDIS_QUEUE_COUNT;li_i++)
	{
		if(gstr_redis_info[ai_num].gstr_key[li_i].enable == 1)
		{
			if(strcmp(as_key,gstr_redis_info[ai_num].gstr_key[li_i].host_key_name) == 0)
			{
				pthread_mutex_lock(&(gstr_redis_info[ai_num].gstr_key[li_i].mux_key));
				count = gstr_redis_info[ai_num].gstr_key[li_i].count;
				for(li_j = count;li_j < REDIS_COUNT;li_j++)
				{
					gstr_redis_info[ai_num].gstr_key[li_i].count = (gstr_redis_info[ai_num].gstr_key[li_i].count+1)%REDIS_COUNT;
					if(gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[li_j].enable == 1)
					{
						printf("num = %d,key = %s\n",gstr_redis_info[ai_num].gstr_key[li_i].count,gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[li_j].virtual_key_name);
						strcpy(as_virkey,gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[li_j].virtual_key_name);
						pthread_mutex_unlock(&(gstr_redis_info[ai_num].gstr_key[li_i].mux_key));
						return li_j;
					}
				}
				pthread_mutex_unlock(&(gstr_redis_info[ai_num].gstr_key[li_i].mux_key));
				return -1;
			}
		}
	}
	return -1;	
}
 
/** @函数名 :int redis_colony_init()
  *
  *  @函数功能: 初始化redis集群函数
  * 							 
  *
  *  @param:  无
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int redis_colony_init()
{
    pthread_t	hThread;
    int ret = 0;
    if(redis_cfg_init()==1)
    {
	ret = pthread_create(&hThread ,NULL ,f_redisinfo_manage ,NULL);
	if(ret != 0)
	{
		exit(0);
	}
	pthread_detach(hThread);
	return 1;
    }
    else
    {
        return -1;
    }
}
 /** @函数名 : int get_virtaul_key(char *as_key,int ai_num )
  *
  *  @函数功能: 初始化redis队列虚拟key值
  * 							 
  *
  *  @param:  as_key :对外key值
  *			ai_num:集群编号
  *
  *  @return :1表示成功，-1表示失败
  *  @retval
  *  @retval
  *  @note 
  */
int creat_virtaul_key(char *as_key,int ai_num)
{
	int li_i = 0;
	int li_j = 0;
	int ret = 0;
	int len = 0;
	unsigned short slot = 0;
	char tmpname[50] = {0};
	if(as_key == NULL||ai_num >= REDIS_COLONY)
	{
		return -1;
	}
	ret = judge_key_isornot(as_key,ai_num);
	if(ret == -1)/*初始化使用*/
	{
		gstr_redis_info[ai_num].gstr_key[gstr_redis_info[ai_num].redis_key_count].enable = 1;
		strcpy(gstr_redis_info[ai_num].gstr_key[gstr_redis_info[ai_num].redis_key_count].host_key_name,as_key);
		pthread_mutex_destroy(&(gstr_redis_info[ai_num].gstr_key[gstr_redis_info[ai_num].redis_key_count].mux_key));
		pthread_mutex_init(&(gstr_redis_info[ai_num].gstr_key[gstr_redis_info[ai_num].redis_key_count].mux_key),NULL);
		for(li_i = 0;li_i < REDIS_COUNT;li_i++)
		{
			if(gstr_redis_info[ai_num].gstr_redis[li_i].redis_enable == 1)
			{
				
				for(li_j = 0;li_j < REDIS_VIRTUAL_KEY;li_j++)
				{
					
					sprintf(tmpname,"%s_%d",as_key,li_j);
					len = strlen(tmpname);
					slot = (crc16(tmpname, len)&16383);
					if(gstr_redis_info[ai_num].gstr_redis[li_i].redis_min_slot <= slot&&gstr_redis_info[ai_num].gstr_redis[li_i].redis_max_slot >= slot)
					{
						printf("生成key值 = %s,槽值 = %d\n",tmpname,slot);
						break;
					}
				}
				strcpy(gstr_redis_info[ai_num].gstr_key[gstr_redis_info[ai_num].redis_key_count].virtual_key_name[li_i].virtual_key_name,tmpname);
				gstr_redis_info[ai_num].gstr_key[gstr_redis_info[ai_num].redis_key_count].virtual_key_name[li_i].enable = 1;
				
			}
		}
		gstr_redis_info[ai_num].redis_key_count++;
		return 1;
	}
	return -1;
}
  
/** @函数名 :int redis_exit()
  *
  *  @函数功能: 程序退出释放redis句柄信息
  * 							 
  *
  *  @param:  
  *           
  *  @return :
  *  @retval
  *  @retval
  *  @note 
  */
int redis_exit()
{
    int li_i, li_j,li_k;

    for(li_i = 0;li_i < REDIS_COLONY;li_i++)
    {
    	 if(gstr_redis_info[li_i].enable == 1)
    	 {
    	 	    for(li_j=0; li_j<REDIS_COUNT; li_j++)
		    {
		    	if(gstr_redis_info[li_i].gstr_redis[li_j].redis_enable == 1)
			 {
			 	for(li_k=0; li_k<gstr_redis_info[li_i].gstr_redis[li_j].maxconnect; li_k++)
			        {
			            redisFree(gstr_redis_info[li_i].gstr_redis[li_j].connectinfo[li_k].rediscontext);

			            pthread_mutex_destroy(&(gstr_redis_info[li_i].gstr_redis[li_j].connectinfo[li_k].mutx));
			        }

			        gstr_redis_info[li_i].gstr_redis[li_j].maxconnect = 0;
			        pthread_mutex_destroy(&(gstr_redis_info[li_i].gstr_redis[li_j].mux_connectredis));
		    	}
		    }
    	 }
    }
    return 1;
}


/** @函数名 :int redis_disconnect(redisContext *arc_rediscontext)
  *
  *  @函数功能: 释放redis连接句柄
  * 							 
  *
  *  @param:  redisContext *arc_rediscontext
  * 		  
  * 		  
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int redis_disconnect(redisContext *arc_rediscontext)
{
    redisFree(arc_rediscontext);
    return 1;
}
/** @函数名 :int redis_connect(str_redis_info *astr_redis, int ai_num, char *as_error)
  *
  *  @函数功能: 初始化非阻塞redis句柄函数
  * 							 
  *
  *  @param:  str_redis_info *astr_redis ：句柄结构体
  * 		  int ai_num    句柄个数
  * 		  char *as_error
  * 		  char *as_error ：返回错误信息
  * 		
  *  @return :>=0 成功
             -101 连接数据库失败
             -102 用户名或者密码验证失败
  *  @retval
  *  @retval
  *  @note 
  */
int redis_connect(str_redis_info *astr_redis, int ai_num, char *as_error)
{
    char ls_hostname[20]={0};
    char ls_username_password[128]={0};
    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    redisReply *reply;
    int li_i;

    if(strlen(astr_redis->ip) == 0)
    {
        strcpy(ls_hostname,"127.0.0.1");
    }
    else
    {
        strcpy(ls_hostname,astr_redis->ip);
    }
printf("host = %s,port = %d\n",ls_hostname,astr_redis->port);
    pthread_mutex_lock(&(astr_redis->mux_connectredis));
    li_i = astr_redis->maxconnect;

    for(; li_i<ai_num; li_i++)
    {
        astr_redis->connectinfo[li_i].rediscontext = redisConnectWithTimeout(ls_hostname, astr_redis->port, timeout);
        if (astr_redis->connectinfo[li_i].rediscontext == NULL || (astr_redis->connectinfo[li_i].rediscontext)->err)
        {
            if (astr_redis->connectinfo[li_i].rediscontext)
            {
                sprintf(as_error,"Connection error: %s\n", (astr_redis->connectinfo[li_i].rediscontext)->errstr);
                redisFree(astr_redis->connectinfo[li_i].rediscontext);
            }
            else
            {
                sprintf(as_error,"Connection error: can't allocate redis context\n");
            }

            pthread_mutex_unlock(&(astr_redis->mux_connectredis));
            return -101;
        }

        /* AUTH requirepass 
        sprintf(ls_username_password, "%s %s", astr_redis->username, astr_redis->password);
        reply = redisCommand(astr_redis->connectinfo[li_i].rediscontext, ls_username_password);
        if(reply == NULL)
        	{
		sprintf(as_error,"用户名或者密码验证命令执行失败");
		pthread_mutex_unlock(&(astr_redis->mux_connectredis));
           	 return -102;
        	}
        else if(strcmp(reply->str,"OK") != 0)
        {
            freeReplyObject(reply);
            sprintf(as_error,"用户名或者密码验证失败");
            pthread_mutex_unlock(&(astr_redis->mux_connectredis));
            return -103;
        }
        freeReplyObject(reply);
*/
        astr_redis->maxconnect = astr_redis->maxconnect +1;
        astr_redis->redis_conn_p = 0;
        astr_redis->redis_conn_green_p = 0;
        astr_redis->connectinfo[li_i].enabled = 1;
        astr_redis->connectinfo[li_i].isbusy = 0;
        pthread_mutex_destroy(&(astr_redis->connectinfo[li_i].mutx));
        pthread_mutex_init(&(astr_redis->connectinfo[li_i].mutx),NULL);
    }

    pthread_mutex_unlock(&(astr_redis->mux_connectredis));

    return astr_redis->maxconnect - 1;//返回下标
}

/** @函数名 :int redis_reconnect(int ai_type, redisContext *arc_rediscontext)
  *
  *  @函数功能: 初始化非阻塞redis句柄函数
  * 							 
  *
  *  @param:  int ai_type ： 句柄列表下标
  * 		  redisContext *arc_rediscontext ：redis实体句柄
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int redis_reconnect(int ai_num,int ai_type, redisContext *arc_rediscontext)
{
	    char ls_hostname[20]={0};
	    char ls_username_password[128]={0};
	    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
	    redisReply *reply;
	    int li_i;

	    if(strlen(gstr_redis_info[ai_num].gstr_redis[ai_type].ip) == 0)
	    {
	        strcpy(ls_hostname,"127.0.0.1");
	    }
	    else
	    {
	        strcpy(ls_hostname,gstr_redis_info[ai_num].gstr_redis[ai_type].ip);
	    }

	    pthread_mutex_lock(&(gstr_redis_info[ai_num].gstr_redis[ai_type].mux_connectredis));

	    arc_rediscontext = redisConnectWithTimeout(ls_hostname, gstr_redis_info[ai_num].gstr_redis[ai_type].port, timeout);
	    if (arc_rediscontext == NULL || arc_rediscontext->err)
	    {
	        if(arc_rediscontext)
	        {
	            redisFree(arc_rediscontext);
	        }
	        pthread_mutex_unlock(&(gstr_redis_info[ai_num].gstr_redis[ai_type].mux_connectredis));
	        return -101;
	    }

	    pthread_mutex_unlock(&(gstr_redis_info[ai_num].gstr_redis[ai_type].mux_connectredis));

	    return 1;
}




/** @函数名 :int lget_rdlist(char *as_key, int ai_num, int ai_overtime, char as_flag)
  *
  *  @函数功能: get队列元素
  * 							 
  *
  *  @param:  char *as_key     ：队列KEY值
  * 		  int ai_num ：集群编号
  * 		  int ai_overtime ：阻塞超时时间
  * 		  char as_flag:	是否使用虚拟队列0表示不用，1表示使用
  * 		
  *  @return :1表示成功，-1表示失败
  *  @retval
  *  @retval
  *  @note 
  */
int lbrget_rdlist(char *as_key, int ai_num,int ai_overtime, void (*af_func)(char *as_data,int ai_len),char as_flag)
{
	int li_i = 0;
	int li_j = 0;
	int li_k = 0;
	int size = 0;
	int ret = 0;
	pthread_t	hThread;
	pthread_attr_t 	lattr;
	redis_pthread_info pthreadinfo;
	size = 1024*1024;
	set_pthread_stack(size,&lattr);
	if(as_flag == 0)
	{
		li_i = get_redisnum(as_key,ai_num);
		if(li_i == 0xffff)
		{
			return -1;
		}
		else
		{
			
			
			strcpy(pthreadinfo.key,as_key);
			pthreadinfo.colonynum = ai_num;
			pthreadinfo.redisnum = li_i;
			pthreadinfo.timeount = ai_overtime;
			pthreadinfo.af_func = af_func;
			for(li_k = 0;li_k < gstr_redis_manageinfo.redis_queue_pthreadcount;li_k++)
			{	
				pthread_mutex_lock(&gt_redis_creatpthread_mux);
				ret = pthread_create(&hThread ,&lattr ,f_thread_redis_list_deal ,(void*)(&pthreadinfo));
				if(ret != 0)
				{
					pthread_mutex_unlock(&gt_redis_creatpthread_mux);
					exit(0);
				}
				pthread_mutex_lock(&gt_redis_creatpthread_mux);
				pthread_mutex_unlock(&gt_redis_creatpthread_mux);
				pthread_detach(hThread);
			}
			return 1;
		}
	}
	else
	{
		for(li_i = 0;li_i < REDIS_QUEUE_COUNT;li_i++)
		{
			if(gstr_redis_info[ai_num].gstr_key[li_i].enable == 1)
			{
				if(strcmp(as_key,gstr_redis_info[ai_num].gstr_key[li_i].host_key_name) == 0)
				{
					pthread_mutex_lock(&(gstr_redis_info[ai_num].gstr_key[li_i].mux_key));
					for(li_j = 0;li_j < REDIS_COUNT;li_j++)
					{
						if(gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[li_j].enable == 1)
						{
							gstr_redis_info[ai_num].gstr_key[li_i].get_value_flag = 1;
							gstr_redis_info[ai_num].gstr_key[li_i].af_func = af_func;
							strcpy(pthreadinfo.key,gstr_redis_info[ai_num].gstr_key[li_i].virtual_key_name[li_j].virtual_key_name);
							pthreadinfo.colonynum = ai_num;
							pthreadinfo.redisnum = li_j;
							pthreadinfo.timeount = ai_overtime;
							pthreadinfo.af_func = af_func;
							for(li_k = 0;li_k < gstr_redis_manageinfo.redis_queue_pthreadcount;li_k++)
							{
								pthread_mutex_lock(&gt_redis_creatpthread_mux);
								ret = pthread_create(&hThread ,&lattr ,f_thread_redis_list_deal ,(void*)(&pthreadinfo));
								if(ret != 0)
								{
									pthread_mutex_unlock(&(gstr_redis_info[ai_num].gstr_key[li_i].mux_key));
									pthread_mutex_unlock(&gt_redis_creatpthread_mux);
									exit(0);
								}
								pthread_detach(hThread);
								pthread_mutex_lock(&gt_redis_creatpthread_mux);
								pthread_mutex_unlock(&gt_redis_creatpthread_mux);
							}
						}
					}
					pthread_mutex_unlock(&(gstr_redis_info[ai_num].gstr_key[li_i].mux_key));
					return 1;
				}
			}
		}	
		return -1;
	}

}
/** @函数名 :int lpush_rdlist(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能: PUSH队列元素
  * 							 
  *
  *  @param:  char *as_key     ：队列KEY值
  * 		  int ai_num ：集群编号
  * 		  int ai_greenflag ：队列标识 0 普通队列 1绿色队列
  * 		  char *as_element ：数据内容
  * 		  char as_flag:	是否使用虚拟队列0表示不用，1表示使用
  * 		
  *  @return :1表示成功，-1表示失败
  *  @retval
  *  @retval
  *  @note 
  */
int lpush_rdlist(char *as_key,int ai_num, int ai_greenflag, char *as_element,char as_flag)
{
    	char ls_tmp[15]={0}, ls_order[RDS_QUEUE_ELEMENT_LEN + 20]={0};
    	int li_i, li_k,li_ret;
    	redisReply *reply;;
	char ls_virkey[50] = {0};
   	str_redisconnect_info *lst_redis_conn;

    	if(as_flag == 0)
    	{
    		li_i = get_redisnum(as_key,ai_num);
    		if(li_i == 0xffff)
		{
			return -1;
		}
		printf("**num = %d,key = %s\n",li_i,as_key);
		sprintf(ls_order,"LPUSH %s %s",as_key,as_element);
    	}
    	else 
   	{
		li_i = get_virtaul_key(as_key,ai_num,ls_virkey);
		if(li_i == -1)
		{
			return -1;
		}
		sprintf(ls_order,"LPUSH %s %s",ls_virkey,as_element);
    	}
	
	if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		redisFree(lst_redis_conn->rediscontext);	
		redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);
	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	            li_i = -1;
	        }
	        else
	        {
	            li_i = 1;
		   freeReplyObject(reply);
	        }
	}
	else
	{
	    li_i = 1;
	    freeReplyObject(reply);
	}
    lst_redis_conn->isbusy = 0;

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}

/** @函数名 :int lrange_rdlist(char *as_key, int ai_greenflag,int ai_start, int ai_stop, char** as_element,int len, int *ai_elementcount)
  *
  *  @函数功能: 获取队列中指定单个、多个元素下标数据
  * 							 
  *
  *  @param:  char *as_key     ：队列KEY值
   * 		  int ai_num ：集群编号
  * 		  int ai_greenflag ：队列标识 0 普通队列 1绿色队列
  * 		  int ai_start     : 起始位置
  *           int ai_stop      : 结束位置
  * 		  char as_element[][RDS_ELEMENT_LEN]：返回数组
  *           int *ai_elementcount              ：返回元素个数
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int lrange_rdlist(char *as_key,int ai_num, int ai_greenflag,int ai_start, int ai_stop, char** as_element,int len, int *ai_elementcount)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i, li_k;
    char* p = NULL;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;
    p = (char*)as_element;
    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"LRANGE %s %d %d",as_key,ai_start,ai_stop);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	 	redisFree(lst_redis_conn->rediscontext);
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	            lst_redis_conn->isbusy = 0;
	            pthread_mutex_unlock(&(lst_redis_conn->mutx));
	            return -1;
	        }
	}

   	 else if (reply->type == REDIS_REPLY_ARRAY)
   	 {
	        li_k = 0;
	        for(li_i=0; li_i<reply->elements; li_i++)
	        {
	            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
	            {
	                strcpy(p+(len*li_k), reply->element[li_i]->str);
	                li_k++;
	            }
	        }
	        *ai_elementcount = li_k;

	        li_i = 1;
   	 }
	    else
	    {
	        li_i = -1;
	    }

	    freeReplyObject(reply);

	    lst_redis_conn->isbusy = 0;

	    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    	return li_i;
}


/** @函数名 :int llen_rdlist(char *as_key, int ai_greenflag)
  *
  *  @函数功能: 返回队列深度
  * 							 
  *
  *  @param:  char *as_key         ：队列KEY值
  *           int ai_greenflag     ：句柄标识 1 绿色 0 非绿色
  *  @return :redis 句柄
  *  @retval
  *  @retval
  *  @note 
  */
int llen_rdlist(char *as_key, int ai_num,int ai_greenflag)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"llen %s",as_key);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		lst_redis_conn->isbusy = 0;
    		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		return -1;
	}
	    else if (reply->type == REDIS_REPLY_INTEGER)
	    {
	        li_i = reply->integer;
	    }
	    else
	    {
	        li_i = -2;
	    }

	    lst_redis_conn->isbusy = 0;

	    freeReplyObject(reply);

	    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    	return li_i;
}
/** @函数名 :int lset_rdlist(char *as_key, int ai_greenflag, int ai_index, char *as_element)
  *
  *  @函数功能: 根据队列下标修改队列元素数据
  * 							 
  *
  *  @param:  char *as_key     ：队列KEY值
  * 		  int ai_greenflag ：队列标识 0 普通队列 1绿色队列
  * 		  int ai_index     : 队列下标值
  *           char *as_element : 修改后的内容
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int lset_rdlist(char *as_key, int ai_num,int ai_greenflag, int ai_index, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"LSET %s %d %s", as_key, ai_index, as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		lst_redis_conn->isbusy = 0;
    		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		return -1;
	}
    if(strcmp(reply->str,"OK") != 0)
    {
        li_i = -1;
    }
    else
    {
        li_i = 1;
    }

    lst_redis_conn->isbusy = 0;

    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}





/** @函数名 :int create_hashtable_rd(char *as_key, int ai_greenflag, int *ai_element,char**as_value,int len)
  *
  *  @函数功能: 创建哈希表
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:阈值数组
  *		as_value:value值
  *		len:参数as_value数组一维的长度
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int create_hashtable_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element,char**as_value,int len)
{
    char ls_order[RDS_QUEUE_ELEMENT_LEN*10]={0};
    int li_i = 0;
    int li_ret = 0;
    char* p = (char*)as_value;
	while(*(ai_element+li_i)!=REDIS_END)
	{
		sprintf(ls_order+strlen(ls_order)," %03d ",*(ai_element+li_i));
		strcat(ls_order,(p+li_i*len));
		li_i++;
	}
	if(li_i != 0)
	{
		li_ret = hmset_rd(as_key,ai_num,ai_greenflag,ls_order);
		return li_ret;
	}
	return -1;
    
}

/** @函数名 :int hmset_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能: 添加哈希表
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:阈值和value值(一个或多个用空格间隔)
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int hmset_rd(char *as_key, int ai_num, int ai_greenflag, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[RDS_QUEUE_ELEMENT_LEN*10 + 20]={0};
    int li_i, li_k;
    int l_redisnum = 0;
    redisReply *reply;
    str_redisconnect_info *lst_redis_conn;
    char *p , *s;
    int slot;
    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    
    li_i = get_redisnum(as_key,ai_num);
    sprintf(ls_order,"HMSET %s %s",as_key,as_element);
    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	            li_i = -2;
	        }
	        else
	        {
	            li_i = 1;
		   freeReplyObject(reply);
	        }
	}
	else
	{
	
	    li_i = 1;
	    freeReplyObject(reply);
	}

    lst_redis_conn->isbusy = 0;

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}


/** @函数名 :int get_hashvalue_rd(char *as_key, int ai_greenflag, int *ai_element,char**as_value,int len,int*count)
  *
  *  @函数功能: 根据key值和域值获取value
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:阈值数组
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		count:返回值的数量
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int get_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element,char**as_value,int len,int*count)
{
    char ls_order[RDS_QUEUE_ELEMENT_LEN]={0};
    int li_i = 0;
    int li_ret = 0;
	while(*(ai_element+li_i)!=REDIS_END)
	{
		sprintf(ls_order+strlen(ls_order)," %d",*(ai_element+li_i));
		li_i++;
	}
	if(li_i != 0)
	{
		li_ret = hmget_rd(as_key,ai_num, ai_greenflag, ls_order,as_value,len,count);
    		return li_ret;
	}
	return -1;
}
/** @函数名 :int hmget_rd(char *as_key, int ai_greenflag, char *as_element,char**as_value,int len,int*count)
  *
  *  @函数功能: 根据key值和域值获取value
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:阈值(一个或多个用空格间隔)
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		count:返回值的数量
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int hmget_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element,char**as_value,int len,int*count)
{
    char ls_tmp[15]={0}, ls_order[1024]={0};
    int li_i, li_k;
    redisReply *reply;
	
    str_redisconnect_info *lst_redis_conn;
    char* p = NULL;
    p = (char*)as_value;
	
    li_i = get_redisnum(as_key,ai_num);
	
    if(strlen(as_element) >= 1000)
	{
		return -1;
	}
    sprintf(ls_order,"HMGET %s %s",as_key,as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	        		lst_redis_conn->isbusy = 0;
	         	pthread_mutex_unlock(&(lst_redis_conn->mutx));
	           	return -1;
	        }
		//freeReplyObject(reply);
		
	}

    if (reply->type == REDIS_REPLY_ARRAY)
    {
        li_k = 0;
        for(li_i=0; li_i<reply->elements; li_i++)
        {
            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
            {
                strcpy(p+(len*li_k), reply->element[li_i]->str);
                li_k++;
            }
        }
        *count = li_k;

        li_i = 1;
    }
    else
    {
        li_i = -2;
    }

    freeReplyObject(reply);

    lst_redis_conn->isbusy = 0;

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}

/** @函数名 :int get_all_hashvalue_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @函数功能: 根据key值获取全部value
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		count:返回值的数量
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int get_all_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, char**as_value,int len,int*count)
{
    int li_ret = 0;
    li_ret = hvals_rd(as_key, ai_num,ai_greenflag, as_value,len,count);
    return li_ret;
}
/** @函数名 :int hvals_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @函数功能: 根据key值获取全部value
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		count:返回值的数量
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int hvals_rd(char *as_key, int ai_num,int ai_greenflag, char**as_value,int len,int*count)
{
     char ls_tmp[15]={0}, ls_order[100]={0};
    int li_i, li_k;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;
    char* p = NULL;
    p = (char*)as_value;
	
    li_i = get_redisnum(as_key,ai_num);
	
    sprintf(ls_order,"HVALS %s",as_key);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}	
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	        		lst_redis_conn->isbusy = 0;
	         	pthread_mutex_unlock(&(lst_redis_conn->mutx));
	           	return -1;
	        }
	}

    if (reply->type == REDIS_REPLY_ARRAY)
    {
        li_k = 0;
        for(li_i=0; li_i<reply->elements; li_i++)
        {
            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
            {
                strcpy(p+(len*li_k), reply->element[li_i]->str);
                li_k++;
            }
        }
        *count = li_k;

        li_i = 1;
    }
    else
    {
        li_i = -2;
    }

    freeReplyObject(reply);

    lst_redis_conn->isbusy = 0;

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}
/** @函数名 :int get_all_hashfieldandvalue_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @函数功能: 根据key值获取全部域值和value
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_value:返回阈值和value值
  *		len:参数as_value数组一维的长度
  *		count:返回值的数量
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int get_all_hashfieldandvalue_rd(char *as_key, int ai_num,int ai_greenflag, char**as_value,int len,int*count)
{
     int li_ret = 0;
     li_ret = hgetall_rd(as_key,ai_num, ai_greenflag, as_value,len,count);
    return li_ret;
}
/** @函数名 :int hgetall_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @函数功能: 根据key值获取全部域值和value
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_value:返回阈值和value值
  *		len:参数as_value数组一维的长度
  *		count:返回值的数量
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int hgetall_rd(char *as_key, int ai_num,int ai_greenflag, char**as_value,int len,int*count)
{
     char ls_tmp[15]={0}, ls_order[100]={0};
    int li_i, li_k;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;
    char* p = NULL;
    p = (char*)as_value;
	
    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"HGETALL %s",as_key);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,li_i, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	       if(reply == NULL)
	        {
	        		lst_redis_conn->isbusy = 0;
	         	pthread_mutex_unlock(&(lst_redis_conn->mutx));
	           	return -1;
	        }
	}

    if (reply->type == REDIS_REPLY_ARRAY)
    {
        li_k = 0;
        for(li_i=0; li_i<reply->elements; li_i++)
        {
            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
            {
                strcpy(p+(len*li_k), reply->element[li_i]->str);
                li_k++;
            }
        }
        *count = li_k;

        li_i = 1;
    }
    else
    {
        li_i = -2;
    }

    freeReplyObject(reply);

    lst_redis_conn->isbusy = 0;

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}
/** @函数名 :int del_hashvalue_rd(char *as_key, int ai_greenflag, int *ai_element)
  *
  *  @函数功能: 删除哈希表中的某个或者某几个域
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:要删除的域名
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int del_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int *ai_element)
{
    char ls_order[RDS_QUEUE_ELEMENT_LEN]={0};
    int li_i = 0;
    int li_ret = 0;
	while(*(ai_element+li_i)!=REDIS_END)
	{
		sprintf(ls_order+strlen(ls_order)," %d",*(ai_element+li_i));
		li_i++;
	}
	if(li_i != 0)
	{
		li_ret = hdel_rd(as_key,ai_num,ai_greenflag, ls_order);
    		return li_ret;
	}
	return -1;
}



/** @函数名 :int hdel_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能: 删除哈希表中的某个或者某几个域
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:要删除的域名(可多个使用空格间隔)
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int hdel_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[1024]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);
     if(strlen(as_element) >= 1000)
	{
		return -3;
	}
    sprintf(ls_order,"HDEL %s %s", as_key, as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
    	if(reply == NULL)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		 return -1;
	}
    lst_redis_conn->isbusy = 0;

    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;

}
/** @函数名 :int change_hashvalue_rd(char *as_key, int ai_greenflag, int *ai_element,char**as_value,int len)
  *
  *  @函数功能: 修改哈希表中的某个或者某几个域的值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:阈值数组
  *		as_value:value值
  *		len:参数as_value数组一维的长度
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int change_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int *ai_element,char**as_value,int len)
{
    char ls_order[RDS_QUEUE_ELEMENT_LEN]={0};
    int li_i = 0;
    int li_ret = 0;
    char* p = (char*)as_value;
	while(*(ai_element+li_i)!=REDIS_END)
	{
		sprintf(ls_order+strlen(ls_order)," %d ",*(ai_element+li_i));
		strcat(ls_order,(p+li_i*len));
		li_i++;
	}
	if(li_i != 0)
	{
		li_ret = hmchange_rd(as_key,ai_num,ai_greenflag, ls_order);
    		return li_ret;
	}
	return -1;
}



/** @函数名 :int hmchange_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能: 修改哈希表中的某个或者某几个域的值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:要修改的域名(可多个使用空格间隔)
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int hmchange_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[1024]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);
    if(strlen(as_element) >= 1000)
	{
		return -3;
	}
    sprintf(ls_order,"HMSET %s %s", as_key, as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		 return -1;
	}
    	else if(strcmp(reply->str,"OK") != 0)
   	 {
      		  li_i = -1;
    	}
    	else
    	{
       		 li_i = 1;
    	}

    lst_redis_conn->isbusy = 0;

    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;

}

/** @函数名 :int add_hashvalue_rd(char *as_key, int ai_greenflag, int ai_element,char*as_value)
  *
  *  @函数功能: 向已存在的哈希表中添加一个域的值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:阈值数组
  *		as_value:value值
  *		len:参数as_value数组一维的长度
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int add_hashvalue_rd(char *as_key,int ai_num, int ai_greenflag, int ai_element,char*as_value)
{
    char ls_order[RDS_QUEUE_ELEMENT_LEN]={0};
    int li_ret = 0;
 
    sprintf(ls_order,"%d %s",ai_element,as_value);
	
    li_ret = hsetnx_rd(as_key,ai_num,ai_greenflag, ls_order);
    return li_ret;
}

/** @函数名 :int hsetnx_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能:向已存在的哈希表中添加一个域的值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:要添加的域值
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int hsetnx_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[1024]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);
    if(strlen(as_element) >= 1000)
	{
		return -1;
	}
    sprintf(ls_order,"HSETNX %s %s", as_key, as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		 return -1;
	}
    lst_redis_conn->isbusy = 0;

    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;

}

/** @函数名 :long long increase_int_hashvalue_rd(char *as_key, int ai_greenflag, int ai_element,int as_value)
  *
  *  @函数功能:向已存在的哈希表中某个域的值增加某个整数值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:要运算的域值
  *		ai_value:要加的数值
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
long long increase_int_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int ai_element,int ai_value)
{
    char ls_order[100]={0};
    long long li_ret = 0;
 
    sprintf(ls_order,"%d %d",ai_element,ai_value);
	
    li_ret = hincrby_rd(as_key,ai_num,ai_greenflag, ls_order);
    return li_ret;
}
/** @函数名 :int hincrby_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能:向已存在的哈希表中某个域的值增加某个整数值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:要增加的域值
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
long long hincrby_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[1024]={0};
    int li_i;
    long long ll_ret = 0;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);
    if(strlen(as_element) >= 1000)
	{
		return -1;
	}
    sprintf(ls_order,"HINCRBY %s %s", as_key, as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		pthread_mutex_lock(&(lst_redis_conn->mutx));
		 return -1;
	}
    	   
    ll_ret = reply->integer;
    lst_redis_conn->isbusy = 0;

    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return ll_ret;

}


/** @函数名 :float increase_float_hashvalue_rd(char *as_key, int ai_greenflag, int ai_element,float ai_value)
  *
  *  @函数功能:向已存在的哈希表中某个域的值增加某个浮点数
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		ai_element:要运算的域值
  *		af_value:要加的数值
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
float increase_float_hashvalue_rd(char *as_key, int ai_num,int ai_greenflag, int ai_element,float af_value)
{
    char ls_order[100]={0};
    float li_ret = 0;
 
    sprintf(ls_order,"%d %f",ai_element,af_value);
	
    li_ret = hincrbyfloat_rd(as_key,ai_num,ai_greenflag, ls_order);
    return li_ret;
}
/** @函数名 :int hincrbyfloat_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @函数功能:向已存在的哈希表中某个域的值增加某个浮点数值
  * 							 
  *
  *  @param:  as_key:key值
  *		ai_num:集群编号
  *		ai_greenflag:连接优先级
  *		as_element:要增加的域值
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
float hincrbyfloat_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element)
{
    char ls_tmp[15]={0}, ls_order[1024]={0};
    int li_i;
    float lf_ret = 0;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);
	
    if(strlen(as_element) >= 1000)
	{
		return -3;
	}
    sprintf(ls_order,"HINCRBYFLOAT %s %s", as_key, as_element);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		pthread_mutex_lock(&(lst_redis_conn->mutx));
		 return -1;
	}
	printf("%d %d  OOOOOOOOOOO\n",reply->integer,reply->type);
    	
    lst_redis_conn->isbusy = 0;
    lf_ret = atof(reply->str);
    freeReplyObject(reply);

    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return lf_ret;
}
/** @函数名 :int scan_all_hashtable_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select)
  *  @函数功能:根据通配符扫描key值(所有)
  * 							 
  *
  *  @param:  
  *		ai_num:集群编号
  *		ai_redisnum:物理redis下标
  *		ai_greenflag:连接优先级
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		ai_count:返回值的数量
  *		as_select:搜查的通配符
  *		ai_maxcount:每次搜查的最大数量
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int scan_all_hashtable_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select)
{
     int li_ret = 0;
     li_ret = hscanall_rd(ai_num,ai_redisnum,ai_greenflag,as_value,len,ai_count,as_select);
    return li_ret;
}

/** @函数名 :int hscanall_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select,int ai_maxcount)
  *
  *  @函数功能:根据通配符扫描key值(所有)
  * 							 
  *
  *  @param: 
  *		ai_num:集群编号
  *		ai_redisnum:物理redis下标
  *		ai_greenflag:连接优先级
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		ai_count:返回值的数量
  *		as_select:搜查的通配符
  *		ai_maxcount:每次搜查的最大数量
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int hscanall_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select)
{
    char ls_tmp[15]={0}, ls_order[200]={0};
    int li_i, li_j,li_k,flag,num;
    redisReply *reply;
    str_redisconnect_info *lst_redis_conn;
    char* p = NULL;
    num = 1;
    flag = 0;
    li_k = 0;
    p = (char*)as_value;
	
    if ((lst_redis_conn=f_get_redis_conn(ai_num,ai_redisnum,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	pthread_mutex_lock(&(lst_redis_conn->mutx));
	while(num)
	{
		if(flag == 0)
		{
			num = 0;
			flag = 1;
		}
		sprintf(ls_order,"SCAN %d MATCH %s", num, as_select);
		reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
		if(reply == NULL)
		{
		        redis_reconnect(ai_num,ai_redisnum, lst_redis_conn->rediscontext);

		        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
		        if(reply == NULL)
		        {
		            lst_redis_conn->isbusy = 0;
		            pthread_mutex_unlock(&(lst_redis_conn->mutx));
		            return -1;
		        }
		}

	    if (reply->type == REDIS_REPLY_ARRAY)
	    {

	        for(li_i=0; li_i<reply->elements; li_i++)
	        {
	            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
	            {
			if(li_i ==1)
	            	{		
	            		for(li_j=0; li_j<reply->element[li_i]->elements; li_j++)
				{
					strcpy(p+(len*li_k), reply->element[li_i]->element[li_j]->str);
					li_k++;
				}
			}
	                
	            }
	        }
		num = atoi(reply->element[0]->str);
		continue;
	    }
	    else
	    {
	    	freeReplyObject(reply);
		lst_redis_conn->isbusy = 0;
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	        return -2;
	    }
    }
    *ai_count = li_k;
    freeReplyObject(reply);
    lst_redis_conn->isbusy = 0;
    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}

/** @函数名 :int scan_part_hashtable_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount)
  *  @函数功能:根据通配符扫描key值(所有)
  * 							 
  *
  *  @param:  
  *		ai_num:集群编号
  *		ai_redisnum:物理redis下标
  *		ai_greenflag:连接优先级
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		ai_count:返回值的数量
  *		as_select:搜查的通配符
  *		ai_maxcount:每次搜查的最大数量
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int scan_part_hashtable_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount)
{
     int li_ret = 0;
     li_ret = hscan_rd(ai_num,ai_redisnum,ai_greenflag,as_value,len,ai_count,ai_start,as_select,ai_maxcount);
    return li_ret;
}
/** @函数名 :int hscan_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount)
  *
  *  @函数功能:根据通配符扫描key值(所有)
  * 							 
  *
  *  @param:  
  *		ai_num:集群编号
  *		ai_redisnum:物理redis下标
  *		ai_greenflag:连接优先级
  *		as_value:返回value值
  *		len:参数as_value数组一维的长度
  *		ai_count:返回值的数量
  *		ai_start:开始搜查的位置
  *		as_select:搜查的通配符
  *		ai_maxcount:每次搜查的最大数量
  *		
  * 		  
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */

int hscan_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount)
{
    char ls_tmp[15]={0}, ls_order[200]={0};
    int li_i, li_j,li_k;
    redisReply *reply;
    str_redisconnect_info *lst_redis_conn;
    char* p = NULL;
    li_k = 0;
    p = (char*)as_value;
	
    if ((lst_redis_conn=f_get_redis_conn(ai_num,ai_redisnum,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;
	sprintf(ls_order,"SCAN %d MATCH %s COUNT %d", ai_start, as_select,ai_maxcount);
	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
	        redis_reconnect(ai_num,ai_redisnum, lst_redis_conn->rediscontext);

	        reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	        if(reply == NULL)
	        {
	            lst_redis_conn->isbusy = 0;
	            pthread_mutex_unlock(&(lst_redis_conn->mutx));
	            return -1;
	        }
	}

    if (reply->type == REDIS_REPLY_ARRAY)
    {

        for(li_i=0; li_i<reply->elements; li_i++)
        {
            if(reply->element[li_i]->type != REDIS_REPLY_NIL)
            {
            	if(li_i == 0)
        		{
			strcpy(p+(len*li_k), reply->element[li_i]->str);
			li_k++;
        		}
		if(li_i ==1)
            	{		
            		for(li_j=0; li_j<reply->element[li_i]->elements; li_j++)
			{
				strcpy(p+(len*li_k), reply->element[li_i]->element[li_j]->str);
				li_k++;
			}
		}
            }
        }
	   *ai_count = li_k;
	    freeReplyObject(reply);
	    lst_redis_conn->isbusy = 0;
	    pthread_mutex_unlock(&(lst_redis_conn->mutx));
	    return 1;
    }
    else
    {
    	freeReplyObject(reply);
	lst_redis_conn->isbusy = 0;
	pthread_mutex_unlock(&(lst_redis_conn->mutx));
        return -2;
    }
}


/** @函数名 :int delkey_rd(char *as_key,ai_num, int ai_greenflag)
  *
  *  @函数功能: 删除给定KEY值
  * 							 
  *
  *  @param:  char *as_key     ：队列KEY值
  *		int 	ai_num:		集群编号
  * 		  int ai_greenflag ：队列标识 0 普通队列 1绿色队列
  * 		
  *  @return :无
  *  @retval
  *  @retval
  *  @note 
  */
int delkey_rd(char *as_key,int ai_num, int ai_greenflag)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"DEL %s",as_key);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i,ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		  lst_redis_conn->isbusy = 0;
		  pthread_mutex_unlock(&(lst_redis_conn->mutx));
		  return -1;
	}
	    lst_redis_conn->isbusy = 0;

	    freeReplyObject(reply);

	    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return 1;
}

/** @函数名 :int exists_rd(char *as_key,ai_num, int ai_greenflag)
  *
  *  @函数功能: 判断KEY值是否存在
  * 							 
  *
  *  @param:  char *as_key         ：队列KEY值
  *		int 	ai_num:		集群编号
  *           int ai_greenflag     ：句柄标识 1 绿色 0 非绿色
  *  @return :1 存在, 0 不存在,-1操作失败
  *  @retval
  *  @retval
  *  @note 
  */
int exists_rd(char *as_key,int ai_num, int ai_greenflag)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"exists %s",as_key);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		lst_redis_conn->isbusy = 0;
    		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		return -1;
	}
	    else if (reply->type == REDIS_REPLY_INTEGER)
	    {
	        li_i = reply->integer;
	    }
	    else
	    {
	        li_i = -1;
	    }

	    lst_redis_conn->isbusy = 0;

	    freeReplyObject(reply);

	    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}



/** @函数名 :int set_keyttl(char *as_key,int ai_num, int ai_greenflag,int ai_time)
  *
  *  @函数功能: 对key值设置超时时间
  * 							 
  *
  *  @param:  char *as_key         ：队列KEY值
  *		int 	ai_num:		集群编号
  *           int ai_greenflag：句柄标识 1 绿色 0 非绿色
  *		int ai_time:	key值的超时时间
  *  @return :1 设置成功, 0 设置不成功,-1操作失败
  *  @retval
  *  @retval
  *  @note 
  */
int set_keyttl(char *as_key,int ai_num, int ai_greenflag,int ai_time)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"EXPIRE %s %d",as_key,ai_time);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		lst_redis_conn->isbusy = 0;
    		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		return -1;
	}
	    else if (reply->type == REDIS_REPLY_INTEGER)
	    {
	        li_i = reply->integer;
	    }
	    else
	    {
	        li_i = -1;
	    }

	    lst_redis_conn->isbusy = 0;

	    freeReplyObject(reply);

	    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}


/** @函数名 :int del_keyttl(char *as_key,int ai_num, int ai_greenflag)
  *
  *  @函数功能: 移除key值的超时时间
  * 							 
  *
  *  @param:  char *as_key         ：队列KEY值
  *		int 	ai_num:		集群编号
  *           int ai_greenflag：句柄标识 1 绿色 0 非绿色
  *  @return :1 设置成功, 0 设置不成功,-1操作失败
  *  @retval
  *  @retval
  *  @note 
  */
int del_keyttl(char *as_key,int ai_num, int ai_greenflag)
{
    char ls_tmp[15]={0}, ls_order[50]={0};
    int li_i;
    redisReply *reply;

    str_redisconnect_info *lst_redis_conn;

    li_i = get_redisnum(as_key,ai_num);

    sprintf(ls_order,"PERSIST %s",as_key);

    if ((lst_redis_conn=f_get_redis_conn(ai_num,li_i, ai_greenflag))==NULL)
	{
		return -1;
    	}
	lst_redis_conn->isbusy = 1;

	pthread_mutex_lock(&(lst_redis_conn->mutx));
	if(lst_redis_conn->enabled == 0)
	{
		pthread_mutex_unlock(&(lst_redis_conn->mutx));
	         return -1;
	}
	reply = redisCommand(lst_redis_conn->rediscontext, ls_order);
	if(reply == NULL)
	{
		lst_redis_conn->isbusy = 0;
    		pthread_mutex_unlock(&(lst_redis_conn->mutx));
		return -1;
	}
	    else if (reply->type == REDIS_REPLY_INTEGER)
	    {
	        li_i = reply->integer;
	    }
	    else
	    {
	        li_i = -1;
	    }

	    lst_redis_conn->isbusy = 0;

	    freeReplyObject(reply);

	    pthread_mutex_unlock(&(lst_redis_conn->mutx));

    return li_i;
}