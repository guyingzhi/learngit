#ifndef DECODE_AFN0A_FN41_150_H
#define DECODE_AFN0A_FN41_150_H

#include "../public/decode_public.h"

typedef struct str_AFN0A_PROGRAM_t
{
    byte periodnumber[8];        /*时段有效标志*/
    double valuation[8];          /*对应时段定值*/
    short isnull[8];              /*对应时段定值判空标志*/
}str_AFN0A_PROGRAM;

typedef struct str_AFN0A_F41_t
{
    str_AFN0A_PROGRAM program[3];   /*方案数组*/
    byte programstate[3];          /*方案有效标志*/
}str_AFN0A_F41;

typedef struct str_AFN0A_F42_t
{
    double facval;              /*厂休定值*/
    short facvalisnull;         /*厂休定值判空标志*/
    datetime starttime;         /*限电起始时间*/
    short starttimeisnull;      /*限电起始时间判空标志*/
    byte  duration;            /*持续时间*/
    byte  weekday[7];           /*周限电日*/
}str_AFN0A_F42;

typedef struct str_AFN0A_F44_VAL_t
{
    datetime starttime;     /*报停起始时间*/
    datetime stoptime;      /*报停结束时间*/
    double Pval;            /*报停功率定值*/
}str_AFN0A_F44_VAL;

typedef struct str_AFN0A_F44_ISNULL_t
{
    short starttime;     /*报停起始时间判空标志*/
    short stoptime;      /*报停结束时间判空标志*/
    short Pval;          /*报停功率定值判空标志*/
}str_AFN0A_F44_ISNULL;

typedef struct str_AFN0A_F44_t
{
    str_AFN0A_F44_VAL val;     /*报停起始时间判空标志*/
    str_AFN0A_F44_ISNULL isnull;      /*报停结束时间判空标志*/
}str_AFN0A_F44;

typedef struct str_AFN0A_ROUND_t
{
    uchar round[8];           /*轮次标志*/
}str_AFN0A_ROUND;

typedef struct str_AFN0A_F46_t
{
    int val;                /*月电控定值*/
    short valisnull;        /*月电控定值判空标志*/
}str_AFN0A_F46;

typedef struct str_AFN0A_F47_t
{
    int GDDno;              /*购电单号*/
    byte GDtype;           /*购电类型,1为购电,2为刷新,0为无效*/
    int GDval;              /*购电值*/
    short GDvalisnull;      /*购电值判空标志*/
    int alarmlimit;         /*报警门限*/
    short alarmlimitisnull; /*报警门限判空标志*/
    int triplimit;          /*跳闸门限*/
    short triplimitisnull;  /*跳闸门限判空标志*/
}str_AFN0A_F47;
typedef struct str_AFN0A_F57_t
{
    byte alarmsound[24];           /*声音告警标志*/
}str_AFN0A_F57;

typedef struct str_AFN0A_F59_t
{
    double difflimit;       /*超差阈值*/
    short difflimitisnull;  /*超差阈值判空标志*/
    double flewlimit;       /*飞走阈值*/
    short  flewlimitisnull; /*飞走阈值判空标志*/
    byte stoplimit;        /*停走阈值*/
    unsigned short correctionlimit;  /*校时阈值*/
}str_AFN0A_F59;

typedef struct str_AFN0A_F60_VAL_t
{
    double harmonicUZ;      /*总电压含有率上限*/
    double harmonicUodd;    /*奇次电压含有率上限*/
    double harmonicUeven;   /*偶次电压含有率上限*/
    double harmonicU[19];   /*电压有效值上限*/
    double harmonicIZ;      /*总电流含有率上限*/
    double harmonicI[19];   /*电流有效值上限*/
}str_AFN0A_F60_VAL;

typedef struct str_AFN0A_F60_ISNULL_t
{
    short harmonicUZ;       /*总电压含有率上限判空标志*/
    short harmonicUodd;     /*奇次电压含有率上限判空标志*/
    short harmonicUeven;    /*偶次电压含有率上限判空标志*/
    short harmonicU[19];    /*电压有效值上限判空标志*/
    short harmonicIZ;       /*总电流含有率上限判空标志*/
    short harmonicI[19];    /*电流有效值上限判空标志*/
}str_AFN0A_F60_ISNULL;

typedef struct str_AFN0A_F60_t
{
    str_AFN0A_F60_VAL val;
    str_AFN0A_F60_ISNULL isnull;
}str_AFN0A_F60;

typedef struct str_AFN0A_F61_t
{
    byte analogflag[8];    /*模拟量接入标志*/
}str_AFN0A_F61;


typedef struct str_AFN0A_LOWVOLINFO_t
{
    unsigned short meterindex;   /*电表序号*/
    byte metertype;    /*电表类型*/
    str_add12 meteradd; /*地址*/
    unsigned short Kval;         /*电表常数*/
    unsigned short collectoradd; /*所属采集器地址*/
    byte port;         /*采集器端口*/
    byte focustype;    /*是否重点户*/
    byte Gateflag;     /*拉合闸标志*/
    byte stopflag;     /*停用标志*/
    byte statuteindex; /*规约类型*/
    byte PpowerZflag;  /*正向有功电能示值抄收标志*/
    byte QpowerZflag;  /*正向无功电能示值抄收标志*/
    byte PpowerFflag;  /*反向有功电能示值抄收标志*/
    byte QpowerFflag;  /*反向无功电能示值抄收标志*/
    byte Uflag;        /*三相电压抄收标志*/
    byte Iflag;        /*三相电流抄收标志*/
    byte Pflag;        /*总及三相有功超收标志*/
    byte Qflag;        /*总及三相无功超收标志*/
    byte readstep;     /*抄表间隔*/
    byte metermedian;  /*表位数*/
}str_AFN0A_LOWVOLINFO;

typedef struct str_AFN0A_F65F66_t
{
    byte cycleunit;        /*周期单位 0 分 1 时 2 日 3 月*/
    byte cycle;            /*发送周期*/
    datetime marktime;      /*基准时间*/
    short marktimeisnull;   /*基准时间判空标志*/
    byte Rval;             /*抽取倍率*/
    byte Nval;             /*数据单元标识个数*/
    byte PN[255];          /*数据单元标识PN*/
    byte FN[255];          /*数据单元标识FN*/
}str_AFN0A_F65F66;

typedef struct str_AFN0A_F73_t
{
    uchar BCFS[16][4]; /* 补偿方式/A相/B相/C相*/
    double DRRL[16];
    short DRRLisnull[16];
}str_AFN0A_F73;

typedef struct str_AFN0A_F74_t
{
    double MBGVYS;            /*目标功率因数*/
    short   MBGVYSisnull;
    double TRWGGV;           /*投入无功功率门限*/
    short    TRWGGVisnull;
    double QCWGGV;           /*切除无功功率门限*/
    short    QCWGGVisnull;
    uchar    YSSJ;                /*延时时间*/
    uchar    SJJG;                /*动作时间间隔*/
    
}str_AFN0A_F74;

typedef struct str_AFN0A_F75_val_t
{
    double GDY;                                      //过电压
    double GDYHCZ;                                //过电压回差值
    double QDY;                                      //欠电压
    double QDYHCZ;                                //欠电压回差值
    double DLHYL;                                   //总畸变电流含有率上限
    double DLHYLHC;                               //总畸变电流含有率越限回差值
    double DYHYL;                                   //总畸变电压含有率上限
    double DYHYLHC;                               //总畸变电压含有率越限回差值
    
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
    double ZLQSZ;                                    //直流模拟量起始值
    double ZLZSZ;                                     //直流模拟量终止值
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
    double ZLS;                                    //直流模拟量上限
    double ZLX;                                     //直流模拟量下限
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
    int XZBM;                   //行政区码
    int ZDDZ;                   //终端地址
}str_AFN0A_89;

typedef struct str_AFN0A_90_t
{
    uchar WXXDZ;                                        //无线信道组
    uchar WXFSGL;                                       //无线网络发射功率
}str_AFN0A_90;    

typedef struct str_AFN0A_91_t
{
    uchar longitude ;                                        //经度
    uchar latitude;                                           //纬度
}str_AFN0A_91;   



typedef struct str_AFN0A_150_t
{
    uchar Pn_mark[255][8];                       //255组测量点有效标志位
    uchar Pn_change_mark[255][8];            //255组测量点参数变更标志
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
