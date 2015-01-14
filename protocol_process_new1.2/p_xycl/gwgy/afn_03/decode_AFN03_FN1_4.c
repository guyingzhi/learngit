#include "decode_AFN03_FN1_4.h"

int de_AFN03_FN1_2_str(uchar *dat_in, int dat_len, str_relay_sta *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 1)
		return ERROR_FRAME_DATA_LENGTH;
	memcpy(str_out, p, 1);
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}


int de_AFN03_FN1_2(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_relay_sta lstr_sta;

	memset(&lstr_sta, 0, sizeof(lstr_sta));
	*ai_step = 1;

	li_ret = de_AFN03_FN1_2_str(ac_p, ai_len, &lstr_sta, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		/*组错误的内部报文*/
/*		get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //组内部报文
		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;*/
	}

/*	f_get_xh(lc_rwbh);
		memset(&lstr_file, 0, sizeof(lstr_file));*/
		/*此处为调试代码*/
		/*memset(&lstr_afn0d_f1.isnull, DATA_ISNOTNULL, sizeof(lstr_afn0d_f1.isnull));
		lstr_afn0d_f1.val.TD.year = 14;
		lstr_afn0d_f1.val.TD.mon = 10;
		lstr_afn0d_f1.val.TD.day = 10;
		lstr_afn0d_f1.val.CBSJ.year = 14;
		lstr_afn0d_f1.val.CBSJ.mon = 10;
		lstr_afn0d_f1.val.CBSJ.day = 10;
		lstr_afn0d_f1.val.CBSJ.hour = 23;
		lstr_afn0d_f1.val.CBSJ.min = 55;
		lstr_afn0d_f1.val.FLS = 3;
		for (li_j = 0; li_j < lstr_afn0d_f1.val.FLS+1; li_j++){
			lstr_afn0d_f1.val.Pcode[li_j] = li_j;
			lstr_afn0d_f1.val.Qcode[li_j] = li_j;
			lstr_afn0d_f1.val.Q12code[li_j] = li_j;
			lstr_afn0d_f1.val.Q34code[li_j] = li_j;
		}
		ac_PN = 1;
		ac_FN = 1;*/		
		/*此处为调试代码*/
		
/*		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
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



int de_AFN03_FN3_str(uchar *dat_in, int dat_len, str_relay_chgsta *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 70)
		return ERROR_FRAME_DATA_LENGTH;
	for (li_i = 0; li_i < 10; li_i++){
		str_out->isnull.chg_time[li_i] = getdataformat15(p, &(str_out->val.chg_time[li_i]), &li_step);  /*时标*/
		*ai_step += li_step;
		p += li_step;
		str_out->val.bef_chgsta[li_i] = *p;
		(*ai_step)++;
		p++;
		str_out->val.after_chgsta[li_i] = *p;
		(*ai_step)++;
		p++;
	}
	for (li_i = 0; li_i < 10; li_i++){
		if (str_out->isnull.chg_time[li_i] != DATA_ISNULL)  //时间存在
			break;
	}
	if (li_i == 10)
		return ERROR_NULL_DATE;

	return ERROR_SUCCESS;
}


int de_AFN03_FN3(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_relay_chgsta lstr_chgsta;

	memset(&lstr_chgsta, 0, sizeof(lstr_chgsta));
	
	li_ret = de_AFN03_FN3_str(ac_p, ai_len, &lstr_chgsta, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		/*组错误的内部报文*/
//		get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file);
//		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;
	}
		

/*	f_get_xh(lc_rwbh);
		memset(&lstr_file, 0, sizeof(lstr_file));*/
		/*此处为调试代码*/
		/*memset(&lstr_afn0d_f1.isnull, DATA_ISNOTNULL, sizeof(lstr_afn0d_f1.isnull));
		lstr_afn0d_f1.val.TD.year = 14;
		lstr_afn0d_f1.val.TD.mon = 10;
		lstr_afn0d_f1.val.TD.day = 10;
		lstr_afn0d_f1.val.CBSJ.year = 14;
		lstr_afn0d_f1.val.CBSJ.mon = 10;
		lstr_afn0d_f1.val.CBSJ.day = 10;
		lstr_afn0d_f1.val.CBSJ.hour = 23;
		lstr_afn0d_f1.val.CBSJ.min = 55;
		lstr_afn0d_f1.val.FLS = 3;
		for (li_j = 0; li_j < lstr_afn0d_f1.val.FLS+1; li_j++){
			lstr_afn0d_f1.val.Pcode[li_j] = li_j;
			lstr_afn0d_f1.val.Qcode[li_j] = li_j;
			lstr_afn0d_f1.val.Q12code[li_j] = li_j;
			lstr_afn0d_f1.val.Q34code[li_j] = li_j;
		}
		ac_PN = 1;
		ac_FN = 1;*/		
		/*此处为调试代码*/
		
/*		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
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


int de_AFN03_FN4_str(uchar *dat_in, int dat_len, str_relay_runsta *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_i;

	if (dat_len < 10)
		return ERROR_FRAME_DATA_LENGTH;
	str_out->chg_cnt = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->apc_onduty =  (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->apc_normal =  (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->bpc_onduty =  (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->bpc_normal =  (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;

	return ERROR_SUCCESS;
}


int de_AFN03_FN4(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_relay_runsta lstr_runsta;

	memset(&lstr_runsta, 0, sizeof(lstr_runsta));
	
	li_ret = de_AFN03_FN4_str(ac_p, ai_len, &lstr_runsta, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		/*组错误的内部报文*/
//		get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file);
//		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;
	}

/*	f_get_xh(lc_rwbh);
		memset(&lstr_file, 0, sizeof(lstr_file));*/
		/*此处为调试代码*/
		/*memset(&lstr_afn0d_f1.isnull, DATA_ISNOTNULL, sizeof(lstr_afn0d_f1.isnull));
		lstr_afn0d_f1.val.TD.year = 14;
		lstr_afn0d_f1.val.TD.mon = 10;
		lstr_afn0d_f1.val.TD.day = 10;
		lstr_afn0d_f1.val.CBSJ.year = 14;
		lstr_afn0d_f1.val.CBSJ.mon = 10;
		lstr_afn0d_f1.val.CBSJ.day = 10;
		lstr_afn0d_f1.val.CBSJ.hour = 23;
		lstr_afn0d_f1.val.CBSJ.min = 55;
		lstr_afn0d_f1.val.FLS = 3;
		for (li_j = 0; li_j < lstr_afn0d_f1.val.FLS+1; li_j++){
			lstr_afn0d_f1.val.Pcode[li_j] = li_j;
			lstr_afn0d_f1.val.Qcode[li_j] = li_j;
			lstr_afn0d_f1.val.Q12code[li_j] = li_j;
			lstr_afn0d_f1.val.Q34code[li_j] = li_j;
		}
		ac_PN = 1;
		ac_FN = 1;*/		
		/*此处为调试代码*/
		
/*		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
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



