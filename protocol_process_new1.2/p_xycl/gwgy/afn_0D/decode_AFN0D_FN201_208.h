#ifndef DECODE_AFN0D_FN201_208_H
#define DECODE_AFN0D_FN201_208_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F201F208_t
{
	datetime  TD;		/*数据时标*/
	short  TDisnull;	
	datetime CB;		/*抄表时间*/
	short CBisnull;
	uint val;			/*费率数*/
	double val1;		/*正向有功总电能市值*/
	short val1isnull;
	double zxyg[14];		/*费率1~m 电能示值*/
	short zxygisnull[14];
}str_AFN0D_F201F208;

int decode_afn0D_F201F208(uchar *as_data, str_AFN0D_F201F208*astr_val, int *ai_step);
#endif
