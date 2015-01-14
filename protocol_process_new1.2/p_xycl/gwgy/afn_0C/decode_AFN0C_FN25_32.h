#ifndef ENCODE_AFN0C_FN25_32_H
#define ENCODE_AFN0C_FN25_32_H
#include "../public/public.h"
#include "../public/decode_public.h"

typedef struct str_AFN0C_F25_val_t
{
	datetime cbtime;               			 /*����ʱ��*/
	double PZ, PA, PB, PC;        		 	 /*�����й�����*/
	double QZ, QA, QB, QC;         			 /*�����޹�����*/
	double COSZ, COSA, COSB, COSC;	  /*���๦������*/
	double UA, UB, UC;              			/*�����ѹ*/
	double IA, IB, IC, I0;          			/*����������������*/
	double SZZ, SZA, SZB, SZC;         		 /*���ڹ���*/
}str_AFN0C_FN25_VAL ;
typedef struct str_AFN0C_F25_ISNULL_t
{
    short cbtime;                 		 	/*����ʱ���пձ�־*/
    short PZ, PA, PB, PC;         			 /*�����й������пձ�־*/
    short QZ, QA, QB, QC;          		/*�����޹������пձ�־*/
    short COSZ, COSA, COSB, COSC; 	 /*���๦�������пձ�־*/
    short UA, UB, UC;              			/*�����ѹ�пձ�־*/
    short IA, IB, IC, I0;         			 /*�����������������пձ�־*/
    short SZZ, SZA, SZB, SZC;    		  /*���ڹ����пձ�־*/
}str_AFN0C_FN25_ISNULL;

typedef struct str_AFN0C_F25_t
{
    str_AFN0C_FN25_VAL val;
    str_AFN0C_FN25_ISNULL isnull;
}str_AFN0C_FN25;
typedef struct str_AFN0C_F26_VAL_t
{
    datetime cbtime;    				 /*�ն˳���ʱ��*/
    int times[4];        					/*�ܡ����� �������*/
    int val[4];          					/*�ܡ����� �����ۼ�ʱ��*/
    datetime startdt[4]; 				/*�ܡ����� ���һ�ζ�����ʼʱ��*/
    datetime enddt[4];   				/*�ܡ����� ���һ�ζ������ʱ��*/
}str_AFN0C_FN26_VAL;

typedef struct str_AFN0C_F26_ISNULL_t
{
    short cbtime;        			/*�ն˳���ʱ���пձ�־*/
    short times[4];      			/*��������пձ�־*/
    short val[4];        				/*�����ۼ�ʱ���пձ�־*/
    short startdt[4];   			 /*���һ�ζ�����ʼʱ���пձ�־*/
    short enddt[4];      			/*���һ�ζ������ʱ���пձ�־*/
}str_AFN0C_FN26_ISNULL;

typedef struct str_AFN0C_F26_t
{
    str_AFN0C_FN26_VAL val;
    str_AFN0C_FN26_ISNULL isnull;
}str_AFN0C_FN26;
typedef struct str_AFN0C_F27_val_t
{
	datetime cbtime;                	 /*�ն˳���ʱ��*/
	datetime termtime;              	 /*���ܱ�����ʱ��*/
	uint     worktime;              	 /*��ع���ʱ��*/
	uint     val1;                   		/*��̴���*/
	datetime time1;                  	/*���һ�α��ʱ��*/
	uint     val;                  		 /*����������*/
	datetime time;                  	/*���һ�ε������ʱ��*/
	uint     val2;                  		/*�����������*/
	datetime time2;                	  /*���һ����������ʱ��*/
	uint     val3;                  		 /*�¼������ܴ���*/
	datetime time3;                 	 /*���һ���¼�����ʱ��*/
	uint     val4;                   		/*Уʱ�ܴ���*/
	datetime time4;                 	 /*���һ��Уʱʱ��*/
	
} str_AFN0C_FN27_VAL;
typedef struct str_AFN0C_F27_ISNULL_t
{
   short cbtime;                 /*�ն˳���ʱ���пձ�־*/
   short termtime;               /*���ܱ�����ʱ���пձ�־*/
   short     worktime;               /*��ع���ʱ��*/
   short     val1;                   /*��̴���*/
   short    time1;                  /*���һ�α��ʱ��*/
   short     val;                   /*����������*/
   short     time;                  /*���һ�ε������ʱ��*/
   short     val2;                   /*�����������*/
   short    time2;                  /*���һ����������ʱ��*/
   short     val3;                   /*�¼������ܴ���*/
   short    time3;                  /*���һ���¼�����ʱ��*/
   short     val4;                   /*Уʱ�ܴ���*/
   short    time4;                  /*���һ��Уʱʱ��*/
}str_AFN0C_FN27_ISNULL;

typedef struct str_AFN0C_F27_t
{
    str_AFN0C_FN27_VAL val;
    str_AFN0C_FN27_ISNULL isnull;
}str_AFN0C_FN27;


typedef struct str_AFN0C_F28_flag_t
{
	uchar  ztbw[16];				/*�������״̬�ֱ�λλ��־*/
	uchar  yxzt[16];				/*�������״̬��*/
}str_AFN0C_FN28_flag;	
typedef struct str_AFN0C_F28_t
{
	datetime cbtime;				 /*�ն˳���ʱ��*/
	short    dtisnull;
	str_AFN0C_FN28_flag   flag[7];      	/*�������״̬��־*/
}str_AFN0C_FN28;

typedef struct str_AFN0C_F29_t
{
	datetime       cbtime;                 /*�ն˳���ʱ��*/
	short          cbtimeisnull;
	double         cuygnsz;        	  /*��ǰͭ���й��ܵ���ʾֵ*/
	short          cuygnszisnull;
	double         feygnsz;        	 /*��ǰ�����й��ܵ���ʾֵ*/
	short          feygnszisnull;
}str_AFN0C_FN29;

typedef struct str_AFN0C_F30_t
{
    datetime       cbtime;                		 /*�ն˳���ʱ��*/
    short          cbtimeisnull;
    double         cuygnsz;          		/*��һ������ͭ���й��ܵ��ܲ�����*/
    short          cuygnszisnull;
    double         feygnsz;         			/*��һ�����������й��ܵ��ܲ�����*/
    short          feygnszisnull;
}str_AFN0C_FN30;

typedef struct str_AFN0C_F31_VAL_t
{
    datetime cbtime;        /*����ʱ��*/
    double ansz[4];       /*A����ʾֵ*/
    double bnsz[4];       /*B����ʾֵ*/
    double cnsz[4];       /*C����ʾֵ*/
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
    datetime cbtime;        /*����ʱ��*/
    double ansz[4];       /*A����ʾֵ*/
    double bnsz[4];       /*B����ʾֵ*/
    double cnsz[4];       /*C����ʾֵ*/
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
