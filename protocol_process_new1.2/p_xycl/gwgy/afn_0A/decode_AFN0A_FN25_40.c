#include "decode_AFN0A_FN25_40.h"

/*********** 解析规约A类数据FN25 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F25
        PT              电压互感器倍率
        CT              电流互感器倍率
        limitU          额定电压
        maxI            最大电流
        limitUisnull    额定电压判空标志
        maxIisnull;     最大电流判空
        Connection;     接线方式
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F25(uchar *data, str_AFN0A_F25 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->PT = *(p + 1);
    astr_val->PT = astr_val->PT << 8;
    astr_val->PT = astr_val->PT + *p;
    (*ai_step) = 2;
    p = p + 2;
    astr_val->CT = *(p + 1);
    astr_val->CT = astr_val->CT << 8;
    astr_val->CT = astr_val->CT + *p;
    (*ai_step) += 2;
    p += 2;
    astr_val->limitUisnull = getdataformat07(p, &(astr_val->limitU), &li_step);
    (*ai_step) += li_step;
    p += li_step;
    astr_val->maxIisnull = getdataformat22(p, &(astr_val->maxI), &li_step);
    (*ai_step) += li_step;
    p += li_step;

    astr_val->limitFHisnull = getdataformat23(p, &(astr_val->limitFH), &li_step);
    (*ai_step) += li_step;
    p += li_step;

    astr_val->Connection = (*p & 0x0C)>> 2;
    astr_val->DYConnection = *p & 0x03;
    (*ai_step)++;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN26 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F26
        str_AFN0A_F26_VAL    数据结构
            limitU;          电压合格上限
            lowerU;          电压合格下限
            breakphaseU;     电压断相门限
            ceilinglimitU;   电压上上限（过压门限）
            lowerlimitU;     电压下下限（欠压门限）
            ceilinglimitI;   相电流上上限（过流门限）
            limitI;          相电流上限（额定电流门限）
            limitIzero;      零序电流上限
            ceilinglimitP;   视在功率上上限
            limitP;          视在功率上限
            unbalanceU;      三相电压不平衡限值
            unbalanceI;      三相电流不平衡限值
            loseUtme;        连续失压时间限值
        str_AFN0A_F26_ISNULL  判空结构
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F26(uchar *data, str_AFN0A_F26 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.limitU = getdataformat07(p, &(astr_val->val.limitU), &li_step);
    *ai_step = li_step;
    p = p + li_step;
    astr_val->isnull.lowerU = getdataformat07(p, &(astr_val->val.lowerU), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.breakphaseU = getdataformat07(p, &(astr_val->val.breakphaseU), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.ceilinglimitU = getdataformat07(p, &(astr_val->val.ceilinglimitU), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.ceilinglimitUtime = 0;
    astr_val->val.ceilinglimitUtime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.ceilinglimitUxs = getdataformat05(p, &(astr_val->val.ceilinglimitUxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.lowerlimitU = getdataformat07(p, &astr_val->val.lowerlimitU, &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.lowerlimitUtime = 0;
    astr_val->val.lowerlimitUtime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.lowerlimitUxs = getdataformat05(p, &(astr_val->val.lowerlimitUxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.ceilinglimitI = getdataformat25(p, &(astr_val->val.ceilinglimitI), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.ceilinglimitItime = 0;
    astr_val->val.ceilinglimitItime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.ceilinglimitIxs = getdataformat05(p, &(astr_val->val.ceilinglimitIxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.limitI = getdataformat25(p, &(astr_val->val.limitI), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.limitItime = 0;
    astr_val->val.limitItime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.limitIxs = getdataformat05(p, &(astr_val->val.limitIxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.limitIzero = getdataformat25(p, &(astr_val->val.limitIzero), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.limitIzerotime = 0;
    astr_val->val.limitIzerotime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.limitIzeroxs = getdataformat05(p, &(astr_val->val.limitIzeroxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.ceilinglimitP = getdataformat23(p, &(astr_val->val.ceilinglimitP), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.ceilinglimitPtime = 0;
    astr_val->val.ceilinglimitPtime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.ceilinglimitPxs = getdataformat05(p, &(astr_val->val.ceilinglimitPxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.limitP = getdataformat23(p, &(astr_val->val.limitP), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.limitPtime = 0;
    astr_val->val.limitPtime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.limitPxs = getdataformat05(p, &(astr_val->val.limitPxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.unbalanceU = getdataformat05(p, &(astr_val->val.unbalanceU), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.unbalanceUtime = 0;
    astr_val->val.unbalanceUtime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.unbalanceUxs = getdataformat05(p, &(astr_val->val.unbalanceUxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.unbalanceI = getdataformat05(p, &(astr_val->val.unbalanceI), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.unbalanceItime = 0;
    astr_val->val.unbalanceItime = *p;
    *ai_step = *ai_step + 1;
    p = p + 1;
    astr_val->isnull.unbalanceIxs = getdataformat05(p, &(astr_val->val.unbalanceIxs), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.loseUtme = 0;
    astr_val->val.loseUtme = *p;
    *ai_step = *ai_step + 1;
    p++;

    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN27 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F27
        double tctc[12];      铁损、铜损参数
        short  tctcisnull[12];    铁损、铜损参数判空
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F27(uchar *data, str_AFN0A_F27 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i, li_step;
    p = data;
    *ai_step = 0;

    for (li_i = 0; li_i < 12; li_i++)
    {
        astr_val->tctcisnull[li_i] = getdataformat26(p, &(astr_val->tctc[li_i]), &li_step);
        *ai_step = *ai_step + li_step;
        p = p + li_step;
    }

    return ERROR_SUCCESS;
}
/*********** 解析规约A类数据FN28 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F28
        limit1         功率因数分段限值1
        limit2         功率因数分段限值2
        limit1isnull   功率因数分段限值1判空标志
        limit2isnull;  功率因数分段限值2判空标志
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F28(uchar *data, str_AFN0A_F28 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->limit1isnull = getdataformat05(p, &(astr_val->limit1), &li_step);
    *ai_step = li_step;
    p = p + li_step;
    astr_val->limit2isnull = getdataformat05(p, &(astr_val->limit2), &li_step);
    *ai_step += li_step;
    p += li_step;
    return ERROR_SUCCESS;
}

int decode_afn0A_F29(uchar *data, str_AFN0A_F29 *astr_val, int *ai_step)
{
    uchar *p;
    p = data;

    memcpy(astr_val->xsh, data, 12);
    astr_val->xsh[12] = 0;

    *ai_step = 12;
    p += 12;

    return ERROR_SUCCESS;
}

int decode_afn0A_F31(uchar *data, str_AFN0A_F31 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step, li_i;
    p = data;

    astr_val->Number = *p;
    *ai_step = 1;
    p = p + 1;
    for (li_i = 0; li_i < astr_val->Number; li_i++)
    {
        astr_val->MeterAddisnull[li_i] = getdataformat12(p, &(astr_val->MeterAdd[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }

    return ERROR_SUCCESS;
}

int decode_afn0A_F33(uchar *data, str_AFN0A_F33 *astr_val, int *ai_step)
{
    int li_i, li_j, li_k, li_m,li_step;
    uchar *p;
    datetime ldt_now;           /*对电表广播校时定时时间*/
    p = data;

    astr_val->number = *p;
    *ai_step = 1;
    p++;
    tracelog("number = %d",astr_val->number);
    for (li_i = 0; li_i < astr_val->number; li_i++)
    {
        astr_val->val[li_i].port = *p;
        (*ai_step) += 1;
        p +=1;

        int ztz_i = 0;
        for(ztz_i;ztz_i<16;++ztz_i)
        {
            astr_val->val[li_i].ztz[ztz_i] = 0;//初始化
        }
        tracelog("p = %x,p+1 = %x",*p,*(p+1));
        astr_val->val[li_i].ztz[15] = ((*p) & 0x01);
        astr_val->val[li_i].ztz[14] = ((*p) & 0x02) >> 1;
        astr_val->val[li_i].ztz[13] = ((*p) & 0x04) >> 2;
        astr_val->val[li_i].ztz[12] = ((*p) & 0x08) >> 3;
        astr_val->val[li_i].ztz[11] = ((*p) & 0x10) >> 4;
        astr_val->val[li_i].ztz[10] = ((*p) & 0x20) >> 5;
        tracelog("ztz = %d %d %d %d %d %d",astr_val->val[li_i].ztz[15],astr_val->val[li_i].ztz[14],
                 astr_val->val[li_i].ztz[13],astr_val->val[li_i].ztz[12],astr_val->val[li_i].ztz[11],
                 astr_val->val[li_i].ztz[10]);
        (*ai_step) += 2;
        p +=2;

        for (li_j = 4; li_j > 0; li_j--)
        {
            for (li_k = 8; li_k > 0; li_k--)
            {
                astr_val->val[li_i].day[li_j * 8 - li_k] = ((*p) & (1 << (li_k - 1))) ? 1 : 0 ;
            }
            (*ai_step)++;
            p++;
        }

        astr_val->val[li_i].cbsjisnull = getdataformat19(p, &(astr_val->val[li_i].cbsj), &li_step);
        tracelog("cbsjisnull=%d",astr_val->val[li_i].cbsjisnull);
        *ai_step = *ai_step + li_step;
        p += li_step;

        astr_val->val[li_i].cbjg = *p;
        tracelog("cbjg=%d",astr_val->val[li_i].cbjg);
        (*ai_step) += 1;
        p +=1;

        f_get_datetime(&ldt_now);
        astr_val->val[li_i].jssjisnull = getdataformat18(p, &ldt_now, &(astr_val->val[li_i].jssj), &li_step);
        tracelog("jssjisnull=%d",astr_val->val[li_i].jssjisnull);
        *ai_step = *ai_step + li_step;
        p += li_step;

        astr_val->val[li_i].sdnumber = *p;
        (*ai_step) += 1;
        p +=1;

        tracelog("抄表时段为%d",astr_val->val[li_i].sdnumber);
        li_m = 0;
        for (li_j = 0; li_j < astr_val->val[li_i].sdnumber; li_j++)
        {
            astr_val->val[li_i].cbsdisnull[li_j+li_m] = getdataformat19(p, &(astr_val->val[li_i].cbsd[li_j+li_m]), &li_step);
            *ai_step = *ai_step + li_step;
            p += li_step;
            li_m++;

            astr_val->val[li_i].cbsdisnull[li_j+li_m] = getdataformat19(p, &(astr_val->val[li_i].cbsd[li_j+li_m]), &li_step);
            *ai_step = *ai_step + li_step;
            p += li_step;
            li_m++;
        }
    }
    tracelog("ai_step=%d",*ai_step);

    return ERROR_SUCCESS;
}

int decode_afn0A_F34(uchar *data, str_AFN0A_F34 *astr_val, int *ai_step)
{
    int li_i, li_j, li_k, li_step;
    uchar *p;
    p = data;

    astr_val->number = *p;
    *ai_step = 1;
    p++;

    for (li_i = 0; li_i < astr_val->number; li_i++)
    {
        astr_val->val[li_i].port = *p;
        (*ai_step) += 1;
        p +=1;

        astr_val->val[li_i].ztz[0] = (*p) & 0x01;
        astr_val->val[li_i].ztz[1] = ((*p) & 0x20) >>1;
        astr_val->val[li_i].ztz[2] = ((*p) & 0x40) >>2;
        astr_val->val[li_i].ztz[3] = ((*p) & 0x80) >>3;
        astr_val->val[li_i].ztz[4] = ((*p) & 0x10) >>4;
        astr_val->val[li_i].ztz[5] = ((*p) & 0x20) >>5;
        astr_val->val[li_i].ztz[6] = ((*p) & 0x40) >>6;
        astr_val->val[li_i].ztz[7] = ((*p) & 0x80) >>7;
        (*ai_step) += 1;
        p +=1;

        astr_val->val[li_i].txsl = *(p+3);
        astr_val->val[li_i].txsl << 8;
        astr_val->val[li_i].txsl = astr_val->val[li_i].txsl + *(p+2);
        astr_val->val[li_i].txsl << 8;
        astr_val->val[li_i].txsl = astr_val->val[li_i].txsl + *(p+1);
        astr_val->val[li_i].txsl << 8;
        astr_val->val[li_i].txsl = astr_val->val[li_i].txsl + *(p);
        (*ai_step) += 4;
        p +=4;

    }

    return ERROR_SUCCESS;
}


int decode_afn0A_F35(uchar *data, str_AFN0A_F35 *astr_val, int *ai_step)
{
    uchar *p;
    uchar lc_i;

    p =data;
    astr_val->zdhgs = *p;
    *ai_step = 1;
    p++;

    for (lc_i = 0; lc_i < astr_val->zdhgs; lc_i++)
    {
        astr_val->setxh[lc_i]=0;
        astr_val->setxh[lc_i] = *(p+1);
        astr_val->setxh[lc_i] = ((astr_val->setxh[lc_i])<<8) + *p;
        (*ai_step) += 2;
        p +=2;
    }

    return ERROR_SUCCESS;
}

int decode_afn0A_F36(uchar *data, uint *ai_val, int *ai_step)
{
    uchar *p;

    p =data;
    *ai_val = *(p+3);
    *ai_val << 8;
    *ai_val = *ai_val + *(p+2);
    *ai_val << 8;
    *ai_val = *ai_val + *(p+1);
    *ai_val << 8;
    *ai_val = *ai_val + *(p);
    (*ai_step) = 4;
    p +=4;

    return ERROR_SUCCESS;
}

int decode_afn0A_F37(uchar *data, str_AFN0A_F37 *astr_val, int *ai_step)
{
    int li_i, li_j, li_k, li_step;
    uchar *p;
    p = data;

    astr_val->port = *p;
    *ai_step = 1;
    p++;

    astr_val->kzz[0] = (*p) & 0x01;
    astr_val->kzz[1] = ((*p) & 0x20) >>1;
    astr_val->kzz[2] = ((*p) & 0x40) >>2;
    astr_val->kzz[3] = ((*p) & 0x80) >>3;
    astr_val->kzz[4] = ((*p) & 0x10) >>4;
    astr_val->kzz[5] = ((*p) & 0x20) >>5;
    astr_val->kzz[6] = ((*p) & 0x40) >>6;
    astr_val->kzz[7] = ((*p) & 0x80) >>7;
    (*ai_step) += 1;
    p +=1;

    astr_val->bwtimeout = *p;
    (*ai_step) += 1;
    p +=1;

    astr_val->jstimeout = *p;
    (*ai_step) += 1;
    p +=1;

    astr_val->recs = *p;
    (*ai_step) += 1;
    p +=1;

    astr_val->xczq = *p;
    (*ai_step) += 1;
    p +=1;

    astr_val->jldx = (*p & 0x80) >>7;
    (*ai_step) += 1;
    p +=1;

    astr_val->number = *p & 0x0f;
    (*ai_step) += 1;
    p +=1;

    for (li_i = 0; li_i < astr_val->number; li_i++)
    {
        astr_val->xzqhm[li_i] = BCDByteToByte(*p) + BCDByteToByte(*(p + 1)) * 100;
        (*ai_step) += 2;
        p +=2;
        astr_val->xzqhm[li_i] = *(p + 1);
        astr_val->xzqhm[li_i]  << 8;
        astr_val->xzqhm[li_i] = astr_val->xzqhm[li_i] + *(p);
        (*ai_step) += 2;
        p +=2;
    }

    return ERROR_SUCCESS;
}

int decode_afn0A_F38F39(uchar *data, str_AFN0A_F38F39 *astr_val, int *ai_step)
{
    int li_i, li_j, li_k, li_step;
    uchar *p;
    p = data;

    astr_val->dlh = *p;
    *ai_step = 1;
    p++;

    astr_val->zs = *p;
    (*ai_step) += 1;
    p +=1;

    for (li_i = 0; li_i < astr_val->zs; li_i++)
    {
        astr_val->val[li_i].xlh = *p;
        (*ai_step) += 1;
        p +=1;

        astr_val->val[li_i].xxlzs = *p;
        (*ai_step) += 1;
        p +=1;

        for (li_j = 0; li_j < astr_val->val[li_i].xxlzs; li_j++)
        {
            for (li_k = 0; li_k < 8; li_k++)
            {
                 astr_val->val[li_i].xxlbz[li_j*8 + li_k] = ((*p) >> li_k) & 0x01;
            }

            p++;
            (*ai_step) += 1;
        }
    }

    return ERROR_SUCCESS;
}

