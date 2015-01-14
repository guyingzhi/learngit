#include "decode_AFN0C_FN169_178.h"

int decode_afn0C_F169(uchar *as_data, str_AFN0C_F169 *astr_val, int *ai_step)
{
	uchar  *p, lc_i, lc_j;
	int li_step;

	p = as_data;
	astr_val->port=*p;
	(*ai_step) = 1;
	p++;

	astr_val->n = *p;
	(*ai_step) += 1;
	p++;

	for (lc_i = 0; lc_i < astr_val->n; lc_i++)
	{
		astr_val->router[lc_i].level = *p;
		(*ai_step) += 1;
		p++;

		for (lc_j = 0; lc_j < astr_val->router[lc_i].level; lc_j++)
		{
			astr_val->router[lc_i].addrisnull[lc_j] = getdataformat12(p, &(astr_val->router[lc_i].addr[lc_j]), &li_step);
			(*ai_step) += li_step;
			p += li_step;
		}
	}

	return ERROR_SUCCESS;
}

int decode_afn0C_F170(uchar *as_data, str_AFN0C_F170 *astr_val, int *ai_step)
{
	uchar  *p, lc_i, lc_j;
	int li_step;

	p = as_data;
	astr_val->port=*p;
	(*ai_step) = 1;
	p++;

	astr_val->n = *p;
	(*ai_step) += 1;
	p++;

	astr_val->cbxw[0] = (*p & 0x10) >> 4;
	astr_val->cbxw[1] = (*p & 0x20) >> 5;
	astr_val->cbxw[2] = (*p & 0x40) >> 6;
	astr_val->sjxw[0] = *p & 0x01;
	astr_val->sjxw[1] = (*p & 0x02) >> 1;
	astr_val->sjxw[2] = (*p & 0x04) >> 2;
	(*ai_step) += 1;
	p++;

	astr_val->fspz = (*p & 0xf0) >> 4;
	astr_val->jspz = *p & 0x0f;
	(*ai_step) += 1;
	p++;

	astr_val->cbflag = *p;
	(*ai_step) += 1;
	p++;

	astr_val->cgtimeisnull = getdataformat01(p, &(astr_val->cgtime), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->sbtimeisnull = getdataformat01(p, &(astr_val->sbtime), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->sbljcs = *p;
	(*ai_step) += 1;
	p++;

	return ERROR_SUCCESS;
}
int decode_afn0C_F177(uchar *as_data, str_AFN0C_F177F178 *astr_val, int *ai_step)
{
	char  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
	p += li_step;
	*ai_step = li_step;

	/*费率数*/
	astr_val->FLS = *p;
	if ((astr_val->FLS < 1) || (astr_val->FLS >15))
		return ERROR_NULL_FLS;
	p++;
	(*ai_step) += 1;

	/*费率有功电能示值*/
	for (lc_i = 1; lc_i <= astr_val->FLS; lc_i++)
	{
		astr_val->valisnull[lc_i] = getdataformat14(p, &(astr_val->val[lc_i]), &li_step);
		p += li_step;
		*ai_step += li_step;
	}
	return ERROR_SUCCESS;
}