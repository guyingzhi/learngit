#include "decode_AFN0D.h"

int decode_AFN0D(str_encode_param *astr_frame)
{
	uchar *p;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	int li_len, li_i, li_j, li_res;
	int li_step;
	str_pn lstr_pn;
	str_fn lstr_fn;
	
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
	li_len = astr_frame->strl.len - li_len;  //纯DADT和数据,无附加域
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
				DEBUG("decode fn = %d\n", lstr_fn.fn[li_j]);
				switch (lstr_fn.fn[li_j]){
					case 1:
					case 2:
					case 9:
					case 10:                    
						li_res = de_AFN0D_FN1_2_9_10(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;                    
					case 3:
					case 4:
					case 11:
					case 12:	
						li_res = de_AFN0D_FN3_4_11_12(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 5:
					case 6:
					case 7:
					case 8:	
					{
						li_res = de_AFN0D_FN5_6_7_8(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 17:
					case 18:	
					{
						li_res = de_AFN0D_FN17_18(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 19:
					case 20:	
					{
						li_res = de_AFN0D_FN19_20(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 21:
		                   case 22:
		                   case 23:
		                   case 24:
		                   {
						li_res = de_AFN0D_FN21_22_23_24(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
		                   }
					case 25:
					{
						li_res = de_AFN0D_FN25(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 26:
					{
						li_res = de_AFN0D_FN26(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 27:
					{
						li_res = de_AFN0D_FN27(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 28:
					{
						li_res = de_AFN0D_FN28(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 29:
					{
						li_res = de_AFN0D_FN29(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 30:
					{
						li_res = de_AFN0D_FN30(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 31:
					{
						li_res = de_AFN0D_FN31(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 32:
					{
						li_res = de_AFN0D_FN32(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 33:
					{
						li_res = de_AFN0D_FN33(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 34:
					{
						li_res = de_AFN0D_FN34(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 35:
					{
						li_res = de_AFN0D_FN35(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 36:
					{
						li_res = de_AFN0D_FN36(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 37:
					{
						li_res = de_AFN0D_FN37(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 38:
					{
						li_res = de_AFN0D_FN38(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
                    	        case 39:
					{
						li_res = de_AFN0D_FN39(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 41:
					{
						li_res = de_AFN0D_FN41(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 42:
					{
						li_res = de_AFN0D_FN42(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 43:
					{
						li_res = de_AFN0D_FN43(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 44:
					{
						li_res = de_AFN0D_FN44(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
                    	        case 45:
					{
						li_res = de_AFN0D_FN45(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
                                case 46:
					{
						li_res = de_AFN0D_FN46(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 49:
					{
						li_res = de_AFN0D_FN49(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 50:
					{
						li_res = de_AFN0D_FN50(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 51:
					{
						li_res = de_AFN0D_FN51(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 52:
					{
						li_res = de_AFN0D_FN52(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 53:
					{
						li_res = de_AFN0D_FN53(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 54:
					{
						li_res = de_AFN0D_FN54(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 57:
					{
						li_res = de_AFN0D_FN57(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 58:
					case 59:
					{
						li_res = de_AFN0D_FN58F59(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 60:
					{
						li_res = de_AFN0D_FN60(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 61:
					case 62:
					{
						li_res = de_AFN0D_FN61F62(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 65:
					case 66:
					{
						li_res = de_AFN0D_FN65F66(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 73:
					case 74:
					{
						li_res = de_AFN0D_FN73F74(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 75:
					case 76:
					{
						li_res = de_AFN0D_FN75F76(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 81:
					case 82:
					case 83:
					case 84:
					case 85:
					case 86:
					case 87:
					case 88:
					{
						li_res = de_AFN0D_PQQX(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len -= li_step;
						break;
					}
					case 89:
					case 90:
					case 91:
					{
						li_res = de_AFN0D_UQX(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 92:
					case 93:
					case 94:
					case 95:
					{
						li_res = de_AFN0D_IQX(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 97:
					case 98:
					case 99:
					case 100:
					{
						li_res = de_AFN0D_POWERQX(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 101:
					case 102:
					case 103:
					case 104:
					{
						li_res = de_AFN0D_CODEQX(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 105:
					case 106:
					case 107:
					case 108:
					{
						li_res = de_AFN0D_COSQX(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 109:
					{
						li_res = de_AFN0D_F109(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 110://2012新增
					{
						li_res = de_AFN0D_F110(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
							return li_res;
						p =p + li_step;
						li_len = li_len - li_step;
						break;
					}
					case 113:
					case 114:
					case 115:
						/*A  B C相2~19次谐波电流量日最大值及发生时间*/
						
						li_res = de_AFN0D_F113_115(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 116:
					case 117:
					case 118:	
						/*A  B C相2~19次谐波电压含有率及总畸形变率日最大值及发生时间*/
						
						li_res = de_AFN0D_F116_118(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 121:
					case 122:	
					case 123:
						/*A  B C相谐波越限日统计数据*/
						
						li_res = de_AFN0D_F121_123(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 124:	
					case 125:
					case 126:	
						/*  日冻结   A  B C相电压谐波电压含有率谐波电流95%概率值*/
						
						li_res = de_AFN0D_F124_126(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 129:
						/*  直流模拟量越限日累计时间，最大最小及发生时间*/
						
						li_res = de_AFN0D_F129(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 130:
						/* 直流模拟量越限月累计时间，最大最小及发生时间*/
						
						li_res = de_AFN0D_F130(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 138:
						/* 直流模拟数据曲线*/
						
						li_res = de_AFN0D_F138(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 145:
					case 146:
					case 147:
					case 148:
						/* 一二三四象限无功功率的总电能市值曲线*/
						
						li_res = de_AFN0D_F145_148(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 153:
					case 155:	
						/*日冻结测量点分相正反向有功电能示值*/
						
						li_res = de_AFN0D_Activeenergy(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 154:
					case 156:	
						/*日冻结测量点分相正反向无功电能示值*/
						
						li_res = de_AFN0D_Idleenergy(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 157:
					case 159:	
						/*月冻结测量点分相正反向有功电能示值*/
						
						li_res = de_AFN0D_Activeenergymon(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 158:	
					case 160:
						/*月冻结测量点分相正反向无功电能示值*/
						
						li_res = de_AFN0D_Idleenergymon(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 161:
					case 163:
					case 169:
					case 171:
						/*日冻结反向/正向有功电能市值*/
						
						li_res = de_AFN0D_Activeenergyday(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 162:
					case 164:	
					case 165:
					case 166:	
					case 167:
					case 168:	
					case 170:
					case 172:
					case 173:
					case 174:	
					case 175:
					case 176:	
						/*日冻结无功电能市值*/
						
						li_res = de_AFN0D_Idleday(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 177:
					case 179:	
						/*月冻结反向/正向有功电能市值*/
						
						li_res = de_AFN0D_F177F179(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 178:	
					case 180:
					case 181:
					case 182:
					case 183:
					case 184:	
						/*月冻结反向/正向无功电能市值*/
						
						li_res = de_AFN0D_Idlemon(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 185:
					case 186:	
					case 187:
					case 188:	
					case 189:	
					case 190:
					case 191:
					case 192:
						/*日冻结正向有功反向无功最大需量及发生时间*/
						
						li_res = de_AFN0D_F185_192(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 193:
					case 194:	
					case 195:
					case 196:	
						/*月冻结正向反向无功有功最大需量及发生的时间*/
						
						li_res = de_AFN0D_F193_196(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 201:
					case 202:
					case 203:
					case 204:	
					case 205:
					case 206:	
					case 207:
					case 208:	
						/*第一到第八时区冻结正向有功电能示值*/
						
						li_res = de_AFN0D_F201F208(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 209:	
						/*日冻结电能表远程控制状态及信息*/
						
						li_res = de_AFN0D_F209(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 210:
						/*日冻结电能表购点用电信息*/
						
						li_res = de_AFN0D_F210(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 215:
						/*月冻结电能表购点用电信息*/
						
						li_res = de_AFN0D_F215(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 212:
						/*月  冻结三相电压、电流不平衡度95概率值*/
						
						li_res = de_AFN0D_F212(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 211:
						/*日冻结三相电压、电流不平衡度95概率值*/
						
						li_res = de_AFN0D_F211(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 213:
						/*电能表开关操作次数*/
						
						li_res = de_AFN0D_F213(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 214:
						/*月冻结电能表参数修改次数及时间*/
						
						li_res = de_AFN0D_F213(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 216:	
						/*电能表结算信息*/
						
						li_res = de_AFN0D_F216(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 217:
						/*台区集中抄表载波主节点白噪声曲线*/
						
						li_res = de_AFN0D_F217(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 218:	
						/*台区集中抄表载波色噪声曲线*/
						
						li_res = de_AFN0D_F218(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					case 219:	
						/*测量点组合数据曲线*/
						
						li_res = de_AFN0D_F219(p, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
						if (li_res == ERROR_DATA_INVALID || li_res == ERROR_FRAME_DATA_LENGTH)
							return li_res;
						p = p + li_step;
						li_len = li_len - li_step;
						break;
					default :
						return ERROR_DATA_INVALID;
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

int de_AFN0D_F113_115(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F113_118 lstr_val;
	li_res = decode_AFN0D_F113_115(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F116_118(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F113_118 lstr_val;
	li_res = decode_AFN0D_F116_118(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F121_123(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F121_123 lstr_val;
	li_res = decode_AFN0D_F121_123(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_F124_126(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F124_126 lstr_val;
	li_res = decode_AFN0D_F124_126(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_F129(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F219F130 lstr_val;
	li_res = decode_AFN0D_F129(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F130(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F219F130 lstr_val;
	li_res = decode_AFN0D_F130(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_F138(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_AFN0D_F138(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_F145_148(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_AFN0D_F145F148(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_Activeenergy(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_Activeenergy lstr_val;
	li_res = decode_AFN0D_Activeenergy(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_Idleenergy(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_idleenergy lstr_val;
	li_res = decode_AFN0D_Idleenergy(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_Activeenergymon(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_Activeenergy lstr_val;
	li_res = decode_AFN0D_Activeenergy(ac_p,&lstr_val,ai_step,2);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_Idleenergymon(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_idleenergy lstr_val;
	li_res = decode_AFN0D_Idleenergy(ac_p,&lstr_val,ai_step,2);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_Activeenergyday(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_Activeenergy lstr_val;
	li_res = decode_AFN0D_Activeenergy(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_Idleday(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_idleenergy lstr_val;
	li_res = decode_AFN0D_Idleenergy(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F177F179(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F201F208 lstr_val;
	li_res = decode_afn0D_F201F208(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_Idlemon(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F193_F200 lstr_val;
	li_res = decode_afn0D_F193_F200(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}	

int de_AFN0D_F185_192(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F193_F200 lstr_val;
	li_res = decode_afn0D_F193_F200(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F193_196(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F193_F200 lstr_val;
	li_res = decode_afn0D_F193_F200(ac_p,&lstr_val,ai_step,2);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_F201F208(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F201F208 lstr_val;
	li_res = decode_afn0D_F201F208(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0D_F209(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F209 lstr_val;
	li_res = decode_afn0D_F209(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F210(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F210F215 lstr_val;
	li_res = decode_afn0D_F210F215(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F215(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F210F215 lstr_val;
	li_res = decode_afn0D_F210F215(ac_p,&lstr_val,ai_step,2);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F211(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F211F212 lstr_val;
	li_res = decode_afn0D_F211F212(ac_p,&lstr_val,ai_step,1);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F212(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F211F212 lstr_val;
	li_res = decode_afn0D_F211F212(ac_p,&lstr_val,ai_step,2);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F213(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F213 lstr_val;
	li_res = decode_afn0D_F213(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F214(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F214 lstr_val;
	li_res = decode_afn0D_F214(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F216(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F216 lstr_val;
	li_res = decode_afn0D_F216(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F217(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F217F218 lstr_val;
	li_res = decode_afn0D_F217(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F218(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F217F218 lstr_val;
	li_res = decode_afn0D_F218(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0D_F219(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0D_F219 lstr_val;
	li_res = decode_afn0D_F219(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
