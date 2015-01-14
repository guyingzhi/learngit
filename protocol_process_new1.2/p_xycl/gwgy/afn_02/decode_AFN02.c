#include "decode_AFN02.h"

int decode_AFN02(str_encode_param *astr_frame)
{
	uchar *p;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	int li_len, li_res;
	int li_step;
	str_pn lstr_pn;
	str_fn lstr_fn;
	char lc_rwxh[32]={0};
	char ls_mes[FRAME_MAXLEN] = {0};
	int li_meslen;
	
	p = astr_frame->dat;
	
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
	li_len = astr_frame->strl.len - li_len;  /*纯DADT和数据,无附加域*/
	if (li_len <= 0){
		if(gi_save_log)
	    		tracelog("updecode AFN%X li_len <= 0 li_len = %d", astr_frame->afn, li_len);
		return ERROR_FRAME_LENGTH;
	}
	while (li_len > 0){
		lc_DA1 = *p;
		lc_DA2 = *(p + 1);
		lc_DT1 = *(p + 2);
		lc_DT2 = *(p + 3);
		lstr_fn = get_FN(lc_DT1, lc_DT2);
		if (lstr_fn.cnt == 1 && lstr_fn.fn[0] == 0)
			return ERROR_RANGE_FN;
        
		lstr_pn = get_PN(lc_DA1, lc_DA2);
		if (lstr_pn.cnt != 1)
			return ERROR_RANGE_DATA;
		if (lstr_pn.pn[0] != 0)
			return ERROR_DATA_INVALID;
		if (lstr_fn.cnt != 1)
			return ERROR_RANGE_DATA;
		if (lstr_fn.fn[0] > 3 || lstr_fn.fn[0] == 0)
			return ERROR_DATA_INVALID;
		p += 4;
		li_len -= 4;
		li_step = 0;
		switch (lstr_fn.fn[0]){
			case 1:   /*登陆*/
				/*f_get_xh(lc_rwxh);
				get_report_000301(ls_mes, &li_meslen, astr_frame, lc_rwxh, (lstr_fn.fn[0] == 1?1:0));
				f_sendto_mngr(ls_mes, li_meslen);*/
				break;
			case 2:   /*退出登录*/
				/*f_get_xh(lc_rwxh);
				get_report_000301(ls_mes, &li_meslen, astr_frame, lc_rwxh, (lstr_fn.fn[0] == 1?1:0));
				f_sendto_mngr(ls_mes, li_meslen);*/
				break;
			case 3:  /*心跳*/
				/*f_get_xh(lc_rwxh);
				get_report_000301(ls_mes, &li_meslen, astr_frame, lc_rwxh, (lstr_fn.fn[0] == 1?1:0));
				f_sendto_mngr(ls_mes, li_meslen);*/
				p += 6;
				li_len -= 6;	
				break;                
			default :
				return ERROR_DATA_INVALID;                  
		}
		if (li_len < 0)
			return ERROR_FRAME_LENGTH;
	}
	
	return ERROR_SUCCESS;
	
}





