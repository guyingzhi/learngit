#include"decode_AFN0D_FN129_136.h"
/*********** ����ģ������ͳ������ *************
	as_data	����ָ��

    str_AFN0D_F129
        str_AFN0D_F129_VAL
            TD            ʱ��
            overlimit     Խ����ʱ��
            overlower     Խ����ʱ��
            MAXval        ���ֵ
            MAXvaltime    ���ֵ����ʱ��
            MINval        ��Сֵ
            MINvaltime    ��Сֵ����ʱ��
        str_AFN0D_F129_ISNULL
            TD            ʱ���пձ�־
            overlimit     Խ����ʱ���пձ�־
            overlower     Խ����ʱ���пձ�־
            MAXval        ���ֵ�пձ�־
            MAXvaltime    ���ֵ����ʱ���пձ�־
            MINval        ��Сֵ�пձ�־
            MINvaltime    ��Сֵ����ʱ���пձ�־
    ai_step ������ռ�ֽ���
	���أ�	 1	������������
*******************************************/
int decode_AFN0D_F129(uchar *data,str_AFN0D_F219F130 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
	/*ʱ��*/
    astr_val->isnull.TD = getdataformat20(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
	/*Խ����ʱ��*/
    if ((astr_val->isnull.overlimit = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.overlimit = *(p + 1);
        astr_val->val.overlimit = (astr_val->val.overlimit << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	/*Խ����ʱ��*/
    if ((astr_val->isnull.overlower = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.overlower = *(p + 1);
        astr_val->val.overlower = (astr_val->val.overlower << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	/*ֱ��ģ���������ֵ*/
    astr_val->isnull.MAXval = getdataformat02(p, &(astr_val->val.MAXval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*ֱ��ģ�������ֵ����ʱ��*/
    astr_val->isnull.MAXvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*ֱ��ģ��������Сֵ*/
    astr_val->isnull.MINval = getdataformat02(p, &(astr_val->val.MINval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*ֱ��ģ��������Сֵ����ʱ��*/
    astr_val->isnull.MINvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MINvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
    return ERROR_SUCCESS;
}

/*********** ����ģ������ͳ������ *************
	as_data	����ָ��

    str_AFN0D_F130
        str_AFN0D_F130_VAL
            TD            ʱ��
            overlimit     Խ����ʱ��
            overlower     Խ����ʱ��
            MAXval        ���ֵ
            MAXvaltime    ���ֵ����ʱ��
            MINval        ��Сֵ
            MINvaltime    ��Сֵ����ʱ��
        str_AFN0D_F130_ISNULL
            TD            ʱ���пձ�־
            overlimit     Խ����ʱ���пձ�־
            overlower     Խ����ʱ���пձ�־
            MAXval        ���ֵ�пձ�־
            MAXvaltime    ���ֵ����ʱ���пձ�־
            MINval        ��Сֵ�пձ�־
            MINvaltime    ��Сֵ����ʱ���пձ�־
    ai_step ������ռ�ֽ���
	���أ�	 1	������������
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
	/*ֱ��ģ���������ֵ*/
    astr_val->isnull.MAXval = getdataformat02(p, &(astr_val->val.MAXval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*ֱ��ģ����Խ���ֵ����ʱ��*/
    astr_val->isnull.MAXvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*ֱ��ģ��������Сֵ*/
    astr_val->isnull.MINval = getdataformat02(p, &(astr_val->val.MINval), &li_step);
    *ai_step += li_step;
    p += li_step;
	/*ֱ��ģ��������Сֵ����ʱ��*/
    astr_val->isnull.MINvaltime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MINvaltime), &li_step);
    *ai_step += li_step;
    p += li_step;
    return ERROR_SUCCESS;
}

