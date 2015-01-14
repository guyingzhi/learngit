#ifndef ENCODE_MAIN_H
#define ENCODE_MAIN_H

#include "public/encode_public.h"
#include "afn_00/encode_AFN00.h"
#include "afn_01/encode_AFN01.h"
#include "afn_03/encode_AFN03.h"
#include "afn_04/encode_AFN04.h"
#include "afn_05/encode_AFN05.h"
#include "afn_06/encode_AFN06.h"
#include "afn_09/encode_AFN09.h"
#include "afn_0A/encode_AFN0A.h"
#include "afn_0B/encode_AFN0B.h"
#include "afn_0C/encode_AFN0C.h"
#include "afn_0D/encode_AFN0D.h"
#include "afn_0E/encode_AFN0E.h"
#include "afn_0F/encode_AFN0F.h"
#include "afn_10/encode_AFN10.h"

extern void encode_main(char *dat_in, int dat_len);
extern int encode_down_frame(str_encode_param *encode_param, int prot_type);




#endif

