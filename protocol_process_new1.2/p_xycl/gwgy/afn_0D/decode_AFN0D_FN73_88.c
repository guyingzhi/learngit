#include "decode_AFN0D_FN73_88.h"

/*********** 解析功率曲线数据 *************
	as_data	报文指针

    astr_val 解码的结果
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
			-4	日期为空
			-5	密度为空
			-6  点数为空
			-7  不能识别的密度
*******************************************/
int decode_AFN0D_F73F74_str(uchar *as_data, str_AFN0D_F73F74 *astr_val, int *ai_step)
{
    int li_i, li_res;
    int li_step;
    datetime ldt_curve_dt,ldt_act_dt;
    uchar lc_m, lc_n, lc_permin;
    uchar *p;
    datetime lstr_now;
    for (li_i = 0; li_i < 255; li_i++)
    {
        astr_val->isnull[li_i] = DATA_ISNULL;
    }
    f_get_datetime(&lstr_now);
    p = as_data;
    li_res = getdataformat15(p, &ldt_curve_dt, &li_step);
    ldt_act_dt = ldt_curve_dt;
    if (li_res == DATA_ISNULL)
        return ERROR_NULL_TD;
    *ai_step = li_step;
    p += li_step;
    if (dataisnull(p, 1))
        return ERROR_NULL_DENSITY;                  /*密度为空*/
    lc_m = *p;          /*取密度*/
    (*ai_step)++;
    p++;
    if (dataisnull(p, 1))
        return ERROR_NULL_POINT;                  /*点数为空*/
    lc_n = *p;          /*取点数*/
    tracelog("lc_n = %d",lc_n);
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
        case 4:
            lc_permin = 60;
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
        li_res = after_time(&ldt_curve_dt, &ldt_act_dt , lc_permin * 60 );/* 计算当前数据点对应的时间 */
        ldt_curve_dt = ldt_act_dt;
        /*if (time_after_check(&ldt_act_dt, &lstr_now) == 0)*/
        astr_val->val_num++;
        *ai_step +=  li_step;
        p += li_step;
    }
    if (astr_val->val_num == 0)
        return ERROR_RANGE_DATETIME;
	printf("*******************解析数据结构体完成************ \n");	
       printf("%d\n",astr_val->val_num);
       for(li_i = 0;li_i <24;li_i ++)
        {
            printf("**********val [%d] =  %f \n ",li_i,astr_val->val[li_i]);
       }       
       printf("测试通过\n");


    return ERROR_SUCCESS;
}

/*********** 解析功率曲线数据 *************
	as_data	报文指针

    astr_val 解码的结果
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
			-4	日期为空
			-5	密度为空
			-6  点数为空
			-7  不能识别的密度
*******************************************/
int decode_AFN0D_F75F76_str(uchar *as_data, str_AFN0D_F75F76 *astr_val, int *ai_step)
{
    int li_i, li_res;
    int li_step;
    datetime ldt_curve_dt,ldt_act_dt;
    uchar lc_m, lc_n, lc_permin;
    uchar *p,ac_unit;
    datetime lstr_now;
    for (li_i = 0; li_i < 255; li_i++)
    {
        astr_val->isnull[li_i] = DATA_ISNULL;
    }
    f_get_datetime(&lstr_now);
    p = as_data;
    li_res = getdataformat15(p, &ldt_curve_dt, &li_step);
    ldt_act_dt = ldt_curve_dt;
    if (li_res == DATA_ISNULL)
        return ERROR_NULL_TD;
    *ai_step = li_step;
    p += li_step;
    if (dataisnull(p, 1))
        return ERROR_NULL_DENSITY;                  /*密度为空*/
    lc_m = *p;          /*取密度*/
    (*ai_step)++;
    p++;
    if (dataisnull(p, 1))
        return ERROR_NULL_POINT;                  /*点数为空*/
    lc_n = *p;          /*取点数*/
    tracelog("lc_n = %d",lc_n);
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
        case 4:
            lc_permin = 60;
            break;

            return ERROR_DATA_INVALID;
    };
    (*ai_step)++;
    p++;
    astr_val->val_num = 0;
    for (li_i = 0; li_i < lc_n ; li_i++)
    {
        astr_val->isnull[li_i] = getdataformat03(p, &(astr_val->val[li_i]),&ac_unit, &li_step);
        astr_val->val_time[li_i] = ldt_act_dt;
        li_res = after_time(&ldt_curve_dt, &ldt_act_dt , lc_permin * 60 );/* 计算当前数据点对应的时间 */
        ldt_curve_dt = ldt_act_dt;
        /*if (time_after_check(&ldt_act_dt, &lstr_now) == 0)*/
        astr_val->val_num++;
        *ai_step +=  li_step;
        p += li_step;
    }
    if (astr_val->val_num == 0)
        return ERROR_RANGE_DATETIME;
	printf("*******************解析数据结构体完成************ \n");	
       printf("%d\n",astr_val->val_num);
       for(li_i = 0;li_i <24;li_i ++)
        {
            printf("**********val [%d] =  %f \n ",li_i,astr_val->val[li_i]);
       }
       printf("测试通过\n");

    return ERROR_SUCCESS;
}


/*********** 解析功率曲线数据 *************
	as_data	报文指针

    astr_val 解码的结果
    ai_step 报文所占字节数
	返回：	 1	解析正常返回
			-4	日期为空
			-5	密度为空
			-6  点数为空
			-7  不能识别的密度
*******************************************/
int decode_AFN0D_PQQX(uchar *as_data, str_AFN0C0D_QX *astr_val, int *ai_step)
{
    int li_i, li_res;
    int li_step;
    datetime ldt_curve_dt,ldt_act_dt;
    uchar lc_m, lc_n, lc_permin;
    uchar *p;
    datetime lstr_now;
    for (li_i = 0; li_i < 255; li_i++)
    {
        astr_val->isnull[li_i] = DATA_ISNULL;
    }
    f_get_datetime(&lstr_now);
    p = as_data;
    li_res = getdataformat15(p, &ldt_curve_dt, &li_step);
    ldt_act_dt = ldt_curve_dt;
    if (li_res == DATA_ISNULL)
        return ERROR_NULL_TD;
    *ai_step = li_step;
    p += li_step;
    if (dataisnull(p, 1))
        return ERROR_NULL_DENSITY;                  /*密度为空*/
    lc_m = *p;          /*取密度*/
    (*ai_step)++;
    p++;
    if (dataisnull(p, 1))
        return ERROR_NULL_POINT;                  /*点数为空*/
    lc_n = *p;          /*取点数*/
    tracelog("lc_n = %d",lc_n);
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
        case 4:
            lc_permin = 60;
            break;

            return ERROR_DATA_INVALID;
    };
    (*ai_step)++;
    p++;
    astr_val->val_num = 0;
    for (li_i = 0; li_i < lc_n ; li_i++)
    {
        astr_val->isnull[li_i] = getdataformat09(p, &(astr_val->val[li_i]), &li_step);
        astr_val->val_time[li_i] = ldt_act_dt;
        li_res = after_time(&ldt_curve_dt, &ldt_act_dt , lc_permin * 60 );/* 计算当前数据点对应的时间 */
        ldt_curve_dt = ldt_act_dt;
        /*if (time_after_check(&ldt_act_dt, &lstr_now) == 0)*/
        astr_val->val_num++;
        *ai_step +=  li_step;
        p += li_step;
    }
    if (astr_val->val_num == 0)
        return ERROR_RANGE_DATETIME;
	printf("*******************解析数据结构体完成************ \n");	
       printf("%d\n",astr_val->val_num);
       for(li_i = 0;li_i <24;li_i ++)
        {
            printf("**********val [%d] =  %f \n ",li_i,astr_val->val[li_i]);
       }
       printf("测试通过\n");
 
    return ERROR_SUCCESS;
}


int de_AFN0D_FN73F74(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F73F74 lstr_afn0D_F73F74_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F73F74_val, 0, sizeof( lstr_afn0D_F73F74_val));
     memset(& lstr_afn0D_F73F74_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F73F74_val.isnull));

	li_ret = decode_AFN0D_F73F74_str(ac_p,  & lstr_afn0D_F73F74_val, ai_step);

	if (li_ret != ERROR_SUCCESS ){
		//组错误的内部报文
		get_report_100302_0001(NULL, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //组内部报文
//		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;
	}

	/*f_get_xh(lc_rwbh);
	for (li_i = 0; li_i < 4; li_i++){
		memset(&lstr_file, 0, sizeof(lstr_file));

		
		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
			get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, ERROR_SUCCESS, 0, &lstr_file);  //get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file)
			f_sendto_sjcl(&lstr_file, ERROR_SUCCESS);
		}
	}
	
 
    if (astr_frame->msa >= MIN_MSA)
    {
        if (ac_FN == 1)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 0);
        }
        if (ac_FN == 2)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 1);
        }
        f_sendto_mngr(ls_mes, li_meslen);
    }*/
/*    if (astr_frame->msa == 1)
    {
        f_lostcheck_process(0x0d, astr_frame->addr, ac_FN, ac_PN, li_intdate);
    }*/
	return ERROR_SUCCESS;
}

int de_AFN0D_FN75F76(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F75F76 lstr_afn0D_F75F76_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F75F76_val, 0, sizeof( lstr_afn0D_F75F76_val));
    memset(& lstr_afn0D_F75F76_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F75F76_val.isnull));

	li_ret = decode_AFN0D_F75F76_str(ac_p, & lstr_afn0D_F75F76_val, ai_step);

	if (li_ret != ERROR_SUCCESS ){
		//组错误的内部报文
		get_report_100302_0001(NULL, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //组内部报文
//		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;
	}

	/*f_get_xh(lc_rwbh);
	for (li_i = 0; li_i < 4; li_i++){
		memset(&lstr_file, 0, sizeof(lstr_file));

		
		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
			get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, ERROR_SUCCESS, 0, &lstr_file);  //get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file)
			f_sendto_sjcl(&lstr_file, ERROR_SUCCESS);
		}
	}
	
 
    if (astr_frame->msa >= MIN_MSA)
    {
        if (ac_FN == 1)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 0);
        }
        if (ac_FN == 2)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 1);
        }
        f_sendto_mngr(ls_mes, li_meslen);
    }*/
/*    if (astr_frame->msa == 1)
    {
        f_lostcheck_process(0x0d, astr_frame->addr, ac_FN, ac_PN, li_intdate);
    }*/
	return ERROR_SUCCESS;
}

int de_AFN0D_PQQX(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	 str_AFN0C0D_QX str_AFN0D_PQX_VAL;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& str_AFN0D_PQX_VAL, 0, sizeof( str_AFN0D_PQX_VAL));
       memset(& str_AFN0D_PQX_VAL.isnull, DATA_ISNULL, sizeof( str_AFN0D_PQX_VAL.isnull));

	li_ret = decode_AFN0D_PQQX(ac_p,  & str_AFN0D_PQX_VAL, ai_step);

	if (li_ret != ERROR_SUCCESS ){
		//组错误的内部报文
		get_report_100302_0001(NULL, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //组内部报文
//		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;
	}

	/*f_get_xh(lc_rwbh);
	for (li_i = 0; li_i < 4; li_i++){
		memset(&lstr_file, 0, sizeof(lstr_file));

		
		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
			get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, ERROR_SUCCESS, 0, &lstr_file);  //get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file)
			f_sendto_sjcl(&lstr_file, ERROR_SUCCESS);
		}
	}
	
 
    if (astr_frame->msa >= MIN_MSA)
    {
        if (ac_FN == 1)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 0);
        }
        if (ac_FN == 2)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 1);
        }
        f_sendto_mngr(ls_mes, li_meslen);
    }*/
/*    if (astr_frame->msa == 1)
    {
        f_lostcheck_process(0x0d, astr_frame->addr, ac_FN, ac_PN, li_intdate);
    }*/
	return ERROR_SUCCESS;
}



