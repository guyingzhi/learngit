#include "decode_AFN0C_FN17_24.h"


/*************************************
       ��ǰ�ܼӹ��й�����
       
**************************************/
int decode_afn0C_F17(uchar * data, str_AFN0C_FN17* lstr_val, int *ai_len)
{
	uchar *p, lc_i, lc_j;
	p = data;

	lstr_val->valisnull = getdataformat02(p, &(lstr_val->val), ai_len);
	
	return ERROR_SUCCESS;
}
/*************************************
       ��ǰ�ܼӹ��޹�����
      
**************************************/
int decode_afn0C_F18(uchar * data, str_AFN0C_FN18* lstr_val, int *ai_len)
{
	uchar *p, lc_i, lc_j;
	p = data;
	lstr_val->idleisnull= getdataformat02(p, &(lstr_val->idle), ai_len);
	
	return ERROR_SUCCESS;
}
/*************************************
       �����ܼӹ�����������
        ����λ1~14
**************************************/
int decode_afn0C_F19(uchar * data, str_AFN0C_FN19* lstr_val, int *ai_len)
{
	uchar  *p, lc_i, lc_unit;
	int li_step;
	p = data;
	/*������*/
	lstr_val->data.ratenum= *p;
	if ((lstr_val->data.ratelnumisnull= ((lstr_val->data.ratenum < 1) || (lstr_val->data.ratenum >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	li_step++;
	p++;
	
	/*�����ܼ��й��ܵ�����*/
	if ((lstr_val->data.valisnull= getdataformat03(p, &(lstr_val->data.val), &lc_unit, &li_step)) == DATA_ISNOTNULL)
		if (lc_unit)
			lstr_val->data.val = lstr_val->data.val * 1000;
	*ai_len += li_step;
	p += li_step;

	/*�����ܼ��й�������*/
	for (lc_i = 0; lc_i < lstr_val->data.ratenum; lc_i++)
	{
		if ((lstr_val->data.valtateisnull[lc_i] =getdataformat03(p , &(lstr_val->data.varate[lc_i]), &lc_unit, &li_step)) == DATA_ISNOTNULL)
			
			if (lc_unit)
				lstr_val->data.varate[lc_i] = lstr_val->data.varate[lc_i] * 1000;
	*ai_len += li_step;
	p += li_step;
	return ERROR_SUCCESS;
}
}
/*************************************
       �����ܼ��޹�������
**************************************/
int decode_afn0C_F20(uchar * data, str_AFN0C_FN20* lstr_val, int *ai_len)
{
	uchar  *p, lc_i, lc_unit;
	int li_step;
	p = data;
	
	/*������*/
	lstr_val->data.ratenum= *p;
	if ((lstr_val->data.ratelnumisnull= ((lstr_val->data.ratenum< 1) || (lstr_val->data.ratenum >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	(*ai_len) = 1;
	p++;
	
	/*�����ܼ��޹��ܵ�����*/
	if ((lstr_val->data.valisnull= getdataformat03(p, &(lstr_val->data.val), &lc_unit, &li_step)) == DATA_ISNOTNULL)
		if (lc_unit)
			lstr_val->data.val = lstr_val->data.val * 1000;
	*ai_len += li_step;
	p += li_step;

	/*�����ܼ��޹�������*/
	for (lc_i = 0; lc_i < lstr_val->data.ratenum; lc_i++)
	{
		if ((lstr_val->data.valtateisnull[lc_i] = getdataformat03(p, &(lstr_val->data.varate[lc_i]), &lc_unit, &li_step)) == DATA_ISNOTNULL)
			if (lc_unit)
				lstr_val->data.varate[lc_i] = lstr_val->data.varate[lc_i] * 1000;
	*ai_len += li_step;
	p += li_step;
	}
	return ERROR_SUCCESS;
}
/*************************************
            �����ܼ��й�������
**************************************/
int decode_afn0C_F21(uchar * data, str_AFN0C_FN21* lstr_val, int *ai_len)
{
	uchar  *p, lc_i, lc_unit;
	int li_step = 0;
	p = data;
	
	/*������*/
	lstr_val->data.ratenum= *p;
	
	if ((lstr_val->data.ratelnumisnull= ((lstr_val->data.ratenum< 1) || (lstr_val->data.ratenum >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	(*ai_len) = 1;
	p++;
	/*�����ܼ��й��ܵ�����*/
	if ((lstr_val->data.valisnull= getdataformat03(p, &(lstr_val->data.val), &lc_unit, &li_step)) == DATA_ISNOTNULL)
		if (lc_unit)
			lstr_val->data.val = lstr_val->data.val * 1000;
	*ai_len += li_step;
	p += li_step;

	/*�����ܼ��й�������*/
	for (lc_i = 0; lc_i < lstr_val->data.ratenum; lc_i++)
	{
		if ((lstr_val->data.valtateisnull[lc_i] = getdataformat03(p, &(lstr_val->data.varate[lc_i]), &lc_unit, &li_step)) == DATA_ISNOTNULL)
			if (lc_unit)
				lstr_val->data.varate[lc_i] = lstr_val->data.varate[lc_i] * 1000;
	*ai_len += li_step;
	p += li_step;
    }
    return ERROR_SUCCESS;

}
/*************************************
       �����ܼ��޹�������
**************************************/
int decode_afn0C_F22(uchar * data, str_AFN0C_FN22* lstr_val, int *ai_len)
{
	uchar  *p, lc_i, lc_unit;
	int li_step;
	p = data;
	
	/*������*/
	lstr_val->data.ratenum= *p;
	if ((lstr_val->data.ratelnumisnull= ((lstr_val->data.ratenum< 1) || (lstr_val->data.ratenum>14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	(*ai_len) = 1;
	p++;
	
	/*�����ܼ��޹��ܵ�����*/
	if ((lstr_val->data.valisnull= getdataformat03(p, &(lstr_val->data.val), &lc_unit, &li_step)) == DATA_ISNOTNULL)
		if (lc_unit)
			lstr_val->data.val = lstr_val->data.val * 1000;
	*ai_len += li_step;
	p += li_step;

	/*�����ܼ��޹�������*/
	for (lc_i = 0; lc_i < lstr_val->data.ratenum; lc_i++)
	{
		if ((lstr_val->data.valtateisnull[lc_i] = getdataformat03(p, &(lstr_val->data.varate[lc_i]), &lc_unit, &li_step)) == DATA_ISNOTNULL)
			if (lc_unit)
				lstr_val->data.varate[lc_i] = lstr_val->data.varate[lc_i] * 1000;
	*ai_len += li_step;
	p += li_step;
	}
	return ERROR_SUCCESS;
}
/*************************************
      �ն˵�ǰʣ�����
**************************************/
int decode_afn0C_F23(uchar * data, str_AFN0C_FN23* lstr_val, int *ai_len)
{
	uchar  *p, lc_unit;
	p = data;

	if ((lstr_val->valisnull= getdataformat03(p , &(lstr_val->val), &lc_unit, ai_len)) == DATA_ISNOTNULL)
		if (lc_unit)
			lstr_val->val = lstr_val->val * 1000;
	return ERROR_SUCCESS;
}
/*************************************
      ��ǰ�����¸��ؿغ��ܼӹ����ʶ���ֵ
**************************************/
int decode_afn0C_F24(uchar * data, str_AFN0C_FN24* lstr_val, int *ai_len)
{
	uchar *p, lc_i, lc_j;
	p = data;
	lstr_val->valisnull= getdataformat02(p, &(lstr_val->val), ai_len);
	return ERROR_SUCCESS;
}
