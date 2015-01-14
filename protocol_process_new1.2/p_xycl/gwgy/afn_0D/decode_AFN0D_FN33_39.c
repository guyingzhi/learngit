#include "decode_AFN0D_FN33_39.h"


int decode_afn0D_F33_str(uchar *data, str_AFN0D_MAXP *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->isnull.MAXPZ = getdataformat23(p, &(astr_val->val.MAXPZ), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPZtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXPZtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPA = getdataformat23(p, &(astr_val->val.MAXPA), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPAtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXPAtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPB = getdataformat23(p, &(astr_val->val.MAXPB), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPBtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXPBtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPC = getdataformat23(p, &(astr_val->val.MAXPC), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXPCtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXPCtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    if ((astr_val->isnull.ZEROPZ = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.ZEROPZ = *(p + 1);
        astr_val->val.ZEROPZ = (astr_val->val.ZEROPZ << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    if ((astr_val->isnull.ZEROPA = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.ZEROPA = *(p + 1);
        astr_val->val.ZEROPA = (astr_val->val.ZEROPA << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    if ((astr_val->isnull.ZEROPB = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.ZEROPB = *(p + 1);
        astr_val->val.ZEROPB = (astr_val->val.ZEROPB << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    if ((astr_val->isnull.ZEROPC = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.ZEROPC = *(p + 1);
        astr_val->val.ZEROPC = (astr_val->val.ZEROPC << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       printf("************MAXPZ = %f\n ",astr_val->val.MAXPZ);
       printf("************MAXPA = %f\n ",astr_val->val.MAXPA);
       printf("************MAXPB = %f\n ",astr_val->val.MAXPB);
       printf("************MAXPC = %f\n ",astr_val->val.MAXPC);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F34_str(uchar *data, str_AFN0D_MAXXL *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->isnull.MAXXLZ = getdataformat23(p, &(astr_val->val.MAXXLZ), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLZtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXXLZtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLA = getdataformat23(p, &(astr_val->val.MAXXLA), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLAtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXXLAtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLB = getdataformat23(p, &(astr_val->val.MAXXLB), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLBtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXXLBtime), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLC = getdataformat23(p, &(astr_val->val.MAXXLC), &li_step);
    *ai_step += li_step;
    p += li_step;
    astr_val->isnull.MAXXLCtime = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXXLCtime), &li_step);
    *ai_step += li_step;
    p += li_step;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       printf("************MAXXLZ = %f\n ",astr_val->val.MAXXLZ);
       printf("************MAXXLA = %f\n ",astr_val->val.MAXXLA);
       printf("************MAXXLB = %f\n ",astr_val->val.MAXXLB);
       printf("************MAXXLC = %f\n ",astr_val->val.MAXXLC);
       printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F35_str(uchar *data, str_AFN0D_STU *astr_val, int *ai_step)
{
    uchar *p;
    int li_step, li_i;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    for (li_i = 0; li_i < 3; li_i++)
    {
        if ((astr_val->isnull.ceillimit[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.ceillimit[li_i] = *(p + 1);
            astr_val->val.ceillimit[li_i] = (astr_val->val.ceillimit[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
        if ((astr_val->isnull.lowerlimit[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.lowerlimit[li_i] = *(p + 1);
            astr_val->val.lowerlimit[li_i] = (astr_val->val.lowerlimit[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
        if ((astr_val->isnull.limit[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.limit[li_i] = *(p + 1);
            astr_val->val.limit[li_i] = (astr_val->val.limit[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
        if ((astr_val->isnull.lower[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.lower[li_i] = *(p + 1);
            astr_val->val.lower[li_i] = (astr_val->val.lower[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
        if ((astr_val->isnull.conformity[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.conformity[li_i] = *(p + 1);
            astr_val->val.conformity[li_i] = (astr_val->val.conformity[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
    }
    for (li_i = 0; li_i < 3; li_i++)
    {
        astr_val->isnull.MAXU[li_i] = getdataformat07(p, &(astr_val->val.MAXU[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
        astr_val->isnull.MAXUtime[li_i] = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXUtime[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
        astr_val->isnull.MINU[li_i] = getdataformat07(p, &(astr_val->val.MINU[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
        astr_val->isnull.MINUtime[li_i] = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MINUtime[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
    for (li_i = 0; li_i < 3; li_i++)
    {
        astr_val->isnull.AVGU[li_i] = getdataformat07(p, &(astr_val->val.AVGU[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
    }
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       for(li_i= 0;li_i<3;li_i++)
      {
            printf("******ceillimit[li_i] =  %d  " ,astr_val->val.ceillimit[li_i]);
            printf("******lowerlimit[li_i] =  %d  " ,astr_val->val.lowerlimit[li_i]);
            printf("******limit[li_i] =  %d  " ,astr_val->val.limit[li_i]);
            printf("******lower[li_i] =  %d  " ,astr_val->val.lower[li_i]);
      }
              
      printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F36_str(uchar *data, str_AFN0D_UNBALANCE *astr_val, int *ai_step)
{
    uchar *p;
    int li_step,li_i;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    if ((astr_val->isnull.Uval = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.Uval = *(p + 1);
        astr_val->val.Uval = (astr_val->val.Uval << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    if ((astr_val->isnull.Ival = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.Ival = *(p + 1);
        astr_val->val.Ival = (astr_val->val.Ival << 8) + *p;
    }
    *ai_step += 2;
    p += 2;

    astr_val->isnull.Ivalue = getdataformat05(p, &(astr_val->val.Ivalue), &li_step);
    *ai_step += li_step;
    p += li_step;

    astr_val->isnull.Ivaluetime = getdataformat17(p, &(astr_val->val.TD), &(astr_val->val.Ivaluetime), &li_step);
    *ai_step += li_step;
    p += li_step;

    astr_val->isnull.Uvalue = getdataformat05(p, &(astr_val->val.Uvalue), &li_step);
    *ai_step += li_step;
    p += li_step;

    astr_val->isnull.Uvaluetime = getdataformat17(p, &(astr_val->val.TD),&(astr_val->val.Uvaluetime), &li_step);
    *ai_step += li_step;
    p += li_step;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       for(li_i= 0;li_i<3;li_i++)
      {
            printf("******Uval =  %d  " ,astr_val->val.Uval);
            printf("******Ival=  %d  " ,astr_val->val.Ival);
      }
              
      printf("测试通过\n");

    return ERROR_SUCCESS;
}

int decode_afn0D_F37_str(uchar *data, str_AFN0D_STI *astr_val, int *ai_step)
{
    uchar *p;
    int li_step, li_i;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    for (li_i = 0; li_i < 3; li_i++)
    {
        if ((astr_val->isnull.ceillimit[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.ceillimit[li_i] = *(p + 1);
            astr_val->val.ceillimit[li_i] = (astr_val->val.ceillimit[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
        if ((astr_val->isnull.limit[li_i] = dataisnull(p, 2)) == DATA_ISNOTNULL)
        {
            astr_val->val.limit[li_i] = *(p + 1);
            astr_val->val.limit[li_i] = (astr_val->val.limit[li_i] << 8) + *p;
        }
        *ai_step += 2;
        p += 2;
    }
    if ((astr_val->isnull.limit[3] = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.limit[3] = *(p + 1);
        astr_val->val.limit[3] = (astr_val->val.limit[3] << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    for (li_i = 0; li_i < 4; li_i++)
    {
        astr_val->isnull.MAXI[li_i] = getdataformat25(p, &(astr_val->val.MAXI[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;
        astr_val->isnull.MAXItime[li_i] = getdataformat18(p, &(astr_val->val.TD), &(astr_val->val.MAXItime[li_i]), &li_step);
        *ai_step += li_step;
        p += li_step;

    }
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
       for(li_i= 0;li_i<3;li_i++)
      {
            printf("******ceillimit[li_i] =  %d  " ,astr_val->val.ceillimit[li_i]);
      }
      for(li_i= 0;li_i<4;li_i++)
      {
            printf("******limit[li_i] =  %d  " ,astr_val->val.limit[li_i]);
            printf("******MAXI[li_i] =  %f  " ,astr_val->val.MAXI[li_i]);
      }       
              
      printf("测试通过\n");
  
    return ERROR_SUCCESS;
}

int decode_afn0D_F38_str(uchar *data, str_AFN0D_APP *astr_val, int *ai_step)
{
    uchar *p;
    int li_step;
    p = data;
    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);
    *ai_step = li_step;
    p += li_step;
    if ((astr_val->isnull.ceillimit = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.ceillimit = *(p + 1);
        astr_val->val.ceillimit = (astr_val->val.ceillimit << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
    if ((astr_val->isnull.limit = dataisnull(p, 2)) == DATA_ISNOTNULL)
    {
        astr_val->val.limit = *(p + 1);
        astr_val->val.limit = (astr_val->val.limit << 8) + *p;
    }
    *ai_step += 2;
    p += 2;
	printf("*******************解析数据结构体完成************ \n");
	
      printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,
             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min); 
      printf("************ceillimit = %d\n ",astr_val->val.ceillimit);
     
      printf("************limit = %d\n ",astr_val->val.limit);
      printf("测试通过\n");

    return ERROR_SUCCESS;
}

/*月负载率统计*/
int decode_afn0D_F39_str(uchar *data, str_AFN0D_39 *astr_val, int *ai_step)
{
    uchar *p, lc_i;
    int li_step;
    p = data;
    astr_val->DTisnull = getdataformat21(p, &(astr_val->DT), &li_step);
    *ai_step = li_step;
    p += li_step;
    astr_val->MAX_loadisnull= getdataformat05(p, &(astr_val->MAX_load), &li_step);
    *ai_step += li_step;
    p += li_step;
    
    astr_val->MAX_load_Tisnull= getdataformat18(p, &(astr_val->DT),&(astr_val->MAX_load_T), &li_step);
    *ai_step += li_step;
    p += li_step;
        astr_val->MIN_loadisnull= getdataformat05(p, &(astr_val->MIN_load), &li_step);
    *ai_step += li_step;
    p += li_step;
    
    astr_val->MIN_load_Tisnull= getdataformat18(p, &(astr_val->DT),&(astr_val->MIN_load_T), &li_step);
    *ai_step += li_step;
    p += li_step;
	printf("*******************解析数据结构体完成************ \n");
	
       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->DT.year,
             astr_val->DT.mon,astr_val->DT.day,astr_val->DT.hour,astr_val->DT.min); 
       printf("************MAX_load = %d\n ",astr_val->MAX_load);
       printf("************MIN_load = %d\n ",astr_val->MIN_load);
       printf("测试通过\n");
 
    return ERROR_SUCCESS;
}


int de_AFN0D_FN33(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_MAXP lstr_afn0D_F33_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F33_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F33_val.isnull));

	memset(&( lstr_afn0D_F33_val.val), 0, sizeof( lstr_afn0D_F33_val.val));

	li_ret = decode_afn0D_F33_str(ac_p,  & lstr_afn0D_F33_val, ai_step);

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


int de_AFN0D_FN34(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_MAXXL lstr_afn0D_F34_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F34_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F34_val.isnull));

	memset(&( lstr_afn0D_F34_val.val), 0, sizeof( lstr_afn0D_F34_val.val));

	li_ret = decode_afn0D_F34_str(ac_p,  & lstr_afn0D_F34_val, ai_step);

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

int de_AFN0D_FN35(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_STU lstr_afn0D_F35_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F35_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F35_val.isnull));

	memset(&( lstr_afn0D_F35_val.val), 0, sizeof( lstr_afn0D_F35_val.val));

	li_ret = decode_afn0D_F35_str(ac_p,  & lstr_afn0D_F35_val, ai_step);

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

int de_AFN0D_FN36(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_UNBALANCE lstr_afn0D_F36_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F36_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F36_val.isnull));

	memset(&( lstr_afn0D_F36_val.val), 0, sizeof( lstr_afn0D_F36_val.val));

	li_ret = decode_afn0D_F36_str(ac_p,  & lstr_afn0D_F36_val, ai_step);

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


int de_AFN0D_FN37(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_STI lstr_afn0D_F37_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F37_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F37_val.isnull));

	memset(&( lstr_afn0D_F37_val.val), 0, sizeof( lstr_afn0D_F37_val.val));

	li_ret = decode_afn0D_F37_str(ac_p,  & lstr_afn0D_F37_val, ai_step);

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


int de_AFN0D_FN38(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_APP lstr_afn0D_F38_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F38_val.isnull, DATA_ISNULL, sizeof( lstr_afn0D_F38_val.isnull));

	memset(&( lstr_afn0D_F38_val.val), 0, sizeof( lstr_afn0D_F38_val.val));

	li_ret = decode_afn0D_F38_str(ac_p,  & lstr_afn0D_F38_val, ai_step);

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

int de_AFN0D_FN39(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)

{
	str_AFN0D_39 lstr_afn0D_F39_val;

	uchar *p;
    	int li_i, li_j, li_m=0;
    	int li_ret;
	char lc_rwbh[32]={0};

	memset(& lstr_afn0D_F39_val, DATA_ISNULL, sizeof( lstr_afn0D_F39_val));

	li_ret = decode_afn0D_F39_str(ac_p,  & lstr_afn0D_F39_val, ai_step);

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










