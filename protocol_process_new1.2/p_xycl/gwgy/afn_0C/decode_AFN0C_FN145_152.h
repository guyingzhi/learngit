#ifndef DECODE_AFN0CG19_H_INCLUDED
#define DECODE_AFN0CG19_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#ifdef _WIN32
#include "..\decode_public.h"
#else
#include "../public/decode_public.h"
#endif
#include "../public/public.h"
/* F145F146F147F148F149F150F151F152  */
typedef struct str_AFN0C_G19_t
{
    datetime	date;               /* 抄表时间 */
    short		dateisnull;         /* 抄表时间判空标志 */
    uchar		FLS;   				/* 费率数 1～14*/
    double 		val[15];            /* 当月正向有功最大需量 总、费率1～14*/
    short		valisnull[15];		/* 判空标志 */
    datetime	dt[15];				/* 最大需量发生时间 */
    short		dtisnull[15];		/* 时间判空标志 */
}str_AFN0C_G19;


int decode_afn0C_G19(uchar *as_data, str_AFN0C_G19 *astr_val, int *ai_step);

#endif
