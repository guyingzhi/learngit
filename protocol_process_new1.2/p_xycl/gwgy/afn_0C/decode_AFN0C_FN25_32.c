#include "decode_AFN0C_FN25_32.h"

/*********** 解析电压C类F25数据 *************
	data	报文指针

	lstr_val 解码的结果
    ai_len 报文所占字节数
	返回：	 1	解析正常返回
*******************************************/
int decode_afn0C_F25(uchar * data, str_AFN0C_FN25 *lstr_val, int * ai_len)
{
	int li_step;
	uchar *p;
	p = data;
	lstr_val->isnull.cbtime = getdataformat15(p, &(lstr_val->val.cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;
	lstr_val->isnull.PZ = getdataformat09(p, &(lstr_val->val.PZ), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.PA = getdataformat09(p, &(lstr_val->val.PA), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.PB = getdataformat09(p, &(lstr_val->val.PB), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.PC = getdataformat09(p, &(lstr_val->val.PC), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.QZ = getdataformat09(p, &(lstr_val->val.QZ), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.QA = getdataformat09(p, &(lstr_val->val.QA), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.QB = getdataformat09(p, &(lstr_val->val.QB), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.QC = getdataformat09(p, &(lstr_val->val.QC), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.COSZ = getdataformat05(p, &(lstr_val->val.COSZ), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.COSA = getdataformat05(p, &(lstr_val->val.COSA), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.COSB = getdataformat05(p, &(lstr_val->val.COSB), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.COSC = getdataformat05(p, &(lstr_val->val.COSC), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.UA = getdataformat07(p, &(lstr_val->val.UA), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.UB = getdataformat07(p, &(lstr_val->val.UB), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.UC = getdataformat07(p, &(lstr_val->val.UC), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.IA = getdataformat25(p, &(lstr_val->val.IA), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.IB = getdataformat25(p, &(lstr_val->val.IB), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.IC = getdataformat25(p, &(lstr_val->val.IC), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.I0 = getdataformat25(p, &(lstr_val->val.I0), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.SZZ = getdataformat09(p, &(lstr_val->val.SZZ), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.SZA = getdataformat09(p, &(lstr_val->val.SZA), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.SZB = getdataformat09(p, &(lstr_val->val.SZB), &li_step);
	*ai_len += li_step;
	p += li_step;
	lstr_val->isnull.SZC = getdataformat09(p, &(lstr_val->val.SZC), &li_step);
	*ai_len += li_step;
	p += li_step;
	return ERROR_SUCCESS;
}

int decode_afn0C_F26(uchar * data, str_AFN0C_FN26* lstr_val, int * ai_len)
{
	uchar  *p, lc_i;
	int li_step;
	p = data;
	lstr_val->isnull.cbtime =getdataformat15 (p, &(lstr_val->val.cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	/*断相次数*/
	for (lc_i = 0; lc_i < 4; lc_i++)
	{
		lstr_val->isnull.times[lc_i] = getdataformat08(p, &(lstr_val->val.times[lc_i]), &li_step);
		*ai_len += li_step;
		p += li_step;
	}
	/*断相累计时间*/
	for (lc_i = 0; lc_i < 4; lc_i++)
	{
		lstr_val->isnull.val[lc_i] = getdataformat10(p, &(lstr_val->val.val[lc_i]), &li_step);
		*ai_len += li_step;
		p += li_step;
	}
	/*起始时间*/
	for (lc_i = 0; lc_i < 4; lc_i++)
	{
		lstr_val->isnull.startdt[lc_i] = getdataformat17(p, &(lstr_val->val.cbtime), &(lstr_val->val.startdt[lc_i]), &li_step);
		*ai_len += li_step;
		p += li_step;
	}

	/*结束时间*/
	for (lc_i = 0; lc_i < 4; lc_i++)
	{
		lstr_val->isnull.enddt[lc_i] = getdataformat17(p, &(lstr_val->val.cbtime), &(lstr_val->val.enddt[lc_i]), &li_step);
		*ai_len += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}

int decode_afn0C_F27(uchar *data,  str_AFN0C_FN27 *lstr_val,int *ai_len)
{
	uchar  *p, lc_i, lc_flag;
	int li_step;

	p = data;
	/*终端抄表时间*/
	lstr_val->isnull.cbtime = getdataformat15(p, &(lstr_val->val.cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	/*终端时间*/
	lstr_val->isnull.termtime = getdataformat01(p, &(lstr_val->val.termtime), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*电池工作时间*/
	lstr_val->isnull.worktime = getdataformat27(p, &(lstr_val->val.worktime), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*编程次数*/
	lstr_val->isnull.val1 = getdataformat10(p, &(lstr_val->val.val1), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*最近一次编程时间*/
	lstr_val->isnull.time1 = getdataformat01(p, &(lstr_val->val.time1), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*电表清零次数*/
	lstr_val->isnull.val = getdataformat10(p, &(lstr_val->val.val), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*最近一次电表清零时间*/
	lstr_val->isnull.time = getdataformat01(p,  &(lstr_val->val.time), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*需量清零次数*/
	lstr_val->isnull.val2 = getdataformat10(p, &(lstr_val->val.val2), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*最近一次需量清零时间*/
	lstr_val->isnull.time2 = getdataformat01(p,  &(lstr_val->val.time2), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*事件清零总次数*/
	lstr_val->isnull.val3 = getdataformat10(p, &(lstr_val->val.val3), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*最近一次事件清零时间*/
	lstr_val->isnull.time3 = getdataformat01(p,  &(lstr_val->val.time3), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*校时总次数*/
	lstr_val->isnull.val3 = getdataformat10(p, &(lstr_val->val.val3), &li_step);
	*ai_len += li_step;
	p += li_step;

	/*最近一次校时时间*/
	lstr_val->isnull.time4 = getdataformat01(p,  &(lstr_val->val.time4), &li_step);
	*ai_len += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}	
int decode_afn0C_F28(uchar *data,  str_AFN0C_FN28 *lstr_val,int *ai_len)
{
	int li_step, li_i, li_j;
	uchar *p;

	p = data;
	lstr_val->dtisnull = getdataformat15(p, &(lstr_val->cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;
	for (li_i = 0; li_i < 7; li_i++)
	{
		for (li_j = 0; li_j < 8; li_j++)
		{
			lstr_val->flag[li_i].ztbw[li_j] =  (*p >> li_j) & 0x01;
		}
		(*ai_len) += 1;
		p++;

		for (li_j = 8; li_j < 16; li_j++)
		{
			lstr_val->flag[li_i].ztbw[li_j] =  (*p >> li_j) & 0x01;
		}
		(*ai_len) += 1;
		p++;
	}

	for (li_i = 0; li_i < 7; li_i++)
	{
		for (li_j = 0; li_j < 8; li_j++)
		{
			lstr_val->flag[li_i].yxzt[li_j] =  (*p >> li_j) & 0x01;
		}
		(*ai_len) += 1;
		p++;

		for (li_j = 8; li_j < 16; li_j++)
		{
			lstr_val->flag[li_i].yxzt[li_j] =  (*p >> li_j) & 0x01;
		}
		(*ai_len) += 1;
		p++;
	}

	return ERROR_SUCCESS;
}	
int decode_afn0C_F29(uchar *data,  str_AFN0C_FN29 *lstr_val,int *ai_len)
{
	int li_step;
	uchar *p;
	p = data;
	lstr_val->cbtimeisnull = getdataformat15(p, &(lstr_val->cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	lstr_val->cuygnszisnull = getdataformat14(p, &(lstr_val->cuygnsz), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	lstr_val->feygnszisnull = getdataformat14(p, &(lstr_val->feygnsz), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	return ERROR_SUCCESS;
}	
int decode_afn0C_F30(uchar *data,  str_AFN0C_FN30*lstr_val,int *ai_len)
{
	int li_step;
	uchar *p;
	p = data;
	lstr_val->cbtimeisnull = getdataformat15(p, &(lstr_val->cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	lstr_val->cuygnszisnull = getdataformat14(p, &(lstr_val->cuygnsz), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	lstr_val->feygnszisnull = getdataformat14(p, &(lstr_val->feygnsz), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	return ERROR_SUCCESS;
}	
int decode_afn0C_F31(uchar *data,  str_AFN0C_FN31*lstr_val,int *ai_len)
{
	int li_step, li_i;
	uchar *p;

	p = data;
	lstr_val->isnull.cbtime = getdataformat15(p, &(lstr_val->val.cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	for (li_i = 0; li_i < 2; li_i++)
	{
		lstr_val->isnull.ansz[li_i] = getdataformat14(p, &(lstr_val->val.ansz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 2; li_i < 4; li_i++)
	{
		lstr_val->isnull.ansz[li_i] = getdataformat11(p, &(lstr_val->val.ansz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 0; li_i < 2; li_i++)
	{
		lstr_val->isnull.bnsz[li_i] = getdataformat14(p, &(lstr_val->val.bnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 2; li_i < 4; li_i++)
	{
		lstr_val->isnull.bnsz[li_i] = getdataformat11(p, &(lstr_val->val.bnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 0; li_i < 2; li_i++)
	{
		lstr_val->isnull.cnsz[li_i] = getdataformat14(p, &(lstr_val->val.cnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 2; li_i < 4; li_i++)
	{
		lstr_val->isnull.cnsz[li_i] = getdataformat11(p, &(lstr_val->val.cnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	return ERROR_SUCCESS;
}	
int decode_afn0C_F32(uchar *data,  str_AFN0C_FN32*lstr_val,int *ai_len)
{
	int li_step, li_i;
	uchar *p;

	p = data;
	lstr_val->isnull.cbtime = getdataformat15(p, &(lstr_val->val.cbtime), &li_step);
	(*ai_len) = li_step;
	p += li_step;

	for (li_i = 0; li_i < 2; li_i++)
	{
		lstr_val->isnull.ansz[li_i] = getdataformat14(p, &(lstr_val->val.ansz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 2; li_i < 4; li_i++)
	{
		lstr_val->isnull.ansz[li_i] = getdataformat11(p, &(lstr_val->val.ansz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 0; li_i < 2; li_i++)
	{
		lstr_val->isnull.bnsz[li_i] = getdataformat14(p, &(lstr_val->val.bnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 2; li_i < 4; li_i++)
	{
		lstr_val->isnull.bnsz[li_i] = getdataformat11(p, &(lstr_val->val.bnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 0; li_i < 2; li_i++)
	{
		lstr_val->isnull.cnsz[li_i] = getdataformat14(p, &(lstr_val->val.cnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	for (li_i = 2; li_i < 4; li_i++)
	{
		lstr_val->isnull.cnsz[li_i] = getdataformat11(p, &(lstr_val->val.cnsz[li_i]), &li_step);
		(*ai_len) = li_step;
		p += li_step;
	}

	return ERROR_SUCCESS;
}	
