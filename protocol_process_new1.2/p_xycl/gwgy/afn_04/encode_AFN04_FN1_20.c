# include "encode_AFN04_FN1_20.h"

int encode_frameA4F1(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

	if ( len_in  <  6)
		return ERROR_FRAME_DATA_LENGTH;
	len_out = 6;
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F2(uchar *buf, uint len_in ,uchar *data)
{
    int len_out,m;
    uchar *p;
    p = buf;

    if (len_in < 1)
        return ERROR_FRAME_DATA_LENGTH;
    m = (*p) & 0x7F;
    if((m<0) || (m>16))
        return ERROR_RANGE_DATA;
    len_out = 2*m+1;
    if ( len_in  <  len_out)
        return ERROR_FRAME_DATA_LENGTH;
    memcpy(data, buf, len_out);
    return len_out;	
}

int encode_frameA4F3(uchar *buf, uint len_in ,uchar *data)//BINè½¬asciiï¼Ÿï¼Ÿï¼Ÿ
{
	int len_out,i;
	uchar *p;
	p = buf;

	len_out = 28;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;	
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F4(uchar *buf, uint len_in ,uchar *data)
{
	int len_out , i;
	uchar *p ,*q;
	p = buf;

      len_out = 16;
	if ( len_in < len_out)
		return ERROR_FRAME_DATA_LENGTH  ;
/*	for(i = 0; i<16;i++)
	{
		if(((*p & 0x0F)<0)||((*p & 0x0F)>11))
			return ERROR_RANGE_DATA;
		if(((*p >> 4) & 0x0F) < 0 || ((*p >> 4) & 0x0F) > 11)
			return ERROR_RANGE_DATA;
		p += 1;
	}*/
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F5(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 3;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH  ;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F6(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 16;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH  ;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F7(uchar *buf, uint len_in ,uchar *data)
{
    int len_out , m , n,i;
    uchar *p;
    p = buf;

    if ( len_in < 24) 
        return ERROR_FRAME_DATA_LENGTH;
    m = *(p+20);
    if (m < 0 || m > 20)
        return  ERROR_RANGE_DATA;
    n = *(p+20+m+1);
    if (n < 0 || n > 20)
        return  ERROR_RANGE_DATA;
    len_out = 24+m+n;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH;
    if(*(p+12)<0 ||*(p+12)>3)
        return  ERROR_RANGE_DATA;
    if(*(p+19)<0 || *(p+19)>1)
        return  ERROR_RANGE_DATA ;

    memcpy(data, buf,len_out);
    return len_out;
}

int encode_frameA4F8(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p,*q;
	p = buf;

      len_out = 8;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH  ;
	
	if((*p & 0x03)<1 || (*p & 0x03)>3)
		return ERROR_RANGE_DATA;
	if(((*p >> 4) & 0x03)<0 || ((*p >> 4) & 0x03)>2)
		return ERROR_RANGE_DATA;
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F9(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 16;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH  ;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F10(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,m,n,i;
	uchar *p;
	p = buf;

      if (len_in < 2)
          return ERROR_FRAME_DATA_LENGTH;
      n = *(p+1) << 8 | *p;
	if(n<0 || n>2040)
		return ERROR_RANGE_DATA;
	len_out = 27*n + 2;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	p+=2;
	for(i = 0;i<n;i++)
	{
	       m = *(p + 1) << 8 | *p;
		if(m<1 || m>2040)
			return ERROR_RANGE_DATA;
		m = *(p+3) << 8 | *(p+2);
		if(m<0 || m>2040)
			return ERROR_RANGE_DATA;
		m = *(p+4)&0x1F;
		if(m<1 || m>31)
			return ERROR_RANGE_DATA;
		m = *(p+18)&0x3F;
		if(m<1 || m>12)
			return ERROR_RANGE_DATA;
		p+=27;
	}
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F11(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n,i,m;
	uchar *p;
	p = buf;

	if (len_in < 1)
	    return ERROR_FRAME_DATA_LENGTH;
      n= *p;
      if((n<0) ||(n>64))
		return ERROR_RANGE_DATA;
      len_out = 5*n+1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;		
	p += 1;
	for(i=0;i<n;i++)
	{
	      m = *p;
		if(m<1 || m>64)
			return ERROR_RANGE_DATA;
		m = *(p+1);	
		if(m<0 || m>64)
			return ERROR_RANGE_DATA;
		p += 5;
	}

	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F12(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 2;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH  ;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F13(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n,i,m;
	uchar *p,*q;
	p = buf;

      if (len_in < 1)
        return ERROR_FRAME_DATA_LENGTH;
      n = *p;
      if((n<0) ||(n>64))
		return ERROR_RANGE_DATA;
	len_out = 3*n + 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
      p += 1;
	for(i =0 ;i<n ;i++)
	{
	      m = *p;
		if(m<1 || m>64)
			return ERROR_RANGE_DATA;
		m = *(p+1);
		if(m<0 || m>64)
			return ERROR_RANGE_DATA;
		m = *(p+2) & 0x07;
		if(m<0 || m>5)
			return ERROR_RANGE_DATA;
		p += 3;
	}
		
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F14(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,n,i ,j;
	uchar *p,*q;
	p = buf;	 

    if (len_in < 3)
        return ERROR_FRAME_DATA_LENGTH;
    n = *p;  /*×Ü¼Ó×éÅäÖÃÊýÁ¿*/
    if((n<1) ||(n>8))
        return ERROR_RANGE_DATA;
    len_out = 1;
    for(i =0 ;i<n ;i++)
    {
        if (len_in - len_out < 2)
            return ERROR_FRAME_DATA_LENGTH;
        j = *(p+len_out);
        if(j<1 || j>8)
            return ERROR_RANGE_DATA;
        len_out++;
        j = *(p+len_out);
        if (j < 0 || j > 64)
            return ERROR_RANGE_DATA;
        len_out += 1+j;
        if (len_in < len_out)
            return ERROR_FRAME_DATA_LENGTH;    
    }
    memcpy(data,buf,len_out);
    return len_out;
}

int encode_frameA4F15(uchar *buf, uint len_in ,uchar *data)
{
    int len_out,n,i ,m;
    uchar *p,*q;
    p = buf;    

    if (len_in < 10)
        return ERROR_FRAME_DATA_LENGTH;
    n = *p;  /*²î¼Ó×éÅäÖÃÊýÁ¿*/
    if((n<1) ||(n>8))
        return ERROR_RANGE_DATA;
    len_out = 9*n+1;
    if (len_in < len_out)
       return ERROR_FRAME_DATA_LENGTH;
    p += 1;
    for(i =0 ;i<n ;i++)
    {
        m = *p;
        if((m<1) ||(m>8))
            return ERROR_RANGE_DATA;
        m = *(p+1);
        if(m<0 || m>8)  
            return ERROR_RANGE_DATA;  
        m = *(p+2);
        if(m<0 || m>8)  
            return ERROR_RANGE_DATA;
        m = *(p+3) & 0x03;
        if(m<0 || m>2)
           return ERROR_RANGE_DATA;     
        p+=9;
    }
    memcpy(data,buf,len_out);
    return len_out;
}

int encode_frameA4F16(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,i;
	uchar *p;
	p = buf;

      len_out = 64;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH ;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F17(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 2;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH ;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F18(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

	len_out = 12;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH ;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F19(uchar *buf, uint len_in ,uchar *data)
{
	int len_out =1;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH ;

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F20(uchar *buf, uint len_in ,uchar *data)
{
	int len_out =1;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH ;

	memcpy(data, buf,len_out);
	return len_out;
}