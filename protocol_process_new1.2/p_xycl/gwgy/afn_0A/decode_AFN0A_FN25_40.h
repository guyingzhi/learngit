#ifndef DECODE_AFN0A_FN25_40_H
#define DECODE_AFN0A_FN25_40_H

#include "../public/decode_public.h"


typedef struct str_AFN0A_F25_t   /*A规约F25数据*/
{
    unsigned short PT, CT;           /*互感器倍率*/
    double limitU,maxI,limitFH;     /*额定电压，最大电流,额定负荷*/
    short limitUisnull,maxIisnull,limitFHisnull;     /*额定电压，最大电流判空,额定负荷判空*/
    byte DYConnection;       /*电源接线方式，数值1～3依次表示三相三线、三相四线、单相表*/
    byte Connection;       /*接线方式 1三相三线 2三相四线 3单相表*/
}str_AFN0A_F25;

typedef struct str_AFN0A_F26_VAL_t   /*A规约F26数据*/
{
    double limitU;          /*电压合格上限*/
    double lowerU;          /*电压合格下限*/
    double breakphaseU;     /*电压断相门限*/
    double ceilinglimitU;   /*电压上上限（过压门限）*/
    byte   ceilinglimitUtime;   /*越限持续时间*/
    double ceilinglimitUxs;   /*越限恢复系数*/
    double lowerlimitU;     /*电压下下限（欠压门限）*/
    byte   lowerlimitUtime;   /*越限持续时间*/
    double lowerlimitUxs;   /*越限恢复系数*/
    double ceilinglimitI;   /*相电流上上限（过流门限）*/
    byte   ceilinglimitItime;   /*越限持续时间*/
    double ceilinglimitIxs;   /*越限恢复系数*/
    double limitI;          /*相电流上限（额定电流门限）*/
    byte   limitItime;   /*越限持续时间*/
    double limitIxs;   /*越限恢复系数*/
    double limitIzero;      /*零序电流上限*/
    byte   limitIzerotime;   /*越限持续时间*/
    double limitIzeroxs;   /*越限恢复系数*/
    double ceilinglimitP;   /*视在功率上上限*/
    byte   ceilinglimitPtime;   /*越限持续时间*/
    double ceilinglimitPxs;   /*越限恢复系数*/
    double limitP;          /*视在功率上限*/
    byte   limitPtime;   /*越限持续时间*/
    double limitPxs;   /*越限恢复系数*/
    double unbalanceU;      /*三相电压不平衡限值*/
    byte   unbalanceUtime;   /*越限持续时间*/
    double unbalanceUxs;   /*越限恢复系数*/
    double unbalanceI;      /*三相电流不平衡限值*/
    byte   unbalanceItime;   /*越限持续时间*/
    double unbalanceIxs;   /*越限恢复系数*/
    byte loseUtme;         /*连续失压时间限值*/
}str_AFN0A_F26_VAL;

typedef struct str_AFN0A_F26_ISNULL_t   /*A规约F26判空*/
{
    short limitU;         /*电压合格上限判空标志*/
    short lowerU;          /*电压合格下限标志*/
    short breakphaseU;     /*电压断相门限标志*/
    short ceilinglimitU;   /*电压上上限标志*/
    short ceilinglimitUtime;   /*越限持续时间*/
    short ceilinglimitUxs;   /*越限恢复系数*/
    short lowerlimitU;     /*电压下下限标志*/
    short lowerlimitUtime;   /*越限持续时间*/
    short lowerlimitUxs;   /*越限恢复系数*/
    short ceilinglimitI;   /*相电流上上限标志*/
    short ceilinglimitItime;   /*越限持续时间*/
    short ceilinglimitIxs;   /*越限恢复系数*/
    short limitI;          /*相电流上限标志*/
    short limitItime;   /*越限持续时间*/
    short limitIxs;   /*越限恢复系数*/
    short limitIzero;      /*零序电流上限标志*/
    short   limitIzerotime;   /*越限持续时间*/
    short limitIzeroxs;   /*越限恢复系数*/
    short ceilinglimitP;   /*视在功率上上限标志*/
    short ceilinglimitPtime;   /*越限持续时间*/
    short ceilinglimitPxs;   /*越限恢复系数*/
    short limitP;          /*视在功率上限标志*/
    short   limitPtime;   /*越限持续时间*/
    short limitPxs;   /*越限恢复系数*/
    short unbalanceU;      /*三相电压不平衡限值标志*/
    short   unbalanceUtime;   /*越限持续时间*/
    short unbalanceUxs;   /*越限恢复系数*/
    short unbalanceI;      /*三相电流不平衡限值标志*/
    short   unbalanceItime;   /*越限持续时间*/
    short unbalanceIxs;   /*越限恢复系数*/
    short loseUtme;        /*连续失压时间限值标志*/
}str_AFN0A_F26_ISNULL;

typedef struct str_AFN0A_F26_t   /*A规约F26解析结果，包括数据及判空标志*/
{
    str_AFN0A_F26_VAL val;        /*数据结构*/
    str_AFN0A_F26_ISNULL isnull;  /*判空标志结构*/
}str_AFN0A_F26;

typedef struct str_AFN0A_F27_t   /*A规约F27解析结果*/
{
    double tctc[12];      /*铁损、铜损参数*/
    short  tctcisnull[12];      /*铁损、铜损参数判空*/
}str_AFN0A_F27;
//typedef struct str_AFN0A_F27_t   /*A规约F27解析结果*/
//{
//    byte DJnumber;         /*冻结信息标识数量*/
//    byte FN[255];          /*冻结信息标识*/
//    str_MD MD[255];         /*冻结密度*/
//}str_AFN0A_F27;

typedef struct str_AFN0A_F28_t   /*A规约F28解析结果*/
{
    double limit1;         /*功率因数分段限值1*/
    double limit2;         /*功率因数分段限值2*/
    short limit1isnull,limit2isnull; /*判空标志*/
}str_AFN0A_F28;

typedef struct str_AFN0A_F29_t   /*A规约F28解析结果*/
{
    char xsh[13];         /*终端当地电能表显示号*/
}str_AFN0A_F29;

typedef struct str_AFN0A_F31_t   /*A规约F28解析结果*/
{
    byte        Number;
    str_add12   MeterAdd[20];      /*从节点附属节点地址*/
    short       MeterAddisnull[20];    /*从节点附属节点地址为空标志*/
}str_AFN0A_F31;
typedef struct str_AFN0A_F33_VAL_t   /*A规约F1数据*/
{
    byte port;              /*终端通信端口号*/
    char ztz[16];           /*台区集中抄表运行控制字, 1 要求，置“0”不要求,（D0取反）*/
    char day[32];           /*抄表日-日期*/
    datetime cbsj;           /*抄表日-时间*/
    short cbsjisnull;
    byte cbjg;              /*抄表间隔时间*/
    datetime jssj;           /*对电表广播校时定时时间*/
    short jssjisnull;
    byte  sdnumber;              /*允许抄表时段数m*/
    datetime cbsd[50];           /*抄表日-时间*/
    short cbsdisnull[50];
}str_AFN0A_F33_VAL;

typedef struct str_AFN0A_F33_t  /*A规约F1结构体，包括数据体和判空标志*/
{
    byte                number;          /*本次设置的参数块个数n*/
    str_AFN0A_F33_VAL   val[32];         /*数据体*/
}str_AFN0A_F33;

typedef struct str_AFN0A_F34_VAL_t   /*A规约F1数据*/
{
    byte port;              /*终端通信端口号*/
    byte ztz[8];           /*台区集中抄表运行控制字, 1 要求，置“0”不要求*/
    unsigned int txsl;       /*通讯速率*/
}str_AFN0A_F34_VAL;

typedef struct str_AFN0A_F34_t  /*A规约F1结构体，包括数据体和判空标志*/
{
    byte                number;          /*本次设置的参数块个数n*/
    str_AFN0A_F34_VAL   val[32];         /*数据体*/
}str_AFN0A_F34;

typedef struct str_AFN0A_F35_t
{
    byte     zdhgs;          /*重点户个数*/
    ushort    setxh[2048];    /*装置序号*/
}str_AFN0A_F35;

typedef struct str_AFN0A_F37_t
{
    byte     port;          /*终端级联通信端口号*/
    byte     kzz[8];    /*终端级联通信控制字*/
    byte     bwtimeout;          /*接收等待报文超时时间*/
    byte     jstimeout;          /*接收等待字节超时时间*/
    byte     recs;          /*级联方（主动站）接收失败重发次数*/
    byte     xczq;          /*级联巡测周期*/
    byte     jldx;          /*级联/被级联标志*/
    byte     number;          /*级联/被级联标志、及其对应的被级联/级联的终端个数n*/
    ushort   xzqhm[255];      /*第n个被级联的终端行政区划码*/
    ushort   zddz[255];         /*第n个被级联的终端地址*/
}str_AFN0A_F37;

typedef struct str_AFN0A_F38F39_VAL_t   /*A规约F1数据*/
{
    byte     xlh;              /*用户小类号*/
    byte     xxlzs;            /*信息类组数n*/
    byte     xxlbz[248];     /*组信息类组所对应的信息类元标志位*/
}str_AFN0A_F38F39_VAL;

typedef struct str_AFN0A_F38F39_t
{
    byte     dlh;               /*用户大类号*/
    byte     zs;               /*组数*/
    str_AFN0A_F38F39_VAL     val[17];
}str_AFN0A_F38F39;


int decode_afn0A_F25(uchar *data, str_AFN0A_F25 *astr_val, int *ai_step);
int decode_afn0A_F26(uchar *data, str_AFN0A_F26 *astr_val, int *ai_step);
int decode_afn0A_F27(uchar *data, str_AFN0A_F27 *astr_val, int *ai_step);
int decode_afn0A_F28(uchar *data, str_AFN0A_F28 *astr_val, int *ai_step);
int decode_afn0A_F29(uchar *data, str_AFN0A_F29 *astr_val, int *ai_step);
int decode_afn0A_F31(uchar *data, str_AFN0A_F31 *astr_val, int *ai_step);
int decode_afn0A_F33(uchar *data, str_AFN0A_F33 *astr_val, int *ai_step);
int decode_afn0A_F34(uchar *data, str_AFN0A_F34 *astr_val, int *ai_step);
int decode_afn0A_F35(uchar *data, str_AFN0A_F35 *astr_val, int *ai_step);
int decode_afn0A_F36(uchar *data, uint *ai_val, int *ai_step);
int decode_afn0A_F37(uchar *data, str_AFN0A_F37 *astr_val, int *ai_step);
int decode_afn0A_F38F39(uchar *data, str_AFN0A_F38F39 *astr_val, int *ai_step);



#endif
