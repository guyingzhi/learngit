#include "encode_AFN00.h"

int encode_AFN00(str_encode_param *astr_param, uchar *usr_dat)
{
	int li_i, li_j;    
	int ret=0, li_len=0;
	str_dataflag data_id;
	char *p, *pbak;
	p = usr_dat;
	pbak = usr_dat;
  
	memset(&data_id, 0, sizeof(data_id));

	if (astr_param->mul_fn.cnt != 1)
		return ERROR_RANGE_FN;

	for (li_i = 0; li_i < astr_param->mul_pn.cnt; li_i++){
		if (astr_param->mul_pn.pn[li_i] != 0)
			continue;
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
					ret = 0;  /*无数据内容*/
					break;
				case 3:
					ret = 0;
					break;
				case 4:
					ret = 0;
					p += 17;
					li_len += 17;
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
}




