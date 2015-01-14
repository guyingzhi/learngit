#include "decode_AFN09_FN1_10.h"





int de_AFN09_FN1_str(uchar *dat_in, int dat_len, str_zd_ver *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 41)
		return ERROR_FRAME_DATA_LENGTH;
	memcpy(str_out->factory_id, p, 4);
	*ai_step += 4;
	p += 4;
	memcpy(str_out->equ_num, p, 8);
	*ai_step += 8;
	p += 8;
	memcpy(str_out->zd_soft_ver, p, 4);
	*ai_step += 4;
	p += 4;
	str_out->zd_soft_dtisnull = getdataformat20(p, &str_out->zd_softdt, &li_step);
	*ai_step += li_step;
	p += li_step;
	memcpy(str_out->zd_memcfg, p, 11);
	*ai_step += 11;
	p += 11;
	memcpy(str_out->zd_comprot_ver, p, 4);
	*ai_step += 4;
	p += 4;
	memcpy(str_out->zd_hw_ver, p, 4);
	*ai_step += 4;
	p += 4;
	str_out->zd_hw_dtisnull = getdataformat20(p, &str_out->zd_hw_dt, &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN09_FN1(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_zd_ver lstr_zdver;

	memset(&lstr_zdver, 0, sizeof(lstr_zdver));
	
	li_ret = de_AFN09_FN1_str(ac_p, ai_len, &lstr_zdver, ai_step);
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


int de_AFN09_FN2_str(uchar *dat_in, int dat_len, str_io_com_portcfg *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_i;

	if (dat_len < 17)
		return ERROR_FRAME_DATA_LENGTH;
	str_out->pulse_incnt = *p;
	(*ai_step)++;
	p++;
	str_out->switch_incnt = *p;
	(*ai_step)++;
	p++;
	str_out->dcanalog_incnt = *p;
	(*ai_step)++;
	p++;
	str_out->switch_outcnt = *p;
	(*ai_step)++;
	p++;
	str_out->pn_cnt = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->zd_uprecv_maxlen = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->zd_upsend_maxlen = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	memcpy(str_out->mac, p, 6);
	*ai_step += 6;
	p += 6;
	str_out->comport_cnt = *p;
	(*ai_step)++;
	p++;
	if ((dat_len - *ai_step) < str_out->comport_cnt*12)
		return ERROR_FRAME_DATA_LENGTH;
	for (li_i = 0; li_i < str_out->comport_cnt; li_i++){
		memcpy(&str_out->str_comport[li_i].portnum_inf, p, 2);
		*ai_step += 2;
		p += 2;
		str_out->str_comport[li_i].maxbaud = (*(p+3) << 24) | (*(p+2) << 16) | (*(p+1) << 8) | *p;
		*ai_step += 4;
		p += 4;
		str_out->str_comport[li_i].equ_cnt = (*(p+1) << 8) | *p;
		*ai_step += 2;
		p += 2;
		str_out->str_comport[li_i].recv_cnt = (*(p+1) << 8) | *p;
		*ai_step += 2;
		p += 2;
		str_out->str_comport[li_i].send_cnt = (*(p+1) << 8) | *p;
		*ai_step += 2;
		p += 2;
	}

	return ERROR_SUCCESS;
}

int de_AFN09_FN2(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_io_com_portcfg lstr_ioportcfg;

	memset(&lstr_ioportcfg, 0, sizeof(lstr_ioportcfg));
	
	li_ret = de_AFN09_FN2_str(ac_p, ai_len, &lstr_ioportcfg, ai_step);
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


int de_AFN09_FN3_str(uchar *dat_in, int dat_len, str_zdother_cfg *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_i;

	if (dat_len < 35)
		return ERROR_FRAME_DATA_LENGTH;
	str_out->maxcld = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	str_out->maxzjz = *p;
	(*ai_step)++;
	p++;
	str_out->maxrw = *p;
	(*ai_step)++;
	p++;
	str_out->maxcdz = *p;
	(*ai_step)++;
	p++;
	str_out->maxfls = *p;
	(*ai_step)++;
	p++;
	str_out->cldmd = *p;
	(*ai_step)++;
	p++;
	str_out->zjzygmd = *p;
	(*ai_step)++;
	p++;
	str_out->zjzwgmd = *p;
	(*ai_step)++;
	p++;
	str_out->zjzygdnlmd = *p;
	(*ai_step)++;
	p++;
	str_out->zjzwgdnlmd = *p;
	(*ai_step)++;
	p++;
	str_out->keepday = *p;
	(*ai_step)++;
	p++;
	str_out->keepmonth = *p;
	(*ai_step)++;
	p++;
	str_out->maxfa = *p;
	(*ai_step)++;
	p++;
	str_out->maxxbcs = *p;
	(*ai_step)++;
	p++;
	str_out->maxzs = *p;
	(*ai_step)++;
	p++;
	str_out->maxzdh = *p;
	(*ai_step)++;
	p++;
	str_out->yhdlflag = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	for (li_i = 0; li_i < 16; li_i++){
		str_out->xlcount[li_i] = *p;
		(*ai_step)++;
		p++;
	}
	
	return ERROR_SUCCESS;
}

int de_AFN09_FN3(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_zdother_cfg lstr_othercfg;

	memset(&lstr_othercfg, 0, sizeof(lstr_othercfg));
	
	li_ret = de_AFN09_FN3_str(ac_p, ai_len, &lstr_othercfg, ai_step);
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


int de_AFN09_FN4_5_str(uchar *dat_in, int dat_len, str_zdsupport_DT *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_i, li_m;

	if (dat_len < 1)
		return ERROR_FRAME_DATA_LENGTH;
	str_out->DTcnt = *p;
	(*ai_step)++;
	p++;
	if ((dat_len - *ai_step) < str_out->DTcnt)
		return ERROR_FRAME_DATA_LENGTH;
	li_m = str_out->DTcnt > 31? 31:str_out->DTcnt;
	for (li_i = 0; li_i < li_m; li_i++){
		str_out->DTxflag[li_i] = *p;
		(*ai_step)++;
		p++;
	}

	return ERROR_SUCCESS;
}

int de_AFN09_FN4_5(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_zdsupport_DT lstr_support_DT;

	memset(&lstr_support_DT, 0, sizeof(lstr_support_DT));
	
	li_ret = de_AFN09_FN4_5_str(ac_p, ai_len, &lstr_support_DT, ai_step);
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


int de_AFN09_FN6_7_str(uchar *dat_in, int dat_len, str_afn09_f6_7 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_i, li_j, li_k, li_m, li_n;

	if (dat_len < 2)
		return ERROR_FRAME_DATA_LENGTH;
	str_out->yhdlflag = (*(p+1) << 8) | *p;
	*ai_step += 2;
	p += 2;
	for (li_i = 0; li_i < 16; li_i++){
		if ((str_out->yhdlflag >> li_i & 0x01)){
			str_out->str_val[li_i].xxcount = *p;
			(*ai_step)++;
			p++;
			li_k = str_out->str_val[li_i].xxcount > 31 ? 31 : str_out->str_val[li_i].xxcount;
			if ((dat_len - *ai_step) < li_k)
				return ERROR_FRAME_DATA_LENGTH;
			for (li_j = 0; li_j < li_k; li_j++){
				str_out->str_val[li_i].xxlbz[li_j] = *p;
				(*ai_step)++;
				p++;
			}
		}
	}
	
	return ERROR_SUCCESS;
}

int de_AFN09_FN6_7(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_afn09_f6_7 lstr_afn09_f6_7;

	memset(&lstr_afn09_f6_7, 0, sizeof(lstr_afn09_f6_7));
	
	li_ret = de_AFN09_FN6_7_str(ac_p, ai_len, &lstr_afn09_f6_7, ai_step);
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


int de_AFN09_FN8_str(uchar *dat_in, int dat_len, str_event_cfg *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_i, li_j, li_k, li_m, li_n;

	if (dat_len < 8)
		return ERROR_FRAME_DATA_LENGTH;
	memcpy(str_out->event_flg, p, 8);
	*ai_step += 8;
	p += 8;
	
	return ERROR_SUCCESS;
}

int de_AFN09_FN8(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_event_cfg lstr_event_cfg;

	memset(&lstr_event_cfg, 0, sizeof(lstr_event_cfg));
	
	li_ret = de_AFN09_FN8_str(ac_p, ai_len, &lstr_event_cfg, ai_step);
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

int de_AFN09_FN9_str(uchar *dat_in, int dat_len, str_commodule_ver *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 46)
		return ERROR_FRAME_DATA_LENGTH;
	memcpy(str_out->factory_id, p, 4);
	*ai_step += 4;
	p += 4;
	memcpy(str_out->module_type, p, 8);
	*ai_step += 8;
	p += 8;
	memcpy(str_out->soft_ver, p, 4);
	*ai_step += 4;
	p += 4;
	str_out->soft_dtisnull = getdataformat20(p, &str_out->soft_dt, &li_step);
	*ai_step += li_step;
	p += li_step;
	memcpy(str_out->hw_ver, p, 4);
	*ai_step += 4;
	p += 4;
	str_out->hw_dtisnull = getdataformat20(p, &str_out->hw_dt, &li_step);
	*ai_step += li_step;
	p += li_step;
	memcpy(str_out->sim_iccid, p, 20);
	*ai_step += 20;
	p += 20;
	
	return ERROR_SUCCESS;
}

int de_AFN09_FN9(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_commodule_ver lstr_commodule_ver;

	memset(&lstr_commodule_ver, 0, sizeof(lstr_commodule_ver));
	
	li_ret = de_AFN09_FN9_str(ac_p, ai_len, &lstr_commodule_ver, ai_step);
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


int de_AFN09_FN10_str(uchar *dat_in, int dat_len, str_locmodule_ver *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 15)
		return ERROR_FRAME_DATA_LENGTH;
	memcpy(str_out->module_addr, p, 6);
	*ai_step += 6;
	p += 6;
	memcpy(str_out->factory_id, p, 2);
	*ai_step += 2;
	p += 2;
	memcpy(str_out->chip_id, p, 2);
	*ai_step += 2;
	p += 2;
	str_out->ver_dt.day = *p;
	(*ai_step)++;
	p++;
	str_out->ver_dt.mon = *p;
	(*ai_step)++;
	p++;
	str_out->ver_dt.year = *p;
	(*ai_step)++;
	p++;
	memcpy(str_out->ver, p, 2);
	*ai_step += 2;
	p += 2;
	
	return ERROR_SUCCESS;
}

int de_AFN09_FN10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    	str_locmodule_ver lstr_locmodule_ver;

	memset(&lstr_locmodule_ver, 0, sizeof(lstr_locmodule_ver));
	
	li_ret = de_AFN09_FN10_str(ac_p, ai_len, &lstr_locmodule_ver, ai_step);
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



