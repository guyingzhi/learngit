#ifndef REPORT_PUBLIC_H_INCLUDED
#define REPORT_PUBLIC_H_INCLUDED

#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include "..\..\p_com\common.h"
#else
#include "../../p_com/common.h"
#endif

#include "../gwgy/public/public.h"

extern void get_report_000103(char *as_report, int *li_reportlen, uchar *as_mes, int ai_meslen, char *as_rwxh, int prot_type);
extern void get_report_000200(char *ls_report, int *ai_len, char *as_rwxh, int socket_id);
extern void get_report_000204(char *ls_report, int *ai_len, char *as_rwxh, int front_id, int prot_type, int termal_addr);



#endif
