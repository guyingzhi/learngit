#ifndef DECODE_AFN0CF49_56__H_INCLUDED
#define DECODE_AFN0CF49_56__H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#ifdef _WIN32
#include "..\decode_public.h"
#else
#include "../public/public.h"
#endif
#include "../public/decode_public.h"

typedef struct str_AFN0C_F49_t
{
   double Ua, Ub, Uc;  		 		 /*�����ѹ��λ��*/
   double Ia, Ib, Ic;  				  /*���������λ��*/
   short Uaisnull, Ubisnull, Ucisnull;   /*�пձ�־λ*/
   short Iaisnull, Ibisnull, Icisnull;
}str_AFN0C_FN49;


int decode_afn0C_F49(uchar *as_data, str_AFN0C_FN49 *astr_val, int *ai_step);

#endif 
