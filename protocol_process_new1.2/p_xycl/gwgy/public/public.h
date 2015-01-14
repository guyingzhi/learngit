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

#define  FRAME_MAXLEN  (17*KB)  //帧最大长度
#define  USRDATA_MAXLEN  16383  //用户数据区最大长度 
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
	char ywbzm[7];				  //业务标识码
	char term_prottype[3]; 	      //终端协议类型
	char term_addr[13];			//终端地址
	char msa[4];					 //MSA
	char mul_fn[1024]; 			//功能码,最多256个
	char mul_pn[10240];	      //多采集点列表,最多2040个
}str_inter_char;


typedef struct str_bytesframe_t
{
    uchar bytes[FRAME_MAXLEN];    /*报文字节内容*/
    uint  len;             /*报文长度*/
}str_bytesframe;



typedef struct str_dataflag_t
{
    uchar DA1;       /*信息点1*/
    uchar DA2;       /*信息点2*/
    uchar DT1;       /*信息类1*/
    uchar DT2;       /*信息类2*/
}str_dataflag;


//typedef struct str_sendframe_t
//{
//    uchar		gy;			/* 规约类型 01：2009规约 03：2012规约 */
//	uint		l;			/* 报文数据长度 */
//	uchar		dir;		/* 控制域C中 DIR */
//	uchar		prm;		/* 控制域C中 PRM */
//	uchar		fcb;		/* 控制域C中 FCB，和ACD相同 */
//	uchar		acd;		/* 控制域C中 ACD，和FCB相同 */
//	uchar		fcv;		/* 控制域C中 FCV */
//	uchar		fun;		/* 控制域C中 功能码 */
//	uint		addr;		/* 终端地址，9位的十进制数 */
//	uchar		addrflag;	/* 终端组地址标志 */
//	uchar		msa;		/* 主站地址 MSA */
//	uchar		afn;		/* 应用层功能码 AFN */
//	uchar		tpv;		/* 帧序列域SEQ中的 TpV */
//	uchar		fir;		/* 帧序列域SEQ中的 FIR */
//	uchar		fin;		/* 帧序列域SEQ中的 FIN */
//	uchar		con;		/* 帧序列域SEQ中的 CON */
//	uchar		seq;		/* 帧序列域SEQ中的 PSEQ/RSEQ */
//	uchar		data[USRDATA_MAXLEN];/* 用户数据体头，从帧序列域SEQ后开始 */
//} str_sendframe;


extern int base64_decode(const char *src, int i_len,int *o_len,char *des);
extern int base64_encode(char *src,int i_len,int *o_len,char *des);

extern uchar BCDByteToByte(uchar ac_BCD);
extern void f_get_week(datetime *adt_datetime, uchar *ac_week);
extern int AddTP(uchar *astr_out, uchar pfc, int *ai_size);

extern int termal_info_key(uint termal_addr, char *key, int max_keylen);




#endif

