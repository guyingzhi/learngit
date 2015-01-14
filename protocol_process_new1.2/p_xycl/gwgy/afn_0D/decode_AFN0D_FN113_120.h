#ifndef DECODE_AFN0D_FN113_120_H
#define DECODE_AFN0D_FN113_120_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F113_118_t
{
	datetime TD;			/*数据时标日月年*/
	short TDisnull;
	double Imax[19];			/*电流日最大值*/
	short Imaxisnull[19];
	double Umax[19];			/*电压日最大值*/
	short Umaxisnull[19];
	datetime xptime[19];				/*最大大发生时间*/
	short xptimeisnull[19];
	double IALL;							/*总畸变电流最大值*/
	short IALLisnull;
	double UALL;							/*总畸变电压最大值*/
	short UALLisnull;	
	datetime IALLtime;								/*畸变日最大发生时间*/
	short IALLtimeisnull;
	
	datetime UALLtime;								/*畸变日最大发生时间*/
	short UALLtimeisnull;
}str_AFN0D_F113_118;
#endif 


int decode_AFN0D_F116_118(uchar *as_data, str_AFN0D_F113_118*astr_val, int *ai_step);
int decode_AFN0D_F113_115(uchar *as_data, str_AFN0D_F113_118*astr_val, int *ai_step);