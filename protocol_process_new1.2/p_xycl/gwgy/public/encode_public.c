#include "encode_public.h"



int SetBitInByte(uchar *ac_val, uchar ac_pos, uchar ac_bool)
{
    if (ac_bool)
    {
        *ac_val =  *ac_val | (1 << ac_pos);
    }
    else
    {
        *ac_val =  *ac_val & (~(1 << ac_pos));
    }
    return ERROR_SUCCESS;
}

int setdataflag(uchar fn, unsigned short pn, str_dataflag *astr_out)
{
    str_dataflag lstr_val;
    uchar lc_i, lc_j;
    if (pn == 0)
    {
        lstr_val.DA1 = 0;
        lstr_val.DA2 = 0;
    }
    else if (pn == 0xFFFF)
    {
        lstr_val.DA1 = 0xFF;
        lstr_val.DA2 = 0xFF;
    }
    else if (pn == 0xFF)
    {
        lstr_val.DA1 = 0xFF;
        lstr_val.DA2 = 0;
    }
    else
    {
        lc_i = (pn - 1) / 8;
        lc_j = (pn - 1) % 8;
        lstr_val.DA1 = 0;
        SetBitInByte(&lstr_val.DA1, lc_j, 1);
        lstr_val.DA2 = lc_i + 1;

     /*   lstr_val.DA2 = (pn / 8) + 1;
        lc_j = (pn  % 8) - 1;
        lstr_val.DA1 = 0;
        SetBitInByte(&lstr_val.DA1, lc_j, 1);*/
    }

    lstr_val.DT2 = (fn - 1) / 8;
    lstr_val.DT1 = 0;
    SetBitInByte(&lstr_val.DT1, (fn - 1) % 8, 1);

    *astr_out = lstr_val;

    return ERROR_SUCCESS;
}

int get_fn_1003xx_dayfrz(int ywbzm, char *gnm, char *gnm_mask, ushort *fn_out)
{
	int li_n = 0, li_gnm;

	li_gnm = atoi(gnm);
	switch (ywbzm){
		case 100301:
			switch (li_gnm){
				case 1:	/*供电统计*/
					fn_out[li_n++] = 49;
					break;
				case 2:	/*控制次数*/
					fn_out[li_n++] = 50;
					break;
				default:
					break;
			}
			break;
		case 100302:
			switch (li_gnm){
				case 1:
					if ((gnm_mask[0] == '1') || (gnm_mask[1] == '1') || (gnm_mask[4] == '1') || (gnm_mask[7] == '1'))
						fn_out[li_n++] = 1;               
					if ((gnm_mask[2] == '1') || (gnm_mask[3] == '1') || (gnm_mask[5] == '1') || (gnm_mask[6] == '1'))
						fn_out[li_n++] = 2;
					break;
				case 2:  /*最大需量*/
					if ((gnm_mask[0] == '1') || (gnm_mask[1] == '1'))
						fn_out[li_n++] = 3;
					if ((gnm_mask[2] == '1') || (gnm_mask[3] == '1'))				
						fn_out[li_n++] = 4;
					break;				
				case 3:	/*有功最大需量*/
					fn_out[li_n++] = 26;
					break;
				case 4:	/*有功功率统计*/
					fn_out[li_n++] = 25;
					break;				
				case 5:
				case 6:	/*电压统计*/
					fn_out[li_n++] = 27;
					break;				
				case 7:
				case 8:	/*电流统计*/
					fn_out[li_n++] = 29;
					break;				
				case 9:	/*不平衡度越限累计*/
					fn_out[li_n++] = 28;
					break;
				case 10:  /*视在功率越限*/
					fn_out[li_n++] = 30;
					break;
				case 11:
				case 12:  /*断相累计时间数据*/
					fn_out[li_n++] = 32;
					break;
				case 13:  /*谐波电流最大值*/
					if (gnm_mask[0] == '1')
						fn_out[li_n++] = 113;
					if (gnm_mask[1] == '1')
						fn_out[li_n++] = 114;
					if (gnm_mask[2] == '1')
						fn_out[li_n++] = 115;
					break;
				case 14:  /*谐波电压含有率最大值*/
					if (gnm_mask[0] == '1')
						fn_out[li_n++] = 116;
					if (gnm_mask[1] == '1')
						fn_out[li_n++] = 117;
					if (gnm_mask[2] == '1')
						fn_out[li_n++] = 118;
					break;
				case 15:  /*谐波越限*/
					if (gnm_mask[0] == '1')
						fn_out[li_n++] = 121;
					if (gnm_mask[1] == '1')
						fn_out[li_n++] = 122;
					if (gnm_mask[2] == '1')
						fn_out[li_n++] = 123;
					break;
				/*2013-8-9*/
				case 161:  /*能示值(正向有功)*/
					fn_out[li_n++] = 161;
					break;
				case 162:  /*能示值(正向无功)*/
					fn_out[li_n++] = 162;
					break;
				case 163:  /*能示值(反向有功)*/
					fn_out[li_n++] = 163;
					break;
				case 164:  /*能示值(反向无功)*/
					fn_out[li_n++] = 164;
					break;
				case 210:  /*日购用电信息*/
					fn_out[li_n++] = 210;
					break;
				default:
					break;
			}
			break;
		case 100303:	
			switch (li_gnm){
				case 1:  /*总加有功功率*/
					fn_out[li_n++] = 57;
					break;
				case 2:
					if (gnm_mask[0] == '1')
						fn_out[li_n++] = 58;
					if (gnm_mask[1] == '1')
						fn_out[li_n++] = 59;
					break;
				default:
					break;
			}
			break;
		case 100304:
			switch (li_gnm){
				case 1:
					fn_out[li_n++] = 129;
					break;
				default:
					break;
			}
			break;
		default:
			break;
    }

    return li_n;
}

int get_fn_1003xx_monfrz(int ywbzm, char *gnm, char *gnm_mask, ushort *fn_out)
{
	int li_n = 0, li_gnm;

	li_gnm = atoi(gnm);
	switch (ywbzm){
		case 100301:
			switch (li_gnm){
				case 1:			
					fn_out[li_n++] = 51;  /*供电统计*/
					break;
				case 2:
					fn_out[li_n++] = 52;  /*控制次数*/
					break;
				default:
					break;
                    }
			break;
		case 100302:
			switch (li_gnm){
				case 1:
					if ((gnm_mask[0] == '1') || (gnm_mask[1] == '1') || (gnm_mask[4] == '1') || (gnm_mask[7] == '1'))
						fn_out[li_n++] = 17;
					if ((gnm_mask[2] == '1') || (gnm_mask[3] == '1') || (gnm_mask[5] == '1') || (gnm_mask[6] == '1'))
						fn_out[li_n++] = 18;
					break;
				case 2:   /*最大需量*/
					if ((gnm_mask[0] == '1') || (gnm_mask[1] == '1'))
						fn_out[li_n++] = 19;
					if ((gnm_mask[2] == '1') || (gnm_mask[3] == '1'))
						fn_out[li_n++] = 20;
					break;
				case 3:  /*有功最大需量*/
					fn_out[li_n++] = 34;
					break;
				case 4:  /*有功功率统计*/
					fn_out[li_n++] = 33;
					break;
				case 5:
				case 6:  /*电压统计*/
					fn_out[li_n++] = 35;
					break;
				case 7:
				case 8:  /*电流统计*/
					fn_out[li_n++] = 37;
					break;
				case 9:	/*不平衡度越限累计*/
					fn_out[li_n++] = 36;
					break;
				case 10:  /*视在功率越限*/
					fn_out[li_n++] = 38;
					break;
                		case 215:  /*电能表购、用电信息*/
					fn_out[li_n++] = 215;
					break;
				default:
					break;
			}
			break;
		case 100303:
			switch (li_gnm){
				case 1:  /*总加有功功率*/
					fn_out[li_n++] = 60;
					break;                
				case 2:
					if (gnm_mask[0] == '1')
						fn_out[li_n++] = 61;			
					if (gnm_mask[1] == '1')				
						fn_out[li_n++] = 62;
					break;
				default:
					break;
			}
			break;
		case 100304:
			switch (li_gnm){
				case 1:		
					fn_out[li_n++] = 130;
					break;
				default:
					break;
			}
			break;     
		default:
			break;
    }

    return li_n;
}



int get_fn_100302(char *gnm, char *gnm_mask, ushort *fn_out)
{
	int li_n = 0, li_gnm;

	li_gnm = atoi(gnm);
	switch (li_gnm){
		case 1:
			if ((gnm_mask[0] == '1') || (gnm_mask[1] == '1') || (gnm_mask[4] == '1') || (gnm_mask[7] == '1'))
				fn_out[li_n++] = 1;               
			if ((gnm_mask[2] == '1') || (gnm_mask[3] == '1') || (gnm_mask[5] == '1') || (gnm_mask[6] == '1'))
				fn_out[li_n++] = 2;
			break;
		case 2:  /*最大需量*/
			if ((gnm_mask[0] == '1') || (gnm_mask[1] == '1'))
				fn_out[li_n++] = 3;
			if ((gnm_mask[2] == '1') || (gnm_mask[3] == '1'))				
				fn_out[li_n++] = 4;
			break;				
		case 3:	/*有功最大需量*/
			fn_out[li_n++] = 26;
			break;
		case 4:	/*有功功率统计*/
			fn_out[li_n++] = 25;
			break;				
		case 5:
		case 6:	/*电压统计*/
			fn_out[li_n++] = 27;
			break;				
		case 7:
		case 8:	/*电流统计*/
			fn_out[li_n++] = 29;
			break;				
		case 9:	/*不平衡度越限累计*/
			fn_out[li_n++] = 28;
			break;
		case 10:  /*视在功率越限*/
			fn_out[li_n++] = 30;
			break;
		case 11:
		case 12:  /*断相累计时间数据*/
			fn_out[li_n++] = 32;
			break;
		case 13:  /*谐波电流最大值*/
			if (gnm_mask[0] == '1')
				fn_out[li_n++] = 113;
			if (gnm_mask[1] == '1')
				fn_out[li_n++] = 114;
			if (gnm_mask[2] == '1')
				fn_out[li_n++] = 115;
			break;
		case 14:  /*谐波电压含有率最大值*/
			if (gnm_mask[0] == '1')
				fn_out[li_n++] = 116;
			if (gnm_mask[1] == '1')
				fn_out[li_n++] = 117;
			if (gnm_mask[2] == '1')
				fn_out[li_n++] = 118;
			break;
		case 15:  /*谐波越限*/
			if (gnm_mask[0] == '1')
				fn_out[li_n++] = 121;
			if (gnm_mask[1] == '1')
				fn_out[li_n++] = 122;
			if (gnm_mask[2] == '1')
				fn_out[li_n++] = 123;
			break;
		/*2013-8-9*/
		case 161:  /*能示值(正向有功)*/
			fn_out[li_n++] = 161;
			break;
		case 162:  /*能示值(正向无功)*/
			fn_out[li_n++] = 162;
			break;
		case 163:  /*能示值(反向有功)*/
			fn_out[li_n++] = 163;
			break;
		case 164:  /*能示值(反向无功)*/
			fn_out[li_n++] = 164;
			break;
		case 210:  /*日购用电信息*/
			fn_out[li_n++] = 210;
			break;
		default:
			break;
	}

	return li_n;
}


int get_fn(char *ywbzm, char *gnm, char *gnm_mask, ushort *fn_out)
{
	int ret, li_ywbzm;
	li_ywbzm = atoi(ywbzm);
	switch(li_ywbzm){
		case 100302:
			ret = get_fn_100302(gnm, gnm_mask, fn_out);
			break;
		default:
			ret = ERROR_YWBZM;
			break;
	}

	return ret;
}

int get_dat_1003xx(char *dat_in, uchar *dat_out)
{
	int li_i, li_j, li_cnt, dat_len, li_m, li_n, ret=0;
	char *p = dat_in, lc_buf[17];

	dat_len = strlen(dat_in);
	for (li_i=0, li_j=0, li_cnt=0, li_m=0; li_i <= dat_len; li_i++, p++){
		memset(lc_buf, 0, sizeof(lc_buf));
		if (strncmp(p, "|", 1) == 0 || strncmp(p, "\0", 1) == 0){
			switch (li_j++){  //字段偏移
				case 0:  //冻结标志:1日冻结,2月冻结,3抄表日冻结
					memcpy(lc_buf, p-li_cnt, li_cnt);
					ret = atoi(lc_buf);
					break;
				default:
					break;
			}  
			li_cnt = 0;   
			if (li_j == 1){  //取用户数据
				if (li_i < dat_len){  //还有后续数据
					memset(lc_buf, 0, sizeof(lc_buf));
					li_n = dat_len - li_i - 1;
					memcpy(lc_buf, p+1, (li_n > 16) ? 16:li_n);
					dat_out[li_m++] = (lc_buf[0]-48)*10+(lc_buf[1]-48);
					dat_out[li_m++] = (lc_buf[2]-48)*10+(lc_buf[3]-48);
					dat_out[li_m++] = (lc_buf[4]-48)*10+(lc_buf[5]-48);
					dat_out[li_m++] = (lc_buf[6]-48)*10+(lc_buf[7]-48);
				}
				break; 
		      }
		} else 
			li_cnt++;
	}  
	
	return ret;
}

/*
int get_fn_dat(str_inter_char *str_char, str_encode_param *str_param)
{
	int ret=0;
	int ywbzm;
	
	ywbzm = atoi(str_char->ywbzm);
	switch (ywbzm){
		case 100301:
		case 100302:
		case 100303:
		case 100304:
			ret = get_dat_1003xx(str_char->usr_dat, str_param->dat);
			if (ret == 2)  //月冻结
				str_param->mul_fn.cnt = get_fn_1003xx_monfrz(ywbzm, str_char->fun_code, str_char->fun_umask, str_param->mul_fn.fn);
			else 
				str_param->mul_fn.cnt = get_fn_1003xx_dayfrz(ywbzm, str_char->fun_code, str_char->fun_umask, str_param->mul_fn.fn);
			if (str_param->mul_fn.cnt == 0)
				ret = ERROR_RANGE_FN;
			break;
		default:
			ret = ERROR_YWBZM;
			break;
			
	}
	
	return ret;
}
*/

int get_pn(char *as_PNstr, str_pn *astr_PNarr)
{
    char *ls_n, ls_m[100]={0}, *p;
    int li_i, li_n, li_m, ret = 1;
    p = as_PNstr;
    li_n = strlen(p);
    li_m = 0;
    astr_PNarr->cnt = 0;
    while (li_n > li_m){
        ls_n =  strchr(p,',');
        if (ls_n == NULL)
        	ls_n = strchr(p, '\0');
        if (ls_n == NULL){
        	ret = -1;
        	break;
        }
        li_i = ls_n - p;
        li_m += li_i;
        if (li_i < sizeof(ls_m)){
		 memcpy(ls_m, p, li_i);
        	 ls_m[li_i] = 0;  //加字符串结束符
        	 if (isnum(ls_m))
            		astr_PNarr->pn[astr_PNarr->cnt++] = atoi(ls_m) % 2040;
        	 else {
			ret = -1;
			break;
		 }
        }
        if (astr_PNarr->cnt >= 2040)
            break;
        if (ls_n != '\0')
        	p = ls_n + 1;
        li_m++;
    }
    return ret;
}





