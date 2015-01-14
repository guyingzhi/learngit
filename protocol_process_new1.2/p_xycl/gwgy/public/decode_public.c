#include "decode_public.h"


/*************** 按位取值***************
  ac_byte 单个字节
  ac_pos  从第几位开始取值(低位为D0，高位为D7)
  ac_len  取值的长度
  返回值  从高位到低位
****************************************/
uchar getbytebybit(uchar ac_byte, uchar ac_pos, uchar ac_len)
{
    uchar lc_bit;
    lc_bit = pow(2.0, (double)ac_len) - 1;
    return ((ac_byte & (lc_bit << ac_pos)) >> ac_pos);
}

/************* 取密度值 ***************
        lc_val    输入的密度字节
    返回
        lmd_val   密度值
*******************************************/
str_MD setMD(uchar lc_val)
{
    str_MD lstr_val;
    if (lc_val > 3)
    {
        lstr_val.notdfine = ERROR_NULL_DENSITY;
    }
    else
    {
        lstr_val.notdfine = ERROR_SUCCESS;
        lstr_val.val = lc_val;
    }
    return lstr_val;
}

/************* 判断低压数据是否为空 ***************
    P   被判断数据的起始指针
    ac_len 被判断的数据长度
    返回：
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*******************************************/
short lowdataisnull(uchar *P, int ac_len)
{
    int li_i;
    for (li_i = 0; li_i < ac_len; li_i++)
    {
        if ((*(P + li_i) != 0xFF) && (*(P + li_i) != 0xEE))
          return DATA_ISNOTNULL;
    }
    return DATA_ISNULL;
}

/************* 判断数据是否为空 ***************
    P   被判断数据的起始指针
    ac_len 被判断的数据长度
    返回：
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*******************************************/
short dataisnull(uchar *P, int ac_len)
{
    int li_i;
    for (li_i = 0; li_i < ac_len; li_i++)
    {
        if (*(P + li_i) != 0xEE)
          return DATA_ISNOTNULL;
    }
    return DATA_ISNULL;
}

/************* 将数值转换为BCD码 ***************
    ac_BCD BCD码
    返回：BCD码代表的数值
*******************************************/
/*uchar ByteToBCDByte(uchar ac_byte)
{
    uchar lc_val;
    lc_val = ac_byte / 100 * 256 + (ac_byte %100) / 10 * 16 + ac_byte % 10;
    return lc_val;
}*/

/*************  解析规约DA  ***************
    ac_DA1   DA1
    ac_DA2   DA2
    输出结果
      str_PN  PN的结构体，
      包含多个PN的数组及PN的数量
*******************************************/


str_pn get_PN(uchar ac_DA1,uchar ac_DA2)
{
    str_pn lstr_val;
    uchar li_j;
    memset(&lstr_val, 0, sizeof(lstr_val));

    if ((ac_DA1 == 0)  && (ac_DA2 == 0))
    {
        lstr_val.cnt = 1;
        lstr_val.pn[0] = 0;
    }
    else if ((ac_DA1 == 0xFF) && (ac_DA2 == 0xFF))
    {
        lstr_val.cnt = 1;
        lstr_val.pn[0] = 0xFFFF;
    }
    else
    {
    	 for (li_j = 0; li_j <= 7; li_j++ )
   	{
            if (((ac_DA1 >> li_j) & 0x01) == 1)
            {
                lstr_val.pn[lstr_val.cnt] = (ac_DA2 - 1) * 8 + (li_j + 1);
                lstr_val.cnt++;
                //长度超过规定的2040，异常退出
                if (lstr_val.cnt >= 2040) break;
            }
        }
    }
    return lstr_val;
}

/*************  解析规约DT  ***************
    ac_DT1   DT1
    ac_DT2   DT2
    输出结果
      str_FN  FN的结构体，
      包含多个FN的数组及FN的数量
*******************************************/
str_fn get_FN(uchar ac_DT1, uchar ac_DT2)
{
    str_fn lstr_val;
    uchar li_i;
    memset(&lstr_val, 0, sizeof(lstr_val));
//    for (li_i = 0; li_i < 255; li_i++)
//        lstr_val.fn[li_i] = 0;
    if (ac_DT1 == 0 && ac_DT2 == 0)
    {
        lstr_val.cnt = 1;
        lstr_val.fn[0] = 0;
    }
    else
    {
        for (li_i = 0; li_i <= 7; li_i++)
        {
            if (((ac_DT1 >> li_i) & 0x01) == 1)
            {
                lstr_val.fn[lstr_val.cnt] = ac_DT2 * 8 + li_i + 1;
                lstr_val.cnt++;
            }
        }
    }
    return lstr_val;
}
/***数据格式01 日期时间***
        ac_ptr 报文指针
        at_val  输出的日期
        ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat01(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 6;
    if (dataisnull(ac_ptr,6))
        return DATA_ISNULL;
    adt_val->sec  = BCDByteToByte(*ac_ptr);
    adt_val->min  = BCDByteToByte(*(ac_ptr + 1));
    adt_val->hour = BCDByteToByte(*(ac_ptr + 2));
    adt_val->day = BCDByteToByte(*(ac_ptr + 3));
    adt_val->mon  = BCDByteToByte(*(ac_ptr + 4) & 0x1f);
    adt_val->year = BCDByteToByte(*(ac_ptr + 5)) + 100;
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;
    return DATA_ISNOTNULL;
}

/***数据格式02 浮点数***
        ac_ptr 报文指针
        adb_val  输出浮点值
        ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat02(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 2;
    int li_i,li_n;
    if (dataisnull(ac_ptr,2))
        return DATA_ISNULL;
    li_i = ((*(ac_ptr+1) & 0xE0) >> 5) * -1 + 4;
    li_n = BCDByteToByte(*(ac_ptr+1) & 0x0f) *100 + BCDByteToByte(*ac_ptr);
    if (li_n == 0)
    {
        *adb_val = 0;
    }
    else
    {
        if ((*(ac_ptr+1) & 0x10) == 0)
        {
            *adb_val = li_n * pow(10.0,(double)li_i);
        }
        else
        {
            *adb_val = li_n * pow(10.0, (double)li_i) * -1;
        }
    }
    return DATA_ISNOTNULL;
}

/***数据格式03 整数******
        ac_ptr 报文指针
        al_val  输出的解码值
        ac_unit 输出的解码单位
        ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat03(uchar *ac_ptr, int *al_val, uchar *ac_unit, int *ai_step)
{
    *ai_step = 4;
    if (dataisnull(ac_ptr, 4))
        return DATA_ISNULL;
    *ac_unit = (*(ac_ptr + 3) & 0x40) >> 6 ;
    if ((*(ac_ptr + 3) & 0x10) == 0)
    {
        *al_val = BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100
             +BCDByteToByte(*(ac_ptr + 2)) * 10000 + BCDByteToByte((*(ac_ptr +3)) & 0x0f) * 1000000;
    }
    else
    {
        *al_val = -1 * (BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100
             +BCDByteToByte(*(ac_ptr + 2)) * 10000 + BCDByteToByte((*(ac_ptr +3)) & 0x0f) * 1000000);
    }
    return DATA_ISNOTNULL;
}

/***数据格式04 整数******
        ac_ptr 报文指针
        ai_val  输出的解码结果，
            正数代表上浮
            负数代表下浮
        ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat04(uchar *ac_ptr, int *ai_val, int *ai_step)
{
    *ai_step = 1;
    if (dataisnull(ac_ptr , 1))
        return DATA_ISNULL;
    if ((*(ac_ptr) & 0x80) ==0)
    {
        *ai_val = BCDByteToByte((*ac_ptr) & 0x7f);
    }
    else
    {
        *ai_val = -1 * BCDByteToByte((*ac_ptr) & 0x7f);
    }
    return DATA_ISNOTNULL;
}

/***数据格式05 浮点数******
        ac_ptr 报文指针
        adb_val  输出的解码结果
        ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat05(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 2))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 10 + (double)(BCDByteToByte(*(ac_ptr + 1) & 0x7f)) * 10;
    if ((*(ac_ptr+1) & 0x80) != 0)
        *adb_val = *adb_val * -1;
    return DATA_ISNOTNULL;
}

/***数据格式06 浮点数******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat06(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 2))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 100 + (double)(BCDByteToByte(*(ac_ptr + 1) & 0x7f));
    if ((*(ac_ptr+1) & 0x80) != 0)
        *adb_val = *adb_val * -1;
    return DATA_ISNOTNULL;
}

/***数据格式07 浮点数******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat07(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 2))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 10 + (double)(BCDByteToByte(*(ac_ptr + 1))) * 10;
    return DATA_ISNOTNULL;
}

/***数据格式08 整数******
   ac_ptr 报文指针
   ai_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat08(uchar *ac_ptr, int *ai_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 2))
        return DATA_ISNULL;
    *ai_val = BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100;
    return DATA_ISNOTNULL;
}

/***数据格式09 浮点数******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat09(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr , 3))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 10000 + (double)(BCDByteToByte(*(ac_ptr + 1))) / 100
        + (double)(BCDByteToByte((*(ac_ptr + 2)) & 0x7f));
    if ((*(ac_ptr + 2) & 0x80) != 0)
        *adb_val = *adb_val * -1;
    return DATA_ISNOTNULL;
}

/***数据格式10 浮点数******
   ac_ptr 报文指针
   ai_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat10(uchar *ac_ptr, int *ai_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr , 3))
        return DATA_ISNULL;
    *ai_val = BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100 + BCDByteToByte(*(ac_ptr + 2)) * 10000;
    return DATA_ISNOTNULL;
}

/***数据格式11 浮点数******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat11(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 4;
    if (dataisnull(ac_ptr , 4))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*(ac_ptr + 1))) + (double)(BCDByteToByte(*ac_ptr)) / 100
        + (double)(BCDByteToByte(*(ac_ptr + 2))) * 100 + (double)(BCDByteToByte(*(ac_ptr + 3))) * 10000;
    return DATA_ISNOTNULL;
}

/***数据格式12 12位表地址结构******
   ac_ptr 报文指针
   ac_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
     0 数据有效
*************************/
short getdataformat12(uchar *ac_ptr, str_add12 *astr_val, int *ai_step)
{
    *ai_step = 6;
    astr_val->ADDRESS[0] = *ac_ptr & 0x0f;
    astr_val->ADDRESS[1] = (*(ac_ptr) & 0xf0) >> 4;
    astr_val->ADDRESS[2] = *(ac_ptr + 1) & 0x0f;
    astr_val->ADDRESS[3] = (*(ac_ptr + 1) & 0xf0) >> 4;
    astr_val->ADDRESS[4] = *(ac_ptr + 2) & 0x0f;
    astr_val->ADDRESS[5] = (*(ac_ptr + 2) & 0xf0) >> 4;
    astr_val->ADDRESS[6] = *(ac_ptr + 3) & 0x0f;
    astr_val->ADDRESS[7] = (*(ac_ptr + 3) & 0xf0) >> 4;
    astr_val->ADDRESS[8] = *(ac_ptr + 4) & 0x0f;
    astr_val->ADDRESS[9] = (*(ac_ptr + 4) & 0xf0) >> 4;
    astr_val->ADDRESS[10] = *(ac_ptr + 5) & 0x0f;
    astr_val->ADDRESS[11] = (*(ac_ptr + 5) & 0xf0) >> 4;
    return DATA_ISNOTNULL;
}

/***数据格式13 浮点数******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat13(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 4;
    if (dataisnull(ac_ptr , 4))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 10000 + (double)(BCDByteToByte(*(ac_ptr + 1))) /100
        + (double)(BCDByteToByte(*(ac_ptr + 2)))  + (double)(BCDByteToByte(*(ac_ptr + 3))) * 100;
    return DATA_ISNOTNULL;
}

/***数据格式14 浮点数******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat14(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 5;
    if (dataisnull(ac_ptr , 5))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 10000 + (double)(BCDByteToByte(*(ac_ptr + 1))) /100
        + (double)(BCDByteToByte(*(ac_ptr + 2)))  + (double)(BCDByteToByte(*(ac_ptr + 3))) * 100
        + (double)(BCDByteToByte(*(ac_ptr + 4))) * 10000 ;
    return DATA_ISNOTNULL;
}

/***数据格式15 日期时间***
   ac_ptr 报文指针
   at_val  输出的日期
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat15(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 5;
    if (dataisnull(ac_ptr,5))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = BCDByteToByte(*ac_ptr);
    adt_val->hour = BCDByteToByte(*(ac_ptr + 1));
    adt_val->day = BCDByteToByte(*(ac_ptr + 2));
    adt_val->mon = BCDByteToByte(*(ac_ptr + 3));
    adt_val->year = BCDByteToByte(*(ac_ptr + 4));  //BCDByteToByte(*(ac_ptr + 4)) + 100
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/***数据格式16 日期时间***
   ac_ptr 报文指针
   adt_in  参考时间，输出时间
       的年月从中获得
   at_val  输出的日期
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat16(uchar *ac_ptr, datetime *adt_in, datetime *adt_val, int *ai_step)
{
    datetime ldt_dt;
    *ai_step = 4;
    if (dataisnull(ac_ptr,4))
        return DATA_ISNULL;
    adt_val->sec = BCDByteToByte(*ac_ptr);
    adt_val->min = BCDByteToByte(*(ac_ptr+1));
    adt_val->hour = BCDByteToByte(*(ac_ptr + 2));
    adt_val->day = BCDByteToByte(*(ac_ptr + 3));
    if (adt_val->day <= adt_in->day)
    {
        ldt_dt = *adt_in;
    }
    else
    {
        after_month(adt_in , &ldt_dt , -1);
    }
    adt_val->mon = ldt_dt.mon;
    adt_val->year = ldt_dt.year;
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/***数据格式17 日期时间***
   ac_ptr 报文指针
   adt_in  参考时间，输出时间
       的年从中获得
   at_val  输出的日期
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat17(uchar *ac_ptr, datetime *adt_in, datetime *adt_val, int *ai_step)
{
    datetime ldt_dt;
    *ai_step = 4;
    if (dataisnull(ac_ptr,4))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = BCDByteToByte(*ac_ptr);
    adt_val->hour = BCDByteToByte(*(ac_ptr+1));
    adt_val->day = BCDByteToByte(*(ac_ptr + 2));
    adt_val->mon = BCDByteToByte(*(ac_ptr + 3));
    ldt_dt = *adt_in;
    if (adt_val->mon > adt_in->mon)
    {
        ldt_dt.year--;
    }
    adt_val->year = ldt_dt.year;

    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;
    return DATA_ISNOTNULL;
}
/***数据格式18 日期时间***
   ac_ptr 报文指针
   adt_in  参考时间，输出时间
       的年月从中获得
   at_val  输出的日期
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat18(uchar *ac_ptr, datetime *adt_in, datetime *adt_val, int *ai_step)
{
    datetime ldt_dt;
    *ai_step = 3;

    if (dataisnull(ac_ptr,3))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = BCDByteToByte(*(ac_ptr));
    adt_val->hour = BCDByteToByte(*(ac_ptr + 1));
    adt_val->day = BCDByteToByte(*(ac_ptr + 2));
    ldt_dt = *adt_in;

    if (adt_val->day <= adt_in->day)
    {
        ldt_dt = *adt_in;
    }
    else
    {
        after_month(adt_in , &ldt_dt , -1);
    }
    adt_val->year = ldt_dt.year;
    adt_val->mon = ldt_dt.mon;
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/***数据格式19 时间***
   ac_ptr 报文指针
   at_val  输出的时间，不包含日期
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat19(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr,2))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = BCDByteToByte(*(ac_ptr));
    adt_val->hour = BCDByteToByte(*(ac_ptr + 1));
    adt_val->day = 0;
    adt_val->mon = 0;
    adt_val->year = 0;
    return DATA_ISNOTNULL;
}

/***数据格式20 日期***
   ac_ptr 报文指针
   at_val  输出的日期，不包含时间
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat20(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr,3))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = 0;
    adt_val->hour = 0;
    adt_val->day = BCDByteToByte(*(ac_ptr ));
    adt_val->mon = BCDByteToByte(*(ac_ptr + 1));
    adt_val->year = BCDByteToByte(*(ac_ptr + 2));  //BCDByteToByte(*(ac_ptr + 2)) + 100;
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/***数据格式21 日期***
   ac_ptr 报文指针
   adt_val  输出的日期，只包括年月
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat21(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr,2))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = 0;
    adt_val->hour = 0;
    adt_val->day = 0;
    adt_val->mon = BCDByteToByte(*ac_ptr);
    adt_val->year = BCDByteToByte(*(ac_ptr + 1)) + 100;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/***数据格式22 浮点数***
   ac_ptr 报文指针
   adb_val  输出的值
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat22(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 1;
    if (dataisnull(ac_ptr,1))
    {
        return DATA_ISNULL;
    }
    *adb_val = (double)BCDByteToByte(*ac_ptr) /10;
    return DATA_ISNOTNULL;
}

/***数据格式23 浮点数***
   ac_ptr 报文指针
   adb_val  输出的值
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat23(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr,3))
    {
        return DATA_ISNULL;
    }
    *adb_val = (double)BCDByteToByte(*ac_ptr) /10000
            + (double)BCDByteToByte(*(ac_ptr + 1))/100
            + (double)BCDByteToByte(*(ac_ptr + 2));
    return DATA_ISNOTNULL;
}

/***数据格式24 日期时间***
   ac_ptr 报文指针
   adt_val  输出的日期时间
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat24(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 6;
    if (dataisnull(ac_ptr,6))
        return DATA_ISNULL;
    adt_val->sec = BCDByteToByte(*(ac_ptr + 5));
    adt_val->min = BCDByteToByte(*(ac_ptr + 4));
    adt_val->hour = BCDByteToByte(*(ac_ptr + 3));
    adt_val->day = BCDByteToByte(*(ac_ptr + 2));
    adt_val->mon = BCDByteToByte(*(ac_ptr + 1));
    adt_val->year = BCDByteToByte(*(ac_ptr)) + 100;
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/***数据格式25 浮点数 20130506by Li haitao******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat25(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr , 3))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 1000
             + (double)(BCDByteToByte(*(ac_ptr + 1))) / 10
             + (double)(BCDByteToByte(*(ac_ptr + 2) & 0x7f) * 10);
    if ((*(ac_ptr+2) & 0x80) != 0)
        *adb_val = *adb_val * -1;
    return DATA_ISNOTNULL;
}

/***数据格式26 浮点数 20130506by Li haitao******
   ac_ptr 报文指针
   adb_val  输出的解码结果
   ai_step 该结构所占长度
   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat26(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 3))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 1000  + (double)(BCDByteToByte(*(ac_ptr + 1))) / 10;
//    if ((*(ac_ptr+2) & 0x80) != 0)
//        *adb_val = *adb_val * -1;
    return DATA_ISNOTNULL;
}

/***数据格式27 ***
   ac_ptr 报文指针
   adt_val  输出的数量
   ai_step 该结构所占长度

   返回结果
        DATA_ISNOTNULL：数据不为空
        DATA_ISNULL：数据为空
*************************/
short getdataformat27(uchar *ac_ptr, int *ai_val, int *ai_step)
{
    *ai_step = 4;
    if (dataisnull(ac_ptr,4))
        return DATA_ISNULL;
    *ai_val = BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100 + BCDByteToByte(*(ac_ptr + 2)) * 10000 + BCDByteToByte(*(ac_ptr + 3)) * 1000000;

    return DATA_ISNOTNULL;
}

short getdataformatYMD(uchar *ac_ptr, datetime *adt_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr,3))
        return DATA_ISNULL;
    adt_val->sec = 0;
    adt_val->min = 0;
    adt_val->hour = 0;
    adt_val->day = BCDByteToByte(*(ac_ptr + 2));
    adt_val->mon = BCDByteToByte(*(ac_ptr + 1));
    adt_val->year = BCDByteToByte(*(ac_ptr)) + 100;
    if ((adt_val->day < 1) || (adt_val->day > 31))
        return DATA_ISNULL;
    if ((adt_val->mon < 1) || (adt_val->mon > 12))
        return DATA_ISNULL;

    return DATA_ISNOTNULL;
}

/*低压数据格式01 用于低压电能示值数据*/
short getlowdataformat01(uchar *ac_ptr, double *adb_val, int *ai_step)
{
   *ai_step = 4;
   if (lowdataisnull(ac_ptr, 4))
   {
      return DATA_ISNULL;
   }
   *adb_val = (double)BCDByteToByte(*ac_ptr) /100
            + (double)BCDByteToByte(*(ac_ptr + 1))
            + (double)BCDByteToByte(*(ac_ptr + 2))* 100
            + (double)BCDByteToByte(*(ac_ptr + 3))* 10000;
    return DATA_ISNOTNULL;
}

/*低压数据格式02 用于低压电压数据*/
short getlowdataformat02(uchar *ac_ptr, double *adb_val, int *ai_step)
{
   *ai_step = 2;
   if (lowdataisnull(ac_ptr, 2))
   {
      return DATA_ISNULL;
   }
   *adb_val = (double)BCDByteToByte(*ac_ptr)
            + (double)BCDByteToByte(*(ac_ptr + 1)) * 100;
    return DATA_ISNOTNULL;
}

/*低压数据格式03 用于低压电流数据*/
short getlowdataformat03(uchar *ac_ptr, double *adb_val, int *ai_step)
{
   *ai_step = 2;
   if (lowdataisnull(ac_ptr, 2))
   {
      return DATA_ISNULL;
   }
   *adb_val = (double)BCDByteToByte(*ac_ptr) / 100
            + (double)BCDByteToByte(getbytebybit(*(ac_ptr + 1), 0, 7));
   if (getbytebybit(*(ac_ptr + 1), 7, 1))
   {
       *adb_val = *adb_val * (-1);
   }
   return DATA_ISNOTNULL;
}

/*低压数据格式04 用于低压功率数据*/
short getlowdataformat04(uchar *ac_ptr, double *adb_val, int *ai_step)
{
   *ai_step = 3;
   if (lowdataisnull(ac_ptr, 3))
   {
      return DATA_ISNULL;
   }
   *adb_val = (double)BCDByteToByte(*ac_ptr) / 10000
            + (double)BCDByteToByte(*(ac_ptr + 1)) / 100
            + (double)BCDByteToByte(getbytebybit(*(ac_ptr + 2), 0, 7));
   if (getbytebybit(*(ac_ptr + 1), 7, 1))
   {
       *adb_val = *adb_val * (-1);
   }
   return DATA_ISNOTNULL;
}

/*低压数据格式05 用于低压功率因数数据*/
short getlowdataformat05(uchar *ac_ptr, double *adb_val, int *ai_step)
{
   *ai_step = 2;
   if (lowdataisnull(ac_ptr, 2))
   {
      return DATA_ISNULL;
   }
   *adb_val = (double)BCDByteToByte(*ac_ptr) / 1000
            + (double)BCDByteToByte(*(ac_ptr + 1)) / 10;
    return DATA_ISNOTNULL;
}

/*低压数据格式剩余电量 用于低压加电数据*/
short getlowdataformatSYDL(uchar *ac_ptr, double *adb_val, int *ai_step)
{
   *ai_step = 5;
   if (lowdataisnull(ac_ptr, 5))
   {
      return DATA_ISNULL;
   }
   *adb_val = (double)BCDByteToByte(*ac_ptr) / 100
            + (double)BCDByteToByte(*(ac_ptr + 1))
            + (double)BCDByteToByte(*(ac_ptr + 2)) * 100
            + (double)BCDByteToByte(*(ac_ptr + 3)) * 10000;
    if ((*(ac_ptr + 4) & 0x01) == 0)
    {
        *adb_val = (*adb_val) * -1;
    }
    return DATA_ISNOTNULL;
}

uchar getqxinoneday(str_AFN0C0D_QX *astr_qx,str_AFN0C0D_QXINONEDAY *astr_QX_inday,uchar startindex)
{
    int li_act_day, li_check_day;
    uchar lc_i;
    if (startindex > astr_qx->val_num)
        return 0; /*没有日曲线可以获取*/
    li_act_day = ((astr_qx->val_time[startindex].year  + 1900) * 10000)
            +(astr_qx->val_time[startindex].mon * 100)
            +astr_qx->val_time[startindex].day;
    astr_QX_inday->intday = li_act_day;
    astr_QX_inday->val_num = 0;
    for (lc_i = startindex; lc_i <= astr_qx->val_num; lc_i++)
    {
        li_check_day = ((astr_qx->val_time[lc_i].year + 1900) * 10000)
            +(astr_qx->val_time[lc_i].mon * 100)
            +(astr_qx->val_time[lc_i].day);
        if (li_act_day != li_check_day)
            return lc_i;
        astr_QX_inday->data_point[astr_QX_inday->val_num] =
            ((astr_qx->val_time[lc_i].hour * 60) + astr_qx->val_time[lc_i].min) / 15;
        astr_QX_inday->val[astr_QX_inday->val_num] = astr_qx->val[lc_i];
        astr_QX_inday->isnull[astr_QX_inday->val_num] = astr_qx->isnull[lc_i];
        astr_QX_inday->val_num++;
    }
    if (lc_i <= astr_qx->val_num)
    {
        return lc_i;
    }
    else
    {
        return 0;
    }
}

uchar gettime0inqx(str_AFN0C0D_QX *astr_qx, uchar startindex)
{
    uchar lc_i;
    if (startindex > astr_qx->val_num)
        return 0; /*已经扫描完*/
    for (lc_i = startindex; lc_i <= astr_qx->val_num; lc_i++)
    {
        if ((astr_qx->val_time[lc_i].hour == 0) && (astr_qx->val_time[lc_i].min == 0))
            return lc_i;
    }
    return 0;
}

void get0A_FNname(char *as_FNname, uchar ai_FN)
{
    switch (ai_FN)
    {
        case 1:
            sprintf(as_FNname, "终端通信参数");
            break;
        case 2:
            sprintf(as_FNname, "终端中继转发设置");
            break;
        case 3:
            sprintf(as_FNname, "主站IP地址和端口");
            break;
        case 4:
            sprintf(as_FNname, "主站电话号码和短信中心号码");
            break;
        case 5:
            sprintf(as_FNname, "终端密码");
            break;
        case 6:
            sprintf(as_FNname, "终端组地址");
            break;
        case 7:
            sprintf(as_FNname, "终端抄表日设置");
            break;
        case 8:
            sprintf(as_FNname, "终端事件记录配置");
            break;
        case 9:
            sprintf(as_FNname, "终端配置数量表");
            break;
        case 10:
            sprintf(as_FNname, "终端电能表/交流采样装置配置");
            break;
        case 11:
            sprintf(as_FNname, "终端脉冲配置");
            break;
        case 12:
            sprintf(as_FNname, "终端状态量输入参数");
            break;
        case 13:
            sprintf(as_FNname, "终端电压电流模拟量配置");
            break;
        case 14:
            sprintf(as_FNname, "终端总加组配置");
            break;
        case 15:
            sprintf(as_FNname, "有功总电能量差动越限事件参数");
            break;
        case 16:
            sprintf(as_FNname, "虚拟专网用户名、密码");
            break;
        case 17:
            sprintf(as_FNname, "终端保安定值");
            break;
        case 18:
            sprintf(as_FNname, "终端功控时段");
            break;
        case 19:
            sprintf(as_FNname, "终端时段功控定值浮动系数");
            break;
        case 20:
            sprintf(as_FNname, "终端月电能量控定值浮动系数");
            break;
        case 21:
            sprintf(as_FNname, "终端电能量费率时段和费率数");
            break;
        case 22:
            sprintf(as_FNname, "终端电能量费率");
            break;
        case 23:
            sprintf(as_FNname, "终端催费告警参数");
            break;
        case 24:
            sprintf(as_FNname, "终端抄表间隔设置");
            break;
        case 25:
            sprintf(as_FNname, "测量点基本参数");
            break;
        case 26:
            sprintf(as_FNname, "测量点限值参数");
            break;
        case 27:
            sprintf(as_FNname, "测量点数据冻结参数");
            break;
        case 28:
            sprintf(as_FNname, "测量点功率因数分段限值");
            break;
        case 33:
            sprintf(as_FNname, "总加组数据冻结参数");
            break;
        case 41:
            sprintf(as_FNname, "时段功控定值");
            break;
        case 42:
            sprintf(as_FNname, "厂休功控参数");
            break;
        case 43:
            sprintf(as_FNname, "功率控制的功率计算滑差时间");
            break;
        case 44:
            sprintf(as_FNname, "营业报停控参数");
            break;
        case 45:
            sprintf(as_FNname, "功控轮次设定");
            break;
        case 46:
            sprintf(as_FNname, "月电量控定值");
            break;
        case 47:
            sprintf(as_FNname, "购电量控参数");
            break;
        case 48:
            sprintf(as_FNname, "电控轮次设定");
            break;
        case 49:
            sprintf(as_FNname, "功控告警时间");
            break;
        case 57:
            sprintf(as_FNname, "终端声音告警允许∕禁止设置");
            break;
        case 58:
            sprintf(as_FNname, "终端自动保电参数");
            break;
        case 59:
            sprintf(as_FNname, "电能表异常判别阈值设定");
            break;
        case 60:
            sprintf(as_FNname, "谐波限值");
            break;
        case 61:
            sprintf(as_FNname, "直流模拟量接入参数");
            break;
        case 62:
            sprintf(as_FNname, "虚拟专网工作方式");
            break;
        case 63:
            sprintf(as_FNname, "配置低压居民电表参数");
            break;
        case 64:
            sprintf(as_FNname, "集中器每天预抄开始时间");
            break;
        case 65:
            sprintf(as_FNname, "定时发送1类数据任务设置");
            break;
        case 66:
            sprintf(as_FNname, "定时发送2类数据任务设置");
            break;
        case 67:
            sprintf(as_FNname, "定时发送1类数据任务启动/停止设置");
            break;
        case 68:
            sprintf(as_FNname, "定时发送2类数据任务启动/停止设置");
            break;
        case 73:
            sprintf(as_FNname, "电容器参数");
            break;
        case 74:
            sprintf(as_FNname, "电容器投切运行参数");
            break;
        case 75:
            sprintf(as_FNname, "电容器保护参数");
            break;
        case 76:
            sprintf(as_FNname, "电容器投切控制方式");
            break;
        case 81:
            sprintf(as_FNname, "直流模拟量输入变比");
            break;
        case 82:
            sprintf(as_FNname, "直流模拟量限值");
            break;
        case 83:
            sprintf(as_FNname, "直流模拟量冻结参数");
            break;
        case 85:
            sprintf(as_FNname, "低压居民表状态设置");
            break;
        case 89:
            sprintf(as_FNname, "本地103规约通讯参数设置");
            break;
        case 90:
            sprintf(as_FNname, "抄表数据量选配参数");
            break;
        case 91:
            sprintf(as_FNname, "第二通讯通道工作方式配置及两个通讯通道启用参数");
            break;
        case 105:
            sprintf(as_FNname, "终端管理的中继器地址参数");
            break;
        case 106:
            sprintf(as_FNname, "终端电能表中继路由配置参数");
            break;
        case 107:
            sprintf(as_FNname, "居民电表中继路由配置参数");
            break;
        default :
            sprintf(as_FNname, "规约中未定义的FN:%d", ai_FN);
            break;
    }
}

void get0E_ERCname(char *as_FNname, uchar ai_ERC)
{
    switch (ai_ERC)
    {
        case 1:
            sprintf(as_FNname, "数据初始化和版本变更记录");
            break;
        case 2:
            sprintf(as_FNname, "参数丢失记录");
            break;
        case 3:
            sprintf(as_FNname, "参数变更记录");
            break;
        case 4:
            sprintf(as_FNname, "状态量变位记");
            break;
        case 5:
            sprintf(as_FNname, "遥控跳闸记录");
            break;
        case 6:
            sprintf(as_FNname, "功控跳闸记录");
            break;
        case 7:
            sprintf(as_FNname, "电控跳闸记录");
            break;
        case 8:
            sprintf(as_FNname, "电能表参数变更");
            break;
        case 9:
            sprintf(as_FNname, "电流回路异常");
            break;
        case 10:
            sprintf(as_FNname, "电压回路异常");
            break;
        case 11:
            sprintf(as_FNname, "相序异常");
            break;
        case 12:
            sprintf(as_FNname, "电能表时间超差");
            break;
        case 13:
            sprintf(as_FNname, "电表故障信息");
            break;
        case 14:
            sprintf(as_FNname, "终端停/上电事件");
            break;
        case 15:
            sprintf(as_FNname, "谐波越限告警");
            break;
        case 16:
            sprintf(as_FNname, "直流模拟量越限记录");
            break;
        case 17:
            sprintf(as_FNname, "电压/电流不平衡度越限记录");
            break;
        case 18:
            sprintf(as_FNname, "电容器投切自锁记录");
            break;
        case 19:
            sprintf(as_FNname, "购电参数设置记录");
            break;
        case 20:
            sprintf(as_FNname, "消息认证错误记录");
            break;
        case 21:
            sprintf(as_FNname, "终端故障记录");
            break;
        case 22:
            sprintf(as_FNname, "有功总电能量差动越限事件记录");
            break;
        case 24:
            sprintf(as_FNname, "电压越限记录");
            break;
        case 25:
            sprintf(as_FNname, "电流越限记录");
            break;
        case 26:
            sprintf(as_FNname, "视在功率越限记录");
            break;
        case 27:
            sprintf(as_FNname, "电能表示度下降记录");
            break;
        case 28:
            sprintf(as_FNname, "电能量超差记录");
            break;
        case 29:
            sprintf(as_FNname, "电能表飞走记录");
            break;
        case 30:
            sprintf(as_FNname, "电能表停走记录");
            break;
        default:
            sprintf(as_FNname, "规约未定义的事件类型");
            break;
    }
}

void geterrorname (char *as_errname, int ai_errindex)
{
    switch(ai_errindex)
    {
        case DECODE_ERROR:
            sprintf(as_errname, "解码错误");
            break;
        case ERROR_NOT_FOUND_TERMBH:
            sprintf(as_errname, "没有找到终端逻辑编号");
            break;
        case ERROR_NOT_FOUND_CJDBH:
            sprintf(as_errname, "返回帧中的测量点未找到对应的采集点档案");
            break;
        case ERROR_NOT_FOUND_MNLBH:
            sprintf(as_errname, "没有找到模拟量编号");
            break;
        case ERROR_NOT_FOUND_GCID:
            sprintf(as_errname, "没有找到过程号");
            break;
        case ERROR_NOT_FOUND_DAID:
            sprintf(as_errname, "没有找到档案号");
            break;
        case ERROR_WRITE_DATA:
            sprintf(as_errname, "写入数据失败");
            break;
        case ERROR_NOT_FOUND_SUMBH:
            sprintf(as_errname, "没有找到总加组号");
            break;
        case ERROR_READ_DATA:
            sprintf(as_errname, "读取数据失败");
            break;
        case ERROR_NOT_FOUND_RECORD:
            sprintf(as_errname, "没有找到数据记录");
            break;
        case ERROR_FRAME_LENGTH:
            sprintf(as_errname, "报文长度不对");
            break;
        case ERROR_FRAME_CRC:
            sprintf(as_errname, "报文CRC校验不对");
            break;
        case ERROR_FRAME_DATA_LENGTH:
            sprintf(as_errname, "ERROR_FRAME_DATA_LENGTH");
            break;
        case ERROR_RANGE_DATETIME:
            sprintf(as_errname, "日期时间超出范围");
            break;
        case ERROR_RANGE_DATA:
            sprintf(as_errname, "数据超出范围");
            break;
        case ERROR_RANGE_NUMBER:
            sprintf(as_errname, "数据的有效数字超出范围");
            break;
        case ERROR_DATA_INVALID:
            sprintf(as_errname, "报文数据体的数据无效");
            break;
        case ERROR_RANGE_FN:
            sprintf(as_errname, "FN超出范围");
            break;
        case ERROR_RANGE_PN:
            sprintf(as_errname, "PN超出范围");
            break;
        case ERROR_NULL_TD:
            sprintf(as_errname, "时标为空");
            break;
        case ERROR_NULL_DATE:
            sprintf(as_errname, "日期为空");
            break;
        case ERROR_NULL_DENSITY:
            sprintf(as_errname, "密度为空");
            break;
        case ERROR_NULL_POINT:
            sprintf(as_errname, "点数为空");
            break;
        case ERROR_NULL_DATA:
            sprintf(as_errname, "数据为空");
            break;
        case ERROR_NULL_FLS:
            sprintf(as_errname, "费率数为空");
            break;
        case ERROR_NULL_XBCNT:
            sprintf(as_errname, "谐波次数为空");
            break;
        case ERROR_DB_DISCONNECT:
            sprintf(as_errname, "数据库连接断开");
            break;
        case ERROR_PNISZERO_ERC:
            sprintf(as_errname, "电表事件的PN=0");
            break;
        default:
            sprintf(as_errname, "未定义的错误,错误代号:%d", ai_errindex);
            break;
    }
}

/*比较两个时间大小，time1>=time2返回1,time1<time2返回0*/
uchar time_after_check(datetime *time1, datetime *time2)
{
    int int_date1, int_date2;
    int_date1 = (time1->year + 1900) * 10000
        + time1->mon * 100 + time1->day;
    int_date2 = (time2->year + 1900) * 10000
        + time2->mon * 100 + time2->day;
    if (int_date1 > int_date2)
    {
        return 1;

    }
    else
    {
        if (int_date1 < int_date2)
        {
            return 0;
        }
        else
        {
            int_date1 = time1->hour * 60 + time1->min;
            int_date2 = time2->hour * 60 + time2->min;
            if (int_date1 >= int_date2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

}

short get_erc_type(short ai_erc)
{
    switch (ai_erc)
    {
        /*终端事件*/
        case 1:
        case 2:
        case 3:
        case 14:
        case 20:
        case 21:
        {
            return 1;
        }
        /*终端事件*/
        case 8:
        case 9:
        case 11:
        case 12:
        case 13:
        case 15:
        case 17:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        {
            return 2;
        }
        case 22:
        {
            return 3;
        }
        case 16:
        {
            return 4;
        }
        case 4:
        case 5:
        case 6:
        case 7:
        case 19:
        {
            return 5;
        }
        default:
            return 6;
    }
}

/*void get_data_ec1(str_encode_param *astr_frame, uchar *ac_ec1)
{
    int li_len;
    li_len = astr_frame->l - 8 - 2;
    if (astr_frame->tpv == 1)
    li_len -= 6;
    *ac_ec1 = *(astr_frame->data + li_len);
}*/

/*void check_date_event(int ai_ret, int ai_addr, int ai_afn, int ai_fn, int ai_pn)
{
    int li_ret;
    char ls_mes[65535], ls_mesinfo[65535], ls_err[65535], ls_sydw[20], ls_rwxh[20];
    int li_meslen;

    switch (ai_ret)
    {
        case ERROR_RANGE_DATETIME:
        case ERROR_NULL_DATE:
        case ERROR_NULL_TD:
        {
            li_ret = SAVE_EVENT_ERC101(ai_addr, 1, ai_ret, ai_afn, ai_fn, ai_pn, ls_err, ls_sydw, ls_mesinfo);
            if (li_ret == ERROR_SUCCESS)
            {
                f_get_xh(ls_rwxh);
                get_report_000220(ls_mes, &li_meslen, ls_rwxh, ai_addr, 6, ls_sydw, ls_mesinfo);
                f_sendto_mngr(ls_mes, li_meslen);
            }
            break;
        }
        default:
			break;
    }
}*/

/*void f_lostcheck_process(uchar ai_afn,int ai_addr,int ai_fn,int ai_pn,int ai_day)
{
    int li_type,li_meslen;
    char ls_mes[65535];
    if ((li_type = f_get_losttype(ai_afn,ai_fn)) > 0)
    {
        get_report_000401(ls_mes, &li_meslen, ai_addr, ai_pn, ai_day, li_type);
        f_sendto_mngr(ls_mes,li_meslen);
    }
}*/

int f_get_losttype(uchar ai_afn,int ai_fn)
{
    int li_res;
    li_res = 0;
    if (ai_afn == 0x0d)
    {
        switch(ai_fn)
        {
            case 89:
                li_res = 1;
                break;
            case 90:
                li_res = 2;
                break;
            case 91:
                li_res = 3;
                break;
            case 92:
                li_res = 4;
                break;
            case 93:
                li_res = 5;
                break;
            case 94:
                li_res = 6;
                break;
            case 82:
                li_res = 7;
                break;
            case 83:
                li_res = 8;
                break;
            case 84:
                li_res = 9;
                break;
            case 81:
                li_res = 10;
                break;
            case 86:
                li_res = 11;
                break;
            case 87:
                li_res = 12;
                break;
            case 88:
                li_res = 13;
                break;
            case 85:
                li_res = 14;
                break;
            case 101:
                li_res = 15;
                break;
            case 102:
                li_res = 16;
                break;
            case 103:
                li_res = 17;
                break;
            case 104:
                li_res = 18;
                break;
            case 106:
                li_res = 19;
                break;
            case 107:
                li_res = 20;
                break;
            case 108:
                li_res = 21;
                break;
            case 105:
                li_res = 22;
                break;
            case 49:
                li_res = 51;
                break;
            case 50:
                li_res = 52;
                break;
            case 27:
                li_res = 53;
                break;
            case 29:
                li_res = 54;
                break;
            case 25:
                li_res = 55;
                break;
            case 1:
            case 2:
                li_res = 56;
                break;
            case 3:
            case 4:
                li_res = 57;
                break;
            case 31:
                li_res = 58;
                break;
        }
    }
    if (ai_afn == 0x0c)
    {
        switch(ai_fn)
        {
            case 13:
                li_res = 59;
                break;
        }
    }
    return li_res;
}


//判断是否低压测量点
int is_lowpn(uchar ac_afn, uchar ac_fn)
{
    int li_res;

    switch (ac_afn)
    {
        case 4:
        {
            switch (ac_fn)
            {
                case 107:
                {
                    li_res = 1;
                    break;
                }
                default:
                    li_res = 0;
                    break;
            }
            break;
        }
        case 0x0C:
        {
            switch (ac_fn)
            {
                case 129:
                case 130:
                case 131:
                case 132:
                case 145:
                case 167:
                case 177:
                case 207:
                case 208:
                {
                    li_res = 1;
                    break;
                }
            default:
                li_res = 0;
                break;
            }
            break;
        }
        case 0x0D:
        {
            switch(ac_fn)
            {
                case 153:
                case 161:
                case 162:
                case 163:
                case 164:
                case 169:
                case 170:
                case 171:
                case 172:
                case 173:
                case 174:
                case 175:
                case 176:
                case 177:
                case 178:
                case 185:
                case 193:
                {
                    li_res = 1;
                    break;
                }
            default:
                li_res = 0;
                break;
            }
            break;
        }
        default:
            li_res = 0;
            break;
    }
    return li_res;
}




