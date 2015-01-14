

#ifndef DECODE_AFN10_FN1_13_H
#define DECODE_AFN10_FN1_13_H

#include "../public/decode_public.h"


typedef struct str_AFN10_F1_t
{
    uchar dkh;      //�˿ں�
    uchar nrlen;      //���ݳ���
    uchar val[256];
}str_AFN10_F01;

typedef struct str_AFN10_F9_t
{
    uchar dkh;      //�˿ں�
    str_add12 TargetAdd; //ת��Ŀ���ַ
    short TargetAddisNull;
    uchar mark;//ת�������־
    uchar nrlen;      //���ݳ���
    uchar datasymbol[4];
    uchar val[256];
}str_AFN10_F09;


typedef struct str_AFN10_F10_t
{
    uchar dkh;      //�˿ں�
    str_add12 TargetAdd; //ת��Ŀ���ַ
    short TargetAddisNull;
    uchar mark;//ת�������־
    uchar tripmark;//��բ/��բ��־
}str_AFN10_F10;

typedef struct str_AFN10_F11_t
{
    uchar dkh;      //�˿ں�
    str_add12 TargetAdd; //ת��Ŀ���ַ
    short TargetAddisNull;
    uchar mark;//ת�������־
    uchar sendingmark;//�͵��־
}str_AFN10_F11;

typedef struct str_AFN10_F13_t
{
    uchar taskmark;      //��������
    short ter_number;        //����ִ�жԵ��������е��������    
    short succ_ter_number; //�ɹ��ĵ������
    uchar Table_no[2040][8];      //�ɹ��ı��
}str_AFN10_F13;

int decode_afn10_F01(uchar *data, str_AFN10_F01 *astr_val, int *ai_step);
int decode_afn10_F09(uchar *data, str_AFN10_F09 *astr_val, int *ai_step);
int decode_afn10_F10(uchar *data, str_AFN10_F10 *astr_val, int *ai_step);
int decode_afn10_F11(uchar *data, str_AFN10_F11 *astr_val, int *ai_step);
int decode_afn10_F13(uchar *data, str_AFN10_F13 *astr_val, int *ai_step);

#endif