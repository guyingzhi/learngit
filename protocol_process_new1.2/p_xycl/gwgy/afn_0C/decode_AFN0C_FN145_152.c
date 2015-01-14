#include "decode_AFN0C_FN145_152.h"

int decode_afn0C_G19(uchar *as_data, str_AFN0C_G19 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step = li_step;

    /*·ÑÂÊÊý*/
    astr_val->FLS = *p;
    if ((astr_val->FLS < 1) || (astr_val->FLS >15))
        return ERROR_NULL_FLS;
    p++;
    (*ai_step) += 1;

    astr_val->valisnull[0] = getdataformat23(p, &(astr_val->val[0]), &li_step);
    *ai_step += li_step;
    p += li_step;

    astr_val->dtisnull[0] = getdataformat17(p, &(astr_val->date), &astr_val->dt[0], &li_step);
    *ai_step += li_step;
    p += li_step;

    for (lc_i = 1; lc_i < (astr_val->FLS+1); lc_i++)
    {
        astr_val->valisnull[lc_i] = getdataformat23(p, &(astr_val->val[lc_i]), &li_step);
        *ai_step += li_step;
        p += li_step;

        astr_val->dtisnull[lc_i] = getdataformat17(p, &(astr_val->date), &(astr_val->dt[lc_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    return ERROR_SUCCESS;
}

