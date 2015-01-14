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
	uchar		level;				/* �м�·�ɼ��� 1~255*/
	str_add12	addr[256];			/* �м�·�ɵĵ�n���м̵�ַ */
	short       addrisnull[256];    /*��ַΪ�ձ�־*/
}str_router;

typedef struct str_AFN0C_F169_t
{
	uchar		port;               /* �����ն�ͨ�Ŷ˿ں� */
	uchar		n;					/* �м�·�ɸ���n */
	str_router  router[256];		/* �м�·�� */
}str_AFN0C_F169;

typedef struct str_AFN0C_F170_t
{
    uchar		port;               /* �����ն�ͨ�Ŷ˿ں� */
    uchar		n;					/* �м�·�ɸ���n */
    uchar       cbxw[3];            /* ������λC�ࡢB�ࡢA�� */
    uchar       sjxw[3];            /* ���ʵ����λC�ࡢB�ࡢA�� */
    uchar		fspz;					/* ������ز��ź�Ʒ�� ����ֵ��Χ1��15*/
    uchar		jspz;					/* �������ز��ź�Ʒ�ʣ���ֵ��Χ1��15 */
    uchar		cbflag;					/* ���һ�γ���ɹ�/ʧ�ܱ�־ */
    datetime    cgtime;                  /*���һ�γ���ɹ�ʱ��*/
    short       cgtimeisnull;
    datetime    sbtime;                  /*���һ�γ���ʧ��ʱ��*/
    short       sbtimeisnull;
    uchar		sbljcs;					/* �������ʧ���ۼƴ���*/
}str_AFN0C_F170;
typedef struct str_AFN0C_F177F178_t
{
	datetime  date;                           /*�ն˳���ʱ��*/
	short dateisnull;
	short FLS;                                    /*������*/
	short  FLSisnull;				/*�п�*/
	double val[15];				/*����ʾֵ*/
	double valisnull[15];
}str_AFN0C_F177F178;

int decode_afn0C_F169(uchar *as_data, str_AFN0C_F169 *astr_val, int *ai_step);
int decode_afn0C_F170(uchar *as_data, str_AFN0C_F170 *astr_val, int *ai_step);
int decode_afn0C_F177(uchar *as_data, str_AFN0C_F177F178 *astr_val, int *ai_step);

#endif
