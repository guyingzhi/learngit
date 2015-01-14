#ifndef DECODE_AFN0CF121_H_INCLUDED
#define DECODE_AFN0CF121_H_INCLUDED

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

/*直流模拟量冻结值*/
int decode_afn0C_F121(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);

#endif 
