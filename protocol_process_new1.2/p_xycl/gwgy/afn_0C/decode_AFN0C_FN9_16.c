#include "decode_AFN0C_FN9_16.h"


/********************************
*
*	终端状态量及变化位标志
*	
*********************************/
int decode_afn0C_F9(uchar *data,str_AFN0C_FN9 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	int lc_i;
	for (lc_i = 0; lc_i < 8; lc_i++)
	{
		lstr_val->ST[lc_i] = getbytebybit(*p, lc_i, 1);
	}
	for (lc_i = 0; lc_i < 8; lc_i++)
	{
		lstr_val->CD[lc_i] = getbytebybit(* (p + 1), lc_i, 1);
	}

	*ai_len  = 2;
	return ERROR_SUCCESS;	
}
/********************************
*
*	终端与主站当日月通信流量

*********************************/
int decode_afn0C_F10(uchar *data,str_AFN0C_FN10 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	lstr_val->daytotal = *(p + 3);
	lstr_val->daytotal <<8;
	lstr_val->daytotal = lstr_val->daytotal + *(p + 2);
	lstr_val->daytotal <<8;
	lstr_val->daytotal = lstr_val->daytotal + *(p + 1);
	lstr_val->daytotal <<8;
	lstr_val->daytotal = lstr_val->daytotal + *(p + 0);
	*ai_len = 4;
	p +=4;
	lstr_val->monthtotal = *(p + 3);
	lstr_val->monthtotal <<8;
	lstr_val->monthtotal = lstr_val->monthtotal + *(p + 2);
	lstr_val->monthtotal <<8;
	lstr_val->monthtotal = lstr_val->monthtotal + *(p + 1);
	lstr_val->monthtotal <<8;
	lstr_val->monthtotal = lstr_val->monthtotal + *(p + 0);
	(*ai_len) += 4;

	return ERROR_SUCCESS;
}
/********************************
*
*	终端集中抄表状态信息

*********************************/
int decode_afn0C_F11(uchar *data,str_AFN0C_FN11 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	int ai_step = 0,lc_number;
	int li_step;
	if (((lstr_val->number = *p )< 1 )||(lstr_val->number = *p )>31 )
	 	return ERROR_FRAME_DATA_LENGTH;
	ai_step ++;

	for (lc_number = 0; lc_number < lstr_val->number; lc_number++)
	{
		if(((lstr_val->val[lc_number].port = *(p + ai_step))< 1 )||(lstr_val->val[lc_number].port = *(p + ai_step)>31 ))
	 		return ERROR_FRAME_DATA_LENGTH;
		ai_step ++;
		
		lstr_val->val[lc_number].total_cb = *(p+ai_step+1);
		lstr_val->val[lc_number].total_cb << 8;
		lstr_val->val[lc_number].total_cb = lstr_val->val[lc_number].total_cb + *(p +ai_step);
		ai_step += 2;

		lstr_val->val[lc_number].cbokflag = (*(p+ai_step) & 0x02)>>1;
		lstr_val->val[lc_number].cbingflag = *(p+ai_step) & 0x01;
		ai_step++;

		lstr_val->val[lc_number].cboktotal = *(p+ai_step+1);
		lstr_val->val[lc_number].cboktotal << 8;
		lstr_val->val[lc_number].cboktotal = lstr_val->val[lc_number].cboktotal + *(p+ai_step);
		ai_step += 2;

		 lstr_val->val[lc_number].cbzdtotal = *(p +ai_step);
		ai_step += 1;


		lstr_val->val[lc_number].cbkssjisnull = getdataformat01((p +ai_step), &(lstr_val->val[lc_number].cbkssj), &li_step);
		ai_step+=  li_step;
	
		lstr_val->val[lc_number].cbjssjisnull = getdataformat01((p +ai_step), &(lstr_val->val[lc_number].cbjssj), &li_step);
		ai_step +=  li_step;
		
		}	
	return ERROR_SUCCESS;	
}
/********************************
*
*	控制输出回路开关接入状态量及变化标志

*********************************/
int decode_afn0C_F12(uchar *data,str_AFN0C_FN12*lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	int lc_i;
	for (lc_i = 0; lc_i < 8; lc_i+=2)
	{
		lstr_val->ST[lc_i] = getbytebybit(*p, lc_i, 2);
	}
	for (lc_i = 0; lc_i < 8; lc_i+=2)
	{
		lstr_val->CD[lc_i] = getbytebybit(* (p + 1), lc_i, 2);
	}

	*ai_len  = 2;
	return ERROR_SUCCESS;	
}
/********************************
*
*	搜索到的电表信息

*********************************
int decode_afn0C_F13(uchar *data,str_AFN0C_FN13 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	
	return ERROR_SUCCESS;	
}
/********************************
*
*	文件传输末收到的数据段

*********************************
int decode_afn0C_F14(uchar *data,str_AFN0C_FN14 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	
	return ERROR_SUCCESS;	
}
************/