#ifndef DECODE_AFN0D_FN153_160_H
#define DECODE_AFN0D_FN153_160_H

#include "../public/decode_public.h"

typedef struct str_AFN0D_Activeenergy_t
{
	datetime TD;		/* 数据时标*/
	short TDisnull;
	datetime CB;			/* 抄表时间*/
	short  CBisnull;
	double Aval;				/* 有功电能示值*/
	short Avalisnull;
	double Bval;					/* B有功电能示值*/
	short Bvalisnull;
	double Cval;						/* C有功电能示值*/
	short  Cvalisnull;
}str_AFN0D_Activeenergy;

typedef struct str_AFN0D_idleenergy_t
{
	datetime TD;/* 数据时标*/
	short TDisnull;
	datetime CB;		/* 抄表时间*/
	short  CBisnull;
	double Aidle;			/* 无功电能示值*/
	short Aidleisnull;
	double Bidle;				/* B无功电能示值*/
	short Bidleisnull;
	double Cidle;					/* C无功电能市值*/
	short  Cidleisnull;
}str_AFN0D_idleenergy;

/*综合F154F156F158F160数据*/
int decode_AFN0D_Activeenergy(uchar *as_data, str_AFN0D_Activeenergy*astr_val, int *ai_step,int frozen_type);
int decode_AFN0D_Idleenergy(uchar *as_data, str_AFN0D_idleenergy*astr_val, int *ai_step,int frozen_type);	
#endif
