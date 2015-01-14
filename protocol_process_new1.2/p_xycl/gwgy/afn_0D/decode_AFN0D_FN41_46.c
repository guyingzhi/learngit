#include "decode_AFN0D_FN41_46.h"


int decode_afn0D_F41_str(uchar *data, str_AFN0D_F41 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    for(li_i= 0;li_i<9;li_i++)
    {
		astr_val->TRSJ[li_i] = (*(p+3)<<24) + (*(p+2)<<16)+(*(p+1)<<8)+*p;
		*ai_step +=4;
		p+=4;
    }
    for(li_i= 0;li_i<9;li_i++)
    {
		astr_val->TRCS[li_i] = (*(p+3)<<24) + (*(p+2)<<16)+(*(p+1)<<8)+*p;
		*ai_step +=4;
		p+=4;
    }	
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       for(li_i = 0;li_i<9;li_i++)
        {
            printf("************TRSJ[li_i] = %f\n ",astr_val->TRSJ[li_i]);
            printf("************TRCS[li_i] = %f\n ",astr_val->TRCS[li_i]);
        }
       printf("测试通过\n");

 
    return ERROR_SUCCESS;
}

int decode_afn0D_F42_str(uchar *data, str_AFN0D_F42 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    
    astr_val->BCDN_Disnull = getdataformat13(p,&(astr_val->BCDN_D),&li_step);
    *ai_step += li_step;
    p+= li_step;

    astr_val->BCDN_Misnull = getdataformat13(p,&(astr_val->BCDN_M),&li_step);
    *ai_step += li_step;
    p+= li_step;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************BCDN_D = %f\n ",astr_val->BCDN_D);
        printf("************BCDN_M = %f\n ",astr_val->BCDN_M);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F43_str(uchar *data, str_AFN0D_F43 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;

    if ((astr_val->LJSJ_1isnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
            astr_val->LJSJ_1 = (*(p+1)<<8)  + *p;
    }
    *ai_step +=2;
    p+=2;

     if ((astr_val->LJSJ_2isnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
            astr_val->LJSJ_2 = (*(p+1)<<8)  + *p;
    }
    *ai_step +=2;
    p+=2;

    if ((astr_val->LJSJ_3isnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
            astr_val->LJSJ_3 = (*(p+1)<<8)  + *p;
    }
    *ai_step +=2;
    p+=2;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************LJSJ_1= %d\n ",astr_val->LJSJ_1);
       printf("************LJSJ_2= %d\n ",astr_val->LJSJ_2);
       printf("************LJSJ_3= %d\n ",astr_val->LJSJ_3);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F44_str(uchar *data, str_AFN0D_F44 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    
     if ((astr_val->LJSJ_1isnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
            astr_val->LJSJ_1 = (*(p+1)<<8)  + *p;
    }
    *ai_step +=2;
    p+=2;

     if ((astr_val->LJSJ_2isnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
            astr_val->LJSJ_2 = (*(p+1)<<8)  + *p;
    }
    *ai_step +=2;
    p+=2;

    if ((astr_val->LJSJ_3isnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
            astr_val->LJSJ_3 = (*(p+1)<<8)  + *p;
    }
    *ai_step +=2;
    p+=2;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************LJSJ_1= %d\n ",astr_val->LJSJ_1);
       printf("************LJSJ_2= %d\n ",astr_val->LJSJ_2);
       printf("************LJSJ_3= %d\n ",astr_val->LJSJ_3);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F45_str(uchar *data, str_AFN0D_F45 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    
    astr_val->Copper_YGDNisnull = getdataformat14(p, &(astr_val->Copper_YGDN), &li_step);
    *ai_step = li_step;
    p += li_step;

    astr_val->Iron_YGDNisnull = getdataformat14(p, &(astr_val->Iron_YGDN), &li_step);
    *ai_step = li_step;
    p += li_step;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************Copper_YGDN= %f\n ",astr_val->Copper_YGDN);
       printf("************Iron_YGDN= %f\n ",astr_val->Iron_YGDN);
       printf("测试通过\n");
 
    return ERROR_SUCCESS;
}

int decode_afn0D_F46_str(uchar *data, str_AFN0D_F46 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    
    astr_val->Copper_YGDNisnull = getdataformat14(p, &(astr_val->Copper_YGDN), &li_step);
    *ai_step = li_step;
    p += li_step;

    astr_val->Iron_YGDNisnull = getdataformat14(p, &(astr_val->Iron_YGDN), &li_step);
    *ai_step = li_step;
    p += li_step;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************Copper_YGDN= %f\n ",astr_val->Copper_YGDN);
       printf("************Iron_YGDN= %f\n ",astr_val->Iron_YGDN);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int de_AFN0D_FN41(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F41 lstr_afn0D_F41_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
	memset(&lstr_afn0D_F41_val, 0, sizeof( lstr_afn0D_F41_val));

	li_ret = decode_afn0D_F41_str(ac_p,  & lstr_afn0D_F41_val, ai_step);

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

int de_AFN0D_FN42(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F42 lstr_afn0D_F42_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_F42_val, 0, sizeof( lstr_afn0D_F42_val));

	li_ret = decode_afn0D_F42_str(ac_p,  & lstr_afn0D_F42_val, ai_step);

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

int de_AFN0D_FN43(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F43 lstr_afn0D_F43_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_F43_val, 0, sizeof( lstr_afn0D_F43_val));


	li_ret = decode_afn0D_F43_str(ac_p,  & lstr_afn0D_F43_val, ai_step);

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

int de_AFN0D_FN44(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F44 lstr_afn0D_F44_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_F44_val, 0, sizeof( lstr_afn0D_F44_val));

	li_ret = decode_afn0D_F44_str(ac_p,  & lstr_afn0D_F44_val, ai_step);

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

int de_AFN0D_FN45(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F45 lstr_afn0D_F45_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_F45_val, 0, sizeof( lstr_afn0D_F45_val));

	li_ret = decode_afn0D_F45_str(ac_p,  & lstr_afn0D_F45_val, ai_step);

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


int de_AFN0D_FN46(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F46 lstr_afn0D_F46_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(&lstr_afn0D_F46_val, 0, sizeof( lstr_afn0D_F46_val));
      memset(&lstr_afn0D_F46_val.Copper_YGDNisnull, DATA_ISNULL, sizeof( lstr_afn0D_F46_val.Copper_YGDNisnull));
      memset(&lstr_afn0D_F46_val.Iron_YGDNisnull, DATA_ISNULL, sizeof( lstr_afn0D_F46_val.Iron_YGDNisnull));

	li_ret = decode_afn0D_F46_str(ac_p,  & lstr_afn0D_F46_val, ai_step);

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



