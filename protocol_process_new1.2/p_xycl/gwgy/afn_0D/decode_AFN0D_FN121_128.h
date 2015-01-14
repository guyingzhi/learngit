#ifndef DECODE_AFN0D_FN121_128_H
#define DECODE_AFN0D_FN121_128_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F121_123_val_t
{
    datetime TD;          				  /*时标*/
    uchar XBCS;           						  /*谐波次数*/
    unsigned short overlimitU[19];  						/*电压越限时间*/
    unsigned short overlimitI[19]; 				  /*电流越限时间*/
}str_AFN0D_F121_123_val;

typedef struct str_AFN0D_F121_123_ISNULL_t
{
    short TD;               							/*时标判空标志*/
    short overlimitU[19];  								 /*电压越限时间判空标志*/
    short overlimitI[19];  										 /*电流越限时间判空标志*/
}str_AFN0D_F121_123_ISNULL;

typedef struct str_AFN0D_F121_123_t
{
    str_AFN0D_F121_123_val val;
    str_AFN0D_F121_123_ISNULL isnull;
}str_AFN0D_F121_123;

typedef struct str_AFN0D_F124_126_val_t
{
	datetime  TD;			/*数据时标*/
	uint   num;				/*谐波次数*/
	double Uall;					/*总畸变电压含有值*/
	double Uodd;							/*奇次畸变*/
	double Ueven;									/*偶次畸变*/
	double Uval[19];				/*N次谐波电压含有值*/
	double Iall;				/*N次谐波电流概率值*/
	double Ivall[19];	/*数据时标*/
}str_AFN0D_F124_126_val;


typedef struct str_AFN0D_F124_126_ISNULL_t
{
	short TDisnull;
	short Uallisnull;;
	short Uoddisnull;
	short Uevenisnull;
	short Uvalisnull[19];
	short Iallisnull;
	short Ivalisnull[19];	
}srt_AFN0D_F124_126_ISNULL;
typedef struct str_AFN0D_F124_126_t
{
	str_AFN0D_F124_126_val val;
	srt_AFN0D_F124_126_ISNULL isnull;
}str_AFN0D_F124_126;

int decode_afn0D_F121_123(uchar *data, str_AFN0D_F121_123 *astr_val, int *ai_step);
int decode_AFN0D_F124_126(uchar *data, str_AFN0D_F124_126 *astr_val, int *ai_step);
#endif