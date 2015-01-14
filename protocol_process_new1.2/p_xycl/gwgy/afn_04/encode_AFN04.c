#include "encode_AFN04.h"

int encode_AFN04(str_encode_param *astr_param, uchar *usr_dat)
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
                    ret = encode_frameA4F1(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 2:
                    ret = encode_frameA4F2(astr_param->dat,astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;	            
                case 3:
                    ret = encode_frameA4F3(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 4:	            
                    ret = encode_frameA4F4(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 5:
                    ret = encode_frameA4F5(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 6:
                    ret = encode_frameA4F6(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 7:
                    ret = encode_frameA4F7(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 8:
                    ret = encode_frameA4F8(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 9:	            
                    ret = encode_frameA4F9(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 10:
                    ret = encode_frameA4F10(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 11:
                    ret = encode_frameA4F11(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 12:
                    ret = encode_frameA4F12(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 13:
                    ret = encode_frameA4F13(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 14:	            
                    ret = encode_frameA4F14(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 15:
                    ret = encode_frameA4F15(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 16:
                    ret = encode_frameA4F16(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 17:
                {
                    ret = encode_frameA4F17(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;			
                }
                case 18:
                    ret = encode_frameA4F18(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 19:	            
                    ret = encode_frameA4F19(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 20:
                    ret = encode_frameA4F20(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 21:
                    ret = encode_frameA4F21(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 22:
                    ret = encode_frameA4F22(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 23:
                    ret = encode_frameA4F23(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                /*        case 24:
                {
                li_res = encode_frameA4F24(astr_param->dat, 2, pt);
                if (ret < 0)
                goto out;

                p += ret;
                li_len += ret;
                }*/
                case 25:
                    ret = encode_frameA4F25(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 26:
                    ret = encode_frameA4F26(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 27:
                    ret = encode_frameA4F27(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 28:
                    ret = encode_frameA4F28(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 29:
                    ret = encode_frameA4F29(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 30:
                    ret = encode_frameA4F30(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                /*       case 31:
                {
                li_res = encode_frameA4F31(astr_param->dat, 2, p);
                return li_res;
                }*/
                case 33:
                    ret = encode_frameA4F33(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 34:
                    ret = encode_frameA4F34(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 35:
                    ret = encode_frameA4F35(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                /*        case 36:
                //            {
                //                li_res = encode_frameA4F36(astr_param->dat, 2, p);
                //                return li_res;
                //            }
                //        case 37:
                //            {
                //                li_res = encode_frameA4F37(astr_param->dat, 2, p);
                //                return li_res;
                //            }*/
                case 38:
                    ret = encode_frameA4F38(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 39:
                    ret = encode_frameA4F39(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 41:
                    ret = encode_frameA4F41(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 42:
                    ret = encode_frameA4F42(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 43:
                    ret = encode_frameA4F43(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 44:
                    ret = encode_frameA4F44(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 45:
                    ret = encode_frameA4F45(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 46:
                    ret = encode_frameA4F46(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 47:
                    ret = encode_frameA4F47(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 48:
                    ret = encode_frameA4F48(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 49:
                {
                    ret = encode_frameA4F49(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                }
                case 57:
                {
                    ret = encode_frameA4F57(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                }
                case 58:
                    ret = encode_frameA4F58(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 59:
                    ret = encode_frameA4F59(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 60:
                    ret = encode_frameA4F60(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 61:
                    ret = encode_frameA4F61(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                /*case 62:
                {
                li_res = encode_frameA4F62(astr_param->dat, 2, p);
                return li_res;
                }
                case 63:
                {
                li_res = encode_frameA4F63(astr_param->dat, 2, p);
                return li_res;
                }
                case 64:
                {
                li_res = encode_frameA4F64(astr_param->dat, 2, p);
                return li_res;
                }*/
                case 65:
                    ret = encode_frameA4F65(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 66:
                    ret = encode_frameA4F66(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 67:
                    ret = encode_frameA4F67(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 68:
                    ret = encode_frameA4F68(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 73:
                    ret = encode_frameA4F73(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 74:
                    ret = encode_frameA4F74(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 75:
                    ret = encode_frameA4F75(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 76:
                    ret = encode_frameA4F76(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 81:
                    ret = encode_frameA4F81(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 82:
                    ret = encode_frameA4F82(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 83:
                    ret = encode_frameA4F83(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 89:
                    ret = encode_frameA4F89(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 90:		            
                    ret = encode_frameA4F90(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 91:
                    ret = encode_frameA4F91(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                /* case 96://2012新增
                {
                li_res = encode_frameA4F96(astr_param->dat, 2, p);
                return li_res;
                }
                case 97://2012新增
                {
                li_res = encode_frameA4F97(astr_param->dat, 2, p);
                return li_res;
                }
                case 98://2012新增
                {
                li_res = encode_frameA4F98(astr_param->dat, 2, p);
                return li_res;
                }
                case 99://2012新增
                {
                li_res = encode_frameA4F99(astr_param->dat, 2, p);
                return li_res;
                }
                case 106://2012新增
                case 107:
                {
                li_res = encode_frameA4F106F107(astr_param->dat, 2, p);
                return li_res;
                }*/
                case 150:
                    ret = encode_frameA4F150(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                /*case 203://2012新增
                {
                li_res = encode_frameA4F203(astr_param->dat, 2, p);
                return li_res;
                }
                case 204://2012新增
                {
                li_res = encode_frameA4F204(astr_param->dat, 2, p);
                return li_res;
                }*/

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


 
