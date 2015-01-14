#include "decode_AFN0D_FN193_200.h"



int decode_afn0D_F193_F200(uchar *as_data, str_AFN0D_F193_F200*astr_val, int *ai_step,int frozen_type)
{
	uchar  *p, lc_i;
	int li_step;
	p = as_data;

	/*月冻结的购用电信息*/
	if(frozen_type == 2)
	{
		astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}
	/*日冻结的购用电信息*/
	else if(frozen_type == 1)
	{
		astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}	

	/*终端抄表时间*/
	astr_val->CBisnull = getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	/*费率数*/
	astr_val->val = *p;
	if ((astr_val->val= ((astr_val->val < 1) || (astr_val->val >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;
	/*正向有功总最大需量*/
	astr_val->val1isnull = getdataformat23(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	/*正向有功最大需量发生时间*/
	astr_val->zxygtimeisnull= getdataformat17(p, &(astr_val->TD),&(astr_val->zxygtime), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*费率1~M 正向有正向有功最大需量和发生时间*/
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