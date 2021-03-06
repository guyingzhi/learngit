#include "decode_AFN10.h"
int de_AFN10_FN01(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN10_F01 lstr_afn10_F01_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    li_res = decode_afn10_F01(ac_p, &lstr_afn10_F01_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN10_FN09(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN10_F09 lstr_afn10_F09_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    li_res = decode_afn10_F09(ac_p, &lstr_afn10_F09_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN10_FN10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN10_F10 lstr_afn10_F10_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    li_res = decode_afn10_F10(ac_p, &lstr_afn10_F10_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN10_FN11(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN10_F11 lstr_afn10_F11_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    li_res = decode_afn10_F11(ac_p, &lstr_afn10_F11_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN10_FN13(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN10_F13 lstr_afn10_F13_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    li_res = decode_afn10_F13(ac_p, &lstr_afn10_F13_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}





/*********** 解析规约10类数据 *************
	astr_frame	帧结构体

	返回：	 1	解析正常返回
			-1	报文长度不对
			-2	有未定义的FN
			-3  FN=0
			-4  无法解析的数据
			-5  错误的数据
*******************************************/

int decode_AFN10(str_encode_param *astr_frame)
{
	uchar *P;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	int li_len, li_i, li_j, li_res;
	int li_step;
	str_pn lstr_pn;
	str_fn lstr_fn;
	P = astr_frame->dat;
	
 /*   li_res = get_zd_gylx(astr_frame->addr, &(astr_frame->gylx));
    if(li_res != ERROR_SUCCESS)
    {
        tracelog("decode_afn0D_frame 没有找到规约类型 astr_frame->addr=%d",astr_frame->addr);
        return li_res;
    }
    tracelog("astr_frame->gylx=%d",astr_frame->gylx);*/
	li_len = 8;
	if (astr_frame->seq.tpv == 1)
		li_len += 6;
	if (astr_frame->c.fcb_acd == 1)  /*EC占两个字节*/
		li_len += 2;
	li_len = astr_frame->strl.len - li_len;  //纯DADT和数据,无附加域
	if (li_len <= 0){
		if(gi_save_log)
	    		tracelog("updecode AFN%X li_len <= 0 li_len = %d", astr_frame->afn, li_len);
		return ERROR_FRAME_LENGTH;
	}
    while (li_len > 0)
    {
        /*printf("li_len S : %d \n",li_len);*/
        lc_DA1 = *P;
        lc_DA2 = *(P + 1);
        lc_DT1 = *(P + 2);
        lc_DT2 = *(P + 3);
        lstr_fn = get_FN(lc_DT1, lc_DT2);
        if (lstr_fn.cnt == 1 && lstr_fn.fn[0] == 0)  //??此处有疑问
        {
            return ERROR_RANGE_FN;
        }
        lstr_pn = get_PN(lc_DA1, lc_DA2);
        P = P + 4;
        li_len = li_len - 4;
        for (li_i = 0;li_i < lstr_pn.cnt;li_i++)
        {
            for (li_j = 0;li_j < lstr_pn.cnt;li_j++)
            {
                li_step = 0;
            //    tracelog("lstr_FN.FN[%d]=%d",li_j,lstr_FN.FN[li_j]);
                switch(lstr_fn.fn[li_j])
                {
                    case 1:
			{
				 li_res = de_AFN10_FN01(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
					
                    case 9:
			{
				 li_res = de_AFN10_FN09(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 10:
			{	
				 li_res = de_AFN10_FN10(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
				
             
			case 11:
			{
				 li_res = de_AFN10_FN11(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 13:
			{
				 li_res = de_AFN10_FN13(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    default :
                    {
                        return ERROR_DATA_INVALID;
                        break;
                    }
                }

       /*         if (get_report_000205(ls_mes, &li_meslen, astr_frame->addr, li_res, lstr_PN.PN[li_i]) == ERROR_SUCCESS)
                {
                    f_sendto_mngr(ls_mes,li_meslen);
                }*/
                if (li_len < 0)
                    return ERROR_FRAME_LENGTH;
            }
        }
    }
    return ERROR_SUCCESS;
}



