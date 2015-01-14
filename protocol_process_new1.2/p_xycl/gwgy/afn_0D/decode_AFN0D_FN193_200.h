#ifndef DECODE_AFN0D_FN193_200_H
#define DECODE_AFN0D_FN193_200_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F193_F200_t
{
	datetime TD;			/*��������ʱ��*/
	short TDisnull;
	datetime CB;			/*����ʱ��*/
	short CBisnull;
	uint val;				/*������*/
	double val1;				/*�����й����������*/
	short val1isnull;
	datetime zxygtime;			/*�����й��������������ʱ��*/
	short zxygtimeisnull;
	double val2[14];				/*���������й��������*/
	short val2isnull[14];
	datetime val2time[14];				/*���������й������������ʱ��*/
	short val2timeisnull[14];
}str_AFN0D_F193_F200;

int decode_afn0D_F193_F200(uchar *as_data, str_AFN0D_F193_F200*astr_val, int *ai_step,int frozen_type);
#endif