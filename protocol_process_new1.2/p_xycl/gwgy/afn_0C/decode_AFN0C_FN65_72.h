#ifndef DECODE_AFN0CF65_72__H_INCLUDED
#define DECODE_AFN0CF65_72__H_INCLUDED

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
typedef struct str_AFN0C_F65_t
{
   uchar ddkz;        /*当地控制*/
   uchar yfkz;        /*远方控制*/
   uchar yjbs;        /*硬件闭锁*/
   uchar rjbs;        /*软件闭锁*/
   uchar gybs;        /*过压闭锁*/
   uchar sbgzbs;      /*设备故障闭锁*/
   uchar zxhlgzbs;    /*执行回路故障闭锁*/
   uchar drstate[16]; /*电容投切状态 1 投入 0 切除*/
}str_AFN0C_FN65;

typedef struct str_AFN0C_F66_t
{
   uint sec[16];     /*投入秒数*/
   uint times[16];   /*投入次数*/
   short secisnull[16];   /*判空标志*/
   short timesisnull[16];
}str_AFN0C_FN66;


typedef struct str_AFN0C_F67_t
{
   double val1;       /*当前日补偿的无功电能量*/
   double val2;       /*当前月补偿的无功电能量*/
   short val1isnull;
   short val2isnull;
}str_AFN0C_FN67;


int decode_afn0C_F65(uchar *as_data, str_AFN0C_FN65 *astr_val, int *ai_step);
int decode_afn0C_F66(uchar *as_data, str_AFN0C_FN66 *astr_val, int *ai_step);
int decode_afn0C_F67(uchar *as_data, str_AFN0C_FN67 *astr_val, int *ai_step);

#endif 
