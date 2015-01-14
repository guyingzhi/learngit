#ifndef DECODE_AFN06_FN1_150_H
#define DECODE_AFN06_FN1_150_H

#include "../public/decode_public.h"

typedef struct str_AFN06_F11_t
{
   uchar  chip_number[16];
   uchar certificate_number [16];
   uchar counter[16];
   uchar chip_state;
   uchar key[16];	
}str_AFN06_F11;


typedef struct str_AFN06_F12_t_0
{
	short len;
	uchar state;
	uchar chat_ID;
	uchar CRL_number[16];
	uchar certificate_number [16];
	uchar  terminal_certificate[1024];//不知道应该定义多大?
	uchar EKs2[16];
	uchar data[64];
	
}str_AFN06_F12_0;
typedef struct str_AFN06_F12_t_1
{
	short len;
	uchar state;
	uchar chat_ID;
	uchar EKs2[16];
	uchar R3[16];
	uchar MAC3[16];
	
}str_AFN06_F12_1;

typedef struct str_AFN06_F13_t
{
	uchar R3[16];
	uchar MAC3[4];
}str_AFN06_F13;

typedef struct str_AFN06_F15_t
{
	uchar certificate_number [16];;
	uchar terminal_key[64];
}str_AFN06_F15;

typedef struct str_AFN06_F17_t
{
	uchar R4 [16];;
	uchar R5[16];
}str_AFN06_F17;

typedef struct str_AFN06_F18_t
{
	uchar R6 [16];;
	
}str_AFN06_F18;


int decode_afn06_F11(uchar *data, str_AFN06_F11 *astr_val, int *ai_step);
int decode_afn06_F12_0(uchar *data, str_AFN06_F12_0 *astr_val, int *ai_step);
int decode_afn06_F12_1(uchar *data, str_AFN06_F12_1 *astr_val, int *ai_step);
int decode_afn06_F13(uchar *data, str_AFN06_F13 *astr_val, int *ai_step);
int decode_afn06_F15(uchar *data, str_AFN06_F15 *astr_val, int *ai_step);
int decode_afn06_F17(uchar *data, str_AFN06_F17 *astr_val, int *ai_step);
int decode_afn06_F18(uchar *data, str_AFN06_F18 *astr_val, int *ai_step);

#endif
