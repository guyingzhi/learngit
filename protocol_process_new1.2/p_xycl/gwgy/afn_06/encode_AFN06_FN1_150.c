#include "encode_AFN06_FN1_150.h"
int encode_frame06F12(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,ln;
	uchar *p;
	p = buf;
	ln = *p + (*(p+1))*256 - 86;
	if ( len_in  <  (ln+88))
		return ERROR_FRAME_DATA_LENGTH  ;
	if(((*(p+3)) != 0) ||((*(p+3)) != 1))
		return ERROR_RANGE_DATA;
	len_out = ln+88;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F13(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,ln;
	uchar *p;
	p = buf;
	ln = *p + (*(p+1))*256 - 181;
	if ( len_in  <  (ln+183))
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out = ln+183;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F14(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n;
	uchar *p;
	p = buf;
	n = *(p+1);
	if ( len_in  <  (32*n +2))
		return ERROR_FRAME_DATA_LENGTH  ;
	if(n>60)
		return ERROR_RANGE_DATA;
	len_out =32*n +2;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F16(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,ln;
	uchar *p;
	p = buf;
	ln = *p + (*(p+1))*256 ;
	if ( len_in  <  (ln +2))
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out =ln+2;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F17(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in  <  16)
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out =16;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F18(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in  <  16)
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out =16;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F19(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in  <  21)
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out =21;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F20(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in  <  20)
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out =20;
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frame06F21(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in  <  32)
		return ERROR_FRAME_DATA_LENGTH  ;

	len_out =32;
	memcpy(data,p,len_out);
	return len_out;
}


