# include "encode_AFN04_FN21_35.h"
int encode_frameA4F21(uchar *buf, uint len_in ,uchar *data)
{
	int len_out, li_i, li_j;
	uchar *p;
	p = buf;

      len_out = 49;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
       for(li_i = 0;li_i <48;li_i++)
       {
            li_j = *(p+li_i);
            if(li_j<0 || li_j >11)
                return ERROR_RANGE_DATA;
       }
       li_j = *(p+48);
       if(li_j<1 || li_j>12)
            return ERROR_RANGE_DATA;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F22(uchar *buf, uint len_in ,uchar *data)//费率数的取值范围？？？
{
	int len_out ,m;
	uchar *p;
	p = buf;

	if (len_in < 1)
	    return ERROR_FRAME_DATA_LENGTH;
	m= *p;
	if((m<1)||(m>12))                                          
		return ERROR_RANGE_DATA;
	len_out = 4*m + 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;		
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F23(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 3;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F25(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

	len_out = 11;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;	
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F26(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

	len_out = 57;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F27(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 24;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F28(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 4;
	if ( len_in < len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F29(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 12;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F30(uchar *buf, uint len_in ,uchar *data)
{
	int len_out =1;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in < len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F31(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      if (len_in < 1)
        return ERROR_FRAME_DATA_LENGTH;
      len_out = 6*(*p)+1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F33(uchar *buf, uint len_in ,uchar *data)
{
    int i,n,m,len_out;
    uchar *p;
    p = buf;

    if (len_in < 1)
        return ERROR_FRAME_DATA_LENGTH;
    n = *p;    
    if((n<1)||(n>31))
        return ERROR_RANGE_DATA;
    len_out = 1;
    for(i=0;i<n;i++)
    {
        if(len_in-len_out < 14)
            return ERROR_FRAME_DATA_LENGTH;
        m = *(p+len_out);
        if((m<1)||(m>31))
            return ERROR_RANGE_DATA;
        len_out += 13;
        m = *(p+len_out);
        if(m<0 || m>24)
            return ERROR_RANGE_DATA;
        len_out += m*2+1;
        if(len_in < len_out)
            return ERROR_FRAME_DATA_LENGTH;	
    }		
	memcpy(data,buf,len_out);
	return len_out;
}


int encode_frameA4F34(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n ,i, m;
	uchar *p;
	p = buf;

	if (len_in < 1)
	    return ERROR_FRAME_DATA_LENGTH;
	n = *p;
	if(n<1 || n>31)
	    return ERROR_RANGE_DATA;
	len_out = 6*n+1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	p+=1;
	for(i =0;i<n;i++)
	{
	      m = *p;
		if(m<1 || m>31)
			return ERROR_RANGE_DATA;
		p+=6;
	}
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F35(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n ,i, m;
	uchar *p;
	p = buf;

	if (len_in < 1)
	    return ERROR_FRAME_DATA_LENGTH;
	n =*p;
	if((n<0) || (n>20))
		return ERROR_RANGE_DATA;
	len_out = 2*n+1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;		
	p+=1;
	for(i=0;i<n;i++)
	{
	      m = *(p+1) << 8 | *p;
		if(m<1 || m>2040)
			return ERROR_RANGE_DATA;
		p+=2;
	}
	
	memcpy(data,buf,len_out);
	return len_out;
}