#include"decode_AFN0D_FN201_208.h"


int decode_afn0D_F201F208(uchar *as_data, str_AFN0D_F201F208*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	/*数据时标月年*/
	astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
	(*ai_step) = li_step;
	p += li_step;
	
	/*抄表时间*/
	astr_val->CBisnull= getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*费率数*/
	astr_val->val = *p;
	if ((astr_val->val= ((astr_val->val < 1) || (astr_val->val >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	li_step++;
	p++;
	
	/*正向有功总电能*/
	astr_val->val1isnull= getdataformat14(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*费率正向有功总电能*/
	for(lc_i = 0;lc_i < astr_val->val;lc_i++)
	{
		astr_val->zxygisnull[lc_i]= getdataformat14(p, &(astr_val->zxyg[lc_i]), &li_step);
		(*ai_step) += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}

