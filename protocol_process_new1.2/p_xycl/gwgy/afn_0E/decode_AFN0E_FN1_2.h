#ifndef DECODE_AFN0E_FN1_2_H
#define DECODE_AFN0E_FN1_2_H

#include "../public/decode_public.h"

/*�¼�ERC1 ���ݳ�ʼ���Ͱ汾�����¼ �ṹ��*/
typedef struct {
	datetime happentime;     /*��ʼ��/�汾�������ʱ��*/
	short happentimeisnull;
	short init;              /*��ʼ����־*/
	short versionchange;     /*�汾�����־*/
	uchar version_befor[4];  /*���ǰ����汾��*/
	uchar version_after[4];  /*���������汾��*/
}str_afn0e_erc1;

/*�¼�ERC2 ������ʧ��¼ �ṹ�� */
typedef struct {
	datetime happentime;  /*����ʱ��*/
	short happentimeisnull;     /*����ʱ���пձ�־*/
	uchar    termarg;     /*�ն˲���*/
	uchar    pnarg;       /*���������*/
}str_afn0e_erc2;

/*�¼�ERC3 ���������¼ �ṹ�� */
typedef struct {
	datetime happentime;  /*����ʱ��*/
	uchar    num;         /*����������ݵ�Ԫ��ʶ����*/
	uchar    msa;         /*����վ��ַ*/
	short    fn[500];     /*FN*/
	short    pn[500];     /*PN*/
}str_afn0e_erc3_val;
typedef struct {
	short    happentime;  /*����ʱ���пձ�־*/
	short    num;         /*����������ݵ�Ԫ��ʶ�����пձ�־*/
	short    msa;         /*����վ��ַ�пձ�־*/
	short    fn[500];     /*FN �пձ�־*/
	short    pn[500];     /*PN �пձ�־*/
}str_afn0e_erc3_isnull;
typedef struct {
	str_afn0e_erc3_val val;
	str_afn0e_erc3_isnull isnull;
}str_afn0e_erc3;

/*�¼�ERC4 ״̬����λ��¼ �ṹ�� */
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short happentimeisnull;
	uchar    state[8];      /*״̬��λ*/
	uchar    afterstate[8]; /*��λ��״̬*/
}str_afn0e_erc4;

/*�¼�ERC5 ң����բ��¼ �ṹ�� */
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uchar    turn[8];       /*��բ�ִ�*/
	double    P1;           /*��բʱ����*/
	double    P2;           /*��բ��2���ӹ���*/
}str_afn0e_erc5_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	short    P1;            /*��բʱ�����пձ�־*/
	short    P2;            /*��բ��2���ӹ����пձ�־*/
}str_afn0e_erc5_isnull;
typedef struct {
	str_afn0e_erc5_val val;
	str_afn0e_erc5_isnull isnull;
}str_afn0e_erc5;

/*ERC6��������բ��¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uchar    pn;            /*�ܼ����*/
	uchar    turn[8];       /*��բ�ִ�*/
	uchar    glxfk, yybtk, cxk, sdk;  /*������� ��ǰ�����¸���	Ӫҵ��ͣ��	���ݿ�	ʱ�ο�*/
	double    P1;           /*��բʱ����*/
	double    P2;           /*��բ��2���ӹ���*/
	double    val;          /*���ʶ�ֵ*/
}str_afn0e_erc6_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*�ܼ�����пձ�־*/
/*	short    glxfk, yybtk, cxk, sdk;/*������� ��ǰ�����¸���	Ӫҵ��ͣ��	���ݿ�	ʱ�ο��пձ�־*/
	short    P1;            /*��բʱ�����пձ�־*/
	short    P2;            /*��բ��2���ӹ����пձ�־*/
	short    val;           /*���ʶ�ֵ�пձ�־*/
}str_afn0e_erc6_isnull;
typedef struct {
	str_afn0e_erc6_val val;
	str_afn0e_erc6_isnull isnull;
}str_afn0e_erc6;

/*ERC7�������բ��¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uchar    pn;            /*�ܼ����*/
	uchar    turn[8];       /*��բ�ִ�*/
	uchar    gdk, ydk;      /*������� 1�����	0�µ��*/
	int    power;        /*��բʱ������*/
	int    val;          /*������ֵ*/
}str_afn0e_erc7_val;
typedef struct {
	short    happentime;    /*����ʱ��*/
	/*    short    pn;            /*�ܼ����*/
	/*    short    gdk, ydk;      /*������� 1�����	0�µ��*/
	short    power;         /*��բʱ������*/
	short    val;           /*������ֵ*/
}str_afn0e_erc7_isnull;
typedef struct {
	str_afn0e_erc7_val val;
	str_afn0e_erc7_isnull isnull;
}str_afn0e_erc7;

/*ERC8�����ܱ�������*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    happentimeisnull;
	short    pn;            /*�������*/
	uchar    fl;            /*����ʱ��*/
	uchar    programtime;   /*���ʱ��*/
	uchar    cbday;         /*������*/
	uchar    k;             /*�����峣��*/
	uchar    bl;            /*����������*/
	uchar    clear;         /*�����������*/
}str_afn0e_erc8;

/*ERC9��������·�쳣*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flaga, flagb, flagc;  /*��Ӧ�෢���쳣*/
	uchar    type;          /* 1��3���α�ʾ��·����·������ֵ0Ϊ����*/
	double    Ua, Ub, Uc;    /*����ʱ��ѹ*/
	double    Ia, Ib, Ic;    /*����ʱ����*/
	double    val;           /*����ʱ���ܱ������й��ܵ���ʾֵ*/
}str_afn0e_erc9_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
/*	short    flagerror;     /*�쳣��־�пձ�־*/
	short    Ua, Ub, Uc;    /*����ʱ��ѹ�пձ�־*/
	short    Ia, Ib, Ic;    /*����ʱ�����пձ�־*/
	short    val;           /*����ʱ���ܱ������й��ܵ���ʾֵ�пձ�־*/
}str_afn0e_erc9_isnull;
typedef struct {
	str_afn0e_erc9_val val;
	str_afn0e_erc9_isnull isnull;
}str_afn0e_erc9;


/*ERC10����ѹ��·�쳣*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flaga, flagb, flagc;  /*��Ӧ�෢���쳣*/
	uchar    type;          /* 0ʧ�� 1��· 2��· 3����*/
	double    Ua, Ub, Uc;    /*����ʱ��ѹ*/
	double    Ia, Ib, Ic;    /*����ʱ����*/
	double    val;           /*����ʱ���ܱ������й��ܵ���ʾֵ*/
}str_afn0e_erc10_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	/*    short    pn;            /*��������пձ�־*/
	/*    short    flag;          /*��/ֹ��־�пձ�־*/
	/*    short    flagerror;     /*�쳣��־�пձ�־*/
	short    Ua, Ub, Uc;    /*����ʱ��ѹ�пձ�־*/
	short    Ia, Ib, Ic;    /*����ʱ�����пձ�־*/
	short    val;           /*����ʱ���ܱ������й��ܵ���ʾֵ�пձ�־*/
}str_afn0e_erc10_isnull;
typedef struct {
	str_afn0e_erc10_val val;
	str_afn0e_erc10_isnull isnull;
}str_afn0e_erc10;

/*ERC11�������쳣*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	double    Ua, Ub, Uc;    /*����ʱ��ѹ��λ��*/
	double    Ia, Ib, Ic;    /*����ʱ������λ��*/
	double    val;           /*����ʱ���ܱ������й��ܵ���ʾֵ*/
}str_afn0e_erc11_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	/*    short    pn;            /*��������пձ�־*/
	/*    short    flag;          /*��/ֹ��־�пձ�־*/
	short    Ua, Ub, Uc;    /*����ʱ��ѹ��λ���пձ�־*/
	short    Ia, Ib, Ic;    /*����ʱ������λ���пձ�־*/
	short    val;           /*����ʱ���ܱ������й��ܵ���ʾֵ�пձ�־*/
}str_afn0e_erc11_isnull;
typedef struct {
	str_afn0e_erc11_val val;
	str_afn0e_erc11_isnull isnull;
}str_afn0e_erc11;

/*ERC12�����ܱ�ʱ�䳬��*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    happentimeisnull;
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
}str_afn0e_erc12;

/*ERC13����������Ϣ*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    happentimeisnull;
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    clear;         /*���ܱ��̴������������������������仯*/
	uchar    dx;            /*���ܱ��������仯*/
	uchar    sy;            /*���ܱ�ʧѹ�����仯*/
	uchar    td;            /*���ܱ�ͣ������仯*/
	uchar    qy;            /*���ܱ���Ƿѹ*/
}str_afn0e_erc13;

/*ERC14���ն�ͣ/�ϵ��¼�*/
typedef struct {
	datetime happentime;    /*ͣ�緢��ʱ��*/
	datetime happentime2;   /*�ϵ�ʱ��*/
}str_afn0e_erc14_val;
typedef struct {
	short    happentime;    /*ͣ�緢��ʱ���пձ�־*/
	short    happentime2;   /*�ϵ�ʱ���пձ�־*/
}str_afn0e_erc14_isnull;
typedef struct {
	str_afn0e_erc14_val val;
	str_afn0e_erc14_isnull isnull;
}str_afn0e_erc14;

/*ERC15��г��Խ�޸澯*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flaga, flagb, flagc;  /*��Ӧ��λ�����쳣*/
	uchar    type;          /*�쳣���� 0 ��ѹ 1 ����*/
	uchar    flagyx[19];    /*Խ�ޱ�־ 0 δԽ�� 1 Խ��*/
	double    val[19];       /*Խ��ʱ����i��г����ѹ�����ʣ�%��/������Чֵ*/
}str_afn0e_erc15_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	/*    short    pn;            /*��������пձ�־*/
	/*    short    flag;          /*��/ֹ��־�пձ�־*/
	/*    short    flagerror;     /*�쳣��־�пձ�־*/
	short    val[19];       /*Խ��ʱ����i��г����ѹ�����ʣ�%��/������Чֵ�пձ�־*/
}str_afn0e_erc15_isnull;
typedef struct {
	str_afn0e_erc15_val val;
	str_afn0e_erc15_isnull isnull;
}str_afn0e_erc15;

/*ERC16��ֱ��ģ����Խ�޼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*ֱ��ģ�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flagyxu;       /*Խ���ޱ�־*/
	uchar    flagyxd;       /*Խ���ޱ�־*/
	double    val;          /*Խ��ʱֱ��ģ��������*/
}str_afn0e_erc16_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*ֱ��ģ��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
	short    val;           /*Խ��ʱֱ��ģ���������пձ�־*/
}str_afn0e_erc16_isnull;
typedef struct {
	str_afn0e_erc16_val val;
	str_afn0e_erc16_isnull isnull;
}str_afn0e_erc16;


/*ERC17����ѹ/������ƽ���Խ�޼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flagU, flagI;  /*��ѹ��������ƽ���־*/
	double   valU, valI;    /*��ѹ��������ƽ���*/
	double   Ua, Ub, Uc;    /*�����ѹ*/
	double   Ia, Ib, Ic;    /*�������*/
}str_afn0e_erc17_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	/*    short    pn;            /*��������пձ�־*/
	/*    short    flag;          /*��/ֹ��־�пձ�־*/
	/*    short    flagerror;     /*�쳣��־�пձ�־*/
	short    valU, valI;    /*��ѹ��������ƽ����пձ�־*/
	short    Ua, Ub, Uc;    /*�����ѹ�пձ�־*/
	short    Ia, Ib, Ic;    /*��������пձ�־*/
}str_afn0e_erc17_isnull;
typedef struct {
	str_afn0e_erc17_val val;
	str_afn0e_erc17_isnull isnull;
}str_afn0e_erc17;

/*ERC18��������Ͷ��������¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flaghl, flagzz, flaggy;  /*ִ�л�·���� װ�ù��� ��ѹ ��־*/
	uchar    flagdr[16];    /*�������־  1 �õ�������������0 �õ�������δ����*/
	double   cos;           /*Խ�޷���ʱ��������*/
	double   Q;             /*Խ�޷���ʱ�޹�����*/
	double   U;             /*Խ�޷���ʱ��ѹ*/
}str_afn0e_erc18_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
/*	short    flagerror;     /*�쳣��־�пձ�־*/
	short    cos;           /*Խ�޷���ʱ���������пձ�־*/
	short    Q;             /*Խ�޷���ʱ�޹������пձ�־*/
	short    U;             /*Խ�޷���ʱ��ѹ�пձ�־*/
}str_afn0e_erc18_isnull;
typedef struct {
	str_afn0e_erc18_val val;
	str_afn0e_erc18_isnull isnull;
}str_afn0e_erc18;

/*ERC19������������ü�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uchar    pn;    /*�ܼ����*/
	int      buyno;         /*���絥��*/
	uchar    flag;          /*׷��/ˢ�±�־��55H��׷�ӣ�AAH��ˢ�£�*/
	int    buyval;        /*������ֵ*/
	int    val1, val2;    /*��������  ��բ����*/
	int    power1, power2;/*���ι���ǰʣ������� ���ι����ʣ�������*/
}str_afn0e_erc19_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	short    flag;          /*׷��/ˢ�±�־��55H��׷�ӣ�AAH��ˢ�£��пձ�־*/
	short    buyval;        /*������ֵ�пձ�־*/
	short    val1, val2;    /*��������  ��բ���� �пձ�־*/
	short    power1, power2;/*���ι���ǰʣ������� ���ι����ʣ������� �пձ�־*/
}str_afn0e_erc19_isnull;
typedef struct {
	str_afn0e_erc19_val val;
	str_afn0e_erc19_isnull isnull;
}str_afn0e_erc19;

/*ERC20����Ϣ��֤�����¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uchar   PW[16];        /*��Ϣ��֤��*/
	uchar    MSA;           /*����վ��ַ*/
}str_afn0e_erc20_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	short    PW;            /*��Ϣ��֤���пձ�־*/
	short    MSA;           /*����վ��ַ�пձ�־*/
}str_afn0e_erc20_isnull;
typedef struct {
	str_afn0e_erc20_val val;
	str_afn0e_erc20_isnull isnull;
}str_afn0e_erc20;

/*ERC21���ն˹��ϼ�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	short happentimeisnull;
	uchar    code;
	/*�ն˹��ϱ��� 1 �ն������ڴ����
	               2 ʱ�ӹ���
	               3 ����ͨ�Ź���
	               4 485�������
	               5 ��ʾ�����
	               6 �ز�ͨ���쳣
	               6-255 ����
	*/
}str_afn0e_erc21;

/*ERC22���й��ܵ������Խ���¼���¼*/
typedef struct {
	datetime happentime;      /*����ʱ��*/
	uchar    pn;              /*����������*/
	uchar    qzflag;            /*��/ֹ��־*/
	int    power1, power2;  /*Խ��ʱ�Ա��ܼ����й��ܵ����� Խ��ʱ�����ܼ����й��ܵ�����*/
	uchar    val1;            /*Խ��ʱ�Խ�����ƫ��ֵ*/
	int    val2;            /*Խ��ʱ�Խ�޾���ƫ��ֵ*/
	uchar    num1;            /*�Ա��ܼ������������*/
	double    powerval1[255];   /*Խ��ʱ�Ա��ܼ����1�������й��ܵ���ʾֵ*/
	uchar    num2;            /*�����ܼ������������*/
	double    powerval2[255];   /*Խ��ʱ�����ܼ����1�������й��ܵ���ʾֵ*/
}str_afn0e_erc22_val;
typedef struct {
	short    happentime;      /*����ʱ���пձ�־*/
/*	short    pn;              /*�����������пձ�־*/
/*	short    flag;            /*��/ֹ��־�пձ�־*/
	short    power1, power2;  /*Խ��ʱ�Ա��ܼ����й��ܵ����� Խ��ʱ�����ܼ����й��ܵ������пձ�־*/
	short    val1;            /*Խ��ʱ�Խ�����ƫ��ֵ�пձ�־*/
	short    val2;            /*Խ��ʱ�Խ�޾���ƫ��ֵ�пձ�־*/
	short    powerval1[255];  /*Խ��ʱ�Ա��ܼ����1�������й��ܵ���ʾֵ�пձ�־*/
	short    powerval2[255];  /*Խ��ʱ�����ܼ����1�������й��ܵ���ʾֵ�пձ�־*/
}str_afn0e_erc22_isnull;
typedef struct {
	str_afn0e_erc22_val val;
	str_afn0e_erc22_isnull isnull;
}str_afn0e_erc22;

/*��ظ澯�¼���¼*/
typedef struct {
	datetime    happentime;        /*�澯ʱ��*/
	uchar        pn;                 /*����������*/
	uchar        turn[8];            /*Ͷ���ִ�*/
	uchar        type;            /*������1���µ�أ�2�������*/
	int         powerval1;             /*�澯ʱ������*/
	int         powerval2;            /*�澯ʱ��ض�ֵ*/
}str_afn0e_erc23_val;
typedef struct {
	short    happentime;      /*�澯ʱ���пձ�־*/
	/*    short    pn;              /*�����������пձ�־*/
	short    type;
	short    powerval1;  /*�澯ʱ�������пձ�־*/
	short    powerval2;  /*�澯ʱ��ض�ֵ�пձ�־*/
}str_afn0e_erc23_isnull;
typedef struct {
	str_afn0e_erc23_val val;
	str_afn0e_erc23_isnull isnull;
}str_afn0e_erc23;

/*ERC24����ѹԽ�޼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flaga, flagb, flagc;  /*Խ����λ*/
	uchar    flagyx;        /* 0 ���� 1 Խ������ 2 Խ������*/
	double    Ua, Ub, Uc;   /*Խ��ʱ��ѹ����*/
}str_afn0e_erc24_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
/*	short    flaga, flagb, flagc;  /*Խ����λ�пձ�־*/
/*	short    flagyx;        /* 0 ���� 1 Խ������ 2 Խ�������пձ�־*/
	short    Ua, Ub, Uc;    /*Խ��ʱ��ѹ�����пձ�־*/
}str_afn0e_erc24_isnull;
typedef struct {
	str_afn0e_erc24_val val;
	str_afn0e_erc24_isnull isnull;
}str_afn0e_erc24;

/*ERC25������Խ�޼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flaga, flagb, flagc;  /*Խ����λ*/
	uchar    flagyx;        /* 0 ���� 1 Խ������ 2 Խ����*/
	double    Ia, Ib, Ic;    /*Խ��ʱ��������*/
}str_afn0e_erc25_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	/*    short    pn;            /*��������пձ�־*/
	/*   short    flag;          /*��/ֹ��־�пձ�־*/
	/*    short    flaga, flagb, flagc;  /*Խ����λ�пձ�־*/
	/*    short    flagyx;        /*�пձ�־*/
	short    Ia, Ib, Ic;    /*Խ��ʱ���������пձ�־*/
}str_afn0e_erc25_isnull;
typedef struct {
	str_afn0e_erc25_val val;
	str_afn0e_erc25_isnull isnull;
}str_afn0e_erc25;

/*ERC26�����ڹ���Խ�޼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	uchar    flagyx;        /* 0 ���� 1 Խ�й����������� 2 Խ�й���������*/
	double    power;        /*����ʱ�����ڹ��� */
	double    val;          /*����ʱ�����ڹ�����ֵ*/
}str_afn0e_erc26_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
/*	short    flagyx;        /*�пձ�־*/
	short    power;         /*����ʱ�����ڹ����пձ�־ */
	short    val;           /*����ʱ�����ڹ�����ֵ�пձ�־*/
}str_afn0e_erc26_isnull;
typedef struct {
	str_afn0e_erc26_val val;
	str_afn0e_erc26_isnull isnull;
}str_afn0e_erc26;

/*ERC27�����ܱ�ʾ���½���¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar     qzflag;          /*��/ֹ��־*/
	double    powerval1;    /*�½�ǰ���ܱ������й��ܵ���ʾֵ*/
	double    powerval2;    /*�½�����ܱ������й��ܵ���ʾֵ*/
}str_afn0e_erc27_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
	short    powerval1;     /*�½�ǰ���ܱ������й��ܵ���ʾֵ�пձ�־*/
	short    powerval2;     /*�½�����ܱ������й��ܵ���ʾֵ�пձ�־*/
}str_afn0e_erc27_isnull;
typedef struct {
	str_afn0e_erc27_val val;
	str_afn0e_erc27_isnull isnull;
}str_afn0e_erc27;

/*ERC28�������������¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar     qzflag;          /*��/ֹ��־*/
	double    powerval1;    /*�����������ʱ��Ӧ�����й��ܵ���ʾֵ*/
	double    powerval2;    /*�����������ʱ�����й��ܵ���ʾֵ*/
	uchar     val;           /*������������ֵ*/
}str_afn0e_erc28_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
	short    powerval1;     /*�����������ʱ��Ӧ�����й��ܵ���ʾֵ�пձ�־*/
	short    powerval2;     /*�����������ʱ�����й��ܵ���ʾֵ�пձ�־*/
	short    val;           /*������������ֵ�пձ�־*/
}str_afn0e_erc28_isnull;
typedef struct {
	str_afn0e_erc28_val val;
	str_afn0e_erc28_isnull isnull;
}str_afn0e_erc28;

/*ERC29�����ܱ���߼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar     qzflag;          /*��/ֹ��־*/
	double   powerval1;     /*���ܱ���߷���ǰ�����й��ܵ���ʾֵ*/
	double   powerval2;     /*���ܱ���߷����������й��ܵ���ʾֵ*/
	uchar    val;           /*���ܱ������ֵ*/
}str_afn0e_erc29_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
	short    powerval1;     /*���ܱ���߷���ǰ�����й��ܵ���ʾֵ�пձ�־*/
	short    powerval2;     /*���ܱ���߷����������й��ܵ���ʾֵ�пձ�־*/
	short    val;           /*���ܱ������ֵ�пձ�־*/
}str_afn0e_erc29_isnull;
typedef struct {
	str_afn0e_erc29_val val;
	str_afn0e_erc29_isnull isnull;
}str_afn0e_erc29;

/*ERC30�����ܱ���߼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar   qzflag;          /*��/ֹ��־*/
	double  powerval;     /*���ܱ�ͣ�߷���ʱ�����й��ܵ���ʾֵ*/
	uchar    val;           /*���ܱ�ͣ����ֵ*/
}str_afn0e_erc30_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	/*    short    pn;            /*��������пձ�־*/
	/*    short    flag;          /*��/ֹ��־�пձ�־*/
	short    powerval;      /*���ܱ�ͣ�߷���ʱ�����й��ܵ���ʾֵ�пձ�־*/
	short    val;           /*���ܱ�ͣ����ֵ�пձ�־*/
}str_afn0e_erc30_isnull;
typedef struct {
	str_afn0e_erc30_val val;
	str_afn0e_erc30_isnull isnull;
}str_afn0e_erc30;

/*ERC31�����ܱ���߼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;            /*�������*/
	uchar    qzflag;          /*��/ֹ��־*/
	datetime zjcbtime;    /*���һ�γ���ɹ�ʱ��*/
	double   powerval1;     /*���һ�γ���ɹ������й��ܵ���ʾֵ*/
	double   powerval2;     /*���һ�γ���ɹ������޹��ܵ���ʾֵ*/
}str_afn0e_erc31_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    pn;            /*��������пձ�־*/
/*	short    flag;          /*��/ֹ��־�пձ�־*/
	short    zjcbtime;    /*���һ�γ���ɹ�ʱ��*/
	short    powerval1;     /*���һ�γ���ɹ������й��ܵ���ʾֵ*/
	short    powerval2;     /*���һ�γ���ɹ������޹��ܵ���ʾֵ*/
}str_afn0e_erc31_isnull;
typedef struct {
	str_afn0e_erc31_val val;
	str_afn0e_erc31_isnull isnull;
}str_afn0e_erc31;

/*ERC32�����ܱ���߼�¼*/
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uint    datacount;      /*�����ѷ�����ͨ������*/
	uint    datalimit;      /*��ͨ����������*/
}str_afn0e_erc32_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	short    datacount;            /*�����ѷ�����ͨ�������пձ�־*/
	short    datalimit;          /*��ͨ�����������пձ�־*/
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
	ushort                     pn;            /*�������*/
	str_afn0e_erc33_flag  flag[7];
}str_afn0e_erc33;

typedef struct {
	datetime happentime;    /*����ʱ��*/
	short      happentimeisnull;
	ushort    pn;            /*�������*/
	uchar     qzflag;          /*��/ֹ��־*/
	uchar    flaga, flagb, flagc;  /*��Ӧ�෢���쳣*/
	uchar    type;          /* D7��D6�������ʾ�쳣����*/
}str_afn0e_erc34;

typedef struct {
	str_add12  MeterAdd;      /*���ַ*/
	short      MeterAddisnull;    /*���ַΪ�ձ�־*/
	uchar       xw;            /*��λ*/
	uchar       xh;            /*�ź�Ʒ��*/
/*	short      XwXhisnull;    /*��λ���ź�Ϊ�ձ�־*/
	uchar       txxy;          /*ͨѶЭ��*/
/*	short      txxyisnull;    /*ͨѶЭ��Ϊ�ձ�־*/
}str_afn0e_erc35_meterinfo;
typedef struct {
	datetime happentime;    /*����ʱ��*/
	uchar     port;          /*D5��D0�� �ն�ͨ�Ŷ˿ںţ�1��31��*/
	uchar     number;          /*���ֿ���n*/
	str_afn0e_erc35_meterinfo  str_meterinfo[256];
}str_afn0e_erc35_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    port;          /*�ն�ͨ�Ŷ˿ں��пձ�־*/
	short    number;        /*���ֿ���n�пձ�־*/
}str_afn0e_erc35_isnull;
typedef struct {
	str_afn0e_erc35_val val;
	str_afn0e_erc35_isnull isnull;
}str_afn0e_erc35;

typedef struct {
	datetime happentime;    /*����ʱ��*/
	short      happentimeisnull;
	uchar     ztbw[4];          /*״̬��λ*/
	uchar     zt[4];          /*��λ��״̬*/
}str_afn0e_erc36;

typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort     pn;          /*�������*/
	int      kgcs;          /*�����ܴ���*/
	datetime starttime;    /*��ʼʱ��*/
	datetime endtime;    /*����ʱ��*/
	double   zxyg[2];    /*����ǰ�������й���ʾֵ*/
	double   fxyg[2];    /*����ǰ�����޹���ʾֵ*/
	double   wg1[2];    /*����ǰ��1�����޹���ʾֵ*/
	double   wg2[2];    /*����ǰ��2�����޹���ʾֵ*/
	double   wg3[2];    /*����ǰ��3�����޹���ʾֵ*/
	double   wg4[2];    /*����ǰ��4�����޹���ʾֵ*/
}str_afn0e_erc37_38_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
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
	datetime happentime;    /*����ʱ��*/
	ushort    pn;          /*�������*/
	datetime time;    /*���һ�γ���ɹ�ʱ��*/
	double   zxyg;    /*���һ�γ���ɹ������й��ܵ���ʾ*/
	double   zxwg;    /*���-�γ���ɹ������޹��ܵ���ʾ*/
}str_afn0e_erc39_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
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
	datetime happentime;    /*����ʱ��*/
	ushort    pn;          /*�������*/
	uchar     qzflag;          /*��ʼ��ʶ*/
	uchar     type;          /*�豸����*/
	uchar      addr[12];          /*�豸��ַ*/
	uchar     untype;        /*�ų��쳣����*/
}str_afn0e_erc40_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
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
	datetime happentime;    /*����ʱ��*/
	ushort    pn;          /*�������*/
	datetime time;    /*��ʱǰʱ��*/
	datetime newtime;    /*��ʱ��ʱ��*/
}str_afn0e_erc41_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
	short    pn;
	short    time;
	short    newtime;
}str_afn0e_erc41_isnull;
typedef struct {
	str_afn0e_erc41_val val;
	str_afn0e_erc41_isnull isnull;
}str_afn0e_erc41;

typedef struct {
	datetime happentime;    /*����ʱ��*/
	ushort    pn;          /*�������*/
	int      bjcs;               /*�Ե籨���ܴ���*/
	datetime fstime;       /*����ʱ��*/
	datetime jstime;       /*����ʱ��*/
	double   zxyg1;          /*����ʱ�������й��ܵ���*/
	double   fxyg1;          /*����ʱ�̷����й��ܵ���*/
	double   hxdl1;          /*����ʱ�̻��ߵ���*/
	double   lxdl1;          /*����ʱ�����ߵ���*/
	double   hxyggl1;          /*����ʱ�̻������й�����*/
	double   lxyggl1;          /*����ʱ���������й�����*/
	double   zxyg2;          /*����ʱ�������й��ܵ���*/
	double   fxyg2;          /*����ʱ�̷����й��ܵ���*/
	double   hxdl2;          /*����ʱ�̻��ߵ���*/
	double   lxdl2;          /*����ʱ�����ߵ���*/
	double   hxyggl2;          /*����ʱ�̻������й�����*/
	double   lxyggl2;          /*����ʱ���������й�����*/
}str_afn0e_erc42_val;
typedef struct {
	short    happentime;    /*����ʱ���пձ�־*/
/*	short    cldh;  */
/*	short      bjcs;               /*�Ե籨���ܴ���*/
	short fstime;       /*����ʱ��*/
	short jstime;       /*����ʱ��*/
	short   zxyg1;          /*����ʱ�������й��ܵ���*/
	short   fxyg1;          /*����ʱ�̷����й��ܵ���*/
	short   hxdl1;          /*����ʱ�̻��ߵ���*/
	short   lxdl1;          /*����ʱ�����ߵ���*/
	short   hxyggl1;          /*����ʱ�̻������й�����*/
	short   lxyggl1;          /*����ʱ���������й�����*/
	short   zxyg2;          /*����ʱ�������й��ܵ���*/
	short   fxyg2;          /*����ʱ�̷����й��ܵ���*/
	short   hxdl2;          /*����ʱ�̻��ߵ���*/
	short   lxdl2;          /*����ʱ�����ߵ���*/
	short   hxyggl2;          /*����ʱ�̻������й�����*/
	short   lxyggl2;          /*����ʱ���������й�����*/
}str_afn0e_erc42_isnull;
typedef struct {
	str_afn0e_erc42_val val;
	str_afn0e_erc42_isnull isnull;
}str_afn0e_erc42;

#endif

