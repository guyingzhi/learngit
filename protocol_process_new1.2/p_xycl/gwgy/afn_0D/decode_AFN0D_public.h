#ifndef DECODE_AFN0D_public_H
#define DECODE_AFN0D_public_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_CODE_VAL_t
{
    datetime TD;            /*时标*/
    datetime CBSJ;          /*抄表时间*/
    short FLS;              /*费率数*/
    double Pcode[15];       /*有功读数*/
    double Qcode[15];       /*无功读数*/
    double Q12code[15];     /*1或2象限无功读数*/
    double Q34code[15];     /*3或4象限无功读数*/
}str_AFN0D_CODE_VAL;

typedef struct str_AFN0D_CODE_ISNULL_t
{
    short TD;             /*时标为空标志*/
    short CBSJ;           /*抄表时间为空标志*/
    short Pcode[15];      /*有功读数为空标志*/
    short Qcode[15];      /*无功读数为空标志*/
    short Q12code[15];    /*1或2象限无功读数为空标志*/
    short Q34code[15];    /*3或4象限无功读数为空标志*/
}str_AFN0D_CODE_ISNULL;

typedef struct str_AFN0D_CODE_t
{
    str_AFN0D_CODE_VAL val;
    str_AFN0D_CODE_ISNULL isnull;
}str_AFN0D_CODE;

typedef struct str_AFN0D_XL_VAL_t
{
    datetime TD;            /*时标*/
    datetime CBSJ;          /*抄表时间*/
    short FLS;              /*费率数*/
    double PXL[15];         /*有功需量*/
    datetime PXLSJ[15];     /*有功需量发生时间*/
    double QXL[15];         /*无功需量*/
    datetime QXLSJ[15];     /*无功需量发生时间*/
}str_AFN0D_XL_VAL;

typedef struct str_AFN0D_XL_ISNULL_t
{
    short TD;            /*时标*/
    short CBSJ;          /*抄表时间*/
    short PXL[15];         /*有功需量*/
    short PXLSJ[15];     /*有功需量发生时间*/
    short QXL[15];         /*无功需量*/
    short QXLSJ[15];     /*无功需量发生时间*/
}str_AFN0D_XL_ISNULL;

typedef struct str_AFN0D_XL_t
{
    str_AFN0D_XL_VAL val;
    str_AFN0D_XL_ISNULL isnull;
}str_AFN0D_XL;

typedef struct str_AFN0D_POWER_VAL_t
{
    datetime TD;            /*时标*/
    short FLS;              /*费率数*/
    double power[15];       /*电量*/
}str_AFN0D_POWER_VAL;

typedef struct str_AFN0D_POWER_ISNULL_t
{
    short TD;            /*时标*/
    short power[15];     /*电量*/
}str_AFN0D_POWER_ISNULL;

typedef struct str_AFN0D_POWER_t
{
    str_AFN0D_POWER_VAL val;
    str_AFN0D_POWER_ISNULL isnull;
}str_AFN0D_POWER;

typedef struct str_AFN0D_MAXP_VAL_t
{
    datetime TD;                /*时标*/
    double MAXPZ;               /*最大总有功*/
    datetime MAXPZtime;         /*最大总有功发生时间*/
    double MAXPA;               /*A相最大有功*/
    datetime MAXPAtime;         /*A相最大有功发生时间*/
    double MAXPB;               /*B相最大有功*/
    datetime MAXPBtime;         /*B相最大有功发生时间*/
    double MAXPC;               /*C相最大有功*/
    datetime MAXPCtime;         /*C相最大有功发生时间*/
    unsigned short ZEROPZ;      /*总有功为0的时间*/
    unsigned short ZEROPA;      /*A相有功为0的时间*/
    unsigned short ZEROPB;      /*B相有功为0的时间*/
    unsigned short ZEROPC;      /*C相有功为0的时间*/
}str_AFN0D_MAXP_VAL;

typedef struct str_AFN0D_MAXP_ISNULL_t
{
    short TD;           /*时标判空标志*/
    short MAXPZ;        /*最大总有功判空标志*/
    short MAXPZtime;    /*最大总有功发生时间判空标志*/
    short MAXPA;        /*A相最大有功判空标志*/
    short MAXPAtime;    /*A相最大有功发生时间判空标志*/
    short MAXPB;        /*B相最大有功判空标志*/
    short MAXPBtime;    /*B相最大有功发生时间判空标志*/
    short MAXPC;        /*C相最大有功判空标志*/
    short MAXPCtime;    /*C相最大有功发生时间判空标志*/
    short ZEROPZ;       /*总有功为0时间判空标志*/
    short ZEROPA;       /*A相有功为0时间判空标志*/
    short ZEROPB;       /*B相有功为0时间判空标志*/
    short ZEROPC;       /*C相有功为0时间判空标志*/
}str_AFN0D_MAXP_ISNULL;

typedef struct str_AFN0D_MAXP_t
{
    str_AFN0D_MAXP_VAL val;
    str_AFN0D_MAXP_ISNULL isnull;
}str_AFN0D_MAXP;

typedef struct str_AFN0D_MAXXL_VAL_t
{
    datetime TD;            /*时标*/
    double MAXXLZ;          /*总最大需量*/
    datetime MAXXLZtime;    /*总最大需量出现时间*/
    double MAXXLA;          /*A相最大需量*/
    datetime MAXXLAtime;    /*A相最大需量出现时间*/
    double MAXXLB;          /*B相最大需量*/
    datetime MAXXLBtime;    /*B相最大需量出现时间*/
    double MAXXLC;          /*C相最大需量*/
    datetime MAXXLCtime;    /*C相最大需量出现时间*/
}str_AFN0D_MAXXL_VAL;

typedef struct str_AFN0D_MAXXL_ISNULL_t
{
    short TD;               /*时标*/
    short MAXXLZ;           /*总最大需量*/
    short MAXXLZtime;       /*总最大需量出现时间*/
    short MAXXLA;           /*A相最大需量*/
    short MAXXLAtime;       /*A相最大需量出现时间*/
    short MAXXLB;           /*B相最大需量*/
    short MAXXLBtime;       /*B相最大需量出现时间*/
    short MAXXLC;           /*C相最大需量*/
    short MAXXLCtime;       /*C相最大需量出现时间*/
}str_AFN0D_MAXXL_ISNULL;

typedef struct str_AFN0D_MAXXL_t
{
    str_AFN0D_MAXXL_VAL val;
    str_AFN0D_MAXXL_ISNULL isnull;
}str_AFN0D_MAXXL;

typedef struct str_AFN0D_STU_VAL__t
{
    datetime TD;            /*时标*/
    unsigned short ceillimit[3];     /*越上上限时间*/
    unsigned short lowerlimit[3];    /*越下下限时间*/
    unsigned short limit[3];         /*越上限时间*/
    unsigned short lower[3];         /*越下限时间*/
    unsigned short conformity[3];    /*合格时间*/
    double MAXU[3];         /*最大电压*/
    datetime MAXUtime[3];   /*最大电压出现时间*/
    double MINU[3];         /*最小电压*/
    datetime MINUtime[3];   /*最小电压出现时间*/
    double AVGU[3];         /*平均电压*/
    double ceillimitrate[3];     /*电压越上限率*/
    double lowerlimitrate[3];    /*电压越下限率*/
    double qualifiedrate[3];     /*电压合格率*/
}str_AFN0D_STU_VAL;

typedef struct str_AFN0D_STU_ISNULL__t
{
    short TD;               /*时标判空标志*/
    short ceillimit[3];     /*越上上限时间判空标志*/
    short lowerlimit[3];    /*越下下限时间判空标志*/
    short limit[3];         /*越上限时间判空标志*/
    short lower[3];         /*越下限时间判空标志*/
    short conformity[3];    /*合格时间判空标志*/
    short MAXU[3];          /*最大电压判空标志*/
    short MAXUtime[3];      /*最大电压出现时间判空标志*/
    short MINU[3];          /*最小电压判空标志*/
    short MINUtime[3];      /*最小电压出现时间判空标志*/
    short AVGU[3];          /*平均电压判空标志*/
    short ceillimitrate[3];     /*电压越上限率判空标志*/
    short lowerlimitrate[3];    /*电压越下限率判空标志*/
    short qualifiedrate[3];     /*电压合格率判空标志*/
}str_AFN0D_STU_ISNULL;

typedef struct str_AFN0D_STU_t
{
    str_AFN0D_STU_VAL val;
    str_AFN0D_STU_ISNULL isnull;
}str_AFN0D_STU;

typedef struct str_AFN0D_UNBALANCE_VAL_T
{
    datetime TD;    /*时标*/
    unsigned short Uval;     /*电压不平衡度累计越限时间*/
    unsigned short Ival;     /*电流不平衡度累计越限时间*/
    double   Ivalue;         /*电流不平衡最大值*/
    datetime   Ivaluetime;   /*电流不平衡最大值发生时间*/
    double   Uvalue;         /*电压不平衡最大值*/
    datetime   Uvaluetime;   /*电压不平衡最大值发生时间*/
}str_AFN0D_UNBALANCE_VAL;

typedef struct str_AFN0D_UNBALANCE_ISNULL_T
{
    short TD;       /*时标判空标志*/
    short Uval;     /*电压不平衡度累计越限时间判空标志*/
    short Ival;     /*电压不平衡度累计越限时间判空标志*/
    short   Ivalue;         /*电流不平衡最大值*/
    short   Ivaluetime;   /*电流不平衡最大值发生时间*/
    short   Uvalue;         /*电压不平衡最大值*/
    short   Uvaluetime;   /*电压不平衡最大值发生时间*/
}str_AFN0D_UNBALANCE_ISNULL;

typedef struct str_AFN0D_UNBALANCE_t
{
    str_AFN0D_UNBALANCE_VAL val;
    str_AFN0D_UNBALANCE_ISNULL isnull;
}str_AFN0D_UNBALANCE;

typedef struct str_AFN0D_STI_VAL_t
{
    datetime TD;            /*时标*/
    unsigned short ceillimit[3];     /*越上上限时间*/
    unsigned short limit[4];         /*越上限时间*/
    double MAXI[4];         /*最大值*/
    datetime MAXItime[4];   /*最大值出现时间*/
}str_AFN0D_STI_VAL;

typedef struct str_AFN0D_STI_ISNULL_t
{
    short TD;               /*时标判空标志*/
    short ceillimit[3];     /*越上上限时间判空标志*/
    short limit[4];         /*越上限时间判空标志*/
    short MAXI[4];          /*最大值判空标志*/
    short MAXItime[4];      /*最大值出现时间判空标志*/
}str_AFN0D_STI_ISNULL;

typedef struct str_AFN0D_STI_t
{
    str_AFN0D_STI_VAL val;
    str_AFN0D_STI_ISNULL isnull;
}str_AFN0D_STI;

typedef struct str_AFN0D_APP_VAL_t
{
    datetime TD;            /*时标*/
    unsigned short ceillimit;        /*越上上限时间*/
    unsigned short limit;            /*越上限时间*/
}str_AFN0D_APP_VAL;

typedef struct str_AFN0D_APP_ISNULL_t
{
    short TD;               /*时标判空标志*/
    short ceillimit;        /*越上上限时间判空标志*/
    short limit;            /*越上限时间判空标志*/
}str_AFN0D_APP_ISNULL;

typedef struct str_AFN0D_APP_t
{
    str_AFN0D_APP_VAL val;
    str_AFN0D_APP_ISNULL isnull;
}str_AFN0D_APP;

typedef struct str_AFN0D_BREAK_VAL_t
{
    datetime TD;            /*时标*/
    datetime CBSJ;          /*抄表时间*/
    int breaks[4];          /*断相次数*/
    int breaktimes[4];      /*断相累计时间*/
    datetime laststart[4];     /*最近一次断相开始时间*/
    datetime laststop[4];      /*最近一次断相结束时间*/
}str_AFN0D_BREAK_VAL;

typedef struct str_AFN0D_BREAK_ISNULL_t
{
    short TD;               /*时标判空标志*/
    short CBSJ;             /*抄表时间判空标志*/
    short breaks[4];        /*断相次数判空标志*/
    short breaktimes[4];    /*断相累计时间判空标志*/
    short laststart[4];        /*最近一次断相开始时间判空标志*/
    short laststop[4];         /*最近一次断相结束时间判空标志*/
}str_AFN0D_BREAK_ISNULL;

typedef struct str_AFN0D_BREAK_t
{
    str_AFN0D_BREAK_VAL val;
    str_AFN0D_BREAK_ISNULL isnull;
}str_AFN0D_BREAK;



int de_AFN0D_FN1_2_9_10_str(uchar *dat_in, int dat_len, str_AFN0D_CODE *str_out, int *ai_step);
int de_AFN0D_FN3_4_11_12_str(uchar *data, str_AFN0D_XL *astr_val, int *ai_step);

int de_AFN0D_FN5_6_7_8_str(uchar *data, str_AFN0D_POWER *astr_val, int *ai_step);
int de_AFN0D_FN1_2_9_10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN3_4_11_12(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_FN5_6_7_8(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);


#endif
