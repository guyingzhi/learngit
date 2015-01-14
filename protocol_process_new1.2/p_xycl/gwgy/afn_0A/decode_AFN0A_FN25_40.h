#ifndef DECODE_AFN0A_FN25_40_H
#define DECODE_AFN0A_FN25_40_H

#include "../public/decode_public.h"


typedef struct str_AFN0A_F25_t   /*A��ԼF25����*/
{
    unsigned short PT, CT;           /*����������*/
    double limitU,maxI,limitFH;     /*���ѹ��������,�����*/
    short limitUisnull,maxIisnull,limitFHisnull;     /*���ѹ���������п�,������п�*/
    byte DYConnection;       /*��Դ���߷�ʽ����ֵ1��3���α�ʾ�������ߡ��������ߡ������*/
    byte Connection;       /*���߷�ʽ 1�������� 2�������� 3�����*/
}str_AFN0A_F25;

typedef struct str_AFN0A_F26_VAL_t   /*A��ԼF26����*/
{
    double limitU;          /*��ѹ�ϸ�����*/
    double lowerU;          /*��ѹ�ϸ�����*/
    double breakphaseU;     /*��ѹ��������*/
    double ceilinglimitU;   /*��ѹ�����ޣ���ѹ���ޣ�*/
    byte   ceilinglimitUtime;   /*Խ�޳���ʱ��*/
    double ceilinglimitUxs;   /*Խ�޻ָ�ϵ��*/
    double lowerlimitU;     /*��ѹ�����ޣ�Ƿѹ���ޣ�*/
    byte   lowerlimitUtime;   /*Խ�޳���ʱ��*/
    double lowerlimitUxs;   /*Խ�޻ָ�ϵ��*/
    double ceilinglimitI;   /*����������ޣ��������ޣ�*/
    byte   ceilinglimitItime;   /*Խ�޳���ʱ��*/
    double ceilinglimitIxs;   /*Խ�޻ָ�ϵ��*/
    double limitI;          /*��������ޣ���������ޣ�*/
    byte   limitItime;   /*Խ�޳���ʱ��*/
    double limitIxs;   /*Խ�޻ָ�ϵ��*/
    double limitIzero;      /*�����������*/
    byte   limitIzerotime;   /*Խ�޳���ʱ��*/
    double limitIzeroxs;   /*Խ�޻ָ�ϵ��*/
    double ceilinglimitP;   /*���ڹ���������*/
    byte   ceilinglimitPtime;   /*Խ�޳���ʱ��*/
    double ceilinglimitPxs;   /*Խ�޻ָ�ϵ��*/
    double limitP;          /*���ڹ�������*/
    byte   limitPtime;   /*Խ�޳���ʱ��*/
    double limitPxs;   /*Խ�޻ָ�ϵ��*/
    double unbalanceU;      /*�����ѹ��ƽ����ֵ*/
    byte   unbalanceUtime;   /*Խ�޳���ʱ��*/
    double unbalanceUxs;   /*Խ�޻ָ�ϵ��*/
    double unbalanceI;      /*���������ƽ����ֵ*/
    byte   unbalanceItime;   /*Խ�޳���ʱ��*/
    double unbalanceIxs;   /*Խ�޻ָ�ϵ��*/
    byte loseUtme;         /*����ʧѹʱ����ֵ*/
}str_AFN0A_F26_VAL;

typedef struct str_AFN0A_F26_ISNULL_t   /*A��ԼF26�п�*/
{
    short limitU;         /*��ѹ�ϸ������пձ�־*/
    short lowerU;          /*��ѹ�ϸ����ޱ�־*/
    short breakphaseU;     /*��ѹ�������ޱ�־*/
    short ceilinglimitU;   /*��ѹ�����ޱ�־*/
    short ceilinglimitUtime;   /*Խ�޳���ʱ��*/
    short ceilinglimitUxs;   /*Խ�޻ָ�ϵ��*/
    short lowerlimitU;     /*��ѹ�����ޱ�־*/
    short lowerlimitUtime;   /*Խ�޳���ʱ��*/
    short lowerlimitUxs;   /*Խ�޻ָ�ϵ��*/
    short ceilinglimitI;   /*����������ޱ�־*/
    short ceilinglimitItime;   /*Խ�޳���ʱ��*/
    short ceilinglimitIxs;   /*Խ�޻ָ�ϵ��*/
    short limitI;          /*��������ޱ�־*/
    short limitItime;   /*Խ�޳���ʱ��*/
    short limitIxs;   /*Խ�޻ָ�ϵ��*/
    short limitIzero;      /*����������ޱ�־*/
    short   limitIzerotime;   /*Խ�޳���ʱ��*/
    short limitIzeroxs;   /*Խ�޻ָ�ϵ��*/
    short ceilinglimitP;   /*���ڹ��������ޱ�־*/
    short ceilinglimitPtime;   /*Խ�޳���ʱ��*/
    short ceilinglimitPxs;   /*Խ�޻ָ�ϵ��*/
    short limitP;          /*���ڹ������ޱ�־*/
    short   limitPtime;   /*Խ�޳���ʱ��*/
    short limitPxs;   /*Խ�޻ָ�ϵ��*/
    short unbalanceU;      /*�����ѹ��ƽ����ֵ��־*/
    short   unbalanceUtime;   /*Խ�޳���ʱ��*/
    short unbalanceUxs;   /*Խ�޻ָ�ϵ��*/
    short unbalanceI;      /*���������ƽ����ֵ��־*/
    short   unbalanceItime;   /*Խ�޳���ʱ��*/
    short unbalanceIxs;   /*Խ�޻ָ�ϵ��*/
    short loseUtme;        /*����ʧѹʱ����ֵ��־*/
}str_AFN0A_F26_ISNULL;

typedef struct str_AFN0A_F26_t   /*A��ԼF26����������������ݼ��пձ�־*/
{
    str_AFN0A_F26_VAL val;        /*���ݽṹ*/
    str_AFN0A_F26_ISNULL isnull;  /*�пձ�־�ṹ*/
}str_AFN0A_F26;

typedef struct str_AFN0A_F27_t   /*A��ԼF27�������*/
{
    double tctc[12];      /*����ͭ�����*/
    short  tctcisnull[12];      /*����ͭ������п�*/
}str_AFN0A_F27;
//typedef struct str_AFN0A_F27_t   /*A��ԼF27�������*/
//{
//    byte DJnumber;         /*������Ϣ��ʶ����*/
//    byte FN[255];          /*������Ϣ��ʶ*/
//    str_MD MD[255];         /*�����ܶ�*/
//}str_AFN0A_F27;

typedef struct str_AFN0A_F28_t   /*A��ԼF28�������*/
{
    double limit1;         /*���������ֶ���ֵ1*/
    double limit2;         /*���������ֶ���ֵ2*/
    short limit1isnull,limit2isnull; /*�пձ�־*/
}str_AFN0A_F28;

typedef struct str_AFN0A_F29_t   /*A��ԼF28�������*/
{
    char xsh[13];         /*�ն˵��ص��ܱ���ʾ��*/
}str_AFN0A_F29;

typedef struct str_AFN0A_F31_t   /*A��ԼF28�������*/
{
    byte        Number;
    str_add12   MeterAdd[20];      /*�ӽڵ㸽���ڵ��ַ*/
    short       MeterAddisnull[20];    /*�ӽڵ㸽���ڵ��ַΪ�ձ�־*/
}str_AFN0A_F31;
typedef struct str_AFN0A_F33_VAL_t   /*A��ԼF1����*/
{
    byte port;              /*�ն�ͨ�Ŷ˿ں�*/
    char ztz[16];           /*̨�����г������п�����, 1 Ҫ���á�0����Ҫ��,��D0ȡ����*/
    char day[32];           /*������-����*/
    datetime cbsj;           /*������-ʱ��*/
    short cbsjisnull;
    byte cbjg;              /*������ʱ��*/
    datetime jssj;           /*�Ե��㲥Уʱ��ʱʱ��*/
    short jssjisnull;
    byte  sdnumber;              /*������ʱ����m*/
    datetime cbsd[50];           /*������-ʱ��*/
    short cbsdisnull[50];
}str_AFN0A_F33_VAL;

typedef struct str_AFN0A_F33_t  /*A��ԼF1�ṹ�壬������������пձ�־*/
{
    byte                number;          /*�������õĲ��������n*/
    str_AFN0A_F33_VAL   val[32];         /*������*/
}str_AFN0A_F33;

typedef struct str_AFN0A_F34_VAL_t   /*A��ԼF1����*/
{
    byte port;              /*�ն�ͨ�Ŷ˿ں�*/
    byte ztz[8];           /*̨�����г������п�����, 1 Ҫ���á�0����Ҫ��*/
    unsigned int txsl;       /*ͨѶ����*/
}str_AFN0A_F34_VAL;

typedef struct str_AFN0A_F34_t  /*A��ԼF1�ṹ�壬������������пձ�־*/
{
    byte                number;          /*�������õĲ��������n*/
    str_AFN0A_F34_VAL   val[32];         /*������*/
}str_AFN0A_F34;

typedef struct str_AFN0A_F35_t
{
    byte     zdhgs;          /*�ص㻧����*/
    ushort    setxh[2048];    /*װ�����*/
}str_AFN0A_F35;

typedef struct str_AFN0A_F37_t
{
    byte     port;          /*�ն˼���ͨ�Ŷ˿ں�*/
    byte     kzz[8];    /*�ն˼���ͨ�ſ�����*/
    byte     bwtimeout;          /*���յȴ����ĳ�ʱʱ��*/
    byte     jstimeout;          /*���յȴ��ֽڳ�ʱʱ��*/
    byte     recs;          /*������������վ������ʧ���ط�����*/
    byte     xczq;          /*����Ѳ������*/
    byte     jldx;          /*����/��������־*/
    byte     number;          /*����/��������־�������Ӧ�ı�����/�������ն˸���n*/
    ushort   xzqhm[255];      /*��n�����������ն�����������*/
    ushort   zddz[255];         /*��n�����������ն˵�ַ*/
}str_AFN0A_F37;

typedef struct str_AFN0A_F38F39_VAL_t   /*A��ԼF1����*/
{
    byte     xlh;              /*�û�С���*/
    byte     xxlzs;            /*��Ϣ������n*/
    byte     xxlbz[248];     /*����Ϣ��������Ӧ����Ϣ��Ԫ��־λ*/
}str_AFN0A_F38F39_VAL;

typedef struct str_AFN0A_F38F39_t
{
    byte     dlh;               /*�û������*/
    byte     zs;               /*����*/
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
