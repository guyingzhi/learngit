#ifndef DECODE_AFN0CF161_168_H_INCLUDED
#define DECODE_AFN0CF161_168_H_INCLUDED

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
#include"../public/public.h"
typedef struct str_AFN0C_F161_t
{
    datetime	date;               /* 抄表时间 */
    short		dateisnull;         /* 抄表时间判空标志 */
    uchar		state;   				/*电能表通断电状态*/
    datetime	tddt;				/* 最近一次合闸发生时间 */
    short		tddtisnull;		/*时间判空标志 */
    datetime	dddt;				/*最大需量发生时间 */
    short		dddtisnull;		/*最近一次跳闸发生时间 */
}str_AFN0C_F161;
typedef struct str_AFN0C_F162_t
{
	datetime date;			/*终端抄表时间*/
	datetime date1;		/*电能表日历时钟*/
	short dateisnull;      /*判空*/
}str_AFN0C_F162;
typedef struct str_AFN0C_F165F166_t
{
    datetime	date;               /* 抄表时间 */
    short		dateisnull;         /* 抄表时间判空标志 */
    int         bcczcs;         /*编程开关操作次数*/
    short         bcczcsisnull;         /*编程开关操作次数*/
    datetime	bcczdt;				/* 最近一次编程开关操作时间 */
    short		bccztisnull;		/*时间判空标志 */
    datetime	bcczdt2;				/* 校时后时间F166专用 */
    short		bccztisnull2;		/*时间判空标志 */
    int         wgdkcs;         /*电能表尾盖打开次数*/
    short         wgdkcsisnull;         /*电能表尾盖打开次数*/
    datetime	wgdkdt;				/*最近一次尾盖打开时间 */
    short		wgdkdtisnull;		/*最近一次电能表远程控制断电时间 */
}str_AFN0C_F165F166;

typedef struct str_AFN0C_F167_t
{
    datetime	date;               /* 抄表时间 */
    short		dateisnull;         /* 抄表时间判空标志 */
    int         gdcs;               /*购电次数*/
    short       gdcsisnull;         /*购电次数判空标志*/
    double      gdje;               /*剩余金额*/
    short       gdjeisnull;         /*剩余金额判空标志*/
    double      ljgdje;               /*累计购电金额*/
    short       ljgdjeisnull;         /*累计购电金额判空标志*/
    double      sydl;               /*剩余电量*/
    short       sydlisnull;         /*剩余电量判空标志*/
    double      tzdl;               /*透支电量*/
    short       tzdlisnull;         /*透支电量判空标志*/
    double      ljgdl;               /*累计购电量*/
    short       ljgdlisnull;         /*累计购电量判空标志*/
    double      sqmxdl;               /*赊欠门限电量*/
    short       sqmxdlisnull;         /*赊欠门限电量判空标志*/
    double      bjdl;               /*报警电量*/
    short       bjdlisnull;         /*报警电量判空标志*/
    double      gzdl;               /*故障电量*/
    short       gzdlisnull;         /*故障电量判空标志*/
}str_AFN0C_F167;

typedef struct str_AFN0C_F168_t
{
    datetime	date;               /* 抄表时间 */
    short		dateisnull;         /* 抄表时间判空标志 */
    short		FLS;   				/* 费率数 1～14*/
    short		FLSisnull;         /* 抄表时间判空标志 */
    double 		yjval[15];            /* 已结有功电能*/
    short		yjvalisnull[15];		/* 判空标志 */
    double 		wjval[15];            /* 未结有功电能*/
    short		wjvalisnull[15];		/* 判空标志 */
}str_AFN0C_F168;


int decode_afn0C_F161(uchar *as_data, str_AFN0C_F161 *astr_val, int *ai_step);
int decode_afn0C_F165(uchar *as_data, str_AFN0C_F165F166 *astr_val, int *ai_step);
int decode_afn0C_F166(uchar *as_data, str_AFN0C_F165F166 *astr_val, int *ai_step);
int decode_afn0C_F167(uchar *as_data, str_AFN0C_F167 *astr_val, int *ai_step);
int decode_afn0C_F168(uchar *as_data, str_AFN0C_F168 *astr_val, int *ai_step);

#endif
