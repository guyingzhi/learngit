#ifndef PUBLIC_H
#define PUBLIC_H

#include <stdio.h> 
#ifdef _WIN32
#include "..\..\..\p_com\common.h"
#include "..\..\..\p_com\redis_common.h"
#else
#include "../../../p_com/common.h"
#include "../../../p_com/redis_common.h"
#endif
#include <math.h>
#include "error_code.h"

#define  KB  1024
#define  MB  1048576  //1024*1024

#define  FRAME_MAXLEN  (17*KB)  //֡��󳤶�
#define  USRDATA_MAXLEN  16383  //�û���������󳤶� 
#define  PROT_MAXLEN  (USRDATA_MAXLEN+8)
#define  FNAME_MAXLEN  256

#define  DOWN_READ_FILE    (0)
#define  UP_READ_FILE      (1)
#define  UP_WRITE_FILE     (2)

#define  REDIS_GREENCHNEL_FLAG  0
#define  HASH_TERMINFO_KEYLEN  256
#define  HASH_TERMINFO_VALEN  50



extern short gi_save_log;
extern short gi_save_data;


/****************************** XML *************************************/
#define RANDOM_LENS 100

typedef struct
{
	char ywbzm[7];				  //ҵ���ʶ��
	char term_prottype[3]; 	      //�ն�Э������
	char term_addr[13];			//�ն˵�ַ
	char msa[4];					 //MSA
	char mul_fn[1024]; 			//������,���256��
	char mul_pn[10240];	      //��ɼ����б�,���2040��
}str_inter_char;


typedef struct str_bytesframe_t
{
    uchar bytes[FRAME_MAXLEN];    /*�����ֽ�����*/
    uint  len;             /*���ĳ���*/
}str_bytesframe;



typedef struct str_dataflag_t
{
    uchar DA1;       /*��Ϣ��1*/
    uchar DA2;       /*��Ϣ��2*/
    uchar DT1;       /*��Ϣ��1*/
    uchar DT2;       /*��Ϣ��2*/
}str_dataflag;


//typedef struct str_sendframe_t
//{
//    uchar		gy;			/* ��Լ���� 01��2009��Լ 03��2012��Լ */
//	uint		l;			/* �������ݳ��� */
//	uchar		dir;		/* ������C�� DIR */
//	uchar		prm;		/* ������C�� PRM */
//	uchar		fcb;		/* ������C�� FCB����ACD��ͬ */
//	uchar		acd;		/* ������C�� ACD����FCB��ͬ */
//	uchar		fcv;		/* ������C�� FCV */
//	uchar		fun;		/* ������C�� ������ */
//	uint		addr;		/* �ն˵�ַ��9λ��ʮ������ */
//	uchar		addrflag;	/* �ն����ַ��־ */
//	uchar		msa;		/* ��վ��ַ MSA */
//	uchar		afn;		/* Ӧ�ò㹦���� AFN */
//	uchar		tpv;		/* ֡������SEQ�е� TpV */
//	uchar		fir;		/* ֡������SEQ�е� FIR */
//	uchar		fin;		/* ֡������SEQ�е� FIN */
//	uchar		con;		/* ֡������SEQ�е� CON */
//	uchar		seq;		/* ֡������SEQ�е� PSEQ/RSEQ */
//	uchar		data[USRDATA_MAXLEN];/* �û�������ͷ����֡������SEQ��ʼ */
//} str_sendframe;


extern int base64_decode(const char *src, int i_len,int *o_len,char *des);
extern int base64_encode(char *src,int i_len,int *o_len,char *des);

extern uchar BCDByteToByte(uchar ac_BCD);
extern void f_get_week(datetime *adt_datetime, uchar *ac_week);
extern int AddTP(uchar *astr_out, uchar pfc, int *ai_size);

extern int termal_info_key(uint termal_addr, char *key, int max_keylen);




#endif

