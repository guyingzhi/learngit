#include "encode_AFN06.h"

int encode_AFN06(str_encode_param *astr_param, uchar *usr_dat)
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
      
                        case 12:
				ret = encode_frame06F12(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;
                        case 13:
				
				ret = encode_frame06F13(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                        case 14:
				   
				ret = encode_frame06F14(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;						
                        case 16:
				 
				ret = encode_frame06F16(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                        case 17:
				
				ret = encode_frame06F17(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                        case 18:
				  
				ret = encode_frame06F18(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                        case 19:
				
				ret = encode_frame06F19(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                        case 20:
				
				ret = encode_frame06F20(astr_param->dat, 2, p);
	                   if (ret < 0)
                            	goto out;
					
                            p += ret;
                            li_len += ret;
	            		break;			
                        case 21:
				ret = encode_frame06F21(astr_param->dat, 2, p);
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

