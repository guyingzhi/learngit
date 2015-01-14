#include "decode_AFN0D_FN137_144.h"

/*********** ����ģ������������ *************
	as_data	����ָ��

    astr_val ����Ľ��
    ai_step ������ռ�ֽ���
	���أ�	 1	������������
			-4	����Ϊ��
			-5	�ܶ�Ϊ��
			-6  ����Ϊ��
			-7  ����ʶ����ܶ�
*******************************************/
int decode_AFN0D_F138(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step)
{
	int li_i, li_res;
	int li_step;
	datetime ldt_curve_dt,ldt_act_dt;
	uchar lc_m, lc_n, lc_permin;
	uchar *p;
	datetime lstr_now;
	f_get_datetime(&lstr_now);
	for (li_i = 0; li_i < 255; li_i++)
	{
		astr_val->isnull[li_i] = DATA_ISNULL;
	}
	p = as_data;
	li_res = getdataformat15(p, &ldt_curve_dt, &li_step);
	ldt_act_dt = ldt_curve_dt;
	if (li_res == DATA_ISNULL)
		return ERROR_NULL_TD;
	*ai_step = li_step;
	p += li_step;
	if (dataisnull(p , 1))
		return ERROR_NULL_DENSITY;                  /*�ܶ�Ϊ��*/
	lc_m = *p;          /*ȡ�ܶ�*/
	(*ai_step)++;
	p++;
	if (dataisnull(p, 1))
		return ERROR_NULL_POINT;                  /*����Ϊ��*/
	lc_n = *p;          /*ȡ����*/
	switch(lc_m)
	{
		case 0:
			lc_permin = 0;
			break;
		case 1:
			lc_permin = 15;
			break;
		case 2:
			lc_permin = 30;
			break;
		case 3:
			lc_permin = 60;
		case 254:
			lc_permin = 5;
		case 255:
			lc_permin = 1;
			break;

		return ERROR_DATA_INVALID;
	};
	(*ai_step)++;
	p++;
	astr_val->val_num = 0;
	for (li_i = 0; li_i < lc_n ; li_i++)
	{
		astr_val->isnull[li_i] = getdataformat02(p, &(astr_val->val[li_i]), &li_step);
		astr_val->val_time[li_i] = ldt_act_dt;
		li_res = after_time(&ldt_curve_dt, &ldt_act_dt , lc_permin * 60 );/* ���㵱ǰ���ݵ��Ӧ��ʱ�� */
		ldt_curve_dt = ldt_act_dt;
		astr_val->val_num++;						
		*ai_step += li_step;
		p += li_step;
	}
	if (astr_val->val_num == 0)
		return ERROR_RANGE_DATETIME;
	return ERROR_SUCCESS;
}

