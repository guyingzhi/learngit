#ifndef DECODE_AFN0A_FN41_150_H
#define DECODE_AFN0A_FN41_150_H

#include "../public/decode_public.h"

typedef struct str_AFN0A_PROGRAM_t
{
    byte periodnumber[8];        /*ʱ����Ч��־*/
    double valuation[8];          /*��Ӧʱ�ζ�ֵ*/
    short isnull[8];              /*��Ӧʱ�ζ�ֵ�пձ�־*/
}str_AFN0A_PROGRAM;

typedef struct str_AFN0A_F41_t
{
    str_AFN0A_PROGRAM program[3];   /*��������*/
    byte programstate[3];          /*������Ч��־*/
}str_AFN0A_F41;

typedef struct str_AFN0A_F42_t
{
    double facval;              /*���ݶ�ֵ*/
    short facvalisnull;         /*���ݶ�ֵ�пձ�־*/
    datetime starttime;         /*�޵���ʼʱ��*/
    short starttimeisnull;      /*�޵���ʼʱ���пձ�־*/
    byte  duration;            /*����ʱ��*/
    byte  weekday[7];           /*���޵���*/
}str_AFN0A_F42;

typedef struct str_AFN0A_F44_VAL_t
{
    datetime starttime;     /*��ͣ��ʼʱ��*/
    datetime stoptime;      /*��ͣ����ʱ��*/
    double Pval;            /*��ͣ���ʶ�ֵ*/
}str_AFN0A_F44_VAL;

typedef struct str_AFN0A_F44_ISNULL_t
{
    short starttime;     /*��ͣ��ʼʱ���пձ�־*/
    short stoptime;      /*��ͣ����ʱ���пձ�־*/
    short Pval;          /*��ͣ���ʶ�ֵ�пձ�־*/
}str_AFN0A_F44_ISNULL;

typedef struct str_AFN0A_F44_t
{
    str_AFN0A_F44_VAL val;     /*��ͣ��ʼʱ���пձ�־*/
    str_AFN0A_F44_ISNULL isnull;      /*��ͣ����ʱ���пձ�־*/
}str_AFN0A_F44;

typedef struct str_AFN0A_ROUND_t
{
    uchar round[8];           /*�ִα�־*/
}str_AFN0A_ROUND;

typedef struct str_AFN0A_F46_t
{
    int val;                /*�µ�ض�ֵ*/
    short valisnull;        /*�µ�ض�ֵ�пձ�־*/
}str_AFN0A_F46;

typedef struct str_AFN0A_F47_t
{
    int GDDno;              /*���絥��*/
    byte GDtype;           /*��������,1Ϊ����,2Ϊˢ��,0Ϊ��Ч*/
    int GDval;              /*����ֵ*/
    short GDvalisnull;      /*����ֵ�пձ�־*/
    int alarmlimit;         /*��������*/
    short alarmlimitisnull; /*���������пձ�־*/
    int triplimit;          /*��բ����*/
    short triplimitisnull;  /*��բ�����пձ�־*/
}str_AFN0A_F47;
typedef struct str_AFN0A_F57_t
{
    byte alarmsound[24];           /*�����澯��־*/
}str_AFN0A_F57;

typedef struct str_AFN0A_F59_t
{
    double difflimit;       /*������ֵ*/
    short difflimitisnull;  /*������ֵ�пձ�־*/
    double flewlimit;       /*������ֵ*/
    short  flewlimitisnull; /*������ֵ�пձ�־*/
    byte stoplimit;        /*ͣ����ֵ*/
    unsigned short correctionlimit;  /*Уʱ��ֵ*/
}str_AFN0A_F59;

typedef struct str_AFN0A_F60_VAL_t
{
    double harmonicUZ;      /*�ܵ�ѹ����������*/
    double harmonicUodd;    /*��ε�ѹ����������*/
    double harmonicUeven;   /*ż�ε�ѹ����������*/
    double harmonicU[19];   /*��ѹ��Чֵ����*/
    double harmonicIZ;      /*�ܵ�������������*/
    double harmonicI[19];   /*������Чֵ����*/
}str_AFN0A_F60_VAL;

typedef struct str_AFN0A_F60_ISNULL_t
{
    short harmonicUZ;       /*�ܵ�ѹ�����������пձ�־*/
    short harmonicUodd;     /*��ε�ѹ�����������пձ�־*/
    short harmonicUeven;    /*ż�ε�ѹ�����������пձ�־*/
    short harmonicU[19];    /*��ѹ��Чֵ�����пձ�־*/
    short harmonicIZ;       /*�ܵ��������������пձ�־*/
    short harmonicI[19];    /*������Чֵ�����пձ�־*/
}str_AFN0A_F60_ISNULL;

typedef struct str_AFN0A_F60_t
{
    str_AFN0A_F60_VAL val;
    str_AFN0A_F60_ISNULL isnull;
}str_AFN0A_F60;

typedef struct str_AFN0A_F61_t
{
    byte analogflag[8];    /*ģ���������־*/
}str_AFN0A_F61;


typedef struct str_AFN0A_LOWVOLINFO_t
{
    unsigned short meterindex;   /*������*/
    byte metertype;    /*�������*/
    str_add12 meteradd; /*��ַ*/
    unsigned short Kval;         /*�����*/
    unsigned short collectoradd; /*�����ɼ�����ַ*/
    byte port;         /*�ɼ����˿�*/
    byte focustype;    /*�Ƿ��ص㻧*/
    byte Gateflag;     /*����բ��־*/
    byte stopflag;     /*ͣ�ñ�־*/
    byte statuteindex; /*��Լ����*/
    byte PpowerZflag;  /*�����й�����ʾֵ���ձ�־*/
    byte QpowerZflag;  /*�����޹�����ʾֵ���ձ�־*/
    byte PpowerFflag;  /*�����й�����ʾֵ���ձ�־*/
    byte QpowerFflag;  /*�����޹�����ʾֵ���ձ�־*/
    byte Uflag;        /*�����ѹ���ձ�־*/
    byte Iflag;        /*����������ձ�־*/
    byte Pflag;        /*�ܼ������й����ձ�־*/
    byte Qflag;        /*�ܼ������޹����ձ�־*/
    byte readstep;     /*������*/
    byte metermedian;  /*��λ��*/
}str_AFN0A_LOWVOLINFO;

typedef struct str_AFN0A_F65F66_t
{
    byte cycleunit;        /*���ڵ�λ 0 �� 1 ʱ 2 �� 3 ��*/
    byte cycle;            /*��������*/
    datetime marktime;      /*��׼ʱ��*/
    short marktimeisnull;   /*��׼ʱ���пձ�־*/
    byte Rval;             /*��ȡ����*/
    byte Nval;             /*���ݵ�Ԫ��ʶ����*/
    byte PN[255];          /*���ݵ�Ԫ��ʶPN*/
    byte FN[255];          /*���ݵ�Ԫ��ʶFN*/
}str_AFN0A_F65F66;

typedef struct str_AFN0A_F73_t
{
    uchar BCFS[16][4]; /* ������ʽ/A��/B��/C��*/
    double DRRL[16];
    short DRRLisnull[16];
}str_AFN0A_F73;

typedef struct str_AFN0A_F74_t
{
    double MBGVYS;            /*Ŀ�깦������*/
    short   MBGVYSisnull;
    double TRWGGV;           /*Ͷ���޹���������*/
    short    TRWGGVisnull;
    double QCWGGV;           /*�г��޹���������*/
    short    QCWGGVisnull;
    uchar    YSSJ;                /*��ʱʱ��*/
    uchar    SJJG;                /*����ʱ����*/
    
}str_AFN0A_F74;

typedef struct str_AFN0A_F75_val_t
{
    double GDY;                                      //����ѹ
    double GDYHCZ;                                //����ѹ�ز�ֵ
    double QDY;                                      //Ƿ��ѹ
    double QDYHCZ;                                //Ƿ��ѹ�ز�ֵ
    double DLHYL;                                   //�ܻ����������������
    double DLHYLHC;                               //�ܻ������������Խ�޻ز�ֵ
    double DYHYL;                                   //�ܻ����ѹ����������
    double DYHYLHC;                               //�ܻ����ѹ������Խ�޻ز�ֵ
    
}str_AFN0A_F75_val;
typedef struct str_AFN0A_F75_isnull_t
{
    double GDY;
    double GDYHCZ;
    double QDY;
    double QDYHCZ;
    double DLHYL;
    double DLHYLHC;
    double DYHYL;
    double DYHYLHC;
    
}str_AFN0A_F75_isnull;

typedef struct str_AFN0A_75_t
{
    str_AFN0A_F75_val  val;
    str_AFN0A_F75_isnull  isnull;
}str_AFN0A_75;

typedef struct str_AFN0A_81_val_t
{
    double ZLQSZ;                                    //ֱ��ģ������ʼֵ
    double ZLZSZ;                                     //ֱ��ģ������ֵֹ
}str_AFN0A_81_val;

typedef struct str_AFN0A_81_isnull_t
{
    double ZLQSZ;                                    
    double ZLZSZ;                                     
}str_AFN0A_81_isnull;
typedef struct str_AFN0A_81_t
{
    str_AFN0A_81_val val;
    str_AFN0A_81_isnull  isnull;                                   
}str_AFN0A_81;

typedef struct str_AFN0A_82_val_t
{
    double ZLS;                                    //ֱ��ģ��������
    double ZLX;                                     //ֱ��ģ��������
}str_AFN0A_82_val;
typedef struct str_AFN0A_82_isnull_t
{
    double ZLS;                                    
    double ZLX;                                     
}str_AFN0A_82_isnull;
typedef struct str_AFN0A_82_t
{
    str_AFN0A_82_val val;
    str_AFN0A_82_isnull  isnull;                                   
}str_AFN0A_82;


typedef struct str_AFN0A_89_t
{
    int XZBM;                   //��������
    int ZDDZ;                   //�ն˵�ַ
}str_AFN0A_89;

typedef struct str_AFN0A_90_t
{
    uchar WXXDZ;                                        //�����ŵ���
    uchar WXFSGL;                                       //�������緢�书��
}str_AFN0A_90;    

typedef struct str_AFN0A_91_t
{
    uchar longitude ;                                        //����
    uchar latitude;                                           //γ��
}str_AFN0A_91;   



typedef struct str_AFN0A_150_t
{
    uchar Pn_mark[255][8];                       //255���������Ч��־λ
    uchar Pn_change_mark[255][8];            //255���������������־
}str_AFN0A_150;

int decode_afn0A_F41(uchar *data, str_AFN0A_F41 *astr_val, int *ai_step);
int decode_afn0A_F42(uchar *data, str_AFN0A_F42 *astr_val, int *ai_step);
int decode_afn0A_F43(uchar *data, uchar *ac_val, int *ai_step);
int decode_afn0A_F44(uchar *data, str_AFN0A_F44 *astr_val, int *ai_step);
int decode_afn0A_GETROUND(uchar *data, str_AFN0A_ROUND *astr_val, int *ai_step);
int decode_afn0A_F46(uchar *data, str_AFN0A_F46 *astr_val, uchar *ac_unit, int *ai_step);
int decode_afn0A_F47(uchar *data, str_AFN0A_F47 *astr_val, int *ai_step);
int decode_afn0A_F49(uchar *data, uchar *ac_val, int *ai_step);
int decode_afn0A_F57(uchar *data, str_AFN0A_F57 *astr_val, int *ai_step);
int decode_afn0A_F58(uchar *data, uchar *lc_val, int *ai_step);
int decode_afn0A_F59(uchar *data, str_AFN0A_F59 *astr_val, int *ai_step);
int decode_afn0A_F60(uchar *data, str_AFN0A_F60 *astr_val, int *ai_step);
int decode_afn0A_F61(uchar *data, str_AFN0A_F61 *astr_val, int *ai_step);
int decode_afn0A_F65F66(uchar *data, str_AFN0A_F65F66 *astr_val,uchar ai_AFN, int *ai_step);
int decode_afn0A_F67F68(uchar *data, uchar *ac_val, int *ai_step);
int decode_afn0A_F73(uchar *data, str_AFN0A_F73 *astr_val, int *ai_step);
int decode_afn0A_F74(uchar *data, str_AFN0A_F74 *astr_val, int *ai_step);
int decode_afn0A_F75(uchar *data, str_AFN0A_75 *astr_val, int *ai_step);
int decode_afn0A_F81(uchar *data, str_AFN0A_81 *astr_val, int *ai_step);
int decode_afn0A_F82(uchar *data, str_AFN0A_82 *astr_val, int *ai_step);
int decode_afn0A_F150(uchar *data, str_AFN0A_150 *astr_val, int *ai_step);


#endif
