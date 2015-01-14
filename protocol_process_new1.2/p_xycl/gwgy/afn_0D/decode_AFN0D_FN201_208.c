#include"decode_AFN0D_FN201_208.h"


int decode_afn0D_F201F208(uchar *as_data, str_AFN0D_F201F208*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	/*����ʱ������*/
	astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
	(*ai_step) = li_step;
	p += li_step;
	
	/*����ʱ��*/
	astr_val->CBisnull= getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*������*/
	astr_val->val = *p;
	if ((astr_val->val= ((astr_val->val < 1) || (astr_val->val >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	li_step++;
	p++;
	
	/*�����й��ܵ���*/
	astr_val->val1isnull= getdataformat14(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*���������й��ܵ���*/
	for(lc_i = 0;lc_i < astr_val->val;lc_i++)
	{
		astr_val->zxygisnull[lc_i]= getdataformat14(p, &(astr_val->zxyg[lc_i]), &li_step);
		(*ai_step) += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}

