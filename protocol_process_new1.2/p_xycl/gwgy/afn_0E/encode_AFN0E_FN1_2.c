#include "encode_AFN0E_FN1_2.h"

/***********************************************
	buf           ������������
	len_in       �������ݳ���
	dat_out      ����һ��֡�ṹ��������ָ��

	����     len_out	�������������ַ�����			
************************************************/
int  en_AFN0E_F1_2(uchar *buf, uint len_in ,uchar *dat_out)
{	
    int len_out=0;
    uchar *p=buf;
	
    if ( len_in  <  2)
        return ERROR_FRAME_DATA_LENGTH  ;
    *(dat_out + len_out++)=  *p;	      /*�����¼���¼��ʼָ��*/
    *(dat_out + len_out++)  =  *(p +1);   /*�����¼���¼����ָ��*/

    return len_out;		
}

