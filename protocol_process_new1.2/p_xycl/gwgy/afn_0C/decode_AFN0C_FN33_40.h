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
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double zxygz;           /*�����й���*/
    double zxyg[14];       /*�����й�����*/
    double zxwgz;           /*�����޹���*/
    double zxwg[14];       /*�����޹�����*/
    double wgz1;            /*��һ�����޹���*/
    double wg1[14];        /*��һ�����޹�����*/
    double wgz4;            /*���������޹���*/
    double wg4[14];        /*���������޹�����*/
}str_AFN0C_F33_VAL;


typedef struct str_AFN0C_F33_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short zxygz;           /*�����й���*/
    short zxyg[14];       /*�����й�����*/
    short zxwgz;           /*�����޹���*/
    short zxwg[14];       /*�����޹�����*/
    short wgz1;            /*��һ�����޹���*/
    short wg1[14];        /*��һ�����޹�����*/
    short wgz4;            /*���������޹���*/
    short wg4[14];        /*���������޹�����*/
}str_AFN0C_F33_ISNULL;


typedef struct str_AFN0C_F33_t
{
    str_AFN0C_F33_VAL val;
    str_AFN0C_F33_ISNULL isnull;
}str_AFN0C_FN33;


typedef struct str_AFN0C_F34_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double fxygz;           /*�����й���*/
    double fxyg[14];       /*�����й�����*/
    double fxwgz;           /*�����޹���*/
    double fxwg[14];       /*�����޹�����*/
    double wgz2;            /*�ڶ������޹���*/
    double wg2[14];        /*�ڶ������޹�����*/
    double wgz3;            /*���������޹���*/
    double wg3[14];        /*���������޹�����*/
}str_AFN0C_F34_VAL;


typedef struct str_AFN0C_F34_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short fxygz;           /*�����й���*/
    short fxyg[14];       /*�����й�����*/
    short fxwgz;           /*�����޹���*/
    short fxwg[14];       /*�����޹�����*/
    short wgz2;            /*�ڶ������޹���*/
    short wg2[14];        /*�ڶ������޹�����*/
    short wgz3;            /*���������޹���*/
    short wg3[14];        /*���������޹�����*/
}str_AFN0C_F34_ISNULL;


typedef struct str_AFN0C_F34_t
{
    str_AFN0C_F34_VAL val;
    str_AFN0C_F34_ISNULL isnull;
}str_AFN0C_FN34;



typedef struct str_AFN0C_F35_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double zxygz;           /*�����й�������*/
    double zxyg[14];       /*�����й���������*/
    datetime zxygzdt;       /*�ܷ���ʱ��*/
    datetime zxygdt[14];   /*����ʱ��*/
    double zxwgz;           /*�����޹�������*/
    double zxwg[14];       /*�����޹���������*/
    datetime zxwgzdt;       /*�ܷ���ʱ��*/
    datetime zxwgdt[14];   /*����ʱ��*/
}str_AFN0C_F35_VAL;

typedef struct str_AFN0C_F35_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short zxygz;           /*�����й�������*/
    short zxyg[14];       /*�����й���������*/
    short zxygzdt;         /*�ܷ���ʱ��*/
    short zxygdt[14];     /*����ʱ��*/
    short zxwgz;           /*�����޹�������*/
    short zxwg[14];       /*�����޹���������*/
    short zxwgzdt;         /*�ܷ���ʱ��*/
    short zxwgdt[14];     /*����ʱ��*/
}str_AFN0C_F35_ISNULL;

typedef struct str_AFN0C_F35_t
{
    str_AFN0C_F35_VAL val;
    str_AFN0C_F35_ISNULL isnull;
}str_AFN0C_FN35;


typedef struct str_AFN0C_F36_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double fxygz;           /*�����й�������*/
    double fxyg[14];       /*�����й���������*/
    datetime fxygzdt;       /*�ܷ���ʱ��*/
    datetime fxygdt[14];   /*����ʱ��*/
    double fxwgz;           /*�����޹�������*/
    double fxwg[14];       /*�����޹���������*/
    datetime fxwgzdt;       /*�ܷ���ʱ��*/
    datetime fxwgdt[14];   /*����ʱ��*/
}str_AFN0C_F36_VAL;

typedef struct str_AFN0C_F36_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short fxygz;           /*�����й�������*/
    short fxyg[14];       /*�����й���������*/
    short fxygzdt;         /*�ܷ���ʱ��*/
    short fxygdt[14];     /*����ʱ��*/
    short fxwgz;           /*�����޹�������*/
    short fxwg[14];       /*�����޹���������*/
    short fxwgzdt;         /*�ܷ���ʱ��*/
    short fxwgdt[14];     /*����ʱ��*/
}str_AFN0C_F36_ISNULL;

typedef struct str_AFN0C_F36_t
{
    str_AFN0C_F36_VAL val;
    str_AFN0C_F36_ISNULL isnull;
}str_AFN0C_FN36;

typedef struct str_AFN0C_F37_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double zxygz;           /*�����й���*/
    double zxyg[14];       /*�����й�����*/
    double zxwgz;           /*�����޹���*/
    double zxwg[14];       /*�����޹�����*/
    double wgz1;            /*��һ�����޹���*/
    double wg1[14];        /*��һ�����޹�����*/
    double wgz4;            /*���������޹���*/
    double wg4[14];        /*���������޹�����*/
}str_AFN0C_F37_VAL;


typedef struct str_AFN0C_F37_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short zxygz;           /*�����й���*/
    short zxyg[14];       /*�����й�����*/
    short zxwgz;           /*�����޹���*/
    short zxwg[14];       /*�����޹�����*/
    short wgz1;            /*��һ�����޹���*/
    short wg1[14];        /*��һ�����޹�����*/
    short wgz4;            /*���������޹���*/
    short wg4[14];        /*���������޹�����*/
}str_AFN0C_F37_ISNULL;


typedef struct str_AFN0C_F37_t
{
    str_AFN0C_F37_VAL val;
    str_AFN0C_F37_ISNULL isnull;
}str_AFN0C_FN37;


typedef struct str_AFN0C_F38_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double fxygz;           /*�����й���*/
    double fxyg[14];       /*�����й�����*/
    double fxwgz;           /*�����޹���*/
    double fxwg[14];       /*�����޹�����*/
    double wgz2;            /*�ڶ������޹���*/
    double wg2[14];        /*�ڶ������޹�����*/
    double wgz3;            /*���������޹���*/
    double wg3[14];        /*���������޹�����*/
}str_AFN0C_F38_VAL;


typedef struct str_AFN0C_F38_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short fxygz;           /*�����й���*/
    short fxyg[14];       /*�����й�����*/
    short fxwgz;           /*�����޹���*/
    short fxwg[14];       /*�����޹�����*/
    short wgz2;            /*�ڶ������޹���*/
    short wg2[14];        /*�ڶ������޹�����*/
    short wgz3;            /*���������޹���*/
    short wg3[14];        /*���������޹�����*/
}str_AFN0C_F38_ISNULL;


typedef struct str_AFN0C_F38_t
{
    str_AFN0C_F38_VAL val;
    str_AFN0C_F38_ISNULL isnull;
}str_AFN0C_FN38;


typedef struct str_AFN0C_F39_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double zxygz;           /*�����й�������*/
    double zxyg[14];       /*�����й���������*/
    datetime zxygzdt;       /*�ܷ���ʱ��*/
    datetime zxygdt[14];   /*����ʱ��*/
    double zxwgz;           /*�����޹�������*/
    double zxwg[14];       /*�����޹���������*/
    datetime zxwgzdt;       /*�ܷ���ʱ��*/
    datetime zxwgdt[14];   /*����ʱ��*/
}str_AFN0C_F39_VAL;

typedef struct str_AFN0C_F39_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short zxygz;           /*�����й�������*/
    short zxyg[14];       /*�����й���������*/
    short zxygzdt;         /*�ܷ���ʱ��*/
    short zxygdt[14];     /*����ʱ��*/
    short zxwgz;           /*�����޹�������*/
    short zxwg[14];       /*�����޹���������*/
    short zxwgzdt;         /*�ܷ���ʱ��*/
    short zxwgdt[14];     /*����ʱ��*/
}str_AFN0C_F39_ISNULL;

typedef struct str_AFN0C_F39_t
{
    str_AFN0C_F39_VAL val;
    str_AFN0C_F39_ISNULL isnull;
}str_AFN0C_FN39;


typedef struct str_AFN0C_F40_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    uchar flnum;            /*������*/
    double fxygz;           /*�����й�������*/
    double fxyg[14];       /*�����й���������*/
    datetime fxygzdt;       /*�ܷ���ʱ��*/
    datetime fxygdt[14];   /*����ʱ��*/
    double fxwgz;           /*�����޹�������*/
    double fxwg[14];       /*�����޹���������*/
    datetime fxwgzdt;       /*�ܷ���ʱ��*/
    datetime fxwgdt[14];   /*����ʱ��*/
}str_AFN0C_FN40_VAL;


typedef struct str_AFN0C_F40_ISNULL_t
{
    short cbtime;          /*����ʱ��*/
    short flnum;           /*������*/
    short fxygz;           /*�����й�������*/
    short fxyg[14];       /*�����й���������*/
    short fxygzdt;         /*�ܷ���ʱ��*/
    short fxygdt[14];     /*����ʱ��*/
    short fxwgz;           /*�����޹�������*/
    short fxwg[14];       /*�����޹���������*/
    short fxwgzdt;         /*�ܷ���ʱ��*/
    short fxwgdt[14];     /*����ʱ��*/
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
