#ifndef DECODE_AFN0D_FN153_160_H
#define DECODE_AFN0D_FN153_160_H

#include "../public/decode_public.h"

typedef struct str_AFN0D_Activeenergy_t
{
	datetime TD;		/* ����ʱ��*/
	short TDisnull;
	datetime CB;			/* ����ʱ��*/
	short  CBisnull;
	double Aval;				/* �й�����ʾֵ*/
	short Avalisnull;
	double Bval;					/* B�й�����ʾֵ*/
	short Bvalisnull;
	double Cval;						/* C�й�����ʾֵ*/
	short  Cvalisnull;
}str_AFN0D_Activeenergy;

typedef struct str_AFN0D_idleenergy_t
{
	datetime TD;/* ����ʱ��*/
	short TDisnull;
	datetime CB;		/* ����ʱ��*/
	short  CBisnull;
	double Aidle;			/* �޹�����ʾֵ*/
	short Aidleisnull;
	double Bidle;				/* B�޹�����ʾֵ*/
	short Bidleisnull;
	double Cidle;					/* C�޹�������ֵ*/
	short  Cidleisnull;
}str_AFN0D_idleenergy;

/*�ۺ�F154F156F158F160����*/
int decode_AFN0D_Activeenergy(uchar *as_data, str_AFN0D_Activeenergy*astr_val, int *ai_step,int frozen_type);
int decode_AFN0D_Idleenergy(uchar *as_data, str_AFN0D_idleenergy*astr_val, int *ai_step,int frozen_type);	
#endif
