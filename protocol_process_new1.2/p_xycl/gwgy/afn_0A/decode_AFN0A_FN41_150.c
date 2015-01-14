#include "decode_AFN0A_FN41_150.h"
/*********** ������ԼA������F41 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F41
        str_AFN0A_PROGRAM  ��������
            periodnumber        ʱ����Ч��־
            valuation           ��Ӧʱ�ζ�ֵ
            isnull              ��Ӧʱ�ζ�ֵ�пձ�־
        programstate       ������Ч��־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F41(uchar *data, str_AFN0A_F41 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i, li_step, li_j;
    p = data;
    for (li_i = 0; li_i < 3; li_i++)
    {
        if ((*p & (1 << li_i)) == 0)
        {
            astr_val->programstate[li_i] = 0;
        }
        else
        {
            astr_val->programstate[li_i] = 1;
        }
    }
    *ai_step = 1;
    p++;
    for (li_i = 0; li_i < 3; li_i++)
    {
        if (astr_val->programstate[li_i])
        {
            for (li_j = 0; li_j < 8; li_j++)
            {
                astr_val->program[li_i].periodnumber[li_j] = (*p & (1 << li_j)) ? 1 : 0;
            }
            *ai_step = *ai_step + 1;
            p++;
            for (li_j = 0; li_j < 8; li_j++)
            {
                if (astr_val->program[li_i].periodnumber[li_j])
                {
                    astr_val->program[li_i].isnull[li_j] = getdataformat02(p, &(astr_val->program[li_i].valuation[li_j]), &li_step);
                    *ai_step = *ai_step + li_step;
                    p = p + li_step;
                }
            }
        }
        else
        {
            astr_val->program[li_i].isnull[li_j] = DATA_ISNULL;
        }
    }
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F42 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F42
        facval             ���ݶ�ֵ
        facvalisnull       ���ݶ�ֵ�пձ�־
        starttime         �޵���ʼʱ��
        starttimeisnull   �޵���ʼʱ���пձ�־
        duration           ����ʱ��
        weekday            ���޵���
    ����
        1          ��������
*******************************************/
int decode_afn0A_F42(uchar *data, str_AFN0A_F42 *astr_val, int *ai_step)
{
    uchar *p;
    int  li_step, li_i;
    p = data;
    astr_val->facvalisnull = getdataformat02(p, &(astr_val->facval), &li_step);
    *ai_step = li_step;
    p = p + li_step;
    astr_val->starttimeisnull = getdataformat19(p, &(astr_val->starttime), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->duration = *p;
    *ai_step = *ai_step + 1;
    p++;
    for (li_i = 1; li_i<8; li_i++)
    {
        astr_val->weekday[li_i - 1] = (*p & (1 << li_i)) ? 1 : 0;
    }
    *ai_step = *ai_step + 1;
    p++;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F43 *************
    data   ����ָ��

    ai_step  ���ĳ���
    lc_val   ���ʼ��㻬��ʱ��
    ����
        1          ��������
*******************************************/
int decode_afn0A_F43(uchar *data, uchar *ac_val, int *ai_step)
{
    *ac_val = *data;
    *ai_step = 1;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F44 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F44
        str_AFN0A_F44_VAL
            starttime   ��ͣ��ʼʱ��
            stoptime    ��ͣ����ʱ��
            Pval        ��ͣ���ʶ�ֵ
        str_AFN0A_F44_ISNULL
            starttime   ��ͣ��ʼʱ���пձ�־
            stoptime    ��ͣ����ʱ���пձ�־
            Pval        ��ͣ���ʶ�ֵ�пձ�־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F44(uchar *data, str_AFN0A_F44 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.starttime = getdataformat20(p , &(astr_val->val.starttime), &li_step);
    *ai_step = li_step;
    p = p + li_step;
    astr_val->isnull.stoptime = getdataformat20(p , &(astr_val->val.stoptime), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    astr_val->isnull.Pval = getdataformat02(p , &(astr_val->val.Pval), &li_step);
    *ai_step = *ai_step + li_step;
    p = p + li_step;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F45 F48 *************
    data   ����ָ��

    ai_step  ���ĳ���
    round    �ִα�־ 1Ϊ�ܿأ�0Ϊ���ܿ�
    ����
        1          ��������
*******************************************/
int decode_afn0A_GETROUND(uchar *data, str_AFN0A_ROUND *astr_val, int *ai_step)
{
    int li_i;
    for (li_i = 0; li_i < 8; li_i++)
        astr_val->round[li_i] = (*data & (1 << li_i)) ? 1 : 0;
    *ai_step = 1;
    return ERROR_SUCCESS;
}

int decode_afn0A_F46(uchar *data, str_AFN0A_F46 *astr_val, uchar *ac_unit, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    if ((astr_val->valisnull = getdataformat03(p, &(astr_val->val), ac_unit, &li_step)) == 0)
    *ai_step = li_step;
    return ERROR_SUCCESS;
}

int decode_afn0A_F47(uchar *data, str_AFN0A_F47 *astr_val, int *ai_step)
{
    uchar *p, lc_unit;
    int li_step;
    p = data;
    astr_val->GDDno = *(p + 3);
    astr_val->GDDno = (astr_val->GDDno << 8) + *(p + 2);
    astr_val->GDDno = (astr_val->GDDno << 8) + *(p + 1);
    astr_val->GDDno = (astr_val->GDDno << 8) + *p ;
    *ai_step = 4;
    p += 4;
    if (*p == 0x55)
    {
        astr_val->GDtype = 1;
    }
    else
    {
        if (*p == 0xaa)
        {
            astr_val->GDtype = 2;
        }
        else
        {
            astr_val->GDtype = 2;
        }
    }
    (*ai_step)++;
    p++;
    if ((astr_val->GDvalisnull = getdataformat03(p, &(astr_val->GDval), &lc_unit, &li_step)) == 0)
        if (lc_unit)
            astr_val->GDval = astr_val->GDval * 1000;
    *ai_step += li_step;
    p += li_step;
    if ((astr_val->alarmlimitisnull = getdataformat03(p, &(astr_val->alarmlimit), &lc_unit, &li_step)) == 0)
        if (lc_unit)
            astr_val->alarmlimit = astr_val->alarmlimit * 1000;
    *ai_step += li_step;
    p += li_step;
    if ((astr_val->triplimitisnull = getdataformat03(p, &(astr_val->triplimit), &lc_unit, &li_step)) == 0)
        if (lc_unit)
            astr_val->triplimit = astr_val->triplimit * 1000;
    *ai_step += li_step;
    p += li_step;

    return ERROR_SUCCESS;
}

/*********** ������ԼA������F49 *************
    data   ����ָ��

    ai_step  ���ĳ���
    lc_val   ���ظ澯ʱ��
    ����
        1          ��������
*******************************************/
int decode_afn0A_F49(uchar *data, uchar *ac_val, int *ai_step)
{
    *ac_val = *data;
    *ai_step = 1;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F57 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F57
        alarmsound  �����澯��־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F57(uchar *data, str_AFN0A_F57 *astr_val, int *ai_step)
{
    uchar *p;
    uchar lc_i, lc_j;
    p = data;
    *ai_step = 0;
    for (lc_i = 0; lc_i < 3; lc_i++)
    {
        for (lc_j = 0; lc_j < 8; lc_j++)
        {
            astr_val->alarmsound[lc_i * 8 + lc_j] = (*(p + lc_i) & (1 << lc_j)) ? 1 : 0;
        }
        (*ai_step)++;
    }
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F57 *************
    data   ����ָ��

    ai_step  ���ĳ���
    lc_val   ��������վ������ͨ��ʱ��
    ����
        1          ��������
*******************************************/
int decode_afn0A_F58(uchar *data, uchar *lc_val, int *ai_step)
{
    *lc_val = *data;
    *ai_step = 1;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F59 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F59
        difflimit        ������ֵ
        difflimitisnull  ������ֵ�пձ�־
        flewlimit        ������ֵ
        flewlimitisnull  ������ֵ�пձ�־
        stoplimit        ͣ����ֵ
        correctionlimit  Уʱ��ֵ
    ����
        1          ��������
*******************************************/
int decode_afn0A_F59(uchar *data, str_AFN0A_F59 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->difflimitisnull = getdataformat22(p, &(astr_val->difflimit), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->flewlimitisnull = getdataformat22(p, &(astr_val->flewlimit), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->stoplimit = *p;
    *ai_step += 1;
    p++;
    //Уʱ��ֵ
    astr_val->correctionlimit = *(p + 1);
    astr_val->correctionlimit = astr_val->correctionlimit << 8;
    astr_val->correctionlimit = astr_val->correctionlimit + *p;
    *ai_step += 2;
    p += 2;

    return ERROR_SUCCESS;
}

/*********** ������ԼA������F60 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F60
        str_AFN0A_F60_VAL
            harmonicUZ      �ܵ�ѹ����������
            harmonicUodd    ��ε�ѹ����������
            harmonicUeven   ż�ε�ѹ����������
            harmonicI       ������Чֵ����
        str_AFN0A_F60_ISNULL
            harmonicUZ       �ܵ�ѹ�����������пձ�־
            harmonicUodd     ��ε�ѹ�����������пձ�־
            harmonicUeven    ż�ε�ѹ�����������пձ�־
            harmonicI        ������Чֵ�����пձ�־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F60(uchar *data, str_AFN0A_F60 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step, li_i;
    p = data;
    astr_val->isnull.harmonicUZ = getdataformat05(p, &(astr_val->val.harmonicUZ), &li_step);
    p += li_step;
    *ai_step = li_step;
    astr_val->isnull.harmonicUodd = getdataformat05(p, &(astr_val->val.harmonicUodd), &li_step);
    p += li_step;
    *ai_step += li_step;
    astr_val->isnull.harmonicUeven = getdataformat05(p, &(astr_val->val.harmonicUeven), &li_step);
    p += li_step;
    *ai_step += li_step;
    for (li_i = 0; li_i < 18; )
    {
        astr_val->isnull.harmonicU[li_i] = getdataformat05(p, &(astr_val->val.harmonicU[li_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
        li_i +=2;
    }

    for (li_i = 1; li_i < 18; )
    {
        astr_val->isnull.harmonicU[li_i] = getdataformat05(p, &(astr_val->val.harmonicU[li_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
        li_i +=2;
    }

    astr_val->isnull.harmonicIZ = getdataformat06(p, &(astr_val->val.harmonicIZ), &li_step);
    p += li_step;
    *ai_step += li_step;

    for (li_i = 0; li_i < 18; )
    {
        astr_val->isnull.harmonicI[li_i] = getdataformat06(p, &(astr_val->val.harmonicI[li_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
        li_i +=2;
    }
    for (li_i = 1; li_i < 18; )
    {
        astr_val->isnull.harmonicI[li_i] = getdataformat06(p, &(astr_val->val.harmonicI[li_i]), &li_step);
        p += li_step;
        *ai_step += li_step;
        li_i +=2;
    }

    return ERROR_SUCCESS;
}


/*********** ������ԼA������F61 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F61
        analogflag      ģ���������־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F61(uchar *data, str_AFN0A_F61 *astr_val, int *ai_step)
{
    int li_i;
    for (li_i = 0; li_i < 8; li_i++)
    {
        astr_val->analogflag[li_i] = (*data & (1 << li_i)) ? 1 : 0;
    }
    *ai_step = 1;
    return ERROR_SUCCESS;
}


int decode_afn0A_F65F66(uchar *data, str_AFN0A_F65F66 *astr_val,uchar ai_AFN, int *ai_step)
{
    uchar *p;
    int li_step, li_i;
    str_pn act_PN;
    str_fn act_FN;
//    str_LowPN actLow_PN;
    p = data;
    astr_val->cycleunit = (*p & 0xc0) >> 6;
    astr_val->cycle = *p & 0x3f;
    *ai_step = 1;
    p++;
    astr_val->marktimeisnull = getdataformat01(p, &(astr_val->marktime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->Rval = *p;
    (*ai_step)++;
    p++;
    astr_val->Nval = *p;
    (*ai_step)++;
    p++;
    for (li_i = 0; li_i < astr_val->Nval; li_i++)
    {
        act_FN = get_FN(*(p + 2), *(p + 3));
        astr_val->FN[li_i] = act_FN.fn[0];

 //       actLow_PN = get_LowPN(*p, *(p + 1));
        astr_val->PN[li_i] = act_PN.pn[0];
        tracelog("actLow_PN.PN[0]=%x",act_PN.pn[0]);

        *ai_step += 4;
        p += 4;;
    }
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F67 F68*************
    data   ����ָ��

    ai_step  ���ĳ���
    ac_val   �����ϱ�״̬��1Ϊ������0Ϊֹͣ��2Ϊ��Ч״̬
    ����
        1          ��������
*******************************************/
int decode_afn0A_F67F68(uchar *data, uchar *ac_val, int *ai_step)
{
    if (*data == 0x55)
    {
        *ac_val = 1;        /*����*/
    }
    else
    {
        if (*data == 0xaa)
        {
            *ac_val = 0;    /*ֹͣ*/
        }
        else
        {
            *ac_val = 2;    /*��Ч*/
        }
    }
    *ai_step = 1;
    return ERROR_SUCCESS;
}


/*********** ������ԼA������F73 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F73
        analogflag      ģ���������־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F73(uchar *data, str_AFN0A_F73 *astr_val, int *ai_step)
{   
    uchar *p;
    int li_step, li_i;
    p = data;
    for(li_i=0;li_i<16;li_i++)
    {   
           astr_val->BCFS[li_i][0] =  (*p&0xc0)>>6;
           astr_val->BCFS[li_i][1] =  (*p&0x04)>>2;
           astr_val->BCFS[li_i][2] =  (*p&0x02)>>1;
           astr_val->BCFS[li_i][3] =  (*p&0x01);

           astr_val->DRRLisnull[li_i] = getdataformat02(p, &(astr_val->DRRL[li_i]), &li_step);

           *ai_step +=3;
           p+=3;       
    }
    return ERROR_SUCCESS;
}

/*********** ������ԼA������F74 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F74
        analogflag      ģ���������־
    ����
        1          ��������
*******************************************/
int decode_afn0A_F74(uchar *data, str_AFN0A_F74 *astr_val, int *ai_step)
{   
    uchar *p;
    int li_step;
    p = data;
    astr_val->MBGVYSisnull = getdataformat05(p, &(astr_val->MBGVYS), &li_step);
    *ai_step += li_step;
    p+=li_step;
    astr_val->TRWGGVisnull= getdataformat05(p, &(astr_val->TRWGGV), &li_step);
    *ai_step += li_step;
    p+=li_step;
    astr_val->QCWGGVisnull= getdataformat05(p, &(astr_val->QCWGGV), &li_step);
    *ai_step += li_step;
    p+=li_step;
    astr_val->YSSJ = *p;
    *ai_step += 1;
    p+=1;
    astr_val->SJJG = *p;
    *ai_step += 1;
    
    return ERROR_SUCCESS;
}

int decode_afn0A_F75(uchar *data, str_AFN0A_75 *astr_val, int *ai_step)
{   
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->isnull.GDY = getdataformat07(p ,&(astr_val->val.GDY), & li_step);
    *ai_step += li_step;
    p+= li_step;
    astr_val->isnull.GDYHCZ= getdataformat07(p ,&(astr_val->val.GDYHCZ), & li_step);
    *ai_step += li_step;
    p+= li_step;
    astr_val->isnull.QDY= getdataformat07(p ,&(astr_val->val.QDY), & li_step);
    *ai_step += li_step;
    p+= li_step;
    astr_val->isnull.QDYHCZ= getdataformat07(p ,&(astr_val->val.QDYHCZ), & li_step);
    *ai_step += li_step;
    p+= li_step;  
    astr_val->isnull.DLHYL= getdataformat05(p ,&(astr_val->val.DLHYL), & li_step);
    *ai_step += li_step;
    p+= li_step; 
    astr_val->isnull.DLHYLHC= getdataformat05(p ,&(astr_val->val.DLHYLHC), & li_step);
    *ai_step += li_step;
    p+= li_step;  
    astr_val->isnull.DYHYL= getdataformat05(p ,&(astr_val->val.DYHYL), & li_step);
    *ai_step += li_step;
    p+= li_step;  
    astr_val->isnull.DYHYLHC= getdataformat05(p ,&(astr_val->val.DYHYLHC), & li_step);
    *ai_step += li_step;
    
    return ERROR_SUCCESS;
}

int decode_afn0A_F81(uchar *data, str_AFN0A_81 *astr_val, int *ai_step)
{   
    uchar *p;
    int li_step,li_i,li_j;
    p = data;
    astr_val->isnull.ZLQSZ = getdataformat02(p, &(astr_val->val.ZLQSZ), &li_step);
    *ai_step += li_step;
    p+=li_step;
     astr_val->isnull.ZLZSZ = getdataformat02(p, &(astr_val->val.ZLZSZ), &li_step);
    *ai_step += li_step;
    p+=li_step;
    return ERROR_SUCCESS;
}
int decode_afn0A_F82(uchar *data, str_AFN0A_82 *astr_val, int *ai_step)
{   
    uchar *p;
    int li_step,li_i,li_j;
    p = data;
    astr_val->isnull.ZLS= getdataformat02(p, &(astr_val->val.ZLS), &li_step);
    *ai_step += li_step;
    p+=li_step;
     astr_val->isnull.ZLX = getdataformat02(p, &(astr_val->val.ZLX), &li_step);
    *ai_step += li_step;
    p+=li_step;
    return ERROR_SUCCESS;
}


int decode_afn0A_F150(uchar *data, str_AFN0A_150 *astr_val, int *ai_step)
{   
    uchar *p;
    int li_step,li_i,li_j;
    p = data;
    for(li_i = 0;li_i <255;li_i++)
    {
        for(li_j = 0;li_j<8;li_j++)
        {
            astr_val->Pn_mark[li_i][li_j] = getbytebybit(*(p+li_i),li_j, 1);
            astr_val->Pn_change_mark[li_i][li_j] = getbytebybit(*(p+256+li_i),li_j, 1);
        }
    }
    *ai_step = 512;
    return ERROR_SUCCESS;
}
