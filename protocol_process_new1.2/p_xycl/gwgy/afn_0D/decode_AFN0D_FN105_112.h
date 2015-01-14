#ifndef DECODE_AFN0D_FN105_112_H
#define DECODE_AFN0D_FN105_112_H


#include "../public/decode_public.h"
typedef struct str_AFN0D_F109_t
{
    int val_num;
    double val[255][3];
    short isnull[255][3];
    datetime val_time[255];
}str_AFN0D_F109;

typedef struct str_AFN0D_F110_t
{
    int val_num;                                                                                      
    double val[255][3];
    short isnull[255][3];
    datetime val_time[255];
}str_AFN0D_F110;
int decode_AFN0D_COSQX(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step);
int decode_AFN0D_F109(uchar *as_data, str_AFN0D_F109 *astr_val, int *ai_step);
int decode_AFN0D_F110(uchar *as_data, str_AFN0D_F110 *astr_val, int *ai_step);
int de_AFN0D_COSQX(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F109(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F110(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);


#endif