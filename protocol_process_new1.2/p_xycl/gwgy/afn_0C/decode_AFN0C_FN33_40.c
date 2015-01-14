#include "decode_AFN0C_FN33_40.h"


int decode_afn0C_F33(uchar *as_data, str_AFN0C_FN33 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;
	/*有功 总*/
	astr_val->isnull.zxygz = getdataformat14(p, &(astr_val->val.zxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxyg[lc_i] = getdataformat14(p, &(astr_val->val.zxyg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*无功 总*/
	astr_val->isnull.zxwgz = getdataformat11(p, &(astr_val->val.zxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxwg[lc_i] = getdataformat11(p, &(astr_val->val.zxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*一象限*/
	astr_val->isnull.wgz1 = getdataformat11(p, &(astr_val->val.wgz1), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg1[lc_i] = getdataformat11(p, &(astr_val->val.wg1[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*四象限*/
	astr_val->isnull.wgz4 = getdataformat11(p, &(astr_val->val.wgz4), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg4[lc_i] = getdataformat11(p, &(astr_val->val.wg4[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}


int decode_afn0C_F34(uchar *as_data, str_AFN0C_FN34 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;
	/*有功 总*/
	astr_val->isnull.fxygz = getdataformat14(p, &(astr_val->val.fxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxyg[lc_i] = getdataformat14(p, &(astr_val->val.fxyg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*无功 总*/
	astr_val->isnull.fxwgz = getdataformat11(p, &(astr_val->val.fxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxwg[lc_i] = getdataformat11(p, &(astr_val->val.fxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*二象限*/
	astr_val->isnull.wgz2 = getdataformat11(p, &(astr_val->val.wgz2), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg2[lc_i] = getdataformat11(p, &(astr_val->val.wg2[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*三象限*/
	astr_val->isnull.wgz3 = getdataformat11(p, &(astr_val->val.wgz3), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg3[lc_i] = getdataformat11(p, &(astr_val->val.wg3[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}


int decode_afn0C_F35(uchar *as_data, str_AFN0C_FN35 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;

	 /*有功 总需量*/
	astr_val->isnull.zxygz = getdataformat23(p, &(astr_val->val.zxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
	    astr_val->isnull.zxyg[lc_i] = getdataformat23(p, &(astr_val->val.zxyg[lc_i]), &li_step);
	    *ai_step += li_step;
	    p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.zxygzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxygzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxygdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxygdt[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}


	 /*无功 总需量*/
	astr_val->isnull.zxwgz = getdataformat23(p, &(astr_val->val.zxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxwg[lc_i] = getdataformat23(p, &(astr_val->val.zxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.zxwgzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxwgzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
	    astr_val->isnull.zxwgdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxwgdt[lc_i]), &li_step);
	    *ai_step += li_step;
	    p += li_step;
	}
	return ERROR_SUCCESS;
}


int decode_afn0C_F36(uchar *as_data, str_AFN0C_FN36 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;

	/*有功 总需量*/
	astr_val->isnull.fxygz = getdataformat23(p, &(astr_val->val.fxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
	astr_val->isnull.fxyg[lc_i] = getdataformat23(p, &(astr_val->val.fxyg[lc_i]), &li_step);
	*ai_step += li_step;
	p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.fxygzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxygzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
	astr_val->isnull.fxygdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxygdt[lc_i]), &li_step);
	*ai_step += li_step;
	p += li_step;
	}


	/*无功 总需量*/
	astr_val->isnull.fxwgz = getdataformat23(p, &(astr_val->val.fxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxwg[lc_i] = getdataformat23(p, &(astr_val->val.fxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.fxwgzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxwgzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxwgdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxwgdt[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}

int decode_afn0C_F37(uchar *as_data, str_AFN0C_FN37 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;
	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;
	/*有功 总*/
	astr_val->isnull.zxygz = getdataformat14(p, &(astr_val->val.zxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxyg[lc_i] = getdataformat14(p, &(astr_val->val.zxyg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*无功 总*/
	astr_val->isnull.zxwgz = getdataformat11(p, &(astr_val->val.zxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxwg[lc_i] = getdataformat11(p, &(astr_val->val.zxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*一象限*/
	astr_val->isnull.wgz1 = getdataformat11(p, &(astr_val->val.wgz1), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg1[lc_i] = getdataformat11(p, &(astr_val->val.wg1[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*四象限*/
	astr_val->isnull.wgz4 = getdataformat11(p, &(astr_val->val.wgz4), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg4[lc_i] = getdataformat11(p, &astr_val->val.wg4[lc_i], &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}

int decode_afn0C_F38(uchar *as_data, str_AFN0C_FN38 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;
	/*有功 总*/
	astr_val->isnull.fxygz = getdataformat14(p, &(astr_val->val.fxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxyg[lc_i] = getdataformat14(p, &(astr_val->val.fxyg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*无功 总*/
	astr_val->isnull.fxwgz = getdataformat11(p, &(astr_val->val.fxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxwg[lc_i] = getdataformat11(p, &(astr_val->val.fxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*二象限*/
	astr_val->isnull.wgz2 = getdataformat11(p, &(astr_val->val.wgz2), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg2[lc_i] = getdataformat11(p, &(astr_val->val.wg2[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	/*三象限*/
	astr_val->isnull.wgz3 = getdataformat11(p, &(astr_val->val.wgz3), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.wg3[lc_i] = getdataformat11(p, &(astr_val->val.wg3[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}

int decode_afn0C_F39(uchar *as_data, str_AFN0C_FN39 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum) > 14)
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;

	/*有功 总需量*/
	astr_val->isnull.zxygz = getdataformat23(p, &(astr_val->val.zxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxyg[lc_i] = getdataformat23(p, &(astr_val->val.zxyg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.zxygzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxygzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxygdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxygdt[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}


	/*无功 总需量*/
	astr_val->isnull.zxwgz = getdataformat23(p, &(astr_val->val.zxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxwg[lc_i] = getdataformat23(p, &(astr_val->val.zxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.zxwgzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxwgzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.zxwgdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.zxwgdt[lc_i]), &li_step);
		*ai_step += li_step;
	}

	return ERROR_SUCCESS;
}

int decode_afn0C_F40(uchar *as_data, str_AFN0C_FN40 *astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step;

	p = as_data;
	astr_val->isnull.cbtime = getdataformat15(p, &(astr_val->val.cbtime), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	/*费率数*/
	astr_val->val.flnum = *p;
	if ((astr_val->val.flnum < 1) || (astr_val->val.flnum > 14))
		return ERROR_NULL_FLS;
	(*ai_step)++;
	p++;

	/*有功 总需量*/
	astr_val->isnull.fxygz = getdataformat23(p, &(astr_val->val.fxygz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*有功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxyg[lc_i] = getdataformat23(p, &(astr_val->val.fxyg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.fxygzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxygzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxygdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxygdt[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}


	/*无功 总需量*/
	astr_val->isnull.fxwgz = getdataformat23(p, &(astr_val->val.fxwgz), &li_step);
	*ai_step += li_step;
	p += li_step;

	/*无功 费率需量*/
	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxwg[lc_i] = getdataformat23(p, &(astr_val->val.fxwg[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*发生时间*/
	astr_val->isnull.fxwgzdt = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxwgzdt), &li_step);
	*ai_step += li_step;
	p += li_step;

	for (lc_i = 0; lc_i < astr_val->val.flnum; lc_i++)
	{
		astr_val->isnull.fxwgdt[lc_i] = getdataformat17(p, &(astr_val->val.cbtime), &(astr_val->val.fxwgdt[lc_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}
