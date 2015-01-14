#ifndef DECODE_AFN0CF129_144_H_INCLUDED
#define DECODE_AFN0CF129_144_H_INCLUDED

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

typedef struct str_AFN0C_LowVal_t
{
    datetime	date;               /* 抄表时间 */
    short		dateisnull;         /* 抄表时间判空标志 */
    uchar		FLS;   				/* 费率数 1～14*/
    double 		val[15];            /* 正向有功、正向无功、反向有功、反向无功电能示值 总、费率1～14*/
    short		valisnull[15];		/* 判空标志 */
}str_AFN0C_LowVal;

typedef struct str_AFN0C_F139_t
{
    datetime date;               /*时间*/
    short    dateisnull;         /*时间判空标志*/
    unsigned short meterindex;   /*电表序号*/
    uchar  flag;                 /*数据项标志*/
    double val;                  /*剩余电量*/
    short  valisnull;            /*剩余电量判空标志*/
    datetime cdsj;						  /*抄到时间*/
    short    cdsjisnull; 				/*抄到时间判空标志*/
}str_AFN0C_F139;


typedef struct str_AFN0C_SYDL_t
{
    datetime date;                  /*时间*/
    short    dateisnull;            /*时间判空标志*/
    uchar    count;                 /*数据体个数*/
    unsigned short meterindex[255]; /*电表序号*/
    uchar  flag[255];               /*数据项标志*/
    double val[255];                /*剩余电量*/
    short  valisnull[255];          /*剩余电量判空标志*/
    datetime cdsj[255];             /*抄到时间*/
    short    cdsjisnull[255];       /*抄到时间判空标志*/
}str_AFN0C_SYDL;

typedef struct str_vip_point_t
{
    double val[23];   /*24点剩余电量*/
    short valisnull[23]; /*24点剩余电量判空标志*/
}str_vip_point;

typedef struct str_AFN0C_VIP_SYDL_t
{
    datetime date;          /* 时间 */
    short    dateisnull;    /* 时间判空标志 */
    uchar    count;         /* 数据体个数 */
    unsigned short meterindex[255]; /*电表序号*/
    uchar  flag[255];               /*数据项标志, 强行为 0x01*/
    str_vip_point data[255];
}str_AFN0C_VIP_SYDL;

//F129F131F137F139F153F154F155F156F157F158F159F160
int decode_afn0C_NSZ14(uchar *as_data, str_AFN0C_LowVal *astr_val, int *ai_step);

//F130F132F133F134F135F136F138F140F141F142F143F144
int decode_afn0C_NSZ11(uchar *as_data, str_AFN0C_LowVal *astr_val, int *ai_step);


int decode_afn0C_F139(uchar *as_data, str_AFN0C_F139 *astr_val, int *ai_step);

int decode_afn0C_SYDL(uchar *as_data, str_AFN0C_SYDL *astr_val, int *ai_step);

int decode_afn0C_VIP_SYDL(uchar *as_data, str_AFN0C_VIP_SYDL *astr_val, int *ai_step);

#endif // DECODE_AFN0CG16_H_INCLUDED
