#ifndef DECODE_AFN0D_FN217_219_H
#define DECODE_AFN0D_FN217_219_H

#include "../public/decode_public.h"
#include "../public/public.h"

typedef struct str_AFN0D_F217F218_t
{
	datetime TD;				/*����ʱ��*/	
	short TDisnull;				/*�п�*/	
	int num;
	short val[32];				/*������ֵ*/	
	str_add12 addr[32];			/*���ڵ��ַ*/
	short addrisnull[32];		/*�п�*/
}str_AFN0D_F217F218;


typedef struct str_AFN0D_F219_t
{
	datetime TD;					/*����ʱ��*/	
	short TDisnull;					/*�п�*/
	double  val;						/*�й�����*/
	short valisnull;
	double idle;					/*�޹�����*/
	short idlesinull;
	double AU,BU,CU;				/*A,B,C ���޵�ѹ*/
	short Auisnull,BUisnull,CUisnull;
	double AI,BI,CI;					/*A,B,C ���޵���*/
	short AIisnull,BIisnull,CIisnull;
	double valpow;				/*�����й��ܵ�����ֵ*/
	short valpowisnull;
	double yidleval;				/*һ�����޹��ܵ�����ֵ*/
	short yidlevalisnull;
	double sidleval;				/*�������޹��ܵ�����ֵ*/
	short sidelvalisnull;
}str_AFN0D_F219;


int decode_afn0D_F217(uchar *as_data, str_AFN0D_F217F218*astr_val, int *ai_step);
int decode_afn0D_F218(uchar *as_data, str_AFN0D_F217F218*astr_val, int *ai_step);
int decode_afn0D_F219(uchar *as_data, str_AFN0D_F219*astr_val, int *ai_step);
#endif 
