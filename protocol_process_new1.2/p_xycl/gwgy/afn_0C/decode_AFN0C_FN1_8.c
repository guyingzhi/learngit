#include "decode_AFN0C_FN1_8.h"

/***********************************
*	终端日历时钟
*	秒，分，时，日，月，年
************************************/
int decode_afn0C_F2(uchar * data, str_AFN0C_FN2* lstr_val, int *ai_len)
{
	uchar *p;
	p = data;
	uchar week;
	datetime *adt_val;
	if ( *p < 0 || *p > 59) 
		return ERROR_RANGE_DATETIME;
	if (*(p + 1) < 0 || *(p + 1) > 59) 
		return ERROR_RANGE_DATETIME;
	if (*(p + 2) < 0 || *(p + 2) > 23) 
		return ERROR_RANGE_DATETIME;
	switch(*(p + 4))                                      /*判断大月和小月分别对应的月日数天*/
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (*(p + 3)  < 1 ||*(p +3) > 31)
			return ERROR_RANGE_DATETIME;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (*(p + 3)  < 1 ||*(p +3) > 30)
			return ERROR_RANGE_DATETIME;
			break;
		case 2:
			if ((*(p+5) % 400) == 0 ||( (*(p+5) % 4)==0  && (*(p+5) % 100)!= 0) )	/*判断是否是闰年*/
			{
				if (*(p + 3)  < 1 ||*(p +3) > 29)
					return ERROR_RANGE_DATETIME;
			}else
			{
				if (*(p + 3)  < 1 ||*(p +3) > 28)
					return ERROR_RANGE_DATETIME;
			}
			break;
		default:
			return ERROR_RANGE_DATETIME;
		}	
	*ai_len= 6;
	lstr_val->termdt.sec   = BCDByteToByte(*p);
	lstr_val->termdt.min   = BCDByteToByte(*(p + 1));
	lstr_val->termdt.hour = BCDByteToByte(*(p + 2));
	lstr_val->termdt.day   = BCDByteToByte(*(p + 3));
	f_get_week(adt_val, &week);
	if (week < 1 || week > 7) 
	 	return ERROR_RANGE_DATETIME;
	lstr_val->termdt.mon  = BCDByteToByte(*(p + 4) & 0x1f) |(week << 5) ;
	lstr_val->termdt.year  = BCDByteToByte(*(p + 5)) + 100;

	return ERROR_SUCCESS ;
}
/*************************************
       终端参数状态
       对应表示本部分04报文的
       参数，置1，终端有该参数，
       置0，终端无该数据项
**************************************/
int decode_afn0C_F3(uchar * data, str_AFN0C_FN3* lstr_val, int *ai_len)
{
	uchar *p, lc_i, lc_j;
	p = data;

	for (lc_i = 0; lc_i < 31; lc_i++)
	{
		for (lc_j =0; lc_j < 8; lc_j++)
		{
			lstr_val->arg[lc_i * 8 + lc_j] = getbytebybit(*(p + lc_i), lc_j, 1);
		}
	}
	(*ai_len) = 31;
	return ERROR_SUCCESS;
}
/********************************************************************
*	终端上行通信状态
* 	data 是指向数据单元
* 	lstr_val->report D0~D1编码表示允许禁止终端主动上报 
*	lstr_val->message D2~D3 编码表示允许禁止终端与主站通话
*	取值1~2
*
*********************************************************************/
int decode_afn0C_F4(uchar *data,str_AFN0C_FN4 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	lstr_val->report = *p & 0x03;
	lstr_val->message = (*p >> 2) & 0x03;
	(*ai_len) = 1;
	return ERROR_SUCCESS;	
}
/*******************************
    终端控制设置状态
    
********************************/
int decode_afn0C_F5(uchar *data,str_AFN0C_FN5 *lstr_val,int *ai_len)	
{
	uchar *p;
	p = data;
	int li_c,li_d,li_step = 0;
	/***投入和解除***/
	lstr_val->bd = *p & 0x01;
	lstr_val->tc   = (*p & 0x02) >> 1;
	lstr_val->cfgj = (*p &0x04) >> 2;
	li_step++;
	/*总加组的控制设置状*/
	for(li_c = 0;li_c < 8;li_c++)
	{
		lstr_val->sum[li_c] = getbytebybit(*(p + li_step), li_c, 1);
	}
	li_step++;
	for(li_c= 0;li_c <8 ;li_c++)
	{
		if (lstr_val->sum[li_c] = 1)
		{	
			/*方案号*/
			lstr_val->ctrl[li_c].projectid = *(p + li_step);
			li_step++;
			/*工控时段标志*/
			for(li_d = 0 ;li_d < 8;li_d++)
			{
				lstr_val->ctrl[li_c].gksd[li_d] = getbytebybit(*(p + li_step), li_d, 1);
			}
			li_step++;
			/*工控状态*/
			lstr_val->ctrl[li_c].sdk = (*p + li_step) & 0x01;
			lstr_val->ctrl[li_c].cxk = ((*p + li_step) & 0x02) >> 1;
			lstr_val->ctrl[li_c].yybtk = ((*p + li_step) & 0x04) >> 2;
			lstr_val->ctrl[li_c].glxfk = ((*p + li_step) & 0x08) >> 3;
			li_step++;
			/*电控D0 是月电控，D1 是购电控*/
			lstr_val->ctrl[li_c].ydk = (*p + li_step) &0x01;
			lstr_val->ctrl[li_c].gdk = (*p + li_step) &0x02;
			li_step++;
			/*工控轮次状态*/
			for (li_d = 0;li_d <8;li_d++)
			{
				lstr_val->ctrl[li_c].turngk[li_d] = getbytebybit(*(p+li_step),li_d,1);
			}
			li_step++;
			/*电控轮次状态*/
			for(li_d = 0;li_d < 8 ; li_d ++)
				{
					lstr_val->ctrl[li_c].turndk[li_d] = getbytebybit(*(p + li_step),li_d,1);
				}
			li_step++;
		}
	}
	*ai_len = li_step;
	return ERROR_SUCCESS;
}
/***************************
	终端当前控制状态
***************************/
int decode_afn0C_F6(uchar *data,str_AFN0C_FN6 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	int li_step=0,li_c,li_d,li_i;
	double ldb_val;
	int val;
	/*遥控跳闸输出状态*/
	for(li_c = 0;li_c < 8;li_c++)
	{
		lstr_val->yktz[li_c] = getbytebybit(*p,li_c,1);
	}
	li_step++;
	/*当前催费告警状态D0 表示当前是否处于催费告警状态*/
	lstr_val->cfgj = *(p+li_step) &0x01;
	li_step++;
	/*总加组状态*/
	for(li_d = 0;li_d < 8;li_d++)
	{
		lstr_val->sum[li_d] =getbytebybit(*(p+li_step),li_d,1);
	}
	li_step++;
	for (li_d = 0;li_d <8;li_d++)
	{
		if (lstr_val->sum[li_d] = 1)
		{
			/*当前工控定值*/
			if(lstr_val->ctrl[li_d].gkdzisnull= getdataformat02(p + li_step, &ldb_val, &li_i) ==DATA_ISNOTNULL);
			lstr_val->ctrl[li_d].gkdz =ldb_val;
			li_step+=2;

			/*当前功率下浮系数*/
			if ( lstr_val->ctrl[li_d].kisnull = getdataformat04(p + li_step, &val, &li_i) == DATA_ISNOTNULL);
			 lstr_val->ctrl[li_d].k=val;
			li_step++;

			/*工控跳闸输出状态*/
			for(li_c = 0;li_c <8;li_c++)
			{
				lstr_val->ctrl[li_d].gltz[li_c] = getbytebybit(*(p+li_step),li_c,1);
			}
			li_step++;

			/*r月电控输出跳闸状态*/
			for(li_c = 0;li_c < 8;li_c++)
			{
				lstr_val->ctrl[li_d].mondgtz[li_c] = getbytebybit(*(p+li_step),li_c,1);
			}
			li_step++;

			/*购电控跳闸输出状态*/
			for(li_c = 0;li_c < 8;li_c++)
			{
				lstr_val->ctrl[li_d].buydgtz[li_c] = getbytebybit(*(p+li_step),li_c,1);
			}
			li_step++;

                    	/*工控越界告警状态*/
			lstr_val->ctrl[li_d].sdk= (*p + li_step) & 0x01;
			lstr_val->ctrl[li_d].cxk = ((*p + li_step) & 0x02) >> 1;
			lstr_val->ctrl[li_d].yybtk = ((*p + li_step) & 0x04) >> 2;
			lstr_val->ctrl[li_d].glxfk = ((*p + li_step) & 0x08) >> 3;
			li_step++;

			/*电控越界告警状态*/
			lstr_val->ctrl[li_c].mondkyj= (*p + li_step) &0x01;
			lstr_val->ctrl[li_c].buydky= (*p + li_step) &0x02;
			li_step++;
		}
	}
	*ai_len = li_step;
	return ERROR_SUCCESS;
}
/********************************
*
*	终端事件计数器当前值
*
*********************************/
int decode_afn0C_F7(uchar *data,str_AFN0C_FN7 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	
	lstr_val->EC1 = *p;
	lstr_val->EC2 = *(p + 1);
	*ai_len = 2;
	return ERROR_SUCCESS;
}

/********************************
*
*	终端事件标志状态
*	D0~D63按顺序对位表示
*	表示ERC1~ERC64,置1有事件
*	置0 无事件
*
*********************************/
int decode_afn0C_F8(uchar *data,str_AFN0C_FN8 *lstr_val,int *ai_len)
{
	int li_step;
	uchar *p;
	int lc_i, lc_j;
	p = data;
	li_step = 0;
	for (lc_i = 0; lc_i < 8; lc_i++)
	{
		for (lc_j = 0; lc_j < 8; lc_j++)
		{
			lstr_val->ERC[lc_i * 8 + lc_j] = getbytebybit(*(p + lc_i), lc_j, 1);
		}
	li_step++;
	}
	*ai_len = li_step;
	return ERROR_SUCCESS;
}
