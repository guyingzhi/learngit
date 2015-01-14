#ifndef ENCODE_AFN0C_FN25_32_H
#define ENCODE_AFN0C_FN25_32_H
#include "../public/public.h"
#include "../public/decode_public.h"

typedef struct str_AFN0C_F25_val_t
{
	datetime cbtime;               			 /*抄表时间*/
	double PZ, PA, PB, PC;        		 	 /*三相有功功率*/
	double QZ, QA, QB, QC;         			 /*三相无功功率*/
	double COSZ, COSA, COSB, COSC;	  /*三相功率因数*/
	double UA, UB, UC;              			/*三相电压*/
	double IA, IB, IC, I0;          			/*三相电流、零序电流*/
	double SZZ, SZA, SZB, SZC;         		 /*视在功率*/
}str_AFN0C_FN25_VAL ;
typedef struct str_AFN0C_F25_ISNULL_t
{
    short cbtime;                 		 	/*抄表时间判空标志*/
    short PZ, PA, PB, PC;         			 /*三相有功功率判空标志*/
    short QZ, QA, QB, QC;          		/*三相无功功率判空标志*/
    short COSZ, COSA, COSB, COSC; 	 /*三相功率因数判空标志*/
    short UA, UB, UC;              			/*三相电压判空标志*/
    short IA, IB, IC, I0;         			 /*三相电流、零序电流判空标志*/
    short SZZ, SZA, SZB, SZC;    		  /*视在功率判空标志*/
}str_AFN0C_FN25_ISNULL;

typedef struct str_AFN0C_F25_t
{
    str_AFN0C_FN25_VAL val;
    str_AFN0C_FN25_ISNULL isnull;
}str_AFN0C_FN25;
typedef struct str_AFN0C_F26_VAL_t
{
    datetime cbtime;    				 /*终端抄表时间*/
    int times[4];        					/*总、三相 断相次数*/
    int val[4];          					/*总、三相 断相累计时间*/
    datetime startdt[4]; 				/*总、三相 最近一次断相起始时刻*/
    datetime enddt[4];   				/*总、三相 最近一次断相结束时刻*/
}str_AFN0C_FN26_VAL;

typedef struct str_AFN0C_F26_ISNULL_t
{
    short cbtime;        			/*终端抄表时间判空标志*/
    short times[4];      			/*断相次数判空标志*/
    short val[4];        				/*断相累计时间判空标志*/
    short startdt[4];   			 /*最近一次断相起始时刻判空标志*/
    short enddt[4];      			/*最近一次断相结束时刻判空标志*/
}str_AFN0C_FN26_ISNULL;

typedef struct str_AFN0C_F26_t
{
    str_AFN0C_FN26_VAL val;
    str_AFN0C_FN26_ISNULL isnull;
}str_AFN0C_FN26;
typedef struct str_AFN0C_F27_val_t
{
	datetime cbtime;                	 /*终端抄表时间*/
	datetime termtime;              	 /*电能表日历时钟*/
	uint     worktime;              	 /*电池工作时间*/
	uint     val1;                   		/*编程次数*/
	datetime time1;                  	/*最近一次编程时间*/
	uint     val;                  		 /*电表清零次数*/
	datetime time;                  	/*最近一次电表清零时间*/
	uint     val2;                  		/*需量清零次数*/
	datetime time2;                	  /*最近一次需量清零时间*/
	uint     val3;                  		 /*事件清零总次数*/
	datetime time3;                 	 /*最近一次事件清零时间*/
	uint     val4;                   		/*校时总次数*/
	datetime time4;                 	 /*最近一次校时时间*/
	
} str_AFN0C_FN27_VAL;
typedef struct str_AFN0C_F27_ISNULL_t
{
   short cbtime;                 /*终端抄表时间判空标志*/
   short termtime;               /*电能表日历时钟判空标志*/
   short     worktime;               /*电池工作时间*/
   short     val1;                   /*编程次数*/
   short    time1;                  /*最近一次编程时间*/
   short     val;                   /*电表清零次数*/
   short     time;                  /*最近一次电表清零时间*/
   short     val2;                   /*需量清零次数*/
   short    time2;                  /*最近一次需量清零时间*/
   short     val3;                   /*事件清零总次数*/
   short    time3;                  /*最近一次事件清零时间*/
   short     val4;                   /*校时总次数*/
   short    time4;                  /*最近一次校时时间*/
}str_AFN0C_FN27_ISNULL;

typedef struct str_AFN0C_F27_t
{
    str_AFN0C_FN27_VAL val;
    str_AFN0C_FN27_ISNULL isnull;
}str_AFN0C_FN27;


typedef struct str_AFN0C_F28_flag_t
{
	uchar  ztbw[16];				/*电表运行状态字变位位标志*/
	uchar  yxzt[16];				/*电表运行状态字*/
}str_AFN0C_FN28_flag;	
typedef struct str_AFN0C_F28_t
{
	datetime cbtime;				 /*终端抄表时间*/
	short    dtisnull;
	str_AFN0C_FN28_flag   flag[7];      	/*电表运行状态标志*/
}str_AFN0C_FN28;

typedef struct str_AFN0C_F29_t
{
	datetime       cbtime;                 /*终端抄表时间*/
	short          cbtimeisnull;
	double         cuygnsz;        	  /*当前铜损有功总电能示值*/
	short          cuygnszisnull;
	double         feygnsz;        	 /*当前铁损有功总电能示值*/
	short          feygnszisnull;
}str_AFN0C_FN29;

typedef struct str_AFN0C_F30_t
{
    datetime       cbtime;                		 /*终端抄表时间*/
    short          cbtimeisnull;
    double         cuygnsz;          		/*上一结算日铜损有功总电能补偿量*/
    short          cuygnszisnull;
    double         feygnsz;         			/*上一结算日铁损有功总电能补偿量*/
    short          feygnszisnull;
}str_AFN0C_FN30;

typedef struct str_AFN0C_F31_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    double ansz[4];       /*A相能示值*/
    double bnsz[4];       /*B相能示值*/
    double cnsz[4];       /*C相能示值*/
}str_AFN0C_FN31_VAL;


typedef struct str_AFN0C_F31_ISNULL_t
{
    short cbtime;
    short ansz[4];
    short bnsz[4];
    short cnsz[4];
}str_AFN0C_FN31_ISNULL;


typedef struct str_AFN0C_F31_t
{
    str_AFN0C_FN31_VAL val;
    str_AFN0C_FN31_ISNULL isnull;
}str_AFN0C_FN31;

typedef struct str_AFN0C_F32_VAL_t
{
    datetime cbtime;        /*抄表时间*/
    double ansz[4];       /*A相能示值*/
    double bnsz[4];       /*B相能示值*/
    double cnsz[4];       /*C相能示值*/
}str_AFN0C_FN32_VAL;


typedef struct str_AFN0C_F32_ISNULL_t
{
    short cbtime;
    short ansz[4];
    short bnsz[4];
    short cnsz[4];
}str_AFN0C_FN32_ISNULL;


typedef struct str_AFN0C_F32_t
{
    str_AFN0C_FN32_VAL val;
    str_AFN0C_FN32_ISNULL isnull;
}str_AFN0C_FN32;

int decode_afn0C_F25(uchar * data, str_AFN0C_FN25* lstr_val, int * ai_len);
int decode_afn0C_F26(uchar * data, str_AFN0C_FN26* lstr_val, int * ai_len);
int decode_afn0C_F27(uchar *data,  str_AFN0C_FN27 *lstr_val,int *ai_len);
int decode_afn0C_F28(uchar *data,  str_AFN0C_FN28 *lstr_val,int *ai_len);
int decode_afn0C_F29(uchar *data,  str_AFN0C_FN29 *lstr_val,int *ai_len);
int decode_afn0C_F30(uchar *data,  str_AFN0C_FN30*lstr_val,int *ai_len); 
int decode_afn0C_F31(uchar *data,  str_AFN0C_FN31*lstr_val,int *ai_len);
int decode_afn0C_F32(uchar *data,  str_AFN0C_FN32*lstr_val,int *ai_len);
#endif 
