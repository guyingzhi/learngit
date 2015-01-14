#include "decode_AFN0C_FN1_8.h"

/***********************************
*	�ն�����ʱ��
*	�룬�֣�ʱ���գ��£���
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
	switch(*(p + 4))                                      /*�жϴ��º�С�·ֱ��Ӧ����������*/
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
			if ((*(p+5) % 400) == 0 ||( (*(p+5) % 4)==0  && (*(p+5) % 100)!= 0) )	/*�ж��Ƿ�������*/
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
       �ն˲���״̬
       ��Ӧ��ʾ������04���ĵ�
       ��������1���ն��иò�����
       ��0���ն��޸�������
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
*	�ն�����ͨ��״̬
* 	data ��ָ�����ݵ�Ԫ
* 	lstr_val->report D0~D1�����ʾ�����ֹ�ն������ϱ� 
*	lstr_val->message D2~D3 �����ʾ�����ֹ�ն�����վͨ��
*	ȡֵ1~2
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
    �ն˿�������״̬
    
********************************/
int decode_afn0C_F5(uchar *data,str_AFN0C_FN5 *lstr_val,int *ai_len)	
{
	uchar *p;
	p = data;
	int li_c,li_d,li_step = 0;
	/***Ͷ��ͽ��***/
	lstr_val->bd = *p & 0x01;
	lstr_val->tc   = (*p & 0x02) >> 1;
	lstr_val->cfgj = (*p &0x04) >> 2;
	li_step++;
	/*�ܼ���Ŀ�������״*/
	for(li_c = 0;li_c < 8;li_c++)
	{
		lstr_val->sum[li_c] = getbytebybit(*(p + li_step), li_c, 1);
	}
	li_step++;
	for(li_c= 0;li_c <8 ;li_c++)
	{
		if (lstr_val->sum[li_c] = 1)
		{	
			/*������*/
			lstr_val->ctrl[li_c].projectid = *(p + li_step);
			li_step++;
			/*����ʱ�α�־*/
			for(li_d = 0 ;li_d < 8;li_d++)
			{
				lstr_val->ctrl[li_c].gksd[li_d] = getbytebybit(*(p + li_step), li_d, 1);
			}
			li_step++;
			/*����״̬*/
			lstr_val->ctrl[li_c].sdk = (*p + li_step) & 0x01;
			lstr_val->ctrl[li_c].cxk = ((*p + li_step) & 0x02) >> 1;
			lstr_val->ctrl[li_c].yybtk = ((*p + li_step) & 0x04) >> 2;
			lstr_val->ctrl[li_c].glxfk = ((*p + li_step) & 0x08) >> 3;
			li_step++;
			/*���D0 ���µ�أ�D1 �ǹ����*/
			lstr_val->ctrl[li_c].ydk = (*p + li_step) &0x01;
			lstr_val->ctrl[li_c].gdk = (*p + li_step) &0x02;
			li_step++;
			/*�����ִ�״̬*/
			for (li_d = 0;li_d <8;li_d++)
			{
				lstr_val->ctrl[li_c].turngk[li_d] = getbytebybit(*(p+li_step),li_d,1);
			}
			li_step++;
			/*����ִ�״̬*/
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
	�ն˵�ǰ����״̬
***************************/
int decode_afn0C_F6(uchar *data,str_AFN0C_FN6 *lstr_val,int *ai_len)
{
	uchar *p;
	p = data;
	int li_step=0,li_c,li_d,li_i;
	double ldb_val;
	int val;
	/*ң����բ���״̬*/
	for(li_c = 0;li_c < 8;li_c++)
	{
		lstr_val->yktz[li_c] = getbytebybit(*p,li_c,1);
	}
	li_step++;
	/*��ǰ�߷Ѹ澯״̬D0 ��ʾ��ǰ�Ƿ��ڴ߷Ѹ澯״̬*/
	lstr_val->cfgj = *(p+li_step) &0x01;
	li_step++;
	/*�ܼ���״̬*/
	for(li_d = 0;li_d < 8;li_d++)
	{
		lstr_val->sum[li_d] =getbytebybit(*(p+li_step),li_d,1);
	}
	li_step++;
	for (li_d = 0;li_d <8;li_d++)
	{
		if (lstr_val->sum[li_d] = 1)
		{
			/*��ǰ���ض�ֵ*/
			if(lstr_val->ctrl[li_d].gkdzisnull= getdataformat02(p + li_step, &ldb_val, &li_i) ==DATA_ISNOTNULL);
			lstr_val->ctrl[li_d].gkdz =ldb_val;
			li_step+=2;

			/*��ǰ�����¸�ϵ��*/
			if ( lstr_val->ctrl[li_d].kisnull = getdataformat04(p + li_step, &val, &li_i) == DATA_ISNOTNULL);
			 lstr_val->ctrl[li_d].k=val;
			li_step++;

			/*������բ���״̬*/
			for(li_c = 0;li_c <8;li_c++)
			{
				lstr_val->ctrl[li_d].gltz[li_c] = getbytebybit(*(p+li_step),li_c,1);
			}
			li_step++;

			/*r�µ�������բ״̬*/
			for(li_c = 0;li_c < 8;li_c++)
			{
				lstr_val->ctrl[li_d].mondgtz[li_c] = getbytebybit(*(p+li_step),li_c,1);
			}
			li_step++;

			/*�������բ���״̬*/
			for(li_c = 0;li_c < 8;li_c++)
			{
				lstr_val->ctrl[li_d].buydgtz[li_c] = getbytebybit(*(p+li_step),li_c,1);
			}
			li_step++;

                    	/*����Խ��澯״̬*/
			lstr_val->ctrl[li_d].sdk= (*p + li_step) & 0x01;
			lstr_val->ctrl[li_d].cxk = ((*p + li_step) & 0x02) >> 1;
			lstr_val->ctrl[li_d].yybtk = ((*p + li_step) & 0x04) >> 2;
			lstr_val->ctrl[li_d].glxfk = ((*p + li_step) & 0x08) >> 3;
			li_step++;

			/*���Խ��澯״̬*/
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
*	�ն��¼���������ǰֵ
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
*	�ն��¼���־״̬
*	D0~D63��˳���λ��ʾ
*	��ʾERC1~ERC64,��1���¼�
*	��0 ���¼�
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
