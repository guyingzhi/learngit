#ifndef DECODE_AFN0CF73_80_H_INCLUDED
#define DECODE_AFN0CF73_80_H_INCLUDED

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
typedef struct str_AFN0C_F73_t
{
    double val;
    short valisnull;
}str_AFN0C_FN73;


int decode_afn0C_F73(uchar *as_data, str_AFN0C_FN73 *astr_val, int *ai_step);

#endif 
