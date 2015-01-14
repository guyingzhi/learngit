#include "decode_AFN0A_FN11_24.h"

/*********** 解析规约A类数据FN11 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F11
        PulseNumber         脉冲数量
        str_AFN0A_F11_PULSEINFO
            pulseinfo  脉冲量设置参数数组
                port;             脉冲量端口
                CLD;              所属测量点
                PulseType;        脉冲类型
                KVal;             K常数
    返回
        1          正常返回
        -4         错误的数据内容
************************************************/
int decode_afn0A_F11(uchar *data, str_AFN0A_F11 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i;
    p = data;
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
    astr_val->PulseNumber = *p;
    *ai_step = 1;
    p++;
    for (li_i = 0; li_i < astr_val->PulseNumber; li_i++)
    {
        astr_val->pulseinfo[li_i].port = *p;
        (*ai_step)++;
        p++;
        astr_val->pulseinfo[li_i].CLD = *p;
        (*ai_step)++;
        p++;
        astr_val->pulseinfo[li_i].PulseType = *p & 0x03;
        (*ai_step)++;
        p++;
        astr_val->pulseinfo[li_i].KVal = *(p + 1);
        astr_val->pulseinfo[li_i].KVal = (astr_val->pulseinfo[li_i].KVal << 8) + *p;
        *ai_step += 2;
        p += 2;
    }
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN12 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F12
        BinaryState      开关量接入状态数组，为
                         1表示该下标路数有接入
        BinaryProperty   开关量类型数组，为1表示
                         该下标路数为a型触点
        BinaryAlarm      开关量报警数组，为1表示
                         该下标路数告警作为重要事件
    返回
        1          正常返回
************************************************/
int decode_afn0A_F12(uchar *data, str_AFN0A_F12 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i;
    p = data;
    for (li_i = 0; li_i < 8; li_i++)
    {
        if ((*p & (1 << li_i)) == 0)
        {
            astr_val->BinaryState[li_i] = 0;
        }
        else
        {
            astr_val->BinaryState[li_i] = 1;
        }
        if ((*(p + 1) & (1 << li_i)) == 0)
        {
            astr_val->BinaryProperty[li_i] = 0;
        }
        else
        {
            astr_val->BinaryProperty[li_i] = 1;
        }
    }
    *ai_step = 2;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN13 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F13
        imitationNumber    设置的模拟量数量
        str_AFN0A_F13_IMITATIONINFO
            imitationinfo      模拟量量配置信息数组
                port           模拟量接入端口
                CLD            所属测量点
                ImitationType  模拟量类型
    返回
        1          正常返回
        -4         错误的数据内容
************************************************/
int decode_afn0A_F13(uchar *data, str_AFN0A_F13 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i;
    p = data;
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
    astr_val->imitationNumber = *p;
    *ai_step = 1;
    p++;
    for (li_i = 0;li_i < astr_val->imitationNumber; li_i++)
    {
        astr_val->imitationinfo[li_i].port = *p;
        *ai_step = *ai_step + 1;
        p++;
        astr_val->imitationinfo[li_i].CLD = *p;
        *ai_step = *ai_step + 1;
        p++;
        /*2为电压 1为电流*/
        astr_val->imitationinfo[li_i].ImitationType = *p > 2 ? 1:2;
        *ai_step = *ai_step + 1;
        p++;
    }
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN14 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F14
        addgroupnumber     设置的总加组数量
        str_AFN0A_F14_ADDGROUPINFO
            addgroupinfo   总加组量配置信息数组
                addgroupindex  总加组序号
                CLDnumber      本总加组的测量点数量
                CLD         本总加组的测量点成员数组
                CLDdirection 本总加组的测量点方向数组
                CLDoperator  本总加组的测量点运算符数组
    返回
        1          正常返回
        -4         错误的数据内容
************************************************/
int decode_afn0A_F14(uchar *data, str_AFN0A_F14 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i,li_j;
    p = data;
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 64))
    {
        return ERROR_DATA_INVALID;
    }
    astr_val->addgroupnumber = *p;
    *ai_step = 1;
    p++;
    for (li_i = 0; li_i < astr_val->addgroupnumber; li_i++)
    {
        astr_val->addgroupinfo[li_i].addgroupindex = *p;
        (*ai_step)++;
        p++;
        astr_val->addgroupinfo[li_i].CLDnumber = *p;
        (*ai_step)++;
        p++;
        for (li_j = 0; li_j < astr_val->addgroupinfo[li_i].CLDnumber; li_j++)
        {
            astr_val->addgroupinfo[li_i].CLD[li_j] = ((*p) & 0x3f) + 1;
            astr_val->addgroupinfo[li_i].CLDdirection[li_j] = ((*p) & 0x40) >> 6;
            astr_val->addgroupinfo[li_i].CLDoperator[li_j] = ((*p) & 0x80) >> 7;
            (*ai_step)++;
            p++;
        }
    }
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN15 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F15
        diffnumber     设置的差动组数量
        str_AFN0A_F15_DIFFINFO
            diffinfo   差动组配置信息数组
                diffnum;         差动组号
                contrastnum;     对比总加组号
                referencenum;    参照总加组号
                Timespan;        时间跨度
                contrasttype;    对比方法
                Relativeval;     对比相对值
                Relativeisnull;  对比相对值判空
                Absoluteval;     对比绝对值
                Absoluteisnull;  对比绝对值判空
    返回
        1          正常返回
************************************************/
int decode_afn0A_F15(uchar *data, str_AFN0A_F15 *astr_val, int *ai_step)
{
    uchar *p, lc_unit;
    int li_i,li_step;
    p = data;
    astr_val->diffnumber = *p;
    *ai_step = 1;
    p++;
    for (li_i = 0; li_i < astr_val->diffnumber; li_i++)
    {
        astr_val->diffinfo[li_i].diffnum = *p;
        (*ai_step)++;
        p++;
        astr_val->diffinfo[li_i].contrastnum = *p;
        (*ai_step)++;
        p++;
        astr_val->diffinfo[li_i].referencenum = *p;
        (*ai_step)++;
        p++;
        astr_val->diffinfo[li_i].Timespan = *p & 0x03;
        astr_val->diffinfo[li_i].contrasttype = *p >> 7;
        (*ai_step)++;
        p++;
        if ((astr_val->diffinfo[li_i].Relativeisnull = dataisnull(p,1)) == 0)
            astr_val->diffinfo[li_i].Relativeval = *p;
        (*ai_step)++;
        p++;
        if ((astr_val->diffinfo[li_i].Absoluteisnull = getdataformat03(p, &(astr_val->diffinfo[li_i].Absoluteval), &lc_unit, &li_step)) == 0)
            if (lc_unit)
                astr_val->diffinfo[li_i].Absoluteval = astr_val->diffinfo[li_i].Absoluteval * 1000;
        *ai_step = *ai_step + li_step;
        p = p + li_step;
    }
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN16 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F16
        AFNuser       AFN用户名
        AFNpassword   AFN密码
    返回
        1          正常返回
************************************************/
int decode_afn0A_F16(uchar *data, str_AFN0A_F16 *astr_val, int *ai_step)
{
    uchar *p;
    p = data;
    memcpy(astr_val->AFNuser, p, 32);
    astr_val->AFNuser[32] = 0;
    memcpy(astr_val->AFNpassword, p + 32, 32);
    astr_val->AFNpassword[32] = 0;
    *ai_step = 64;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN17 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F17
        val        保安定值
        isnull     保安定值为空标志
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F17(uchar *data, str_AFN0A_F17 *astr_val, int *ai_step)
{
    uchar *p;
    int  li_step;
    p = data;
    astr_val->isnull = getdataformat02(p, &(astr_val->val), &li_step);
    *ai_step = li_step;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN18 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F18
        Periodstate        时段状态数组
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F18(uchar *data, str_AFN0A_F18 *astr_val, int *ai_step)
{
    uchar *p, ac_actchar;
    int li_i;
    p = data;
    for (li_i = 0; li_i < 12; li_i++)
    {
        ac_actchar = *(p + li_i);
        astr_val->Periodstate[li_i * 4] = ac_actchar & 0x03;
        astr_val->Periodstate[li_i * 4 + 1] = (ac_actchar & 0x0c) >> 2;
        astr_val->Periodstate[li_i * 4 + 2] = (ac_actchar & 0x30) >> 4;
        astr_val->Periodstate[li_i * 4 + 3] = (ac_actchar & 0xc0) >> 6;
    }
    *ai_step = 12;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据FN19F20 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_FLOATFACATOR
        val        浮动系数
        isnull     浮动系数为空标志
    返回
        1          正常返回
*******************************************/
int decode_afn0A_FLOATFACATOR(uchar *data, str_AFN0A_FLOATFACATOR *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull = getdataformat04(p, &(astr_val->val), &li_step);
    *ai_step = li_step;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据F21 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F21
        FLstate    费率时段数组
        FLS        费率数
        FLSisnull  费率数为空标志
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F21(uchar *data, str_AFN0A_F21 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i;
    p = data;
    for (li_i = 0; li_i < 48; li_i++)
    {
        astr_val->FLstate[li_i] = *p;
//        astr_val->FLstate[li_i * 2] = *p & 0x0f;
//        astr_val->FLstate[li_i * 2 + 1] = (*p & 0xf0) >> 4;
        p++;
    }
    if ((dataisnull(p,1) == DATA_ISNULL) || (*p > 14))
    {
        astr_val->FLSisnull = DATA_ISNULL;
    }
    else
    {
        astr_val->FLSisnull = DATA_ISNOTNULL;
        astr_val->FLS = *p;
    }
    (*ai_step) = 49;
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据F22 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F22
        FL        费率数组
        FLisnull  费率为空标志数组
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F22(uchar *data, str_AFN0A_F22 *astr_val, int *ai_step)
{
    uchar *p, lc_unit;
    int li_i, li_step ;
    p = data;
    (*ai_step) = 0;
    for (li_i = 0; li_i < astr_val->FLS; li_i++)
    {
        if ((astr_val->FLisnull[li_i] = getdataformat03(p, &(astr_val->FL[li_i]), &lc_unit, &li_step)) == DATA_ISNOTNULL)
        if (lc_unit)
            astr_val->FL[li_i] = astr_val->FL[li_i] * 1000;
        *ai_step += li_step;
        p += li_step;
    }
    return ERROR_SUCCESS;
}

/*********** 解析规约A类数据F23 *************
    data   报文指针

    ai_step  报文长度
    str_AFN0A_F23
        alarm    催费告警标志数组
    返回
        1          正常返回
*******************************************/
int decode_afn0A_F23(uchar *data, str_AFN0A_F23 *astr_val, int *ai_step)
{
    uchar *p;
    int li_i, li_j;
    p = data;
    for (li_i = 0; li_i < 3; li_i++)
    {
        for (li_j = 0; li_j < 8; li_j++)
        {
            if ((*(p + li_i) & (1 << li_j)) == 0)
            {
                astr_val->alarm[li_i * 8 + li_j] = 0;
            }
            else
            {
                astr_val->alarm[li_i * 8 + li_j] = 1;
            }
        }
    }
    *ai_step = 3;
    return ERROR_SUCCESS;
}


