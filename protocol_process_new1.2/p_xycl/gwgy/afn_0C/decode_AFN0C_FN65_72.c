#include "decode_AFN0C_FN65_72.h"



int decode_afn0C_F65(uchar *as_data, str_AFN0C_FN65 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;

	p = as_data;

	astr_val->ddkz = getbytebybit(*p, 0, 1);
	astr_val->yfkz = getbytebybit(*p, 1, 1);
	astr_val->yjbs = getbytebybit(*p, 2, 1);
	astr_val->rjbs = getbytebybit(*p, 3, 1);
	astr_val->gybs = getbytebybit(*p, 4, 1);
	astr_val->sbgzbs = getbytebybit(*p, 5, 1);
	astr_val->zxhlgzbs = getbytebybit(*p, 6, 1);

	*(ai_step) = 1;
	p++;

	for (lc_i = 0; lc_i < 8; lc_i++)
	{
		astr_val->drstate[lc_i] = getbytebybit(*p, lc_i, 1);
	}

	for (lc_i = 0; lc_i < 8; lc_i++)
	{
		astr_val->drstate[lc_i + 8] = getbytebybit(*(p + 1), lc_i, 1);
	}
	*ai_step += 2;
	p += 2;

	return ERROR_SUCCESS;
}

int decode_afn0C_F66(uchar *as_data, str_AFN0C_FN66 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	p = as_data;

	(*ai_step) = 0;
	for (lc_i = 0; lc_i < 16; lc_i++)
	{
		if ((astr_val->secisnull[lc_i] = dataisnull(p, 4)) == DATA_ISNOTNULL)
		astr_val->sec[lc_i] = (*(p + 3) << 24) + (*(p + 2) << 16) + (*(p + 1) << 8) + *p;
		*ai_step +=  4;
		p += 4;
	}

	for (lc_i = 0; lc_i < 16; lc_i++)
	{
		if ((astr_val->timesisnull[lc_i] = dataisnull(p, 4)) == DATA_ISNOTNULL)
			astr_val->times[lc_i] = (*(p + 3) << 24) + (*(p + 2) << 16) + (*(p + 1) << 8) + *p;
		*ai_step += 4;
		p += 4;
	}
	return ERROR_SUCCESS;
}


int decode_afn0C_F67(uchar *as_data, str_AFN0C_FN67 *astr_val, int *ai_step)
{
	uchar  *p;
	int li_step;

	p = as_data;
	astr_val->val1isnull = getdataformat13(p, &(astr_val->val1), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	astr_val->val2isnull = getdataformat13(p, &(astr_val->val2), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}
