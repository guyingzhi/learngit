#ifndef DECODE_AFN0D_FN57_76_H
#define DECODE_AFN0D_FN57_76_H


#include "../public/decode_public.h"


typedef struct str_AFN0D_F57_t
{
    datetime TD;        /*ʱ��*/
    short TDisnull;     /*ʱ���пձ�־*/
    double YGGV_Max ; /*������й�����*/
    short YGGV_Maxisnull; 
    datetime YGGV_Max_T;      /*������й����ʷ���ʱ��*/
    short YGGV_Max_Tisnull;
    double YGGV_Min ;  /*����С�й�����*/
    short YGGV_Minisnull; 
    datetime YGGV_Min_T;        /*����С�й����ʷ���ʱ��*/
    short YGGV_Min_Tisnull;
    unsigned short YGGV_zero;  /*�й�����Ϊ���ۼ�ʱ��*/
}str_AFN0D_F57;


typedef struct str_AFN0D_F58F59_t
{
    datetime TD;        /*ʱ��*/
    short TDisnull;     /*ʱ���пձ�־*/
    uchar FLM;
    int DN_Total;/*���ۼ������޹�������*/
    short DN_Totalisnull;
    int DN[14];       
    short DNisnull[14];
}str_AFN0D_F58F59;

typedef struct str_AFN0D_F60_t
{
    datetime TD;        /*ʱ��*/
    short TDisnull;     /*ʱ���пձ�־*/
    double YGGV_Max ; /*������й�����*/
    short YGGV_Maxisnull; 
    datetime YGGV_Max_T;      /*������й����ʷ���ʱ��*/
    short YGGV_Max_Tisnull;
    double YGGV_Min ;  /*����С�й�����*/
    short YGGV_Minisnull; 
    datetime YGGV_Min_T;        /*����С�й����ʷ���ʱ��*/
    short YGGV_Min_Tisnull;
    unsigned short YGGV_zero;  /*���й�����Ϊ���ۼ�ʱ��*/
}str_AFN0D_F60;

typedef struct str_AFN0D_F61F62_t
{
    datetime TD;        /*ʱ��*/
    short TDisnull;     /*ʱ���пձ�־*/
    uchar FLM;
    int DN[15];       
    short DNisnull[15];
}str_AFN0D_F61F62;

typedef struct str_AFN0D_F65F66_t
{
    datetime TD;            /*ʱ��*/
    short TDisnull;          /*ʱ���пձ�־*/
    short Time_Total;
    short Time_Totalisnull;
    int DN_Total;     /*���ۼƵ�����*/
    short DN_Totalisnull;
}str_AFN0D_F65F66;

int decode_afn0D_F57_str(uchar *data, str_AFN0D_F57 *astr_val, int *ai_step);
int decode_afn0D_F58F59_str(uchar *data, str_AFN0D_F58F59 *astr_val, int *ai_step);
int decode_afn0D_F60_str(uchar *data, str_AFN0D_F60 *astr_val, int *ai_step);
int decode_afn0D_F61F62_str(uchar *data, str_AFN0D_F61F62 *astr_val, int *ai_step);
int decode_afn0D_F65F66_str(uchar *data, str_AFN0D_F65F66 *astr_val, int *ai_step);
int de_AFN0D_FN57(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN58F59(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_FN60(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN61F62(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_FN65F66(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);



#endif
