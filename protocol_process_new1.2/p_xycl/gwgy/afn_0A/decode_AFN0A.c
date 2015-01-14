#include "decode_AFN0A.h"

int de_AFN0A_FN1(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F1 lstr_afn0A_F1_val;
    f_get_xh(ls_rwxh);

    memset(& lstr_afn0A_F1_val.isnull, DATA_ISNULL, sizeof( lstr_afn0A_F1_val.isnull));

    memset(&( lstr_afn0A_F1_val.val), 0, sizeof( lstr_afn0A_F1_val.val));
    li_res = decode_afn0A_F1(ac_p, &lstr_afn0A_F1_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }

  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  1, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF1(lstr_afn0A_F1_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN2(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F2 lstr_afn0A_F2_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F2_val, 0,sizeof(lstr_afn0A_F2_val));

    li_res = decode_afn0A_F2(ac_p, &lstr_afn0A_F2_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  2, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF2(lstr_afn0A_F2_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN3(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F3 lstr_afn0A_F3_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F3_val, 0,sizeof(lstr_afn0A_F3_val));

    li_res = decode_afn0A_F3(ac_p, &lstr_afn0A_F3_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  3, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF3(lstr_afn0A_F3_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN4(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F4 lstr_afn0A_F4_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F4_val, 0,sizeof(lstr_afn0A_F4_val));

    li_res = decode_afn0A_F4(ac_p, &lstr_afn0A_F4_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  4, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF4(lstr_afn0A_F4_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN5(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F5 lstr_afn0A_F5_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F5_val, 0,sizeof(lstr_afn0A_F5_val));

    li_res = decode_afn0A_F5(ac_p, &lstr_afn0A_F5_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  5, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF5(lstr_afn0A_F5_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN6(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F6 lstr_afn0A_F6_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F6_val, 0,sizeof(lstr_afn0A_F6_val));

    li_res = decode_afn0A_F6(ac_p, &lstr_afn0A_F6_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  6, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF6(lstr_afn0A_F6_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN7(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F7 lstr_afn0A_F7_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F7_val, 0,sizeof(lstr_afn0A_F7_val));

    li_res = decode_afn0A_F7(ac_p, &lstr_afn0A_F7_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     //   if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F7(astr_frame->addr, &lstr_afn0A_F7_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F07数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  7, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF7(lstr_afn0A_F7_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN8(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F8 lstr_afn0A_F8_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F8_val, 0,sizeof(lstr_afn0A_F8_val));

    li_res = decode_afn0A_F8(ac_p, &lstr_afn0A_F8_val, ai_step);
    /*showdataAFN0AF8(lstr_afn0A_F8_val, li_res, *ai_step);*/
    if (li_res == ERROR_SUCCESS)
    {
 
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  8, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }*/
    return li_res;
}

int de_AFN0A_FN9(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F9 lstr_afn0A_F9_val;
    memset(&lstr_afn0A_F9_val, 0,sizeof(lstr_afn0A_F9_val));

    li_res = decode_afn0A_F9(ac_p, &lstr_afn0A_F9_val, ai_step);
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    if (li_res == ERROR_SUCCESS)
    {
       
    }

    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  9, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }

    /**/
    /*showdataAFN0AF9(lstr_afn0A_F9_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN10(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lc_i;
    str_AFN0A_F10 lstr_afn0A_F10_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F10_val, 0,sizeof(lstr_afn0A_F10_val));

    li_res = decode_afn0A_F10(ac_p, &lstr_afn0A_F10_val, ai_step);
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    if (li_res == ERROR_SUCCESS)
    {
       
    }
    /*for (lc_i = 0; lc_i < lstr_afn0A_F10_val.MeterNumber; lc_i++)
    {
        if (astr_frame->msa >= MIN_MSA)
        {
            get_report_2002XX(ls_mes, &li_meslen, astr_frame, lstr_afn0A_F10_val.MeterInfo[lc_i].CLD
                ,  10, ls_rwxh , ls_saveID, li_res, 1);
            f_sendto_mngr(ls_mes, li_meslen);
        }
    }*/
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0
            ,  10, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF10(lstr_afn0A_F10_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN11(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lc_i;
    str_AFN0A_F11 lstr_afn0A_F11_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F11_val, 0,sizeof(lstr_afn0A_F11_val));

    li_res = decode_afn0A_F11(ac_p, &lstr_afn0A_F11_val, ai_step);
    strcpy(ls_saveID, "");
    if (li_res == ERROR_SUCCESS)
    {
        //if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F11(astr_frame->addr, &lstr_afn0A_F11_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F11数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
  /*  for (lc_i = 0; lc_i < lstr_afn0A_F11_val.PulseNumber; lc_i++)
    {
        if (astr_frame->msa >= MIN_MSA)
        {
            get_report_2002XX(ls_mes, &li_meslen, astr_frame, lstr_afn0A_F11_val.pulseinfo[lc_i].CLD
            ,  11, ls_rwxh , ls_saveID, li_res, 2);
            f_sendto_mngr(ls_mes, li_meslen);
        }
    }
    /*showdataAFN0AF11(lstr_afn0A_F11_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN12(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F12 lstr_afn0A_F12_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F12_val, 0,sizeof(lstr_afn0A_F12_val));

    li_res = decode_afn0A_F12(ac_p, &lstr_afn0A_F12_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F12(astr_frame->addr, &lstr_afn0A_F12_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F12数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  12, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF12(lstr_afn0A_F12_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN13(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F13 lstr_afn0A_F13_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F13_val, 0,sizeof(lstr_afn0A_F13_val));

    li_res = decode_afn0A_F13(ac_p, &lstr_afn0A_F13_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       // if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F13(astr_frame->addr, &lstr_afn0A_F13_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F13数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  13, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF13(lstr_afn0A_F13_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN14(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lc_i;
    str_AFN0A_F14 lstr_afn0A_F14_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F14_val, 0,sizeof(lstr_afn0A_F14_val));

    strcpy(ls_saveID, "");
    
    li_res = decode_afn0A_F14(ac_p, &lstr_afn0A_F14_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      //  if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F14(astr_frame->addr, &lstr_afn0A_F14_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F14数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
    /*for (lc_i = 0; lc_i <lstr_afn0A_F14_val.addgroupnumber; lc_i++)
    {
        if (astr_frame->msa >= MIN_MSA)
        {
            get_report_2002XX(ls_mes, &li_meslen, astr_frame, lstr_afn0A_F14_val.addgroupinfo[lc_i].addgroupindex
            ,  14, ls_rwxh , ls_saveID, li_res, 3);
            f_sendto_mngr(ls_mes, li_meslen);
        }
    }*/
 /*   if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0
        ,  14, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF14(lstr_afn0A_F14_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN15(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F15 lstr_afn0A_F15_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F15_val, 0,sizeof(lstr_afn0A_F15_val));

    li_res = decode_afn0A_F15(ac_p, &lstr_afn0A_F15_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      //  if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F15(astr_frame->addr, &lstr_afn0A_F15_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F15数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }

 /*   if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  15, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF15(lstr_afn0A_F15_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN16(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F16 lstr_afn0A_F16_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F16_val, 0,sizeof(lstr_afn0A_F16_val));

    li_res = decode_afn0A_F16(ac_p, &lstr_afn0A_F16_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      //  if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F16(astr_frame->addr, &lstr_afn0A_F16_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F16数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  16, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF16(lstr_afn0A_F16_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN17(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F17 lstr_afn0A_F17_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F17_val, 0,sizeof(lstr_afn0A_F17_val));

    li_res = decode_afn0A_F17(ac_p, &lstr_afn0A_F17_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     //   if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F17(astr_frame->addr, &lstr_afn0A_F17_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F17数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  17, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF17(lstr_afn0A_F17_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN18(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F18 lstr_afn0A_F18_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F18_val, 0,sizeof(lstr_afn0A_F18_val));

    li_res = decode_afn0A_F18(ac_p, &lstr_afn0A_F18_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      //  if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F18(astr_frame->addr, &lstr_afn0A_F18_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F18数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  18, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF18(lstr_afn0A_F18_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN19(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_FLOATFACATOR lstr_afn0A_F19_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F19_val, 0,sizeof(lstr_afn0A_F19_val));
 
    li_res = decode_afn0A_FLOATFACATOR(ac_p, &lstr_afn0A_F19_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        //if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F1920(astr_frame->addr, &lstr_afn0A_F19_val, 19, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F19数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  19, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF19(lstr_afn0A_F19_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN20(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_FLOATFACATOR lstr_afn0A_F20_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F20_val, 0,sizeof(lstr_afn0A_F20_val));

    li_res = decode_afn0A_FLOATFACATOR(ac_p, &lstr_afn0A_F20_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        //if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F1920(astr_frame->addr, &lstr_afn0A_F20_val, 20, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F20数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }

    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  20, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF20(lstr_afn0A_F20_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN21(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F21 lstr_afn0A_F21_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F21_val, 0,sizeof(lstr_afn0A_F21_val));

    li_res = decode_afn0A_F21(ac_p, &lstr_afn0A_F21_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      //  if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F21(astr_frame->addr, &lstr_afn0A_F21_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F21数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  21, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF21(lstr_afn0A_F21_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN22(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F22 lstr_afn0A_F22_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F22_val, 0,sizeof(lstr_afn0A_F22_val));

    li_res = decode_afn0A_F22(ac_p, &lstr_afn0A_F22_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       // if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F22(astr_frame->addr, &lstr_afn0A_F22_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F22数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }
 /*   if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  22, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF22(lstr_afn0A_F22_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN23(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F23 lstr_afn0A_F23_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F23_val, 0,sizeof(lstr_afn0A_F23_val));

    li_res = decode_afn0A_F23(ac_p, &lstr_afn0A_F23_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
    //    if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//        if ((li_res = SAVE_AFN0A_F23(astr_frame->addr, &lstr_afn0A_F23_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
//        {
//            tracelog("afn0A_F23数据库存储错误,错误信息:%s\n", ls_mes);
//        }
    }

   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  23, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF23(lstr_afn0A_F23_val, li_res, *ai_step);*/
    return li_res;
}


int de_AFN0A_FN25(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F25 lstr_afn0A_F25_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F25_val, 0,sizeof(lstr_afn0A_F25_val));

    li_res = decode_afn0A_F25(ac_p, &lstr_afn0A_F25_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  25, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF25(lstr_afn0A_F25_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN26(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F26 lstr_afn0A_F26_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");

	memset(& lstr_afn0A_F26_val.isnull, DATA_ISNULL, sizeof( lstr_afn0A_F26_val.isnull));

	memset(&( lstr_afn0A_F26_val.val), 0, sizeof( lstr_afn0A_F26_val.val));


    li_res = decode_afn0A_F26(ac_p, &lstr_afn0A_F26_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }

   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  26, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF26(lstr_afn0A_F26_val, li_res, *ai_step);*/
    return li_res;
}

//int Treatment_afn0A_F27(uchar *ac_p,str_frame *astr_frame, uchar ac_PN, int *ai_step, int ai_len)
//{
//    int li_res, li_meslen;
//    uchar ls_saveID[16]={0};
//    char ls_rwxh[32]={0}, ls_mes[65535]={0};
//    str_AFN0A_F27 lstr_afn0A_F27_val;
//    f_get_xh(ls_rwxh);
//    strcpy(ls_saveID, "");
//    li_res = decode_afn0A_F27(ac_p, &lstr_afn0A_F27_val, ai_step);
//    if (li_res == ERROR_SUCCESS)
//    {
//        if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
////        if ((li_res = SAVE_AFN0A_F27(astr_frame->addr, ac_PN, &lstr_afn0A_F27_val, ls_saveID, ls_mes)) != ERROR_SUCCESS)
////        {
////            tracelog("afn0A_F27数据库存储错误,错误信息:%s\n", ls_mes);
////        }
//    }
//    if (astr_frame->msa >= MIN_MSA)
//    {
//        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  27, ls_rwxh , ls_saveID, li_res, 2);
//        f_sendto_mngr(ls_mes, li_meslen);
//    }
//    /*showdataAFN0AF27(lstr_afn0A_F27_val, li_res, *ai_step);*/
//    return li_res;
//}

int de_AFN0A_FN28(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F28 lstr_afn0A_F28_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F28_val, 0,sizeof(lstr_afn0A_F28_val));

    li_res = decode_afn0A_F28(ac_p, &lstr_afn0A_F28_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  28, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF28(lstr_afn0A_F28_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN29(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F29 lstr_afn0A_F29_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F29_val, 0,sizeof(lstr_afn0A_F29_val));

    li_res = decode_afn0A_F29(ac_p, &lstr_afn0A_F29_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  29, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF28(lstr_afn0A_F28_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN30(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};

    int li_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    li_val = *ac_p;
    *ai_step =1;
    ac_p++;
    if (li_res == ERROR_SUCCESS)
    {
        
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  30, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF28(lstr_afn0A_F28_val, li_res, *ai_step);*/
    return li_res;
}

//int Treatment_afn0A_F32(uchar *ac_p,str_frame *astr_frame, uchar ac_PN, int *ai_step, int ai_len)
//{
//    int li_res, li_meslen;
//    uchar ls_saveID[16]={0};
//    char ls_rwxh[32]={0}, ls_mes[65535]={0};
//    str_AFN0A_F32_2012 lstr_afn0A_F32_val;
//    f_get_xh(ls_rwxh);
//    strcpy(ls_saveID, "");
//    li_res = decode_afn0A_F32_2012(ac_p, &lstr_afn0A_F32_val, ai_step);
//    if (li_res == ERROR_SUCCESS)
//    {
//        if ((ai_len - (*ai_step)) < 0) return ERROR_FRAME_DATA_LENGTH;
//
////        if ((li_res = SAVE_AFN0A_F32_2012(astr_frame->addr, &lstr_afn0A_F32_val,  ls_saveID, ls_mes)) != ERROR_SUCCESS)
////        {
////            tracelog("afn0A_F33数据库存储错误,错误信息:%s\n", ls_mes);
////        }
//    }
//    if (astr_frame->msa >= MIN_MSA)
//    {
//        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  32, ls_rwxh , ls_saveID, li_res, 3);
//        f_sendto_mngr(ls_mes, li_meslen);
//    }
//    /*showdataAFN0AF33(lstr_afn0A_F33_val, li_res, *ai_step);*/
//    return li_res;
//}

int de_AFN0A_FN33(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F33 lstr_afn0A_F33_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F33_val, 0,sizeof(lstr_afn0A_F33_val));

    li_res = decode_afn0A_F33(ac_p, &lstr_afn0A_F33_val, ai_step);

    if (li_res == ERROR_SUCCESS)
    {
       
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  33, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF33(lstr_afn0A_F33_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN34(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F34 lstr_afn0A_F34_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F34_val, 0,sizeof(lstr_afn0A_F34_val));
   
    li_res = decode_afn0A_F34(ac_p, &lstr_afn0A_F34_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  34, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF33(lstr_afn0A_F33_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN35(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F35 lstr_afn0A_F35_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F35_val, 0,sizeof(lstr_afn0A_F35_val));

    li_res = decode_afn0A_F35(ac_p, &lstr_afn0A_F35_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
    tracelog("afn0A_F35的li_res=%d",li_res);
    /*if (astr_frame->msa >= MIN_MSA)
    {
        tracelog("afn0A_F35的get_report_2002XX");
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  35, ls_rwxh , ls_saveID, li_res, 2);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF33(lstr_afn0A_F33_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN38(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F38F39 lstr_afn0A_F38_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F38_val, 0,sizeof(lstr_afn0A_F38_val));
 
    li_res = decode_afn0A_F38F39(ac_p, &lstr_afn0A_F38_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  38, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF33(lstr_afn0A_F33_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN39(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F38F39 lstr_afn0A_F39_val;
    f_get_xh(ls_rwxh);
    memset(&lstr_afn0A_F39_val, 0,sizeof(lstr_afn0A_F39_val));
 
    li_res = decode_afn0A_F38F39(ac_p, &lstr_afn0A_F39_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  39, ls_rwxh , ls_saveID, li_res,  3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF33(lstr_afn0A_F33_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN41(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F41 lstr_afn0A_F41_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F41_val, 0,sizeof(lstr_afn0A_F41_val));

    li_res = decode_afn0A_F41(ac_p, &lstr_afn0A_F41_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  41, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF41(lstr_afn0A_F41_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN42(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F42 lstr_afn0A_F42_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F42_val, 0,sizeof(lstr_afn0A_F42_val));

    li_res = decode_afn0A_F42(ac_p, &lstr_afn0A_F42_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  42, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF42(lstr_afn0A_F42_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN43(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lstr_afn0A_F43_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F43_val, 0, sizeof(lstr_afn0A_F43_val));

    li_res = decode_afn0A_F43(ac_p, &lstr_afn0A_F43_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  43, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF43(lstr_afn0A_F43_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN44(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F44 lstr_afn0A_F44_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
  memset(& lstr_afn0A_F44_val.isnull, DATA_ISNULL, sizeof( lstr_afn0A_F44_val.isnull));

    memset(&( lstr_afn0A_F44_val.val), 0, sizeof( lstr_afn0A_F44_val.val));

    li_res = decode_afn0A_F44(ac_p, &lstr_afn0A_F44_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  44, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF44(lstr_afn0A_F44_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN45(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_ROUND lstr_afn0A_F45_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F45_val, 0,sizeof(lstr_afn0A_F45_val));
    li_res = decode_afn0A_GETROUND(ac_p, &lstr_afn0A_F45_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  45, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF45(lstr_afn0A_F45_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN46(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0}, lc_unit;
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F46 lstr_afn0A_F46_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F46_val, 0,sizeof(lstr_afn0A_F46_val));
    li_res = decode_afn0A_F46(ac_p, &lstr_afn0A_F46_val, &lc_unit, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  46, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF46(lstr_afn0A_F46_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN47(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F47 lstr_afn0A_F47_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F47_val, 0,sizeof(lstr_afn0A_F47_val));
    li_res = decode_afn0A_F47(ac_p, &lstr_afn0A_F47_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  47, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF47(lstr_afn0A_F47_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN48(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_ROUND lstr_afn0A_F48_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F48_val, 0,sizeof(lstr_afn0A_F48_val));
    li_res = decode_afn0A_GETROUND(ac_p, &lstr_afn0A_F48_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  48, ls_rwxh , ls_saveID, li_res, 3);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF48(lstr_afn0A_F48_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN49(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lstr_afn0A_F49_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F49_val, 0, sizeof(lstr_afn0A_F49_val));
    li_res = decode_afn0A_F49(ac_p, &lstr_afn0A_F49_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
 /*   if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  49, ls_rwxh , ls_saveID, li_res, 5);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF49(lstr_afn0A_F49_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN57(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F57 lstr_afn0A_F57_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F57_val, 0,sizeof(lstr_afn0A_F57_val));
    li_res = decode_afn0A_F57(ac_p, &lstr_afn0A_F57_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  57, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF57(lstr_afn0A_F57_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN58(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lstr_afn0A_F58_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F58_val, 0, sizeof(lstr_afn0A_F58_val));
    li_res = decode_afn0A_F58(ac_p, &lstr_afn0A_F58_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
       
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  58, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF58(lstr_afn0A_F58_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN59(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F59 lstr_afn0A_F59_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F59_val, 0,sizeof(lstr_afn0A_F59_val));
    li_res = decode_afn0A_F59(ac_p, &lstr_afn0A_F59_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      
    }
    /*if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  59, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF59(lstr_afn0A_F59_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN60(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F60 lstr_afn0A_F60_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
  memset(& lstr_afn0A_F60_val.isnull, DATA_ISNULL, sizeof( lstr_afn0A_F60_val.isnull));

    memset(&( lstr_afn0A_F60_val.val), 0, sizeof( lstr_afn0A_F60_val.val));
    li_res = decode_afn0A_F60(ac_p, &lstr_afn0A_F60_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }

 /*   if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  60, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF60(lstr_afn0A_F60_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN61(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F61 lstr_afn0A_F61_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F61_val, 0,sizeof(lstr_afn0A_F61_val));
    li_res = decode_afn0A_F61(ac_p, &lstr_afn0A_F61_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }

  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, 0,  61, ls_rwxh , ls_saveID, li_res, 1);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF61(lstr_afn0A_F61_val, li_res, *ai_step);*/
    return li_res;
}
int de_AFN0A_FN65(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F65F66 lstr_afn0A_F65_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F65_val, 0,sizeof(lstr_afn0A_F65_val));
    li_res = decode_afn0A_F65F66(ac_p, &lstr_afn0A_F65_val,0x0C, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
/*    if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  65, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF65(lstr_afn0A_F65_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN66(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F65F66 lstr_afn0A_F66_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


memset(&lstr_afn0A_F66_val, 0,sizeof(lstr_afn0A_F66_val));

    li_res = decode_afn0A_F65F66(ac_p, &lstr_afn0A_F66_val,0x0D, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
        
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  66, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF66(lstr_afn0A_F66_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN67(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lstr_afn0A_F67_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


memset(&lstr_afn0A_F67_val, 0, sizeof(lstr_afn0A_F67_val));

    li_res = decode_afn0A_F67F68(ac_p, &lstr_afn0A_F67_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
      
    }
   /* if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  67, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF67(lstr_afn0A_F67_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN68(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar lstr_afn0A_F68_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


memset(&lstr_afn0A_F68_val, 0, sizeof(lstr_afn0A_F68_val));

    li_res = decode_afn0A_F67F68(ac_p, &lstr_afn0A_F68_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN73(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F73 lstr_afn0A_F73_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


memset(&lstr_afn0A_F73_val, 0, sizeof(lstr_afn0A_F73_val));

    li_res = decode_afn0A_F73(ac_p, &lstr_afn0A_F73_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN74(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_F74 lstr_afn0A_F74_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


memset(&lstr_afn0A_F74_val, 0, sizeof(lstr_afn0A_F74_val));

    li_res = decode_afn0A_F74(ac_p, &lstr_afn0A_F74_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN75(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_75 lstr_afn0A_F75_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


    memset(&lstr_afn0A_F75_val.val, 0, sizeof(lstr_afn0A_F75_val.val));
    memset(&lstr_afn0A_F75_val.isnull, DATA_ISNULL, sizeof(lstr_afn0A_F75_val.isnull));
    li_res = decode_afn0A_F75(ac_p, &lstr_afn0A_F75_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN76(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen,control_mode = 0;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar *p;
    p =ac_p;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    /*1:当地自动控制 2:远方遥控3:闭锁4:解锁5:当地手动控制*/
    control_mode = *p;
    
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN81(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_81 lstr_afn0A_F81_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F81_val.val, 0, sizeof(lstr_afn0A_F81_val.val));
    memset(&lstr_afn0A_F81_val.isnull, DATA_ISNULL, sizeof(lstr_afn0A_F81_val.isnull));

    li_res = decode_afn0A_F81(ac_p, &lstr_afn0A_F81_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN82(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_82 lstr_afn0A_F82_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    memset(&lstr_afn0A_F82_val.val, 0, sizeof(lstr_afn0A_F82_val.val));
    memset(&lstr_afn0A_F82_val.isnull, DATA_ISNULL, sizeof(lstr_afn0A_F82_val.isnull));

    li_res = decode_afn0A_F82(ac_p, &lstr_afn0A_F82_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}

int de_AFN0A_FN83(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen,Freeze_density = 0;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    uchar *p;
    p =ac_p;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");
    /*冻结密度*/
    Freeze_density = *p;
    
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}
int de_AFN0A_FN150(uchar *ac_p, str_encode_param *str_upframe, uchar ac_PN, uchar ac_FN, int *ai_step, int ai_len)
{
    int li_res, li_meslen;
    uchar ls_saveID[16]={0};
    char ls_rwxh[32]={0}, ls_mes[65535]={0};
    str_AFN0A_150 lstr_afn0A_F150_val;
    f_get_xh(ls_rwxh);
    strcpy(ls_saveID, "");


    memset(&lstr_afn0A_F150_val, 0, sizeof(lstr_afn0A_F150_val));

    li_res = decode_afn0A_F150(ac_p, &lstr_afn0A_F150_val, ai_step);
    if (li_res == ERROR_SUCCESS)
    {
     
    }
  /*  if (astr_frame->msa >= MIN_MSA)
    {
        get_report_2002XX(ls_mes, &li_meslen, astr_frame, ac_PN,  68, ls_rwxh , ls_saveID, li_res, 6);
        f_sendto_mngr(ls_mes, li_meslen);
    }
    /*showdataAFN0AF68(lstr_afn0A_F68_val, li_res, *ai_step);*/
    return li_res;
}




/*********** 解析规约A类数据 *************
	astr_frame	帧结构体

	返回：	 1	解析正常返回
			-1	报文长度不对
			-2	有未定义的FN
			-3  FN=0
			-4  无法解析的数据
			-5  错误的数据
*******************************************/

int decode_AFN0A(str_encode_param *astr_frame)
{
	uchar *P;
	uchar lc_DA1, lc_DA2, lc_DT1, lc_DT2;
	int li_len, li_i, li_j, li_res;
	int li_step;
	str_pn lstr_pn;
	str_fn lstr_fn;
	P = astr_frame->dat;
	
 /*   li_res = get_zd_gylx(astr_frame->addr, &(astr_frame->gylx));
    if(li_res != ERROR_SUCCESS)
    {
        tracelog("decode_afn0D_frame 没有找到规约类型 astr_frame->addr=%d",astr_frame->addr);
        return li_res;
    }
    tracelog("astr_frame->gylx=%d",astr_frame->gylx);*/
	li_len = 8;
	if (astr_frame->seq.tpv == 1)
		li_len += 6;
	if (astr_frame->c.fcb_acd == 1)  /*EC占两个字节*/
		li_len += 2;
	li_len = astr_frame->strl.len - li_len;  //纯DADT和数据,无附加域
	if (li_len <= 0){
		if(gi_save_log)
	    		tracelog("updecode AFN%X li_len <= 0 li_len = %d", astr_frame->afn, li_len);
		return ERROR_FRAME_LENGTH;
	}
    while (li_len > 0)
    {
        /*printf("li_len S : %d \n",li_len);*/
        lc_DA1 = *P;
        lc_DA2 = *(P + 1);
        lc_DT1 = *(P + 2);
        lc_DT2 = *(P + 3);
        lstr_fn = get_FN(lc_DT1, lc_DT2);
        if (lstr_fn.cnt == 1 && lstr_fn.fn[0] == 0)  //??此处有疑问
        {
            return ERROR_RANGE_FN;
        }
        lstr_pn = get_PN(lc_DA1, lc_DA2);
        P = P + 4;
        li_len = li_len - 4;
        for (li_i = 0;li_i < lstr_pn.cnt;li_i++)
        {
            for (li_j = 0;li_j < lstr_pn.cnt;li_j++)
            {
                li_step = 0;
            //    tracelog("lstr_FN.FN[%d]=%d",li_j,lstr_FN.FN[li_j]);
                switch(lstr_fn.fn[li_j])
                {
                    case 1:
			{
				 li_res = de_AFN0A_FN1(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
					
                    case 2:
			{
				 li_res = de_AFN0A_FN2(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 3:
			{	
				 li_res = de_AFN0A_FN3(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
				
                    case 4:
			{
				
				 li_res = de_AFN0A_FN4(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 5:
			{
				 li_res = de_AFN0A_FN5(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 6:
			{
				 li_res = de_AFN0A_FN6(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 7:
			{
				 li_res = de_AFN0A_FN7(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
			case 8:
			{
				 li_res = de_AFN0A_FN8(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 9:
			{
				 li_res = de_AFN0A_FN9(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 10:
			{
				 li_res = de_AFN0A_FN10(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 11:
			{
				 li_res = de_AFN0A_FN11(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 12:
			{
				 li_res = de_AFN0A_FN12(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 13:
			{
				 li_res = de_AFN0A_FN13(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 14:
			{
				 li_res = de_AFN0A_FN14(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 15:
			{
				 li_res = de_AFN0A_FN15(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 16:
			{
				 li_res = de_AFN0A_FN16(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 17:
			{
				 li_res = de_AFN0A_FN17(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 18:
			{
				 li_res = de_AFN0A_FN18(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 19:
			{
				 li_res = de_AFN0A_FN19(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 20:
			{
				 li_res = de_AFN0A_FN20(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 21:
			{
				 li_res = de_AFN0A_FN21(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 22:
			{
				 li_res = de_AFN0A_FN22(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 23:
			{
				 li_res = de_AFN0A_FN23(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 24:	
			case 25:
				{
				 li_res = de_AFN0A_FN25(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}
                    case 26:
                    case 27:
                    case 28:
			{
				 li_res = de_AFN0A_FN28(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 29:
			{
				 li_res = de_AFN0A_FN29(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 30:
			{
				 li_res = de_AFN0A_FN30(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 31:
                    case 33:
			{
				 li_res = de_AFN0A_FN33(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 34:
			{
				 li_res = de_AFN0A_FN34(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 35:
			{
				 li_res = de_AFN0A_FN35(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 36:
                    case 37:
			case 38:
			{
				 li_res = de_AFN0A_FN38(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 39:
			{
				 li_res = de_AFN0A_FN39(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 41:
			{
				 li_res = de_AFN0A_FN41(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 42:	
			{
				 li_res = de_AFN0A_FN42(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 43:
			{
				 li_res = de_AFN0A_FN43(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 44:
			{
				 li_res = de_AFN0A_FN44(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 45:
			{
				 li_res = de_AFN0A_FN45(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 46:
			{
				 li_res = de_AFN0A_FN46(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 47:
			{
				 li_res = de_AFN0A_FN47(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 48:
			{
				 li_res = de_AFN0A_FN48(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 49:
			{
				 li_res = de_AFN0A_FN49(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 57:
			{
				 li_res = de_AFN0A_FN57(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 58:
			{
				 li_res = de_AFN0A_FN58(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 59:
			{
				 li_res = de_AFN0A_FN59(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 60:
			{
				 li_res = de_AFN0A_FN60(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 61:
			{
				 li_res = de_AFN0A_FN61(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 65:
			{
				 li_res = de_AFN0A_FN65(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}	
                    case 66:
			{
				 li_res = de_AFN0A_FN66(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 67:
			{
				 li_res = de_AFN0A_FN67(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
                    case 68:
			{
				 li_res = de_AFN0A_FN68(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}			
			case 73:
 			{
		           li_res = de_AFN0A_FN73(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                
                    case 74:
			{
			    li_res = de_AFN0A_FN74(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                         
                    case 75:
			{
				 li_res = de_AFN0A_FN75(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                        
                    case 76:
			{
			    li_res = de_AFN0A_FN76(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                        
			case 81:
			{
			    li_res = de_AFN0A_FN81(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                   
                    case 82:
			{
			    li_res = de_AFN0A_FN82(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                           
                    case 83:
			{
			    li_res = de_AFN0A_FN83(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}                           
                    case 89:                          
			case 90:			                
                    case 91:
                                 break;
                    case 150:
                   {
			    li_res = de_AFN0A_FN150(P, astr_frame, lstr_pn.pn[li_i], lstr_fn.fn[li_j], &li_step, li_len);
                        if (( li_res != ERROR_SUCCESS)&& (li_res != ERROR_NOT_FOUND_CJDBH) && (li_res != NOT_DEFINE_DATA))
                            return li_res;
                        P = P + li_step;
                        li_len = li_len - li_step;
                        break;
			}    					
                    default :
                    {
                        return ERROR_DATA_INVALID;
                        break;
                    }
                }

       /*         if (get_report_000205(ls_mes, &li_meslen, astr_frame->addr, li_res, lstr_PN.PN[li_i]) == ERROR_SUCCESS)
                {
                    f_sendto_mngr(ls_mes,li_meslen);
                }*/
                if (li_len < 0)
                    return ERROR_FRAME_LENGTH;
            }
        }
    }
    return ERROR_SUCCESS;
}




