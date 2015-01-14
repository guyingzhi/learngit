#ifndef ENCODE_AFN0C_FN17_24_H
#define ENCODE_AFN0C_FN17_24_H
#include "../public/public.h"
#include "../public/decode_public.h"

/*****376.1******/

typedef struct str_AFN0C_F17_t
{
	double val;            			 /*当前总加有功功率*/
	short valisnull;      			 /*判空标志*/
}str_AFN0C_FN17;

typedef struct str_AFN0C_F18_t
{
	double idle;            			 /*当前总加无功功率*/
	short idleisnull;      			 /*判空标志*/
}str_AFN0C_FN18;
typedef struct str_AFN0C_sum_t
{
	uchar ratenum;           	/*费率数*/
	short ratelnumisnull;    	 /*费率数合法标志 1～14*/
	int val;            			 /*总加总电能量*/
	short valisnull;       		/*判空标志*/
	int varate[14];      		 /*费率N总加电能量*/
	short valtateisnull[14]; 	/*判空标志*/
}str_AFN0C_sum;


typedef struct  str_AFN0C_F19_t
{
	str_AFN0C_sum data;     /*当日总加有功*/
}str_AFN0C_FN19;

typedef struct  str_AFN0C_F20_t
{
	str_AFN0C_sum data;    /*当日总加无功*/
}str_AFN0C_FN20;


typedef struct  str_AFN0C_F21_t
{
	str_AFN0C_sum data;    /*当月总加有功*/
}str_AFN0C_FN21;

typedef struct  str_AFN0C_F22_t
{
	str_AFN0C_sum data;    /*当月总加无功*/
}str_AFN0C_FN22;

typedef struct str_AFN0C_F23_t
{
	int val;
	short valisnull;
}str_AFN0C_FN23;
typedef struct str_AFN0C_F24_t
{
	double val;             /*控后总加有功功率冻结值*/
	short valisnull;       /*判空标志*/	
}str_AFN0C_FN24;
;
int decode_afn0C_F17(uchar * data, str_AFN0C_FN17* lstr_val, int * ai_len);
int decode_afn0C_F18(uchar * data, str_AFN0C_FN18* lstr_val, int * ai_len);
int decode_afn0C_F19(uchar * data, str_AFN0C_FN19* lstr_val, int * ai_len);
int decode_afn0C_F20(uchar * data, str_AFN0C_FN20* lstr_val, int * ai_len);
int decode_afn0C_F21(uchar * data, str_AFN0C_FN21* lstr_val, int * ai_len);
int decode_afn0C_F22(uchar * data, str_AFN0C_FN22* lstr_val, int * ai_len);
int decode_afn0C_F23(uchar * data, str_AFN0C_FN23* lstr_val, int * ai_len);
int decode_afn0C_F24(uchar * data, str_AFN0C_FN24* lstr_val, int * ai_len);

#endif