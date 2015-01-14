#include "decode_AFN0D_FN49_54.h"    

int decode_afn0D_F49_str(uchar *data, str_AFN0D_ONPOWER *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.TD = getdataformat20(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;

        astr_val->val.onpowertime = *(p + 1);
        astr_val->val.onpowertime = (astr_val->val.onpowertime << 8) + *p;

    *ai_step += 2;
    p += 2;

        astr_val->val.resettime = *(p + 1);
        astr_val->val.resettime = (astr_val->val.resettime << 8) + *p;
    
    *ai_step += 2;
    p += 2;

	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       printf("************onpowertime = %d\n ",astr_val->val.onpowertime);
       printf("************resettime = %d\n ",astr_val->val.resettime);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F50_str(uchar *data, str_AFN0D_CONTROL *astr_val, int *ai_step)
{
    uchar *p, lc_i;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    for (lc_i = 0; lc_i < 4; lc_i++)
        astr_val->times[lc_i] = *(p + lc_i);
    *ai_step += 4;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       for(li_i = 0;li_i<4;li_i++)
       {
           printf("************times[li_i] = %d\n ",astr_val->times[li_i]); 
       }
       
       printf("测试通过\n");
 
    return ERROR_SUCCESS;
}

int decode_afn0D_F51_str(uchar *data, str_AFN0D_ONPOWER *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    if ((astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step)) == 0)
    *ai_step = li_step;
    p += li_step;

        astr_val->val.onpowertime = *(p + 1);
        astr_val->val.onpowertime = (astr_val->val.onpowertime << 8) + *p;
    
    *ai_step += 2;
    p += 2;

        astr_val->val.resettime = *(p + 1);
        astr_val->val.resettime = (astr_val->val.resettime << 8) + *p;
    
    *ai_step += 2;
    p += 2;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       printf("************onpowertime = %d\n ",astr_val->val.onpowertime);
       printf("************resettime = %d\n ",astr_val->val.resettime);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F52_str(uchar *data, str_AFN0D_CONTROL *astr_val, int *ai_step)
{
    uchar *p, lc_i;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    for (lc_i = 0; lc_i < 4; lc_i++)
        astr_val->times[lc_i] = *(p + lc_i);
    *ai_step += 4;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       for(li_i = 0;li_i<4;li_i++)
       {
           printf("************times[li_i] = %d\n ",astr_val->times[li_i]); 
       }
       
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F53_str(uchar *data, str_AFN0D_F53F54 *astr_val, int *ai_step)
{
    uchar *p, lc_i;
    int li_step;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;

    if ((astr_val->datacountisnull = dataisnull(p, 4)) == DATA_ISNOTNULL)
    {
        astr_val->datacount = *(p + 3);
        astr_val->datacount = (astr_val->datacount << 8) + *(p+2);
        astr_val->datacount = (astr_val->datacount << 8) + *(p+1);
        astr_val->datacount = (astr_val->datacount << 8) + *p;
    }
    *ai_step += 4;
    p += 4;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************datacount= %d\n ",astr_val->datacount);
       printf("测试通过\n");
 
    return ERROR_SUCCESS;
}

int decode_afn0D_F54_str(uchar *data, str_AFN0D_F53F54 *astr_val, int *ai_step)
{
    uchar *p, lc_i;
    int li_step;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;

    if ((astr_val->datacountisnull = dataisnull(p, 4)) == DATA_ISNOTNULL)
    {
        astr_val->datacount = *(p + 3);
        astr_val->datacount = (astr_val->datacount << 8) + *(p+2);
        astr_val->datacount = (astr_val->datacount << 8) + *(p+1);
        astr_val->datacount = (astr_val->datacount << 8) + *p;
    }
    *ai_step += 4;
    p += 4;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************datacount= %d\n ",astr_val->datacount);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int de_AFN0D_FN49(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_ONPOWER lstr_afn0D_F49_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F49_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F49_val.isnull));

	memset(&( lstr_afn0D_F49_val.val), 0, sizeof( lstr_afn0D_F49_val.val));

	li_ret = decode_afn0D_F49_str(ac_p,  & lstr_afn0D_F49_val, ai_step);

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

int de_AFN0D_FN50(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_CONTROL lstr_afn0D_F50_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F50_val, 0, sizeof( lstr_afn0D_F50_val));

	li_ret = decode_afn0D_F50_str(ac_p,  & lstr_afn0D_F50_val, ai_step);

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

int de_AFN0D_FN51(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_ONPOWER lstr_afn0D_F51_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F51_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F51_val.isnull));

	memset(&( lstr_afn0D_F51_val.val), 0, sizeof( lstr_afn0D_F51_val.val));

	li_ret = decode_afn0D_F51_str(ac_p, & lstr_afn0D_F51_val, ai_step);

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

int de_AFN0D_FN52(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_CONTROL lstr_afn0D_F52_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F52_val, 0, sizeof( lstr_afn0D_F52_val));


	li_ret = decode_afn0D_F52_str(ac_p,  & lstr_afn0D_F52_val, ai_step);

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


int de_AFN0D_FN53(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F53F54 lstr_afn0D_F53_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F53_val, 0, sizeof( lstr_afn0D_F53_val));
      memset(& lstr_afn0D_F53_val.datacountisnull, DATA_ISNULL, sizeof(lstr_afn0D_F53_val.datacountisnull));
      memset(& lstr_afn0D_F53_val.TDisnull, DATA_ISNULL, sizeof(lstr_afn0D_F53_val.TDisnull));

	li_ret = decode_afn0D_F53_str(ac_p, & lstr_afn0D_F53_val, ai_step);

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

int de_AFN0D_FN54(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F53F54 lstr_afn0D_F54_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F54_val, 0, sizeof( lstr_afn0D_F54_val));
      memset(& lstr_afn0D_F54_val.datacountisnull, DATA_ISNULL, sizeof(lstr_afn0D_F54_val.datacountisnull));
      memset(& lstr_afn0D_F54_val.TDisnull, DATA_ISNULL, sizeof(lstr_afn0D_F54_val.TDisnull));

	li_ret = decode_afn0D_F54_str(ac_p,  & lstr_afn0D_F54_val, ai_step);

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

