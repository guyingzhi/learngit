#include"decode_AFN0D_FN129_136.h"
/*********** 解析模拟量日统计数据 *************
	as_data	报文指针

    str_AFN0D_F129
        str_AFN0D_F129_VAL
            TD            时标
            overlimit     越上限时间
            overlower     越下限时间
            MAXval        最大值
            MAXvaltime    最大值出现时间
            MINval        最小值
            MINvaltime    最小值出现时间
        str_AFN0D_F129_ISNULL
            TD            时标判空标志
            overlimit     越上限时间判空标志
            overlower     越下限时间判空标志
            MAXval        最大值判空标志
            MAXvaltime    最大值出现时间判空标志
            MINval        最小值判空标志
            MINvaltime    最小值出现时间判空标志
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
*******************************************/
int decode_AFN0D_F129(uchar *data,str_AFN0D_F219F130 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
	/*时标*/
    astr_val->isnull.TD = getdataformat20(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
	/*越上限时间*/
    if ((astr_val->isnull.overlimit = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.overlimit = *(p + 1);
        astr_val->val.overlimit = (astr_val->val.overlimit << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	/*越下限时间*/
    if ((astr_val->isnull.overlower = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.overlower = *(p + 1);
        astr_val->val.overlower = (astr_val->val.overlower << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	/*直流模拟量日最大值*/
    astr_val->isnull.MAXval = getdataformat02(p, &(astr_val->val.MAXval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*直流模拟量最大值发生时间*/
    astr_val->isnull.MAXvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*直流模拟量日最小值*/
    astr_val->isnull.MINval = getdataformat02(p, &(astr_val->val.MINval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*直流模拟量日最小值发生时间*/
    astr_val->isnull.MINvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MINvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
    return ERROR_SUCCESS;
}

/*********** 解析模拟量月统计数据 *************
	as_data	报文指针

    str_AFN0D_F130
        str_AFN0D_F130_VAL
            TD            时标
            overlimit     越上限时间
            overlower     越下限时间
            MAXval        最大值
            MAXvaltime    最大值出现时间
            MINval        最小值
            MINvaltime    最小值出现时间
        str_AFN0D_F130_ISNULL
            TD            时标判空标志
            overlimit     越上限时间判空标志
            overlower     越下限时间判空标志
            MAXval        最大值判空标志
            MAXvaltime    最大值出现时间判空标志
            MINval        最小值判空标志
            MINvaltime    最小值出现时间判空标志
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
*******************************************/
int decode_AFN0D_F130(uchar *data, str_AFN0D_F219F130 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    if ((astr_val->isnull.overlimit = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.overlimit = *(p + 1);
        astr_val->val.overlimit = (astr_val->val.overlimit << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    if ((astr_val->isnull.overlower = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.overlower = *(p + 1);
        astr_val->val.overlower = (astr_val->val.overlower << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	/*直流模拟量月最大值*/
    astr_val->isnull.MAXval = getdataformat02(p, &(astr_val->val.MAXval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*直流模拟量越最大值发生时间*/
    astr_val->isnull.MAXvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*直流模拟量月最小值*/
    astr_val->isnull.MINval = getdataformat02(p, &(astr_val->val.MINval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*直流模拟量月最小值发生时间*/
    astr_val->isnull.MINvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MINvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
    return ERROR_SUCCESS;
}

