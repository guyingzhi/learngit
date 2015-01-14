#ifndef DECODE_AFN0D_FN33_39_H
#define DECODE_AFN0D_FN33_39_H


#include "../public/decode_public.h"
#include "decode_AFN0D_public.h"

typedef struct str_AFN0D_39_t
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
}str_AFN0D_39;

int decode_afn0D_F33_str(uchar *data, str_AFN0D_MAXP *astr_val, int *ai_step);

int de_AFN0D_FN33(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN34(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN35(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN36(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN37(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN38(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int decode_afn0D_F34_str(uchar *data, str_AFN0D_MAXXL *astr_val, int *ai_step);
int decode_afn0D_F35_str(uchar *data, str_AFN0D_STU *astr_val, int *ai_step);
int decode_afn0D_F36_str(uchar *data, str_AFN0D_UNBALANCE *astr_val, int *ai_step);
int decode_afn0D_F37_str(uchar *data, str_AFN0D_STI *astr_val, int *ai_step);
int decode_afn0D_F38_str(uchar *data, str_AFN0D_APP *astr_val, int *ai_step);


#endif
