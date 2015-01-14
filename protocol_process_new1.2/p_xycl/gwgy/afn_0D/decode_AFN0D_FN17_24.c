#include "decode_AFN0D_FN17_24.h"/*********** ������ԼD�����ݱ���(������)*************    data   ����ָ��    ai_step  ���ĳ���    str_AFN0D_CODE        str_AFN0D_CODE_VAL            TD         ʱ��            CBSJ       ����ʱ��            FLS        ������            Pcode      �й���������            Qcode      �޹���������            Q12code    1��2�����޹���������            Q34code    3��4�����޹���������        str_AFN0D_CODE_ISNULL            TD         ʱ���пձ�־            CBSJ       ����ʱ���пձ�־            Pcode      �й����������пձ�־            Qcode      �޹����������пձ�־            Q12code    1��2�����޹����������пձ�־            Q34code    3��4�����޹����������пձ�־    ����        1          ��������        -4         ���������*******************************************/int decode_afn0D_CODE_M(uchar *data, str_AFN0D_CODE *astr_val, int *ai_step){    uchar *p;    int li_step, li_i;    p = data;    for (li_i = 0; li_i < 15; li_i++)    {        astr_val->isnull.Pcode[li_i] = DATA_ISNULL;        astr_val->isnull.Qcode[li_i] = DATA_ISNULL;        astr_val->isnull.Q12code[li_i] = DATA_ISNULL;        astr_val->isnull.Q34code[li_i] = DATA_ISNULL;    }    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);    *ai_step = li_step;    p += li_step;    astr_val->isnull.CBSJ = getdataformat15(p, &(astr_val->val.CBSJ), &li_step);    *ai_step += li_step;    p += li_step;    astr_val->val.FLS = *p;    (*ai_step)++;    p++;    if (astr_val->val.FLS > 14)        return ERROR_DATA_INVALID;    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.Pcode[li_i] = getdataformat14(p, &(astr_val->val.Pcode[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.Qcode[li_i] = getdataformat11(p, &(astr_val->val.Qcode[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.Q12code[li_i] = getdataformat11(p, &(astr_val->val.Q12code[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.Q34code[li_i] = getdataformat11(p, &(astr_val->val.Q34code[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }	 printf("*******************�������ݽṹ�����************ \n");	       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min);        printf("*********year = %d,month = %d, day =%d,FLS = %d**********\n",astr_val->val.CBSJ.year,             astr_val->val.CBSJ.mon,astr_val->val.CBSJ.day,astr_val->val.FLS);       for(li_i = 0;li_i<astr_val->val.FLS;li_i++)       {            printf("Pcode[li_i]  = %f  ",astr_val->val.Pcode[li_i]);            printf("Qcode[li_i]  = %f  ",astr_val->val.Qcode[li_i]);            printf("Q12code[li_i]  = %f  ",astr_val->val.Q12code[li_i]);            printf("Q34code[li_i]  = %f  ",astr_val->val.Q34code[li_i]);       }   printf("����ͨ��\n");   return ERROR_SUCCESS;}/*********** ������ԼD����������(��)*************    data   ����ָ��    ai_step  ���ĳ���    str_AFN0D_XL        str_AFN0D_XL_VAL            TD        ʱ��            CBSJ      ����ʱ��            FLS       ������            PXL       �й���������            PXLSJ     �й���������ʱ������            QXL       �޹���������            QXLSJ     �޹���������ʱ������        str_AFN0D_XL_ISNULL            TD        ʱ���пձ�־            CBSJ      ����ʱ���пձ�־            FLS       �������пձ�־            PXL       �й������пձ�־����            PXLSJ     �й���������ʱ���пձ�־����            QXL       �޹������пձ�־����            QXLSJ     �޹���������ʱ���пձ�־����    ����        1          ��������        -4         ���������*******************************************/int decode_afn0D_XL_M(uchar *data, str_AFN0D_XL *astr_val, int *ai_step){    uchar *p;    int li_step, li_i;    for (li_i = 0; li_i < 15; li_i++)    {        astr_val->isnull.PXL[li_i] = DATA_ISNULL;        astr_val->isnull.PXLSJ[li_i] = DATA_ISNULL;        astr_val->isnull.QXL[li_i] = DATA_ISNULL;        astr_val->isnull.QXLSJ[li_i] = DATA_ISNULL;    }    p = data;    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);    *ai_step = li_step;    p += li_step;    astr_val->isnull.CBSJ = getdataformat15(p, &(astr_val->val.CBSJ), &li_step);    *ai_step += li_step;    p += li_step;    astr_val->val.FLS = *p;    (*ai_step)++;    p++;    if (astr_val->val.FLS > 14)        return ERROR_DATA_INVALID;    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.PXL[li_i] = getdataformat23(p, &(astr_val->val.PXL[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.PXLSJ[li_i] = getdataformat17(p, &(astr_val->val.TD), &(astr_val->val.PXLSJ[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.QXL[li_i] = getdataformat23(p, &(astr_val->val.QXL[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.QXLSJ[li_i] = getdataformat17(p, &(astr_val->val.TD), &(astr_val->val.QXLSJ[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }	 printf("*******************�������ݽṹ�����************ \n");	       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min);        printf("*********year = %d,month = %d, day =%d,FLS = %d**********\n",astr_val->val.CBSJ.year,             astr_val->val.CBSJ.mon,astr_val->val.CBSJ.day,astr_val->val.FLS);       for(li_i = 0;li_i<astr_val->val.FLS;li_i++)       {            printf("PXL[li_i]  = %f  ",astr_val->val.PXL[li_i]);            printf("QXL[li_i]  = %f  ",astr_val->val.QXL[li_i]);       }   printf("����ͨ��\n");     return ERROR_SUCCESS;}/*********** ������ԼD�����ݵ�����(��)*************    data   ����ָ��    ai_step  ���ĳ���    str_AFN0D_POWER        str_AFN0D_POWER_VAL            TD          ʱ��            CBSJ        ����ʱ��            FLS         ������            power       ��������        str_AFN0D_POWER_ISNULL            TD          ʱ���пձ�־            CBSJ        ����ʱ���пձ�־            FLS         �������пձ�־            power       �����пձ�־����    ����        1          ��������        -4         ���������*******************************************/int decode_afn0D_POWER_M(uchar *data, str_AFN0D_POWER *astr_val, int *ai_step){    uchar *p;    int li_i, li_step;    for (li_i = 0; li_i < 15; li_i++)    {        astr_val->isnull.power[li_i] = DATA_ISNULL;    }    p = data;    astr_val->isnull.TD = getdataformat21(p, &(astr_val->val.TD), &li_step);    *ai_step = li_step;    p += li_step;    astr_val->val.FLS = *p;    (*ai_step)++;    p++;    if (astr_val->val.FLS > 14)        return ERROR_DATA_INVALID;    for (li_i = 0; li_i <= astr_val->val.FLS; li_i++)    {        astr_val->isnull.power[li_i] = getdataformat13(p, &(astr_val->val.power[li_i]), &li_step);        *ai_step += li_step;        p += li_step;    }	 printf("*******************�������ݽṹ�����************ \n");	       printf("*********year = %d,month = %d, day =%d,hour = %d,min = %d**********\n",astr_val->val.TD.year,             astr_val->val.TD.mon,astr_val->val.TD.day,astr_val->val.TD.hour,astr_val->val.TD.min);        for(li_i = 0;li_i<astr_val->val.FLS;li_i++)       {            printf("power[li_i]  = %f  ",astr_val->val.power[li_i]);       }   printf("����ͨ��\n");    return ERROR_SUCCESS;}

int de_AFN0D_FN17_18(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
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
int de_AFN0D_FN19_20(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
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

