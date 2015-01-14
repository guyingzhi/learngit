#ifndef DECODE_AFN0D_FN1_12_H
#define DECODE_AFN0D_FN1_12_H

#include "../public/decode_public.h"
#include "decode_AFN0D_public.h"


/*typedef struct
{
    datetime TD;            /*时标*/
/*    datetime CBSJ;          /*抄表时间*/
/*    short FLS;              /*费率数*/
/*    double Pcode[15];       /*有功读数*/
/*    double Qcode[15];       /*无功读数*/
/*    double Q12code[15];     /*1或2象限无功读数*/
/*    double Q34code[15];     /*3或4象限无功读数*/
/*}str_AFN0D_CODE_VAL;

typedef struct
{
    short TD;             /*时标为空标志*/
 /*   short CBSJ;           /*抄表时间为空标志*/
 /*   short Pcode[15];      /*有功读数为空标志*/
 /*   short Qcode[15];      /*无功读数为空标志*/
/*    short Q12code[15];    /*1或2象限无功读数为空标志*/
/*    short Q34code[15];    /*3或4象限无功读数为空标志*/
/*}str_AFN0D_CODE_ISNULL;

typedef struct
{
    str_AFN0D_CODE_VAL val;
    str_AFN0D_CODE_ISNULL isnull;
}str_AFN0D_CODE;

typedef struct
{
    datetime TD;            /*时标*/
/*    datetime CBSJ;          /*抄表时间*/
/*    short FLS;              /*费率数*/
/*    double PXL[15];         /*有功需量*/
/*    datetime PXLSJ[15];     /*有功需量发生时间*/
/*    double QXL[15];         /*无功需量*/
/*    datetime QXLSJ[15];     /*无功需量发生时间*/
/*}str_AFN0D_XL_VAL;

typedef struct
{
    short TD;            /*时标*/
/*    short CBSJ;          /*抄表时间*/
 /*   short PXL[15];         /*有功需量*/
/*    short PXLSJ[15];     /*有功需量发生时间*/
/*    short QXL[15];         /*无功需量*/
/*    short QXLSJ[15];     /*无功需量发生时间*/
/*}str_AFN0D_XL_ISNULL;

typedef struct
{
    str_AFN0D_XL_VAL val;
    str_AFN0D_XL_ISNULL isnull;
}str_AFN0D_XL;
*/




int de_AFN0D_FN1_2_9_10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);




#endif
