#include "decode_AFN0D_FN17_24.h"


{
	str_AFN0D_CODE lstr_afn0D_CODE_val;;
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_CODE_val.isnull, DATA_ISNULL, sizeof(lstr_afn0D_CODE_val.isnull));
	memset(&(lstr_afn0D_CODE_val.val), 0, sizeof(lstr_afn0D_CODE_val.val));

	li_ret = decode_afn0D_CODE_M(ac_p,  &lstr_afn0D_CODE_val, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		//�������ڲ�����
		get_report_100302_0001(NULL, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //���ڲ�����
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

{
	str_AFN0D_XL lstr_afn0D_XL_val;
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_XL_val.isnull, DATA_ISNULL, sizeof(lstr_afn0D_XL_val.isnull));
	memset(&(lstr_afn0D_XL_val.val), 0, sizeof(lstr_afn0D_XL_val.val));

	li_ret = decode_afn0D_XL_M(ac_p,  &lstr_afn0D_XL_val, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		//�������ڲ�����
		get_report_100302_0001(NULL, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //���ڲ�����
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

int de_AFN0D_FN21_22_23_24(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	 str_AFN0D_POWER lstr_afn0D_power;
	uchar *p;
    int li_i, li_j, li_m=0;
    int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_power.isnull, DATA_ISNULL, sizeof(lstr_afn0D_power.isnull));
	memset(&(lstr_afn0D_power.val), 0, sizeof(lstr_afn0D_power.val));

	li_ret = decode_afn0D_POWER_M(ac_p,  &lstr_afn0D_power, ai_step);
	if (li_ret != ERROR_SUCCESS ){
		//�������ڲ�����
		get_report_100302_0001(NULL, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //���ڲ�����
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

