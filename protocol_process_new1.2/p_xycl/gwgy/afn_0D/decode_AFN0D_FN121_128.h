#ifndef DECODE_AFN0D_FN121_128_H
#define DECODE_AFN0D_FN121_128_H

#include "../public/decode_public.h"


typedef struct str_AFN0D_F121_123_val_t
{
    datetime TD;          				  /*ʱ��*/
    uchar XBCS;           						  /*г������*/
    unsigned short overlimitU[19];  						/*��ѹԽ��ʱ��*/
    unsigned short overlimitI[19]; 				  /*����Խ��ʱ��*/
}str_AFN0D_F121_123_val;

typedef struct str_AFN0D_F121_123_ISNULL_t
{
    short TD;               							/*ʱ���пձ�־*/
    short overlimitU[19];  								 /*��ѹԽ��ʱ���пձ�־*/
    short overlimitI[19];  										 /*����Խ��ʱ���пձ�־*/
}str_AFN0D_F121_123_ISNULL;

typedef struct str_AFN0D_F121_123_t
{
    str_AFN0D_F121_123_val val;
    str_AFN0D_F121_123_ISNULL isnull;
}str_AFN0D_F121_123;

typedef struct str_AFN0D_F124_126_val_t
{
	datetime  TD;			/*����ʱ��*/
	uint   num;				/*г������*/
	double Uall;					/*�ܻ����ѹ����ֵ*/
	double Uodd;							/*��λ���*/
	double Ueven;									/*ż�λ���*/
	double Uval[19];				/*N��г����ѹ����ֵ*/
	double Iall;				/*N��г����������ֵ*/
	double Ivall[19];	/*����ʱ��*/
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