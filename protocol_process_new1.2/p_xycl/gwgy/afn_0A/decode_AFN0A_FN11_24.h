#ifndef DECODE_AFN0A_FN11_24_H
#define DECODE_AFN0A_FN11_24_H

#include "../public/decode_public.h"



typedef struct str_AFN0A_F11_PULSEINFO_t
{
    byte port;             /*脉冲量端口*/
    byte CLD;              /*所属测量点*/
    byte PulseType;        /*脉冲属性 0正向有功 1 正向无功 2 反向有功 3 反向无功*/
    unsigned short KVal;    /*K常数*/
}str_AFN0A_F11_PULSEINFO;

typedef struct str_AFN0A_F11_t
{
    byte PulseNumber;      /*本次配置脉冲量数量*/
    str_AFN0A_F11_PULSEINFO pulseinfo[64];  /*脉冲量设置参数数组*/
}str_AFN0A_F11;

typedef struct str_AFN0A_F12_t
{
    byte BinaryState[8];
    byte BinaryProperty[8];
}str_AFN0A_F12;

typedef struct str_AFN0A_F13_IMITATIONINFO_t
{
    byte port;             /*模拟量端口*/
    byte CLD;              /*所属测量点*/
    byte ImitationType;    /*属性 0 A相电压 1 B相电压 2 C相电压
                                   3 A相电流 4 B相电流 5 C相电流*/
}str_AFN0A_F13_IMITATIONINFO;

typedef struct str_AFN0A_F13_t
{
    byte imitationNumber;      /*本次配置模拟量数量*/
    str_AFN0A_F13_IMITATIONINFO imitationinfo[64];  /*模拟量设置参数数组*/
}str_AFN0A_F13;

typedef struct str_AFN0A_F14_ADDGROUPINFO_t
{
    byte addgroupindex;             /*总加组序号*/
    byte CLDnumber;                 /*测量点数量*/
    byte CLD[255];                  /*测量点数组*/
    byte CLDdirection[255];         /*方向*/
    byte CLDoperator[255];          /*运算符*/
}str_AFN0A_F14_ADDGROUPINFO;

typedef struct str_AFN0A_F14_t
{
    byte addgroupnumber;                /*总加组数量*/
    str_AFN0A_F14_ADDGROUPINFO addgroupinfo[64];  /*总加组配置数组*/
}str_AFN0A_F14;

typedef struct str_AFN0A_F15_DIFFINFO_t
{
    byte diffnum;                    /*差动组号*/
    byte contrastnum;                /*对比总加组号*/
    byte referencenum;               /*参照总加组号*/
    byte Timespan;                   /*时间跨度*/
    byte contrasttype;               /*对比方法*/
    byte Relativeval;                /*对比相对值*/
    short Relativeisnull;            /*对比相对值判空*/
    int Absoluteval;                 /*对比绝对值*/
    short Absoluteisnull;            /*对比绝对值判空*/
}str_AFN0A_F15_DIFFINFO;

typedef struct str_AFN0A_F15_t
{
    byte diffnumber;                /*差动组数量*/
    str_AFN0A_F15_DIFFINFO diffinfo[255];  /*差动组配置数组*/
}str_AFN0A_F15;

typedef struct str_AFN0A_F16_t
{
    uchar AFNuser[32];                /*AFN用户名*/
    uchar AFNpassword[32];            /*AFN密码*/
}str_AFN0A_F16;
typedef struct str_AFN0A_F17_t
{
    double val;        /*终端保安定值*/
    short isnull;      /*保安定值判空标志*/
}str_AFN0A_F17;

typedef struct str_AFN0A_F18_t
{
    byte Periodstate[48];      /*时段标志 0 不控制 1 控制1 2 控制2 3 保留*/
}str_AFN0A_F18;

typedef struct str_AFN0A_FLOATFACATOR_t
{
    int val;           /*浮动系数*/
    short isnull;      /*浮动系数判空标志*/
}str_AFN0A_FLOATFACATOR;

typedef struct str_AFN0A_F21_t
{
    byte FLstate[48];      /*时段标志 0~13 表示1～14费率*/
    byte FLS;              /*费率数*/
    short FLSisnull;        /*费率数为空标志*/
}str_AFN0A_F21;

typedef struct str_AFN0A_F22_t
{
    byte FLS;              /*费率数*/
    int FL[14];      /*费率*/
    short FLisnull[14]; /*费率为空标志*/
}str_AFN0A_F22;

typedef struct str_AFN0A_F23_t
{
    byte alarm[24]; /*催费告警标志*/
}str_AFN0A_F23;



int decode_afn0A_F11(uchar *data, str_AFN0A_F11 *astr_val, int *ai_step);
int decode_afn0A_F12(uchar *data, str_AFN0A_F12 *astr_val, int *ai_step);
int decode_afn0A_F13(uchar *data, str_AFN0A_F13 *astr_val, int *ai_step);
int decode_afn0A_F14(uchar *data, str_AFN0A_F14 *astr_val, int *ai_step);
int decode_afn0A_F15(uchar *data, str_AFN0A_F15 *astr_val, int *ai_step);
int decode_afn0A_F16(uchar *data, str_AFN0A_F16 *astr_val, int *ai_step);
int decode_afn0A_F17(uchar *data, str_AFN0A_F17 *astr_val, int *ai_step);
int decode_afn0A_F18(uchar *data, str_AFN0A_F18 *astr_val, int *ai_step);
int decode_afn0A_FLOATFACATOR(uchar *data, str_AFN0A_FLOATFACATOR *astr_val, int *ai_step);
int decode_afn0A_F21(uchar *data, str_AFN0A_F21 *astr_val, int *ai_step);
int decode_afn0A_F22(uchar *data, str_AFN0A_F22 *astr_val, int *ai_step);
int decode_afn0A_F23(uchar *data, str_AFN0A_F23 *astr_val, int *ai_step);

#endif

