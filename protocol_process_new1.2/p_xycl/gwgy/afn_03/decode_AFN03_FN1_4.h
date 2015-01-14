#ifndef DECODE_AFN03_FN1_4_H
#define DECODE_AFN03_FN1_4_H

#include "../public/decode_public.h"

typedef struct {
	uchar    apc_sta : 2;    /*A机状态，编码表示0～3，0：不存在，1：正常，2：故障，3：备用*/
	uchar    apc_type : 1;    /*置0：A机为备份机，置1：A机为值班机*/
	uchar    apc_relay_yorn : 1;    /*置0：A机禁止中继转发，置1：A机允许中继转发*/
	uchar    bpc_sta : 2;
	uchar    bpc_type : 1;
	uchar    bpc_relay_yorn : 1;
}str_relay_sta;

typedef struct {
	datetime chg_time[10];
	uchar bef_chgsta[10];
	uchar after_chgsta[10];
}str_relay_chgsta_val;  //中继站工作状态切换记录

typedef struct {
	short chg_time[10];
}str_relay_chgsta_isnull;

typedef struct {
	str_relay_chgsta_val val;
	str_relay_chgsta_isnull isnull;
}str_relay_chgsta;


typedef struct {
	ushort chg_cnt;
	ushort apc_onduty;
	ushort apc_normal;
	ushort bpc_onduty;
	ushort bpc_normal;
}str_relay_runsta;

extern int de_AFN03_FN1_2(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
extern int de_AFN03_FN3(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
extern int de_AFN03_FN4(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);



#endif
