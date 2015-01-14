#include "decode_AFN0D_FN145_152.h"


/*********** 解析综合曲线F145数据 *************
	as_data	报文指针

    code_PZz    无功曲线
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
			-4	日期为空
			-5	密度为空
			-6  点数为空
			-7  不能识别的密度
*******************************************/
int decode_AFN0D_F145F148(uchar *as_data, str_AFN0C0D_QX *code_PZz, int *ai_step)
{
	int li_i, li_res;
	int li_step;
	datetime ldt_curve_dt,ldt_act_dt;
	uchar lc_m, lc_n, lc_permin;
	uchar *p;
	for (li_i = 0; li_i < 255; li_i++)
	{
		code_PZz->isnull[li_i] = DATA_ISNULL;
	}
	p = as_data;
	li_res = getdataformat15(p, &ldt_curve_dt, &li_step);
	ldt_act_dt = ldt_curve_dt;
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
	code_PZz->val_num = lc_n;

	for (li_i = 0; li_i < lc_n ; li_i++)
	{
		code_PZz->isnull[li_i] = getdataformat11(p, &(code_PZz->val[li_i]), &li_step);
		code_PZz->val_time[li_i] = ldt_act_dt;
		*ai_step += li_step;
		p += li_step;

		li_res = after_time(&ldt_curve_dt, &ldt_act_dt , lc_permin * 60 );/* 计算当前数据点对应的时间 */
		ldt_curve_dt = ldt_act_dt;
	}
	return ERROR_SUCCESS;

}


