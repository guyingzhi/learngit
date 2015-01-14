#include "decode_AFN0C_FN41_48.h"


int decode_afn0C_F4all(uchar *as_data, str_AFN0C_FN41_48 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;

	astr_val->flnum = *p;
	if ((astr_val->flnum < 1) || (astr_val->flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step) = 1;
	p++;

	astr_val->valisnull = getdataformat13(p, &(astr_val->val), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->flnum; lc_i++)
	{
		astr_val->valflisnull[lc_i] = getdataformat13(p, &(astr_val->valfl[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}
