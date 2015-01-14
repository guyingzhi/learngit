#ifndef DECODE_AFN0CF57_64__H_INCLUDED
#define DECODE_AFN0CF57_64__H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#ifdef _WIN32
#include "..\decode_public.h"
#else
#include "../public/public.h"
#endif
#include "../public/decode_public.h"


typedef struct str_AFN0C_F57F58_VAL_t
{
    uchar xbcnt;                 /*谐波次数*/
    double Ua[19], Ub[19], Uc[19];		/*ABC相总谐波电压含有率1~19*/
    double Ia[19], Ib[19], Ic[19];		/*A B C相总谐波电流含有率1~19*/
}str_AFN0C_F57F58_VAL;


typedef struct str_AFN0C_F57F58_ISNULL_t
{
    short Ua[19], Ub[19], Uc[19];  /*从1开始*/
    short Ia[19], Ib[19], Ic[19];
}str_AFN0C_F57F58_ISNULL;


typedef struct str_AFN0C_F57F58_t
{
    str_AFN0C_F57F58_VAL val;
    str_AFN0C_F57F58_ISNULL isnull;
}str_AFN0C_F57F58;


int decode_afn0C_F57(uchar *as_data, str_AFN0C_F57F58 *astr_val, int *ai_step);
int decode_afn0C_F58(uchar *as_data, str_AFN0C_F57F58 *astr_val, int *ai_step);

#endif // DECODE_AFN0CG08_H_INCLUDED
