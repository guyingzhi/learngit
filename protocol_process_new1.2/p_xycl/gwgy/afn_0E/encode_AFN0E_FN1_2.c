#include "encode_AFN0E_FN1_2.h"

/***********************************************
	buf           下行数据内容
	len_in       数据内容长度
	dat_out      返回一个帧结构数据内容指针

	返回     len_out	解析正常返回字符长度			
************************************************/
int  en_AFN0E_F1_2(uchar *buf, uint len_in ,uchar *dat_out)
{	
    int len_out=0;
    uchar *p=buf;
	
    if ( len_in  <  2)
        return ERROR_FRAME_DATA_LENGTH  ;
    *(dat_out + len_out++)=  *p;	      /*请求事件记录起始指针*/
    *(dat_out + len_out++)  =  *(p +1);   /*请求事件记录结束指针*/

    return len_out;		
}

