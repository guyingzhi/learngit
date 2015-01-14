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
    datetime	date;               /* ����ʱ�� */
    short		dateisnull;         /* ����ʱ���пձ�־ */
    uchar		state;   				/*���ܱ�ͨ�ϵ�״̬*/
    datetime	tddt;				/* ���һ�κ�բ����ʱ�� */
    short		tddtisnull;		/*ʱ���пձ�־ */
    datetime	dddt;				/*�����������ʱ�� */
    short		dddtisnull;		/*���һ����բ����ʱ�� */
}str_AFN0C_F161;
typedef struct str_AFN0C_F162_t
{
	datetime date;			/*�ն˳���ʱ��*/
	datetime date1;		/*���ܱ�����ʱ��*/
	short dateisnull;      /*�п�*/
}str_AFN0C_F162;
typedef struct str_AFN0C_F165F166_t
{
    datetime	date;               /* ����ʱ�� */
    short		dateisnull;         /* ����ʱ���пձ�־ */
    int         bcczcs;         /*��̿��ز�������*/
    short         bcczcsisnull;         /*��̿��ز�������*/
    datetime	bcczdt;				/* ���һ�α�̿��ز���ʱ�� */
    short		bccztisnull;		/*ʱ���пձ�־ */
    datetime	bcczdt2;				/* Уʱ��ʱ��F166ר�� */
    short		bccztisnull2;		/*ʱ���пձ�־ */
    int         wgdkcs;         /*���ܱ�β�Ǵ򿪴���*/
    short         wgdkcsisnull;         /*���ܱ�β�Ǵ򿪴���*/
    datetime	wgdkdt;				/*���һ��β�Ǵ�ʱ�� */
    short		wgdkdtisnull;		/*���һ�ε��ܱ�Զ�̿��ƶϵ�ʱ�� */
}str_AFN0C_F165F166;

typedef struct str_AFN0C_F167_t
{
    datetime	date;               /* ����ʱ�� */
    short		dateisnull;         /* ����ʱ���пձ�־ */
    int         gdcs;               /*�������*/
    short       gdcsisnull;         /*��������пձ�־*/
    double      gdje;               /*ʣ����*/
    short       gdjeisnull;         /*ʣ�����пձ�־*/
    double      ljgdje;               /*�ۼƹ�����*/
    short       ljgdjeisnull;         /*�ۼƹ������пձ�־*/
    double      sydl;               /*ʣ�����*/
    short       sydlisnull;         /*ʣ������пձ�־*/
    double      tzdl;               /*͸֧����*/
    short       tzdlisnull;         /*͸֧�����пձ�־*/
    double      ljgdl;               /*�ۼƹ�����*/
    short       ljgdlisnull;         /*�ۼƹ������пձ�־*/
    double      sqmxdl;               /*��Ƿ���޵���*/
    short       sqmxdlisnull;         /*��Ƿ���޵����пձ�־*/
    double      bjdl;               /*��������*/
    short       bjdlisnull;         /*���������пձ�־*/
    double      gzdl;               /*���ϵ���*/
    short       gzdlisnull;         /*���ϵ����пձ�־*/
}str_AFN0C_F167;

typedef struct str_AFN0C_F168_t
{
    datetime	date;               /* ����ʱ�� */
    short		dateisnull;         /* ����ʱ���пձ�־ */
    short		FLS;   				/* ������ 1��14*/
    short		FLSisnull;         /* ����ʱ���пձ�־ */
    double 		yjval[15];            /* �ѽ��й�����*/
    short		yjvalisnull[15];		/* �пձ�־ */
    double 		wjval[15];            /* δ���й�����*/
    short		wjvalisnull[15];		/* �пձ�־ */
}str_AFN0C_F168;


int decode_afn0C_F161(uchar *as_data, str_AFN0C_F161 *astr_val, int *ai_step);
int decode_afn0C_F165(uchar *as_data, str_AFN0C_F165F166 *astr_val, int *ai_step);
int decode_afn0C_F166(uchar *as_data, str_AFN0C_F165F166 *astr_val, int *ai_step);
int decode_afn0C_F167(uchar *as_data, str_AFN0C_F167 *astr_val, int *ai_step);
int decode_afn0C_F168(uchar *as_data, str_AFN0C_F168 *astr_val, int *ai_step);

#endif
