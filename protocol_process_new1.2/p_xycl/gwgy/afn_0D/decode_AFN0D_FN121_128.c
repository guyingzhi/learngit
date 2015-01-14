#include "decode_AFN0D_FN121_128.h"


/*********** 解析谐波越限统计值数据 *************
	as_data	报文指针

    str_AFN0D_F121_123
        str_AFN0D_F121_123_VAL
            TD            时标
            XBCS          谐波次数
            overlimitU    电压越限时间
            overlimitI    电流越限时间
        str_AFN0D_F121_123_ISNULL
            TD            时标判空标志
            XBCS          谐波次数判空标志
            overlimitU    电压越限时间判空标志
            overlimitI    电流越限时间判空标志
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
            -8  谐波次数不对
*******************************************/
int decode_AFN0D_F121_123(uchar *data, str_AFN0D_F121_123 *astr_val, int *ai_step)
{
	uchar *p;
	int li_step, li_i;
	p = data;
	astr_val->isnull.TD = getdataformat20(p, &(astr_val->val.TD), &li_step);
	*ai_step = li_step;
	p += li_step;
	astr_val->val.XBCS = *p;
	(*ai_step)++;
	p++;
	if (astr_val->val.XBCS > 19)
		return ERROR_NULL_XBCNT;
	for (li_i = 0; li_i < 19; li_i++)
	{
		if ((astr_val->isnull.overlimitU[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
		{
			astr_val->val.overlimitU[li_i] = *(p + 1);
			astr_val->val.overlimitU[li_i] = (astr_val->val.overlimitU[li_i] << 8) + *p;
		}
	*ai_step += 2;
	p += 2;
	}
	for (li_i = 0; li_i < 19; li_i++)
	{
		if ((astr_val->isnull.overlimitI[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
		{
			astr_val->val.overlimitI[li_i] = *(p + 1);
			astr_val->val.overlimitI[li_i] = (astr_val->val.overlimitI[li_i] << 8) + *p;
		}
	*ai_step += 2;
	p += 2;
	}
	return ERROR_SUCCESS;
}

int decode_AFN0D_F124_126(uchar *data, str_AFN0D_F124_126 *astr_val, int *ai_step)
{
	uchar *p;
	int li_step, li_i;
	p = data;
	/*日冻结数据时标*/
	astr_val->isnull.TDisnull = getdataformat20(p,&(astr_val->val.TD),&li_step);
	*ai_step = li_step;
	p += li_step;
	/*谐波次数*/
	astr_val->val.num = *p;
	if (astr_val->val.num >=19 ||astr_val->val.num<0)
		return ERROR_RANGE_DATA;
	*ai_step++;
	p++;
	/*相总畸变电压含有率*/
	astr_val->isnull.Uallisnull= getdataformat05(p,&(astr_val->val.Uall),&li_step);
	*ai_step += li_step;
	p += li_step;

	astr_val->isnull.Uoddisnull = getdataformat05(p,&(astr_val->val.Uodd),&li_step);
	*ai_step += li_step;
	p+=li_step;

	astr_val->isnull.Uevenisnull = getdataformat05(p,&(astr_val->val.Ueven),&li_step);
	(*ai_step +=li_step);
	p+= li_step;
	/*2次谐波电压含有率概率值*/
	for(li_i = 2;li_i<=astr_val->val.num;li_i++)
	{
		astr_val->isnull.Uvalisnull[li_i] = getdataformat05(p,&(astr_val->val.Uval[li_i]),&li_step);
		(*ai_step +=li_step);
		p+= li_step;

		astr_val->isnull.Iallisnull = getdataformat06(p,&(astr_val->val.Iall),&li_step);
		(*ai_step +=li_step);
		p+= li_step;

		astr_val->isnull.Ivalisnull[li_i] = getdataformat06(p,&(astr_val->val.Iall),&li_step);
		(*ai_step +=li_step);
		p+= li_step;
	}
	return ERROR_SUCCESS;
}

