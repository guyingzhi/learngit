#include "encode_AFN0D_FN1_224.h"

/*************����������ʱ��Td_c**********
	buf           ������������
	len_in       �������ݳ���
	date         ����һ��֡�ṹ��������ָ��

	����     len_out	�������������ַ�����			

************************************************/
int  encodedataformatTD_C(uchar *buf, uint len_in ,uchar *dat)
{	
    int len_out=0, li_i=0;
    uchar *p=buf;
    datetime adt_val;

    if ( len_in  <  7)
        return ERROR_FRAME_DATA_LENGTH;
    memset(&adt_val, 0, sizeof(adt_val));
    adt_val.min = BCDByteToByte(*p);
    adt_val.hour = BCDByteToByte(*(p + 1));
    adt_val.day = BCDByteToByte(*(p + 2));
    adt_val.mon = BCDByteToByte(*(p + 3));
    adt_val.year = BCDByteToByte(*(p + 4));
	
    if ((adt_val.min < 0) || adt_val.min >59)                       /*�ж����ڷ��Ƿ񳬳���Χ*/
        return ERROR_RANGE_DATETIME;
    if (adt_val.hour < 0 || adt_val.hour > 23)            /*�ж�����ʱ�Ƿ񳬳���Χ*/
        return ERROR_RANGE_DATETIME;				
    switch(adt_val.mon)                                      /*�жϴ��º�С�·ֱ��Ӧ����������*/
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (adt_val.day < 1 || adt_val.day > 31)
                return ERROR_RANGE_DATETIME;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (adt_val.day < 1 || adt_val.day > 30)
                return ERROR_RANGE_DATETIME;
            break;
        case 2:
            if (((adt_val.year + 2000) % 400) == 0 || (((adt_val.year + 2000) % 4) == 0  && ((adt_val.year + 2000) % 100) != 0))	/*�ж��Ƿ�������*/
            {
                if (adt_val.day < 1 || adt_val.day > 29)
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

//	if (*(p+ 4) < 114||*(p + 4) > 126)                                         /*������ķ�Χ2014��2100*/
//		return ERROR_RANGE_DATETIME;	
    li_i = *(p+5);     /*�ж����ݶ����ܶ��Ƿ��ǿ�*/
    if(li_i != 0 && li_i != 1 && li_i != 2 && li_i != 3 && li_i != 254 && li_i != 255)    
        return ERROR_NULL_DENSITY;

    *(dat + len_out++) = *p;					 /*  BIN  ��ת��ΪBCD   ��ʽ*/
    *(dat + len_out++) = *(p + 1);
    *(dat + len_out++) = *(p + 2);
    *(dat + len_out++) = *(p + 3);
    *(dat + len_out++) = *(p + 4);
    *(dat + len_out++) = *(p + 5);
    *(dat + len_out++) = *(p + 6);
    return len_out;		
}
/*********�ն���������ʱ��Td_d*******************/
int encodedataformatTD_d(uchar *buf, uint len_in, uchar *dat)
{	
    int len_out=0;
    uchar *p;
    datetime adt_val;
    p = buf;

    if (len_in < 3)
        return ERROR_FRAME_DATA_LENGTH;
    memset(&adt_val, 0, sizeof(adt_val));
    adt_val.day = BCDByteToByte(*p);
    adt_val.mon = BCDByteToByte(*(p + 1));
    adt_val.year= BCDByteToByte(*(p + 2));
	
    switch(adt_val.mon)							 /*�жϴ��º�С�·ֱ��Ӧ����������*/
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (adt_val.day < 1 || adt_val.day > 31)
                return ERROR_RANGE_DATETIME;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (adt_val.day < 1 || adt_val.day > 30)
                return ERROR_RANGE_DATETIME;
            break;
        case 2:
            if (((adt_val.year + 2000 ) % 400) == 0 || (((adt_val.year + 2000) % 4) == 0 && ((adt_val.year + 2000) % 100) != 0))	/*�ж��Ƿ�������*/
            {
                if (adt_val.day < 1 || adt_val.day > 29)
                    return ERROR_RANGE_DATETIME;
            } 
            else 
            {					
                if (adt_val.day < 1 || adt_val.day > 28)
                    return ERROR_RANGE_DATETIME;				
            }
            break;
        default:
            return ERROR_RANGE_DATETIME;
    }		

//	if ((*(p + 2) < 114) || (*(p + 2) > 126))							 /*�ж��������Ƿ���2014--2026��*/
//		return ERROR_RANGE_DATETIME;
	
    *(dat + len_out++) = *p;								 /*  BIN  ��ת��ΪBCD   ��ʽ*/
    *(dat + len_out++) = *(p + 1);
    *(dat + len_out++) = *(p + 2);
    return len_out;	
}
/***********�¶���������ʱ��Td_m*************/
int encodedataformatTD_m(uchar *buf, uint len_in ,uchar *date)
{
    int len_out=0;
    uchar*p;
    p = buf ;

    if ( len_in < 2)							/*�ж����ݱ��ĳ���*/
        return ERROR_FRAME_DATA_LENGTH;

    if ((BCDByteToByte(*p) < 1) || (BCDByteToByte(*p) > 12))					/*�ж��������Ƿ񳬳���Χ*/   
        return ERROR_RANGE_DATETIME;
    //	if ((*(p + 1) < 114) || (*(p  + 1) > 126))      /*�ж��������Ƿ���2014--2026��*/
    //		return ERROR_RANGE_DATETIME;

    *(date + len_out++) = *p;
    *(date + len_out++) = *(p + 1);
    return len_out;
}
