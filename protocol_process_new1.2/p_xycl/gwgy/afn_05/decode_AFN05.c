#include "decode_AFN05.h"

int decode_afn05_frame(str_frame *astr_frame)
{
	uchar *P;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	int li_len, li_res, li_meslen;
	int li_step;
	str_pn lstr_PN;
	str_fn lstr_FN;
	P = astr_frame->data;
	li_len = 8;
	P = P + 2;
	if (astr_frame->tpv == 1)
		li_len = li_len + 6;
	if (astr_frame->acd)  /*EC占两个字节*/
		li_len = li_len + 2;
		li_len = astr_frame->l - li_len;
	if (li_len <= 0)
	{
		return ERROR_FRAME_DATA_LENGTH;
	}
	while (li_len > 0)
	{
		lc_DA1 = *P;
		lc_DA2 = *(P + 1);
		lc_DT1 = *(P + 2);
		lc_DT2 = *(P + 3);
		tracelog("lc_DA1=%x,lc_DA2=%x,lc_DT1=%x,lc_DT2=%x",lc_DA1,lc_DA2,lc_DT1,lc_DT2);
		lstr_PN = get_PN(lc_DA1, lc_DA2);
		lstr_FN = get_FN(lc_DT1, lc_DT2);
		if (lstr_PN.cnt!= 1)
		    return ERROR_RANGE_DATA;
		if (lstr_PN.pn[0] != 0)
		    return ERROR_DATA_INVALID;
		if (lstr_FN.cnt!= 1)
		    return ERROR_RANGE_DATA;
		if (lstr_FN.fn[0] > 3)
		    return ERROR_DATA_INVALID;
		if (lstr_FN.fn[0] == 0)
		    return ERROR_DATA_INVALID;
		P = P + 4;
		li_len = li_len - 4;
		tracelog("lstr_FN.FN[0]=%d",lstr_FN.fn[0]);
		switch(lstr_FN.fn[0])
		{
		        case 1:
		        {
		            f_get_xh(ls_rwxh);
		            get_report_000301(ls_mes, &li_meslen, astr_frame, ls_rwxh, 1);
		       //     f_sendto_mngr(ls_mes, li_meslen);
		            break;
		        }
		        case 2:
		        {
		            f_get_xh(ls_rwxh);
		            get_report_000301(ls_mes, &li_meslen, astr_frame, ls_rwxh, 0);
		          //  f_sendto_mngr(ls_mes, li_meslen);
		            break;
		        }
		        case 3:
		        {
		            li_res = Treatment_afn05_F03(P, astr_frame, &li_step ,li_len);
		            P += li_step;
		            li_len -= li_step;
		            break;
		        }
		    }
        if (li_len<0)
            return ERROR_FRAME_DATA_LENGTH;
    }
    return ERROR_SUCCESS;
}

int Treatment_afn05_F03(uchar *lc_p, str_frame *astr_frame, int *li_step, int ai_len)
{
	int li_len, li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN00_F03 ai_val;
	uchar lc_i, lc_commit;
	li_len = ai_len;
	li_res = decode_afn05_F03(lc_p, &ai_val, li_step, li_len);




	/*
	f_get_xh(ls_rwxh);
	if (li_res == ERROR_SUCCESS)
	{
		lc_commit = 1;
		for (lc_i = 0; lc_i < ai_val.len; lc_i++)
		{
			if (ai_val.ERR[lc_i] != 0)
			lc_commit = 0;
		}
		get_report_000301(ls_mes, &li_meslen, astr_frame, ls_rwxh, lc_commit);
	}
	else
	{
	    get_report_000301(ls_mes, &li_meslen, astr_frame, ls_rwxh, 0);
	}*/
	f_sendto_mngr(ls_mes, li_meslen);
	return li_res;
}

int decode_afn05_F03(uchar *data, str_AFN00_F03 *lstr_val, int *ai_step, int ai_len)
{
	uchar *p;
	int li_n;
	uchar lc_DA1,lc_DA2,lc_DT1,lc_DT2;
	str_pn lstr_PN;
	str_fn lstr_FN;
	lstr_val->len = 0;
	p = data;
	li_n = ai_len;
	if (li_n <= 0)
		return ERROR_FRAME_DATA_LENGTH;
	lstr_val->afn = *p;
	p++;
	(*ai_step)++;
	
	while (li_n > 0)
	{
	        lc_DA1 = *p;
	        lc_DA2 = *(p + 1);
	        lc_DT1 = *(p + 2);
	        lc_DT2 = *(p + 3);
	        lstr_PN = get_PN(lc_DA1, lc_DA2);
	        lstr_FN = get_FN(lc_DT1, lc_DT2);
	        lstr_val->PN[lstr_val->len] = lstr_PN.pn[0];
	        lstr_val->FN[lstr_val->len] = lstr_FN.fn[0];
	        p += 4;
	        *ai_step += 4;
	        li_n -=4;
	        if (li_n <= 0)
	            return -8;
	        lstr_val->ERR[lstr_val->len] = *p;
	        p++;
	        (*ai_step)++;
	        lstr_val->len++;
	        li_n--;
	        if (li_n < 0)
	            return ERROR_FRAME_DATA_LENGTH;
	        if (lstr_val->len > 255)
	            return ERROR_FRAME_DATA_LENGTH;
    }
    return ERROR_SUCCESS;
}

