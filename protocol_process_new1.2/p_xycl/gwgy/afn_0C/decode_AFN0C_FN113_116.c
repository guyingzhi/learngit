#include "decode_AFN0C_FN113_116.h"


int decode_afn0C_F113_F116(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step)
{
	uchar  *p, lc_i, lc_m, lc_hour, lc_permin;
	int li_step;
	datetime ldt_dt;

	p = as_data;
	lc_hour = BCDByteToByte(getbytebybit(*p, 4, 2)) * 10
	+ BCDByteToByte(getbytebybit(*p, 0, 4));
	lc_m = getbytebybit(*p, 6, 2);
	switch(lc_m)
	{
		case 0:
			lc_permin = 0;
			astr_val->val_num = 0;
			break;
		case 1:
			lc_permin = 15;
			astr_val->val_num = 4;
			break;
		case 2:
			lc_permin = 30;
			astr_val->val_num = 2;
			break;
		case 3:
			lc_permin = 60;
			astr_val->val_num = 1;
			break;
		default :
		return ERROR_NULL_DENSITY;
	};

	(*ai_step) = 1;
	p++;
	f_get_datetime(&ldt_dt);
	if (ldt_dt.hour < lc_hour)
		after_day(&ldt_dt, &ldt_dt , -1);
		ldt_dt.min = 0;
		ldt_dt.sec = 0;
		ldt_dt.hour = lc_hour;
	for (lc_i = 0; lc_i < astr_val->val_num; lc_i++)
	{
		astr_val->isnull[lc_i] = getdataformat05(p, &(astr_val->val[lc_i]), &li_step);
		astr_val->val_time[lc_i] = ldt_dt;
		after_time(&ldt_dt, &ldt_dt, 60 * lc_permin);
		*ai_step += li_step;
		p += li_step;
	}

	return ERROR_SUCCESS;
}
