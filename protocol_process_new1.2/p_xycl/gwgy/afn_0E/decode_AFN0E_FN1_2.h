#ifndef DECODE_AFN0E_FN1_2_H
#define DECODE_AFN0E_FN1_2_H

#include "../public/decode_public.h"

/*事件ERC1 数据初始化和版本变更记录 结构体*/
typedef struct {
	datetime happentime;     /*初始化/版本变更发生时间*/
	short happentimeisnull;
	short init;              /*初始化标志*/
	short versionchange;     /*版本变更标志*/
	uchar version_befor[4];  /*变更前软件版本号*/
	uchar version_after[4];  /*变更后软件版本号*/
}str_afn0e_erc1;

/*事件ERC2 参数丢失记录 结构体 */
typedef struct {
	datetime happentime;  /*发生时间*/
	short happentimeisnull;     /*发生时间判空标志*/
	uchar    termarg;     /*终端参数*/
	uchar    pnarg;       /*测量点参数*/
}str_afn0e_erc2;

/*事件ERC3 参数变更记录 结构体 */
typedef struct {
	datetime happentime;  /*发生时间*/
	uchar    num;         /*变更参数数据单元标识个数*/
	uchar    msa;         /*启动站地址*/
	short    fn[500];     /*FN*/
	short    pn[500];     /*PN*/
}str_afn0e_erc3_val;
typedef struct {
	short    happentime;  /*发生时间判空标志*/
	short    num;         /*变更参数数据单元标识个数判空标志*/
	short    msa;         /*启动站地址判空标志*/
	short    fn[500];     /*FN 判空标志*/
	short    pn[500];     /*PN 判空标志*/
}str_afn0e_erc3_isnull;
typedef struct {
	str_afn0e_erc3_val val;
	str_afn0e_erc3_isnull isnull;
}str_afn0e_erc3;

/*事件ERC4 状态量变位记录 结构体 */
typedef struct {
	datetime happentime;    /*发生时间*/
	short happentimeisnull;
	uchar    state[8];      /*状态变位*/
	uchar    afterstate[8]; /*变位后状态*/
}str_afn0e_erc4;

/*事件ERC5 遥控跳闸记录 结构体 */
typedef struct {
	datetime happentime;    /*发生时间*/
	uchar    turn[8];       /*跳闸轮次*/
	double    P1;           /*跳闸时功率*/
	double    P2;           /*跳闸后2分钟功率*/
}str_afn0e_erc5_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	short    P1;            /*跳闸时功率判空标志*/
	short    P2;            /*跳闸后2分钟功率判空标志*/
}str_afn0e_erc5_isnull;
typedef struct {
	str_afn0e_erc5_val val;
	str_afn0e_erc5_isnull isnull;
}str_afn0e_erc5;

/*ERC6：功控跳闸记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	uchar    pn;            /*总加组号*/
	uchar    turn[8];       /*跳闸轮次*/
	uchar    glxfk, yybtk, cxk, sdk;  /*功控类别 当前功率下浮控	营业报停控	厂休控	时段控*/
	double    P1;           /*跳闸时功率*/
	double    P2;           /*跳闸后2分钟功率*/
	double    val;          /*功率定值*/
}str_afn0e_erc6_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*总加组号判空标志*/
/*	short    glxfk, yybtk, cxk, sdk;/*功控类别 当前功率下浮控	营业报停控	厂休控	时段控判空标志*/
	short    P1;            /*跳闸时功率判空标志*/
	short    P2;            /*跳闸后2分钟功率判空标志*/
	short    val;           /*功率定值判空标志*/
}str_afn0e_erc6_isnull;
typedef struct {
	str_afn0e_erc6_val val;
	str_afn0e_erc6_isnull isnull;
}str_afn0e_erc6;

/*ERC7：电控跳闸记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	uchar    pn;            /*总加组号*/
	uchar    turn[8];       /*跳闸轮次*/
	uchar    gdk, ydk;      /*功控类别 1购电控	0月电控*/
	int    power;        /*跳闸时电能量*/
	int    val;          /*电量定值*/
}str_afn0e_erc7_val;
typedef struct {
	short    happentime;    /*发生时间*/
	/*    short    pn;            /*总加组号*/
	/*    short    gdk, ydk;      /*功控类别 1购电控	0月电控*/
	short    power;         /*跳闸时电能量*/
	short    val;           /*电量定值*/
}str_afn0e_erc7_isnull;
typedef struct {
	str_afn0e_erc7_val val;
	str_afn0e_erc7_isnull isnull;
}str_afn0e_erc7;

/*ERC8：电能表参数变更*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    happentimeisnull;
	short    pn;            /*测量点号*/
	uchar    fl;            /*费率时段*/
	uchar    programtime;   /*编程时间*/
	uchar    cbday;         /*抄表日*/
	uchar    k;             /*表脉冲常数*/
	uchar    bl;            /*互感器倍率*/
	uchar    clear;         /*最大需量清零*/
}str_afn0e_erc8;

/*ERC9：电流回路异常*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flaga, flagb, flagc;  /*对应相发生异常*/
	uchar    type;          /* 1～3依次表示短路、开路、反向，值0为备用*/
	double    Ua, Ub, Uc;    /*发生时电压*/
	double    Ia, Ib, Ic;    /*发生时电流*/
	double    val;           /*发生时电能表正向有功总电能示值*/
}str_afn0e_erc9_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
/*	short    flagerror;     /*异常标志判空标志*/
	short    Ua, Ub, Uc;    /*发生时电压判空标志*/
	short    Ia, Ib, Ic;    /*发生时电流判空标志*/
	short    val;           /*发生时电能表正向有功总电能示值判空标志*/
}str_afn0e_erc9_isnull;
typedef struct {
	str_afn0e_erc9_val val;
	str_afn0e_erc9_isnull isnull;
}str_afn0e_erc9;


/*ERC10：电压回路异常*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flaga, flagb, flagc;  /*对应相发生异常*/
	uchar    type;          /* 0失流 1短路 2开路 3反向*/
	double    Ua, Ub, Uc;    /*发生时电压*/
	double    Ia, Ib, Ic;    /*发生时电流*/
	double    val;           /*发生时电能表正向有功总电能示值*/
}str_afn0e_erc10_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    pn;            /*测量点号判空标志*/
	/*    short    flag;          /*起/止标志判空标志*/
	/*    short    flagerror;     /*异常标志判空标志*/
	short    Ua, Ub, Uc;    /*发生时电压判空标志*/
	short    Ia, Ib, Ic;    /*发生时电流判空标志*/
	short    val;           /*发生时电能表正向有功总电能示值判空标志*/
}str_afn0e_erc10_isnull;
typedef struct {
	str_afn0e_erc10_val val;
	str_afn0e_erc10_isnull isnull;
}str_afn0e_erc10;

/*ERC11：相序异常*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	double    Ua, Ub, Uc;    /*发生时电压相位角*/
	double    Ia, Ib, Ic;    /*发生时电流相位角*/
	double    val;           /*发生时电能表正向有功总电能示值*/
}str_afn0e_erc11_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    pn;            /*测量点号判空标志*/
	/*    short    flag;          /*起/止标志判空标志*/
	short    Ua, Ub, Uc;    /*发生时电压相位角判空标志*/
	short    Ia, Ib, Ic;    /*发生时电流相位角判空标志*/
	short    val;           /*发生时电能表正向有功总电能示值判空标志*/
}str_afn0e_erc11_isnull;
typedef struct {
	str_afn0e_erc11_val val;
	str_afn0e_erc11_isnull isnull;
}str_afn0e_erc11;

/*ERC12：电能表时间超差*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    happentimeisnull;
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
}str_afn0e_erc12;

/*ERC13：电表故障信息*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    happentimeisnull;
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    clear;         /*电能表编程次数或最大需量清零次数发生变化*/
	uchar    dx;            /*电能表断相次数变化*/
	uchar    sy;            /*电能表失压次数变化*/
	uchar    td;            /*电能表停电次数变化*/
	uchar    qy;            /*电能表电池欠压*/
}str_afn0e_erc13;

/*ERC14：终端停/上电事件*/
typedef struct {
	datetime happentime;    /*停电发生时间*/
	datetime happentime2;   /*上电时间*/
}str_afn0e_erc14_val;
typedef struct {
	short    happentime;    /*停电发生时间判空标志*/
	short    happentime2;   /*上电时间判空标志*/
}str_afn0e_erc14_isnull;
typedef struct {
	str_afn0e_erc14_val val;
	str_afn0e_erc14_isnull isnull;
}str_afn0e_erc14;

/*ERC15：谐波越限告警*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flaga, flagb, flagc;  /*对应相位发生异常*/
	uchar    type;          /*异常类型 0 电压 1 电流*/
	uchar    flagyx[19];    /*越限标志 0 未越限 1 越限*/
	double    val[19];       /*越限时该相i次谐波电压含有率（%）/电流有效值*/
}str_afn0e_erc15_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    pn;            /*测量点号判空标志*/
	/*    short    flag;          /*起/止标志判空标志*/
	/*    short    flagerror;     /*异常标志判空标志*/
	short    val[19];       /*越限时该相i次谐波电压含有率（%）/电流有效值判空标志*/
}str_afn0e_erc15_isnull;
typedef struct {
	str_afn0e_erc15_val val;
	str_afn0e_erc15_isnull isnull;
}str_afn0e_erc15;

/*ERC16：直流模拟量越限记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*直流模拟量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flagyxu;       /*越上限标志*/
	uchar    flagyxd;       /*越下限标志*/
	double    val;          /*越限时直流模拟量数据*/
}str_afn0e_erc16_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*直流模拟量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
	short    val;           /*越限时直流模拟量数据判空标志*/
}str_afn0e_erc16_isnull;
typedef struct {
	str_afn0e_erc16_val val;
	str_afn0e_erc16_isnull isnull;
}str_afn0e_erc16;


/*ERC17：电压/电流不平衡度越限记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flagU, flagI;  /*电压、电流不平衡标志*/
	double   valU, valI;    /*电压、电流不平衡度*/
	double   Ua, Ub, Uc;    /*三相电压*/
	double   Ia, Ib, Ic;    /*三相电流*/
}str_afn0e_erc17_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    pn;            /*测量点号判空标志*/
	/*    short    flag;          /*起/止标志判空标志*/
	/*    short    flagerror;     /*异常标志判空标志*/
	short    valU, valI;    /*电压、电流不平衡度判空标志*/
	short    Ua, Ub, Uc;    /*三相电压判空标志*/
	short    Ia, Ib, Ic;    /*三相电流判空标志*/
}str_afn0e_erc17_isnull;
typedef struct {
	str_afn0e_erc17_val val;
	str_afn0e_erc17_isnull isnull;
}str_afn0e_erc17;

/*ERC18：电容器投切自锁记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flaghl, flagzz, flaggy;  /*执行回路故障 装置故障 过压 标志*/
	uchar    flagdr[16];    /*电容组标志  1 该电容器组自锁。0 该电容器组未自锁*/
	double   cos;           /*越限发生时功率因数*/
	double   Q;             /*越限发生时无功功率*/
	double   U;             /*越限发生时电压*/
}str_afn0e_erc18_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
/*	short    flagerror;     /*异常标志判空标志*/
	short    cos;           /*越限发生时功率因数判空标志*/
	short    Q;             /*越限发生时无功功率判空标志*/
	short    U;             /*越限发生时电压判空标志*/
}str_afn0e_erc18_isnull;
typedef struct {
	str_afn0e_erc18_val val;
	str_afn0e_erc18_isnull isnull;
}str_afn0e_erc18;

/*ERC19：购电参数设置记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	uchar    pn;    /*总加组号*/
	int      buyno;         /*购电单号*/
	uchar    flag;          /*追加/刷新标志（55H：追加，AAH：刷新）*/
	int    buyval;        /*购电量值*/
	int    val1, val2;    /*报警门限  跳闸门限*/
	int    power1, power2;/*本次购电前剩余电能量 本次购电后剩余电能量*/
}str_afn0e_erc19_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	short    flag;          /*追加/刷新标志（55H：追加，AAH：刷新）判空标志*/
	short    buyval;        /*购电量值判空标志*/
	short    val1, val2;    /*报警门限  跳闸门限 判空标志*/
	short    power1, power2;/*本次购电前剩余电能量 本次购电后剩余电能量 判空标志*/
}str_afn0e_erc19_isnull;
typedef struct {
	str_afn0e_erc19_val val;
	str_afn0e_erc19_isnull isnull;
}str_afn0e_erc19;

/*ERC20：消息认证错误记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	uchar   PW[16];        /*消息认证码*/
	uchar    MSA;           /*启动站地址*/
}str_afn0e_erc20_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	short    PW;            /*消息认证码判空标志*/
	short    MSA;           /*启动站地址判空标志*/
}str_afn0e_erc20_isnull;
typedef struct {
	str_afn0e_erc20_val val;
	str_afn0e_erc20_isnull isnull;
}str_afn0e_erc20;

/*ERC21：终端故障记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	short happentimeisnull;
	uchar    code;
	/*终端故障编码 1 终端主板内存故障
	               2 时钟故障
	               3 主板通信故障
	               4 485抄表故障
	               5 显示板故障
	               6 载波通道异常
	               6-255 备用
	*/
}str_afn0e_erc21;

/*ERC22：有功总电能量差动越限事件记录*/
typedef struct {
	datetime happentime;      /*发生时间*/
	uchar    pn;              /*电能量差动组号*/
	uchar    qzflag;            /*起/止标志*/
	int    power1, power2;  /*越限时对比总加组有功总电能量 越限时参照总加组有功总电能量*/
	uchar    val1;            /*越限时差动越限相对偏差值*/
	int    val2;            /*越限时差动越限绝对偏差值*/
	uchar    num1;            /*对比总加组测量点数量*/
	double    powerval1[255];   /*越限时对比总加组第1测量点有功总电能示值*/
	uchar    num2;            /*参照总加组测量点数量*/
	double    powerval2[255];   /*越限时参照总加组第1测量点有功总电能示值*/
}str_afn0e_erc22_val;
typedef struct {
	short    happentime;      /*发生时间判空标志*/
/*	short    pn;              /*电能量差动组号判空标志*/
/*	short    flag;            /*起/止标志判空标志*/
	short    power1, power2;  /*越限时对比总加组有功总电能量 越限时参照总加组有功总电能量判空标志*/
	short    val1;            /*越限时差动越限相对偏差值判空标志*/
	short    val2;            /*越限时差动越限绝对偏差值判空标志*/
	short    powerval1[255];  /*越限时对比总加组第1测量点有功总电能示值判空标志*/
	short    powerval2[255];  /*越限时参照总加组第1测量点有功总电能示值判空标志*/
}str_afn0e_erc22_isnull;
typedef struct {
	str_afn0e_erc22_val val;
	str_afn0e_erc22_isnull isnull;
}str_afn0e_erc22;

/*电控告警事件记录*/
typedef struct {
	datetime    happentime;        /*告警时间*/
	uchar        pn;                 /*电能量差动组号*/
	uchar        turn[8];            /*投入轮次*/
	uchar        type;            /*电控类别1：月电控，2：购电控*/
	int         powerval1;             /*告警时电能量*/
	int         powerval2;            /*告警时电控定值*/
}str_afn0e_erc23_val;
typedef struct {
	short    happentime;      /*告警时间判空标志*/
	/*    short    pn;              /*电能量差动组号判空标志*/
	short    type;
	short    powerval1;  /*告警时电能量判空标志*/
	short    powerval2;  /*告警时电控定值判空标志*/
}str_afn0e_erc23_isnull;
typedef struct {
	str_afn0e_erc23_val val;
	str_afn0e_erc23_isnull isnull;
}str_afn0e_erc23;

/*ERC24：电压越限记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flaga, flagb, flagc;  /*越限相位*/
	uchar    flagyx;        /* 0 备用 1 越上上限 2 越下下限*/
	double    Ua, Ub, Uc;   /*越限时电压数据*/
}str_afn0e_erc24_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
/*	short    flaga, flagb, flagc;  /*越限相位判空标志*/
/*	short    flagyx;        /* 0 备用 1 越上上限 2 越下下限判空标志*/
	short    Ua, Ub, Uc;    /*越限时电压数据判空标志*/
}str_afn0e_erc24_isnull;
typedef struct {
	str_afn0e_erc24_val val;
	str_afn0e_erc24_isnull isnull;
}str_afn0e_erc24;

/*ERC25：电流越限记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flaga, flagb, flagc;  /*越限相位*/
	uchar    flagyx;        /* 0 备用 1 越上上限 2 越上限*/
	double    Ia, Ib, Ic;    /*越限时电流数据*/
}str_afn0e_erc25_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    pn;            /*测量点号判空标志*/
	/*   short    flag;          /*起/止标志判空标志*/
	/*    short    flaga, flagb, flagc;  /*越限相位判空标志*/
	/*    short    flagyx;        /*判空标志*/
	short    Ia, Ib, Ic;    /*越限时电流数据判空标志*/
}str_afn0e_erc25_isnull;
typedef struct {
	str_afn0e_erc25_val val;
	str_afn0e_erc25_isnull isnull;
}str_afn0e_erc25;

/*ERC26：视在功率越限记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	uchar    flagyx;        /* 0 备用 1 越有功功率上上限 2 越有功功率上限*/
	double    power;        /*发生时的视在功率 */
	double    val;          /*发生时的视在功率限值*/
}str_afn0e_erc26_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
/*	short    flagyx;        /*判空标志*/
	short    power;         /*发生时的视在功率判空标志 */
	short    val;           /*发生时的视在功率限值判空标志*/
}str_afn0e_erc26_isnull;
typedef struct {
	str_afn0e_erc26_val val;
	str_afn0e_erc26_isnull isnull;
}str_afn0e_erc26;

/*ERC27：电能表示度下降记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar     qzflag;          /*起/止标志*/
	double    powerval1;    /*下降前电能表正向有功总电能示值*/
	double    powerval2;    /*下降后电能表正向有功总电能示值*/
}str_afn0e_erc27_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
	short    powerval1;     /*下降前电能表正向有功总电能示值判空标志*/
	short    powerval2;     /*下降后电能表正向有功总电能示值判空标志*/
}str_afn0e_erc27_isnull;
typedef struct {
	str_afn0e_erc27_val val;
	str_afn0e_erc27_isnull isnull;
}str_afn0e_erc27;

/*ERC28：电能量超差记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar     qzflag;          /*起/止标志*/
	double    powerval1;    /*电能量超差发生时对应正向有功总电能示值*/
	double    powerval2;    /*电能量超差发生时正向有功总电能示值*/
	uchar     val;           /*电能量超差阈值*/
}str_afn0e_erc28_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
	short    powerval1;     /*电能量超差发生时对应正向有功总电能示值判空标志*/
	short    powerval2;     /*电能量超差发生时正向有功总电能示值判空标志*/
	short    val;           /*电能量超差阈值判空标志*/
}str_afn0e_erc28_isnull;
typedef struct {
	str_afn0e_erc28_val val;
	str_afn0e_erc28_isnull isnull;
}str_afn0e_erc28;

/*ERC29：电能表飞走记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar     qzflag;          /*起/止标志*/
	double   powerval1;     /*电能表飞走发生前正向有功总电能示值*/
	double   powerval2;     /*电能表飞走发生后正向有功总电能示值*/
	uchar    val;           /*电能表飞走阈值*/
}str_afn0e_erc29_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
	short    powerval1;     /*电能表飞走发生前正向有功总电能示值判空标志*/
	short    powerval2;     /*电能表飞走发生后正向有功总电能示值判空标志*/
	short    val;           /*电能表飞走阈值判空标志*/
}str_afn0e_erc29_isnull;
typedef struct {
	str_afn0e_erc29_val val;
	str_afn0e_erc29_isnull isnull;
}str_afn0e_erc29;

/*ERC30：电能表飞走记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar   qzflag;          /*起/止标志*/
	double  powerval;     /*电能表停走发生时正向有功总电能示值*/
	uchar    val;           /*电能表停走阈值*/
}str_afn0e_erc30_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    pn;            /*测量点号判空标志*/
	/*    short    flag;          /*起/止标志判空标志*/
	short    powerval;      /*电能表停走发生时正向有功总电能示值判空标志*/
	short    val;           /*电能表停走阈值判空标志*/
}str_afn0e_erc30_isnull;
typedef struct {
	str_afn0e_erc30_val val;
	str_afn0e_erc30_isnull isnull;
}str_afn0e_erc30;

/*ERC31：电能表飞走记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;            /*测量点号*/
	uchar    qzflag;          /*起/止标志*/
	datetime zjcbtime;    /*最近一次抄表成功时间*/
	double   powerval1;     /*最近一次抄表成功正向有功总电能示值*/
	double   powerval2;     /*最近一次抄表成功正向无功总电能示值*/
}str_afn0e_erc31_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    pn;            /*测量点号判空标志*/
/*	short    flag;          /*起/止标志判空标志*/
	short    zjcbtime;    /*最近一次抄表成功时间*/
	short    powerval1;     /*最近一次抄表成功正向有功总电能示值*/
	short    powerval2;     /*最近一次抄表成功正向无功总电能示值*/
}str_afn0e_erc31_isnull;
typedef struct {
	str_afn0e_erc31_val val;
	str_afn0e_erc31_isnull isnull;
}str_afn0e_erc31;

/*ERC32：电能表飞走记录*/
typedef struct {
	datetime happentime;    /*发生时间*/
	uint    datacount;      /*当月已发生的通信流量*/
	uint    datalimit;      /*月通信流量门限*/
}str_afn0e_erc32_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	short    datacount;            /*当月已发生的通信流量判空标志*/
	short    datalimit;          /*月通信流量门限判空标志*/
}str_afn0e_erc32_isnull;
typedef struct {
	str_afn0e_erc32_val val;
	str_afn0e_erc32_isnull isnull;
}str_afn0e_erc32;

typedef struct {
	uchar  ztbw[16];
	uchar  yxzt[16];
}str_afn0e_erc33_flag;
typedef struct {
	datetime                  happentime;
	short                       happentimeisnull;
	ushort                     pn;            /*测量点号*/
	str_afn0e_erc33_flag  flag[7];
}str_afn0e_erc33;

typedef struct {
	datetime happentime;    /*发生时间*/
	short      happentimeisnull;
	ushort    pn;            /*测量点号*/
	uchar     qzflag;          /*起/止标志*/
	uchar    flaga, flagb, flagc;  /*对应相发生异常*/
	uchar    type;          /* D7～D6：编码表示异常类型*/
}str_afn0e_erc34;

typedef struct {
	str_add12  MeterAdd;      /*表地址*/
	short      MeterAddisnull;    /*表地址为空标志*/
	uchar       xw;            /*相位*/
	uchar       xh;            /*信号品质*/
/*	short      XwXhisnull;    /*相位、信号为空标志*/
	uchar       txxy;          /*通讯协议*/
/*	short      txxyisnull;    /*通讯协议为空标志*/
}str_afn0e_erc35_meterinfo;
typedef struct {
	datetime happentime;    /*发生时间*/
	uchar     port;          /*D5～D0： 终端通信端口号（1～31）*/
	uchar     number;          /*发现块数n*/
	str_afn0e_erc35_meterinfo  str_meterinfo[256];
}str_afn0e_erc35_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    port;          /*终端通信端口号判空标志*/
	short    number;        /*发现块数n判空标志*/
}str_afn0e_erc35_isnull;
typedef struct {
	str_afn0e_erc35_val val;
	str_afn0e_erc35_isnull isnull;
}str_afn0e_erc35;

typedef struct {
	datetime happentime;    /*发生时间*/
	short      happentimeisnull;
	uchar     ztbw[4];          /*状态变位*/
	uchar     zt[4];          /*变位后状态*/
}str_afn0e_erc36;

typedef struct {
	datetime happentime;    /*发生时间*/
	ushort     pn;          /*测量点号*/
	int      kgcs;          /*开盖总次数*/
	datetime starttime;    /*开始时间*/
	datetime endtime;    /*结束时间*/
	double   zxyg[2];    /*开盖前后正向有功能示值*/
	double   fxyg[2];    /*开盖前后反向无功能示值*/
	double   wg1[2];    /*开盖前后1象限无功能示值*/
	double   wg2[2];    /*开盖前后2象限无功能示值*/
	double   wg3[2];    /*开盖前后3象限无功能示值*/
	double   wg4[2];    /*开盖前后4象限无功能示值*/
}str_afn0e_erc37_38_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    cldh;*/
	short    kgcs;
	short    starttime;
	short    endtime;
	short    zxyg[2];
	short    fxyg[2];
	short    wg1[2];
	short    wg2[2];
	short    wg3[2];
	short    wg4[2];
}str_afn0e_erc37_38_isnull;
typedef struct {
	str_afn0e_erc37_38_val val;
	str_afn0e_erc37_38_isnull isnull;
}str_afn0e_erc37_38;

typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;          /*测量点号*/
	datetime time;    /*最近一次抄表成功时间*/
	double   zxyg;    /*最近一次抄表成功正向有功总电能示*/
	double   zxwg;    /*最近-次抄表成功正向无功总电能示*/
}str_afn0e_erc39_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	short    pn;
	short    time;
	short    zxyg;
	short    zxwg;
}str_afn0e_erc39_isnull;
typedef struct {
	str_afn0e_erc39_val val;
	str_afn0e_erc39_isnull isnull;
}str_afn0e_erc39;

typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;          /*测量点号*/
	uchar     qzflag;          /*起始标识*/
	uchar     type;          /*设备类型*/
	uchar      addr[12];          /*设备地址*/
	uchar     untype;        /*磁场异常类型*/
}str_afn0e_erc40_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	/*    short    cldh;  */
	/*    short    flag;  */
	/*    short    type;  */
	short    addr;
	/*    short    untype;  */
}str_afn0e_erc40_isnull;
typedef struct {
	str_afn0e_erc40_val val;
	str_afn0e_erc40_isnull isnull;
}str_afn0e_erc40;

typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;          /*测量点号*/
	datetime time;    /*对时前时间*/
	datetime newtime;    /*对时后时间*/
}str_afn0e_erc41_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
	short    pn;
	short    time;
	short    newtime;
}str_afn0e_erc41_isnull;
typedef struct {
	str_afn0e_erc41_val val;
	str_afn0e_erc41_isnull isnull;
}str_afn0e_erc41;

typedef struct {
	datetime happentime;    /*发生时间*/
	ushort    pn;          /*测量点号*/
	int      bjcs;               /*窃电报警总次数*/
	datetime fstime;       /*发生时刻*/
	datetime jstime;       /*结束时刻*/
	double   zxyg1;          /*发生时刻正向有功总电能*/
	double   fxyg1;          /*发生时刻反向有功总电能*/
	double   hxdl1;          /*发生时刻火线电流*/
	double   lxdl1;          /*发生时刻零线电流*/
	double   hxyggl1;          /*发生时刻火线总有功功率*/
	double   lxyggl1;          /*发生时刻零线总有功功率*/
	double   zxyg2;          /*结束时刻正向有功总电能*/
	double   fxyg2;          /*结束时刻反向有功总电能*/
	double   hxdl2;          /*结束时刻火线电流*/
	double   lxdl2;          /*结束时刻零线电流*/
	double   hxyggl2;          /*结束时刻火线总有功功率*/
	double   lxyggl2;          /*结束时刻零线总有功功率*/
}str_afn0e_erc42_val;
typedef struct {
	short    happentime;    /*发生时间判空标志*/
/*	short    cldh;  */
/*	short      bjcs;               /*窃电报警总次数*/
	short fstime;       /*发生时刻*/
	short jstime;       /*结束时刻*/
	short   zxyg1;          /*发生时刻正向有功总电能*/
	short   fxyg1;          /*发生时刻反向有功总电能*/
	short   hxdl1;          /*发生时刻火线电流*/
	short   lxdl1;          /*发生时刻零线电流*/
	short   hxyggl1;          /*发生时刻火线总有功功率*/
	short   lxyggl1;          /*发生时刻零线总有功功率*/
	short   zxyg2;          /*结束时刻正向有功总电能*/
	short   fxyg2;          /*结束时刻反向有功总电能*/
	short   hxdl2;          /*结束时刻火线电流*/
	short   lxdl2;          /*结束时刻零线电流*/
	short   hxyggl2;          /*结束时刻火线总有功功率*/
	short   lxyggl2;          /*结束时刻零线总有功功率*/
}str_afn0e_erc42_isnull;
typedef struct {
	str_afn0e_erc42_val val;
	str_afn0e_erc42_isnull isnull;
}str_afn0e_erc42;

#endif

