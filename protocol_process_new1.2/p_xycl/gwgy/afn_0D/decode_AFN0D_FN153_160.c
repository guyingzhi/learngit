#include"decode_AFN0D_FN153_160.h"


/*********** �����ۺ�F153F155F157F159���� *************
	as_data	����ָ��

	str_AFN0D_Activeenergy   �й�������ֵ
	ai_step ������ռ�ֽ���
	���أ�	 1	������������
			
*******************************************/
int decode_AFN0D_Activeenergy(uchar *as_data, str_AFN0D_Activeenergy*astr_val, int *ai_step,int frozen_type)
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
	
	astr_val->CBisnull = getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->Avalisnull = getdataformat14(p, &(astr_val->Aval), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->Bvalisnull = getdataformat14(p, &(astr_val->Bval), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->Cvalisnull = getdataformat14(p, &(astr_val->Cval), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return  ERROR_SUCCESS;
}


/*********** �����ۺ�F154F156F158F160���� *************
	as_data	����ָ��

	str_AFN0D_idleenergy   �й�������ֵ
	ai_step ������ռ�ֽ���
	���أ�	 1	������������
			
*******************************************/
int decode_AFN0D_Idleenergy(uchar *as_data, str_AFN0D_idleenergy*astr_val, int *ai_step,int frozen_type)
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
	/*�޹�����ʾֵ*/
	astr_val->CBisnull = getdataformat15(p, &(astr_val->CB), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->Aidleisnull= getdataformat11(p, &(astr_val->Aidle), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->Bidleisnull= getdataformat11(p, &(astr_val->Bidle), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->Cidleisnull= getdataformat11(p, &(astr_val->Cidle), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}
