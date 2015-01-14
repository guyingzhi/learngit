#include "encode_AFN0A.h"

int encode_AFN0A(str_encode_param *astr_param, uchar *usr_dat)
{
    int li_i, li_j;    
    int ret=0, li_len=0;
    str_dataflag data_id;
    char *p,*pbak;
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
                case 2:                    
                case 3:                    
                case 4:                    
                case 5:                    
                case 6:                   
                case 7:	            
                case 8:
                case 9:
                case 12:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:	                 
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 35:
                case 36:
                case 37:
                case 41:	           
                case 42:	          
                case 43:	            
                case 44:	           
                case 45:	           
                case 46:	           
                case 47:	            
                case 48:	            
                case 49:	            
                case 57:	            
                case 58:	            
                case 59:	           
                case 60:	            
                case 61:	           
                case 65:	            
                case 66:	            
                case 67:	           
                case 68:	            
                case 73:	            
                case 74:	           
                case 75:	            
                case 76:	           
                case 81:	            
                case 82:	           
                case 83:	      
                case 89:	            
                case 90:	           
                case 91:				
                case 150:
                    ret = 0;
                    break;
                case 10:
                    ret = encode_frameAAF10(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 11:
                    ret = encode_frameAAF11(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 13:
                    ret = encode_frameAAF13(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 14:
                    ret = encode_frameAAF14(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 15:
                    ret = encode_frameAAF15(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 33:
                    ret = encode_frameAAF33(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 34:
                    ret = encode_frameAAF34(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 38:
                    ret = encode_frameAAF38(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 39:
                    ret = encode_frameAAF39(astr_param->dat, astr_param->dat_len, p);
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
}


 

