#include "report_public.h"


void get_report_000103(char *as_report, int *ai_reportlen, uchar *as_mes, int ai_meslen, char *as_rwxh, int prot_type)
{
	int li_i = 0, ret = -1;
	char ls_tmp[32]={0};
	int   termal_addr=0;
	char *p = as_report;
	uint front_id = 0;
	char termal_key[HASH_TERMINFO_KEYLEN] = {0};
	int element[2] = {SC_NORMAL_QZ_NO, REDIS_END};
	char element_val[1][HASH_TERMINFO_VALEN] = {0};

	termal_addr = (*(as_mes+8) >> 4) * 100000000 + (*(as_mes+8) & 0x0F) * 10000000
		+ (*(as_mes+7) >> 4) * 1000000 + (*(as_mes+7)  & 0x0F) * 100000
		+ (*(as_mes+10)<<8) + *(as_mes+9);
	termal_info_key(termal_addr, termal_key, HASH_TERMINFO_KEYLEN);
	ret = get_hashvalue_rd(termal_key, 0, REDIS_GREENCHNEL_FLAG, element, (char **)element_val, HASH_TERMINFO_VALEN, &li_i);
	front_id = (ret < 0 ? 211 : atoi(element_val[0]));
	DEBUG("ret = %d, front_id = %d\n", ret, front_id);
	/*000103|������|1|������|ǰ�ñ��|��Լ����|�ն˵�ַ|�ն˹�Լ��������*/
	strcpy(p, "#^&!12345678#^&!");
	p += 16;
	sprintf(p, "000103|%s|1|%s|%.3d|%.1d|%.12d|",
		as_rwxh,
		gs_cxbh,
		front_id,
		prot_type,
		termal_addr);
	li_i = strlen(p);
	p += li_i;
	memcpy(p, as_mes, ai_meslen);
	p += ai_meslen;
	li_i += ai_meslen;
//    memset(p, 0xff , 5);
//	p += 5;
//	li_i += 5;
	sprintf(ls_tmp, "%.8d", li_i);  //�������ݵĳ���
	memcpy(as_report + 4, ls_tmp, 8);
	sprintf(p, "%c*^!#", check_crc(as_report + 16, li_i));
	p += 5;
	*ai_reportlen = 16 + li_i + 5;
}


/*
    ls_report   ����ı���
    ai_len      ����ı��ĳ���
    astr_frame  �����֡�ṹ��
    ac_PN       �����PNֵ
    as_rwxh     ������������
    ac_djbz     ����Ķ����־
    ai_date     ���������
    ai_res      ����Ľ���ʹ洢���
    FX          ���ʵķ���0Ϊ����1Ϊ����
*/
/*100302|������2|1|������|MSA|SEQ|������|�ն˵�ַ|�ն˹�Լ����|0|
    �ٲ�ɹ�ʧ�ܱ�־|����������/�ٲ�ʧ��ԭ��|����|�����־|*/

/*    ҵ���ʶ��|������|Ӧ���ʶ|������|ǰ�ñ��|MSA|SEQ|������|�ն˱��|�ն˵�ַ|�ն˹�Լ����
|��ɼ�������ʶ|�ɼ������б�|�������|����Ա���|���������־|�ɹ�ʧ�ܱ�ʶ|����������/�ٲ�ʧ��ԭ��|�ļ�λ�þ���·��|�ļ��ṹ*/
void get_report_100302_0001(char *ls_report, int *ai_len, str_encode_param *astr_frame, uchar ac_PN,
     char *as_rwxh, int ai_res, uchar FX)
{
	char ls_tmp[32]={0}, ls_mask[256]={0};
	int li_i, li_j;
	uchar lc_success;
	int termal_addr = 0;
	int dxxh = 1, czybh = 10, rwjsbz = 1;
	char *p = ls_report;
	termal_addr = (astr_frame->addr.a1_high >> 4) * 100000000 + (astr_frame->addr.a1_high & 0x0F) * 10000000
		+ (astr_frame->addr.a1_low >> 4) * 1000000 + (astr_frame->addr.a1_low & 0x0F) * 100000
		+ (astr_frame->addr.a2_high << 8) + astr_frame->addr.a2_low;
	
	if (ai_res == ERROR_SUCCESS){
		lc_success = 1;
		if (FX == 0)
			strcpy(ls_mask,"11001001");
		else
			strcpy(ls_mask,"00110110");
	} else {
		lc_success = 0;
		geterrorname(ls_mask, ai_res);
	}

	strcpy(p, "#^&!12345678#^&!");
	p += 16;
	sprintf(p, "100302|%s|1|%s|%.3d|%.4d|%.4d|0001|%.12d|%.12d|%.1d|%.2d|%.2d|%.2d|%.4d|%.1d|%.1d|%s",
		as_rwxh,
		gs_cxbh,
		211,
		astr_frame->addr.a3.msa,
		astr_frame->seq.seq,
		termal_addr,
		termal_addr,
		astr_frame->strl.gy,
		ac_PN,
		ac_PN,
		dxxh,
		czybh,
		rwjsbz,
		lc_success,
		ls_mask);
	p += strlen(p);
	li_i = strlen(ls_report + 16);
	sprintf(ls_tmp, "%.8d", li_i);
	memcpy(ls_report + 4, ls_tmp, 8);
	sprintf(p, "%c*^!#", check_crc(ls_report + 16, li_i));
	p += 5;
	*ai_len = 16 + li_i + 5;
}

void get_report_000301(char *ls_report, int *ai_len, str_encode_param *astr_frame, char *as_rwxh, uchar commit)
{
    int li_i, termal_addr;
    char ls_tmp[32]={0};

    termal_addr = (astr_frame->addr.a1_high >> 4) * 100000000 + (astr_frame->addr.a1_high & 0x0F) * 10000000
		+ (astr_frame->addr.a1_low >> 4) * 1000000 + (astr_frame->addr.a1_low & 0x0F) * 100000
		+ (astr_frame->addr.a2_high << 8) + astr_frame->addr.a2_low;
    /*000301|������|1|������|MSA|SEQ|�ն˵�ַ|ȷ��/����(1��ȷ��,0:����)*/
    strcpy(ls_report,"#^&!12345678#^&!");
    sprintf(ls_report + 16, "000301|%s|1|%s|%.4d|%.4d|%.12d|%01d",
        as_rwxh,
        gs_cxbh,
        astr_frame->addr.a3.msa,
        astr_frame->seq.seq,
        termal_addr,
        commit);
    li_i = strlen(ls_report + 16);
    sprintf(ls_tmp, "%.8d", li_i);
    memcpy(ls_report + 4, ls_tmp, 8);
    sprintf(ls_report + 16 + li_i,"%c*^!#",check_crc(ls_report + 16,li_i));
    *ai_len = 16 + li_i + 5;
}

void get_report_000200(char *ls_report, int *ai_len, char *as_rwxh, int socket_id)
{
    int li_i;
    char ls_tmp[32]={0};

    /*000200|������|1|������ |socketʶ����|  */
    strcpy(ls_report,"#^&!12345678#^&!");
    sprintf(ls_report + 16, "000200|%s|1|%s|%d|",
        as_rwxh,
        gs_cxbh,
        socket_id);
    li_i = strlen(ls_report + 16);
    sprintf(ls_tmp, "%.8d", li_i);
    memcpy(ls_report + 4, ls_tmp, 8);
    sprintf(ls_report + 16 + li_i,"%c*^!#",check_crc(ls_report + 16,li_i));
    *ai_len = 16 + li_i + 5;
}

void get_report_000204(char *ls_report, int *ai_len, char *as_rwxh, int front_id, int prot_type, int termal_addr)
{
    int li_i;
    char ls_tmp[32]={0};

    /*000204|������|1|������|ǰ�ñ��|��Լ����|�ն˵�ַ|  */
    strcpy(ls_report,"#^&!12345678#^&!");
    sprintf(ls_report + 16, "000204|%s|1|%s|%03d|%01d|%012d|",
        as_rwxh,
        gs_cxbh,
        front_id,
        prot_type,
        termal_addr);
    li_i = strlen(ls_report + 16);
    sprintf(ls_tmp, "%.8d", li_i);
    memcpy(ls_report + 4, ls_tmp, 8);
    sprintf(ls_report + 16 + li_i,"%c*^!#",check_crc(ls_report + 16,li_i));
    *ai_len = 16 + li_i + 5;
}




