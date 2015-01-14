#ifndef DECODE_MAIN_H_INCLUDED
#define DECODE_MAIN_H_INCLUDED

#ifdef _WIN32
#include "..\..\p_com\common.h"
#else
#include "../../p_com/common.h"
#endif

#include "public/decode_public.h"
#include "encode_main.h"
#include "afn_00/decode_AFN00.h"
#include "afn_02/decode_AFN02.h"
#include "afn_03/decode_AFN03.h"
#include "afn_06/decode_AFN06.h"
#include "afn_09/decode_AFN09.h"
#include "afn_0A/decode_AFN0A.h"
#include "afn_0C/decode_AFN0C.h"
#include "afn_0D/decode_AFN0D.h"
#include "afn_0E/decode_AFN0E.h"
#include "afn_0F/decode_AFN0F.h"
#include "afn_10/decode_AFN10.h"

extern void f_process_000101(char *as_data,int ai_len);
extern void f_process_000200(char *as_data,int ai_len);
extern void f_process_000201(char *as_data,int ai_len);



#endif
