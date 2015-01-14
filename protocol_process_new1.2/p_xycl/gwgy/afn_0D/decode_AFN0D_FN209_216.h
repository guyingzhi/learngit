#ifndef DECODE_AFN0D_FN209_216_H
#define DECODE_AFN0D_FN209_216_H

#include "../public/decode_public.h"
#include "../public/public.h"

typedef struct str_AFN0D_FN209_t
{
	datetime DT;		/*����ʱ��*/
	short DTisnull;
	datetime CB;		/*����ʱ��*/
	short CBisnull;
	uchar state;		
	datetime hz;		/*���һ�κ�բ������ʱ��*/
	short hzisnull;		
	datetime TZ;		/*���һ����բ������ʱ��*/
	short TZisnull;
}str_AFN0D_F209;

typedef struct str_AFN0D_F210F215
{
	datetime	TD;			        		/*����ʱ��Td_m��Td_d */
	short		TDisnull;
	datetime	dt;			            		/*����ʱ��*/
	short		dtisnull;
	unsigned short      Powertime;              /*�������*/
	short       Powertimeisnull;
	double      Remainamount;          	 /*ʣ����*/
	short       Remainamountisnull;
	double      Accumulatedamount;      /*�ۼƹ�����*/
	short       Accumulatedamountisnull;
	double      Dump;                   /*ʣ�����*/
	short       Dumpisnull;
	double      Overdraw;               /*͸֧����*/
	short       Overdrawisnull;
	double      Accumulatedenergy;     /*�ۼƹ�����*/
	short       Accumulatedenergyisnull;
	double      Credit;                 /*��Ƿ���޵���*/
	short       Creditisnull;
	double      Alarm;                  /*��������*/
	short       Alarmisnull;
	double      Failure;                /*���ϵ���*/
	short       Failureisnull;
}str_AFN0D_F210F215;

typedef struct str_AFN0D_F211F212_t
{
	datetime TD;					/*����ʱ��*/
	short TDisnull;
	double Ival;					/*������ƽ���95 ����ֵ*/
	short Ivalisnull;
	double Uval;					/*��ѹ��ƽ���95 ����ֵ*/
	short Uvalisnull;
}str_AFN0D_F211F212;
typedef struct str_AFN0D_F213
{
	datetime TD;				/*����ʱ��*/
	short TDisnull;
	datetime CB;				/*����ʱ��*/
	short CBisnull;
	uint val;					/*���ܱ��̴���*/
	short valisnull;
	datetime protime;			/*���һ�α��ʱ��*/
	short protimeisnull;
	uint val1;					/*���ܱ�β�Ǵ򿪴���*/
	short val1isnull;
	datetime opentime;			/*���һ��β�Ǵ�ʱ��*/
	short opentimeisnull;
}str_AFN0D_F213;
typedef struct str_AFN0D_F214_t
{
	datetime TD;				/*����ʱ��*/
	short TDisnull;
	datetime CB;				/*����ʱ��*/
	short CBisnull;
	uint val;					/*Уʱ�ܴ���*/
	short valisnull;
	datetime CStime;			/*Уʱǰʱ��*/
	short CStimeisnull;
	datetime CStime1;			/*Уʱ��ʱ��*/
	short CStime1isnull;
	uint val1;					/*ʱ�α��̴���*/
	short val1isnull;
	datetime nowTD;			/*���һ��ʱ�α��ʱ�����ʱ������*/
	short nowTDisnull;
}str_AFN0D_F214;
typedef struct str_AFN0D_F216_t
{
	datetime TD;   			/*����ʱ������*/
	short TDisnull;			/*�п�*/
	datetime CB;			/* *����ʱ��**/
	short CBisnull;			/*�п�*/
	uchar val;			/*����*/
	double val1;			/*�ѽ��й��ܵ���*/
	short val1isnull;
	double zxyg[14];		/*����1 ~M �����й��ܵ���*/
	short zxygisnull[14];
	double val2;			/*δ���й��ܵ���*/
	short val2isnull;
	double zxyg1[14];		/*δ����������й�����*/
	short zxyg1isnull[14];
}str_AFN0D_F216;

int decode_afn0D_F209(uchar *as_data, str_AFN0D_F209*astr_val, int *ai_step);
int decode_afn0D_F210F215(uchar *as_data, str_AFN0D_F210F215*astr_val, int *ai_step,int frozen_type);
int decode_afn0D_F211F212(uchar *as_data, str_AFN0D_F211F212*astr_val, int *ai_step,int frozen_type);
int decode_afn0D_F213(uchar *as_data, str_AFN0D_F213*astr_val, int *ai_step);
int decode_afn0D_F214(uchar *as_data, str_AFN0D_F214*astr_val, int *ai_step);
int decode_afn0D_F216(uchar *as_data, str_AFN0D_F216*astr_val, int *ai_step);
#endif
