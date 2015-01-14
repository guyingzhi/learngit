#include "decode_AFN0C_FN73_80.h"


int decode_afn0C_F73(uchar *as_data, str_AFN0C_FN73 *astr_val, int *ai_step)
{
	uchar  *p;
	p = as_data;
	astr_val->valisnull = getdataformat02(p, &(astr_val->val), ai_step);
	return ERROR_SUCCESS;
}
