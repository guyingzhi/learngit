#ifndef DECODE_AFN0A_FN1_10_H
#define DECODE_AFN0A_FN1_10_H

#include "../public/decode_public.h"


typedef struct str_AFN0A_F1_VAL_t   /*A��ԼF1����*/
{
    byte RTS;              /*RTS*/
    byte PDelay;           /*����վ��������ʱ*/
    unsigned short CTimeout;           /*�Ӷ�վ��Ӧ��ʱʱ��*/
    byte RTimes;           /*�ط�����*/
    byte con1;             /*��Ҫ�¼�ȷ�ϱ�־*/
    byte con2;             /*һ���¼�ȷ�ϱ�־*/
    byte con3;             /*3�������Զ��ϱ���־*/
    byte HCycle;           /*��������*/
}str_AFN0A_F1_VAL;

typedef struct str_AFN0A_F1_ISNULL_t  /*A��ԼF1�пգ�1Ϊ�գ�0Ϊ�ǿ�*/
{
    short RTS;               /*RTS�пձ�־*/
    short PDelay;            /*����վ��������ʱ�пձ�־*/
    short CTimeout;          /*�Ӷ�վ��Ӧ��ʱʱ���пձ�־*/
    short RTimes;            /*�ط������пձ�־*/
    short con1;              /*��Ҫ�¼�ȷ���пձ�־*/
    short con2;              /*һ���¼�ȷ���пձ�־*/
    short con3;              /*3�������Զ��ϱ���־*/
    short HCycle;            /*���������пձ�־*/
}str_AFN0A_F1_ISNULL;

typedef struct str_AFN0A_F1_t  /*A��ԼF1�ṹ�壬������������пձ�־*/
{
    str_AFN0A_F1_VAL val;         /*������*/
    str_AFN0A_F1_ISNULL isnull;   /*�пձ�־*/
}str_AFN0A_F1;

typedef struct str_AFN0A_F2_t
{
    byte ForwardNumber;        /*��ת�����ն��� 0~127*/
    byte Forward;              /*�����ֹת����־*/
    unsigned short ForwardAddress[255];  /*��ת�����ն˵�ַ����*/
}str_AFN0A_F2;

typedef struct str_AFN0A_F3_t
{
    uchar MainIP[16];        /*����IP*/
    unsigned short MainSOCKET;        /*���ö˿�*/
    uchar STBYIP[16];        /*����IP*/
    unsigned short STBYSOCKET;        /*���ö˿�*/
    uchar APN[17];           /*APN*/
}str_AFN0A_F3;

typedef struct str_AFN0A_F4_t
{
    uchar MSAPhone[17];     /*��վ�绰����*/
    uchar SMSPhone[17];     /*�������ĺ���*/
}str_AFN0A_F4;

typedef struct str_AFN0A_F5_t
{
    byte MesNum;              /*��Ϣ��֤��*/
    unsigned short MesPar;    /*��Ϣ��֤����*/
}str_AFN0A_F5;

typedef struct str_AFN0A_F6_t
{
    unsigned short Address[8];     /*�ն����ַ*/
}str_AFN0A_F6;

typedef struct str_AFN0A_F7_t
{
    byte zdIP[16];        /*�ն�IP*/
    byte zwYM[16];        /*��������*/
    byte WG[16];          /*����*/
    byte dllx;           /*��������*/
    byte dlIP[16];       /*����IP*/
    unsigned short dlSOCKET;      /*����˿�*/
    byte ljfs;           /*�������ӷ�ʽ*/
    byte nmlen;          /*�û�������*/
    char  name[21];       /*�û���*/
    byte pwlen;          /*���볤��*/
    char  pw[21];         /*����*/
    unsigned short zdSOCKET;       /*�ն������˿�*/
}str_AFN0A_F7;

typedef struct str_AFN0A_F8_t
{
    byte onlinetype;        /*��������ģʽ��ȡֵ��Χ1��3���α�ʾ��������ģʽ����������ģʽ��ʱ������ģʽ*/
    byte worktype;         /*�ն˵����ֹ���ģʽ��ȡֵ��Χ0��2���α�ʾ���ģʽ���ͻ���ģʽ��������ģʽ*/
    byte sockettype;         /*�á�0��ΪTCP���á�1��ΪUDP*/
    unsigned short retelstep;  /*��������ģʽ�ز����*/
    byte reteltimes;       /*��������ģʽ�ز�����*/
    byte distime;          /*��������ģʽ������ͨ���Զ�����ʱ��*/
    byte onlinetime[24];          /*ʱ������ģʽ��������ʱ�α�־*/
}str_AFN0A_F8;

typedef struct str_AFN0A_F9_t
{
    byte SaveEvent[64];  /*��¼�¼���־*/
    byte EventRate[64];  /*�¼��ȼ���־*/
}str_AFN0A_F9;
typedef struct str_AFN0A_F10_METERINFO_t
{
    unsigned short Index;             /*��������*/
    unsigned short CLD;               /*�����������*/
    byte Port;              /*485����˿�*/
    byte SpeedIndex;        /*485����*/
    byte StatuteIndex;      /*��Լ���*/
    str_add12 MeterAdd;      /*���ַ*/
    short MeterAddisnull;    /*���ַΪ�ձ�־*/
    uchar password[6];       /*����*/
    byte XSW;               /*С��λ�� (1~4)*/
    byte ZSW;               /*����λ�� (4~7)*/
    byte FLS;               /*������   (1~14)*/
    str_add12 CJQAdd;      /*�����ɼ���ͨ�ŵ�ַ*/
    short     CJQAddisnull;    /*�ɼ�����ַΪ�ձ�־*/
    byte     DLH;               /*�û������*/
    byte     XLH;               /*�û�С���*/
}str_AFN0A_F10_METERINFO;

typedef struct str_AFN0A_F10_t
{
    unsigned short MeterNumber;       /*�������õ������*/
    str_AFN0A_F10_METERINFO MeterInfo[2040];  /*�������õĵ���������*/
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

