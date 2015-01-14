#ifndef DECODE_AFN09_FN1_10_H
#define DECODE_AFN09_FN1_10_H

#include "../public/decode_public.h"

typedef struct {
	uchar    factory_id[5];      /*厂商代号*/
	uchar    equ_num[9];       /*设备编号*/
	uchar    zd_soft_ver[5];   /*终端软件版本号*/
	datetime zd_softdt;      /*终端软件发布日期*/
	short    zd_soft_dtisnull; /*终端软件发布日期判空标志*/
	uchar   zd_memcfg[12];   /*终端配置容量信息码*/
	uchar   zd_comprot_ver[5]; /*终端通信协议版本号*/
	uchar   zd_hw_ver[5];        /*终端硬件版本号*/
	datetime  zd_hw_dt;         /*终端硬件发布日期*/
	short    zd_hw_dtisnull;    /*终端硬件发布日期判空标志*/
}str_zd_ver;

typedef struct {
	ushort portid : 5;  /*端口号*/
	ushort porttype : 2;  /*通道类型*/
	ushort portattr : 1;  /*标准或非标准异步串行口*/
	ushort reserve : 5;  /*保留*/
	ushort purpose : 3;  /*用途*/
}str_portnum_inf;

typedef struct {
	str_portnum_inf portnum_inf;
	uint      maxbaud;  /*通信端口支持的最高波特率*/
	ushort   equ_cnt;  /*通信端口支持的设备个数*/
	ushort   recv_cnt;  /*通信端口支持的最大接收缓存区字节数*/
	ushort   send_cnt;  /*通信端口支持的最大发送缓存区字节数*/
}str_com_portcfg;

typedef struct {
	uchar    pulse_incnt;  /*脉冲量输入路数*/
	uchar    switch_incnt;  /*开关量输入路数*/
	uchar    dcanalog_incnt;  /*直流模拟量输入路数*/
	uchar    switch_outcnt;  /*开关量输出路数*/
	ushort   pn_cnt;  /*支持电能表或交流采样装置最多个数*/
	ushort   zd_uprecv_maxlen;  /*终端上行通信最大接收缓存区字节数*/
	ushort   zd_upsend_maxlen;   /*终端上行通信最大发送缓存区字节数*/
	uchar    mac[7];  /*终端MAC地址段*/
	uchar    comport_cnt;  /*通信端口数量*/
	str_com_portcfg str_comport[33];
}str_io_com_portcfg;

typedef struct {
	ushort   maxcld;         /*支持的测量点最多点数*/
	uchar    maxzjz;         /*支持的总加组最多组数 */
	uchar    maxrw;         /*支持的任务最多个数*/
	uchar    maxcdz;       /*支持的有功总电能量差动组最多组数*/
	uchar    maxfls;        /*支持的最大费率数*/
	uchar    cldmd;         /*支持的测量点数据最大冻结密度*/
	uchar    zjzygmd;     /*支持的总加组有功功率数据最大冻结密度*/
	uchar    zjzwgmd;     /*支持的总加组无功功率数据最大冻结密度*/
	uchar    zjzygdnlmd; /*支持的总加组有功电能量数据最大冻结密度*/
	uchar    zjzwgdnlmd; /*支持的总加组有功无功电能量数据最大冻结密度*/
	uchar    keepday;       /*支持的日冻结最多存放天数*/
	uchar    keepmonth;   /*支持的月冻结最多存放天数*/
	uchar    maxfa;          /*支持的时段功控定值方案最多个数*/
	uchar    maxxbcs;      /*支持的谐波检测最高谐波次数*/
	uchar    maxzs;         /*支持的无功补偿电容器组最多组数 */
	uchar    maxzdh;       /*支持的台区集中抄表重点户最多户数*/
	ushort   yhdlflag;      /*支持的用户大类号标志*/
	uchar    xlcount[16];   /*支持x号用户大类下的用户小类号个数*/
}str_zdother_cfg;


typedef struct {
    uchar    DTcnt;         /*支持的信息类组数*/
    uchar    DTxflag[32]; /*支持的每组对应的标志位*/
}str_zdsupport_DT;


typedef struct {
    uchar    xxcount;   /*支持的信息类组数*/
    uchar    xxlbz[32]; /*支持的第X组信息类组所对应的信息类元标志位*/
}str_afn09_f6_7_val;

typedef struct {
    ushort   yhdlflag;     /*支持的用户大类号标志*/
    str_afn09_f6_7_val str_val[16];
}str_afn09_f6_7;

typedef struct {
    uchar event_flg[8];  /*终端支持的事件记录标志位*/
}str_event_cfg;

typedef struct {
    uchar factory_id[4];  /*厂商代号*/
    uchar module_type[8];  /*模块型号*/
    uchar soft_ver[4];  /*软件版本号*/
    datetime soft_dt;  /*软件发布日期*/
    short soft_dtisnull;  /*软件发布日期判空标志*/
    uchar hw_ver[4];  /*硬件件版本号*/
    datetime hw_dt;  /*硬件发布日期*/
    short hw_dtisnull;  /*硬件发布日期判空标志*/
    uchar sim_iccid[20];  /*SIM卡ICCID*/
}str_commodule_ver;  /*远程通信模块版本信息*/

typedef struct {
    uchar module_addr[6];  /*厂商代号*/
    uchar factory_id[2];   /*厂商代码*/
    uchar chip_id[2];  /*芯片代码*/
    datetime ver_dt;  /*版本日期*/
    uchar ver[2];  /*版本*/
}str_locmodule_ver;  /*本地通信模块版本信息*/



#endif

