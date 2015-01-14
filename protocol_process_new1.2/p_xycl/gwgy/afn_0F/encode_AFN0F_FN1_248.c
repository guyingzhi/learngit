#include "encode_AFN0F_FN1_248.h"


int en_AFN0F_FN1(uchar *buf, uint len_in, uchar *dat_out)
{	
	int len_out, li_i;
	uchar *p;
	p = buf;
	
	if ( len_in < 11)							/*�ж����ݱ��ĳ���*/
		return ERROR_FRAME_DATA_LENGTH;
	if (*p > 0x07)  /*�ļ���ʶ*/
		return ERROR_DATA_INVALID;
	if (*(p + 1) > 0x01)   /*�ļ�����,��ʼ���м�֡��00H������֡��01H*/
		return ERROR_DATA_INVALID;
	if (*(p + 1) > 0x02)   /*�ļ�ָ��,00H�����ķ�ʽ��װ��01H��FTP��ʽ��װ��02H���������ַ����*/
		return ERROR_DATA_INVALID;
	li_i = (*(p + 10) << 8) | *(p + 9);
	if (len_in < li_i + 11)
		return ERROR_FRAME_DATA_LENGTH;

	len_out = 0;
	memcpy(dat_out, p, 11);
	len_out += 11;
	memcpy(dat_out + len_out, p + len_out, li_i);
	len_out += li_i;

	return len_out;		
}

