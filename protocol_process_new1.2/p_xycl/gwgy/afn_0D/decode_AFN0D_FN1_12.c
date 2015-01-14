
#include "decode_AFN0D_public.h"

/*
int de_AFN0D_FN1_2_9_10_save(str_file *file_out, str_AFN0D_CODE *str_in,uchar ac_PN, uchar ac_FN, uchar type)
{
	int li_m=0, li_i;
	char file_name[256]={0}, field_name[100]={0};
	double *pdat;
	short *pdat_isnull;
	int ret = ERROR_SUCCESS;

	switch (ac_FN){  
		case 1:
			switch (type){   //0:表示正反向有功总，1:表示正反向无功总，2:表示一二象限无功总，3:表示三四象限无功总
				case 0:
					strcpy(file_name, "dayfrz_zxyg_dnsz");
					strcpy(field_name, "PAP_R");
					pdat_isnull = str_in->isnull.Pcode;
					pdat = str_in->val.Pcode;
					break;
				case 1:
					strcpy(file_name, "dayfrz_zxwg_dnsz");
					strcpy(field_name, "PRP_R");
					pdat_isnull = str_in->isnull.Qcode;
					pdat = str_in->val.Qcode;
					break;
				case 2:
					strcpy(file_name, "dayfrz_1xxwg_dnsz");
					strcpy(field_name, "RP1_R");
					pdat_isnull = str_in->isnull.Q12code;
					pdat = str_in->val.Q12code;
					break;
				case 3:
					strcpy(file_name, "dayfrz_4xxwg_dnsz");
					strcpy(field_name, "RP4_R");
					pdat_isnull = str_in->isnull.Q34code;
					pdat = str_in->val.Q34code;
					break;
				default:
					ret = NOT_DEFINE_DATA;
					break;
			}
			break;
		case 2:
			switch (type){
				case 0:
					strcpy(file_name, "dayfrz_fxyg_dnsz");
					strcpy(field_name, "RAP_R");
					pdat_isnull = str_in->isnull.Pcode;
					pdat = str_in->val.Pcode;
					break;
				case 1:
					strcpy(file_name, "dayfrz_fxwg_dnsz");
					strcpy(field_name, "RRP_R");
					pdat_isnull = str_in->isnull.Qcode;
					pdat = str_in->val.Qcode;
					break;
				case 2:
					strcpy(file_name, "dayfrz_2xxwg_dnsz");
					strcpy(field_name, "RP2_R");
					pdat_isnull = str_in->isnull.Q12code;
					pdat = str_in->val.Q12code;
					break;
				case 3:
					strcpy(file_name, "dayfrz_3xxwg_dnsz");
					strcpy(field_name, "RP3_R");
					pdat_isnull = str_in->isnull.Q34code;
					pdat = str_in->val.Q34code;
					break;
				default:
					ret = NOT_DEFINE_DATA;
					break;
			}
			break;
/*		case 9:
			switch (type){
				case 0:
					strcpy(file_name, "cbdayfrz_zxyg_dnsz");
					pdat_isnull = str_in->isnull.Pcode;
					pdat = str_in->val.Pcode;
					break;
				case 1:
					strcpy(file_name, "cbdayfrz_zxwg_dnsz");
					pdat_isnull = str_in->isnull.Qcode;
					pdat = str_in->val.Qcode;
					break;
				case 2:
					strcpy(file_name, "cbdayfrz_1xxwg_dnsz");
					pdat_isnull = str_in->isnull.Q12code;
					pdat = str_in->val.Q12code;
					break;
				case 3:
					strcpy(file_name, "cbdayfrz_4xxwg_dnsz");
					pdat_isnull = str_in->isnull.Q34code;
					pdat = str_in->val.Q34code;
					break;
				default:
					ret = NOT_DEFINE_DATA;
					break;
			}
			break;
		case 10:
			switch (type){
				case 0:
					strcpy(file_name, "cbdayfrz_fxyg_dnsz");
					pdat_isnull = str_in->isnull.Pcode;
					pdat = str_in->val.Pcode;
					break;
				case 1:
					strcpy(file_name, "cbdayfrz_fxwg_dnsz");
					pdat_isnull = str_in->isnull.Qcode;
					pdat = str_in->val.Qcode;
					break;
				case 2:
					strcpy(file_name, "cbdayfrz_2xxwg_dnsz");
					pdat_isnull = str_in->isnull.Q12code;
					pdat = str_in->val.Q12code;
					break;
				case 3:
					strcpy(file_name, "cbdayfrz_3xxwg_dnsz");
					pdat_isnull = str_in->isnull.Q34code;
					pdat = str_in->val.Q34code;
					break;
				default:
					ret = NOT_DEFINE_DATA;
					break;
			}
			break;*/
/*		default:
			ret = NOT_DEFINE_DATA;
			break;
	}
	if (ret != ERROR_SUCCESS)
		return ret;

	sprintf(file_out->name, "/home/store/20141010_data/freezing/zxygz/%d_", ac_PN);
	strcpy(file_out->field[li_m].name, "DATA_DATE");  //日冻结时标
	sprintf(file_out->field[li_m++].values, "%.2u%.2u%.2u", str_in->val.TD.year, str_in->val.TD.mon, str_in->val.TD.day);
	strcpy(file_out->field[li_m].name, "COL_TIME");  //终端抄表时间
	sprintf(file_out->field[li_m++].values, "%.2u%.2u%.2u%.2u%.2u", str_in->val.CBSJ.year, str_in->val.CBSJ.mon, str_in->val.CBSJ.day, str_in->val.CBSJ.hour, str_in->val.CBSJ.min);
	strcpy(file_out->field[li_m].name, "fls");  //费率数
	sprintf(file_out->field[li_m++].values, "%u", str_in->val.FLS);
	
	strcat(file_out->name, file_name);
	if (pdat_isnull[0] != DATA_ISNULL){
		strcpy(file_out->field[li_m].name, field_name);
		sprintf(file_out->field[li_m++].values, "%f", pdat[0]);
	}
	for (li_i = 1; li_i <= str_in->val.FLS; li_i++){
		if (pdat_isnull[li_i] != DATA_ISNULL){
			sprintf(file_out->field[li_m].name, "%s%u", field_name, li_i);
			sprintf(file_out->field[li_m++].values, "%f", pdat[li_i]);
		}
	}
	sprintf(file_out->field_num, "%u", li_m);	

		printf("***********###########file_out->field_num = %s\n", file_out->field_num);

	
	return ret;
}*/


int de_AFN0D_FN1_2_9_10_str(uchar *dat_in, int dat_len, str_AFN0D_CODE *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 43)
		return ERROR_FRAME_DATA_LENGTH;
	/*时标*/
	str_out->isnull.TD = getdataformat20(p, &(str_out->val.TD), &li_step);
	*ai_step = li_step;
	p += li_step;
	/*抄表时间*/
	str_out->isnull.CBSJ = getdataformat15(p, &(str_out->val.CBSJ), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*费率数*/
	str_out->val.FLS = *p;
	(*ai_step)++;
	p++;
	if (str_out->val.FLS > 14)
		return ERROR_DATA_INVALID;
	if (dat_len - *ai_step < (5+4+4+4+5*str_out->val.FLS+4*str_out->val.FLS*3))
		return ERROR_FRAME_DATA_LENGTH;
	/*有功电能示值*/
	for (li_i = 0; li_i <= str_out->val.FLS; li_i++){
		str_out->isnull.Pcode[li_i] = getdataformat14(p, &(str_out->val.Pcode[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*无功电能示值*/
	for (li_i = 0; li_i <= str_out->val.FLS; li_i++){
		str_out->isnull.Qcode[li_i] = getdataformat11(p, &(str_out->val.Qcode[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*1、2象限电能示值*/
	for (li_i = 0; li_i <= str_out->val.FLS; li_i++){
		str_out->isnull.Q12code[li_i] = getdataformat11(p, &(str_out->val.Q12code[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*3、4象限电能示值*/
	for (li_i = 0; li_i <= str_out->val.FLS; li_i++){
		str_out->isnull.Q34code[li_i] = getdataformat11(p, &(str_out->val.Q34code[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	 printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",str_out->val.TD.year,
             str_out->val.TD.mon,str_out->val.TD.day,str_out->val.TD.hour,str_out->val.TD.min); 
       printf("*********year = %d,month = %d, day =%d,FLS = %d**********\n",str_out->val.CBSJ.year,
             str_out->val.CBSJ.mon,str_out->val.CBSJ.day,str_out->val.FLS);
       for(li_i = 0;li_i<str_out->val.FLS;li_i++)
       {
            printf("Pcode[li_i]  = %f  ",str_out->val.Pcode[li_i]);
       }
       printf("测试通过\n");

	
    /*if ((ac_FN == 1) || (ac_FN == 1))
    {
        after_day(&lstr_afn0D_CODE_val.val.TD,&lstr_afn0D_CODE_val.val.TD,1);
    }*/
	if (str_out->isnull.TD == DATA_ISNULL)  /*时间不存在*/
		return ERROR_NULL_TD;

	return ERROR_SUCCESS;
}

/*********** 解析规约D类数据需量(日,抄表日)*************
    data   报文指针

    ai_step  报文长度
    str_AFN0D_XL
        str_AFN0D_XL_VAL
            TD        时标
            CBSJ      抄表时间
            FLS       费率数
            PXL       有功需量数组
            PXLSJ     有功需量发生时间数组
            QXL       无功需量数组
            QXLSJ     无功需量发生时间数组
        str_AFN0D_XL_ISNULL
            TD        时标判空标志
            CBSJ      抄表时间判空标志
            FLS       费率数判空标志
            PXL       有功需量判空标志数组
            PXLSJ     有功需量发生时间判空标志数组
            QXL       无功需量判空标志数组
            QXLSJ     无功需量发生时间判空标志数组
    返回
        1          正常返回
        -4         错误的数据
*******************************************/
int de_AFN0D_FN3_4_11_12_str(uchar *data, str_AFN0D_XL *astr_val, int *ai_step)
{
    uchar *p;
    int li_step, li_i, li_j;
    astr_val->isnull.TD = DATA_ISNULL;
    astr_val->isnull.CBSJ = DATA_ISNULL;
    for (li_i = 0; li_i < 15; li_i++)
    {
        astr_val->isnull.PXL[li_i] = DATA_ISNULL;
        astr_val->isnull.PXLSJ[li_i] = DATA_ISNULL;
        astr_val->isnull.QXL[li_i] = DATA_ISNULL;
        astr_val->isnull.QXLSJ[li_i] = DATA_ISNULL;
    }
    memset(&(astr_val->val), 0 ,sizeof(astr_val->val));
    p = data;
    astr_val->isnull.TD = getdataformat20(p, &(astr_val->val.TD ), &li_step);
    *ai_step = li_step;
    p += li_step;

    astr_val->isnull.CBSJ = getdataformat15(p, &(astr_val->val.CBSJ), &li_step);
    *ai_step += li_step;
    p += li_step;

    astr_val->val.FLS = *p;
    (*ai_step)++;
    p++;
    if (astr_val->val.FLS > 14)
        return ERROR_DATA_INVALID;
    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)
    {
        astr_val->isnull.PXL[li_i] = getdataformat23(p, &(astr_val->val.PXL[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)
    {
        astr_val->isnull.PXLSJ[li_i] = getdataformat17(p, &(astr_val->val.TD), &(astr_val->val.PXLSJ[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)
    {
        astr_val->isnull.QXL[li_i] = getdataformat23(p, &(astr_val->val.QXL[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)
    {
        astr_val->isnull.QXLSJ[li_i] = getdataformat17(p, &(astr_val->val.TD), &(astr_val->val.QXLSJ[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
  
	 printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       printf("*********year = %d,month = %d, day =%d,FLS = %d**********\n",astr_val->val.CBSJ.year,
             astr_val->val.CBSJ.mon,astr_val->val.CBSJ.day,astr_val->val.FLS);
       for(li_j = 0;li_j<astr_val->val.FLS;li_j++)
       {
            printf("PXL[li_j]  = %f  ",astr_val->val.PXL[li_j]);
       }    
       printf("测试通过\n");

	
    return ERROR_SUCCESS;
}

/*********** 解析规约D类数据电能量(日,抄表日)*************
    data   报文指针

    ai_step  报文长度
    str_AFN0D_POWER
        str_AFN0D_POWER_VAL
            TD          时标
            CBSJ        抄表时间
            FLS         费率数
            power       电量数组
        str_AFN0D_POWER_ISNULL
            TD          时标判空标志
            CBSJ        抄表时间判空标志
            FLS         费率数判空标志
            power       电量判空标志数组
    返回
        1          正常返回
        -4         错误的数据
*******************************************/
int de_AFN0D_FN5_6_7_8_str(uchar *data, str_AFN0D_POWER *astr_val, int *ai_step)
{
    uchar *p;
    int li_i, li_step;
    for (li_i = 0; li_i < 15; li_i++)
    {
        astr_val->isnull.power[li_i] = DATA_ISNULL;
    }
    memset(&(astr_val->val), 0, sizeof(astr_val->val));
    p = data;
    astr_val->isnull.TD = getdataformat20(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->val.FLS = *p;
    (*ai_step)++;
    p++;
    if (astr_val->val.FLS > 14)
        return ERROR_DATA_INVALID;
    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)
    {
        astr_val->isnull.power[li_i] = getdataformat13(p, &(astr_val->val.power[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
    return ERROR_SUCCESS;
}


int de_AFN0D_FN1_2_9_10(uchar *ac_p, str_encode_param *str_up, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	str_AFN0D_CODE lstr_afn0d_f1;
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0d_f1.isnull, DATA_ISNULL, sizeof(lstr_afn0d_f1.isnull));
	memset(&(lstr_afn0d_f1.val), 0, sizeof(lstr_afn0d_f1.val));

	li_ret = de_AFN0D_FN1_2_9_10_str(ac_p, ai_len, &lstr_afn0d_f1, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		//组错误的内部报文
/*		get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file);  //组内部报文
		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;*/
	}

//	f_get_xh(lc_rwbh);



	printf("lstr_afn0d_f1=%d\n", lstr_afn0d_f1.val.FLS);
	printf("Pcode=%lf\n", lstr_afn0d_f1.val.Pcode[0]);
	printf("Qcode=%lf\n", lstr_afn0d_f1.val.Qcode[0]);

	
	
	
	DEBUG("write file AFN0D_F1 done!\n");
		
	/*	if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
			get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, ERROR_SUCCESS, 0, &lstr_file);  //get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file)
			f_sendto_sjcl(&lstr_file, ERROR_SUCCESS);
		}*/
	
 
/*   if (astr_frame->msa >= MIN_MSA)
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

int de_AFN0D_FN3_4_11_12(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	str_AFN0D_XL lstr_afn0D_XL_val;
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_XL_val.isnull, DATA_ISNULL, sizeof(lstr_afn0D_XL_val.isnull));
	memset(&(lstr_afn0D_XL_val.val), 0, sizeof(lstr_afn0D_XL_val.val));

	li_ret = de_AFN0D_FN3_4_11_12_str(ac_p, &lstr_afn0D_XL_val, ai_step);
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


int de_AFN0D_FN5_6_7_8(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	str_AFN0D_POWER lstr_AFN0D_POWER;
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_AFN0D_POWER.isnull, DATA_ISNULL, sizeof(lstr_AFN0D_POWER.isnull));
	memset(&(lstr_AFN0D_POWER.val), 0, sizeof(lstr_AFN0D_POWER.val));

	li_ret = de_AFN0D_FN5_6_7_8_str(ac_p,  &lstr_AFN0D_POWER, ai_step);
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


