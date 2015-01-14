#ifndef DECODE_AFN0CF105_F112_H_INCLUDED
#define DECODE_AFN0CF105_F112_H_INCLUDED


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
#include "../public/public.h"
/*有功无功电能量*/
int decode_afn0C_F105_F108(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);
/*电能示值*/
int decode_afn0C_F109_F112(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);

#endif 
