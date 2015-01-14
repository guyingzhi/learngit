#ifndef ENCODE_AFN0D_FN1_224_H
#define ENCODE_AFN0D_FN1_224_H

#include "../public/encode_public.h"


typedef struct {
	datetime dt;
	uchar frz_m;  /*数据冻结密度*/
	uchar dat_cnt;  /*数据点数*/
}str_td_c;  /*曲线类数据时标*/

typedef struct {
	datetime dt;
}str_td_d;  /*日冻结类数据时标*/

typedef struct {
	datetime dt;
}str_td_m;  /*月冻结类数据时标*/



int  encodedataformatTD_C(uchar *buf, uint len_in, uchar *date);
int encodedataformatTD_d(uchar *buf, uint len_in, uchar *dat);
int encodedataformatTD_m(uchar *buf, uint len_in, uchar *date);




#endif

