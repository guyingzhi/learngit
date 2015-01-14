#include "decode_AFN0D_FN217_219.h"

int decode_afn0D_F217(uchar *as_data, str_AFN0D_F217F218*astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step,li_res,lc_n,lc_m,lc_permin;
	p = as_data;
	li_res = getdataformat15(p, &astr_val->TD, &li_step);
	if (li_res == DATA_ISNULL)
		return ERROR_NULL_TD;
	*ai_step = li_step;
	p += li_step;
	if (dataisnull(p , 1))
		return ERROR_NULL_DENSITY;                  /*密度为空*/
	lc_m = *p;          /*取密度*/
	(*ai_step)++;
	p++;
	if (dataisnull(p, 1))
		return ERROR_NULL_POINT;                  /*点数为空*/
	lc_n = *p;          /*取点数*/
	switch(lc_m)
		{
		case 0:
			lc_permin = 0;
			break;
		case 1:
			lc_permin = 15;
			break;
		case 2:
			lc_permin = 30;
			break;
		case 3:
			lc_permin = 60;
		case 254:
			lc_permin = 5;
		case 255:
			lc_permin = 1;
			break;

		return ERROR_DATA_INVALID;
	};
	(*ai_step)++;
	p++;
	astr_val->num= lc_n;
	for(lc_i = 0 ;lc_i < lc_n ;lc_i++)
	{
		astr_val->val[lc_i] = *p;
		p++;
		*ai_step++;
	}

	return ERROR_SUCCESS;	
}
int decode_afn0D_F218(uchar *as_data, str_AFN0D_F217F218*astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step,li_res,lc_n,lc_m,lc_permin;
	p = as_data;

	li_res = getdataformat15(p, &astr_val->TD, &li_step);
	if (li_res == DATA_ISNULL)
		return ERROR_NULL_TD;
	*ai_step = li_step;
	p += li_step;
	if (dataisnull(p , 1))
		return ERROR_NULL_DENSITY;                  /*密度为空*/
	lc_m = *p;          /*取密度*/
	(*ai_step)++;
	p++;
	if (dataisnull(p, 1))
		return ERROR_NULL_POINT;                  /*点数为空*/
	lc_n = *p;          /*取点数*/
	switch(lc_m)
		{
		case 0:
			lc_permin = 0;
			break;
		case 1:
			lc_permin = 15;
			break;
		case 2:
			lc_permin = 30;
			break;
		case 3:
			lc_permin = 60;
		case 254:
			lc_permin = 5;
		case 255:
			lc_permin = 1;
			break;

		return ERROR_DATA_INVALID;
	};
	(*ai_step)++;
	p++;
	astr_val->num= lc_n;

	for (lc_i = 0; lc_i < lc_n;lc_i++)
	{
		/*噪声比值*/
		astr_val->val[lc_i] =*(p++);

		/*主节点地址*/
		astr_val->addrisnull[lc_i] = getdataformat12(p, &(astr_val->addr[lc_i]), &li_step);
		p +=li_step;
		*ai_step +=li_step;
	}
	return ERROR_SUCCESS;	
}
int decode_afn0D_F219(uchar *as_data, str_AFN0D_F219*astr_val, int *ai_step)
{
	uchar  *p, lc_i;
	int li_step,li_res,lc_n,lc_m,lc_permin;
	p = as_data;

	li_res = getdataformat15(p, &astr_val->TD, &li_step);
	if (li_res == DATA_ISNULL)
		return ERROR_NULL_TD;
	*ai_step = li_step;
	p += li_step;
	if (dataisnull(p , 1))
		return ERROR_NULL_DENSITY;                  /*密度为空*/
	lc_m = *p;          /*取密度*/
	(*ai_step)++;
	p++;
	if (dataisnull(p, 1))
		return ERROR_NULL_POINT;                  /*点数为空*/
	lc_n = *p;          /*取点数*/
	switch(lc_m)
		{
		case 0:
			lc_permin = 0;
			break;
		case 1:
			lc_permin = 15;
			break;
		case 2:
			lc_permin = 30;
			break;
		case 3:
			lc_permin = 60;
		case 254:
			lc_permin = 5;
		case 255:
			lc_permin = 1;
			break;

		return ERROR_DATA_INVALID;
	};
	(*ai_step)++;
	p++;
	/*无功功率*/
	astr_val->idlesinull = getdataformat09(p, &(astr_val->idle), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*A,B,C 象限电流*/
	astr_val->Auisnull= getdataformat07(p, &(astr_val->AU), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->BUisnull= getdataformat07(p, &(astr_val->BU), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->CUisnull= getdataformat07(p, &(astr_val->CU), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*A,B,C 象限电流*/
	astr_val->AIisnull= getdataformat25(p, &(astr_val->AI), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->BIisnull= getdataformat25(p, &(astr_val->BI), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	astr_val->CIisnull= getdataformat25(p, &(astr_val->CI), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*正向有功总电能市值*/
	astr_val->valpowisnull = getdataformat11(p, &(astr_val->valpow), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*一象限无功总电能市值*/
	astr_val->yidlevalisnull= getdataformat11(p, &(astr_val->yidleval), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	/*四象限无功总电能市值*/
	astr_val->sidelvalisnull= getdataformat11(p, &(astr_val->sidleval), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	
	return ERROR_SUCCESS;	
}

