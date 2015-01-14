#include "decode_AFN0A_FN1_10.h"

/*********** ������ԼA������FN1 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F1
        RTS        RTS��ʱ
        PDelay     ����վ��������ʱ
        CTimeout;  �Ӷ�վ��Ӧ��ʱʱ��
        RTimes;    �ط�����
        con1;      ��Ҫ�¼�ȷ�ϱ�־
        con2;      һ���¼�ȷ�ϱ�־
        HCycle;    ��������
    ����
        1          ��������
*******************************************/
int decode_afn0A_F1(uchar *data, str_AFN0A_F1 *astr_val, int *ai_step)
{
    uchar   *p;
    uchar   lc_c;
    p = data;
    if ((astr_val->isnull.RTS  = dataisnull(p , 1)) == DATA_ISNOTNULL)
        astr_val->val.RTS = *p;
    *ai_step = 1;
    p++;
    if ((astr_val->isnull.PDelay = dataisnull(p, 1)) == DATA_ISNOTNULL)
        astr_val->val.PDelay = *p;
    (*ai_step)++;
    p++;
    if (dataisnull(p, 2) == DATA_ISNULL)
    {
        astr_val->isnull.HCycle = DATA_ISNULL;
        astr_val->isnull.CTimeout = DATA_ISNULL;
        astr_val->isnull.RTimes = DATA_ISNULL;
    }
    else
    {
        astr_val->isnull.HCycle = DATA_ISNOTNULL;
        astr_val->isnull.CTimeout = DATA_ISNOTNULL;
        astr_val->isnull.RTimes = DATA_ISNOTNULL;
        astr_val->val.CTimeout = (*(p + 1)) & 0x0F;
        astr_val->val.CTimeout <<= 8;
        astr_val->val.CTimeout += *p ;
        astr_val->val.RTimes = (*(p + 1)) & 0x30;
        astr_val->val.RTimes >>= 4;
    }
    *ai_step += 2;
    p += 2;
    lc_c = *p;
    if (dataisnull(p , 1) == DATA_ISNULL)
    {
        astr_val->isnull.con1 = DATA_ISNULL;
        astr_val->isnull.con2 = DATA_ISNULL;
        astr_val->isnull.con3 = DATA_ISNULL;
    }
    else
    {
        astr_val->isnull.con1 = DATA_ISNOTNULL;
        astr_val->isnull.con2 = DATA_ISNOTNULL;
        astr_val->isnull.con3 = DATA_ISNOTNULL;
        astr_val->val.con1 = (lc_c & 0x01) ? 1 : 0;
        astr_val->val.con2 = (lc_c & 0x02) ? 1 : 0;
        astr_val->val.con3 = (lc_c & 0x04) ? 1 : 0;
    }
    (*ai_step)++;
    p++;
    if ((astr_val->isnull.HCycle = dataisnull(p, 1)) == DATA_ISNOTNULL)
        astr_val->val.HCycle = *p;
    (*ai_step)++;
    p++;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN2 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F2
        ForwardNumber        ��ת�����ն���
        ForwardAddress  ��ת�����ն˵�ַ����
    ����
            1  ��������
            -5 ���������
*******************************************/
int decode_afn0A_F2(uchar *data, str_AFN0A_F2 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i;
    p = data;
    astr_val->ForwardNumber = *p & 0x7f;
    if (astr_val->ForwardNumber > 16)
      return ERROR_DATA_INVALID;
    astr_val->Forward = (*p & 0x80) ? 1 : 0;
    *ai_step = 1;
    p++;
    for (li_i = 0;li_i < astr_val->ForwardNumber; li_i++)
    {
        astr_val->ForwardAddress[li_i] = *(p + 1);
        astr_val->ForwardAddress[li_i] = (astr_val->ForwardAddress[li_i] << 8) + *p;
        *ai_step += 2;
        p += 2;
    }
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN3 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F3
        MainIP        ����IP
        MainSOCKET    ���ö˿�
        STBYIP        ����IP
        STBYSOCKET    ���ö˿�
        AgentIP       ����IP
        AgentSOCKET   ����˿�
        APN           APN
    ����
            1  ��������
*******************************************/
int decode_afn0A_F3(uchar *data, str_AFN0A_F3 *astr_val, int *ai_step)
{
    uchar *p;
    uchar lc_n, li_i;
    p = data;
    for (li_i = 0; li_i < 15; li_i++)
        astr_val->MainIP[li_i] = ' ';
    lc_n = *p;
    sprintf(&(astr_val->MainIP[0]), "%.3d", lc_n);
    lc_n = *(p + 1);
    astr_val->MainIP[3] = '.';
    sprintf(&(astr_val->MainIP[4]), "%.3d", lc_n);
    lc_n = *(p + 2);
    astr_val->MainIP[7] = '.';
    sprintf(&(astr_val->MainIP[8]), "%.3d", lc_n);
    lc_n = *(p + 3);
    astr_val->MainIP[11] = '.';
    sprintf(&(astr_val->MainIP[12]), "%.3d", lc_n);
    for (li_i = 0; li_i < 15; li_i++)
        if (astr_val->MainIP[li_i] == 0)
            astr_val->MainIP[li_i] = ' ';
    astr_val->MainIP[15] = 0;
    astr_val->MainSOCKET = *(p + 5);
    astr_val->MainSOCKET = astr_val->MainSOCKET << 8;
    astr_val->MainSOCKET = astr_val->MainSOCKET + *(p + 4);
    *ai_step = 6;
    p +=6;

    for (li_i = 0; li_i < 15; li_i++)
        astr_val->STBYIP[li_i] = ' ';
    lc_n = *p;
    sprintf(&(astr_val->STBYIP[0]), "%.3d", lc_n);
    lc_n = *(p + 1);
    astr_val->STBYIP[3] = '.';
    sprintf(&(astr_val->STBYIP[4]), "%.3d", lc_n);
    lc_n = *(p + 2);
    astr_val->STBYIP[7] = '.';
    sprintf(&(astr_val->STBYIP[8]), "%.3d", lc_n);
    lc_n = *(p + 3);
    astr_val->STBYIP[11] = '.';
    sprintf(&(astr_val->STBYIP[12]), "%.3d", lc_n);
    for (li_i = 0; li_i < 15; li_i++)
        if (astr_val->STBYIP[li_i] == 0)
            astr_val->STBYIP[li_i] = ' ';
    astr_val->STBYIP[15] = 0;
    astr_val->STBYSOCKET = *(p + 5);
    astr_val->STBYSOCKET = astr_val->STBYSOCKET << 8;
    astr_val->STBYSOCKET = astr_val->STBYSOCKET + *(p + 4);
    *ai_step += 6;
    p +=6;

    for (li_i = 0; li_i < 16; li_i++)
        astr_val->APN[li_i] = *(p + li_i);
    astr_val->APN[16] = 0;
    *ai_step += 16;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN4 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F4
        MSAPhone      ��վ�绰����
        SMSPhone      �������ĺ���
    ����
            1  ��������
*******************************************/
int decode_afn0A_F4(uchar *data, str_AFN0A_F4 *astr_val, int *ai_step)
{
    uchar *p;
    uchar lc_n;
    int li_i;
    p = data;
    for (li_i = 0; li_i < 16; li_i++)
        astr_val->MSAPhone[li_i] = ' ';
    astr_val->MSAPhone[16] = 0;
    for (li_i = 0; li_i < 8; li_i++)
    {
        lc_n = *(p + li_i) & 0x0f;
        switch (lc_n)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                astr_val->MSAPhone[li_i * 2 + 1] = lc_n + '0';
                break;
            case 10:
                astr_val->MSAPhone[li_i * 2 + 1] = ',';
                break;
            case 11:
                astr_val->MSAPhone[li_i * 2 + 1] = '#';
                break;
            astr_val->MSAPhone[li_i * 2 + 1] = ' ';
        }
        lc_n = (*(p + li_i) & 0xf0) >> 4;
        switch (lc_n)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                astr_val->MSAPhone[li_i * 2] = lc_n + '0';
                break;
            case 10:
                astr_val->MSAPhone[li_i * 2] = ',';
                break;
            case 11:
                astr_val->MSAPhone[li_i * 2] = '#';
                break;
            astr_val->MSAPhone[li_i * 2] = ' ';
        }
    }
    for (li_i = 0; li_i < 16; li_i++)
        astr_val->SMSPhone[li_i] = ' ';
    astr_val->SMSPhone[16] = 0;
    for (li_i = 0; li_i < 8; li_i++)
    {
        lc_n = *(p + 8 + li_i) & 0x0f;
        switch (lc_n)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                astr_val->SMSPhone[li_i * 2 + 1] = lc_n + '0';
                break;
            case 10:
                astr_val->SMSPhone[li_i * 2 + 1] = ',';
                break;
            case 11:
                astr_val->SMSPhone[li_i * 2 + 1] = '#';
                break;
            astr_val->SMSPhone[li_i * 2 + 1] = ' ';
        }
        lc_n = (*(p + 8 + li_i) & 0xf0) >> 4;
        switch (lc_n)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                astr_val->SMSPhone[li_i * 2] = lc_n + '0';
                break;
            case 10:
                astr_val->SMSPhone[li_i * 2] = ',';
                break;
            case 11:
                astr_val->SMSPhone[li_i * 2] = '#';
                break;
            astr_val->SMSPhone[li_i * 2] = ' ';
        }
    }
    *ai_step = 16;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN5 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F5
        MesNum      ��Ϣ��֤������
        MesPar      ��Ϣ��֤����
    ����
            1  ��������
*******************************************/
int decode_afn0A_F5(uchar *data, str_AFN0A_F5 *astr_val, int *ai_step)
{
    uchar *p;
    p = data;
    astr_val->MesNum = *p;
    astr_val->MesPar = *(p + 2);
    astr_val->MesPar = (astr_val->MesPar << 8) + *(p + 1);
    *ai_step = 3;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN6 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F6
        Address        �ն����ַ
    ����
            1  ��������
*******************************************/
int decode_afn0A_F6(uchar *data, str_AFN0A_F6 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i;
    p = data;
    *ai_step = 0;
    for (li_i = 0; li_i < 8; li_i++)
    {
        astr_val->Address[li_i] = *(p + 1);
        astr_val->Address[li_i] = (astr_val->Address[li_i] << 8) + *p;
        *ai_step += 2;
        p +=2;
    }
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN7 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F7
        cbday          ���������飬Ϊ1��ʾ���±�
                       ����Ϊ������
        cbtime         ����ʱ��
        cbtimeisnull   ����ʱ��Ϊ�ձ�־��1��ʾ��
                       ��ʱ��Ϊ��
    ����
            1  ��������
*********************************************/
int decode_afn0A_F7(uchar *data, str_AFN0A_F7 *astr_val, int *ai_step)
{
    uchar *p;
    uchar lc_n, li_i;

    p = data;

    for (li_i = 0; li_i < 15; li_i++)
        astr_val->zdIP[li_i] = ' ';
    lc_n = *p;
    sprintf((char *)&(astr_val->zdIP[0]), "%.3d", lc_n);
    lc_n = *(p + 1);
    astr_val->zdIP[3] = '.';
    sprintf((char *)&(astr_val->zdIP[4]), "%.3d", lc_n);
    lc_n = *(p + 2);
    astr_val->zdIP[7] = '.';
    sprintf((char *)&(astr_val->zdIP[8]), "%.3d", lc_n);
    lc_n = *(p + 3);
    astr_val->zdIP[11] = '.';
    sprintf((char *)&(astr_val->zdIP[12]), "%.3d", lc_n);
    *ai_step = 4;
    p +=4;

    for (li_i = 0; li_i < 15; li_i++)
        astr_val->zwYM[li_i] = ' ';
    lc_n = *p;
    sprintf((char *)&(astr_val->zwYM[0]), "%.3d", lc_n);
    lc_n = *(p + 1);
    astr_val->zwYM[3] = '.';
    sprintf((char *)&(astr_val->zwYM[4]), "%.3d", lc_n);
    lc_n = *(p + 2);
    astr_val->zwYM[7] = '.';
    sprintf((char *)&(astr_val->zwYM[8]), "%.3d", lc_n);
    lc_n = *(p + 3);
    astr_val->zwYM[11] = '.';
    sprintf((char *)&(astr_val->zwYM[12]), "%.3d", lc_n);
    (*ai_step) += 4;
    p +=4;

    for (li_i = 0; li_i < 15; li_i++)
        astr_val->WG[li_i] = ' ';
    lc_n = *p;
    sprintf((char *)&(astr_val->WG[0]), "%.3d", lc_n);
    lc_n = *(p + 1);
    astr_val->WG[3] = '.';
    sprintf((char *)&(astr_val->WG[4]), "%.3d", lc_n);
    lc_n = *(p + 2);
    astr_val->WG[7] = '.';
    sprintf((char *)&(astr_val->WG[8]), "%.3d", lc_n);
    lc_n = *(p + 3);
    astr_val->WG[11] = '.';
    sprintf((char *)&(astr_val->WG[12]), "%.3d", lc_n);
    (*ai_step) += 4;
    p +=4;

    astr_val->dllx = *p;
    (*ai_step) += 1;
    p +=1;

    for (li_i = 0; li_i < 15; li_i++)
        astr_val->dlIP[li_i] = ' ';
    lc_n = *p;
    sprintf((char *)&(astr_val->dlIP[0]), "%.3d", lc_n);
    lc_n = *(p + 1);
    astr_val->dlIP[3] = '.';
    sprintf((char *)&(astr_val->dlIP[4]), "%.3d", lc_n);
    lc_n = *(p + 2);
    astr_val->dlIP[7] = '.';
    sprintf((char *)&(astr_val->dlIP[8]), "%.3d", lc_n);
    lc_n = *(p + 3);
    astr_val->dlIP[11] = '.';
    sprintf((char *)&(astr_val->dlIP[12]), "%.3d", lc_n);
    (*ai_step) += 4;
    p +=4;

    astr_val->dlSOCKET = *(p+1);
    astr_val->dlSOCKET = (astr_val->dlSOCKET <<8) + *(p);
    (*ai_step)+=2;
    p+=2;

    astr_val->ljfs = *p;
    (*ai_step) += 1;
    p +=1;

    astr_val->nmlen = *p;
    (*ai_step) += 1;
    p +=1;
    memcpy(astr_val->name, p, astr_val->nmlen);

    astr_val->pwlen = *p;
    (*ai_step) += 1;
    p +=1;
    memcpy(astr_val->pw, p, astr_val->pwlen);

    astr_val->zdSOCKET = *(p+1);
    astr_val->zdSOCKET = (astr_val->zdSOCKET <<8) + *(p);
    (*ai_step)+=2;
    p+=2;

    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN8 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F8
        SaveEvent  ��¼�¼���־���飬Ϊ1��ʾ
                   ���±���¼���Ч
        EventRate  �¼��ȼ���־���飬Ϊ1��ʾ
                   ���±���¼�Ϊ��Ҫ�¼�
    ����
            1  ��������
*********************************************/
int decode_afn0A_F8(uchar *data, str_AFN0A_F8 *astr_val, int *ai_step)
{
    int li_i;

    uchar *p;
    p = data;
    astr_val->onlinetype = (*p) & 0X03;
    astr_val->worktype = ((*p) & 0X30) >> 4;
    astr_val->sockettype = ((*p) & 0X80) >> 7;
    *ai_step = 1;
    p++;
    astr_val->retelstep = *(p + 1);
    astr_val->retelstep = (astr_val->retelstep  << 8) + *p;
    *ai_step += 2;
    p += 2;
    astr_val->reteltimes = *p;
    (*ai_step)++;
    p++;
    astr_val->distime = *p;
    (*ai_step)++;
    p++;

    for(li_i = 0; li_i<24; li_i++)
    {
        astr_val->onlinetime[li_i] = *p;
        (*ai_step)++;
        p++;
    }

    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN9 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F9
        MeterNumber        ���������
        PulseNumber        ��������
        ImitationNumber;   ģ��������
        AddgroupNumber;    �ܼ�������
    ����
        1          ��������
*******************************************/
int decode_afn0A_F9(uchar *data, str_AFN0A_F9 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i, li_j;
    p = data;
    for (li_i = 0; li_i < 8; li_i++)
    {
        for (li_j = 0; li_j < 8; li_j++)
        {
            astr_val->SaveEvent[li_i * 8 + li_j] = (*(p + li_i) & ( 1 << li_j)) ? 1 : 0;
        }
    }
    p = p + 8;
    for (li_i = 0; li_i < 8; li_i++)
        for (li_j = 0; li_j < 8; li_j++)
        {
            astr_val->EventRate[li_i * 8 + li_j] = (*(p + li_i) & ( 1 << li_j)) ? 1 : 0;
        }
    *ai_step = 16;
    return ERROR_SUCCESS;
}

/*********** ������ԼA������FN10 *************
    data   ����ָ��

    ai_step  ���ĳ���
    str_AFN0A_F10
        MeterNumber        ���������
        str_AFN0A_F10_METERINFO  ����������
                Index;         ��������
                CLD;           �����������
                Port;              485����˿�
                SpeedIndex;        485����
                StatuteIndex;      ��Լ���
                MeterAdd;          ���ַ
                MeterAddisnull;    ���ַΪ�ձ�־
                password[6];       ����
                XSW;               С��λ��
                ZSW;               ����λ��
                FLS;               ������
    ����
        1          ��������
        -4         �������������
*******************************************/
int decode_afn0A_F10(uchar *data, str_AFN0A_F10 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i, li_step;
    p =data;
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
    astr_val->MeterNumber = *(p+1);
    astr_val->MeterNumber = ((astr_val->MeterNumber)<<8) + *p;
    *ai_step = 2;
    p +=2 ;
    tracelog("astr_val->MeterNumber=%d",astr_val->MeterNumber);
    for (li_i = 0;li_i < astr_val->MeterNumber; li_i++)
    {
        astr_val->MeterInfo[li_i].Index = *(p+1);
        astr_val->MeterInfo[li_i].Index = ((astr_val->MeterInfo[li_i].Index)<<8) + *p;
        (*ai_step) +=2 ;
        p +=2 ;
        astr_val->MeterInfo[li_i].CLD = *(p+1);
        astr_val->MeterInfo[li_i].CLD = ((astr_val->MeterInfo[li_i].CLD)<<8) + *p;
        (*ai_step) +=2 ;
        p +=2 ;
        astr_val->MeterInfo[li_i].Port = *p & 0x1f;
        astr_val->MeterInfo[li_i].SpeedIndex = (*p & 0xe0) >> 5;
        (*ai_step)++;
        p++;
        astr_val->MeterInfo[li_i].StatuteIndex = *p;
        (*ai_step)++;
        p++;
        astr_val->MeterInfo[li_i].MeterAddisnull = getdataformat12(p, &(astr_val->MeterInfo[li_i].MeterAdd), &li_step);
        *ai_step += li_step;
        p += li_step;
        memcpy(astr_val->MeterInfo[li_i].password, p, 6);
        *ai_step += 6;
        p = p + 6;

        astr_val->MeterInfo[li_i].FLS = *p & 0X3F;
        (*ai_step)++;
        p = p + 1;

        astr_val->MeterInfo[li_i].XSW = (*p & 0x03) + 1;
        astr_val->MeterInfo[li_i].ZSW = ((*p & 0x0C) >> 2) + 4;
        (*ai_step)++;
        p = p + 1;

        astr_val->MeterInfo[li_i].CJQAddisnull = getdataformat12(p, &(astr_val->MeterInfo[li_i].CJQAdd), &li_step);
        *ai_step += li_step;
        p += li_step;
        astr_val->MeterInfo[li_i].DLH = (*p & 0xf0) >>4;
        astr_val->MeterInfo[li_i].XLH = *p & 0x0f ;
        (*ai_step)++;
        p++;
    }
    return ERROR_SUCCESS;
}