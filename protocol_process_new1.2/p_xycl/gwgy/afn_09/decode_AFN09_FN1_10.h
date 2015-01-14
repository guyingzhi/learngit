#ifndef DECODE_AFN09_FN1_10_H
#define DECODE_AFN09_FN1_10_H

#include "../public/decode_public.h"

typedef struct {
	uchar    factory_id[5];      /*���̴���*/
	uchar    equ_num[9];       /*�豸���*/
	uchar    zd_soft_ver[5];   /*�ն�����汾��*/
	datetime zd_softdt;      /*�ն������������*/
	short    zd_soft_dtisnull; /*�ն�������������пձ�־*/
	uchar   zd_memcfg[12];   /*�ն�����������Ϣ��*/
	uchar   zd_comprot_ver[5]; /*�ն�ͨ��Э��汾��*/
	uchar   zd_hw_ver[5];        /*�ն�Ӳ���汾��*/
	datetime  zd_hw_dt;         /*�ն�Ӳ����������*/
	short    zd_hw_dtisnull;    /*�ն�Ӳ�����������пձ�־*/
}str_zd_ver;

typedef struct {
	ushort portid : 5;  /*�˿ں�*/
	ushort porttype : 2;  /*ͨ������*/
	ushort portattr : 1;  /*��׼��Ǳ�׼�첽���п�*/
	ushort reserve : 5;  /*����*/
	ushort purpose : 3;  /*��;*/
}str_portnum_inf;

typedef struct {
	str_portnum_inf portnum_inf;
	uint      maxbaud;  /*ͨ�Ŷ˿�֧�ֵ���߲�����*/
	ushort   equ_cnt;  /*ͨ�Ŷ˿�֧�ֵ��豸����*/
	ushort   recv_cnt;  /*ͨ�Ŷ˿�֧�ֵ������ջ������ֽ���*/
	ushort   send_cnt;  /*ͨ�Ŷ˿�֧�ֵ�����ͻ������ֽ���*/
}str_com_portcfg;

typedef struct {
	uchar    pulse_incnt;  /*����������·��*/
	uchar    switch_incnt;  /*����������·��*/
	uchar    dcanalog_incnt;  /*ֱ��ģ��������·��*/
	uchar    switch_outcnt;  /*���������·��*/
	ushort   pn_cnt;  /*֧�ֵ��ܱ��������װ��������*/
	ushort   zd_uprecv_maxlen;  /*�ն�����ͨ�������ջ������ֽ���*/
	ushort   zd_upsend_maxlen;   /*�ն�����ͨ������ͻ������ֽ���*/
	uchar    mac[7];  /*�ն�MAC��ַ��*/
	uchar    comport_cnt;  /*ͨ�Ŷ˿�����*/
	str_com_portcfg str_comport[33];
}str_io_com_portcfg;

typedef struct {
	ushort   maxcld;         /*֧�ֵĲ�����������*/
	uchar    maxzjz;         /*֧�ֵ��ܼ���������� */
	uchar    maxrw;         /*֧�ֵ�����������*/
	uchar    maxcdz;       /*֧�ֵ��й��ܵ���������������*/
	uchar    maxfls;        /*֧�ֵ���������*/
	uchar    cldmd;         /*֧�ֵĲ�����������󶳽��ܶ�*/
	uchar    zjzygmd;     /*֧�ֵ��ܼ����й�����������󶳽��ܶ�*/
	uchar    zjzwgmd;     /*֧�ֵ��ܼ����޹�����������󶳽��ܶ�*/
	uchar    zjzygdnlmd; /*֧�ֵ��ܼ����й�������������󶳽��ܶ�*/
	uchar    zjzwgdnlmd; /*֧�ֵ��ܼ����й��޹�������������󶳽��ܶ�*/
	uchar    keepday;       /*֧�ֵ��ն������������*/
	uchar    keepmonth;   /*֧�ֵ��¶������������*/
	uchar    maxfa;          /*֧�ֵ�ʱ�ι��ض�ֵ����������*/
	uchar    maxxbcs;      /*֧�ֵ�г��������г������*/
	uchar    maxzs;         /*֧�ֵ��޹�������������������� */
	uchar    maxzdh;       /*֧�ֵ�̨�����г����ص㻧��໧��*/
	ushort   yhdlflag;      /*֧�ֵ��û�����ű�־*/
	uchar    xlcount[16];   /*֧��x���û������µ��û�С��Ÿ���*/
}str_zdother_cfg;


typedef struct {
    uchar    DTcnt;         /*֧�ֵ���Ϣ������*/
    uchar    DTxflag[32]; /*֧�ֵ�ÿ���Ӧ�ı�־λ*/
}str_zdsupport_DT;


typedef struct {
    uchar    xxcount;   /*֧�ֵ���Ϣ������*/
    uchar    xxlbz[32]; /*֧�ֵĵ�X����Ϣ��������Ӧ����Ϣ��Ԫ��־λ*/
}str_afn09_f6_7_val;

typedef struct {
    ushort   yhdlflag;     /*֧�ֵ��û�����ű�־*/
    str_afn09_f6_7_val str_val[16];
}str_afn09_f6_7;

typedef struct {
    uchar event_flg[8];  /*�ն�֧�ֵ��¼���¼��־λ*/
}str_event_cfg;

typedef struct {
    uchar factory_id[4];  /*���̴���*/
    uchar module_type[8];  /*ģ���ͺ�*/
    uchar soft_ver[4];  /*����汾��*/
    datetime soft_dt;  /*�����������*/
    short soft_dtisnull;  /*������������пձ�־*/
    uchar hw_ver[4];  /*Ӳ�����汾��*/
    datetime hw_dt;  /*Ӳ����������*/
    short hw_dtisnull;  /*Ӳ�����������пձ�־*/
    uchar sim_iccid[20];  /*SIM��ICCID*/
}str_commodule_ver;  /*Զ��ͨ��ģ��汾��Ϣ*/

typedef struct {
    uchar module_addr[6];  /*���̴���*/
    uchar factory_id[2];   /*���̴���*/
    uchar chip_id[2];  /*оƬ����*/
    datetime ver_dt;  /*�汾����*/
    uchar ver[2];  /*�汾*/
}str_locmodule_ver;  /*����ͨ��ģ��汾��Ϣ*/



#endif

