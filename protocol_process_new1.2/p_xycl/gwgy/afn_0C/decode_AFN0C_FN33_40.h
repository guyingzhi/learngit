#ifndef DECODE_AFN0C_FN33_44_H_INCLUDED
#define  DECODE_AFN0C_FN33_44_H_INCLUDED
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
typedef struct str_AFN0C_F33_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double zxygz;           /*正向有功总*/
    double zxyg[14];       /*正向有功费率*/
    double zxwgz;           /*正向无功总*/
    double zxwg[14];       /*正向无功费率*/
    double wgz1;            /*第一象限无功总*/
    double wg1[14];        /*第一象限无功费率*/
    double wgz4;            /*第四象限无功总*/
    double wg4[14];        /*第四象限无功费率*/
}str_AFN0C_F33_VAL;


typedef struct str_AFN0C_F33_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short zxygz;           /*正向有功总*/
    short zxyg[14];       /*正向有功费率*/
    short zxwgz;           /*正向无功总*/
    short zxwg[14];       /*正向无功费率*/
    short wgz1;            /*第一象限无功总*/
    short wg1[14];        /*第一象限无功费率*/
    short wgz4;            /*第四象限无功总*/
    short wg4[14];        /*第四象限无功费率*/
}str_AFN0C_F33_ISNULL;


typedef struct str_AFN0C_F33_t
{
    str_AFN0C_F33_VAL val;
    str_AFN0C_F33_ISNULL isnull;
}str_AFN0C_FN33;


typedef struct str_AFN0C_F34_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double fxygz;           /*反向有功总*/
    double fxyg[14];       /*反向有功费率*/
    double fxwgz;           /*反向无功总*/
    double fxwg[14];       /*反向无功费率*/
    double wgz2;            /*第二象限无功总*/
    double wg2[14];        /*第二象限无功费率*/
    double wgz3;            /*第三象限无功总*/
    double wg3[14];        /*第三象限无功费率*/
}str_AFN0C_F34_VAL;


typedef struct str_AFN0C_F34_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short fxygz;           /*反向有功总*/
    short fxyg[14];       /*反向有功费率*/
    short fxwgz;           /*反向无功总*/
    short fxwg[14];       /*反向无功费率*/
    short wgz2;            /*第二象限无功总*/
    short wg2[14];        /*第二象限无功费率*/
    short wgz3;            /*第三象限无功总*/
    short wg3[14];        /*第三象限无功费率*/
}str_AFN0C_F34_ISNULL;


typedef struct str_AFN0C_F34_t
{
    str_AFN0C_F34_VAL val;
    str_AFN0C_F34_ISNULL isnull;
}str_AFN0C_FN34;



typedef struct str_AFN0C_F35_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double zxygz;           /*正向有功总需量*/
    double zxyg[14];       /*正向有功费率需量*/
    datetime zxygzdt;       /*总发生时间*/
    datetime zxygdt[14];   /*发生时间*/
    double zxwgz;           /*正向无功总需量*/
    double zxwg[14];       /*正向无功费率需量*/
    datetime zxwgzdt;       /*总发生时间*/
    datetime zxwgdt[14];   /*发生时间*/
}str_AFN0C_F35_VAL;

typedef struct str_AFN0C_F35_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short zxygz;           /*正向有功总需量*/
    short zxyg[14];       /*正向有功费率需量*/
    short zxygzdt;         /*总发生时间*/
    short zxygdt[14];     /*发生时间*/
    short zxwgz;           /*正向无功总需量*/
    short zxwg[14];       /*正向无功费率需量*/
    short zxwgzdt;         /*总发生时间*/
    short zxwgdt[14];     /*发生时间*/
}str_AFN0C_F35_ISNULL;

typedef struct str_AFN0C_F35_t
{
    str_AFN0C_F35_VAL val;
    str_AFN0C_F35_ISNULL isnull;
}str_AFN0C_FN35;


typedef struct str_AFN0C_F36_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double fxygz;           /*反向有功总需量*/
    double fxyg[14];       /*反向有功费率需量*/
    datetime fxygzdt;       /*总发生时间*/
    datetime fxygdt[14];   /*发生时间*/
    double fxwgz;           /*反向无功总需量*/
    double fxwg[14];       /*反向无功费率需量*/
    datetime fxwgzdt;       /*总发生时间*/
    datetime fxwgdt[14];   /*发生时间*/
}str_AFN0C_F36_VAL;

typedef struct str_AFN0C_F36_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short fxygz;           /*反向有功总需量*/
    short fxyg[14];       /*反向有功费率需量*/
    short fxygzdt;         /*总发生时间*/
    short fxygdt[14];     /*发生时间*/
    short fxwgz;           /*反向无功总需量*/
    short fxwg[14];       /*反向无功费率需量*/
    short fxwgzdt;         /*总发生时间*/
    short fxwgdt[14];     /*发生时间*/
}str_AFN0C_F36_ISNULL;

typedef struct str_AFN0C_F36_t
{
    str_AFN0C_F36_VAL val;
    str_AFN0C_F36_ISNULL isnull;
}str_AFN0C_FN36;

typedef struct str_AFN0C_F37_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double zxygz;           /*正向有功总*/
    double zxyg[14];       /*正向有功费率*/
    double zxwgz;           /*正向无功总*/
    double zxwg[14];       /*正向无功费率*/
    double wgz1;            /*第一象限无功总*/
    double wg1[14];        /*第一象限无功费率*/
    double wgz4;            /*第四象限无功总*/
    double wg4[14];        /*第四象限无功费率*/
}str_AFN0C_F37_VAL;


typedef struct str_AFN0C_F37_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short zxygz;           /*正向有功总*/
    short zxyg[14];       /*正向有功费率*/
    short zxwgz;           /*正向无功总*/
    short zxwg[14];       /*正向无功费率*/
    short wgz1;            /*第一象限无功总*/
    short wg1[14];        /*第一象限无功费率*/
    short wgz4;            /*第四象限无功总*/
    short wg4[14];        /*第四象限无功费率*/
}str_AFN0C_F37_ISNULL;


typedef struct str_AFN0C_F37_t
{
    str_AFN0C_F37_VAL val;
    str_AFN0C_F37_ISNULL isnull;
}str_AFN0C_FN37;


typedef struct str_AFN0C_F38_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double fxygz;           /*反向有功总*/
    double fxyg[14];       /*反向有功费率*/
    double fxwgz;           /*反向无功总*/
    double fxwg[14];       /*反向无功费率*/
    double wgz2;            /*第二象限无功总*/
    double wg2[14];        /*第二象限无功费率*/
    double wgz3;            /*第三象限无功总*/
    double wg3[14];        /*第三象限无功费率*/
}str_AFN0C_F38_VAL;


typedef struct str_AFN0C_F38_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short fxygz;           /*反向有功总*/
    short fxyg[14];       /*反向有功费率*/
    short fxwgz;           /*反向无功总*/
    short fxwg[14];       /*反向无功费率*/
    short wgz2;            /*第二象限无功总*/
    short wg2[14];        /*第二象限无功费率*/
    short wgz3;            /*第三象限无功总*/
    short wg3[14];        /*第三象限无功费率*/
}str_AFN0C_F38_ISNULL;


typedef struct str_AFN0C_F38_t
{
    str_AFN0C_F38_VAL val;
    str_AFN0C_F38_ISNULL isnull;
}str_AFN0C_FN38;


typedef struct str_AFN0C_F39_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double zxygz;           /*正向有功总需量*/
    double zxyg[14];       /*正向有功费率需量*/
    datetime zxygzdt;       /*总发生时间*/
    datetime zxygdt[14];   /*发生时间*/
    double zxwgz;           /*正向无功总需量*/
    double zxwg[14];       /*正向无功费率需量*/
    datetime zxwgzdt;       /*总发生时间*/
    datetime zxwgdt[14];   /*发生时间*/
}str_AFN0C_F39_VAL;

typedef struct str_AFN0C_F39_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short zxygz;           /*正向有功总需量*/
    short zxyg[14];       /*正向有功费率需量*/
    short zxygzdt;         /*总发生时间*/
    short zxygdt[14];     /*发生时间*/
    short zxwgz;           /*正向无功总需量*/
    short zxwg[14];       /*正向无功费率需量*/
    short zxwgzdt;         /*总发生时间*/
    short zxwgdt[14];     /*发生时间*/
}str_AFN0C_F39_ISNULL;

typedef struct str_AFN0C_F39_t
{
    str_AFN0C_F39_VAL val;
    str_AFN0C_F39_ISNULL isnull;
}str_AFN0C_FN39;


typedef struct str_AFN0C_F40_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    uchar flnum;            /*费率数*/
    double fxygz;           /*反向有功总需量*/
    double fxyg[14];       /*反向有功费率需量*/
    datetime fxygzdt;       /*总发生时间*/
    datetime fxygdt[14];   /*发生时间*/
    double fxwgz;           /*反向无功总需量*/
    double fxwg[14];       /*反向无功费率需量*/
    datetime fxwgzdt;       /*总发生时间*/
    datetime fxwgdt[14];   /*发生时间*/
}str_AFN0C_FN40_VAL;


typedef struct str_AFN0C_F40_ISNULL_t
{
    short cbtime;          /*抄表时间*/
    short flnum;           /*费率数*/
    short fxygz;           /*反向有功总需量*/
    short fxyg[14];       /*反向有功费率需量*/
    short fxygzdt;         /*总发生时间*/
    short fxygdt[14];     /*发生时间*/
    short fxwgz;           /*反向无功总需量*/
    short fxwg[14];       /*反向无功费率需量*/
    short fxwgzdt;         /*总发生时间*/
    short fxwgdt[14];     /*发生时间*/
}str_AFN0C_FN40_ISNULL;


typedef struct str_AFN0C_F40_t
{
    str_AFN0C_FN40_VAL val;
    str_AFN0C_FN40_ISNULL isnull;
}str_AFN0C_FN40;


int decode_afn0C_F33(uchar *as_data, str_AFN0C_FN33 *astr_val, int *ai_step);
int decode_afn0C_F34(uchar *as_data, str_AFN0C_FN34 *astr_val, int *ai_step);
int decode_afn0C_F35(uchar *as_data, str_AFN0C_FN35 *astr_val, int *ai_step);
int decode_afn0C_F36(uchar *as_data, str_AFN0C_FN36 *astr_val, int *ai_step);
int decode_afn0C_F37(uchar *as_data, str_AFN0C_FN37 *astr_val, int *ai_step);
int decode_afn0C_F38(uchar *as_data, str_AFN0C_FN38 *astr_val, int *ai_step);
int decode_afn0C_F39(uchar *as_data, str_AFN0C_FN39 *astr_val, int *ai_step);
int decode_afn0C_F40(uchar *as_data, str_AFN0C_FN40 *astr_val, int *ai_step);


#endif // DECODE_AFN0CG05_H_INCLUDED
