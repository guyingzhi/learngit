#ifndef DECODE_AFN0C_F169_178_H_INCLUDED
#define DECODE_AFN0C_F169_178_H_INCLUDED

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
typedef struct str_router_2012_t
{
	uchar		level;				/* 中继路由级数 1~255*/
	str_add12	addr[256];			/* 中继路由的第n级中继地址 */
	short       addrisnull[256];    /*地址为空标志*/
}str_router;

typedef struct str_AFN0C_F169_t
{
	uchar		port;               /* 所属终端通信端口号 */
	uchar		n;					/* 中继路由个数n */
	str_router  router[256];		/* 中继路由 */
}str_AFN0C_F169;

typedef struct str_AFN0C_F170_t
{
    uchar		port;               /* 所属终端通信端口号 */
    uchar		n;					/* 中继路由个数n */
    uchar       cbxw[3];            /* 抄表相位C相、B相、A相 */
    uchar       sjxw[3];            /* 电表实际相位C相、B相、A相 */
    uchar		fspz;					/* 电表发送载波信号品质 ，数值范围1～15*/
    uchar		jspz;					/* 电表接收载波信号品质，数值范围1～15 */
    uchar		cbflag;					/* 最近一次抄表成功/失败标志 */
    datetime    cgtime;                  /*最近一次抄表成功时间*/
    short       cgtimeisnull;
    datetime    sbtime;                  /*最近一次抄表失败时间*/
    short       sbtimeisnull;
    uchar		sbljcs;					/* 最近连续失败累计次数*/
}str_AFN0C_F170;
typedef struct str_AFN0C_F177F178_t
{
	datetime  date;                           /*终端抄表时间*/
	short dateisnull;
	short FLS;                                    /*费率数*/
	short  FLSisnull;				/*判空*/
	double val[15];				/*电能示值*/
	double valisnull[15];
}str_AFN0C_F177F178;

int decode_afn0C_F169(uchar *as_data, str_AFN0C_F169 *astr_val, int *ai_step);
int decode_afn0C_F170(uchar *as_data, str_AFN0C_F170 *astr_val, int *ai_step);
int decode_afn0C_F177(uchar *as_data, str_AFN0C_F177F178 *astr_val, int *ai_step);

#endif
