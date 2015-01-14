

#ifndef DECODE_AFN10_FN1_13_H
#define DECODE_AFN10_FN1_13_H

#include "../public/decode_public.h"


typedef struct str_AFN10_F1_t
{
    uchar dkh;      //端口号
    uchar nrlen;      //内容长度
    uchar val[256];
}str_AFN10_F01;

typedef struct str_AFN10_F9_t
{
    uchar dkh;      //端口号
    str_add12 TargetAdd; //转发目标地址
    short TargetAddisNull;
    uchar mark;//转发结果标志
    uchar nrlen;      //内容长度
    uchar datasymbol[4];
    uchar val[256];
}str_AFN10_F09;


typedef struct str_AFN10_F10_t
{
    uchar dkh;      //端口号
    str_add12 TargetAdd; //转发目标地址
    short TargetAddisNull;
    uchar mark;//转发结果标志
    uchar tripmark;//跳闸/合闸标志
}str_AFN10_F10;

typedef struct str_AFN10_F11_t
{
    uchar dkh;      //端口号
    str_add12 TargetAdd; //转发目标地址
    short TargetAddisNull;
    uchar mark;//转发结果标志
    uchar sendingmark;//送电标志
}str_AFN10_F11;

typedef struct str_AFN10_F13_t
{
    uchar taskmark;      //任务类型
    short ter_number;        //批量执行对电表的任务中电表总数量    
    short succ_ter_number; //成功的电表数量
    uchar Table_no[2040][8];      //成功的表号
}str_AFN10_F13;

int decode_afn10_F01(uchar *data, str_AFN10_F01 *astr_val, int *ai_step);
int decode_afn10_F09(uchar *data, str_AFN10_F09 *astr_val, int *ai_step);
int decode_afn10_F10(uchar *data, str_AFN10_F10 *astr_val, int *ai_step);
int decode_afn10_F11(uchar *data, str_AFN10_F11 *astr_val, int *ai_step);
int decode_afn10_F13(uchar *data, str_AFN10_F13 *astr_val, int *ai_step);

#endif