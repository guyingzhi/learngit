#include "decode_AFN0D_FN193_200.h"



int decode_afn0D_F193_F200(uchar *as_data, str_AFN0D_F193_F200*astr_val, int *ai_step,int frozen_type)
{
	uchar  *p, lc_i;
	int li_step;
	p = as_data;

	/*�¶���Ĺ��õ���Ϣ*/
	if(frozen_type == 2)
	{
		astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}
	/*�ն���Ĺ��õ���Ϣ*/
	else if(frozen_type == 1)
	{
		astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}	

	/*�ն˳���ʱ��*/
	astr_val->CBisnull = getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	/*������*/
	astr_val->val = *p;
	if ((astr_val->val= ((astr_val->val < 1) || (astr_val->val >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;
	/*�����й����������*/
	astr_val->val1isnull = getdataformat23(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	/*�����й������������ʱ��*/
	astr_val->zxygtimeisnull= getdataformat17(p, &(astr_val->TD),&(astr_val->zxygtime), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*����1~M �����������й���������ͷ���ʱ��*/
	 for(lc_i = 0;lc_i<astr_val->val;lc_i++)
 	{
 		astr_val->val2isnull[lc_i]= getdataformat23(p,&(astr_val->val2[lc_i]),&li_step);
		(*ai_step) += li_step;
		p += li_step;
		astr_val->val2timeisnull[lc_i] = getdataformat17(p,&(astr_val->TD),&(astr_val->val2time[lc_i]),&li_step);
		(*ai_step) += li_step;
		p += li_step;
 	}

	return ERROR_SUCCESS;
}