#ifndef DECODE_AFN0D_FN201_208_H
#define DECODE_AFN0D_FN201_208_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F201F208_t
{
	datetime  TD;		/*����ʱ��*/
	short  TDisnull;	
	datetime CB;		/*����ʱ��*/
	short CBisnull;
	uint val;			/*������*/
	double val1;		/*�����й��ܵ�����ֵ*/
	short val1isnull;
	double zxyg[14];		/*����1~m ����ʾֵ*/
	short zxygisnull[14];
}str_AFN0D_F201F208;

int decode_afn0D_F201F208(uchar *as_data, str_AFN0D_F201F208*astr_val, int *ai_step);
#endif
