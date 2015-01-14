#ifndef DECODE_AFN0D_FN209_216_H
#define DECODE_AFN0D_FN209_216_H

#include "../public/decode_public.h"
#include "../public/public.h"

typedef struct str_AFN0D_FN209_t
{
	datetime DT;		/*数据时标*/
	short DTisnull;
	datetime CB;		/*抄表时间*/
	short CBisnull;
	uchar state;		
	datetime hz;		/*最近一次合闸发生的时间*/
	short hzisnull;		
	datetime TZ;		/*最近一次跳闸发生的时间*/
	short TZisnull;
}str_AFN0D_F209;

typedef struct str_AFN0D_F210F215
{
	datetime	TD;			        		/*数据时间Td_m或Td_d */
	short		TDisnull;
	datetime	dt;			            		/*抄表时间*/
	short		dtisnull;
	unsigned short      Powertime;              /*购电次数*/
	short       Powertimeisnull;
	double      Remainamount;          	 /*剩余金额*/
	short       Remainamountisnull;
	double      Accumulatedamount;      /*累计购电金额*/
	short       Accumulatedamountisnull;
	double      Dump;                   /*剩余电量*/
	short       Dumpisnull;
	double      Overdraw;               /*透支电量*/
	short       Overdrawisnull;
	double      Accumulatedenergy;     /*累计购电量*/
	short       Accumulatedenergyisnull;
	double      Credit;                 /*赊欠门限电量*/
	short       Creditisnull;
	double      Alarm;                  /*报警电量*/
	short       Alarmisnull;
	double      Failure;                /*故障电量*/
	short       Failureisnull;
}str_AFN0D_F210F215;

typedef struct str_AFN0D_F211F212_t
{
	datetime TD;					/*数据时标*/
	short TDisnull;
	double Ival;					/*电流不平衡度95 概率值*/
	short Ivalisnull;
	double Uval;					/*电压不平衡度95 概率值*/
	short Uvalisnull;
}str_AFN0D_F211F212;
typedef struct str_AFN0D_F213
{
	datetime TD;				/*数据时标*/
	short TDisnull;
	datetime CB;				/*抄表时间*/
	short CBisnull;
	uint val;					/*电能表编程次数*/
	short valisnull;
	datetime protime;			/*最近一次编程时间*/
	short protimeisnull;
	uint val1;					/*电能表尾盖打开次数*/
	short val1isnull;
	datetime opentime;			/*最近一次尾盖打开时间*/
	short opentimeisnull;
}str_AFN0D_F213;
typedef struct str_AFN0D_F214_t
{
	datetime TD;				/*数据时标*/
	short TDisnull;
	datetime CB;				/*抄表时间*/
	short CBisnull;
	uint val;					/*校时总次数*/
	short valisnull;
	datetime CStime;			/*校时前时间*/
	short CStimeisnull;
	datetime CStime1;			/*校时后时间*/
	short CStime1isnull;
	uint val1;					/*时段表编程次数*/
	short val1isnull;
	datetime nowTD;			/*最近一次时段编程时间秒分时年月日*/
	short nowTDisnull;
}str_AFN0D_F214;
typedef struct str_AFN0D_F216_t
{
	datetime TD;   			/*数据时标月年*/
	short TDisnull;			/*判空*/
	datetime CB;			/* *抄表时间**/
	short CBisnull;			/*判空*/
	uchar val;			/*费率*/
	double val1;			/*已结有功总电能*/
	short val1isnull;
	double zxyg[14];		/*费率1 ~M 正向有功总电能*/
	short zxygisnull[14];
	double val2;			/*未结有功总电能*/
	short val2isnull;
	double zxyg1[14];		/*未结费率正向有功电能*/
	short zxyg1isnull[14];
}str_AFN0D_F216;

int decode_afn0D_F209(uchar *as_data, str_AFN0D_F209*astr_val, int *ai_step);
int decode_afn0D_F210F215(uchar *as_data, str_AFN0D_F210F215*astr_val, int *ai_step,int frozen_type);
int decode_afn0D_F211F212(uchar *as_data, str_AFN0D_F211F212*astr_val, int *ai_step,int frozen_type);
int decode_afn0D_F213(uchar *as_data, str_AFN0D_F213*astr_val, int *ai_step);
int decode_afn0D_F214(uchar *as_data, str_AFN0D_F214*astr_val, int *ai_step);
int decode_afn0D_F216(uchar *as_data, str_AFN0D_F216*astr_val, int *ai_step);
#endif
