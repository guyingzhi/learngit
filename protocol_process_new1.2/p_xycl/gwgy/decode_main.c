#include "decode_main.h"

void f_process_000101(char *as_data,int ai_len)
{
	int		li_i, li_j;
	uchar	*p,*ret;
	str_encode_param lstr_up;
	str_encode_param lstr_dn;

	memset(&lstr_up, 0, sizeof(lstr_up));
/*000101|任务编号|1|程序编号|前置编号|规约类型|终端规约报文内容  */
	p = as_data + 26 + 6;	/*3761规约数据 */
	li_j = ai_len - 26 - 6;
	if ((li_i = get_frame_struct(&lstr_up, p, li_j)) != 1)
	{
		if(gi_save_log)
			tracelog("解析规约错误，返回 %d", li_i);
		return;
	}

	/*if (lstr_frame.msa <=1)		//0 上报	1 漏点补招
	{
		queue_in(p,ai_len - 28,2);	//入队处理
		return;
	}*/

	uchar *li_p;
	li_p = lstr_up.frame_head;
	for (li_i = 0; li_i < (6 + 2 + lstr_up.strl.len); li_i++)
		DEBUG("%02x ", *(li_p+li_i));
	DEBUG("\n");
	DEBUG("recv zd frame AFN = %02x\n", lstr_up.afn);
	switch (lstr_up.afn){
		case 0x00:
			decode_AFN00(&lstr_up);
			break;
		case 0x01:   /*上行确认否认*/
			break;
		case 0x02:
			decode_AFN02(&lstr_up);
			break;
		case 0x03:
			decode_AFN03(&lstr_up);
			break;
		case 0x04:   /*上行确认否认*/
			break;
		case 0x05:   /*上行确认否认*/
			break;
		case 0x06:
			decode_AFN06(&lstr_up);
			break;
		case 0x07:   /*保留*/
			break;
		case 0x08:
			break;
		case 0x09:
			decode_AFN09(&lstr_up);
			break;
		case 0x0A:
			decode_AFN0A(&lstr_up);
			break;
		case 0x0B:   /*上行一类或二类数据*/
			break;
		case 0x0C:
			decode_AFN0C(&lstr_up);
			break;
		case 0x0D:
			decode_AFN0D(&lstr_up);
			break;
		case 0x0E:
			decode_AFN0E(&lstr_up);
			break;
		case 0x0F:
			decode_AFN0F(&lstr_up);
			break;
		case 0x10:
			decode_AFN10(&lstr_up);
			break;
		default:
			if (gi_save_data);
				datalog("未定义的AFN类型",&lstr_up);
			break;
	}

	if (lstr_up.seq.con) {     /*发送确认报文*/
		memset(&lstr_dn, 0, sizeof(lstr_dn));
		lstr_dn.strl.gy = lstr_up.strl.gy;
		memset(&lstr_dn.c, 0x00, 1);
		memcpy(&lstr_dn.addr, &lstr_up.addr, sizeof(lstr_dn.addr));
		lstr_dn.afn = 0x00;
		lstr_dn.seq.seq = lstr_up.seq.seq;
		lstr_dn.seq.con = 0;
		lstr_dn.seq.fin = 1;
		lstr_dn.seq.fir = 1;
		lstr_dn.mul_fn.cnt = 1;
		lstr_dn.mul_fn.fn[0] = 1;
		lstr_dn.mul_pn.cnt = 1;
		lstr_dn.mul_pn.pn[0] = 0;
		encode_down_frame(&lstr_dn, 2);
	}
    
	/*
    if ((astr_frame->acd == 1) && (astr_frame->msa <= 1))
    {
        lstr_param.msa = astr_frame->msa;
        lstr_param.addr = astr_frame->addr;
        lstr_param.pfc = astr_frame->seq;
        get_data_ec1(astr_frame,&lc_EC1);
        lc_ECold = GET_TERM_EC1VAL(astr_frame->addr);
        if (lc_EC1 != lc_ECold)
        {
            SAVE_TERM_EC1VAL(astr_frame->addr, lc_EC1);
            lstr_event.Pm = lc_ECold;
            lstr_event.Pn = lc_EC1;
            lstr_param.pn = 0;
            lstr_param.fn = 1;
            encodeframe0E(&lstr_param, &lstr_event, &lstr_out);
            f_get_xh(ls_rwxh);
            get_report_000103(ls_mes, &li_meslen, lstr_out.bytes, lstr_out.len, ls_rwxh);
            f_sendto_mngr(ls_mes, li_meslen);
        }
    }
    if ((li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_TERMBH) && (li_res != ERROR_NOT_FOUND_CJDBH)
        && (li_res != ERROR_NOT_FOUND_SUMBH) && (li_res != ERROR_NOT_FOUND_MNLBH)
        && (li_res != ERROR_DB_DISCONNECT) && (li_res != ERROR_NOT_FOUND_DAID)
        && (li_res != NOT_DEFINE_DATA) && (li_res != ERROR_PNISZERO_ERC) && (li_res != ERROR_WRITE_DATA))
    {
        if (gi_save_data == 1)
        {
            sprintf(ls_ss, "错误的报文,错误代码:%d", li_res);
            datalog(ls_ss, astr_frame);
        }
    }*/
}

void f_process_000200(char *as_data,int ai_len)
{
	int  li_i=0;
	char  lc_rwxh[32]={0};
	char  ls_mes[FRAME_MAXLEN] = {0};
	int  li_meslen=0;

      /*000200|任务编号|1|程序编号|socket识别码|  */
	sscanf(as_data, "%*[^|]|%*[^|]|%*[^|]|%*[^|]|%d|", &li_i);
	DEBUG("socket id = %d\n", li_i);
	f_get_xh(lc_rwxh);
	get_report_000200(ls_mes, &li_meslen, lc_rwxh, li_i);
	f_sendto_mngr(ls_mes, li_meslen);
	DEBUG("send:%s\n", ls_mes);
}

void f_process_000201(char *as_data,int ai_len)
{
	char  lc_rwxh[32]={0};
	char  ls_mes[FRAME_MAXLEN] = {0};
	int  li_meslen=0, li_i;
	int  termal_addr=0, termal_sta=0, front_id=0, prot_type=0;
	uchar log_flg=0;
	char key[HASH_TERMINFO_KEYLEN] = {0};
	int hx_field[30] = {0};
	char hx_val[30][HASH_TERMINFO_VALEN]  = {0};

	/*000201|任务编号|1|程序编号|前置编号|规约类型|终端地址|当前状态(0 掉线 1 在线)|
	报文日志记录标志(0 不记录 1 记录)|终端IP地址|当天终端登录次数|
	终端最后一次登录时间|终端最后一次掉线时间|当天终端在线时间(秒)|
	当天上行报文数|当天上行数据流量(字节)|当天下行报文数|当天下行数据流量(字节)|
	终端最后上报数据时间|终端连接端口号|主动事件上报数|
    */
	li_i = sscanf(as_data, "%*[^|]|%*[^|]|%*[^|]|%*[^|]|\
	%[^|]|%*[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\
	%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\
	%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", 
	hx_val[0], hx_val[1], hx_val[2], hx_val[3], hx_val[4], hx_val[5],
	hx_val[6], hx_val[7], hx_val[8], hx_val[9], hx_val[10],
	hx_val[11], hx_val[12], hx_val[13], hx_val[14], hx_val[15]);

	if (li_i == -1)
		return;
	hx_field[0] = SC_NORMAL_QZ_NO;
	hx_field[1] = SC_NORMAL_TERM_ADDR;
	hx_field[2] = SC_NORMAL_STATE;
	hx_field[3] = SC_NORMAL_LOG;
	hx_field[4] = SC_NORMAL_IP;
	hx_field[5] = SC_LOGIN_TIMES;
	hx_field[6] = SC_LOGIN_TIME;
	hx_field[7] = SC_OFFLINE_TIME;
	hx_field[8] = SC_ONLIE_TIME_SPAN;
	hx_field[9] = SC_UP_REPORT_COUNT;
	hx_field[10] = SC_UP_FLOW;
	hx_field[11] = SC_DOWN_REPORT_COUNT;
	hx_field[12] = SC_DOWN_FLOW;
	hx_field[13] = SC_LAST_REPORT_TIME;
	hx_field[14] = SC_NORMAL_PORT;
	hx_field[15] = SC_EVENT_REPORT_TIMES;
	hx_field[16] = REDIS_END;
	
	front_id = atoi(hx_val[0]);
	termal_addr = atoi(hx_val[1]);
	termal_sta = atoi(hx_val[2]);
	log_flg = atoi(hx_val[3]);
	
	DEBUG("termal_addr = %d, termal_sta = %d, log_flg = %d\n", termal_addr, termal_sta, log_flg);
	log_flg = (log_flg == 0 ? 0 : 1);
	if (log_flg)
		tracelog("内部报文201终端在线状态变化通知:%s\n", as_data);
	termal_sta = (termal_sta == 0 ? 0 : 1);
	/*根据终端地址查询redis库有无档案*/
	if (0) {  /*实时库中无终端信息 */
		if (termal_sta) {
			f_get_xh(lc_rwxh);
			get_report_000204(ls_mes, &li_meslen, lc_rwxh, front_id, prot_type, termal_addr);
			f_sendto_mngr(ls_mes, li_meslen);
			DEBUG("send:%s\n", ls_mes);
		}
		return;
	}
	/*更新终端在线状态*/	
	if (termal_info_key(termal_addr, key, sizeof(key)) > 0) {
		DEBUG("push to redis %s !\n",key);
		li_i = create_hashtable_rd(key, 0, REDIS_GREENCHNEL_FLAG, hx_field, (char**)hx_val, HASH_TERMINFO_VALEN);
	}		
}


