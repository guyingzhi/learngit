#ifndef DECODE_AFN0F_FN1_248_H
#define DECODE_AFN0F_FN1_248_H

#include "../public/decode_public.h"

typedef struct {
	uint seg_flg;  /*当前段标识或偏移*/
}str_afn0f_f1;



extern int de_AFN0F_FN1(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len);

#endif

