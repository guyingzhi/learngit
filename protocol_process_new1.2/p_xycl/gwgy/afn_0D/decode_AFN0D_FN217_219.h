#ifndef DECODE_AFN0D_FN217_219_H
#define DECODE_AFN0D_FN217_219_H

#include "../public/decode_public.h"
#include "../public/public.h"

typedef struct str_AFN0D_F217F218_t
{
	datetime TD;				/*数据时标*/	
	short TDisnull;				/*判空*/	
	int num;
	short val[32];				/*噪声比值*/	
	str_add12 addr[32];			/*主节点地址*/
	short addrisnull[32];		/*判空*/
}str_AFN0D_F217F218;


typedef struct str_AFN0D_F219_t
{
	datetime TD;					/*数据时标*/	
	short TDisnull;					/*判空*/
	double  val;						/*有功功率*/
	short valisnull;
	double idle;					/*无功功率*/
	short idlesinull;
	double AU,BU,CU;				/*A,B,C 象限电压*/
	short Auisnull,BUisnull,CUisnull;
	double AI,BI,CI;					/*A,B,C 象限电流*/
	short AIisnull,BIisnull,CIisnull;
	double valpow;				/*正向有功总电能市值*/
	short valpowisnull;
	double yidleval;				/*一象限无功总电能市值*/
	short yidlevalisnull;
	double sidleval;				/*四象限无功总电能市值*/
	short sidelvalisnull;
}str_AFN0D_F219;


int decode_afn0D_F217(uchar *as_data, str_AFN0D_F217F218*astr_val, int *ai_step);
int decode_afn0D_F218(uchar *as_data, str_AFN0D_F217F218*astr_val, int *ai_step);
int decode_afn0D_F219(uchar *as_data, str_AFN0D_F219*astr_val, int *ai_step);
#endif 
