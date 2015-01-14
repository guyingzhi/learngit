#include "encode_AFN0B_FN1_2.h"

int en_AFN0B_FN2(uchar *buf, uint len_in, uchar *dat_out)
{	
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in < 5)							/*判断数据报文长度*/
		return ERROR_FRAME_DATA_LENGTH;

	if ((*(p + 4) < 0) ||*(p + 4) >59 ) 					  /*判断日期分是否超出范围*/
		return ERROR_RANGE_DATETIME;
	if (*(p + 3) < 1 ||*(p + 3) > 23)			 /*判断日期时是否超出范围*/
		return ERROR_RANGE_DATETIME;
	
	switch(*(p + 1))									  /*判断大月和小月分别对应的月日数天*/
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (*(p + 2)  < 1 ||*(p +2) > 31)
				return ERROR_RANGE_DATETIME;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (*(p + 2)  < 1 ||*(p + 2) > 30)
				return ERROR_RANGE_DATETIME;
			break;
		case 2:
			if (((*p + 2000) % 400) == 0 || (((*p + 2000) % 4) == 0 && ((*p + 2000) % 100) != 0))	/*判断是否是闰年*/
			{
				if (*(p + 2)  < 1 ||*(p + 2) > 29)
					return ERROR_RANGE_DATETIME;
			}else
			{
				if (*(p + 2)  < 1 ||*(p + 2) > 28)
					return ERROR_RANGE_DATETIME;
			}
			break;
		default:
			return ERROR_RANGE_DATETIME;
		}	

//	if (*(p+ 4) < 114||*(p + 4) > 126)										   /*日期年的范围2014到2100*/
//		return ERROR_RANGE_DATETIME;	
	
	len_out = 0;
	*(dat_out + len_out++)=  ByteToBCDByte(*(p + 4));					 /*  BIN  码转化为BCD	格式*/
	*(dat_out + len_out++)  =	ByteToBCDByte(*(p +3));
	*(dat_out + len_out++)  =	ByteToBCDByte(*(p + 2));
	*(dat_out + len_out++)  =	ByteToBCDByte(*(p + 1));
	*(dat_out + len_out++)  =	ByteToBCDByte(*p);
	
	return len_out; 

		
}



