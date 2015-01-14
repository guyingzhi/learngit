#include "decode_AFN0D_FN209_216.h"

int decode_afn0D_F209(uchar *as_data, str_AFN0D_F209 *astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	astr_val->DTisnull= getdataformat20(p, &(astr_val->DT), &li_step);
	(*ai_step) = li_step;
	p += li_step;

	astr_val->CBisnull = getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->state  = *p;
	p++;
	(*ai_step) +=1;
	/*��բ����ʱ��*/
	astr_val->hzisnull= getdataformat01(p, &(astr_val->hz), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	/*��բ����ʱ��*/
	astr_val->TZisnull= getdataformat01(p, &(astr_val->TZ), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	return ERROR_SUCCESS;
}
int decode_afn0D_F211F212(uchar *as_data, str_AFN0D_F211F212*astr_val, int *ai_step,int frozen_type)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	/*�¶���Ĺ��õ���Ϣ*/
	if(frozen_type == 2)
	{
		astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}
	/*�ն���Ĺ��õ���Ϣ*/
	else if(frozen_type == 1)
	{
		astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}
	/*������ƽ�����ֵ*/
	astr_val->Ivalisnull = getdataformat05(p, &(astr_val->Ival), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	astr_val->Uvalisnull= getdataformat05(p, &(astr_val->Uval), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}
int decode_afn0D_F213(uchar *as_data, str_AFN0D_F213*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	/*����ʱ������*/
	astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
	(*ai_step) = li_step;
	p += li_step;
	
	/*����ʱ��*/
	astr_val->CBisnull= getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*���ܱ��̴���*/
	astr_val->valisnull= getdataformat10(p, &(astr_val->val), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*���һ�α��ʱ��*/
	astr_val->protimeisnull= getdataformat01(p, &(astr_val->protime), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*���ܱ�β�Ǵ򿪴���*/
	astr_val->val1isnull= getdataformat10(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*���һ��β�Ǵ�ʱ��*/
	astr_val->opentimeisnull= getdataformat01(p, &(astr_val->opentime), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	return ERROR_SUCCESS;
}
int decode_afn0D_F214(uchar *as_data, str_AFN0D_F214*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	/*����ʱ��*/
	astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
	(*ai_step) = li_step;
	p += li_step;
	
	/*����ʱ��*/
	astr_val->CBisnull= getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*Уʱ�ܴ���*/
	astr_val->valisnull= getdataformat10(p, &(astr_val->val), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*Уʱǰʱ��*/
	astr_val->CStimeisnull= getdataformat01(p, &(astr_val->CStime), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*Уʱ��ʱ��*/
	astr_val->CStime1isnull= getdataformat01(p, &(astr_val->CStime1), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	/*ʱ�α����ܴ���*/
	astr_val->val1isnull= getdataformat10(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	/*���һ��ʱ�α���ʱ��*/
	astr_val->nowTDisnull = getdataformat01(p, &(astr_val->nowTD), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}
int decode_afn0D_F210F215(uchar *as_data, str_AFN0D_F210F215 *astr_val, int *ai_step,int frozen_type)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	if(frozen_type == 2)			/*�¶���Ĺ��õ���Ϣ*/
	{
		astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}
	else if(frozen_type == 1)		/*�ն���Ĺ��õ���Ϣ*/
	{
		astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}
	 /*����ʱ��*/
	astr_val->dtisnull = getdataformat15(p, &(astr_val->dt), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*�������*/
	astr_val->Powertimeisnull = getdataformat08(p, (int *)&(astr_val->Powertime), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*ʣ����*/
	astr_val->Remainamountisnull = getdataformat14(p, &(astr_val->Remainamount), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*�ۼƹ�����*/
	astr_val->Accumulatedamountisnull = getdataformat14(p, &(astr_val->Accumulatedamount), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*ʣ�����*/
	astr_val->Dumpisnull = getdataformat11(p, &(astr_val->Dump), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*͸֧����*/	
	astr_val->Overdrawisnull = getdataformat11(p, &(astr_val->Overdraw), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*�ۼƹ�����*/
	astr_val->Accumulatedenergyisnull = getdataformat11(p, &(astr_val->Accumulatedenergy), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*�������޵���*/
	astr_val->Creditisnull = getdataformat11(p, &(astr_val->Credit), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*��������*/
	astr_val->Alarmisnull = getdataformat11(p, &(astr_val->Alarm), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	 /*���ϵ���*/
	astr_val->Failureisnull = getdataformat11(p, &(astr_val->Failure), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int decode_afn0D_F216(uchar *as_data, str_AFN0D_F216*astr_val, int *ai_step)
{
	int li_step;
	uchar *p, lc_i;
	p = as_data;
	
	/*����ʱ������*/
	astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
	(*ai_step) = li_step;
	p += li_step;
	
	/*����ʱ��*/
	astr_val->CBisnull= getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*������*/
	astr_val->val = *p;
	if ((astr_val->val= ((astr_val->val < 1) || (astr_val->val >14))) == DATA_ISNULL)
		return ERROR_NULL_FLS;
	li_step++;
	p++;
	
	/*�ѽ��й��ܵ���*/
	astr_val->val1isnull= getdataformat14(p, &(astr_val->val1), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*�ѽ���������й��ܵ���*/
	for(lc_i = 0;lc_i < astr_val->val;lc_i++)
	{
		astr_val->zxygisnull[lc_i]= getdataformat14(p, &(astr_val->zxyg[lc_i]), &li_step);
		(*ai_step) = li_step;
		p += li_step;
	}

		/*δ���й��ܵ���*/
	astr_val->val2isnull= getdataformat14(p, &(astr_val->val2), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*δ����������й��ܵ���*/
	for(lc_i = 0;lc_i < astr_val->val;lc_i++)
	{
		astr_val->zxyg1isnull[lc_i]= getdataformat14(p, &(astr_val->zxyg1[lc_i]), &li_step);
		(*ai_step) += li_step;
		p += li_step;
	}
	return ERROR_SUCCESS;
}
