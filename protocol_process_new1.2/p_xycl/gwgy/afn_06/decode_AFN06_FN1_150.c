#include "decode_AFN06_FN1_150.h"


int decode_afn06_F11(uchar *data, str_AFN06_F11 *astr_val, int *ai_step)
{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
    for(li_i = 0;li_i<8;li_i++)
    {
	  astr_val->chip_number[li_i] = *(p+li_i);
    }
	p+= 8;
   for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->certificate_number[li_i] =*(p+li_i); 
   }
   p+=16;
   for(li_i = 0;li_i<4;li_i++)
   {
	astr_val->counter[li_i] = *(p+li_i);
   }
   p+=4;
   astr_val->chip_state = *p;
   p+=1;
   for(li_i = 0;li_i<8;li_i++)
   {
	astr_val->key[li_i] = *(p+li_i);
   }
   
   *ai_step = 37;
    return ERROR_SUCCESS;	
	
}

int decode_afn06_F12_0(uchar *data, str_AFN06_F12_0 *astr_val, int *ai_step)

{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
	astr_val->len = *p + (*(p+1)<<8);
	p+=2;
	astr_val->state = *p;
	p+=1;
	astr_val->chat_ID = *p;
	p+=1;
	 for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->CRL_number[li_i] =*(p+li_i); 
   }
	 p+=16;
	  for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->certificate_number[li_i] =*(p+li_i); 
   }
	  p+=16;
	   for(li_i = 0;li_i<(astr_val->len-114);li_i++)
   {
	astr_val->terminal_certificate[li_i] =*(p+li_i); 
   }
	   p+=(astr_val->len-114);
	
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->EKs2[li_i] =*(p+li_i); 
   }
	   p+=16;
	 for(li_i = 0;li_i<64;li_i++)
   {
	astr_val->certificate_number[li_i] =*(p+li_i); 
   }
	 *ai_step = astr_val->len+2;
	 
	  return ERROR_SUCCESS;	  
	
}

int decode_afn06_F12_1(uchar *data, str_AFN06_F12_1 *astr_val, int *ai_step)
{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
	astr_val->len = *p + (*(p+1)<<8);
	p+=2;
	astr_val->state = *p;
	p+=1;
	astr_val->chat_ID = *p;
	p+=1;
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->EKs2[li_i] =*(p+li_i); 
   }
	p+=16;
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->R3[li_i] =*(p+li_i); 
   }
	p+=16;
	for(li_i = 0;li_i<4;li_i++)
   {
	astr_val->MAC3[li_i] =*(p+li_i); 
   }
	*ai_step = 40;
	
	return ERROR_SUCCESS;

}

int decode_afn06_F13(uchar *data, str_AFN06_F13 *astr_val, int *ai_step)
{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->R3[li_i] =*(p+li_i); 
   }
	p+=16;
	for(li_i = 0;li_i<4;li_i++)
   {
	astr_val->MAC3[li_i] =*(p+li_i); 
   }
	*ai_step = 20;
	
	return ERROR_SUCCESS;	

}

int decode_afn06_F15(uchar *data, str_AFN06_F15 *astr_val, int *ai_step)
{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->certificate_number[li_i] =*(p+li_i); 
   }
	p+=16;
	for(li_i = 0;li_i<64;li_i++)
   {
	astr_val->terminal_key[li_i] =*(p+li_i); 
   }
	*ai_step = 80;
	
	return ERROR_SUCCESS;	

}

int decode_afn06_F17(uchar *data, str_AFN06_F17 *astr_val, int *ai_step)
{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->R4[li_i] =*(p+li_i); 
   }
	p+=16;
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->R5[li_i] =*(p+li_i); 
   }
	*ai_step = 32;
	
	return ERROR_SUCCESS;	

}

int decode_afn06_F18(uchar *data, str_AFN06_F18 *astr_val, int *ai_step)
{
	 uchar *p;
    int li_i;
    p = data;
	
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
	for(li_i = 0;li_i<16;li_i++)
   {
	astr_val->R6[li_i] =*(p+li_i); 
   }

	*ai_step =16;
	
	return ERROR_SUCCESS;	

}