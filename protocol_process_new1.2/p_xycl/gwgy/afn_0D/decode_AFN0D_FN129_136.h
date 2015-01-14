#ifndef DECODE_AFN0D_FN121_136_H
#define DECODE_AFN0D_FN121_136_H


#include "../public/decode_public.h"


typedef struct str_AFN0D_F219F130_VAL_t
{
    datetime TD;           							 /*ʱ��*/
    unsigned short overlimit;        						/*Խ����ʱ��*/
    unsigned short overlower;       							 /*Խ����ʱ��*/
    double MAXval;         								 /*���ֵ*/
    datetime MAXvaltime;   						 /*���ֵ����ʱ��*/
    double MINval;          			/*��Сֵ*/
    datetime MINvaltime;   			 /*��Сֵ����ʱ��*/
}str_AFN0D_F219F130_VAL;

typedef struct str_AFN0D_F219F130_ISNULL_t
{
    short TD;               /*ʱ���пձ�־*/
    short overlimit;        /*Խ����ʱ���пձ�־*/
    short overlower;        /*Խ����ʱ���пձ�־*/
    short MAXval;           /*���ֵ�пձ�־*/
    short MAXvaltime;       /*���ֵ����ʱ���пձ�־*/
    short MINval;           /*��Сֵ�пձ�־*/
    short MINvaltime;       /*��Сֵ����ʱ���пձ�־*/
}str_AFN0D_F219F130_ISNULL;

typedef struct str_AFN0D_F219F130_t
{
    str_AFN0D_F219F130_VAL val;
    str_AFN0D_F219F130_ISNULL isnull;
}str_AFN0D_F219F130;

int decode_AFN0D_F129(uchar *data, str_AFN0D_F219F130 *astr_val, int *ai_step);
int decode_AFN0D_F130(uchar *data, str_AFN0D_F219F130 *astr_val, int *ai_step);



#endif 
