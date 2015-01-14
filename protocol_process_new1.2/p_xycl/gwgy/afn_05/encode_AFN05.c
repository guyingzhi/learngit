#include "encode_AFN05.h"

int encode_AFN05(str_encode_param *astr_param, uchar *usr_dat)
{

    int li_i, li_j;    
    int ret=0, li_len=0;
    str_dataflag data_id;
    uchar *p, *pbak;
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
                    /******遥控跳闸*********/
                    ret = encodedataformat05_F1(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 2:
                    ret = 0;
                    break;
                case 9:
                    /******时段工控投入**********/
                    ret = encodedataformat05_F9(astr_param->dat,astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 10:
                case 11:
                    ret = 0;
                    break;
                case 12:
                    /******当前功率下浮控投入********/
                    ret = encodedataformat05_F12(astr_param->dat,astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 23:
                case 24:
                    ret = 0;
                    break;
                case 25:
                    /*******终端保电投入*******/
                    ret = encodedataformat05_F25(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 26:
                case 27:
                case 28:
                case 29:
                    ret = 0;
                    break;
                case 30:
                    /*******终端对电能表对时功能******/
                    ret = encodedataformat05_F30(astr_param->dat,astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 31:
                    /*******对时命令*******/
                    ret = encodedataformat05_F31(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 32:
                    /*******中文信息*******/
                    ret = encodedataformat05_F32(astr_param->dat, astr_param->dat_len, p);//???
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                    ret = 0;
                    break;
                case 41:
                    /*******电容器控制投入*******/
                    ret = encodedataformat05_F41(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 42:
                    /*******电容器控制切除*******/
                    ret = encodedataformat05_F42(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                    /*******命令指定通信端口暂停抄表*******/
                    ret = encodedataformat05_F49(astr_param->dat,astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 149:
                    /*******电能表通信参数自动维护功能开启和关闭*******/
                    ret = encodedataformat05_F149(astr_param->dat, astr_param->dat_len, p);
                    if (ret < 0)
                        goto out;
                    p += ret;
                    li_len += ret;
                    break;
                case 150:
                    ret = 0;
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
