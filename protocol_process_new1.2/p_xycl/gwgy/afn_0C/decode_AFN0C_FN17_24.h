#ifndef ENCODE_AFN0C_FN17_24_H
#define ENCODE_AFN0C_FN17_24_H
#include "../public/public.h"
#include "../public/decode_public.h"

/*****376.1******/

typedef struct str_AFN0C_F17_t
{
	double val;            			 /*��ǰ�ܼ��й�����*/
	short valisnull;      			 /*�пձ�־*/
}str_AFN0C_FN17;

typedef struct str_AFN0C_F18_t
{
	double idle;            			 /*��ǰ�ܼ��޹�����*/
	short idleisnull;      			 /*�пձ�־*/
}str_AFN0C_FN18;
typedef struct str_AFN0C_sum_t
{
	uchar ratenum;           	/*������*/
	short ratelnumisnull;    	 /*�������Ϸ���־ 1��14*/
	int val;            			 /*�ܼ��ܵ�����*/
	short valisnull;       		/*�пձ�־*/
	int varate[14];      		 /*����N�ܼӵ�����*/
	short valtateisnull[14]; 	/*�пձ�־*/
}str_AFN0C_sum;


typedef struct  str_AFN0C_F19_t
{
	str_AFN0C_sum data;     /*�����ܼ��й�*/
}str_AFN0C_FN19;

typedef struct  str_AFN0C_F20_t
{
	str_AFN0C_sum data;    /*�����ܼ��޹�*/
}str_AFN0C_FN20;


typedef struct  str_AFN0C_F21_t
{
	str_AFN0C_sum data;    /*�����ܼ��й�*/
}str_AFN0C_FN21;

typedef struct  str_AFN0C_F22_t
{
	str_AFN0C_sum data;    /*�����ܼ��޹�*/
}str_AFN0C_FN22;

typedef struct str_AFN0C_F23_t
{
	int val;
	short valisnull;
}str_AFN0C_FN23;
typedef struct str_AFN0C_F24_t
{
	double val;             /*�غ��ܼ��й����ʶ���ֵ*/
	short valisnull;       /*�пձ�־*/	
}str_AFN0C_FN24;
;
int decode_afn0C_F17(uchar * data, str_AFN0C_FN17* lstr_val, int * ai_len);
int decode_afn0C_F18(uchar * data, str_AFN0C_FN18* lstr_val, int * ai_len);
int decode_afn0C_F19(uchar * data, str_AFN0C_FN19* lstr_val, int * ai_len);
int decode_afn0C_F20(uchar * data, str_AFN0C_FN20* lstr_val, int * ai_len);
int decode_afn0C_F21(uchar * data, str_AFN0C_FN21* lstr_val, int * ai_len);
int decode_afn0C_F22(uchar * data, str_AFN0C_FN22* lstr_val, int * ai_len);
int decode_afn0C_F23(uchar * data, str_AFN0C_FN23* lstr_val, int * ai_len);
int decode_afn0C_F24(uchar * data, str_AFN0C_FN24* lstr_val, int * ai_len);

#endif