#ifndef DECODE_AFN0D_FN89_104_H
#define DECODE_AFN0D_FN89_104_H


#include "../public/decode_public.h"

int decode_AFN0D_UQX(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);
int decode_AFN0D_IQX(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);
int decode_AFN0D_POWERQX(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);
int decode_AFN0D_CODEQX(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);
int de_AFN0D_UQX(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_IQX(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_POWERQX(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_CODEQX(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

#endif
