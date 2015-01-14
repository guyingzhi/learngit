#include "encode_AFN10.h"

int encode_AFN10(str_encode_param *astr_param, uchar *usr_dat)
{
    int li_i, li_j;    
    int ret=0, li_len=0;
    str_dataflag data_id;
    char *p, *pbak;
    p = usr_dat;
    pbak = usr_dat;
  
    memset(&data_id, 0, sizeof(data_id));

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
				ret = encode_frame10F1(astr_param->dat, 2, p);
             			 if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                    
                        case 9:
				
				ret = encode_frame10F9(astr_param->dat, 2, p);
             			 if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;				
                        case 10:
				
				ret = encode_frame10F10(astr_param->dat, 2, p);
             			 if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;				
                        case 11:
				
				ret = encode_frame10F11(astr_param->dat, 2, p);
             			 if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;				
                        case 12:
				
				ret = encode_frame10F12(astr_param->dat, 2, p);
             			 if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;
			     case 13:
				
				ret = encode_frame10F13(astr_param->dat, 2, p);
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


