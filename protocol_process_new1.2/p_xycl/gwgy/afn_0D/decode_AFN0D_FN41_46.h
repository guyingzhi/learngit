#ifndef DECODE_AFN0D_FN41_46_H
#define DECODE_AFN0D_FN41_46_H


#include "../public/decode_public.h"

typedef struct str_AFN0D_F41_t
{
       datetime TD;                /*ʱ��*/
	short TDisnull;
	double TRSJ[9];
	
	double 	TRCS[9];
}str_AFN0D_F41;

typedef struct str_AFN0D_F42_t
{
       datetime TD;                /*ʱ��*/
	short TDisnull;
	double 	BCDN_D;       /*�ղ����޹�������*/
	short BCDN_Disnull;
	double 	BCDN_M;       /*�²����޹�������*/
	short BCDN_Misnull;
}str_AFN0D_F42;

typedef struct str_AFN0D_F43_t
{
    datetime TD;                /*�ն���������ʱ��*/
    short TDisnull;
    unsigned short LJSJ_1;/*����1�ۼ�ʱ��*/
    short LJSJ_1isnull;
    unsigned short LJSJ_2;
    short LJSJ_2isnull;
    unsigned short LJSJ_3;
    short LJSJ_3isnull;
	
}str_AFN0D_F43;

typedef struct str_AFN0D_F44_t
{
    datetime TD;                /*�¶���������ʱ��*/
    short TDisnull;
    unsigned short LJSJ_1;/*����1�ۼ�ʱ��*/
    short LJSJ_1isnull;
    unsigned short LJSJ_2;
    short LJSJ_2isnull;
    unsigned short LJSJ_3;
    short LJSJ_3isnull;
	
}str_AFN0D_F44;

typedef struct str_AFN0D_F45_t
{
    datetime TD;                /*��ʱ��*/
    short TDisnull;
    double Copper_YGDN;        /*ͭ���й�����ʾֵ*/
    short Copper_YGDNisnull;
    double Iron_YGDN;		/*�����й�����ʾֵ*/
    short Iron_YGDNisnull;
}str_AFN0D_F45;

typedef struct str_AFN0D_F46_t
{
        datetime TD;                /*��ʱ��*/
	 short TDisnull;
        double Copper_YGDN;        /*ͭ���й�����ʾֵ*/
        short Copper_YGDNisnull;
        double Iron_YGDN;		/*�����й�����ʾֵ*/
        short Iron_YGDNisnull;	
}str_AFN0D_F46;


int decode_afn0D_F41_str(uchar *data, str_AFN0D_F41 *astr_val, int *ai_step);
int decode_afn0D_F42_str(uchar *data, str_AFN0D_F42 *astr_val, int *ai_step);
int decode_afn0D_F43_str(uchar *data, str_AFN0D_F43 *astr_val, int *ai_step);
int decode_afn0D_F44_str(uchar *data, str_AFN0D_F44 *astr_val, int *ai_step);
int decode_afn0D_F45_str(uchar *data, str_AFN0D_F45 *astr_val, int *ai_step);
int decode_afn0D_F46_str(uchar *data, str_AFN0D_F46 *astr_val, int *ai_step);



#endif