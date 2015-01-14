#ifndef DECODE_AFN0D_H_INCLUDED
#define DECODE_AFN0D_H_INCLUDED

#include "../public/decode_public.h"
#include "decode_AFN0D_public.h"
#include "decode_AFN0D_FN17_24.h"
#include "decode_AFN0D_FN25_32.h"
#include "decode_AFN0D_FN33_39.h"
#include "decode_AFN0D_FN41_46.h"
#include "decode_AFN0D_FN49_54.h"
#include "decode_AFN0D_FN57_66.h"
#include "decode_AFN0D_FN73_88.h"
#include "decode_AFN0D_FN89_104.h"
#include "decode_AFN0D_FN105_112.h"
#include "decode_AFN0D_FN217_219.h"
#include "decode_AFN0D_FN209_216.h"
#include "decode_AFN0D_FN201_208.h"
#include "decode_AFN0D_FN193_200.h"
#include "decode_AFN0D_FN145_152.h"
#include "decode_AFN0D_FN153_160.h"
#include"decode_AFN0D_FN193_200.h"
#include"decode_AFN0D_FN113_120.h"
#include"decode_AFN0D_FN121_128.h"
#include"decode_AFN0D_FN129_136.h"
#include "decode_AFN0D_FN137_144.h"

int decode_AFN0D(str_encode_param *astr_frame);




int de_AFN0D_FN1_2_9_10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F113_115(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F116_118(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F121_123(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F124_126(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F129(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F130(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F138(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);


int de_AFN0D_F145_148(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F177F179(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_Idlemon(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F185_192(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F193_196(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_Activeenergy(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len);
int de_AFN0D_Idleenergy(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len);
int de_AFN0D_Activeenergymon(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len);
int de_AFN0D_Idleenergymon(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len);

int de_AFN0D_Activeenergyday(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len);
int de_AFN0D_Idleday(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len);


int de_AFN0D_F201F208(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

int de_AFN0D_F209(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F210(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F211(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F212(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F213(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F214(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F215(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F216(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);


int de_AFN0D_F217(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F218(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);
int de_AFN0D_F219(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);




#endif


