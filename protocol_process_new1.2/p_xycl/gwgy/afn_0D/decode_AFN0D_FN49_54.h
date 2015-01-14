#ifndef DECODE_AFN0D_FN49_54_H
#define DECODE_AFN0D_FN49_54_H


#include "../public/decode_public.h"

typedef struct str_AFN0D_ONPOWER_VAL_t
{
    datetime TD;        /*ʱ��*/
    unsigned short onpowertime;  /*����ʱ��*/
    unsigned short resettime;    /*��λ����*/
}str_AFN0D_ONPOWER_VAL;

typedef struct str_AFN0D_ONPOWER_ISNULL_t
{
    short TD;           /*ʱ���пձ�־*/
 /*   short onpowertime;  /*����ʱ���пձ�־*/
 /*   short resettime;    /*��λ�����пձ�־*/
}str_AFN0D_ONPOWER_ISNULL;

typedef struct str_AFN0D_ONPOWER_t
{
    str_AFN0D_ONPOWER_VAL val;
    str_AFN0D_ONPOWER_ISNULL isnull;
}str_AFN0D_ONPOWER;

typedef struct str_AFN0D_CONTROL_t
{
    datetime TD;        /*ʱ��*/
    short TDisnull;     /*ʱ���пձ�־*/
    short times[4];     /*��բ��������*/
}str_AFN0D_CONTROL;

typedef struct str_AFN0D_F53F54_t
{
    datetime TD;        /*ʱ��*/
    short TDisnull;     /*ʱ���пձ�־*/
    uint  datacount;     /*ͨ������*/
    short datacountisnull;
}str_AFN0D_F53F54;

int decode_afn0D_F49_str(uchar *data, str_AFN0D_ONPOWER *astr_val, int *ai_step);
int decode_afn0D_F50_str(uchar *data, str_AFN0D_CONTROL *astr_val, int *ai_step);
int decode_afn0D_F51_str(uchar *data, str_AFN0D_ONPOWER *astr_val, int *ai_step);
int decode_afn0D_F52_str(uchar *data, str_AFN0D_CONTROL *astr_val, int *ai_step);
int decode_afn0D_F53_str(uchar *data, str_AFN0D_F53F54 *astr_val, int *ai_step);
int decode_afn0D_F54_str(uchar *data, str_AFN0D_F53F54 *astr_val, int *ai_step);
int de_AFN0D_FN49(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN50(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN51(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN52(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN53(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN54(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
#endif

