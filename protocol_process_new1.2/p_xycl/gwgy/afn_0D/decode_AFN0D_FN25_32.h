#ifndef DECODE_AFN0D_FN25_32_H
#define DECODE_AFN0D_FN25_32_H


#include "../public/decode_public.h"
#include "decode_AFN0D_public.h"


typedef struct str_AFN0D_31_t
{
   datetime DT;
   short DTisnull;
   double MAX_load;                /*负载率最大值*/
   short MAX_loadisnull;
   datetime MAX_load_T;
   short MAX_load_Tisnull;
   double MIN_load;                /*负载率最小值*/
   short MIN_loadisnull;
   datetime MIN_load_T;
   short MIN_load_Tisnull;
}str_AFN0D_31;

int decode_afn0D_F25_str(uchar *data, str_AFN0D_MAXP *astr_val, int *ai_step);
int decode_afn0D_F26_str(uchar *data, str_AFN0D_MAXXL *astr_val, int *ai_step);
int decode_afn0D_F27_str(uchar *data, str_AFN0D_STU *astr_val, int *ai_step);
int decode_afn0D_F28_str(uchar *data, str_AFN0D_UNBALANCE *astr_val, int *ai_step);
int decode_afn0D_F29_str(uchar *data, str_AFN0D_STI *astr_val, int *ai_step);
int decode_afn0D_F30_str(uchar *data, str_AFN0D_APP *astr_val, int *ai_step);
int decode_afn0D_F31_str(uchar *data, str_AFN0D_31 *astr_val, int *ai_step);
int decode_afn0D_F32_str(uchar *data, str_AFN0D_BREAK *astr_val, int *ai_step);

int de_AFN0D_FN25(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN26(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN27(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN28(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN29(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN30(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN31(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN32(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

#endif
