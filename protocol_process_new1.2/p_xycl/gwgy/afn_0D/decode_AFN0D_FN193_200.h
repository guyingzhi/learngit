#ifndef DECODE_AFN0D_FN193_200_H
#define DECODE_AFN0D_FN193_200_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F193_F200_t
{
	datetime TD;			/*月数据类时标*/
	short TDisnull;
	datetime CB;			/*抄表时间*/
	short CBisnull;
	uint val;				/*费率数*/
	double val1;				/*正向有功总最大需量*/
	short val1isnull;
	datetime zxygtime;			/*正向有功总最大需量发生时间*/
	short zxygtimeisnull;
	double val2[14];				/*费率正向有功最大需量*/
	short val2isnull[14];
	datetime val2time[14];				/*费率正向有功最大需量发生时间*/
	short val2timeisnull[14];
}str_AFN0D_F193_F200;

int decode_afn0D_F193_F200(uchar *as_data, str_AFN0D_F193_F200*astr_val, int *ai_step,int frozen_type);
#endif