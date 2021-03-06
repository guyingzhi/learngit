#include "decode_AFN09.h"

int decode_AFN09(str_encode_param *astr_frame)
{
	uchar *p;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	int li_len, li_res, li_i, li_j;
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
//		if (lstr_fn.cnt == 1 && lstr_fn.fn[0] == 0)
//			return ERROR_RANGE_FN;
        
		lstr_pn = get_PN(lc_DA1, lc_DA2);
		p += 4;
		li_len -= 4;
		for (li_i = 0; li_i < lstr_pn.cnt; li_i++){
			for (li_j = 0; li_j < lstr_fn.cnt; li_j++){
				li_step = 0;
				switch (lstr_fn.fn[li_j]){
					case 1:
						li_res = de_AFN09_FN1(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 2:
						li_res = de_AFN09_FN2(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 3:
						li_res = de_AFN09_FN3(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 4:
					case 5:					 
						li_res = de_AFN09_FN4_5(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break; 				   
					case 6:
					case 7:
						li_res = de_AFN09_FN6_7(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break; 	
					case 8:
						li_res = de_AFN09_FN8(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break; 	
					case 9:					 
						li_res = de_AFN09_FN9(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 10:					 
						li_res = de_AFN09_FN10(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break; 
					default :
						return ERROR_DATA_INVALID;
				}
		
		/*		   if (get_report_000205(ls_mes, &li_meslen, astr_frame->addr, li_res, lstr_PN.PN[li_i]) == ERROR_SUCCESS)
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




