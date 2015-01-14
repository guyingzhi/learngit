#include "decode_AFN10_FN1_13.h"


int decode_afn10_F01(uchar *data, str_AFN10_F01 *astr_val, int *ai_step)
{
	 int li_i;
    uchar *p;

    p = data;
    astr_val->dkh = *p;
	p++;
    astr_val->nrlen = *p;
    *ai_step = 1;
    p++;

    li_i=(int)(astr_val->nrlen);
    memcpy(astr_val->val, p, li_i);
    *ai_step += li_i;
    p += li_i;

    return ERROR_SUCCESS;	
}

int decode_afn10_F09(uchar *data, str_AFN10_F09 *astr_val, int *ai_step)
{
    int li_i,li_step,li_j;
    uchar *p;

    p = data;
    astr_val->dkh = *p;
    *ai_step = 1;
    p++;
    astr_val->TargetAddisNull = getdataformat12(p, &(astr_val->TargetAdd),& li_step);
    (*ai_step) += li_step;
    p+=li_step;
    astr_val->mark = *p;
    *ai_step ++;
    p++;
    astr_val->nrlen = *p;
    *ai_step ++;
    p++;
    for(li_j=0;li_j<4;li_j++)
    {
	 astr_val->datasymbol[li_j] = *(p+li_j);
	 *ai_step ++;
	 p++;
    }

    li_i=(int)(astr_val->nrlen)-4;
    memcpy(astr_val->val, p, li_i);
    *ai_step += li_i;
    p += li_i;

    return ERROR_SUCCESS;	
}

int decode_afn10_F10(uchar *data, str_AFN10_F10 *astr_val, int *ai_step)
{
	    int li_i,li_step;
    uchar *p;

    p = data;
    astr_val->dkh = *p;
    *ai_step = 1;
    p++;
    astr_val->TargetAddisNull = getdataformat12(p, &(astr_val->TargetAdd),& li_step);
   ( *ai_step) += li_step;
    p+=li_step;
	
    astr_val->mark = *p;
    *ai_step ++;
    p++;
    astr_val->tripmark = *p;
    *ai_step ++;
    p++;

    return ERROR_SUCCESS;	
}

int decode_afn10_F11(uchar *data, str_AFN10_F11 *astr_val, int *ai_step)
{
		    int li_i,li_step;
    uchar *p;

    p = data;
    astr_val->dkh = *p;
    *ai_step = 1;
    p++;
    astr_val->TargetAddisNull = getdataformat12(p, &(astr_val->TargetAdd),& li_step);
    (*ai_step) += li_step;
    p+=li_step;
	
    astr_val->mark = *p;
    *ai_step ++;
    p++;
    astr_val->sendingmark = *p;
    *ai_step ++;
    p++;

    return ERROR_SUCCESS;
}

int decode_afn10_F13(uchar *data, str_AFN10_F13 *astr_val, int *ai_step)
{
    int li_i,li_j;
    uchar *p;

    p = data;
    astr_val->taskmark = *p;
    *ai_step = 1;
    p++;
    astr_val->ter_number = *p + *(p+1)<<8;
    *ai_step +=2;
    p+=2;
    astr_val->succ_ter_number = *p + *(p+1)<<8;
    *ai_step +=2;
    p+=2;
	
   for(li_i=0;li_i<astr_val->succ_ter_number;li_i++)
   {
	for(li_j=0;li_j<8;li_j++)
	{
		astr_val->Table_no[li_i][li_j] = *p;
		ai_step ++;
		p++;
	}

   }

    return ERROR_SUCCESS;
}
