# include "encode_AFN04_FN36_150.h"
int encode_frameA4F36(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 4;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F37(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,i,n;
	uchar *p;
	p = buf;

      if (len_in < 7)
        return ERROR_FRAME_DATA_LENGTH;

	n=*(p+6) & 0x0F;	
	if(((*(p+6)>>7) &0x80)==0)
	{
		if((n<0) || (n>3))
			return ERROR_RANGE_DATA;
	}
	else
	{
		if(n > 1) 
			return ERROR_RANGE_DATA;
	}
	len_out = 4*n+7;
	if ( len_in < len_out)
		return ERROR_FRAME_DATA_LENGTH;
      i = *p;
	if((i<0) || (i>31))
		return ERROR_RANGE_DATA;
	i = *(p+4);
	if((i<0) || (i>3))
		return ERROR_RANGE_DATA;

/*	if((*p<1) || (*p>60))
		return ERROR_RANGE_DATA;*/
	
	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F38(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,m,i;
	uchar *p;
	p = buf;

	if (len_in < 2)
	    return ERROR_FRAME_DATA_LENGTH;
	m = *p;
	if((m<0)||(m>15))
		return ERROR_RANGE_DATA;
	m = *(p+1);
	if((m<1)||(m>16))	
		return ERROR_RANGE_DATA;
	len_out = 2;	
	for(i=0;i<m;i++)
	{
	      if (len_in - len_out < 2)
	            return ERROR_FRAME_DATA_LENGTH;
	      m = *(p+len_out);
		if((m<0)||(m>15))
		    return ERROR_RANGE_DATA;
		len_out++;
		m = *(p+len_out);
		if((m<0) || (m>31))
		    return ERROR_RANGE_DATA;
		len_out += m+1;
		if (len_in < len_out)		
		    return ERROR_FRAME_DATA_LENGTH;
	}

	memcpy(data, buf,len_out);
	return len_out;
}


int encode_frameA4F39(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,m,i;
	uchar *p;
	p = buf;

	if (len_in < 2)
	    return ERROR_FRAME_DATA_LENGTH;
	m = *p;
	if((m<0)||(m>15))
		return ERROR_RANGE_DATA;
	m = *(p+1);
	if((m<1)||(m>16))	
		return ERROR_RANGE_DATA;
	len_out = 2;	
	for(i=0;i<m;i++)
	{
	      if (len_in - len_out < 2)
	            return ERROR_FRAME_DATA_LENGTH;
	      m = *(p+len_out);
		if((m<0)||(m>15))
		    return ERROR_RANGE_DATA;
		len_out++;
		m = *(p+len_out);
		if((m<0) || (m>31))
		    return ERROR_RANGE_DATA;
		len_out += m+1;
		if (len_in < len_out)		
		    return ERROR_FRAME_DATA_LENGTH;
	}

	memcpy(data, buf,len_out);
	return len_out;
}

int encode_frameA4F41(uchar *buf, uint len_in ,uchar *data)//写的很乱有待改进
{
    int len_out,li_i,li_j,li_k,m,n;
    uchar *p;
    p = buf;

    if (len_in < 1)
        return ERROR_FRAME_DATA_LENGTH;
    len_out = 1;
    for (li_i = 0; li_i < 3; li_i++) {
        if ((*p >> li_i) & 0x01) {
            if (len_in - len_out < 1)
                return ERROR_FRAME_DATA_LENGTH;
            m = *(p+len_out);
            len_out++;
            for (li_j = 0, li_k = 0; li_j < 8; li_j++) {
                if ((m >> li_j) & 0x01)
                    li_k++;
            }
            len_out += 2*li_k;
            if (len_in < len_out)
                return ERROR_FRAME_DATA_LENGTH;
        }
    }
    	
    memcpy(data, buf, len_out);
    return len_out;
}
int encode_frameA4F42(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,li_i;
	uchar *p;
	p = buf;

      len_out = 6;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	li_i = *(p+4);
       if(li_i<1 || li_i>48)
            return ERROR_RANGE_DATA;
	
	memcpy(data, buf, len_out);
	return len_out;
}

int encode_frameA4F43(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
      if ((*p<1) || (*p>60))
            return  ERROR_RANGE_DATA; 
	
	memcpy(data, buf, len_out);
	return len_out;
}
int encode_frameA4F44(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,li_i;
	uchar *p;
	p = buf;

      len_out = 8;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
    
	memcpy(data, buf, len_out);
	return len_out;
}
int encode_frameA4F45(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}
int encode_frameA4F46(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,li_i;
	uchar *p;
	p = buf;

	len_out = 5;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frameA4F47(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,li_i ;
	uchar *p;
	p = buf;

	len_out = 17;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
/*      if((*(p+4)!=0x55) || (*(p+4) != 0xAA))
            return ERROR_RANGE_DATA;*/

	memcpy(data,buf,len_out);
	return len_out;
}
int encode_frameA4F48(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}
int encode_frameA4F49(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 1;
	if (len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,p,len_out);
	return len_out;
}
int encode_frameA4F57(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 3;
	if (len_in  < len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}
int encode_frameA4F58(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 1;
	if (len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F59(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 4;
	if (len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,p,len_out);
	return len_out;
}

int encode_frameA4F60(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,i ;
	uchar *p;
	p = buf;

      len_out = 80;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;	
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F61(uchar *buf, uint len_in ,uchar *data)
{
	int len_out,i ;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}


int encode_frameA4F65(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,n;
	uchar *p;
	p = buf;

	if (len_in < 9)
	    return ERROR_FRAME_DATA_LENGTH;
	n = *(p+7);
	if (n<1 || n>96)
		return ERROR_RANGE_DATA;
	n = *(p+8);
	len_out = 9+n*4;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;			

	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F66(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,n;
	uchar *p;
	p = buf;

	if (len_in < 9)
	    return ERROR_FRAME_DATA_LENGTH;
	n = *(p+7);
	if (n<1 || n>96)
		return ERROR_RANGE_DATA;
	n = *(p+8);
	len_out = 9+n*4;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;			

	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F67(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
 /*     if((*p != 0x55) && (*p != 0xAA))
            return ERROR_RANGE_DATA;*/
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F68(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
/*      if((*p != 0x55) && (*p != 0xAA))
            return ERROR_RANGE_DATA;*/
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F73(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,li_i,m;
	uchar *p;
      p = buf;

      len_out = 48;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
      for(li_i =0 ;li_i<16;li_i++)
      {
            m = (*p>>6)&0x03;
            if(m<1 || m>2)
                return ERROR_RANGE_DATA;
            p+=3;
      }
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F74(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,li_i;
	uchar *p;
	p = buf;

      len_out = 10;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F75(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,li_i;
	uchar *p;
	p = buf;

      len_out = 16;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F76(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
/*        if((*p<1) ||(*p >5))
            return ERROR_RANGE_DATA;
*/        
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F81(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,li_i ;
	uchar *p;
	p = buf;

      len_out = 4;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F82(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,li_i ;
	uchar *p;
	p = buf;

      len_out = 4;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F83(uchar *buf, uint len_in ,uchar *data)
{
	int len_out, m;
	uchar *p;
	p = buf;

      len_out = 1;
	if ( len_in  <  len_out)
	    return ERROR_FRAME_DATA_LENGTH;
      m = *p;
      if((m != 0) && (m != 1) && (m != 2) && (m != 3) && (m != 253) && (m != 254))
          return ERROR_RANGE_DATA;
	
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F89(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 4;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;      
	
	memcpy(data,buf,len_out);
	return len_out;
}


int encode_frameA4F90(uchar *buf, uint len_in ,uchar *data)
{
	int len_out;
	uchar *p;
	p = buf;

      len_out = 2;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;
/*      if(*p<0 ||*p>63)
            return ERROR_RANGE_DATA;
      if(*(p+1)<0 ||*(p+1)>3)
            return ERROR_RANGE_DATA;
*/           
	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F91(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ,i;
	uchar *p;
	p = buf;

      len_out = 10;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data,buf,len_out);
	return len_out;
}

int encode_frameA4F150(uchar *buf, uint len_in ,uchar *data)
{
	int len_out ;
	uchar *p;
	p = buf;

      len_out = 512;
	if ( len_in  <  len_out)
		return ERROR_FRAME_DATA_LENGTH;

	memcpy(data,buf,len_out);
	return len_out;
}	
	
