#ifndef DECODE_AFN0A_FN1_10_H
#define DECODE_AFN0A_FN1_10_H

#include "../public/decode_public.h"


typedef struct str_AFN0A_F1_VAL_t   /*A规约F1数据*/
{
    byte RTS;              /*RTS*/
    byte PDelay;           /*启动站允许传输延时*/
    unsigned short CTimeout;           /*从动站响应超时时间*/
    byte RTimes;           /*重发次数*/
    byte con1;             /*重要事件确认标志*/
    byte con2;             /*一般事件确认标志*/
    byte con3;             /*3类数据自动上报标志*/
    byte HCycle;           /*心跳周期*/
}str_AFN0A_F1_VAL;

typedef struct str_AFN0A_F1_ISNULL_t  /*A规约F1判空，1为空，0为非空*/
{
    short RTS;               /*RTS判空标志*/
    short PDelay;            /*启动站允许传输延时判空标志*/
    short CTimeout;          /*从动站响应超时时间判空标志*/
    short RTimes;            /*重发次数判空标志*/
    short con1;              /*重要事件确认判空标志*/
    short con2;              /*一般事件确认判空标志*/
    short con3;              /*3类数据自动上报标志*/
    short HCycle;            /*心跳周期判空标志*/
}str_AFN0A_F1_ISNULL;

typedef struct str_AFN0A_F1_t  /*A规约F1结构体，包括数据体和判空标志*/
{
    str_AFN0A_F1_VAL val;         /*数据体*/
    str_AFN0A_F1_ISNULL isnull;   /*判空标志*/
}str_AFN0A_F1;

typedef struct str_AFN0A_F2_t
{
    byte ForwardNumber;        /*被转发的终端数 0~127*/
    byte Forward;              /*允许禁止转发标志*/
    unsigned short ForwardAddress[255];  /*被转发的终端地址数组*/
}str_AFN0A_F2;

typedef struct str_AFN0A_F3_t
{
    uchar MainIP[16];        /*主用IP*/
    unsigned short MainSOCKET;        /*主用端口*/
    uchar STBYIP[16];        /*备用IP*/
    unsigned short STBYSOCKET;        /*备用端口*/
    uchar APN[17];           /*APN*/
}str_AFN0A_F3;

typedef struct str_AFN0A_F4_t
{
    uchar MSAPhone[17];     /*主站电话号码*/
    uchar SMSPhone[17];     /*短信中心号码*/
}str_AFN0A_F4;

typedef struct str_AFN0A_F5_t
{
    byte MesNum;              /*消息认证号*/
    unsigned short MesPar;    /*消息认证参数*/
}str_AFN0A_F5;

typedef struct str_AFN0A_F6_t
{
    unsigned short Address[8];     /*终端组地址*/
}str_AFN0A_F6;

typedef struct str_AFN0A_F7_t
{
    byte zdIP[16];        /*终端IP*/
    byte zwYM[16];        /*子网掩码*/
    byte WG[16];          /*网关*/
    byte dllx;           /*代理类型*/
    byte dlIP[16];       /*代理IP*/
    unsigned short dlSOCKET;      /*代理端口*/
    byte ljfs;           /*代理连接方式*/
    byte nmlen;          /*用户名长度*/
    char  name[21];       /*用户名*/
    byte pwlen;          /*密码长度*/
    char  pw[21];         /*密码*/
    unsigned short zdSOCKET;       /*终端侦听端口*/
}str_AFN0A_F7;

typedef struct str_AFN0A_F8_t
{
    byte onlinetype;        /*三种在线模式，取值范围1～3依次表示永久在线模式、被动激活模式、时段在线模式*/
    byte worktype;         /*终端的三种工作模式，取值范围0～2依次表示混合模式、客户机模式、服务器模式*/
    byte sockettype;         /*置“0”为TCP；置“1”为UDP*/
    unsigned short retelstep;  /*永久在线模式重拨间隔*/
    byte reteltimes;       /*被动激活模式重拨次数*/
    byte distime;          /*被动激活模式连续无通信自动断线时间*/
    byte onlinetime[24];          /*时段在线模式允许在线时段标志*/
}str_AFN0A_F8;

typedef struct str_AFN0A_F9_t
{
    byte SaveEvent[64];  /*记录事件标志*/
    byte EventRate[64];  /*事件等级标志*/
}str_AFN0A_F9;
typedef struct str_AFN0A_F10_METERINFO_t
{
    unsigned short Index;             /*电表交采序号*/
    unsigned short CLD;               /*所属测量点号*/
    byte Port;              /*485抄表端口*/
    byte SpeedIndex;        /*485速率*/
    byte StatuteIndex;      /*规约序号*/
    str_add12 MeterAdd;      /*表地址*/
    short MeterAddisnull;    /*表地址为空标志*/
    uchar password[6];       /*密码*/
    byte XSW;               /*小数位数 (1~4)*/
    byte ZSW;               /*整数位数 (4~7)*/
    byte FLS;               /*费率数   (1~14)*/
    str_add12 CJQAdd;      /*所属采集器通信地址*/
    short     CJQAddisnull;    /*采集器地址为空标志*/
    byte     DLH;               /*用户大类号*/
    byte     XLH;               /*用户小类号*/
}str_AFN0A_F10_METERINFO;

typedef struct str_AFN0A_F10_t
{
    unsigned short MeterNumber;       /*本次配置电表数量*/
    str_AFN0A_F10_METERINFO MeterInfo[2040];  /*本次配置的电表参数数组*/
}str_AFN0A_F10;

int decode_afn0A_F1(uchar *data, str_AFN0A_F1 *astr_val, int *ai_step);
int decode_afn0A_F2(uchar *data, str_AFN0A_F2 *astr_val, int *ai_step);
int decode_afn0A_F3(uchar *data, str_AFN0A_F3 *astr_val, int *ai_step);
int decode_afn0A_F4(uchar *data, str_AFN0A_F4 *astr_val, int *ai_step);
int decode_afn0A_F5(uchar *data, str_AFN0A_F5 *astr_val, int *ai_step);
int decode_afn0A_F6(uchar *data, str_AFN0A_F6 *astr_val, int *ai_step);
int decode_afn0A_F7(uchar *data, str_AFN0A_F7 *astr_val, int *ai_step);
int decode_afn0A_F8(uchar *data, str_AFN0A_F8 *astr_val, int *ai_step);
int decode_afn0A_F9(uchar *data, str_AFN0A_F9 *astr_val, int *ai_step);
int decode_afn0A_F10(uchar *data, str_AFN0A_F10 *astr_val, int *ai_step);


#endif

