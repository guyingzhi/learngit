#ifndef DECODE_AFN0D_FN1_12_H
#define DECODE_AFN0D_FN1_12_H

#include "../public/decode_public.h"
#include "decode_AFN0D_public.h"


/*typedef struct
{
    datetime TD;            /*ʱ��*/
/*    datetime CBSJ;          /*����ʱ��*/
/*    short FLS;              /*������*/
/*    double Pcode[15];       /*�й�����*/
/*    double Qcode[15];       /*�޹�����*/
/*    double Q12code[15];     /*1��2�����޹�����*/
/*    double Q34code[15];     /*3��4�����޹�����*/
/*}str_AFN0D_CODE_VAL;

typedef struct
{
    short TD;             /*ʱ��Ϊ�ձ�־*/
 /*   short CBSJ;           /*����ʱ��Ϊ�ձ�־*/
 /*   short Pcode[15];      /*�й�����Ϊ�ձ�־*/
 /*   short Qcode[15];      /*�޹�����Ϊ�ձ�־*/
/*    short Q12code[15];    /*1��2�����޹�����Ϊ�ձ�־*/
/*    short Q34code[15];    /*3��4�����޹�����Ϊ�ձ�־*/
/*}str_AFN0D_CODE_ISNULL;

typedef struct
{
    str_AFN0D_CODE_VAL val;
    str_AFN0D_CODE_ISNULL isnull;
}str_AFN0D_CODE;

typedef struct
{
    datetime TD;            /*ʱ��*/
/*    datetime CBSJ;          /*����ʱ��*/
/*    short FLS;              /*������*/
/*    double PXL[15];         /*�й�����*/
/*    datetime PXLSJ[15];     /*�й���������ʱ��*/
/*    double QXL[15];         /*�޹�����*/
/*    datetime QXLSJ[15];     /*�޹���������ʱ��*/
/*}str_AFN0D_XL_VAL;

typedef struct
{
    short TD;            /*ʱ��*/
/*    short CBSJ;          /*����ʱ��*/
 /*   short PXL[15];         /*�й�����*/
/*    short PXLSJ[15];     /*�й���������ʱ��*/
/*    short QXL[15];         /*�޹�����*/
/*    short QXLSJ[15];     /*�޹���������ʱ��*/
/*}str_AFN0D_XL_ISNULL;

typedef struct
{
    str_AFN0D_XL_VAL val;
    str_AFN0D_XL_ISNULL isnull;
}str_AFN0D_XL;
*/




int de_AFN0D_FN1_2_9_10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);




#endif
