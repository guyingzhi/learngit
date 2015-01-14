#ifndef DECODE_AFN0C0_F41_48_H_INCLUDED
#define  DECODE_AFN0C0_F41_48_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#ifdef _WIN32
#include "..\public/public.h"
#else
#include "../public/public.h"
#endif

#include "../public/decode_public.h"

typedef struct str_AFN0C_F41_48_t
{
    uchar flnum;            /*费率数*/
    double val;              /*总*/
    double valfl[14];        /*费率*/
    short valisnull;
    short valflisnull[14];
}str_AFN0C_FN41_48;

//int decode_afn0C_F41_F48(uchar *as_data, str_AFN0C_FN41_48 *astr_val, int *ai_step);
 int decode_afn0C_F4all(uchar *as_data, str_AFN0C_FN41_48 *astr_val, int *ai_step);
#endif 
