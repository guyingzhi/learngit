#ifndef DECODE_AFN00_FN3_H
#define DECODE_AFN00_FN3_H

#include "../public/decode_public.h"


typedef struct{
	uchar afn;       /*AFN*/
	short len;       /*���ݵ�Ԫ��ʶ����*/
	uchar pn[255];   /*PN*/
	uchar fn[255];   /*FN*/
	uchar err[255];  /*0:��ȷ,1:��������,2:���ַ�ظ�*/
}str_AFN00_F3;



extern int decode_AFN00_F3(uchar *lc_p, str_encode_param *astr_frame, int *li_step, int ai_len, char *lc_buf);

#endif

