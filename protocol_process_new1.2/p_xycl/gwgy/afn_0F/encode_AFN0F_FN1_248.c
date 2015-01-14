#include "encode_AFN0F_FN1_248.h"


int en_AFN0F_FN1(uchar *buf, uint len_in, uchar *dat_out)
{	
	int len_out, li_i;
	uchar *p;
	p = buf;
	
	if ( len_in < 11)							/*判断数据报文长度*/
		return ERROR_FRAME_DATA_LENGTH;
	if (*p > 0x07)  /*文件标识*/
		return ERROR_DATA_INVALID;
	if (*(p + 1) > 0x01)   /*文件属性,起始、中间帧：00H；结束帧：01H*/
		return ERROR_DATA_INVALID;
	if (*(p + 1) > 0x02)   /*文件指令,00H：报文方式下装；01H：FTP方式下装；02H：启动组地址升级*/
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

