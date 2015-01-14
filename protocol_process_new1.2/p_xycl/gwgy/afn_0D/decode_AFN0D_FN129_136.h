#ifndef DECODE_AFN0D_FN121_136_H
#define DECODE_AFN0D_FN121_136_H


#include "../public/decode_public.h"


typedef struct str_AFN0D_F219F130_VAL_t
{
    datetime TD;           							 /*时标*/
    unsigned short overlimit;        						/*越上限时间*/
    unsigned short overlower;       							 /*越下限时间*/
    double MAXval;         								 /*最大值*/
    datetime MAXvaltime;   						 /*最大值出现时间*/
    double MINval;          			/*最小值*/
    datetime MINvaltime;   			 /*最小值出现时间*/
}str_AFN0D_F219F130_VAL;

typedef struct str_AFN0D_F219F130_ISNULL_t
{
    short TD;               /*时标判空标志*/
    short overlimit;        /*越上限时间判空标志*/
    short overlower;        /*越下限时间判空标志*/
    short MAXval;           /*最大值判空标志*/
    short MAXvaltime;       /*最大值出现时间判空标志*/
    short MINval;           /*最小值判空标志*/
    short MINvaltime;       /*最小值出现时间判空标志*/
}str_AFN0D_F219F130_ISNULL;

typedef struct str_AFN0D_F219F130_t
{
    str_AFN0D_F219F130_VAL val;
    str_AFN0D_F219F130_ISNULL isnull;
}str_AFN0D_F219F130;

int decode_AFN0D_F129(uchar *data, str_AFN0D_F219F130 *astr_val, int *ai_step);
int decode_AFN0D_F130(uchar *data, str_AFN0D_F219F130 *astr_val, int *ai_step);



#endif 
