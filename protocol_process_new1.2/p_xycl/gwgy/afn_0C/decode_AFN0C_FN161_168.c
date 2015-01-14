#include "decode_AFN0C_FN161_168.h"

int decode_afn0C_F161(uchar *as_data, str_AFN0C_F161 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step = 0;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->state = *p;
    p++;
    (*ai_step) += 1;

    astr_val->tddtisnull = getdataformat01(p, &(astr_val->tddt), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->dddtisnull = getdataformat01(p, &(astr_val->dddt), &li_step);
    p += li_step;
    *ai_step += li_step;

    return ERROR_SUCCESS;
}
int decode_afn0C_F162(uchar *as_data,str_AFN0C_F162 *astr_val,int *ai_step)
{
	uchar *p ,lc_i;
	int li_step = 0;

	p = as_data;
	astr_val->dateisnull= getdataformat01(p, &(astr_val->date), &li_step);

	p +=li_step;
	*ai_step +=li_step;

	astr_val->dateisnull = getdataformat01(p, &(astr_val->date1), &li_step);
	*ai_step +=li_step;
	return ERROR_SUCCESS;
}
int decode_afn0C_F165(uchar *as_data, str_AFN0C_F165F166 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->bcczcsisnull = getdataformat10(p, &(astr_val->bcczcs), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->bccztisnull = getdataformat01(p, &(astr_val->bcczdt), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->wgdkcsisnull = getdataformat10(p, &(astr_val->wgdkcs), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->wgdkdtisnull = getdataformat01(p, &(astr_val->wgdkdt), &li_step);
    p += li_step;
    *ai_step += li_step;

    return ERROR_SUCCESS;
}

int decode_afn0C_F166(uchar *as_data, str_AFN0C_F165F166 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->bcczcsisnull = getdataformat10(p, &(astr_val->bcczcs), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->bccztisnull = getdataformat01(p, &(astr_val->bcczdt), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->bccztisnull2 = getdataformat01(p, &(astr_val->bcczdt2), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->wgdkcsisnull = getdataformat10(p, &(astr_val->wgdkcs), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->wgdkdtisnull = getdataformat01(p, &(astr_val->wgdkdt), &li_step);
    p += li_step;
    *ai_step += li_step;

    return ERROR_SUCCESS;
}

int decode_afn0C_F167(uchar *as_data, str_AFN0C_F167 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->gdcsisnull = getdataformat08(p, &(astr_val->gdcs), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->gdjeisnull = getdataformat14(p, &(astr_val->gdje), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->ljgdjeisnull = getdataformat14(p, &(astr_val->ljgdje), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->sydlisnull = getdataformat11(p, &(astr_val->sydl), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->tzdlisnull = getdataformat11(p, &(astr_val->tzdl), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->ljgdlisnull = getdataformat11(p, &(astr_val->ljgdl), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->sqmxdlisnull = getdataformat11(p, &(astr_val->sqmxdl), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->bjdlisnull = getdataformat11(p, &(astr_val->bjdl), &li_step);
    p += li_step;
    *ai_step += li_step;

    astr_val->gzdlisnull = getdataformat11(p, &(astr_val->gzdl), &li_step);
    p += li_step;
    *ai_step += li_step;


    return ERROR_SUCCESS;
}

int decode_afn0C_F168(uchar *as_data, str_AFN0C_F168 *astr_val, int *ai_step)
{
    uchar  *p, lc_i;
    int li_step;

    p = as_data;
    astr_val->dateisnull = getdataformat15(p, &(astr_val->date), &li_step);
    p += li_step;
    *ai_step += li_step;

    /*费率数*/
//    astr_val->FLSisnull = getdataformat08(p, &(astr_val->FLS), &li_step);
//    p += li_step;
//    *ai_step += li_step;
    astr_val->FLS = *p;
    if ((astr_val->FLS < 1) || (astr_val->FLS >15))
        return ERROR_NULL_FLS;
    p++;
    (*ai_step) += 1;

    /*已结有功电能*/
    for (lc_i = 0; lc_i <= astr_val->FLS; lc_i++)
    {
        astr_val->yjvalisnull[lc_i] = getdataformat14(p, &(astr_val->yjval[lc_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
    }

     /*未结有功电能*/
    for (lc_i = 0; lc_i <= astr_val->FLS; lc_i++)
    {
        astr_val->wjvalisnull[lc_i] = getdataformat14(p, &(astr_val->wjval[lc_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
    }

    return ERROR_SUCCESS;
}

