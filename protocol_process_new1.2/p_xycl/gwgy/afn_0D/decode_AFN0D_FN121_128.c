#include "decode_AFN0D_FN121_128.h"


/*********** ����г��Խ��ͳ��ֵ���� *************
	as_data	����ָ��

    str_AFN0D_F121_123
        str_AFN0D_F121_123_VAL
            TD            ʱ��
            XBCS          г������
            overlimitU    ��ѹԽ��ʱ��
            overlimitI    ����Խ��ʱ��
        str_AFN0D_F121_123_ISNULL
            TD            ʱ���пձ�־
            XBCS          г�������пձ�־
            overlimitU    ��ѹԽ��ʱ���пձ�־
            overlimitI    ����Խ��ʱ���пձ�־
    ai_step ������ռ�ֽ���
	���أ�	 1	������������
            -8  г����������
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
	/*�ն�������ʱ��*/
	astr_val->isnull.TDisnull = getdataformat20(p,&(astr_val->val.TD),&li_step);
	*ai_step = li_step;
	p += li_step;
	/*г������*/
	astr_val->val.num = *p;
	if (astr_val->val.num >=19 ||astr_val->val.num<0)
		return ERROR_RANGE_DATA;
	*ai_step++;
	p++;
	/*���ܻ����ѹ������*/
	astr_val->isnull.Uallisnull= getdataformat05(p,&(astr_val->val.Uall),&li_step);
	*ai_step += li_step;
	p += li_step;

	astr_val->isnull.Uoddisnull = getdataformat05(p,&(astr_val->val.Uodd),&li_step);
	*ai_step += li_step;
	p+=li_step;

	astr_val->isnull.Uevenisnull = getdataformat05(p,&(astr_val->val.Ueven),&li_step);
	(*ai_step +=li_step);
	p+= li_step;
	/*2��г����ѹ�����ʸ���ֵ*/
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

