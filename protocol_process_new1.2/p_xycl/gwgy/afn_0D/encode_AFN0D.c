#include "encode_AFN0D.h"

int encode_AFN0D(str_encode_param *astr_param, uchar *usr_dat)
{
	int li_i, li_j, li_m;    
	int ret=0, li_len=0;
	str_dataflag data_id;
	char *p, *pbak;

	memset(&data_id, 0, sizeof(data_id));
	p = usr_dat;
	pbak = usr_dat;	
	
	for (li_i = 0; li_i < astr_param->mul_pn.cnt; li_i++){		
		for (li_j = 0; li_j < astr_param->mul_fn.cnt; li_j++){
			setdataflag(astr_param->mul_fn.fn[li_j], astr_param->mul_pn.pn[li_i], &data_id);
			*p = data_id.DA1;
			p++;
			li_len++;
			*p = data_id.DA2;
			p++;
			li_len++;
			*p = data_id.DT1;
			p++;
			li_len++;
			*p = data_id.DT2;
			p++;
			li_len++;
			switch (astr_param->mul_fn.fn[li_j]){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
				case 11:
				case 12:
				case 25:
				case 26:
				case 27:
				case 28:
				case 29:
				case 30:
				case 31:
				case 32:
				case 41:
				case 42:
				case 43:
				case 45:
				case 49:
				case 50:
				case 53:
				case 57:
				case 58:
				case 59:
				case 113:
				case 114:
				case 115:
				case 116:
				case 117:
				case 118:
				case 121:
				case 122:
				case 123:
				case 124:
				case 125:
				case 126:
				case 129:
				case 153:
				case 154:
				case 155:
				case 156:
				case 161:
				case 162:
				case 163:
				case 164:
				case 165:
				case 166:
				case 167:
				case 168:
				case 169:
				case 170:
				case 171:
				case 172:
				case 173:
				case 174:
				case 175:
				case 176:
				case 185:
				case 186:
				case 187:
				case 188:
				case 189:
				case 190:
				case 191:
				case 192:
				case 209:
				case 210:
				case 211:						
					ret = encodedataformatTD_d(astr_param->dat, astr_param->dat_len, p);
					if (ret < 0)
						goto out;
					p += ret;
					li_len += ret;
					break;
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 33:
				case 34:
				case 35:
				case 36:
				case 37:
				case 38:
				case 39:
				case 44:
				case 46:
				case 51:
				case 52:
				case 54:
				case 60:
				case 61:
				case 62:
				case 65:
				case 66:
				case 130:
				case 157:
				case 158:
				case 159:
				case 160:
				case 177:
				case 178:
				case 179:
				case 180:
				case 181:
				case 182:
				case 183:
				case 184:
				case 193:
				case 194:
				case 195:
				case 196:
				case 201:
				case 202:
				case 203:
				case 204:
				case 205:
				case 206:
				case 207:
				case 208:
				case 212:
				case 213:
				case 214:
				case 215:
				case 216:
					//添加数据内容，月冻结
					ret = encodedataformatTD_m(astr_param->dat, astr_param->dat_len, p);
					if (ret < 0)
						goto out;
					p += ret;
					li_len += ret;
					break;
				case 73:
				case 74:
				case 75:
				case 76:
				case 81:
				case 82:
				case 83:
				case 84:
				case 85:
				case 86:
				case 87:
				case 88:
				case 89:
				case 90:
				case 91:
				case 92:
				case 93:
				case 94:
				case 95:
				case 96:
				case 97:
				case 98:
				case 99:
				case 100:
				case 101:
				case 102:
				case 103:
				case 104:
				case 105:
				case 106:
				case 107:
				case 108:
				case 109:
				case 110:
				case 138:
				case 145:
				case 146:
				case 147:
				case 148:
				case 217:
				case 218:
				case 219:
					//添加数据内容，曲线
					ret = encodedataformatTD_C(astr_param->dat, astr_param->dat_len, p);
					if (ret < 0)
						goto out;
					p += ret;
					li_len += ret;
					break;
				default :
					p -= 4;
					li_len -= 4;
					break;
			}
		}
	}
    
out:
	if (ret < 0)
    		return ret;
    	else
    		return li_len;
//    ret = encodeframe0D(astr_param, &astr_out);
/*    if (ret != ERROR_SUCCESS){
		printf("ret=%d\n",ret);
		return ret;
    }
        printf("**************** SEND ***************\n");
        for(i = 0; i< astr_out.len; i++)
    	    printf("%02x ",astr_out.bytes[i]);
        printf("\n");


    f_get_xh(ls_rwxh);
    get_report_000103(ls_mes, &li_meslen, astr_out.bytes, astr_out.len, ls_rwxh);
    f_sendto_mngr(ls_mes, li_meslen);

    return ERROR_SUCCESS;*/
}


