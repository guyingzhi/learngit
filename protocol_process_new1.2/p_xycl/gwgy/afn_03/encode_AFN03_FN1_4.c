#include "encode_AFN03_FN1_4.h"

int en_AFN03_FN1(uchar *buf, uint len_in, uchar *dat_out)
{	
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in < 1)							/*�ж����ݱ��ĳ���*/
		return ERROR_FRAME_DATA_LENGTH;

	if((*p & 0x03) != 0 && (*p & 0x03) != 3)
		return ERROR_DATA_INVALID;
	if(((*p >> 2) & 0x03) != 0 && ((*p >> 2) & 0x03) != 3)
		return ERROR_DATA_INVALID;

	len_out = 0;	
	*(dat_out + len_out++)  =  *p;								 /*  BIN  ��ת��ΪBCD   ��ʽ*/
	
	return len_out;
		
}

