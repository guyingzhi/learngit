#include "decode_AFN0D_FN57_66.h"

int decode_afn0D_F57_str(uchar *data, str_AFN0D_F57 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->YGGV_Maxisnull = getdataformat02(p,&(astr_val->YGGV_Max),&li_step);
    *ai_step += li_step;
    p+=li_step;
       astr_val->YGGV_Max_Tisnull = getdataformat18(p,&(astr_val->TD),&(astr_val->YGGV_Max_T),&li_step);
    *ai_step += li_step;
    p+=li_step;
        astr_val->YGGV_Minisnull = getdataformat02(p,&(astr_val->YGGV_Min),&li_step);
    *ai_step += li_step;
    p+=li_step;
        astr_val->YGGV_Min_Tisnull = getdataformat18(p,&(astr_val->TD),&(astr_val->YGGV_Min_T),&li_step);
    *ai_step += li_step;
    p+=li_step;
    astr_val->YGGV_zero = (*(p+1)<<8) + *p;
    *ai_step += 2;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************YGGV_Max = %f\n ",astr_val->YGGV_Max);
       printf("************YGGV_Min = %f\n ",astr_val->YGGV_Min);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F58F59_str(uchar *data, str_AFN0D_F58F59 *astr_val, int *ai_step)
{
    uchar *p,*ac_unit;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat20(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->FLM = *p;
    (*ai_step) +=1;
    p++;
    astr_val->DN_Totalisnull = getdataformat03(p, &(astr_val->DN_Total),  ac_unit, &li_step);
    (*ai_step) += li_step;
    p += li_step;
    for(li_i=0; li_i<astr_val->FLM; li_i++)
    {
        astr_val->DNisnull[li_i] = getdataformat03(p, &(astr_val->DN[li_i]),  ac_unit, &li_step);
    (*ai_step) += li_step;
    p += li_step;
    }
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************FLM = %d\n ",astr_val->FLM);
       printf("************DN_Total = %d\n ",astr_val->DN_Total);
       for(li_i = 0;li_i<astr_val->FLM;li_i ++)
        {
             printf("************DN[%d] = %d\n ",li_i,astr_val->DN[li_i]);
       }
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F60_str(uchar *data, str_AFN0D_F60 *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->YGGV_Maxisnull = getdataformat02(p,&(astr_val->YGGV_Max),&li_step);
    *ai_step += li_step;
    p+=li_step;
       astr_val->YGGV_Max_Tisnull = getdataformat18(p,&(astr_val->TD),&(astr_val->YGGV_Max_T),&li_step);
    *ai_step += li_step;
    p+=li_step;
        astr_val->YGGV_Minisnull = getdataformat02(p,&(astr_val->YGGV_Min),&li_step);
    *ai_step += li_step;
    p+=li_step;
        astr_val->YGGV_Min_Tisnull = getdataformat18(p,&(astr_val->TD),&(astr_val->YGGV_Min_T),&li_step);
    *ai_step += li_step;
    p+=li_step;
    astr_val->YGGV_zero = (*(p+1)<<8) + *p;
    *ai_step += 2;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************YGGV_Max = %f\n ",astr_val->YGGV_Max);
       printf("************YGGV_Min = %f\n ",astr_val->YGGV_Min);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}


int decode_afn0D_F61F62_str(uchar *data, str_AFN0D_F61F62 *astr_val, int *ai_step)
{
             printf("^^^^^^**^^^^^^^^**开始解析结构体************\n");

    uchar *p, ac_unit;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    
    astr_val->FLM = *p;
    (*ai_step) +=1;
    p++;
   
    for(li_i=0; li_i<=astr_val->FLM; li_i++)
    {
        if((astr_val->DNisnull[li_i] = getdataformat03(p, &(astr_val->DN[li_i]),  &ac_unit, &li_step))==0);
         if (ac_unit)
                astr_val->DN[li_i] = astr_val->DN[li_i] * 1000;
         (*ai_step) += li_step;
        p += li_step;
    }
       
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************FLM = %d\n ",astr_val->FLM);
       for(li_i = 0;li_i<=astr_val->FLM;li_i ++)
        {
             printf("************DN[%d] = %d\n ",li_i,astr_val->DN[li_i]);
       }
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F65F66_str(uchar *data, str_AFN0D_F65F66 *astr_val, int *ai_step)
{
    uchar *p,ac_unit;
    int li_step,li_i;
    p = data;
    astr_val->TDisnull = getdataformat21(p, &(astr_val->TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    if ((astr_val->Time_Totalisnull= dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->Time_Total = (*(p+1)<<8)+*p;
    }
    *ai_step +=2;
    p+=2;
     if ((astr_val->DN_Totalisnull= getdataformat03(p, &(astr_val->DN_Total), &ac_unit, &li_step)) == 0)
          if (ac_unit)
              astr_val->DN_Total = astr_val->DN_Total* 1000;
    *ai_step = *ai_step + li_step;

	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->TD.year,
             astr_val->TD.mon,astr_val->TD.day,astr_val->TD.hour,astr_val->TD.min); 
       printf("************Time_Total = %d\n ",astr_val->Time_Total);
       printf("************DN_Total = %d\n ",astr_val->DN_Total);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}


int de_AFN0D_FN57(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F57 lstr_afn0D_F57_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

       memset(& lstr_afn0D_F57_val, 0, sizeof( lstr_afn0D_F57_val));
      memset(&lstr_afn0D_F57_val.TDisnull,DATA_ISNULL,sizeof(lstr_afn0D_F57_val.TDisnull));
      memset(&lstr_afn0D_F57_val.YGGV_Maxisnull,DATA_ISNULL,sizeof(lstr_afn0D_F57_val.YGGV_Maxisnull));
      memset(&lstr_afn0D_F57_val.YGGV_Max_Tisnull,DATA_ISNULL,sizeof(lstr_afn0D_F57_val.YGGV_Max_Tisnull));
      memset(&lstr_afn0D_F57_val.YGGV_Minisnull,DATA_ISNULL,sizeof(lstr_afn0D_F57_val.YGGV_Minisnull));
      memset(&lstr_afn0D_F57_val.YGGV_Min_Tisnull,DATA_ISNULL,sizeof(lstr_afn0D_F57_val.YGGV_Min_Tisnull));

	li_ret = decode_afn0D_F57_str(ac_p,  & lstr_afn0D_F57_val, ai_step);

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

int de_AFN0D_FN58F59(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F58F59 lstr_afn0D_F58F59_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};
    
	memset(& lstr_afn0D_F58F59_val, 0, sizeof( lstr_afn0D_F58F59_val));
       memset(&lstr_afn0D_F58F59_val.DNisnull,DATA_ISNULL,sizeof(lstr_afn0D_F58F59_val.DNisnull));
       memset(&lstr_afn0D_F58F59_val.DN_Totalisnull,DATA_ISNULL,sizeof(lstr_afn0D_F58F59_val.DN_Totalisnull));
       memset(&lstr_afn0D_F58F59_val.TDisnull,DATA_ISNULL,sizeof(lstr_afn0D_F58F59_val.TDisnull));

	li_ret = decode_afn0D_F58F59_str(ac_p,  & lstr_afn0D_F58F59_val, ai_step);

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

int de_AFN0D_FN60(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F60 lstr_afn0D_F60_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

      memset(& lstr_afn0D_F60_val, 0, sizeof( lstr_afn0D_F60_val));
      memset(&lstr_afn0D_F60_val.TDisnull,DATA_ISNULL,sizeof(lstr_afn0D_F60_val.TDisnull));
      memset(&lstr_afn0D_F60_val.YGGV_Maxisnull,DATA_ISNULL,sizeof(lstr_afn0D_F60_val.YGGV_Maxisnull));
      memset(&lstr_afn0D_F60_val.YGGV_Max_Tisnull,DATA_ISNULL,sizeof(lstr_afn0D_F60_val.YGGV_Max_Tisnull));
      memset(&lstr_afn0D_F60_val.YGGV_Minisnull,DATA_ISNULL,sizeof(lstr_afn0D_F60_val.YGGV_Minisnull));
      memset(&lstr_afn0D_F60_val.YGGV_Min_Tisnull,DATA_ISNULL,sizeof(lstr_afn0D_F60_val.YGGV_Min_Tisnull));

	li_ret = decode_afn0D_F60_str(ac_p,  & lstr_afn0D_F60_val, ai_step);

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

int de_AFN0D_FN61F62(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F61F62 lstr_afn0D_F61F62_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

       memset(& lstr_afn0D_F61F62_val, 0, sizeof( lstr_afn0D_F61F62_val));
       memset(lstr_afn0D_F61F62_val.DNisnull,DATA_ISNULL,sizeof(lstr_afn0D_F61F62_val.DNisnull));
       memset(&lstr_afn0D_F61F62_val.TDisnull,DATA_ISNULL,sizeof(lstr_afn0D_F61F62_val.TDisnull));

	li_ret = decode_afn0D_F61F62_str(ac_p,  & lstr_afn0D_F61F62_val, ai_step);

	if (li_ret != ERROR_SUCCESS ){
		//组错误的内部报文
/*		get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);  //组内部报文
		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;*/
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

int de_AFN0D_FN65F66(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_F65F66 lstr_afn0D_F65F66_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

      memset(& lstr_afn0D_F65F66_val, 0, sizeof( lstr_afn0D_F65F66_val));
      memset(&lstr_afn0D_F65F66_val.DN_Totalisnull,DATA_ISNULL,sizeof(lstr_afn0D_F65F66_val.DN_Totalisnull));
      memset(&lstr_afn0D_F65F66_val.TDisnull,DATA_ISNULL,sizeof(lstr_afn0D_F65F66_val.TDisnull));
      memset(&lstr_afn0D_F65F66_val.Time_Totalisnull,DATA_ISNULL,sizeof(lstr_afn0D_F65F66_val.Time_Totalisnull));

	li_ret = decode_afn0D_F65F66_str(ac_p,  & lstr_afn0D_F65F66_val, ai_step);

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


