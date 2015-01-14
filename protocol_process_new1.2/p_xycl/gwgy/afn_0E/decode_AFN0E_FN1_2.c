#include "decode_AFN0E_FN1_2.h"


int de_AFN0E_ERC1_str(uchar *dat_in, int dat_len, str_afn0e_erc1 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 14)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc1));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->init =  getbytebybit(*p, 0, 1);
	str_out->versionchange = getbytebybit(*p, 1, 1);
	(*ai_step)++;
	p++;
	memcpy(str_out->version_befor, p, 4);
	*ai_step += 4;
	p += 4;
	memcpy(str_out->version_after, p, 4);
	*ai_step += 4;
	p += 4;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC2_str(uchar *dat_in, int dat_len, str_afn0e_erc2 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 6)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc2));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->termarg = getbytebybit(*p, 0, 1);
	str_out->pnarg = getbytebybit(*p, 1, 1);
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC3_str(uchar *dat_in, int dat_len, int erc_len, str_afn0e_erc3 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j, li_m, li_n;
	uchar lc_da1, lc_da2, lc_dt1, lc_dt2;
	str_pn str_p;
	str_fn str_f;

	if (dat_len - erc_len < 0)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc3));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.msa = dataisnull(p, 1);
	str_out->val.msa = *p;
	(*ai_step)++;
	p++;
	if ((erc_len - 6) % 4 != 0)    /*长度不对*/
		return ERROR_FRAME_DATA_LENGTH;
	else
		str_out->val.num = (erc_len - 6) / 4;
	str_out->isnull.num = DATA_ISNOTNULL;
	for (li_i = 0, li_j = 0; li_i < str_out->val.num; li_i++){
		lc_da1 = *p;
		lc_da2 = *(p + 1);
		lc_dt1 = *(p + 2);
		lc_dt2 = *(p + 3);
		*ai_step += 4;
		p += 4;
		str_p = get_PN(lc_da1, lc_da2);
		str_f = get_FN(lc_dt1, lc_dt2);
		for (li_m = 0; li_m < str_f.cnt; li_m++){
			for (li_n = 0; li_n < str_p.cnt; li_n++){
				str_out->isnull.fn[li_j] = DATA_ISNOTNULL;
				str_out->isnull.pn[li_j] = DATA_ISNOTNULL;
				str_out->val.fn[li_j] = str_f.fn[li_m];
				str_out->val.pn[li_j++] = str_p.pn[li_n];
			}
		}
	}	

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC4_str(uchar *dat_in, int dat_len, str_afn0e_erc4 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 7)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc4));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	for (li_i = 0; li_i < 8; li_i ++){
		str_out->state[li_i] = getbytebybit(*p, li_i, 1);
		str_out->afterstate[li_i] = getbytebybit(*(p + 1), li_i, 1);
	}
	(*ai_step) += 2;
	p += 2;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC5_str(uchar *dat_in, int dat_len, str_afn0e_erc5 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 10)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc5));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	for (li_i = 0; li_i < 8; li_i++)
		str_out->val.turn[li_i] = getbytebybit(*p, li_i, 1);
	(*ai_step)++;
	p++;
	str_out->isnull.P1 = getdataformat02(p, &str_out->val.P1, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.P2 = getdataformat02(p, &str_out->val.P1, &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC6_str(uchar *dat_in, int dat_len, str_afn0e_erc6 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 10)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc6));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = getbytebybit(*p, 0, 6);
	(*ai_step)++;
	p++;
	for (li_i = 0; li_i < 8; li_i++)
		str_out->val.turn[li_i] = getbytebybit(*p, li_i, 1);
	(*ai_step)++;
	p++;
	str_out->val.glxfk = getbytebybit(*p, 3, 1);
	str_out->val.yybtk = getbytebybit(*p, 2, 1);
	str_out->val.cxk = getbytebybit(*p, 1, 1);
	str_out->val.sdk = getbytebybit(*p, 0, 1);
	(*ai_step)++;
	p++;
	/*跳闸前功率*/
	str_out->isnull.P1 = getdataformat02(p, &str_out->val.P1, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*跳闸后2分钟的功率*/
	str_out->isnull.P2 = getdataformat02(p, &str_out->val.P2, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*跳闸时功率定值*/
	str_out->isnull.val = getdataformat02(p, &str_out->val.val, &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC7_str(uchar *dat_in, int dat_len, str_afn0e_erc7 *str_out, int *ai_step)
{
	uchar *p = dat_in, luc_i;
	int li_step, li_i;

	if (dat_len < 10)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc7));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *p;
	(*ai_step)++;
	p++;
	for (li_i = 0; li_i < 8; li_i++)
		str_out->val.turn[li_i] = getbytebybit(*p, li_i, 1);
	(*ai_step)++;
	p++;
	str_out->val.gdk = getbytebybit(*p, 1, 1);
	str_out->val.ydk = getbytebybit(*p, 0, 1);
	(*ai_step)++;
	p++;
	/*跳闸时电能量*/
	str_out->isnull.power = getdataformat03(p, &str_out->val.power, &luc_i, &li_step);
	if (luc_i)
		str_out->val.power = str_out->val.power * 1000;
	*ai_step += li_step;
	p += li_step;
	/*跳闸时电能量定值*/
	str_out->isnull.val = getdataformat03(p, &str_out->val.power, &luc_i, &li_step);
	if (luc_i)
		str_out->val.power = str_out->val.power * 1000;
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC8_str(uchar *dat_in, int dat_len, str_afn0e_erc8 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 8)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc8));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->pn = *(p+1) & 0X0F;
	str_out->pn <<= 8;
	str_out->pn |= *p;
	(*ai_step) += 2;
	p += 2;
	str_out->fl = getbytebybit(*p, 0, 1);
	str_out->programtime = getbytebybit(*p, 1, 1);
	str_out->cbday = getbytebybit(*p, 2, 1);
	str_out->k = getbytebybit(*p, 3, 1);
	str_out->bl = getbytebybit(*p, 4, 1);
	str_out->clear = getbytebybit(*p, 5, 1);
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC9_str(uchar *dat_in, int dat_len, str_afn0e_erc9 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 28)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc9));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	str_out->val.flaga = getbytebybit(*p, 0, 1);
	str_out->val.flagb = getbytebybit(*p, 1, 1);
	str_out->val.flagc = getbytebybit(*p, 2, 1);
	str_out->val.type  = getbytebybit(*p, 6, 2);
	(*ai_step)++;
	p++;
	/*Ua/Uab*/
	str_out->isnull.Ua = getdataformat07(p, &str_out->val.Ua, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ub*/
	str_out->isnull.Ub = getdataformat07(p, &str_out->val.Ub , &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Uc/Ucb*/
	str_out->isnull.Uc = getdataformat07(p, &str_out->val.Uc, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ia*/
	str_out->isnull.Ia = getdataformat25(p, &(str_out->val.Ia), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ib*/
	str_out->isnull.Ib = getdataformat25(p, &(str_out->val.Ib), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ic*/
	str_out->isnull.Ic = getdataformat25(p, &(str_out->val.Ic), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*正向有功总电能示值*/
	str_out->isnull.val = getdataformat14(p, &(str_out->val.val), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC10_str(uchar *dat_in, int dat_len, str_afn0e_erc10 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 28)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc10));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	str_out->val.flaga = getbytebybit(*p, 0, 1);
	str_out->val.flagb = getbytebybit(*p, 1, 1);
	str_out->val.flagc = getbytebybit(*p, 2, 1);
	str_out->val.type  = getbytebybit(*p, 6, 2);
	(*ai_step)++;
	p++;
	/*Ua/Uab*/
	str_out->isnull.Ua = getdataformat07(p, &str_out->val.Ua, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ub*/
	str_out->isnull.Ub = getdataformat07(p, &str_out->val.Ub , &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Uc/Ucb*/
	str_out->isnull.Uc = getdataformat07(p, &str_out->val.Uc, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ia*/
	str_out->isnull.Ia = getdataformat25(p, &(str_out->val.Ia), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ib*/
	str_out->isnull.Ib = getdataformat25(p, &(str_out->val.Ib), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ic*/
	str_out->isnull.Ic = getdataformat25(p, &(str_out->val.Ic), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*正向有功总电能示值*/
	str_out->isnull.val = getdataformat14(p, &(str_out->val.val), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC11_str(uchar *dat_in, int dat_len, str_afn0e_erc11 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 24)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc11));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	/*Ua/Uab*/
	str_out->isnull.Ua = getdataformat05(p, &str_out->val.Ua, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ub*/
	str_out->isnull.Ub = getdataformat05(p, &str_out->val.Ub , &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Uc/Ucb*/
	str_out->isnull.Uc = getdataformat05(p, &str_out->val.Uc, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ia*/
	str_out->isnull.Ia = getdataformat05(p, &(str_out->val.Ia), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ib*/
	str_out->isnull.Ib = getdataformat05(p, &(str_out->val.Ib), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*Ic*/
	str_out->isnull.Ic = getdataformat05(p, &(str_out->val.Ic), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*正向有功总电能示值*/
	str_out->isnull.val = getdataformat14(p, &(str_out->val.val), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC12_str(uchar *dat_in, int dat_len, str_afn0e_erc12 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 7)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc12));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->pn = *(p+1) & 0X0F;
	str_out->pn <<= 8;
	str_out->pn |= *p;
	str_out->qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC13_str(uchar *dat_in, int dat_len, str_afn0e_erc13 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 8)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc13));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->pn = *(p+1) & 0X0F;
	str_out->pn <<= 8;
	str_out->pn |= *p;
	str_out->qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	str_out->clear = getbytebybit(*p, 0, 1);
	str_out->dx    = getbytebybit(*p, 1, 1);
	str_out->sy    = getbytebybit(*p, 2, 1);
	str_out->td    = getbytebybit(*p, 3, 1);
	str_out->qy    = getbytebybit(*p, 4, 1);
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC14_str(uchar *dat_in, int dat_len, str_afn0e_erc14 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 10)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc14));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.happentime2 = getdataformat15(p, &str_out->val.happentime2, &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC15_str(uchar *dat_in, int dat_len, str_afn0e_erc15 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j, li_k;

	if (dat_len < 49)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc15));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	str_out->val.flaga = getbytebybit(*p, 0, 1);
	str_out->val.flagb = getbytebybit(*p, 1, 1);
	str_out->val.flagc = getbytebybit(*p, 2, 1);
	str_out->val.type	= getbytebybit(*p, 7, 1);
	(*ai_step)++;
	p++;
	for (li_i = 0; li_i < 3; li_i++){  /*0~2个字节*/
		for (li_j = 0; li_j < 8; li_j ++){   /*0~7位*/
			li_k = li_i * 8 + li_j;
			if (li_k < 19)
				str_out->val.flagyx[li_k] =  getbytebybit(*(p + li_i), li_j, 1);
		}
	}
	*ai_step += 3;
	p += 3;
	/*越限时电压含有率（%）/电流有效值*/
	for (li_i = 0; li_i < 19; li_i ++){
		if (str_out->val.type)    /*判断是电流还是电压越限*/
			str_out->isnull.val[li_i] = getdataformat06(p, &(str_out->val.val[li_i]), &li_step);
		else
			str_out->isnull.val[li_i] = getdataformat05(p, &(str_out->val.val[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC16_str(uchar *dat_in, int dat_len, str_afn0e_erc16 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j, li_k;

	if (dat_len < 9)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc16));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = getbytebybit(*p, 0, 6);
	str_out->val.qzflag = getbytebybit(*p, 7, 1);
	(*ai_step)++;
	p++;
	/*越限标志*/
	str_out->val.flagyxu = getbytebybit(*p, 0, 1);
	str_out->val.flagyxd = getbytebybit(*p, 1, 1);
	(*ai_step)++;
	p++;
	str_out->isnull.val = getdataformat02(p, &(str_out->val.val), &li_step);
	*ai_step += li_step;
	p += li_step;	

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC17_str(uchar *dat_in, int dat_len, str_afn0e_erc17 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j, li_k;

	if (dat_len < 27)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc17));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	str_out->val.flagU= getbytebybit(*p, 0, 1);
	str_out->val.flagI= getbytebybit(*p, 1, 1);
	(*ai_step)++;
	p++;
	/*电压不平衡度*/
	str_out->isnull.valU = getdataformat05(p, &(str_out->val.valU), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*电流不平衡度*/
	str_out->isnull.valI = getdataformat05(p, &(str_out->val.valI), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*U*/
	str_out->isnull.Ua = getdataformat07(p, &(str_out->val.Ua), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.Ub = getdataformat07(p, &(str_out->val.Ub), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.Uc = getdataformat07(p, &(str_out->val.Uc), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*I*/
	str_out->isnull.Ia = getdataformat25(p, &(str_out->val.Ia), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.Ib = getdataformat25(p, &(str_out->val.Ib), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.Ic = getdataformat25(p, &(str_out->val.Ic), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC18_str(uchar *dat_in, int dat_len, str_afn0e_erc18 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j, li_k;

	if (dat_len < 16)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc18));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	str_out->val.flaggy = getbytebybit(*p, 0, 1);
	str_out->val.flagzz = getbytebybit(*p, 1, 1);
	str_out->val.flaghl = getbytebybit(*p, 2, 1);
	(*ai_step)++;
	p++;
	/*电容标志*/
	for (li_i = 0; li_i < 2; li_i++){   /*0~1 个字节*/
		for (li_j = 0; li_j < 8; li_j ++){   /*0~7位*/
			li_k = li_i * 8 + li_j;
			if (li_k < 16)
				str_out->val.flagdr[li_k] = getbytebybit(*(p + li_i), li_j, 1);
		}
	}
	(*ai_step) += 2;
	p += 2;
	/*功率因数*/
	str_out->isnull.cos = getdataformat05(p, &(str_out->val.cos), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*无功功率*/
	str_out->isnull.Q = getdataformat23(p, &(str_out->val.Q), &li_step);
	*ai_step += li_step;
	p += li_step;
	/*电压*/
	str_out->isnull.U= getdataformat07(p, &(str_out->val.U), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC19_str(uchar *dat_in, int dat_len, str_afn0e_erc19 *str_out, int *ai_step)
{
	uchar *p = dat_in, luc_i;
	int li_step;

	if (dat_len < 31)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc19));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = getbytebybit(*p, 0, 6);
	(*ai_step)++;
	p++;
	str_out->val.buyno = (*(p + 3) << 24) + (*(p + 2) << 16) + (*(p + 1) << 8) + *p;
	*ai_step += 4;
	p += 4;
	str_out->val.flag = *p;
	if (str_out->val.flag == 0xAA || str_out->val.flag == 0x55)
		str_out->isnull.flag = DATA_ISNOTNULL;
	else
		str_out->isnull.flag = DATA_ISNULL;
	(*ai_step)++;
	p++;

	/*购电值*/
	str_out->isnull.buyval = getdataformat03(p, &(str_out->val.buyval), &luc_i, &li_step);
	if (luc_i)
		str_out->val.buyval = str_out->val.buyval * 1000;
	*ai_step += li_step;
	p += li_step;
	/*报警门限*/
	str_out->isnull.val1 = getdataformat03(p, &(str_out->val.val1), &luc_i, &li_step);
	if (luc_i)
		str_out->val.val1 = str_out->val.val1 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*跳闸门限*/
	str_out->isnull.val2 = getdataformat03(p, &(str_out->val.val2), &luc_i, &li_step);
	if (luc_i)
		str_out->val.val2 = str_out->val.val2 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*本次购电前剩余电能量*/
	str_out->isnull.power1 = getdataformat03(p, &(str_out->val.power1), &luc_i, &li_step);
	if (luc_i)
		str_out->val.power1 = str_out->val.power1 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*本次购电后剩余电能量*/
	str_out->isnull.power2 = getdataformat03(p, &(str_out->val.power2), &luc_i, &li_step);
	if (luc_i)
		str_out->val.power2 = str_out->val.power2 * 1000;
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC20_str(uchar *dat_in, int dat_len, str_afn0e_erc20 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 22)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc20));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	/*消息认证*/
	str_out->isnull.PW = DATA_ISNOTNULL;
	memcpy(&(str_out->val.PW), p, 16);
	*ai_step += 16;
	p += 16;
	str_out->isnull.MSA = dataisnull(p, 1);
	str_out->val.MSA = *p;
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC21_str(uchar *dat_in, int dat_len, str_afn0e_erc21 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 6)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc21));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->code= *p;
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC22_str(uchar *dat_in, int dat_len, str_afn0e_erc22 *str_out, int *ai_step)
{
	uchar *p = dat_in, luc_i;
	int li_step, li_i;

	if (dat_len < 31)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc22));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = getbytebybit(*p, 0, 6);
	str_out->val.qzflag = getbytebybit(*p, 7, 1);
	(*ai_step)++;
	p++;
	/*越限时对比总加组有功总电能量*/
	str_out->isnull.power1 = getdataformat03(p, &(str_out->val.power1), &luc_i, &li_step);
	if (luc_i)
		str_out->val.power1 = str_out->val.power1 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*越限时参照总加组有功总电能量*/
	str_out->isnull.power2 = getdataformat03(p, &(str_out->val.power2), &luc_i, &li_step);
	if (luc_i)
		str_out->val.power2 = str_out->val.power2 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*越限时差动越限相对偏差值*/
	str_out->isnull.val1 = dataisnull(p, 1);
	str_out->val.val1 = *p;
	(*ai_step)++;
	p++;
	/*越限时差动越限绝对偏差值*/
	str_out->isnull.val2 = getdataformat03(p, &(str_out->val.val2), &luc_i, &li_step);
	if (luc_i)
		str_out->val.val2 = str_out->val.val2 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*对比总加组测量点数量n*/
	str_out->val.num1 = *p;
	(*ai_step)++;
	p++;
	if (dat_len - *ai_step < str_out->val.num1 * 5)
		return ERROR_FRAME_DATA_LENGTH;
	/*越限时对比总加组第i测量点有功总电能示值*/
	for (li_i = 0; li_i < str_out->val.num1; li_i++){
		str_out->isnull.powerval1[li_i] = getdataformat14(p, &(str_out->val.powerval1[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	/*参照总加组测量点数量*/
	str_out->val.num2 = *p;
	(*ai_step)++;
	p++;
	if (dat_len - *ai_step < str_out->val.num2 * 5)
		return ERROR_FRAME_DATA_LENGTH;
	for (li_i = 0; li_i < str_out->val.num2; li_i++){
		str_out->isnull.powerval2[li_i] = getdataformat14(p, &(str_out->val.powerval2[li_i]), &li_step);
		*ai_step += li_step;
		p += li_step;
	}

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC23_str(uchar *dat_in, int dat_len, str_afn0e_erc23 *str_out, int *ai_step)
{
	uchar *p = dat_in, luc_i;
	int li_step, li_i;

	if (dat_len < 16)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc23));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = getbytebybit(*p, 0, 6);
	(*ai_step)++;
	p++;
	for (li_i = 0; li_i < 8; li_i ++)	
		str_out->val.turn[li_i] = getbytebybit(*p, li_i, 1);
	(*ai_step)++;
	p++;
	str_out->isnull.type = dataisnull(p, 1);
	str_out->val.type = *p;
	(*ai_step)++;
	p++;

	/*告警时电能量*/
	str_out->isnull.powerval1 = getdataformat03(p, &(str_out->val.powerval1), &luc_i, &li_step);
	if (luc_i)
		str_out->val.powerval1 = str_out->val.powerval1 * 1000;
	*ai_step += li_step;
	p += li_step;
	/*告警时电控定值*/
	str_out->isnull.powerval2 = getdataformat03(p, &(str_out->val.powerval2), &luc_i, &li_step);
	if (luc_i)
		str_out->val.powerval2 = str_out->val.powerval2 * 1000;
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC24_str(uchar *dat_in, int dat_len, str_afn0e_erc24 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 14)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc24));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	/*越限标志*/
	str_out->val.flaga = getbytebybit(*p, 0, 1);
	str_out->val.flagb = getbytebybit(*p, 1, 1);
	str_out->val.flagc = getbytebybit(*p, 2, 1);
	str_out->val.flagyx = getbytebybit(*p, 6, 2);
	(*ai_step)++;
	p++;
	  /*Ua*/
	str_out->isnull.Ua = getdataformat07(p, &(str_out->val.Ua), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	str_out->isnull.Ub = getdataformat07(p, &(str_out->val.Ub), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	str_out->isnull.Uc = getdataformat07(p, &(str_out->val.Uc), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC25_str(uchar *dat_in, int dat_len, str_afn0e_erc25 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 14)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc25));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;
	/*越限标志*/
	str_out->val.flaga = getbytebybit(*p, 0, 1);
	str_out->val.flagb = getbytebybit(*p, 1, 1);
	str_out->val.flagc = getbytebybit(*p, 2, 1);
	str_out->val.flagyx = getbytebybit(*p, 6, 2);
	(*ai_step)++;
	p++;
	  /*I*/
	str_out->isnull.Ia = getdataformat07(p, &(str_out->val.Ia), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	str_out->isnull.Ib = getdataformat07(p, &(str_out->val.Ib), &li_step);
	(*ai_step) += li_step;
	p += li_step;
	str_out->isnull.Ic = getdataformat07(p, &(str_out->val.Ic), &li_step);
	(*ai_step) += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC26_str(uchar *dat_in, int dat_len, str_afn0e_erc26 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 14)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc26));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	/*越限标志*/
	str_out->val.flagyx = getbytebybit(*p, 6, 2);
	(*ai_step)++;
	p++;
	str_out->isnull.power = getdataformat23(p, &(str_out->val.power), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.val = getdataformat23(p, &(str_out->val.val), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC27_str(uchar *dat_in, int dat_len, str_afn0e_erc27 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 17)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc27));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->isnull.powerval1 = getdataformat14(p, &(str_out->val.powerval1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.powerval2 = getdataformat14(p, &(str_out->val.powerval2), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC28_str(uchar *dat_in, int dat_len, str_afn0e_erc28 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 18)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc28));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->isnull.powerval1 = getdataformat14(p, &(str_out->val.powerval1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.powerval2 = getdataformat14(p, &(str_out->val.powerval2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.val = dataisnull(p, 1);
	str_out->val.val = *p;
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC29_str(uchar *dat_in, int dat_len, str_afn0e_erc29 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 18)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc29));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->isnull.powerval1 = getdataformat14(p, &(str_out->val.powerval1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.powerval2 = getdataformat14(p, &(str_out->val.powerval2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.val = dataisnull(p, 1);
	str_out->val.val = *p;
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC30_str(uchar *dat_in, int dat_len, str_afn0e_erc30 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 13)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc30));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->isnull.powerval = getdataformat14(p, &(str_out->val.powerval), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.val = dataisnull(p, 1);
	str_out->val.val = *p;
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC31_str(uchar *dat_in, int dat_len, str_afn0e_erc31 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 21)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc31));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->isnull.zjcbtime = getdataformat15(p, &(str_out->val.zjcbtime), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.powerval1 = getdataformat14(p, &(str_out->val.powerval1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.powerval2 = getdataformat11(p, &(str_out->val.powerval2), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC32_str(uchar *dat_in, int dat_len, str_afn0e_erc32 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 13)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc32));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.datacount = dataisnull(p, 4);
	str_out->val.datacount = *(p+3);
	str_out->val.datacount <<= 8;
	str_out->val.datacount |= *(p+2);
	str_out->val.datacount <<= 8;
	str_out->val.datacount |= *(p+1);
	str_out->val.datacount <<= 8;
	str_out->val.datacount |= *p;
	*ai_step += 4;
	p += 4;
	str_out->isnull.datalimit= dataisnull(p, 4);
	str_out->val.datalimit = *(p+3);
	str_out->val.datalimit <<= 8;
	str_out->val.datalimit |= *(p+2);
	str_out->val.datalimit <<= 8;
	str_out->val.datalimit |= *(p+1);
	str_out->val.datalimit <<= 8;
	str_out->val.datalimit |= *p;
	*ai_step += 4;
	p += 4;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC33_str(uchar *dat_in, int dat_len, str_afn0e_erc33 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j;

	if (dat_len < 35)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc33));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->pn = *(p+1) & 0X0F;
	str_out->pn <<= 8;
	str_out->pn |= *p;
	(*ai_step) += 2;
	p += 2;	
	for (li_i = 0; li_i < 7; li_i++){
		for (li_j = 0; li_j < 8; li_j++){
			str_out->flag[li_i].ztbw[li_j] =  (*p >> li_j) & 0x01;
		}
		(*ai_step)++;
		p++;
		for (li_j = 0; li_j < 8; li_j++){
			str_out->flag[li_i].ztbw[li_j+8] =  (*p >> li_j) & 0x01;
		}
		(*ai_step)++;
		p++;
	}
	for (li_i = 0; li_i < 7; li_i++){
		for (li_j = 0; li_j < 8; li_j++){
			str_out->flag[li_i].yxzt[li_j] =  (*p >> li_j) & 0x01;
		}
		(*ai_step)++;
		p++;
		for (li_j = 0; li_j < 8; li_j++){
			str_out->flag[li_i].yxzt[li_j+8] =  (*p >> li_j) & 0x01;
		}
		(*ai_step)++;
		p++;
	}

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC34_str(uchar *dat_in, int dat_len, str_afn0e_erc34 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 8)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc34));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->pn = *(p+1) & 0X0F;
	str_out->pn <<= 8;
	str_out->pn |= *p;
	str_out->qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->flaga = getbytebybit(*p, 0, 1);
	str_out->flagb = getbytebybit(*p, 1, 1);
	str_out->flagc = getbytebybit(*p, 2, 1);
	str_out->type  = getbytebybit(*p, 6, 2);
	(*ai_step)++;
	p++;	

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC35_str(uchar *dat_in, int dat_len, str_afn0e_erc35 *str_out, int *ai_step)
{
	uchar *p = dat_in, luc_i;
	int li_step, li_i;

	if (dat_len < 7)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc35));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.port = getbytebybit(*p, 0, 6);
	(*ai_step)++;
	p++;
	str_out->val.number = *p;
	(*ai_step)++;
	p++;
	if (dat_len - *ai_step < str_out->val.number * 8)
		return ERROR_FRAME_DATA_LENGTH;
	for(li_i=0; li_i < str_out->val.number; li_i++){
		str_out->val.str_meterinfo[li_i].MeterAddisnull = getdataformat12(p, &(str_out->val.str_meterinfo[li_i].MeterAdd), &li_step);
		*ai_step += li_step;
		p += li_step;
            str_out->val.str_meterinfo[li_i].xw = ((*p) & 0XE0) >> 5;
            str_out->val.str_meterinfo[li_i].xh = (*p) & 0X0F;       
		(*ai_step)++;
		p++;
            str_out->val.str_meterinfo[li_i].txxy = (*p) & 0X03;
		(*ai_step)++;
		p++;
	}

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC36_str(uchar *dat_in, int dat_len, str_afn0e_erc36 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 7)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc36));
	str_out->happentimeisnull = getdataformat15(p, &str_out->happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	for(li_i = 0; li_i < 4; li_i++)	{
		str_out->ztbw[li_i] = (*p >> (li_i*2)) & 0X03;
		str_out->zt[li_i] = (*(p + 1) >> (li_i*2)) & 0X03;
	}
	*ai_step += 2;
	p += 2;
	
	return ERROR_SUCCESS;
}

int de_AFN0E_ERC37_38_str(uchar *dat_in, int dat_len, str_afn0e_erc37_38 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i;

	if (dat_len < 70)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc37_38));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	(*ai_step) += 2;
	p += 2;
	str_out->isnull.kgcs = getdataformat10(p, &(str_out->val.kgcs ), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.starttime = getdataformat01(p, &(str_out->val.starttime ), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.endtime = getdataformat01(p, &(str_out->val.endtime ), &li_step);
	*ai_step += li_step;
	p += li_step;
	for (li_i = 0; li_i < 2; li_i++){
		str_out->isnull.zxyg[li_i] = getdataformat11(p, &(str_out->val.zxyg[li_i] ), &li_step);
		*ai_step += li_step;
		p += li_step;
		str_out->isnull.fxyg[li_i] = getdataformat11(p, &(str_out->val.fxyg[li_i] ), &li_step);
		*ai_step += li_step;
		p += li_step;
		str_out->isnull.wg1[li_i] = getdataformat11(p, &(str_out->val.wg1[li_i] ), &li_step);
		*ai_step += li_step;
		p += li_step;
		str_out->isnull.wg2[li_i] = getdataformat11(p, &(str_out->val.wg2[li_i] ), &li_step);
		*ai_step += li_step;
		p += li_step;
		str_out->isnull.wg3[li_i] = getdataformat11(p, &(str_out->val.wg3[li_i] ), &li_step);
		*ai_step += li_step;
		p += li_step;
		str_out->isnull.wg4[li_i] = getdataformat11(p, &(str_out->val.wg4[li_i] ), &li_step);
		*ai_step += li_step;
		p += li_step;
	}
	
	return ERROR_SUCCESS;
}

int de_AFN0E_ERC39_str(uchar *dat_in, int dat_len, str_afn0e_erc39 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 21)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc39));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	(*ai_step) += 2;
	p += 2;
	str_out->isnull.time = getdataformat15(p, &(str_out->val.time ), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.zxyg = getdataformat14(p, &(str_out->val.zxyg ), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.zxwg = getdataformat11(p, &(str_out->val.zxwg ), &li_step);
	*ai_step += li_step;
	p += li_step;
	
	return ERROR_SUCCESS;
}

int de_AFN0E_ERC40_str(uchar *dat_in, int dat_len, str_afn0e_erc40 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step, li_i, li_j;

	if (dat_len < 15)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc40));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	str_out->val.qzflag = getbytebybit(*(p+1), 7, 1);
	(*ai_step) += 2;
	p += 2;	
	str_out->val.type = *p;
	(*ai_step)++;
	p++;
	str_out->isnull.addr = dataisnull(p, 6);
	for (li_i = 5, li_j = 0; li_i >= 0; li_i--){
		str_out->val.addr[li_j++] = (*(p+li_i) >> 4) & 0x0f;
		str_out->val.addr[li_j++] = *(p+li_i) & 0x0f;
	}
	(*ai_step) += 6;
	p += 6;
	str_out->val.untype = *p;
	(*ai_step)++;
	p++;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC41_str(uchar *dat_in, int dat_len, str_afn0e_erc41 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 19)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc41));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	(*ai_step) += 2;
	p += 2;	
	str_out->isnull.time = getdataformat01(p, &(str_out->val.time), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.newtime = getdataformat01(p, &(str_out->val.newtime), &li_step);
	*ai_step += li_step;
	p += li_step;

	return ERROR_SUCCESS;
}

int de_AFN0E_ERC42_str(uchar *dat_in, int dat_len, str_afn0e_erc42 *str_out, int *ai_step)
{
	uchar *p = dat_in;
	int li_step;

	if (dat_len < 19)
		return ERROR_FRAME_DATA_LENGTH;
	memset(str_out, 0, sizeof(str_afn0e_erc42));
	str_out->isnull.happentime = getdataformat15(p, &str_out->val.happentime, &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->val.pn = *(p+1) & 0X0F;
	str_out->val.pn <<= 8;
	str_out->val.pn |= *p;
	(*ai_step) += 2;
	p += 2;
	str_out->val.bjcs = *p;
	(*ai_step)++;
	p++;
	str_out->isnull.fstime = getdataformat01(p, &(str_out->val.fstime), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.jstime = getdataformat01(p, &(str_out->val.jstime), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.zxyg1 = getdataformat11(p, &(str_out->val.zxyg1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.fxyg1 = getdataformat11(p, &(str_out->val.fxyg1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.hxdl1 = getdataformat25(p, &(str_out->val.hxdl1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.lxdl1 = getdataformat25(p, &(str_out->val.lxdl1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.hxyggl1 = getdataformat23(p, &(str_out->val.hxyggl1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.lxyggl1 = getdataformat23(p, &(str_out->val.lxyggl1), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.zxyg2 = getdataformat11(p, &(str_out->val.zxyg2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.fxyg2 = getdataformat11(p, &(str_out->val.fxyg2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.hxdl2 = getdataformat25(p, &(str_out->val.hxdl2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.lxdl2 = getdataformat25(p, &(str_out->val.lxdl2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.hxyggl2 = getdataformat23(p, &(str_out->val.hxyggl2), &li_step);
	*ai_step += li_step;
	p += li_step;
	str_out->isnull.lxyggl2 = getdataformat23(p, &(str_out->val.lxyggl2), &li_step);
	*ai_step += li_step;
	p += li_step;	

	return ERROR_SUCCESS;
}

int de_AFN0E_FN1_2(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
	uchar *p=ac_p;
    	int li_i, li_j, li_m=0;
    	int li_ret = ERROR_SUCCESS, li_step;
	char lc_rwbh[32]={0};
    	uchar ec1, ec2, pos1, pos2, erc_cnt, symbol_erc, symbol_erc_len;
    	str_afn0e_erc1  lstr_erc1;
    	str_afn0e_erc2  lstr_erc2;
    	str_afn0e_erc3  lstr_erc3;
    	str_afn0e_erc4  lstr_erc4;
    	str_afn0e_erc5  lstr_erc5;
    	str_afn0e_erc6  lstr_erc6;
    	str_afn0e_erc7  lstr_erc7;
    	str_afn0e_erc8  lstr_erc8;
    	str_afn0e_erc9  lstr_erc9;
    	str_afn0e_erc10  lstr_erc10;
    	str_afn0e_erc11  lstr_erc11;
    	str_afn0e_erc12  lstr_erc12;
    	str_afn0e_erc13  lstr_erc13;
    	str_afn0e_erc14  lstr_erc14;
    	str_afn0e_erc15  lstr_erc15;
    	str_afn0e_erc16  lstr_erc16;
    	str_afn0e_erc17  lstr_erc17;
    	str_afn0e_erc18  lstr_erc18;
    	str_afn0e_erc19  lstr_erc19;
    	str_afn0e_erc20  lstr_erc20;
    	str_afn0e_erc21  lstr_erc21;
    	str_afn0e_erc22  lstr_erc22;
    	str_afn0e_erc23  lstr_erc23;
    	str_afn0e_erc24  lstr_erc24;
    	str_afn0e_erc25  lstr_erc25;
    	str_afn0e_erc26  lstr_erc26;
    	str_afn0e_erc27  lstr_erc27;
    	str_afn0e_erc28  lstr_erc28;
    	str_afn0e_erc29  lstr_erc29;
    	str_afn0e_erc30  lstr_erc30;
    	str_afn0e_erc31  lstr_erc31;
    	str_afn0e_erc32  lstr_erc32;
    	str_afn0e_erc33  lstr_erc33;
    	str_afn0e_erc34  lstr_erc34;
    	str_afn0e_erc35  lstr_erc35;
    	str_afn0e_erc36  lstr_erc36;
    	str_afn0e_erc37_38  lstr_erc37_38;
    	str_afn0e_erc39  lstr_erc39;
    	str_afn0e_erc40  lstr_erc40;
    	str_afn0e_erc41  lstr_erc41;
    	str_afn0e_erc42  lstr_erc42;

	if (ai_len < 4)
		return ERROR_FRAME_DATA_LENGTH;
	ec1 = *p;          /*当前重要事件计数器*/
	ec2 = *(p + 1);   /*当前一般事件计数器*/
	pos1 = *(p + 2);   /*事件记录起始指针*/
	pos2 = *(p + 3);  /*事件记录结束指针*/
	p += 4;
	ai_len -= 4;
	if (pos2 > pos1)
		erc_cnt = pos2 - pos1;
	else
		erc_cnt = pos2 + 256 - pos1;
	switch (ac_FN){
		case 1:
			if (ec1 == 0)
				erc_cnt = 0;
			break;
		case 2:
			if (ec2 == 0)
				erc_cnt = 0;
			break;
	}
	while (erc_cnt--){
		symbol_erc = *p;  /*事件代码*/
		symbol_erc_len = *(p + 1);  /*事件记录长度*/
		p += 2;
		ai_len -= 2;
		li_step = 0;
		switch (symbol_erc){
			case 1:
				li_ret = de_AFN0E_ERC1_str(p, ai_len, &lstr_erc1, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 2:
				li_ret = de_AFN0E_ERC2_str(p, ai_len, &lstr_erc2, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 3:
				li_ret = de_AFN0E_ERC3_str(p, ai_len, symbol_erc_len, &lstr_erc3, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 4:
				li_ret = de_AFN0E_ERC4_str(p, ai_len, &lstr_erc4, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 5:
				li_ret = de_AFN0E_ERC5_str(p, ai_len, &lstr_erc5, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 6:
				li_ret = de_AFN0E_ERC6_str(p, ai_len, &lstr_erc6, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 7:
				li_ret = de_AFN0E_ERC7_str(p, ai_len, &lstr_erc7, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 8:
				li_ret = de_AFN0E_ERC8_str(p, ai_len, &lstr_erc8, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 9:
				li_ret = de_AFN0E_ERC9_str(p, ai_len, &lstr_erc9, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 10:
				li_ret = de_AFN0E_ERC10_str(p, ai_len, &lstr_erc10, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 11:
				li_ret = de_AFN0E_ERC11_str(p, ai_len, &lstr_erc11, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 12:
				li_ret = de_AFN0E_ERC12_str(p, ai_len, &lstr_erc12, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 13:
				li_ret = de_AFN0E_ERC13_str(p, ai_len, &lstr_erc13, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 14:
				li_ret = de_AFN0E_ERC14_str(p, ai_len, &lstr_erc14, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 15:
				li_ret = de_AFN0E_ERC15_str(p, ai_len, &lstr_erc15, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 16:
				li_ret = de_AFN0E_ERC16_str(p, ai_len, &lstr_erc16, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 17:
				li_ret = de_AFN0E_ERC17_str(p, ai_len, &lstr_erc17, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 18:
				li_ret = de_AFN0E_ERC18_str(p, ai_len, &lstr_erc18, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 19:
				li_ret = de_AFN0E_ERC19_str(p, ai_len, &lstr_erc19, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 20:
				li_ret = de_AFN0E_ERC20_str(p, ai_len, &lstr_erc20, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 21:
				li_ret = de_AFN0E_ERC21_str(p, ai_len, &lstr_erc21, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 22:
				li_ret = de_AFN0E_ERC22_str(p, ai_len, &lstr_erc22, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 23:
				li_ret = de_AFN0E_ERC23_str(p, ai_len, &lstr_erc23, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 24:
				li_ret = de_AFN0E_ERC24_str(p, ai_len, &lstr_erc24, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 25:
				li_ret = de_AFN0E_ERC25_str(p, ai_len, &lstr_erc25, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 26:
				li_ret = de_AFN0E_ERC26_str(p, ai_len, &lstr_erc26, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 27:
				li_ret = de_AFN0E_ERC27_str(p, ai_len, &lstr_erc27, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 28:
				li_ret = de_AFN0E_ERC28_str(p, ai_len, &lstr_erc28, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 29:
				li_ret = de_AFN0E_ERC29_str(p, ai_len, &lstr_erc29, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 30:
				li_ret = de_AFN0E_ERC30_str(p, ai_len, &lstr_erc30, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 31:
				li_ret = de_AFN0E_ERC31_str(p, ai_len, &lstr_erc31, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 32:
				li_ret = de_AFN0E_ERC32_str(p, ai_len, &lstr_erc32, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 33:
				li_ret = de_AFN0E_ERC33_str(p, ai_len, &lstr_erc33, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 34:
				li_ret = de_AFN0E_ERC34_str(p, ai_len, &lstr_erc34, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 35:
				li_ret = de_AFN0E_ERC35_str(p, ai_len, &lstr_erc35, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 36:
				li_ret = de_AFN0E_ERC36_str(p, ai_len, &lstr_erc36, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 37:
			case 38:
				li_ret = de_AFN0E_ERC37_38_str(p, ai_len, &lstr_erc37_38, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 39:
				li_ret = de_AFN0E_ERC39_str(p, ai_len, &lstr_erc39, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 40:
				li_ret = de_AFN0E_ERC40_str(p, ai_len, &lstr_erc40, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 41:
				li_ret = de_AFN0E_ERC41_str(p, ai_len, &lstr_erc41, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			case 42:
				li_ret = de_AFN0E_ERC42_str(p, ai_len, &lstr_erc42, &li_step);
				if (li_ret != ERROR_SUCCESS)
					break;
				if (li_step != symbol_erc_len)
					li_ret = ERROR_FRAME_DATA_LENGTH;				
				break;
			default:
				li_ret = ERROR_RANGE_ERC;
				break;
		}
		if (li_ret != ERROR_SUCCESS)
			break;
		p += li_step;
		ai_len -= li_step;
	}
	if (li_ret != ERROR_SUCCESS ){
		/*组错误的内部报文*/
//		get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0);
//		f_sendto_sjcl(&lstr_file, li_ret);
		return li_ret;
	}
		

/*	f_get_xh(lc_rwbh);
		memset(&lstr_file, 0, sizeof(lstr_file));*/
		/*此处为调试代码*/
		/*memset(&lstr_afn0d_f1.isnull, DATA_ISNOTNULL, sizeof(lstr_afn0d_f1.isnull));
		lstr_afn0d_f1.val.TD.year = 14;
		lstr_afn0d_f1.val.TD.mon = 10;
		lstr_afn0d_f1.val.TD.day = 10;
		lstr_afn0d_f1.val.CBSJ.year = 14;
		lstr_afn0d_f1.val.CBSJ.mon = 10;
		lstr_afn0d_f1.val.CBSJ.day = 10;
		lstr_afn0d_f1.val.CBSJ.hour = 23;
		lstr_afn0d_f1.val.CBSJ.min = 55;
		lstr_afn0d_f1.val.FLS = 3;
		for (li_j = 0; li_j < lstr_afn0d_f1.val.FLS+1; li_j++){
			lstr_afn0d_f1.val.Pcode[li_j] = li_j;
			lstr_afn0d_f1.val.Qcode[li_j] = li_j;
			lstr_afn0d_f1.val.Q12code[li_j] = li_j;
			lstr_afn0d_f1.val.Q34code[li_j] = li_j;
		}
		ac_PN = 1;
		ac_FN = 1;*/		
		/*此处为调试代码*/
		
/*		if (de_AFN0D_FN1_2_9_10_save(&lstr_file, &lstr_afn0d_f1, ac_PN, ac_FN, li_i) == ERROR_SUCCESS){
			get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, ERROR_SUCCESS, 0);  //get_report_100302_0001(lstr_file.info, &li_m, str_upframe, ac_PN, lc_rwbh, li_ret, 0, &lstr_file)
			f_sendto_sjcl(&lstr_file, ERROR_SUCCESS);
		}*/
	
 
/*   if (astr_frame->msa >= MIN_MSA)
    {
        if (ac_FN == 1)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 0);
        }
        if (ac_FN == 2)
        {
            get_report_100302_0001(ls_mes, &li_meslen, astr_frame, ac_PN, ls_rwxh, 1, li_intdate, li_res, 1);
        }
        f_sendto_mngr(ls_mes, li_meslen);
    }*/
/*    if (astr_frame->msa == 1)
    {
        f_lostcheck_process(0x0d, astr_frame->addr, ac_FN, ac_PN, li_intdate);
    }*/
	return ERROR_SUCCESS;
}


