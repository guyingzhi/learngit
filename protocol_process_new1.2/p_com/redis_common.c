/********************************************Copyright (c)*****************************************
**                                          ���������ǳ�����Ƽ����޹�˾
**
**                                           http://www.ipole.com.cn/show/zn/index.jsp
**                                           tel :(010)-82825208
**--------------�ļ���Ϣ---------------------------------------------------------------------------
**��   ��   ��: redis_common.c
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
#include "redis_common.h"
/**************************************��������***************************************************/
unsigned short crc16(const char *buf, int len) ;
unsigned int HASH_SLOT(char *key, int keylen) ;
int get_redisnum(char* as_key,int ai_num);
int brpop_rdvalue(redisContext *arc_rediscontext, char *as_key, int ai_overtime, char** as_value,int len, int *ai_valuecount);
void* f_thread_redis_list_deal(void *pvParam);/*redis�����������մ����߳�*/
int redis_cfg_init();/* redis���ݿ��ʼ�� ai_type��Ӧredis_type 0 �ļ����У�1 �������ݻ�������as_dbbh ini�ֶ�����*/
str_redisconnect_info *f_get_redis_conn(int ai_num,int ai_redis, int ai_greenflag);/*����һ���������� ai_flag:0��ͨ���ȼ���1�����ȼ�*/
int hscan_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount);/*����ͨ���ɨ��keyֵ(����ɨ��)*/
int hscanall_rd(int ai_num,int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select);/*����ͨ���ɨ��keyֵ(����)*/
float hincrbyfloat_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element);/*���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ��������ֵ*/
long long hincrby_rd(char *as_key, int ai_num,int ai_greenflag, char *as_element);/*���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ������ֵ*/
int hsetnx_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*���Ѵ��ڵĹ�ϣ�������һ�����ֵ*/
int hmchange_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*�޸Ĺ�ϣ���е�ĳ������ĳ�������ֵ*/
int hdel_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*����:ɾ����ϣ���е�ĳ������ĳ������*/
int hgetall_rd(char *as_key, int ai_num,int ai_greenflag, char**as_value,int len,int*count);/*����keyֵ��ȡȫ����ֵ��value*/
int hvals_rd(char *as_key,int ai_num, int ai_greenflag, char**as_value,int len,int*count);/*����keyֵ��ȡȫ��value*/
int hmget_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element,char**as_value,int len,int*count);/*����keyֵ����ֵ��ȡvalue*/
int hmset_rd(char *as_key,int ai_num, int ai_greenflag, char *as_element);/*��ӹ�ϣ��*/






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

pthread_mutex_t	gt_redis_creatpthread_mux;		/* �������������߳�ʱʹ�� */
/************************************�ڲ���������********************************************************/
/*CRC16У��*/
unsigned short crc16(const char *buf, int len) 
{
    int counter;
    unsigned short crc = 0;
    for (counter = 0; counter < len; counter++)
            crc = (crc<<8) ^ crc16tab[((crc>>8) ^ *buf++)&0x00FF];
    return crc;
}
/*����keyֵ��ȡ��ϣ��ֵ*/
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


/*����keyֵ��ȡ��ģ������redis�������ӳ��±�*/
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

 /** @������ :int redis_mutex_destroy(char *as_key, int ai_greenflag)
  *
  *  @��������: ����KEYֵ���ʱ��
  * 							 
  *
  *  @param:  char *as_key��    redis�������
  *		ai_num:		��Ⱥ���
  * 		  ai_greenflag��    ͨ����ʶ
  * 		
  *  @return :0-n ���ʱ��  -1�쳣  -2 ɾ��
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
/** @������ :int redis_set_ttl_mutex(char *as_key, int ai_greenflag,int ttl)
  *
  *  @��������: ����KEYֵ���ʱ��
  * 							 
  *
  *  @param:  char *as_key��     redis�������
  *		ai_num:		��Ⱥ���
  * 		  ai_greenflag��    ͨ����ʶ
  * 		  int ttl:          ���������ʱ��
  * 		
  *  @return :��
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
/** @������ :int brpop_rdvalue(redisContext *arc_rediscontext, char *as_key, int ai_overtime, char as_value,int len, int *ai_valuecount)
  *
  *  @��������: ����ʱ���������ն���Ԫ��
  * 							 
  *
  *  @param:  redisContext *arc_rediscontext ��redis���
  *           char *as_key     ������KEYֵ
  * 		  int ai_overtime  ����ʱʱ��
  *           char as_value[][RDS_QUEUE_ELEMENT_LEN]����������
  *           int *ai_valuecount ������Ԫ�ظ���
  * 		
  *  @return :��
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

/** @������ :int redis_cfg_init()
  *
  *  @��������: ��ʼ��������redis�����Ϣ�ṹ��
  * 							 
  *
  *  @param:  ��
  * 		
  *  @return :��
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


/** @������ :str_redisconnect_info *f_get_redis_conn(int ai_redis, int ai_greenflag)
  *
  *  @��������: ��ȡһ������REDIS���Ӿ��
  * 							 
  *
  *  @param:  int ai_redis         ���غ�
  *           int ai_greenflag     �������ʶ 1 ��ɫ 0 ����ɫ
  *  @return :redis ���
  *  @retval
  *  @retval
  *  @note 
  */
str_redisconnect_info *f_get_redis_conn(int ai_num,int ai_redis, int ai_greenflag)
{
	int		li_max,li_min,li_p;

	/* ��ѯһ�����е����� */

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
/** @������ :int redis_colonyinfo_free(int num)
  *
  *  @��������: redis ������Ϣͬ���߳�
  * 							 
  *
  *  @param: num Ϊ��Ⱥ���
  * 		
  *  @return :�ɹ�Ϊ1��ʧ��Ϊ-1
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

/** @������ :int redis_colonyinfo_init(redisContext *rediscontext,int num)
  *
  *  @��������: redis ������Ϣͬ��������
  * 							 
  *
  *  @param:rediscontext:redis���Ӿ��
  *					num :��Ⱥ���
  * 		
  *  @return :�ɹ�Ϊ1��ʧ��Ϊ-1
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
	/*����redis�ڵ���Ϣ*/
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
			printf("��Ⱥ�ڵ�%d ����:\n",li_i);
			printf("minslot = %d\n",redisinfo[li_i].minslot);
			printf("maxslot = %d\n",redisinfo[li_i].maxslot);
			printf("ip = %s\n",redisinfo[li_i].ip);
			printf("port = %d\n",redisinfo[li_i].port);
			li_count++;
        		}
	}
	freeReplyObject(reply);
	/*redis�ڵ���Ϣ����*/
	if(gstr_redis_info[num].enable == 0)/*��Ⱥ���*/
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
	else/*��Ⱥ��Ϣ�Ա�*/
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
						gstr_redis_info[num].gstr_redis[li_j].redis_cmp_flag = 1;/*�ڵ�û�б��*/
						printf("�ڵ�%d û�б仯\n",li_j);
					}
					else
					{
						gstr_redis_info[num].gstr_redis[li_j].redis_cmp_flag = 2;/*�ڵ�۷����˱仯\n*/
						printf("�ڵ�%d�۷����˱仯\n",li_j);
					}
					break;
				}
				
				
			}
			if(li_j == REDIS_COUNT)/*�����ڵ�*/
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
		/*�� �ԱȺ�Ľ�����д���*/
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
					/*ɾ���ڵ��keyֵ����*/
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

/** @������ :void*f_redisinfo_manage(void *pvParam)
  *
  *  @��������: redis ������Ϣͬ���߳�
  * 							 
  *
  *  @param:  pvParam ΪNULL
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
					   printf("�������Ӿ�ʧ��\n");
				            continue;
				        }
					gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 0;
					redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
					printf("������ʧ�ܣ������ӳɹ�\n");
					continue;
			        }
				
				gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 1;
				redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
				printf("�����ӳɹ�\n");
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
					  if(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag == 0)/*Ŀǰ���ӵ��Ǳ���IP*/
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
							   printf("1�������Ӿ�ʧ��\n");
						            continue;
						        }
							gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 0;
							redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
							printf("1������ʧ�ܣ������ӳɹ�\n");
							continue;
					        }
						
						gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].host_flag = 1;
						redis_colonyinfo_init(gstr_redis_manageinfo.gstr_redis_manageinfo_unit[li_i].rediscontext,li_i);
						printf("1�����ӳɹ�\n");
					  }
				}
			}
		}
		sleep(REDIS_SYNC_TIME);
	}
}
/** @������ :int f_thread_redis_list_deal(void *pvParam)
  *
  *  @��������: ����Ԫ�ػ�ȡ�����߳�
  * 							 
  *
  *  @param:  pvParam     ��
  * 		 
  * 		
  *  @return :1��ʾ�ɹ���-1��ʾʧ��
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

			/* �����ȴ������ݷ��͹���������0��ʾ�����ж� */
			ls_ret =  brpop_rdvalue(astr_redis.connectinfo[ls_indx].rediscontext,pthreadinfo.key,pthreadinfo.timeount,(char**)ls_data,REDIS_BUFF_MAXLEN,&ls_count);
			if (ls_ret == 0)	/* �����ж� */
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
				printf("ʹ��keyֵ = %s,���յ�����= %s������= %d\n",pthreadinfo.key,ls_data[0],strlen(ls_data[0]));
				pthreadinfo.af_func(ls_data[0],strlen(ls_data[0]));
			}

		} while(1);
	}
}
/** @������ :int redis_get_mutex(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������: ��ȡ����REDIS��ϵͳ��
  * 							 
  *
  *  @param:  int ai_type��     redis�������
  *		  ai_num:		��Ⱥ���
  * 		  ai_greenflag��    ͨ����ʶ
  * 		  char *as_element������������
  * 		  int ttl:          ���������ʱ��
  * 		
  *  @return :1 �ɹ����  0 �����ʧ��
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
		if(1 == li_i)// �ɹ�������
		{
			// ���ü�ֵ���ʱ��
			if(1 == redis_set_ttl_mutex(as_key,ai_num,ai_greenflag,ttl))
			{
				// ���ô��ʱ��ɹ�
				li_i = 1;
			}
			else
			{
				// ɾ��KEY
				if(1 == exists_rd(as_key,ai_num,ai_greenflag))// ����ɾ��
				{
					if(1== delkey_rd(as_key,ai_num,ai_greenflag))
					{
						//
					}
					else
					{
						// ϵͳ����
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
  
  /** @������ :int redis_get_mutex(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������: ��ȡ����REDIS��ϵͳ������Ϣ
  * 							 
  *
  *  @param:  int ai_type��     redis�������
  *		  ai_num:		��Ⱥ���
  * 		  ai_greenflag��    ͨ����ʶ
  * 		  char *as_element������������
  * 		  int ttl:          ���������ʱ��
  * 		
  *  @return :1 �ɹ����  0 �����ʧ��
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
  
  /** @������ :int redis_mutex_destroy(char *as_key, int ai_greenflag)
  *
  *  @��������: ����KEYֵ���ʱ��
  * 							 
  *
  *  @param:  char *as_key��     redis�������
  *		  ai_num:		��Ⱥ���
  * 		  ai_greenflag��    ͨ����ʶ
  * 		
  *  @return :��
  *  @retval
  *  @retval
  *  @note 
  */
int redis_mutex_destroy(char *as_key,int ai_num, int ai_greenflag)
{
     	int li_i = -1;
	int li_ret = 0;
	li_ret = redis_get_ttl(as_key, ai_num,ai_greenflag);
	if(li_ret>= 0)//������Ҫɾ��
	{
		if(1== delkey_rd(as_key,ai_num,ai_greenflag))
		{
			// 
			li_i = 0;
		}
		else
		{
			// ϵͳ����
		}
	}
	else if(-1 ==li_ret)// �쳣����
	{
		if(1== delkey_rd(as_key,ai_num,ai_greenflag))
		{
			//
			li_i = 0;
		}
		else
		{
			// ϵͳ����
		}
	}
	else if(-2 ==li_ret)// �Ѿ�ɾ��
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
			// ϵͳ����
		}
	}
	return li_i;
}
 
  /** @������ : int judge_key_isornot(char *as_key,int ai_num )
  *
  *  @��������: �ж�keyֵ�Ƿ����
  * 							 
  *
  *  @param:  as_key :����keyֵ
  *			ai_num:��Ⱥ���
  * 		
  *  @return :���ڵ���0��ʾkeyֵλ�ã�-1��ʾû��
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

   /** @������ : int pthread_judge_key(char *as_key,int ai_num,int ai_redisnum)
  *
  *  @��������: �ж�keyֵ�Ƿ����
  * 							 
  *
  *  @param:  as_key :����keyֵ
  *			ai_num:��Ⱥ���
  *			ai_redisnum: redis�ڵ���
  * 		
  *  @return :1��ʾ�У�-1��ʾû��
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
    /** @������ : int get_virtaul_key(char *as_key,int ai_num,char* as_virkey )
  *
  *  @��������: ��ʼ��redis��������keyֵ
  * 							 
  *
  *  @param:  as_key :����keyֵ
  *			ai_num:��Ⱥ���
  *			as_virkey���ص�����keyֵ
  * 		
  *  @return :���ڵ���0��ʾredis�ڵ��±꣬-1��ʾʧ��
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
 
/** @������ :int redis_colony_init()
  *
  *  @��������: ��ʼ��redis��Ⱥ����
  * 							 
  *
  *  @param:  ��
  * 		
  *  @return :��
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
 /** @������ : int get_virtaul_key(char *as_key,int ai_num )
  *
  *  @��������: ��ʼ��redis��������keyֵ
  * 							 
  *
  *  @param:  as_key :����keyֵ
  *			ai_num:��Ⱥ���
  *
  *  @return :1��ʾ�ɹ���-1��ʾʧ��
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
	if(ret == -1)/*��ʼ��ʹ��*/
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
						printf("����keyֵ = %s,��ֵ = %d\n",tmpname,slot);
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
  
/** @������ :int redis_exit()
  *
  *  @��������: �����˳��ͷ�redis�����Ϣ
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


/** @������ :int redis_disconnect(redisContext *arc_rediscontext)
  *
  *  @��������: �ͷ�redis���Ӿ��
  * 							 
  *
  *  @param:  redisContext *arc_rediscontext
  * 		  
  * 		  
  * 		  
  * 		
  *  @return :��
  *  @retval
  *  @retval
  *  @note 
  */
int redis_disconnect(redisContext *arc_rediscontext)
{
    redisFree(arc_rediscontext);
    return 1;
}
/** @������ :int redis_connect(str_redis_info *astr_redis, int ai_num, char *as_error)
  *
  *  @��������: ��ʼ��������redis�������
  * 							 
  *
  *  @param:  str_redis_info *astr_redis ������ṹ��
  * 		  int ai_num    �������
  * 		  char *as_error
  * 		  char *as_error �����ش�����Ϣ
  * 		
  *  @return :>=0 �ɹ�
             -101 �������ݿ�ʧ��
             -102 �û�������������֤ʧ��
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
		sprintf(as_error,"�û�������������֤����ִ��ʧ��");
		pthread_mutex_unlock(&(astr_redis->mux_connectredis));
           	 return -102;
        	}
        else if(strcmp(reply->str,"OK") != 0)
        {
            freeReplyObject(reply);
            sprintf(as_error,"�û�������������֤ʧ��");
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

    return astr_redis->maxconnect - 1;//�����±�
}

/** @������ :int redis_reconnect(int ai_type, redisContext *arc_rediscontext)
  *
  *  @��������: ��ʼ��������redis�������
  * 							 
  *
  *  @param:  int ai_type �� ����б��±�
  * 		  redisContext *arc_rediscontext ��redisʵ����
  * 		
  *  @return :��
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




/** @������ :int lget_rdlist(char *as_key, int ai_num, int ai_overtime, char as_flag)
  *
  *  @��������: get����Ԫ��
  * 							 
  *
  *  @param:  char *as_key     ������KEYֵ
  * 		  int ai_num ����Ⱥ���
  * 		  int ai_overtime ��������ʱʱ��
  * 		  char as_flag:	�Ƿ�ʹ���������0��ʾ���ã�1��ʾʹ��
  * 		
  *  @return :1��ʾ�ɹ���-1��ʾʧ��
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
/** @������ :int lpush_rdlist(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������: PUSH����Ԫ��
  * 							 
  *
  *  @param:  char *as_key     ������KEYֵ
  * 		  int ai_num ����Ⱥ���
  * 		  int ai_greenflag �����б�ʶ 0 ��ͨ���� 1��ɫ����
  * 		  char *as_element ����������
  * 		  char as_flag:	�Ƿ�ʹ���������0��ʾ���ã�1��ʾʹ��
  * 		
  *  @return :1��ʾ�ɹ���-1��ʾʧ��
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

/** @������ :int lrange_rdlist(char *as_key, int ai_greenflag,int ai_start, int ai_stop, char** as_element,int len, int *ai_elementcount)
  *
  *  @��������: ��ȡ������ָ�����������Ԫ���±�����
  * 							 
  *
  *  @param:  char *as_key     ������KEYֵ
   * 		  int ai_num ����Ⱥ���
  * 		  int ai_greenflag �����б�ʶ 0 ��ͨ���� 1��ɫ����
  * 		  int ai_start     : ��ʼλ��
  *           int ai_stop      : ����λ��
  * 		  char as_element[][RDS_ELEMENT_LEN]����������
  *           int *ai_elementcount              ������Ԫ�ظ���
  * 		
  *  @return :��
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


/** @������ :int llen_rdlist(char *as_key, int ai_greenflag)
  *
  *  @��������: ���ض������
  * 							 
  *
  *  @param:  char *as_key         ������KEYֵ
  *           int ai_greenflag     �������ʶ 1 ��ɫ 0 ����ɫ
  *  @return :redis ���
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
/** @������ :int lset_rdlist(char *as_key, int ai_greenflag, int ai_index, char *as_element)
  *
  *  @��������: ���ݶ����±��޸Ķ���Ԫ������
  * 							 
  *
  *  @param:  char *as_key     ������KEYֵ
  * 		  int ai_greenflag �����б�ʶ 0 ��ͨ���� 1��ɫ����
  * 		  int ai_index     : �����±�ֵ
  *           char *as_element : �޸ĺ������
  * 		
  *  @return :��
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





/** @������ :int create_hashtable_rd(char *as_key, int ai_greenflag, int *ai_element,char**as_value,int len)
  *
  *  @��������: ������ϣ��
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:��ֵ����
  *		as_value:valueֵ
  *		len:����as_value����һά�ĳ���
  * 		  
  * 		
  *  @return :��
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

/** @������ :int hmset_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������: ��ӹ�ϣ��
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:��ֵ��valueֵ(һ�������ÿո���)
  * 		  
  * 		
  *  @return :��
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


/** @������ :int get_hashvalue_rd(char *as_key, int ai_greenflag, int *ai_element,char**as_value,int len,int*count)
  *
  *  @��������: ����keyֵ����ֵ��ȡvalue
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:��ֵ����
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		count:����ֵ������
  * 		  
  * 		
  *  @return :��
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
/** @������ :int hmget_rd(char *as_key, int ai_greenflag, char *as_element,char**as_value,int len,int*count)
  *
  *  @��������: ����keyֵ����ֵ��ȡvalue
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:��ֵ(һ�������ÿո���)
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		count:����ֵ������
  * 		  
  * 		
  *  @return :��
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

/** @������ :int get_all_hashvalue_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @��������: ����keyֵ��ȡȫ��value
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		count:����ֵ������
  * 		  
  * 		
  *  @return :��
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
/** @������ :int hvals_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @��������: ����keyֵ��ȡȫ��value
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		count:����ֵ������
  * 		  
  * 		
  *  @return :��
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
/** @������ :int get_all_hashfieldandvalue_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @��������: ����keyֵ��ȡȫ����ֵ��value
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_value:������ֵ��valueֵ
  *		len:����as_value����һά�ĳ���
  *		count:����ֵ������
  * 		  
  * 		
  *  @return :��
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
/** @������ :int hgetall_rd(char *as_key, int ai_greenflag, char**as_value,int len,int*count)
  *
  *  @��������: ����keyֵ��ȡȫ����ֵ��value
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_value:������ֵ��valueֵ
  *		len:����as_value����һά�ĳ���
  *		count:����ֵ������
  * 		  
  * 		
  *  @return :��
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
/** @������ :int del_hashvalue_rd(char *as_key, int ai_greenflag, int *ai_element)
  *
  *  @��������: ɾ����ϣ���е�ĳ������ĳ������
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:Ҫɾ��������
  *		
  * 		  
  * 		
  *  @return :��
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



/** @������ :int hdel_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������: ɾ����ϣ���е�ĳ������ĳ������
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:Ҫɾ��������(�ɶ��ʹ�ÿո���)
  *		
  * 		  
  * 		
  *  @return :��
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
/** @������ :int change_hashvalue_rd(char *as_key, int ai_greenflag, int *ai_element,char**as_value,int len)
  *
  *  @��������: �޸Ĺ�ϣ���е�ĳ������ĳ�������ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:��ֵ����
  *		as_value:valueֵ
  *		len:����as_value����һά�ĳ���
  *		
  * 		  
  * 		
  *  @return :��
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



/** @������ :int hmchange_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������: �޸Ĺ�ϣ���е�ĳ������ĳ�������ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:Ҫ�޸ĵ�����(�ɶ��ʹ�ÿո���)
  *		
  * 		  
  * 		
  *  @return :��
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

/** @������ :int add_hashvalue_rd(char *as_key, int ai_greenflag, int ai_element,char*as_value)
  *
  *  @��������: ���Ѵ��ڵĹ�ϣ�������һ�����ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:��ֵ����
  *		as_value:valueֵ
  *		len:����as_value����һά�ĳ���
  *		
  * 		  
  * 		
  *  @return :��
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

/** @������ :int hsetnx_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������:���Ѵ��ڵĹ�ϣ�������һ�����ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:Ҫ��ӵ���ֵ
  *		
  * 		  
  * 		
  *  @return :��
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

/** @������ :long long increase_int_hashvalue_rd(char *as_key, int ai_greenflag, int ai_element,int as_value)
  *
  *  @��������:���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ������ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:Ҫ�������ֵ
  *		ai_value:Ҫ�ӵ���ֵ
  * 		  
  * 		
  *  @return :��
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
/** @������ :int hincrby_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������:���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ������ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:Ҫ���ӵ���ֵ
  *		
  * 		  
  * 		
  *  @return :��
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


/** @������ :float increase_float_hashvalue_rd(char *as_key, int ai_greenflag, int ai_element,float ai_value)
  *
  *  @��������:���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ��������
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		ai_element:Ҫ�������ֵ
  *		af_value:Ҫ�ӵ���ֵ
  * 		  
  * 		
  *  @return :��
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
/** @������ :int hincrbyfloat_rd(char *as_key, int ai_greenflag, char *as_element)
  *
  *  @��������:���Ѵ��ڵĹ�ϣ����ĳ�����ֵ����ĳ��������ֵ
  * 							 
  *
  *  @param:  as_key:keyֵ
  *		ai_num:��Ⱥ���
  *		ai_greenflag:�������ȼ�
  *		as_element:Ҫ���ӵ���ֵ
  *		
  * 		  
  * 		
  *  @return :��
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
/** @������ :int scan_all_hashtable_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select)
  *  @��������:����ͨ���ɨ��keyֵ(����)
  * 							 
  *
  *  @param:  
  *		ai_num:��Ⱥ���
  *		ai_redisnum:����redis�±�
  *		ai_greenflag:�������ȼ�
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		ai_count:����ֵ������
  *		as_select:�Ѳ��ͨ���
  *		ai_maxcount:ÿ���Ѳ���������
  *		
  * 		  
  * 		
  *  @return :��
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

/** @������ :int hscanall_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,char*as_select,int ai_maxcount)
  *
  *  @��������:����ͨ���ɨ��keyֵ(����)
  * 							 
  *
  *  @param: 
  *		ai_num:��Ⱥ���
  *		ai_redisnum:����redis�±�
  *		ai_greenflag:�������ȼ�
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		ai_count:����ֵ������
  *		as_select:�Ѳ��ͨ���
  *		ai_maxcount:ÿ���Ѳ���������
  *		
  * 		  
  * 		
  *  @return :��
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

/** @������ :int scan_part_hashtable_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount)
  *  @��������:����ͨ���ɨ��keyֵ(����)
  * 							 
  *
  *  @param:  
  *		ai_num:��Ⱥ���
  *		ai_redisnum:����redis�±�
  *		ai_greenflag:�������ȼ�
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		ai_count:����ֵ������
  *		as_select:�Ѳ��ͨ���
  *		ai_maxcount:ÿ���Ѳ���������
  *		
  * 		  
  * 		
  *  @return :��
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
/** @������ :int hscan_rd(int ai_redisnum,int ai_greenflag,char**as_value,int len,int*ai_count,int ai_start,char*as_select,int ai_maxcount)
  *
  *  @��������:����ͨ���ɨ��keyֵ(����)
  * 							 
  *
  *  @param:  
  *		ai_num:��Ⱥ���
  *		ai_redisnum:����redis�±�
  *		ai_greenflag:�������ȼ�
  *		as_value:����valueֵ
  *		len:����as_value����һά�ĳ���
  *		ai_count:����ֵ������
  *		ai_start:��ʼ�Ѳ��λ��
  *		as_select:�Ѳ��ͨ���
  *		ai_maxcount:ÿ���Ѳ���������
  *		
  * 		  
  * 		
  *  @return :��
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


/** @������ :int delkey_rd(char *as_key,ai_num, int ai_greenflag)
  *
  *  @��������: ɾ������KEYֵ
  * 							 
  *
  *  @param:  char *as_key     ������KEYֵ
  *		int 	ai_num:		��Ⱥ���
  * 		  int ai_greenflag �����б�ʶ 0 ��ͨ���� 1��ɫ����
  * 		
  *  @return :��
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

/** @������ :int exists_rd(char *as_key,ai_num, int ai_greenflag)
  *
  *  @��������: �ж�KEYֵ�Ƿ����
  * 							 
  *
  *  @param:  char *as_key         ������KEYֵ
  *		int 	ai_num:		��Ⱥ���
  *           int ai_greenflag     �������ʶ 1 ��ɫ 0 ����ɫ
  *  @return :1 ����, 0 ������,-1����ʧ��
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



/** @������ :int set_keyttl(char *as_key,int ai_num, int ai_greenflag,int ai_time)
  *
  *  @��������: ��keyֵ���ó�ʱʱ��
  * 							 
  *
  *  @param:  char *as_key         ������KEYֵ
  *		int 	ai_num:		��Ⱥ���
  *           int ai_greenflag�������ʶ 1 ��ɫ 0 ����ɫ
  *		int ai_time:	keyֵ�ĳ�ʱʱ��
  *  @return :1 ���óɹ�, 0 ���ò��ɹ�,-1����ʧ��
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


/** @������ :int del_keyttl(char *as_key,int ai_num, int ai_greenflag)
  *
  *  @��������: �Ƴ�keyֵ�ĳ�ʱʱ��
  * 							 
  *
  *  @param:  char *as_key         ������KEYֵ
  *		int 	ai_num:		��Ⱥ���
  *           int ai_greenflag�������ʶ 1 ��ɫ 0 ����ɫ
  *  @return :1 ���óɹ�, 0 ���ò��ɹ�,-1����ʧ��
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