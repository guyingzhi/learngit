#include "encode_AFN10_FN1_13.h"


int  encode_frame10F1(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,k;
	uchar *p;
	p = buf;

	k = *(p+5)<<8 + *(p+4);

	if ( len_in  <  k+6)
		return ERROR_FRAME_DATA_LENGTH  ;
	if((*p>31) || (*p < 1))
		return ERROR_RANGE_DATA;
	
	len_out = k+6;
	memcpy(data,p,len_out);
	return len_out;
}

int  encode_frame10F9(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n;
	int i =0;
	uchar *p,*q;
	p = buf;
	q = buf;

	n = *(p+1);

	if ( len_in  <  6*n+13)
		return ERROR_FRAME_DATA_LENGTH  ;
	if((*p>31) || (*p < 1))
		return ERROR_RANGE_DATA;

	if((n <0) ||(n>32))
		return ERROR_RANGE_DATA;
	p+=2;
	for(i;i<=6*n ; i++)
	{
		*(p+i) = ByteToBCDByte (*(p+i));
	}
		
	
	len_out = 6*n+13;
	memcpy(data,q,len_out);
	return len_out;
}

int  encode_frame10F10(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n,k;
	int i =0;
	uchar *p,*q;
	p = buf;
	q = buf;

	n = *(p+1);
	k = *(p+6*n+3);

	if ( len_in  <  k+6*n+10)
		return ERROR_FRAME_DATA_LENGTH  ;
	if((*p>31) || (*p < 1))
		return ERROR_RANGE_DATA;

	if((n<0) ||(n>32))
		return ERROR_RANGE_DATA;
	if(((*(p+6*n+8))!=0xAA)&&((*(p+6*n+8))!=0x55))
		return ERROR_RANGE_DATA ;
	
	p+=2;
	for(i;i<=6*n ; i++)
	{
		*(p+i) = ByteToBCDByte (*(p+i));
	}
		
	
	len_out =  k+6*n+10;
	memcpy(data,q,len_out);
	return len_out;
}

int  encode_frame10F11(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n,k;
	int i =0;
	uchar *p,*q;
	p = buf;
	q = buf;

	n = *(p+1);
	k = *(p+6*n+3);

	if ( len_in  <  k+6*n+10)
		return ERROR_FRAME_DATA_LENGTH  ;
	if((*p>31) || (*p < 1))
		return ERROR_RANGE_DATA;

	if((n<0) ||(n>32))
		return ERROR_RANGE_DATA;
	if(((*(p+6*n+8))!=0xAA)&&((*(p+6*n+8))!=0x55))
		return ERROR_RANGE_DATA ;
	
	p+=2;
	for(i;i<=6*n ; i++)
	{
		*(p+i) = ByteToBCDByte (*(p+i));
	}
		
	
	len_out =  k+6*n+10;
	memcpy(data,q,len_out);
	return len_out;
}


int  encode_frame10F12(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,ln,n;
	uchar *p;
	p = buf;
	ln = *(p+4)<<8 + *(p+3);
	n = *(p+ln+5) + *(p+ln+6)<<8;
	if ( len_in  <  40*n+ln+7)
		return ERROR_FRAME_DATA_LENGTH  ;
	len_out =  40*n+ln+7;
	memcpy(data,p,len_out);
	return len_out;
}

int  encode_frame10F13(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;
	
	if ( len_in  < 1)
		return ERROR_FRAME_DATA_LENGTH  ;
	len_out =  1;
	memcpy(data,p,len_out);
	return len_out;
}

