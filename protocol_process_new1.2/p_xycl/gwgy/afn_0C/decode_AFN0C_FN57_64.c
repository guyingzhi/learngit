#include "decode_AFN0C_FN57_64.h"


int decode_afn0C_F57(uchar *as_data, str_AFN0C_F57F58 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    /*谐波次数*/
    astr_val->val.xbcnt = *p;
    if ((astr_val->val.xbcnt  < 2) || (astr_val->val.xbcnt > 19))
        return ERROR_NULL_XBCNT;
    (*ai_step) = 1;
    p++;
    /*Ua*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ua[lc_i - 1] = getdataformat07(p, &(astr_val->val.Ua[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ub*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ub[lc_i - 1] = getdataformat07(p, &(astr_val->val.Ub[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Uc*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Uc[lc_i - 1] = getdataformat07(p, &(astr_val->val.Uc[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ia*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ia[lc_i - 1] = getdataformat06(p, &(astr_val->val.Ia[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ib*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ib[lc_i - 1] = getdataformat06(p, &(astr_val->val.Ib[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ic*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ic[lc_i - 1] = getdataformat06(p, &(astr_val->val.Ic[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
    return ERROR_SUCCESS;
}

int decode_afn0C_F58(uchar *as_data, str_AFN0C_F57F58 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    /*谐波次数*/
    astr_val->val.xbcnt = *p;
    if ((astr_val->val.xbcnt  < 2) || (astr_val->val.xbcnt > 19))
        return ERROR_NULL_XBCNT;
    (*ai_step) = 1;
    p++;
    /*Ua*/
    astr_val->isnull.Ua[0] = getdataformat05(p, &(astr_val->val.Ua[0]), &li_step);
    *ai_step += li_step;
    p += li_step;
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ua[lc_i - 1] = getdataformat05(p, &(astr_val->val.Ua[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ub*/
    astr_val->isnull.Ub[0] = getdataformat05(p, &(astr_val->val.Ub[0]), &li_step);
    *ai_step += li_step;
    p += li_step;
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ub[lc_i - 1] = getdataformat05(p, &(astr_val->val.Ub[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Uc*/
    astr_val->isnull.Uc[0] = getdataformat05(p, &(astr_val->val.Uc[0]), &li_step);
    *ai_step += li_step;
    p += li_step;
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Uc[lc_i - 1] = getdataformat05(p, &(astr_val->val.Uc[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ia*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ia[lc_i - 1] = getdataformat05(p , &(astr_val->val.Ia[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ib*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ib[lc_i - 1] = getdataformat05(p, &(astr_val->val.Ib[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    /*Ic*/
    for (lc_i = 2; lc_i <= astr_val->val.xbcnt; lc_i++)
    {
        astr_val->isnull.Ic[lc_i - 1] = getdataformat05(p, &(astr_val->val.Ic[lc_i - 1]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    return ERROR_SUCCESS;
}
