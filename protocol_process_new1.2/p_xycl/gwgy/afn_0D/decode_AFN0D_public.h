#ifndef DECODE_AFN0D_public_H
#define DECODE_AFN0D_public_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_CODE_VAL_t
{
    datetime TD;            /*ʱ��*/
    datetime CBSJ;          /*����ʱ��*/
    short FLS;              /*������*/
    double Pcode[15];       /*�й�����*/
    double Qcode[15];       /*�޹�����*/
    double Q12code[15];     /*1��2�����޹�����*/
    double Q34code[15];     /*3��4�����޹�����*/
}str_AFN0D_CODE_VAL;

typedef struct str_AFN0D_CODE_ISNULL_t
{
    short TD;             /*ʱ��Ϊ�ձ�־*/
    short CBSJ;           /*����ʱ��Ϊ�ձ�־*/
    short Pcode[15];      /*�й�����Ϊ�ձ�־*/
    short Qcode[15];      /*�޹�����Ϊ�ձ�־*/
    short Q12code[15];    /*1��2�����޹�����Ϊ�ձ�־*/
    short Q34code[15];    /*3��4�����޹�����Ϊ�ձ�־*/
}str_AFN0D_CODE_ISNULL;

typedef struct str_AFN0D_CODE_t
{
    str_AFN0D_CODE_VAL val;
    str_AFN0D_CODE_ISNULL isnull;
}str_AFN0D_CODE;

typedef struct str_AFN0D_XL_VAL_t
{
    datetime TD;            /*ʱ��*/
    datetime CBSJ;          /*����ʱ��*/
    short FLS;              /*������*/
    double PXL[15];         /*�й�����*/
    datetime PXLSJ[15];     /*�й���������ʱ��*/
    double QXL[15];         /*�޹�����*/
    datetime QXLSJ[15];     /*�޹���������ʱ��*/
}str_AFN0D_XL_VAL;

typedef struct str_AFN0D_XL_ISNULL_t
{
    short TD;            /*ʱ��*/
    short CBSJ;          /*����ʱ��*/
    short PXL[15];         /*�й�����*/
    short PXLSJ[15];     /*�й���������ʱ��*/
    short QXL[15];         /*�޹�����*/
    short QXLSJ[15];     /*�޹���������ʱ��*/
}str_AFN0D_XL_ISNULL;

typedef struct str_AFN0D_XL_t
{
    str_AFN0D_XL_VAL val;
    str_AFN0D_XL_ISNULL isnull;
}str_AFN0D_XL;

typedef struct str_AFN0D_POWER_VAL_t
{
    datetime TD;            /*ʱ��*/
    short FLS;              /*������*/
    double power[15];       /*����*/
}str_AFN0D_POWER_VAL;

typedef struct str_AFN0D_POWER_ISNULL_t
{
    short TD;            /*ʱ��*/
    short power[15];     /*����*/
}str_AFN0D_POWER_ISNULL;

typedef struct str_AFN0D_POWER_t
{
    str_AFN0D_POWER_VAL val;
    str_AFN0D_POWER_ISNULL isnull;
}str_AFN0D_POWER;

typedef struct str_AFN0D_MAXP_VAL_t
{
    datetime TD;                /*ʱ��*/
    double MAXPZ;               /*������й�*/
    datetime MAXPZtime;         /*������й�����ʱ��*/
    double MAXPA;               /*A������й�*/
    datetime MAXPAtime;         /*A������й�����ʱ��*/
    double MAXPB;               /*B������й�*/
    datetime MAXPBtime;         /*B������й�����ʱ��*/
    double MAXPC;               /*C������й�*/
    datetime MAXPCtime;         /*C������й�����ʱ��*/
    unsigned short ZEROPZ;      /*���й�Ϊ0��ʱ��*/
    unsigned short ZEROPA;      /*A���й�Ϊ0��ʱ��*/
    unsigned short ZEROPB;      /*B���й�Ϊ0��ʱ��*/
    unsigned short ZEROPC;      /*C���й�Ϊ0��ʱ��*/
}str_AFN0D_MAXP_VAL;

typedef struct str_AFN0D_MAXP_ISNULL_t
{
    short TD;           /*ʱ���пձ�־*/
    short MAXPZ;        /*������й��пձ�־*/
    short MAXPZtime;    /*������й�����ʱ���пձ�־*/
    short MAXPA;        /*A������й��пձ�־*/
    short MAXPAtime;    /*A������й�����ʱ���пձ�־*/
    short MAXPB;        /*B������й��пձ�־*/
    short MAXPBtime;    /*B������й�����ʱ���пձ�־*/
    short MAXPC;        /*C������й��пձ�־*/
    short MAXPCtime;    /*C������й�����ʱ���пձ�־*/
    short ZEROPZ;       /*���й�Ϊ0ʱ���пձ�־*/
    short ZEROPA;       /*A���й�Ϊ0ʱ���пձ�־*/
    short ZEROPB;       /*B���й�Ϊ0ʱ���пձ�־*/
    short ZEROPC;       /*C���й�Ϊ0ʱ���пձ�־*/
}str_AFN0D_MAXP_ISNULL;

typedef struct str_AFN0D_MAXP_t
{
    str_AFN0D_MAXP_VAL val;
    str_AFN0D_MAXP_ISNULL isnull;
}str_AFN0D_MAXP;

typedef struct str_AFN0D_MAXXL_VAL_t
{
    datetime TD;            /*ʱ��*/
    double MAXXLZ;          /*���������*/
    datetime MAXXLZtime;    /*�������������ʱ��*/
    double MAXXLA;          /*A���������*/
    datetime MAXXLAtime;    /*A�������������ʱ��*/
    double MAXXLB;          /*B���������*/
    datetime MAXXLBtime;    /*B�������������ʱ��*/
    double MAXXLC;          /*C���������*/
    datetime MAXXLCtime;    /*C�������������ʱ��*/
}str_AFN0D_MAXXL_VAL;

typedef struct str_AFN0D_MAXXL_ISNULL_t
{
    short TD;               /*ʱ��*/
    short MAXXLZ;           /*���������*/
    short MAXXLZtime;       /*�������������ʱ��*/
    short MAXXLA;           /*A���������*/
    short MAXXLAtime;       /*A�������������ʱ��*/
    short MAXXLB;           /*B���������*/
    short MAXXLBtime;       /*B�������������ʱ��*/
    short MAXXLC;           /*C���������*/
    short MAXXLCtime;       /*C�������������ʱ��*/
}str_AFN0D_MAXXL_ISNULL;

typedef struct str_AFN0D_MAXXL_t
{
    str_AFN0D_MAXXL_VAL val;
    str_AFN0D_MAXXL_ISNULL isnull;
}str_AFN0D_MAXXL;

typedef struct str_AFN0D_STU_VAL__t
{
    datetime TD;            /*ʱ��*/
    unsigned short ceillimit[3];     /*Խ������ʱ��*/
    unsigned short lowerlimit[3];    /*Խ������ʱ��*/
    unsigned short limit[3];         /*Խ����ʱ��*/
    unsigned short lower[3];         /*Խ����ʱ��*/
    unsigned short conformity[3];    /*�ϸ�ʱ��*/
    double MAXU[3];         /*����ѹ*/
    datetime MAXUtime[3];   /*����ѹ����ʱ��*/
    double MINU[3];         /*��С��ѹ*/
    datetime MINUtime[3];   /*��С��ѹ����ʱ��*/
    double AVGU[3];         /*ƽ����ѹ*/
    double ceillimitrate[3];     /*��ѹԽ������*/
    double lowerlimitrate[3];    /*��ѹԽ������*/
    double qualifiedrate[3];     /*��ѹ�ϸ���*/
}str_AFN0D_STU_VAL;

typedef struct str_AFN0D_STU_ISNULL__t
{
    short TD;               /*ʱ���пձ�־*/
    short ceillimit[3];     /*Խ������ʱ���пձ�־*/
    short lowerlimit[3];    /*Խ������ʱ���пձ�־*/
    short limit[3];         /*Խ����ʱ���пձ�־*/
    short lower[3];         /*Խ����ʱ���пձ�־*/
    short conformity[3];    /*�ϸ�ʱ���пձ�־*/
    short MAXU[3];          /*����ѹ�пձ�־*/
    short MAXUtime[3];      /*����ѹ����ʱ���пձ�־*/
    short MINU[3];          /*��С��ѹ�пձ�־*/
    short MINUtime[3];      /*��С��ѹ����ʱ���пձ�־*/
    short AVGU[3];          /*ƽ����ѹ�пձ�־*/
    short ceillimitrate[3];     /*��ѹԽ�������пձ�־*/
    short lowerlimitrate[3];    /*��ѹԽ�������пձ�־*/
    short qualifiedrate[3];     /*��ѹ�ϸ����пձ�־*/
}str_AFN0D_STU_ISNULL;

typedef struct str_AFN0D_STU_t
{
    str_AFN0D_STU_VAL val;
    str_AFN0D_STU_ISNULL isnull;
}str_AFN0D_STU;

typedef struct str_AFN0D_UNBALANCE_VAL_T
{
    datetime TD;    /*ʱ��*/
    unsigned short Uval;     /*��ѹ��ƽ����ۼ�Խ��ʱ��*/
    unsigned short Ival;     /*������ƽ����ۼ�Խ��ʱ��*/
    double   Ivalue;         /*������ƽ�����ֵ*/
    datetime   Ivaluetime;   /*������ƽ�����ֵ����ʱ��*/
    double   Uvalue;         /*��ѹ��ƽ�����ֵ*/
    datetime   Uvaluetime;   /*��ѹ��ƽ�����ֵ����ʱ��*/
}str_AFN0D_UNBALANCE_VAL;

typedef struct str_AFN0D_UNBALANCE_ISNULL_T
{
    short TD;       /*ʱ���пձ�־*/
    short Uval;     /*��ѹ��ƽ����ۼ�Խ��ʱ���пձ�־*/
    short Ival;     /*��ѹ��ƽ����ۼ�Խ��ʱ���пձ�־*/
    short   Ivalue;         /*������ƽ�����ֵ*/
    short   Ivaluetime;   /*������ƽ�����ֵ����ʱ��*/
    short   Uvalue;         /*��ѹ��ƽ�����ֵ*/
    short   Uvaluetime;   /*��ѹ��ƽ�����ֵ����ʱ��*/
}str_AFN0D_UNBALANCE_ISNULL;

typedef struct str_AFN0D_UNBALANCE_t
{
    str_AFN0D_UNBALANCE_VAL val;
    str_AFN0D_UNBALANCE_ISNULL isnull;
}str_AFN0D_UNBALANCE;

typedef struct str_AFN0D_STI_VAL_t
{
    datetime TD;            /*ʱ��*/
    unsigned short ceillimit[3];     /*Խ������ʱ��*/
    unsigned short limit[4];         /*Խ����ʱ��*/
    double MAXI[4];         /*���ֵ*/
    datetime MAXItime[4];   /*���ֵ����ʱ��*/
}str_AFN0D_STI_VAL;

typedef struct str_AFN0D_STI_ISNULL_t
{
    short TD;               /*ʱ���пձ�־*/
    short ceillimit[3];     /*Խ������ʱ���пձ�־*/
    short limit[4];         /*Խ����ʱ���пձ�־*/
    short MAXI[4];          /*���ֵ�пձ�־*/
    short MAXItime[4];      /*���ֵ����ʱ���пձ�־*/
}str_AFN0D_STI_ISNULL;

typedef struct str_AFN0D_STI_t
{
    str_AFN0D_STI_VAL val;
    str_AFN0D_STI_ISNULL isnull;
}str_AFN0D_STI;

typedef struct str_AFN0D_APP_VAL_t
{
    datetime TD;            /*ʱ��*/
    unsigned short ceillimit;        /*Խ������ʱ��*/
    unsigned short limit;            /*Խ����ʱ��*/
}str_AFN0D_APP_VAL;

typedef struct str_AFN0D_APP_ISNULL_t
{
    short TD;               /*ʱ���пձ�־*/
    short ceillimit;        /*Խ������ʱ���пձ�־*/
    short limit;            /*Խ����ʱ���пձ�־*/
}str_AFN0D_APP_ISNULL;

typedef struct str_AFN0D_APP_t
{
    str_AFN0D_APP_VAL val;
    str_AFN0D_APP_ISNULL isnull;
}str_AFN0D_APP;

typedef struct str_AFN0D_BREAK_VAL_t
{
    datetime TD;            /*ʱ��*/
    datetime CBSJ;          /*����ʱ��*/
    int breaks[4];          /*�������*/
    int breaktimes[4];      /*�����ۼ�ʱ��*/
    datetime laststart[4];     /*���һ�ζ��࿪ʼʱ��*/
    datetime laststop[4];      /*���һ�ζ������ʱ��*/
}str_AFN0D_BREAK_VAL;

typedef struct str_AFN0D_BREAK_ISNULL_t
{
    short TD;               /*ʱ���пձ�־*/
    short CBSJ;             /*����ʱ���пձ�־*/
    short breaks[4];        /*��������пձ�־*/
    short breaktimes[4];    /*�����ۼ�ʱ���пձ�־*/
    short laststart[4];        /*���һ�ζ��࿪ʼʱ���пձ�־*/
    short laststop[4];         /*���һ�ζ������ʱ���пձ�־*/
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
