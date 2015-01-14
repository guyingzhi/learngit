#include "decode_AFN0D_FN113_120.h"

int decode_AFN0D_F113_115(uchar *as_data, str_AFN0D_F113_118*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;

	astr_val->TDisnull = getdataformat20(p,&(astr_val->TD),&li_step);
	(*ai_step) = li_step;
	p += li_step;

	for (lc_i = 2;lc_i <=19;lc_i++)
	{
		astr_val->Imaxisnull[lc_i] = getdataformat06(p,&(astr_val->Imax[lc_i]),&li_step);
		(*ai_step) += li_step;
		p += li_step;
		astr_val->xptimeisnull[lc_i] = getdataformat17(p,&(astr_val->TD),&(astr_val->xptime[lc_i]),&li_step);
		(*ai_step) += li_step;
		p += li_step;
	}
	astr_val->IALLisnull = getdataformat06(p,&(astr_val->IALL),&li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	astr_val->IALLtimeisnull = getdataformat17(p,&(astr_val->TD),&(astr_val->IALLtime),&li_step);
	(*ai_step) += li_step;
	p += li_step;


	return ERROR_SUCCESS;
}

int decode_AFN0D_F116_118(uchar *as_data, str_AFN0D_F113_118*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;

	astr_val->TDisnull = getdataformat20(p,&(astr_val->TD),&li_step);
	(*ai_step) = li_step;
	p += li_step;

	for (lc_i = 2;lc_i <=19;lc_i++)
	{
		astr_val->Umaxisnull[lc_i] = getdataformat05(p,&(astr_val->Umax[lc_i]),&li_step);
		(*ai_step) += li_step;
		p += li_step;
		astr_val->xptimeisnull[lc_i] = getdataformat17(p,&(astr_val->TD),&(astr_val->xptime[lc_i]),&li_step);
		(*ai_step) += li_step;
		p += li_step;
	}
	astr_val->UALLisnull = getdataformat05(p,&(astr_val->UALL),&li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	astr_val->UALLtimeisnull = getdataformat17(p,&(astr_val->TD),&(astr_val->UALLtime),&li_step);
	(*ai_step) += li_step;
	p += li_step;


	return ERROR_SUCCESS;
}