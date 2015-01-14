#ifndef DECODE_AFN0D_FN17_24_H
#define DECODE_AFN0D_FN17_24_H


#include "../public/decode_public.h"
#include "decode_AFN0D_public.h"

int decode_afn0D_CODE_M(uchar *data, str_AFN0D_CODE *astr_val, int *ai_step);
int decode_afn0D_XL_M(uchar *data, str_AFN0D_XL *astr_val, int *ai_step);
int decode_afn0D_POWER_M(uchar *data, str_AFN0D_POWER *astr_val, int *ai_step);
int de_AFN0D_FN17_18(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN19_20(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN21_22_23_24(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
	

#endif
