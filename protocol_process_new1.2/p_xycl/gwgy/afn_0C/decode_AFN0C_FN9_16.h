#ifndef ENCODE_AFN0C_FN9_16_H
#define ENCODE_AFN0C_FN9_16_H
#include "../public/public.h"
#include "../public/decode_public.h"

/*****376.1******/

typedef struct str_AFN0C_F9_t
{
	uchar ST[8];      		 /*״̬����״̬ST*/
	uchar CD[8];       		/*״̬���ı�λCD*/
}str_AFN0C_FN9;	

typedef struct str_AFN0C_F10_t
{
	unsigned int daytotal;         	/*�ն�����վ����ͨ������*/
	unsigned int monthtotal;       /*�ն�����վ����ͨ������*/
}str_AFN0C_FN10;

typedef struct str_AFN0C_F11_group_t
{
	uchar   port;                          		/*�ն�ͨ�Ŷ˿ں�*/
	unsigned short   total_cb;            	 /*Ҫ���������*/
	uchar   cbokflag;                     	 /*��������ʱ�������/δ��ɱ�־λ*/
	uchar   cbingflag;                     	/*����æ/�б�־λ*/
	unsigned short   cboktotal;            /*����ɹ�����*/
	uchar   cbzdtotal;                     	/*���ص��ɹ�����*/
	datetime   cbkssj;                     	/*����ʼʱ��*/
	short   cbkssjisnull;
	datetime   cbjssj;                     	/*�������ʱ��*/
	short   cbjssjisnull;
}str_AFN0C_FN11_group;

typedef struct str_AFN0C_F11_t
{
	uchar   number;				/*���ݿ����*/
	str_AFN0C_FN11_group val[32] ;      
}str_AFN0C_FN11;

typedef struct str_AFN0C_F12_t
{
	uchar ST[8];      		 /*״̬����״̬ST��λһ��*/
	uchar CD[8];       		/*״̬���ı�λCD��λһ��*/
}str_AFN0C_FN12;





int decode_afn0C_F9(uchar * data, str_AFN0C_FN9* lstr_val, int * ai_len);
int decode_afn0C_F10(uchar * data, str_AFN0C_FN10* lstr_val, int *ai_len);
int decode_afn0C_F11(uchar *data,  str_AFN0C_FN11 *lstr_val, int *ai_len);
int decode_afn0C_F12(uchar *data,  str_AFN0C_FN12 *lstr_val, int *ai_len);
/*
int decode_afn0C_F13(uchar *data,  str_AFN0C_FN13 *lstr_val, int *ai_len);
int decode_afn0C_F14(uchar *data,  str_AFN0C_FN14 *lstr_val, int *ai_len);
*/
#endif