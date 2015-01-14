#include "decode_AFN0C.h"

int decode_AFN0C(str_encode_param *astr_frame)
{
	uchar *P;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	int li_len, li_i, li_j, li_res;
	int li_step;
	str_pn lstr_PN;
	str_fn lstr_FN;
	P = astr_frame->dat; 
	li_len = 8;
	P = P + 2;
	if (astr_frame->seq.tpv== 1)
	  li_len = li_len + 6;    			 /*时间标签6个字节**/
	if (astr_frame->c.fcb_acd)  		/*EC占两个字节*/
	    li_len = li_len + 2;
	li_len = astr_frame->strl.len - li_len;
	if (li_len <= 0)
	{
	    return ERROR_FRAME_LENGTH;
	}
	while (li_len > 0)
	{
		lc_DA1 = *P;
		lc_DA2 = *(P + 1);
		lc_DT1 = *(P + 2);
		lc_DT2 = *(P + 3);
		lstr_FN = get_FN(lc_DT1, lc_DT2);
		if ((lstr_FN.cnt== 1) && (lstr_FN.fn[0] == 0)) 
		{
		    return ERROR_RANGE_FN;
		}

		lstr_PN = get_PN(lc_DA1, lc_DA2);

		P = P + 4;
		li_len = li_len - 4;
		for (li_i = 0;li_i < lstr_PN.cnt;li_i++)
		{
		    for (li_j = 0;li_j < lstr_FN.cnt;li_j++)
		    {
			li_step = 0;
			switch(lstr_FN.fn[li_j])
		        {
				case 1:
					break;
				case 2:
				{	/********终端日历时钟*********/
					li_res = de_AFN0C_FN2(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 3:
				{	/*********终端参数状态********/
					li_res = de_AFN0C_FN3(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 4:
				{	/*********终端上行通信状态********/
					li_res = de_AFN0C_FN4(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 5:
				{	
					/**********终端控制设置状态********/
					li_res = de_AFN0C_FN5(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 6:
				{	
					/***********终端当前控制状态*******/
					li_res = de_AFN0C_FN6(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 7:
				{	
					/*********终端计数器当前值********/
					li_res = de_AFN0C_FN7(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 8:
				{	
					/*********终端事件标状态*********/
					li_res = de_AFN0C_FN8(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 9:
				{
					/*********终端状态量及变位标志*********/
					li_res = de_AFN0C_FN9(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 10:
				{
					/*********终端与主站当日月通信流量*********/
					li_res = de_AFN0C_FN10(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 11:
				{
					/*********终端集中抄表状态信息*********/
					li_res = de_AFN0C_FN11(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 12:
				{
					/*********控制输出回路开关接入状态量及变化标志********/
					li_res = de_AFN0C_FN12(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 13:
				{
					/*********搜索到的电表信息********
					li_res = de_AFN0C_FN13(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 14:
				{
					/*********文件传输末收到的数据段********
					li_res = de_AFN0C_FN14(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
					break;
				}
					/********F15~F16备用**************/
				case 17:
					/*当前总加有功功率*/
				{
					li_res = de_AFN0C_FN17(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if ((li_res != ERROR_SUCCESS) &&(li_res !=ERROR_NOT_FOUND_CJDBH))
						return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
					break;
				}
				case 18:
				{
					/********当前总共无功功率********/
					li_res = de_AFN0C_FN18(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 19:
				{
					/********当日总加工电能量*******/
					li_res = de_AFN0C_FN19(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 20:
				{
					/*********当日总加无功电能量*******/
					li_res = de_AFN0C_FN20(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 21:
				{
					/*********当日总加有功电能量********/
					li_res = de_AFN0C_FN21(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 22:
				{	/*********当月总加无功电能量*******/
					li_res = de_AFN0C_FN22(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 23:
				{	/********终端当前剩余电量********/
					li_res = de_AFN0C_FN23(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 24:
				{	/*********当前功率下浮控控后总加有功功率冻结值******/
					li_res = de_AFN0C_FN24(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 25:
				{	/*********当前三相及总有无功功率，功率因数，三相电压
						电流，零序电流，视在功率******/
					li_res = de_AFN0C_FN25(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 26:
				{	/*********A,B,C三相断相统计数据及最近一次断相记录*****/
					li_res = de_AFN0C_FN26(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 27:
				{	/*********电能表日历时钟，编程次数，及最近一次操作时间*****/
					li_res = de_AFN0C_FN27(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 28:
				{	/********电表运行状态字及其变化标志******/
					li_res = de_AFN0C_FN28(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 29:
				{	/*********当前铜损，铁损有功总电能市值****/
					li_res = de_AFN0C_FN29(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 30:
				{	/*******上一结算日铜损，铁损有功总电能市值****/
					li_res = de_AFN0C_FN30(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 31:
				{	/*********当前ABC,三相正反/反向有功电能市值，组合无功1/2电能市值*****/
					li_res = de_AFN0C_FN31(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 32:
				{	/******上一结算日ABC,三正相反向有功电能市值，组合无功1/2电能市值*****/
					li_res = de_AFN0C_FN32(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 33:
				{	
					/******当前正向有无功电能市值，一四象限无功电能市值***/
					li_res = de_AFN0C_FN33(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 34:
				{	/******当前反向有无功电能市值，二三象限无功电能市值***/
					
					li_res = de_AFN0C_FN34(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 35:
				{	/******当月正向有无功最大需量及发生时间**/
					
					li_res = de_AFN0C_FN35(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 36:
				{	/*****当月反向有无功最大需量及发生时间**/
					
					li_res = de_AFN0C_FN36(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 37:
				{	/*****上月正向有无功电能市值，一四象限无功电能市值*/
					
					li_res = de_AFN0C_FN37(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 38:
				{	/*****上月正向有无功电能市值，二三象限无功电能市值*/
					
					li_res = de_AFN0C_FN38(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 39:
				{	/***上月正向有无功最大需量及发生时间*/
					
					li_res = de_AFN0C_FN39(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 40:
				{	/*****上月反向有无功最大需量及发生时间*/
					
					li_res = de_AFN0C_FN40(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 41:
				case 42:
				case 43:
				case 44:
				case 45:
				case 46:
				case 47:
				case 48:
				{	/****当日,月正向有功正向无功电能量*/
					
					li_res = de_AFN0C_FN41_F48(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 49:
				{	/****当前电压电流相位角*/
					
					li_res = de_AFN0C_FN49(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
			/*	case 50:
				case 51:
				case 52:
				case 53:
				case 54:          
				case 55:
				case 56:*/
				case 57:
				{	/*****当前A  B C 三相电压，电流2 ~N次谐波有效值*/
					
					li_res = de_AFN0C_FN57(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 58:
				{	/*****当前A  B C 三相电压，电流2 ~N次谐波含有率*/
					
					li_res = de_AFN0C_FN58(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
			    /*case 59:
				case 60:
				case 61:
				case 62:
				case 63:
				case 64:*/
				case 65:
				{	/*****当前电容投切状态*/
					
					li_res = de_AFN0C_FN65(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 66:
				{	/*****当前电容累计补偿投入的时间和次数*/
					
					li_res = de_AFN0C_FN66(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 67:
				{	/*****当日当月电容器累计补偿的无功电能量*/
					
					li_res = de_AFN0C_FN67(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 73:
				{	/****直流模拟量当前数据*/
					
					li_res = de_AFN0C_FN73(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 81:
				case 82:
				{	/****小时冻结总加有功功率和小时冻结总加无功功率*/
					
					li_res = de_AFN0C_F81_F82(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 83:
				case 84:
				{	/***小时冻结总加有功总电能量和小时冻结总加无功总电能量*/
					
					li_res = de_AFN0C_F83_F84(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 89:
				case 90:
				case 91:
				case 92:
				case 93:
				case 94:
				case 95:
				case 96:
				{	/***小时冻结有功功率无功功率ABC*/
					
					li_res = de_AFN0C_F89_F96(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 97:
				case 98:
				case 99:
				{	/***小时冻结ABC   电压*/
					
					li_res = de_AFN0C_F97_F99(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 100:
				case 101:
				case 102:
				case 103:
				{	/***小时ABC相电流***/
					
					li_res = de_AFN0C_F100_F103(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 104:
				case 105:
				case 106:
				case 107:
				case 108:
				{	/***小时冻结正向反向/无功有功/总电能量***/
					
					li_res = de_AFN0C_F105_F108(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 109:
				case 110:
				case 111:
				case 112:
				{	/***小时冻结正向反向/无功有功/总电能示值***/
					
					li_res = de_AFN0C_F109_F112(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 113:
				case 114:
				case 115:
				case 116:
				{	/***小时冻结ABC Z 功率因数***/
					
					li_res = de_AFN0C_F113_F116(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 121:
				{	/***小时冻结直流模拟量***/
					
					li_res = de_AFN0C_F121(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 129:
					{	/***当前正向有功电能示值*/
					
					li_res = de_AFN0C_F121(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 130:
					{	/***当前正向无功电能示值***/
					
					li_res = de_AFN0C_F130(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 131:
					{	/***当前反向有功电能示值**/
					
					li_res = de_AFN0C_F131(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 132:
					{	/***当前反向无功电能示值***/
					
					li_res = de_AFN0C_F132(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 133:
					{	/**当前一象限无功电能市值***/
					
					li_res = de_AFN0C_F133(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 134:
					{	/**当前二象限无功电能市值**/
					
					li_res = de_AFN0C_F134(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 135:
					{	/**当前三象限无功电能市值***/
					
					li_res = de_AFN0C_F135(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 136:
					{	/***当前四象限无功电能市值***/
					
					li_res = de_AFN0C_F136(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 137:
					{	/***上月正向有功电能示值***/
					
					li_res = de_AFN0C_F137(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 138:
					{	/**上月正向无功电能示值**/
					
					li_res = de_AFN0C_F138(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 139:
					{	/**上月反向有功电能示值***/
					
					li_res = de_AFN0C_F139(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 140:
					{	/**上月反向无功电能示值**/
					
					li_res = de_AFN0C_F140(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 141:
					{	/***上月一象限无功电能示值**/
					
					li_res = de_AFN0C_F141(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 142:
					{	/**上月二象限无功电能示值**/
					
					li_res = de_AFN0C_F142(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 143:
					{	/***上月三象限无功电能示值**/
					
					li_res = de_AFN0C_F143(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 144:
				{	/***上月四象限无功电能示值***/
					
					li_res = de_AFN0C_F144(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 145:
				case 146:
				case 147:
				case 148:
				case 149:
				case 150:
				case 151:
				case 152:
				{	/***上月四象限无功电能示值***/
					
					li_res = de_AFN0C_F145_F152(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 153:
				case 154:
				case 155:
				case 156:
				case 157:
				case 158:
				case 159:
				case 160:
				{	/***第一第二第三第四 ~第八时区正向有功电能示值*/
					
					li_res = de_AFN0C_F153_F160(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 161:
				{	/***电能远程控制通断电状态及记录*/
					
					li_res = de_AFN0C_F161(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 162:
				{	/***电能表日历时钟*/
					
					li_res = de_AFN0C_F162(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 165:
				{	/***电能表开关操作次数挤时间*/
					
					li_res = de_AFN0C_F165(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 166:
				{	/***电能表参数修改次数及时间*/
					
					li_res = de_AFN0C_F166(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 167:
				{	/***电能购电用电信息*/
				
					li_res = de_AFN0C_F167(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 168:
				{	/**电能表结算信息*/
					
					li_res = de_AFN0C_F168(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 169:
				{	/***集中抄表中集器路由信息*/
					
					li_res = de_AFN0C_F169(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 170:
				{	/**集中抄表电表抄读信息*/
					
					li_res = de_AFN0C_F170(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 177:
				{	/**当前组合含有功电能示值*/
					
					li_res = de_AFN0C_F177(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				case 178:
				{	/**上1结算日组合有功电能示值*/
					
					li_res = de_AFN0C_F178(P, astr_frame, lstr_PN.pn[li_i], lstr_FN.fn[li_j], &li_step, li_len);
					if (( li_res != ERROR_SUCCESS) && (li_res != ERROR_NOT_FOUND_CJDBH))
					return li_res;
					P = P + li_step;
					li_len = li_len - li_step;
				}
					break;
				default:
					break;
				}
				if (li_len < 0)
				return ERROR_FRAME_LENGTH;
			}
	            }
	       }
	    return ERROR_SUCCESS;
	}
}
/***************************************************
	D0~D246按顺序对位表示部分04H 所
	定义的参数置 1，终端已经有该项参数
	终端已经有该项参数，相反,无;
****************************************************/
int de_AFN0C_FN2(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_FN2 lstr_val;

	f_get_xh(ls_rwxh);
	li_res = decode_afn0C_F2(ac_p, &lstr_val, ai_step);
	
/**********数据处理******************/
	memcpy(ls_mes, &lstr_val, sizeof(lstr_val));
	f_sendto_mngr(ls_mes, li_meslen);



    return li_res;
}
/***************************
	终端参数状态
	decode_afn0C_F3解码函数
	ac_p   数据单单元指针
        ai_step  报文长度
****************************/
int de_AFN0C_FN3(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_FN3 lstr_val;
	li_res = decode_afn0C_F3(ac_p, &lstr_val, ai_step);
	
	memcpy(ls_mes, &lstr_val, sizeof(lstr_val));
	f_sendto_mngr(ls_mes, li_meslen);
	return li_res;
}
/***************************
	终端上行通信状态
	decode_afn0C_F4解码函数
	ac_p   数据单单元指针
        ai_step  报文长度
****************************/
int de_AFN0C_FN4(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_FN4 lstr_val;
	li_res = decode_afn0C_F4(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes, &lstr_val, sizeof(lstr_val));
	f_sendto_mngr(ls_mes, li_meslen);
	return li_res;
}
/***************************
	终端控制设置状态
	decode_afn0C_F5解码函数
	ac_p   数据单单元指针
        ai_step  报文长度
****************************/
int de_AFN0C_FN5(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	 int li_res ,li_meslen;
	 char ls_mes[65535] = {0};
	 str_AFN0C_FN5 lstr_val;
	 li_res = decode_afn0C_F5(ac_p,&lstr_val,ai_step);

	 memcpy(ls_mes,&lstr_val,sizeof(lstr_val));

	 f_sendto_mngr(ls_mes,li_meslen);
	 return li_res;
}
/***************************
	终端当前控制状态
	decode_afn0C_F6解码函数
	ac_p   数据单单元指针
        ai_step  报文长度
****************************/
int de_AFN0C_FN6(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN6 lstr_val;
	li_res = decode_afn0C_F6(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));

	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/***************************
	终端计数器当前值
	decode_afn0C_F7解码函数
	ac_p   数据单元指针

        ai_step  报文长度
****************************/
int de_AFN0C_FN7(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN7 lstr_val;
	li_res = decode_afn0C_F7(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/***************************
	终端事件标志状态
	decode_afn0C_F8解码函数
	ac_p   数据单元指针
        ai_step  报文长度
****************************/
int de_AFN0C_FN8(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN8 lstr_val;
	li_res = decode_afn0C_F8(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/***********************************
	终端状态量及变化位标志
	decode_afn0C_F9解码函数
	ac_p   数据单元指针
        ai_step  报文长度
*************************************/
int de_AFN0C_FN9(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN9 lstr_val;
	li_res = decode_afn0C_F9(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/*************************************
	终端与主站当日月通信流量
	decode_afn0C_F10解码函数
	ac_p   数据单元指针
        ai_step  报文长度
*************************************/
int de_AFN0C_FN10(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN10 lstr_val;
	li_res = decode_afn0C_F10(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************
	终端集中抄表状态信息
	decode_afn0C_F11解码函数
	ac_p   数据单元指针
        ai_step  报文长度
**********************************/
int de_AFN0C_FN11(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN11 lstr_val;
	li_res = decode_afn0C_F11(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	控制输出回路开关接入状态量及变化标志
	decode_afn0C_F12解码函数
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN12(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN12 lstr_val;
	li_res = decode_afn0C_F12(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

/********************************************************
*	搜索到的电表信息
*	decode_afn0C_F13解码函数
*	ac_p   数据单元指针
*       ai_step  报文长度
********************************************************/
/*
int de_AFN0C_FN13(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN13 lstr_val;
	li_res = decode_afn0C_F13(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
*/
/********************************************************
	文件传输末收到的数据段
	decode_afn0C_F14解码函数
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
/*
int de_AFN0C_FN14(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN14 lstr_val;
	li_res = decode_afn0C_F14(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
*/

/********************************************************
	当前总加有功功率*
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN17(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN17 lstr_val;
	li_res = decode_afn0C_F17(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	**当前总共无功功率**
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN18(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN18 lstr_val;
	li_res = decode_afn0C_F18(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	当日总加工电能量
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN19(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN19 lstr_val;
	li_res = decode_afn0C_F19(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	当日总加无功电能量
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN20(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN20 lstr_val;
	li_res = decode_afn0C_F20(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	当日总加有功电能量*
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN21(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN21 lstr_val;
	li_res = decode_afn0C_F21(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	当月总加无功电能量*
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN22(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN22 lstr_val;
	li_res = decode_afn0C_F22(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	终端当前剩余电量*
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN23(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN23 lstr_val;
	li_res = decode_afn0C_F23(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
/********************************************************
	当前功率下浮控控后总加有功功率冻结值
	ac_p   数据单元指针
        ai_step  报文长度
********************************************************/
int de_AFN0C_FN24(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN24 lstr_val;
	li_res = decode_afn0C_F24(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN25(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN25 lstr_val;
	li_res = decode_afn0C_F25(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN26(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN26 lstr_val;
	li_res = decode_afn0C_F26(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN27(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN27 lstr_val;
	li_res = decode_afn0C_F27(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN28(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN28 lstr_val;
	li_res = decode_afn0C_F28(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN29(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN29 lstr_val;
	li_res = decode_afn0C_F29(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN30(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN30 lstr_val;
	li_res = decode_afn0C_F30(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN31(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN31 lstr_val;
	li_res = decode_afn0C_F31(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN32(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN32 lstr_val;
	li_res = decode_afn0C_F32(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN33(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN33 lstr_val;
	li_res = decode_afn0C_F33(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN34(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN34 lstr_val;
	li_res = decode_afn0C_F34(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN35(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN35 lstr_val;
	li_res = decode_afn0C_F35(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN36(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN36 lstr_val;
	li_res = decode_afn0C_F36(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN37(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN37 lstr_val;
	li_res = decode_afn0C_F37(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN38(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN38 lstr_val;
	li_res = decode_afn0C_F38(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN39(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN39 lstr_val;
	li_res = decode_afn0C_F39(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN40(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN40 lstr_val;
	li_res = decode_afn0C_F40(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN41_F48(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN41_48 lstr_val;
	li_res = decode_afn0C_F4all(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN49(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN49 lstr_val;
	li_res = decode_afn0C_F49(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN57(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_F57F58 lstr_val;
	li_res = decode_afn0C_F58(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN58(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_F57F58 lstr_val;
	li_res = decode_afn0C_F58(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0C_FN65(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN65 lstr_val;
	li_res = decode_afn0C_F65(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN66(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN66 lstr_val;
	li_res = decode_afn0C_F66(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN67(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN67 lstr_val;
	li_res = decode_afn0C_F67(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_FN73(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C_FN73 lstr_val;
	li_res = decode_afn0C_F73(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0C_F81_F82(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F81_F82(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F83_F84(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F83_F84(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F89_F96(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F89_F96(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0C_F97_F99(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F97_F99(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F100_F103(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F100_F103(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F105_F108(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F105_F108(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F109_F112(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F109_F112(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F113_F116(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F113_F116(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}

int de_AFN0C_F121(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res ,li_meslen;
	char ls_mes[65535] = {0};
	str_AFN0C0D_QX lstr_val;
	li_res = decode_afn0C_F121(ac_p,&lstr_val,ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F129(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ14(ac_p, &lstr_val, ai_step);/*//F129F131F137F139F153F154F155F156F157F158F159F160*/

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F130(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F131(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ14(ac_p, &lstr_val, ai_step);/*F129F131F137F139F153F154F155F156F157F158F159F160*/

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F132(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F133(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F134(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F135(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F136(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F137(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ14(ac_p, &lstr_val, ai_step);/*//F129F131F137F139F153F154F155F156F157F158F159F160*/

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F138(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F139(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ14(ac_p, &lstr_val, ai_step);/*//F129F131F137F139F153F154F155F156F157F158F159F160*/

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F140(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F141(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F142(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F143(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F144(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ11(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F145_F152(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res , li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_G19 lstr_val;

	li_res = decode_afn0C_G19(ac_p, &lstr_val, ai_step);
	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F153_F160(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_meslen;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	str_AFN0C_LowVal lstr_val;
	li_res = decode_afn0C_NSZ14(ac_p, &lstr_val, ai_step);

	
	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F161(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F161 lstr_val;

	li_res = decode_afn0C_F161(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F162(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F162 lstr_val;

	li_res = decode_afn0C_F162(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F165(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F165F166 lstr_val;

	li_res = decode_afn0C_F165(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F166(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F165F166 lstr_val;

	li_res = decode_afn0C_F166(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F167(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F167 lstr_val;

	li_res = decode_afn0C_F167(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F168(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F168 lstr_val;

	li_res = decode_afn0C_F168(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F169(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F169 lstr_val;

	li_res = decode_afn0C_F169(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F170(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F170 lstr_val;

	li_res = decode_afn0C_F170(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F177(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F177F178 lstr_val;

	li_res = decode_afn0C_F177(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}
int de_AFN0C_F178(uchar *ac_p, str_encode_param *astr_frame, uchar ac_PN,uchar ac_FN, int *ai_step,int ai_len)
{
	int li_res, li_date, li_meslen, li_ret;
	char ls_mes[65535]={0}, ls_rwxh[32]={0};
	char ls_err[32]={0};
	str_AFN0C_F177F178 lstr_val;

	li_res = decode_afn0C_F177(ac_p, &lstr_val, ai_step);

	memcpy(ls_mes,&lstr_val,sizeof(lstr_val));
	f_sendto_mngr(ls_mes,li_meslen);
	return li_res;
}