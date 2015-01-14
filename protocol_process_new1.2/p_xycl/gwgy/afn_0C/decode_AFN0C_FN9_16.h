#ifndef ENCODE_AFN0C_FN9_16_H
#define ENCODE_AFN0C_FN9_16_H
#include "../public/public.h"
#include "../public/decode_public.h"

/*****376.1******/

typedef struct str_AFN0C_F9_t
{
	uchar ST[8];      		 /*状态量的状态ST*/
	uchar CD[8];       		/*状态量的变位CD*/
}str_AFN0C_FN9;	

typedef struct str_AFN0C_F10_t
{
	unsigned int daytotal;         	/*终端与主站当日通信流量*/
	unsigned int monthtotal;       /*终端与主站当月通信流量*/
}str_AFN0C_FN10;

typedef struct str_AFN0C_F11_group_t
{
	uchar   port;                          		/*终端通信端口号*/
	unsigned short   total_cb;            	 /*要抄电表总数*/
	uchar   cbokflag;                     	 /*抄表任务时段内完成/未完成标志位*/
	uchar   cbingflag;                     	/*抄表忙/闲标志位*/
	unsigned short   cboktotal;            /*抄表成功块数*/
	uchar   cbzdtotal;                     	/*抄重点表成功块数*/
	datetime   cbkssj;                     	/*抄表开始时间*/
	short   cbkssjisnull;
	datetime   cbjssj;                     	/*抄表结束时间*/
	short   cbjssjisnull;
}str_AFN0C_FN11_group;

typedef struct str_AFN0C_F11_t
{
	uchar   number;				/*数据块个数*/
	str_AFN0C_FN11_group val[32] ;      
}str_AFN0C_FN11;

typedef struct str_AFN0C_F12_t
{
	uchar ST[8];      		 /*状态量的状态ST俩位一组*/
	uchar CD[8];       		/*状态量的变位CD俩位一组*/
}str_AFN0C_FN12;





int decode_afn0C_F9(uchar * data, str_AFN0C_FN9* lstr_val, int * ai_len);
int decode_afn0C_F10(uchar * data, str_AFN0C_FN10* lstr_val, int *ai_len);
int decode_afn0C_F11(uchar *data,  str_AFN0C_FN11 *lstr_val, int *ai_len);
int decode_afn0C_F12(uchar *data,  str_AFN0C_FN12 *lstr_val, int *ai_len);
/*
int decode_afn0C_F13(uchar *data,  str_AFN0C_FN13 *lstr_val, int *ai_len);
int decode_afn0C_F14(uchar *data,  str_AFN0C_FN14 *lstr_val, int *ai_len);
*/
#endif