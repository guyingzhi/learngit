#ifndef ENCODE_AFN0C_FN1_8_H
#define ENCODE_AFN0C_FN1_8_H

#include "../public/decode_public.h"

/*****376.1******/

typedef struct  str_AFN0C_F2_t
{
    datetime    termdt;           			/*�ն�����ʱ��*/
    short       termdtisnull;    			 /*�ն�������������пձ�־*/
}str_AFN0C_FN2;

typedef struct  str_AFN0C_F3_t
{
    uchar  arg[248]; 					  /*����ӳ���*/
}str_AFN0C_FN3;

typedef struct str_AFN0C_F4_t
{
	uchar report;         				  /**1~2���α�ʾ����/��ֹ�ϱ�**/
	uchar message;				  /**1~2���α�ʾ����/��ֹͨ��**/
}str_AFN0C_FN4;

typedef struct str_AFN0C_F5_group_t
{
	uchar projectid;             			 /*���ض�ֵ������*/
	uchar gksd[8];               			 /*����ʱ�α�־1~8ʱ��*/
	uchar sdk, cxk, yybtk, glxfk; 		/*���أ�ʱ�ο�  ���ݿ�  Ӫҵ��ͣ��  ��ǰ�����¸���*/
	uchar ydk, gdk;              		 	/*��أ��µ��  �����*/
	uchar turngk[8];              		/*�����ִ�״̬*/
	uchar turndk[8];              		/*����ִ�״̬*/ 
} str_AFN0C_FN5_group;

typedef struct  str_AFN0C_F5_t
{
    uchar  bd, tc, cfgj;                 		/*���硢�޳��ʹ߷Ѹ澯Ͷ��״̬*/
    uchar  sum[8];               			/*�ܼ����־*/
    str_AFN0C_FN5_group ctrl[8];		  /*�ܼ��������Ϣ*/
}str_AFN0C_FN5;

typedef struct str_AFN0C_F6_group_t
{
	uchar gkdz;                                      	 /*��ǰ���ض�ֵ*/
	uchar gkdzisnull;					/*�ж��Ƿ�Ϊ��*/
	uchar k;						 	/*��ǰ�����¸���ϵ��*/
	uchar kisnull;
	uchar gltz[8];					 	 /*������բ���*/
	uchar mondgtz[8];					 /*�µ繩��բ���״̬*/
	uchar buydgtz[8];					 /*�������բ���״̬*/
	uchar sdk, cxk, yybtk, glxfk;			/*����Խ��ʱ�οգ����ݿأ�Ӫҵ��ͣ�أ���ǰ�����¸�����*/
	uchar mondkyj,buydky;				/*���Խ���µ�أ������*/
}str_AFN0C_FN6_group;
typedef struct str_AFN0C_F6_t
{
	uchar  yktz[8];
	uchar cfgj;
	uchar  sum[8];
	str_AFN0C_FN6_group ctrl[8];
}str_AFN0C_FN6;
typedef struct str_AFN0C_F7_t
{
	uchar EC1;			/*��Ҫ�¼�������ֵ*/
	uchar EC2;			/*һ���¼�������ֵ*/
}str_AFN0C_FN7;
typedef struct str_AFN0C_F8_t
{
	uchar ERC[64];			/*�¼�״̬��־ERC1~ERC64*/
}str_AFN0C_FN8;

int decode_afn0C_F2(uchar * data, str_AFN0C_FN2* lstr_val, int * ai_len);
int decode_afn0C_F3(uchar * data, str_AFN0C_FN3* lstr_val, int * ai_len);
int decode_afn0C_F4(uchar *data,  str_AFN0C_FN4 *lstr_val,int *ai_len);
int decode_afn0C_F5(uchar *data,  str_AFN0C_FN5 *lstr_val,int *ai_len);
int decode_afn0C_F6(uchar *data,  str_AFN0C_FN6 *lstr_val,int *ai_len);
int decode_afn0C_F7(uchar *data,  str_AFN0C_FN7 *lstr_val,int *ai_len);
int decode_afn0C_F8(uchar *data,  str_AFN0C_FN8 *lstr_val,int *ai_len);
#endif
