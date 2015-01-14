#ifndef DECODE_AFN0D_FN113_120_H
#define DECODE_AFN0D_FN113_120_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F113_118_t
{
	datetime TD;			/*����ʱ��������*/
	short TDisnull;
	double Imax[19];			/*���������ֵ*/
	short Imaxisnull[19];
	double Umax[19];			/*��ѹ�����ֵ*/
	short Umaxisnull[19];
	datetime xptime[19];				/*������ʱ��*/
	short xptimeisnull[19];
	double IALL;							/*�ܻ���������ֵ*/
	short IALLisnull;
	double UALL;							/*�ܻ����ѹ���ֵ*/
	short UALLisnull;	
	datetime IALLtime;								/*�����������ʱ��*/
	short IALLtimeisnull;
	
	datetime UALLtime;								/*�����������ʱ��*/
	short UALLtimeisnull;
}str_AFN0D_F113_118;
#endif 


int decode_AFN0D_F116_118(uchar *as_data, str_AFN0D_F113_118*astr_val, int *ai_step);
int decode_AFN0D_F113_115(uchar *as_data, str_AFN0D_F113_118*astr_val, int *ai_step);