#ifndef ENCODE_AFN0C_FN1_8_H
#define ENCODE_AFN0C_FN1_8_H

#include "../public/decode_public.h"

/*****376.1******/

typedef struct  str_AFN0C_F2_t
{
    datetime    termdt;           			/*终端日历时钟*/
    short       termdtisnull;    			 /*终端软件发布日期判空标志*/
}str_AFN0C_FN2;

typedef struct  str_AFN0C_F3_t
{
    uchar  arg[248]; 					  /*参数映射表*/
}str_AFN0C_FN3;

typedef struct str_AFN0C_F4_t
{
	uchar report;         				  /**1~2依次表示允许/禁止上报**/
	uchar message;				  /**1~2依次表示允许/禁止通话**/
}str_AFN0C_FN4;

typedef struct str_AFN0C_F5_group_t
{
	uchar projectid;             			 /*功控定值方案号*/
	uchar gksd[8];               			 /*功控时段标志1~8时段*/
	uchar sdk, cxk, yybtk, glxfk; 		/*功控：时段控  厂休控  营业报停控  当前功率下浮控*/
	uchar ydk, gdk;              		 	/*电控：月电控  购电控*/
	uchar turngk[8];              		/*功控轮次状态*/
	uchar turndk[8];              		/*电控轮次状态*/ 
} str_AFN0C_FN5_group;

typedef struct  str_AFN0C_F5_t
{
    uchar  bd, tc, cfgj;                 		/*保电、剔除和催费告警投入状态*/
    uchar  sum[8];               			/*总加组标志*/
    str_AFN0C_FN5_group ctrl[8];		  /*总加组控制信息*/
}str_AFN0C_FN5;

typedef struct str_AFN0C_F6_group_t
{
	uchar gkdz;                                      	 /*当前工控定值*/
	uchar gkdzisnull;					/*判断是否为空*/
	uchar k;						 	/*当前功率下浮控系数*/
	uchar kisnull;
	uchar gltz[8];					 	 /*工控跳闸输出*/
	uchar mondgtz[8];					 /*月电供跳闸输出状态*/
	uchar buydgtz[8];					 /*购电控跳闸输出状态*/
	uchar sdk, cxk, yybtk, glxfk;			/*功控越界时段空，厂休控，营业报停控，当前功率下浮控邋*/
	uchar mondkyj,buydky;				/*电控越界月电控，购电控*/
}str_AFN0C_FN6_group;
typedef struct str_AFN0C_F6_t
{
	uchar  yktz[8];
	uchar cfgj;
	uchar  sum[8];
	str_AFN0C_FN6_group ctrl[8];
}str_AFN0C_FN6;
typedef struct str_AFN0C_F7_t
{
	uchar EC1;			/*重要事件计数器值*/
	uchar EC2;			/*一般事件计数器值*/
}str_AFN0C_FN7;
typedef struct str_AFN0C_F8_t
{
	uchar ERC[64];			/*事件状态标志ERC1~ERC64*/
}str_AFN0C_FN8;

int decode_afn0C_F2(uchar * data, str_AFN0C_FN2* lstr_val, int * ai_len);
int decode_afn0C_F3(uchar * data, str_AFN0C_FN3* lstr_val, int * ai_len);
int decode_afn0C_F4(uchar *data,  str_AFN0C_FN4 *lstr_val,int *ai_len);
int decode_afn0C_F5(uchar *data,  str_AFN0C_FN5 *lstr_val,int *ai_len);
int decode_afn0C_F6(uchar *data,  str_AFN0C_FN6 *lstr_val,int *ai_len);
int decode_afn0C_F7(uchar *data,  str_AFN0C_FN7 *lstr_val,int *ai_len);
int decode_afn0C_F8(uchar *data,  str_AFN0C_FN8 *lstr_val,int *ai_len);
#endif
