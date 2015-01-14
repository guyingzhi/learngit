#ifndef DECODE_AFN0A_FN11_24_H
#define DECODE_AFN0A_FN11_24_H

#include "../public/decode_public.h"



typedef struct str_AFN0A_F11_PULSEINFO_t
{
    byte port;             /*�������˿�*/
    byte CLD;              /*����������*/
    byte PulseType;        /*�������� 0�����й� 1 �����޹� 2 �����й� 3 �����޹�*/
    unsigned short KVal;    /*K����*/
}str_AFN0A_F11_PULSEINFO;

typedef struct str_AFN0A_F11_t
{
    byte PulseNumber;      /*������������������*/
    str_AFN0A_F11_PULSEINFO pulseinfo[64];  /*���������ò�������*/
}str_AFN0A_F11;

typedef struct str_AFN0A_F12_t
{
    byte BinaryState[8];
    byte BinaryProperty[8];
}str_AFN0A_F12;

typedef struct str_AFN0A_F13_IMITATIONINFO_t
{
    byte port;             /*ģ�����˿�*/
    byte CLD;              /*����������*/
    byte ImitationType;    /*���� 0 A���ѹ 1 B���ѹ 2 C���ѹ
                                   3 A����� 4 B����� 5 C�����*/
}str_AFN0A_F13_IMITATIONINFO;

typedef struct str_AFN0A_F13_t
{
    byte imitationNumber;      /*��������ģ��������*/
    str_AFN0A_F13_IMITATIONINFO imitationinfo[64];  /*ģ�������ò�������*/
}str_AFN0A_F13;

typedef struct str_AFN0A_F14_ADDGROUPINFO_t
{
    byte addgroupindex;             /*�ܼ������*/
    byte CLDnumber;                 /*����������*/
    byte CLD[255];                  /*����������*/
    byte CLDdirection[255];         /*����*/
    byte CLDoperator[255];          /*�����*/
}str_AFN0A_F14_ADDGROUPINFO;

typedef struct str_AFN0A_F14_t
{
    byte addgroupnumber;                /*�ܼ�������*/
    str_AFN0A_F14_ADDGROUPINFO addgroupinfo[64];  /*�ܼ�����������*/
}str_AFN0A_F14;

typedef struct str_AFN0A_F15_DIFFINFO_t
{
    byte diffnum;                    /*����*/
    byte contrastnum;                /*�Ա��ܼ����*/
    byte referencenum;               /*�����ܼ����*/
    byte Timespan;                   /*ʱ����*/
    byte contrasttype;               /*�Աȷ���*/
    byte Relativeval;                /*�Ա����ֵ*/
    short Relativeisnull;            /*�Ա����ֵ�п�*/
    int Absoluteval;                 /*�ԱȾ���ֵ*/
    short Absoluteisnull;            /*�ԱȾ���ֵ�п�*/
}str_AFN0A_F15_DIFFINFO;

typedef struct str_AFN0A_F15_t
{
    byte diffnumber;                /*�������*/
    str_AFN0A_F15_DIFFINFO diffinfo[255];  /*�����������*/
}str_AFN0A_F15;

typedef struct str_AFN0A_F16_t
{
    uchar AFNuser[32];                /*AFN�û���*/
    uchar AFNpassword[32];            /*AFN����*/
}str_AFN0A_F16;
typedef struct str_AFN0A_F17_t
{
    double val;        /*�ն˱�����ֵ*/
    short isnull;      /*������ֵ�пձ�־*/
}str_AFN0A_F17;

typedef struct str_AFN0A_F18_t
{
    byte Periodstate[48];      /*ʱ�α�־ 0 ������ 1 ����1 2 ����2 3 ����*/
}str_AFN0A_F18;

typedef struct str_AFN0A_FLOATFACATOR_t
{
    int val;           /*����ϵ��*/
    short isnull;      /*����ϵ���пձ�־*/
}str_AFN0A_FLOATFACATOR;

typedef struct str_AFN0A_F21_t
{
    byte FLstate[48];      /*ʱ�α�־ 0~13 ��ʾ1��14����*/
    byte FLS;              /*������*/
    short FLSisnull;        /*������Ϊ�ձ�־*/
}str_AFN0A_F21;

typedef struct str_AFN0A_F22_t
{
    byte FLS;              /*������*/
    int FL[14];      /*����*/
    short FLisnull[14]; /*����Ϊ�ձ�־*/
}str_AFN0A_F22;

typedef struct str_AFN0A_F23_t
{
    byte alarm[24]; /*�߷Ѹ澯��־*/
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

