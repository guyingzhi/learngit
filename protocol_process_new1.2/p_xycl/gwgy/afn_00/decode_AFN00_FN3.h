#ifndef DECODE_AFN00_FN3_H
#define DECODE_AFN00_FN3_H

#include "../public/decode_public.h"


typedef struct{
	uchar afn;       /*AFN*/
	short len;       /*数据单元标识个数*/
	uchar pn[255];   /*PN*/
	uchar fn[255];   /*FN*/
	uchar err[255];  /*0:正确,1:其它错误,2:表地址重复*/
}str_AFN00_F3;



extern int decode_AFN00_F3(uchar *lc_p, str_encode_param *astr_frame, int *li_step, int ai_len, char *lc_buf);

#endif

