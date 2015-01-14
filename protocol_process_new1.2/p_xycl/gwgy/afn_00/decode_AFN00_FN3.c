#include "decode_AFN00_FN3.h"

int decode_AFN00_F3(uchar *lc_p, str_encode_param *astr_frame, int *li_step, int ai_len, char *lc_buf)
{
	str_AFN00_F3 lstr_f3;
	uchar *p, lc_commit;
	uchar lc_DA1,lc_DA2,lc_DT1,lc_DT2;
	str_pn lstr_pn;
	str_fn lstr_fn;
	int li_i=0;
	char lc_rwxh[32]={0};

	memset(&lstr_f3, 0, sizeof(lstr_f3));
	p = lc_p;
	if (ai_len <= 0)
		return ERROR_FRAME_DATA_LENGTH;
	lstr_f3.afn = *p;
	p++;
	li_i++;
	ai_len--;
	while (ai_len > 0){
		lc_DA1 = *p;
		lc_DA2 = *(p + 1);
		lc_DT1 = *(p + 2);
		lc_DT2 = *(p + 3);
		p += 4;
		li_i += 4;
		ai_len -= 4;
		if (ai_len <= 0)
			return -8;
		if (lstr_f3.len >= 255)
			return ERROR_FRAME_DATA_LENGTH;
		lstr_pn = get_PN(lc_DA1, lc_DA2);
		lstr_fn = get_FN(lc_DT1, lc_DT2);
		lstr_f3.pn[lstr_f3.len] = lstr_pn.pn[0];
		lstr_f3.fn[lstr_f3.len] = lstr_fn.fn[0];
		lstr_f3.err[lstr_f3.len++] = *p;
		p++;
		li_i++;
		ai_len--;
		*li_step += li_i;
		if (ai_len < 0)
			return ERROR_FRAME_DATA_LENGTH;
	}
	
	lc_commit = 1;
	for (li_i = 0; li_i < lstr_f3.len; li_i++){
		if (lstr_f3.err[li_i] != 0){
			lc_commit = 0;
			break;
		}		
	}
	f_get_xh(lc_rwxh);
	get_report_000301(lc_buf, &li_i, astr_frame, lc_rwxh, lc_commit);
	f_sendto_mngr(lc_buf, li_i);
	
	return ERROR_SUCCESS;
}







