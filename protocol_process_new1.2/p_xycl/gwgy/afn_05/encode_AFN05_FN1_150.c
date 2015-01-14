#include "encode_AFN05_FN1_150.h"

int encodedataformat05_F1(uchar *buf, uint len_in ,uchar *date)
{
	int len_out =0;
	uchar *p;
	p = buf;
	if ( len_in  <  1)
		return ERROR_FRAME_DATA_LENGTH ;
	len_out = 1;
	memcpy(date,buf,len_out);
	return len_out;
}
int encodedataformat05_F9(uchar *buf, uint len_in ,uchar *date)
{
	int len_out = 0;
	uchar *p;
	p = buf;
	if ( len_in  <  2)
		return ERROR_FRAME_DATA_LENGTH ;
	if (*(p + 1) > 3)
		return ERROR_RANGE_DATA;
	len_out = 2;
	memcpy(date,buf,len_out);
	return len_out;
}
int encodedataformat05_F12(uchar *buf, uint len_in ,uchar *date)
{
	int len_out = 0;
	uchar *p;
	p = buf;
	if ( len_in  <  8)
		return ERROR_FRAME_DATA_LENGTH ;
	if (*p < 1 || *p > 60)
		return ERROR_RANGE_DATA;
	if (*(p + 2) > 60 ||*(p + 2) < 5)
		return ERROR_RANGE_DATA;
	len_out = 8;
	memcpy(date,buf,len_out);
	return len_out;	
}
int encodedataformat05_F25(uchar *buf, uint len_in ,uchar *date)
{
	int len_out = 0;
	uchar *p;
	p = buf;
	if ( len_in  <  1)
		return ERROR_FRAME_DATA_LENGTH ;
	if (*p > 48  || *p  < 0)
		return ERROR_RANGE_DATA;
	len_out = 1;
	memcpy(date,buf,len_out);
	return len_out;		
}
int encodedataformat05_F30(uchar *buf, uint len_in ,uchar *date)
{
	int len_out;
	uchar *p;
	p = buf;
	if ( len_in < 1)
		return ERROR_FRAME_DATA_LENGTH ;
	len_out = 1;
	memcpy(date,buf,len_out);
	return len_out;
}

int encodedataformat05_F31(uchar *buf, uint len_in ,uchar *date)//秒分 时日月年
{
	int len_out=0;
	uchar *p;
	uchar  lc_week;
	p = buf;
	datetime adt_val;
	
	if ( len_in  <  6)
		return ERROR_FRAME_DATA_LENGTH ;
	memset(&adt_val, 0, sizeof(adt_val));
	adt_val.sec = BCDByteToByte(*p);
	adt_val.min = BCDByteToByte(*(p + 1));
	adt_val.hour = BCDByteToByte(*(p + 2));
	adt_val.day = BCDByteToByte(*(p + 3));
	adt_val.mon = BCDByteToByte(*(p + 4) & 0x1f);
	adt_val.year = BCDByteToByte(*(p + 5));
	
	if ( adt_val.sec < 0 || adt_val.sec > 59) 
		return ERROR_RANGE_DATETIME;
	if (adt_val.min < 0 || adt_val.min > 59) 
		return ERROR_RANGE_DATETIME;
	if (adt_val.hour < 0 || adt_val.hour > 23) 
		return ERROR_RANGE_DATETIME;
	switch(adt_val.mon)                                      /*判断大月和小月分别对应的月日数天*/
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (adt_val.day  < 1 || adt_val.day > 31)
			    return ERROR_RANGE_DATETIME;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (adt_val.day  < 1 || adt_val.day > 30)
			    return ERROR_RANGE_DATETIME;
			break;
		case 2:
			if (((adt_val.year + 2000) % 400) == 0 || (((adt_val.year + 2000) % 4)==0  && ((adt_val.year + 2000) % 100)!= 0) )	/*判断是否是闰年*/
			{
				if (adt_val.day  < 1 || adt_val.day > 29)
					return ERROR_RANGE_DATETIME;
			}else
			{
				if (adt_val.day < 1 || adt_val.day > 28)
					return ERROR_RANGE_DATETIME;
			}
			break;
		default:
			return ERROR_RANGE_DATETIME;
		}	

	/*年份规定在2000～2100年*/
/*	if (*(p + 5) < 100 || *(p + 5) > 126) 
		return ERROR_RANGE_DATETIME;*/
	 f_get_week(&adt_val, &lc_week);
	if (lc_week < 1 || lc_week > 7) 
	 	return ERROR_RANGE_DATETIME;
	*(date + len_out++) = *p;
	*(date + len_out++) = *(p + 1);
	*(date + len_out++) = *(p + 2);
	*(date + len_out++) = *(p + 3);
	*(date + len_out++) = *(p + 4);
	*(date + len_out++) = *(p + 5);
	
	return len_out;
}
int encodedataformat05_F32(uchar *buf, uint len_in ,uchar *date)
{
	int len_out;
	uchar *p;
	p = buf;
	if ( len_in  <  2 || len_in >202)
		return ERROR_FRAME_DATA_LENGTH ;
	len_out = len_in;
	memcpy(date,buf,len_out);
	return len_out;		
		
}
int encodedataformat05_F41(uchar *buf, uint len_in ,uchar *date)
{
	int len_out;
	uchar *p;
	p = buf;
	if ( len_in  <  2)
		return ERROR_FRAME_DATA_LENGTH ;
	len_out = 2;
	memcpy(date,buf,len_out);
	return len_out;
}
int encodedataformat05_F42(uchar *buf, uint len_in ,uchar *date)
{
	int len_out = 0;
	uchar *p;
	p = buf;
	if ( len_in  <  2)
		return ERROR_FRAME_DATA_LENGTH ;
	len_out = 2;
	memcpy(date,buf,len_out);
	return len_out;
}
int encodedataformat05_F49(uchar *buf, uint len_in ,uchar *date)
{
	int len_out = 0;
	uchar *p;
	p = buf;
	if ( len_in  <  1)
		return ERROR_FRAME_DATA_LENGTH ;
	if (*p < 1 || *p > 31)
		return ERROR_RANGE_DATA;
	len_out = 1;
	memcpy(date,buf,len_out);
	return len_out;
}
int encodedataformat05_F149(uchar *buf, uint len_in ,uchar *date)
{
	int len_out = 0;
	uchar *p;
	p = buf;
	if ( len_in  <  1)
		return ERROR_FRAME_DATA_LENGTH ;
	len_out = 1;
	memcpy(date,buf,len_out);
	return len_out;	
}