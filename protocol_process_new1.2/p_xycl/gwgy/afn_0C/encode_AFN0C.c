#include "encode_AFN0C.h"

int encode_AFN0C(str_encode_param *astr_param, uchar *usr_dat)
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
                case 2:  /*测量点号*/
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
                case 13:
                case 14:
                    ret = 0;
                    break;
                case 17:  /*总加组号*/
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                    ret = 0;
                    break;
                case 25:  /*测量点号*/
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 57:
                case 58:
                case 65:
                case 66:
                case 67:
                    ret = 0;
                    break;
                case 73:  /*直流模拟量端口号*/
                    ret = 0;
                    break;
                case 81:  /*总加组号*/
                case 82:
                case 83:
                case 84:
                    ret = 0;
                    break;
                case 89:    /*测量点号*/
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
                case 105:
                case 106:
                case 107:
                case 108:
                case 109:
                case 110:
                case 111:
                case 112:
                case 113:
                case 114:
                case 115:
                case 116:
                    ret = 0;
                    break;                       
                case 121:   /*直流模拟量端口号*/
                    ret = 0;
                    break;
                case 129:    /*测量点号*/
                case 130:
                case 131:
                case 132:
                case 133:
                case 134:
                case 135:
                case 136:
                case 137:
                case 138:
                case 139:
                case 140:
                case 141:
                case 142:
                case 143:
                case 144:
                case 145:
                case 146:
                case 147:
                case 148:
                case 149:
                case 150:
                case 151:
                case 152:
                case 153:
                case 154:
                case 155:
                case 156:
                case 157:
                case 158:
                case 159:
                case 160:
                case 161:
                case 162:                   
                case 165:
                case 166:
                case 167:
                case 168:
                case 169:
                case 170:
                case 177:
                case 178:
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


