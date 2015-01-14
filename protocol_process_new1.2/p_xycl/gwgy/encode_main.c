#include "encode_main.h"


/*�ն�ʵʱ�ٲ��౨��*/
int get_100101_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    int li_i=0, li_j=0;

    li_j = sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    if (li_j <= 0)
        return -1;
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr / 100000) % 100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr / 10000000) % 100);
    dat_out->addr.a2_low = (termal_addr % 100000) % 256;
    dat_out->addr.a2_high = (termal_addr % 100000) / 256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len <= 1)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        li_j = sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt]);  /*ȡ������*/
        if (li_j > 0)
            dat_out->mul_fn.cnt++;
        for ( ; dat_len > 0 && *p != ','; dat_len--, p++) {};
    }

    dat_out->mul_pn.cnt = 1;
    dat_out->mul_pn.pn[0] = 0;

    dat_out->afn = 0x0c;
    return ERROR_SUCCESS;
}

/*������ʵʱ�ٲ��౨��*/
int get_100102_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    
    char *p = dat_in;
    uint termal_addr = 0;
    int li_i=0, li_j=0;

    li_j = sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    if (li_j <= 0)
        return -1;
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr / 100000) % 100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr / 10000000) % 100);
    dat_out->addr.a2_low = (termal_addr % 100000) % 256;
    dat_out->addr.a2_high = (termal_addr % 100000) / 256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len <= 1)
        return -2;
    p++;
    dat_len--;

    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        li_j = sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt]);  /*ȡ������*/
        if (li_j > 0)
            dat_out->mul_fn.cnt++;
        for ( ; dat_len > 0 && *p != ','; dat_len--, p++) {};
    }
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        li_j = sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt]);  /*ȡ������*/
        if (li_j > 0)
            dat_out->mul_pn.cnt++;
        for ( ; dat_len > 0 && *p != ','; dat_len--, p++) {};
    }

    dat_out->afn = 0x0c;
    return ERROR_SUCCESS;
}

/*�����ٲ���*/
int get_200101_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0, lui_m;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    DEBUG("termal_addr = %d\n", termal_addr);
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    DEBUG("msa = %d\n", lui_i);
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    DEBUG("dat_out->mul_fn.cnt = %d\n", dat_out->mul_fn.cnt);
    for (lui_m = 0; lui_m < dat_out->mul_fn.cnt; lui_m++)
        DEBUG("dat_out->mul_fn.fn[%d] = %d\n", lui_m, dat_out->mul_fn.fn[lui_m]);
    
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    DEBUG("dat_out->mul_pn.cnt = %d\n", dat_out->mul_pn.cnt);
    for (lui_m = 0; lui_m < dat_out->mul_pn.cnt; lui_m++)
        DEBUG("dat_out->mul_pn.pn[%d] = %d\n", lui_m, dat_out->mul_pn.pn[lui_m]);
    
    if (dat_len == 0)
        return -4;
    p++;
    dat_len--;
    
    if (dat_len & 1)  /*ż���ж�*/
        return -5;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }
    DEBUG("dat_out->dat_len = %d\n", dat_out->dat_len);
    for (lui_m = 0; lui_m < dat_out->dat_len; lui_m++)
        DEBUG("dat_out->dat[%d] = %x\n", lui_m, dat_out->dat[lui_m]);
        
    dat_out->afn = 0x0d;
    return ERROR_SUCCESS;
}

/*�����ٲ���*/
int get_300xxx_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -4;
    p++;
    dat_len--;
    
    if (dat_len & 1)  /*ż���ж�*/
        return -5;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }

    dat_out->afn = 0x0d;
    return ERROR_SUCCESS;
}

/*����������*/
int get_400xxx_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -4;
    p++;
    dat_len--;
    
    if (dat_len & 1)  /*ż���ж�*/
        return -5;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }

    dat_out->afn = 0x04;
    return ERROR_SUCCESS;
}


/*�ն˲����ٲ⣬�п��ܴ�������*/
int get_500101_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return ERROR_SUCCESS;
    p++;
    dat_len--;
    
    if (dat_len & 1)  /*ż���ж�*/
        return -4;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }

    dat_out->afn = 0x0a;
    return ERROR_SUCCESS;
}

/*����������ٲ⣬����������*/
int get_500102_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ','; dat_len--, p++) {};
    }

    dat_out->afn = 0x0a;
    return ERROR_SUCCESS;
}

/*������*/
int get_600xxx_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;
	
    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;

    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return ERROR_SUCCESS;
    p++;
    dat_len--;

    if (dat_len & 1)  /*ż���ж�*/
        return -4;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }
	 
    dat_out->afn = 0x05;
    return ERROR_SUCCESS;
}

/*��λ����*/
int get_600103_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ','; dat_len--, p++) {};
    }

    dat_out->afn = 0x01;
    return ERROR_SUCCESS;
}


/*�����ն����ü���Ϣ*/
int get_700101_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ','; dat_len--, p++) {};
    }

    dat_out->afn = 0x09;
    return ERROR_SUCCESS;
}

/*�¼��ٲ�*/
int get_800101_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -4;
    p++;
    dat_len--;
    
    if (dat_len & 1)  /*ż���ж�*/
        return -5;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }

    dat_out->afn = 0x0e;
    return ERROR_SUCCESS;
}

/*��·�ӿڼ��*/
int get_900101_str(char *dat_in, int dat_len, str_encode_param *dat_out)
{
    char *p = dat_in;
    uint termal_addr = 0;
    uint lui_i=0;

    sscanf(p, "%u", &termal_addr);  /*ȡ�ն˵�ַ*/
    dat_out->addr.a1_low = ByteToBCDByte((termal_addr/100000)%100);
    dat_out->addr.a1_high = ByteToBCDByte((termal_addr/10000000)%100);
    dat_out->addr.a2_low = (termal_addr%100000)%256;
    dat_out->addr.a2_high = (termal_addr%100000)/256;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -1;
    p++;
    dat_len--;

    sscanf(p, "%u", &lui_i);  /*ȡMSA*/
    dat_out->addr.a3.msa = lui_i;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {};
    if (dat_len == 0)
        return -2;
    p++;
    dat_len--;
    
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_fn.fn[dat_out->mul_fn.cnt++]);  /*ȡ������*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return -3;
    p++;
    dat_len--;
    for ( ; dat_len > 0 && *p != '|'; dat_len--, p++) {
        sscanf(p, "%u", &dat_out->mul_pn.pn[dat_out->mul_pn.cnt++]);  /*ȡ�ɼ���*/
        for ( ; dat_len > 0 && *p != ',' && *p != '|'; dat_len--, p++) {};
        if (*p == '|')
            break;
    }
    if (dat_len == 0)
        return ERROR_SUCCESS;
    p++;
    dat_len--;
    
    if (dat_len & 1)  /*ż���ж�*/
        return -4;
    for ( ; dat_len > 0; dat_len -= 2, p += 2) {
        sscanf(p, "%2x", &dat_out->dat[dat_out->dat_len++]);
        if (dat_out->dat_len >= USRDATA_MAXLEN)
            break;
    }

    dat_out->afn = 0x02;
    return ERROR_SUCCESS;
}


int encode_down_frame(str_encode_param *encode_param, int prot_type)
{
    char ls_rwxh[32]= {0};
    char ls_mes[FRAME_MAXLEN] = {0};
    int li_meslen;
    int ret, li_i;
    str_bytesframe astr_out;
    uchar *p, *pbak;
    uchar pw_flg = 0;  /*�Ƿ�Я�������־*/

    memset(&astr_out, 0, sizeof(astr_out));
    p = astr_out.bytes;
    pbak = astr_out.bytes;

    encode_param->strl.gy = 2;
    encode_param->c.dir = 0;
    encode_param->c.prm = 1;
    encode_param->c.fcb_acd = 0;
    encode_param->c.fcv_keep = 0;
    encode_param->c.fun = 0;
    encode_param->addr.a3.gpaddr_v = 0;
    encode_param->seq.tpv = 0;
    encode_param->seq.fir = 1;
    encode_param->seq.fin = 1;
    encode_param->seq.con = 0;
    encode_param->seq.seq = 0;
    
    *p = 0x68;
    p++;
    astr_out.len++;
    *p |= encode_param->strl.gy;  //����������
    p++;
    astr_out.len++;
    *p = 0;
    p++;
    astr_out.len++;
    *p = *(p-2);
    p++;
    astr_out.len++;
    *p = *(p-2);
    p++;
    astr_out.len++;
    *p = 0x68;
    p++;
    astr_out.len++;
    memcpy(p, &encode_param->c, 1);
    p++;
    astr_out.len++;
    *p = encode_param->addr.a1_low;
    p++;
    astr_out.len++;
    *p = encode_param->addr.a1_high;
    p++;
    astr_out.len++;
    *p = encode_param->addr.a2_low;
    p++;
    astr_out.len++;
    *p = encode_param->addr.a2_high;
    p++;
    astr_out.len++;
    memcpy(p, &encode_param->addr.a3, 1);
    p++;
    astr_out.len++;
    *p = encode_param->afn;
    p++;
    astr_out.len++; 
    memcpy(p, &encode_param->seq, 1);
    p++;
    astr_out.len++;   

    DEBUG("down encode frame AFN%02X!\n", encode_param->afn);
	
    switch (encode_param->afn){
        case 0x00:
            ret = encode_AFN00(encode_param, p);
            encode_param->seq.tpv = 1;
            break;
        case 0x01:
            ret = encode_AFN01(encode_param, p);
            encode_param->c.fun = 1;  /*��λ����*/
            pw_flg = 1;
            encode_param->seq.tpv = 1;
            break;
        case 0x02:
            ret = 0;
            encode_param->c.fun = 9;  /*��·����*/
            break;
        case 0x03:
            ret = encode_AFN03(encode_param, p);
            break;
        case 0x04:
            ret = encode_AFN04(encode_param, p);
            encode_param->c.fun = 10;  /*����һ������*/
            pw_flg = 1;
            encode_param->seq.tpv = 1;
            break;
        case 0x05:
            ret = encode_AFN05(encode_param, p);
            encode_param->c.fun = 10;  /*����һ������*/
            pw_flg = 1;
            encode_param->seq.tpv = 1;
            break;
        case 0x06:
            ret = encode_AFN06(encode_param, p);
            pw_flg = 1;
            encode_param->seq.tpv = 1;
            break;
        case 0x07:
            ret = 0;
            break;
        case 0x08:
            ret = encode_AFN08(encode_param, p);
            break;
        case 0x09:
            ret = encode_AFN09(encode_param, p);
            encode_param->c.fun = 11;  /*�����������*/
            encode_param->seq.tpv = 1;
            break;
        case 0x0A:
            ret = encode_AFN0A(encode_param, p);
            encode_param->c.fun = 11;  /*�����������*/
            encode_param->seq.tpv = 1;
            break;
        case 0x0B:
            ret = encode_AFN0B(encode_param, p);
            encode_param->seq.tpv = 1;
            break;
        case 0x0C:
            ret = encode_AFN0C(encode_param, p);
            encode_param->c.fun = 11;  /*�����������*/
            encode_param->seq.tpv = 1;
            break;
        case 0x0D:
            ret = encode_AFN0D(encode_param, p);
            encode_param->c.fun = 11;  /*�����������*/
            encode_param->seq.tpv = 1;
            break;
        case 0x0E:
            ret = encode_AFN0E(encode_param, p);
            encode_param->seq.tpv = 1;
            break;
        case 0x0F:
            ret = encode_AFN0F(encode_param, p);
            encode_param->c.fun = 10;  /*����һ������*/
            pw_flg = 1;
            encode_param->seq.tpv = 1;
            break;
        case 0x10:
            ret = encode_AFN10(encode_param, p);
            encode_param->c.fun = 10;  /*����һ������*/
            pw_flg = 1;
            encode_param->seq.tpv = 1;
            break;
        default:
            ret = -1;
            break;
    }
    if (ret < 0)
        return ret;
    if (ret < 4)
        return ERROR_FRAME_DATA_LENGTH;  //���ݳ��Ȳ���
    p += ret;
    astr_out.len += ret;
    if (pw_flg){
        memcpy(p, encode_param->aux.pw, 16);
        p += 16;
        astr_out.len += 16;
    }
    if (encode_param->seq.tpv){
        AddTP(p, encode_param->seq.seq, &li_i);
        p += li_i;
        astr_out.len += li_i;
    }
    *(pbak+1) |= ((astr_out.len-6) << 2);  //���ȸ�ֵ
    *(pbak+2) = (astr_out.len-6) >> 6;
    *(pbak+3) = *(pbak+1);
    *(pbak+4) = *(pbak+2);
    memcpy(pbak + 6, &encode_param->c, 1);  /*���¸�ֵ������*/
    memcpy(pbak + 13, &encode_param->seq, 1);   /*���¸�ֵSEQ*/
    *p = check_crc(pbak+6, astr_out.len-6);
    p++;
    astr_out.len++;
    *p = 0x16;
    p++;
    astr_out.len++;

    if (astr_out.len > PROT_MAXLEN)
        return ERROR_FRAME_LENGTH;  //����3761���ĳ���

    DEBUG("frame 3761:");
    for (li_i = 0; li_i < astr_out.len; li_i++)
        DEBUG("%02x ", astr_out.bytes[li_i]);
    DEBUG("\n");

    f_get_xh(ls_rwxh);
    get_report_000103(ls_mes, &li_meslen, astr_out.bytes, astr_out.len, ls_rwxh, prot_type);
    f_sendto_mngr(ls_mes, li_meslen);

    DEBUG("send:%s\n", ls_mes);

    return ERROR_SUCCESS;
}

void encode_main(char *dat_in, int dat_len)
{

    str_encode_param astr_param;
    int ret, ywbzm=0, prot_type=0, li_i = 0;
    char *p = dat_in;

    memset(&astr_param, 0, sizeof(astr_param));
    astr_param.afn = 0xff;  /*�����ڵ�AFN*/
    DEBUG("recv web frame:%s\n", dat_in);

    if (dat_len > FRAME_MAXLEN || dat_len == 0)
        return;
    sscanf(p, "%d", &ywbzm);  /*ȡҵ���ʶ��*/
    DEBUG("ywbzm = %d\n", ywbzm);
    for (; dat_len > 0 && *p != '|'; dat_len--, p++) {};  /*��λָ��*/
    if (dat_len <= 1)
        return;
    p++;
    dat_len--;
    sscanf(p, "%d", &li_i);  /*ȡMSA*/
    DEBUG("msa = %d\n", li_i);
    astr_param.addr.a3.msa = li_i;    
    for (; dat_len > 0 && *p != '|'; dat_len--, p++) {};  /*��λָ��*/
    if (dat_len <= 1)
        return;
    p++;
    dat_len--;
    sscanf(p, "%d", &prot_type);  /*ȡЭ������*/
    DEBUG("prot_type = %d\n", prot_type);
    for (; dat_len > 0 && *p != '|'; dat_len--, p++) {};  /*��λָ��*/
    if (dat_len <= 1)
        return;
    p++;
    dat_len--;
    switch (ywbzm) {
        case 100101:
            ret = get_100101_str(p, dat_len, &astr_param);
        case 100102:
            ret = get_100102_str(p, dat_len, &astr_param);
            break;
        case 200101:
            ret = get_200101_str(p, dat_len, &astr_param);
            break;
        case 300101:
        case 300102:
            ret = get_300xxx_str(p, dat_len, &astr_param);
            break;
        case 400101:
        case 400102:
            ret = get_400xxx_str(p, dat_len, &astr_param);
            break;
        case 500101:
            ret = get_500101_str(p, dat_len, &astr_param);
            break;
        case 500102:
            ret = get_500102_str(p, dat_len, &astr_param);
            break;
        case 600101:
        case 600102: 
            ret = get_600xxx_str(p, dat_len, &astr_param);
            break;
        case 600103:
            ret = get_600103_str(p, dat_len, &astr_param);
            break;
        case 700101:
            ret = get_700101_str(p, dat_len, &astr_param);
            break;
        case 800101:
            ret = get_800101_str(p, dat_len, &astr_param);
            break;
        case 900101:
            ret = get_900101_str(p, dat_len, &astr_param);
            break;
        default:
            ret = -1;
            return;
    }
    if (ret != ERROR_SUCCESS) {
        if (gi_save_log)
            tracelog("down decode %u inter_frame error:%d\n", ywbzm, ret);
        DEBUG("down decode %u inter_frame error:%d\n", ywbzm, ret);
        return;
    }

    DEBUG("\n\n******* SEND  %02d-%02d-%02d %02d:%02d:%02d********\n", gdt_now.year-100, gdt_now.mon, gdt_now.day, gdt_now.hour,  gdt_now.min, gdt_now.sec);
    ret = encode_down_frame(&astr_param, prot_type);
    if (ret != ERROR_SUCCESS) {
        if (gi_save_log)
            tracelog("down encode frame error:%d\n", ret);
        DEBUG("down encode frame error:%d\n", ret);
        return;
    }

    return;		
}

