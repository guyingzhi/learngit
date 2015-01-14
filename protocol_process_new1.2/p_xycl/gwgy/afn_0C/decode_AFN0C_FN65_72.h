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
   uchar ddkz;        /*���ؿ���*/
   uchar yfkz;        /*Զ������*/
   uchar yjbs;        /*Ӳ������*/
   uchar rjbs;        /*�������*/
   uchar gybs;        /*��ѹ����*/
   uchar sbgzbs;      /*�豸���ϱ���*/
   uchar zxhlgzbs;    /*ִ�л�·���ϱ���*/
   uchar drstate[16]; /*����Ͷ��״̬ 1 Ͷ�� 0 �г�*/
}str_AFN0C_FN65;

typedef struct str_AFN0C_F66_t
{
   uint sec[16];     /*Ͷ������*/
   uint times[16];   /*Ͷ�����*/
   short secisnull[16];   /*�пձ�־*/
   short timesisnull[16];
}str_AFN0C_FN66;


typedef struct str_AFN0C_F67_t
{
   double val1;       /*��ǰ�ղ������޹�������*/
   double val2;       /*��ǰ�²������޹�������*/
   short val1isnull;
   short val2isnull;
}str_AFN0C_FN67;


int decode_afn0C_F65(uchar *as_data, str_AFN0C_FN65 *astr_val, int *ai_step);
int decode_afn0C_F66(uchar *as_data, str_AFN0C_FN66 *astr_val, int *ai_step);
int decode_afn0C_F67(uchar *as_data, str_AFN0C_FN67 *astr_val, int *ai_step);

#endif 
