#ifndef DECODE_AFN0C_H_INCLUDED
#define DECODE_AFN0C_H_INCLUDED

#include "../public/decode_public.h"
#include "../../myreport/report_public.h"

#ifdef _WIN32
#include "..\..\p_com\common.h"
#else

#include "../../p_com/common.h"
#endif

typedef struct str_AFN00_F03_t
{
    uchar afn;       /*AFN*/
    short len;       /*数据标示长度*/
    uchar PN[255];   /*PN*/
    uchar FN[255];   /*FN*/
    uchar ERR[255];  /*出错否认代码*/
}str_AFN00_F03;

int decode_afn05_frame(str_frame *astr_frame);
int Treatment_afn05_F03(uchar *lc_p, str_frame *astr_frame, int *li_step, int ai_len);
int decode_afn05_F03(uchar *data, str_AFN00_F03 *lstr_val, int *ai_step, int ai_len);


#endif 