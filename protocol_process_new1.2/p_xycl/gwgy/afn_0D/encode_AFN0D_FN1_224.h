#ifndef ENCODE_AFN0D_FN1_224_H
#define ENCODE_AFN0D_FN1_224_H

#include "../public/encode_public.h"


typedef struct {
	datetime dt;
	uchar frz_m;  /*���ݶ����ܶ�*/
	uchar dat_cnt;  /*���ݵ���*/
}str_td_c;  /*����������ʱ��*/

typedef struct {
	datetime dt;
}str_td_d;  /*�ն���������ʱ��*/

typedef struct {
	datetime dt;
}str_td_m;  /*�¶���������ʱ��*/



int  encodedataformatTD_C(uchar *buf, uint len_in, uchar *date);
int encodedataformatTD_d(uchar *buf, uint len_in, uchar *dat);
int encodedataformatTD_m(uchar *buf, uint len_in, uchar *date);




#endif

