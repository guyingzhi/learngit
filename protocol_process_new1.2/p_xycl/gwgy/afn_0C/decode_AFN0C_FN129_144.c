#include "decode_AFN0C_FN129_144.h"

//F129F131F137F139F153F154F155F156F157F158F159F160
int decode_afn0C_NSZ14(uchar *as_data, str_AFN0C_LowVal *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step = li_step;

    /*费率数*/
    astr_val->FLS = *p;
    if ((astr_val->FLS < 1) || (astr_val->FLS >15))
        return ERROR_NULL_FLS;
    p++;
    (*ai_step) += 1;

    /*总有功总电能量*/
    astr_val->valisnull[0] = getdataformat14(p, &(astr_val->val[0]), &li_step);
    *ai_step += li_step;
    p += li_step;

    /*费率有功电能量*/
    for (lc_i = 1; lc_i <= astr_val->FLS; lc_i++)
    {
        astr_val->valisnull[lc_i] = getdataformat14(p, &(astr_val->val[lc_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
    }

    return ERROR_SUCCESS;
}

//F130F132F133F134F135F136F138F140F141F142F143F144
int decode_afn0C_NSZ11(uchar *as_data, str_AFN0C_LowVal *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step = li_step;

    /*费率数*/
    astr_val->FLS = *p;
    if ((astr_val->FLS < 1) || (astr_val->FLS >15))
        return ERROR_NULL_FLS;
    p++;
    (*ai_step) += 1;

    /*总有功总电能量*/
    astr_val->valisnull[0] = getdataformat11(p, &(astr_val->val[0]), &li_step);
    *ai_step += li_step;
    p += li_step;

    /*费率有功电能量*/
    for (lc_i = 1; lc_i <= astr_val->FLS; lc_i++)
    {
        astr_val->valisnull[lc_i] = getdataformat11(p, &(astr_val->val[lc_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
    }

    return ERROR_SUCCESS;
}


int decode_afn0C_F139(uchar *as_data, str_AFN0C_F139 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;
    p = as_data;

    astr_val->dateisnull = getdataformat24(p, &(astr_val->date), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->meterindex = *(p + 1) << 8 + (*p & 0xFF);
    *ai_step +=2;
    p += 2;
    astr_val->flag = *p;
    (*ai_step)++;
    p++;

    if (astr_val->flag & 1)
    {
        astr_val->valisnull = getlowdataformatSYDL(p, &astr_val->val, &li_step);
        *ai_step += li_step;
        p +=li_step;
    }
    else
    astr_val->valisnull = DATA_ISNULL;


    if (astr_val->flag & 2)
    {
        astr_val->cdsjisnull= getdataformat01(p, &(astr_val->cdsj), &li_step);
        p += li_step;
        *ai_step += li_step;
    }
    else
    astr_val->cdsjisnull = DATA_ISNULL;

    return ERROR_SUCCESS;
}

int decode_afn0C_SYDL(uchar *as_data, str_AFN0C_SYDL *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;
    p = as_data;

    astr_val->dateisnull = getdataformatYMD(p, &(astr_val->date), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->count = *p;
    p++;
    (*ai_step)++;
    for (lc_i = 0; lc_i < astr_val->count; lc_i++)
    {
        /*电表序号*/
        astr_val->meterindex[lc_i] = (*(p + 1) << 8) + (*p & 0xFF);
        *ai_step +=2;
        p += 2;
        /*数据项标志*/
        astr_val->flag[lc_i] = *p;
        (*ai_step)++;
        p++;
        /*剩余电量*/
        if (astr_val->flag[lc_i] & 1)
        {
            astr_val->valisnull[lc_i] = getlowdataformatSYDL(p, &(astr_val->val[lc_i]), &li_step);
            p += li_step;
            *ai_step += li_step;
        }
        else
        astr_val->valisnull[lc_i] = DATA_ISNULL;
        /*抄到时间*/
        if (astr_val->flag[lc_i] & 2)
        {
            astr_val->cdsjisnull[lc_i] = getdataformat01(p, &(astr_val->cdsj[lc_i]), &li_step);
            p += li_step;
            *ai_step += li_step;
        }
        else
        astr_val->cdsjisnull[lc_i] = DATA_ISNULL;

    }
    return ERROR_SUCCESS;
}

int decode_afn0C_VIP_SYDL(uchar *as_data, str_AFN0C_VIP_SYDL *astr_val, int *ai_step)
{
    uchar  *p, lc_i, lc_j;
    int li_step;
    p = as_data;

    astr_val->dateisnull = getdataformatYMD(p, &(astr_val->date), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->count = *p;
    p++;
    (*ai_step)++;
    for (lc_i = 0; lc_i < astr_val->count; lc_i++)
    {
        /*电表序号*/
        astr_val->meterindex[lc_i] = *(p + 1) << 8 + (*p & 0xFF);
        *ai_step +=2;
        p += 2;
        /*数据项标志*/
        astr_val->flag[lc_i] = *p;
        (*ai_step)++;
        p++;
        /*24点剩余电量*/
        if (astr_val->flag[lc_i] & 1)
        {
            for (lc_j = 0; lc_j < 24; lc_j++)
            {
                astr_val->data[lc_i].valisnull[lc_j] = getlowdataformatSYDL(p, &(astr_val->data[lc_i].val[lc_j]), &li_step);
                p += li_step;
                *ai_step += li_step;
            }
        }
        else
        {
            for (lc_j = 0; lc_j < 24; lc_j++)
            astr_val->data[lc_i].valisnull[lc_j] = DATA_ISNULL;
        }
    }
    return ERROR_SUCCESS;
}
