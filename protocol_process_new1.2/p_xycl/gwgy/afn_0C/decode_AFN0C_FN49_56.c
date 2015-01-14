#include "decode_AFN0C_FN49_56.h"


int decode_afn0C_F49(uchar *as_data, str_AFN0C_FN49 *astr_val, int *ai_step)
{
	uchar  *p;
	int li_step;

	p = as_data;
	astr_val->Uaisnull = getdataformat05(p, &(astr_val->Ua), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	astr_val->Ubisnull = getdataformat05(p, &(astr_val->Ub), &li_step);
	*ai_step += li_step;
	p += li_step;

	astr_val->Ucisnull = getdataformat05(p, &(astr_val->Uc), &li_step);
	*ai_step += li_step;
	p += li_step;


	astr_val->Iaisnull = getdataformat05(p, &(astr_val->Ia), &li_step);
	*ai_step += li_step;
	p += li_step;

	astr_val->Ibisnull = getdataformat05(p, &(astr_val->Ib), &li_step);
	*ai_step += li_step;
	p += li_step;

	astr_val->Icisnull = getdataformat05(p, &(astr_val->Ic), &li_step);
	*ai_step += li_step;
	p += li_step;
	return ERROR_SUCCESS;

}
