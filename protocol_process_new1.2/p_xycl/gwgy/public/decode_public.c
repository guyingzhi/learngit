#include "decode_public.h"


/*************** ��λȡֵ***************
  ac_byte �����ֽ�
  ac_pos  �ӵڼ�λ��ʼȡֵ(��λΪD0����λΪD7)
  ac_len  ȡֵ�ĳ���
  ����ֵ  �Ӹ�λ����λ
****************************************/
uchar getbytebybit(uchar ac_byte, uchar ac_pos, uchar ac_len)
{
    uchar lc_bit;
    lc_bit = pow(2.0, (double)ac_len) - 1;
    return ((ac_byte & (lc_bit << ac_pos)) >> ac_pos);
}

/************* ȡ�ܶ�ֵ ***************
        lc_val    ������ܶ��ֽ�
    ����
        lmd_val   �ܶ�ֵ
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

/************* �жϵ�ѹ�����Ƿ�Ϊ�� ***************
    P   ���ж����ݵ���ʼָ��
    ac_len ���жϵ����ݳ���
    ���أ�
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/************* �ж������Ƿ�Ϊ�� ***************
    P   ���ж����ݵ���ʼָ��
    ac_len ���жϵ����ݳ���
    ���أ�
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/************* ����ֵת��ΪBCD�� ***************
    ac_BCD BCD��
    ���أ�BCD��������ֵ
*******************************************/
/*uchar ByteToBCDByte(uchar ac_byte)
{
    uchar lc_val;
    lc_val = ac_byte / 100 * 256 + (ac_byte %100) / 10 * 16 + ac_byte % 10;
    return lc_val;
}*/

/*************  ������ԼDA  ***************
    ac_DA1   DA1
    ac_DA2   DA2
    ������
      str_PN  PN�Ľṹ�壬
      �������PN�����鼰PN������
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
                //���ȳ����涨��2040���쳣�˳�
                if (lstr_val.cnt >= 2040) break;
            }
        }
    }
    return lstr_val;
}

/*************  ������ԼDT  ***************
    ac_DT1   DT1
    ac_DT2   DT2
    ������
      str_FN  FN�Ľṹ�壬
      �������FN�����鼰FN������
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
/***���ݸ�ʽ01 ����ʱ��***
        ac_ptr ����ָ��
        at_val  ���������
        ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ02 ������***
        ac_ptr ����ָ��
        adb_val  �������ֵ
        ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ03 ����******
        ac_ptr ����ָ��
        al_val  ����Ľ���ֵ
        ac_unit ����Ľ��뵥λ
        ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ04 ����******
        ac_ptr ����ָ��
        ai_val  ����Ľ�������
            ���������ϸ�
            ���������¸�
        ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ05 ������******
        ac_ptr ����ָ��
        adb_val  ����Ľ�����
        ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ06 ������******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ07 ������******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
*************************/
short getdataformat07(uchar *ac_ptr, double *adb_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 2))
        return DATA_ISNULL;
    *adb_val = (double)(BCDByteToByte(*ac_ptr)) / 10 + (double)(BCDByteToByte(*(ac_ptr + 1))) * 10;
    return DATA_ISNOTNULL;
}

/***���ݸ�ʽ08 ����******
   ac_ptr ����ָ��
   ai_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
*************************/
short getdataformat08(uchar *ac_ptr, int *ai_val, int *ai_step)
{
    *ai_step = 2;
    if (dataisnull(ac_ptr , 2))
        return DATA_ISNULL;
    *ai_val = BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100;
    return DATA_ISNOTNULL;
}

/***���ݸ�ʽ09 ������******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ10 ������******
   ac_ptr ����ָ��
   ai_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
*************************/
short getdataformat10(uchar *ac_ptr, int *ai_val, int *ai_step)
{
    *ai_step = 3;
    if (dataisnull(ac_ptr , 3))
        return DATA_ISNULL;
    *ai_val = BCDByteToByte(*ac_ptr) + BCDByteToByte(*(ac_ptr + 1)) * 100 + BCDByteToByte(*(ac_ptr + 2)) * 10000;
    return DATA_ISNOTNULL;
}

/***���ݸ�ʽ11 ������******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ12 12λ���ַ�ṹ******
   ac_ptr ����ָ��
   ac_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
     0 ������Ч
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

/***���ݸ�ʽ13 ������******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ14 ������******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ15 ����ʱ��***
   ac_ptr ����ָ��
   at_val  ���������
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ16 ����ʱ��***
   ac_ptr ����ָ��
   adt_in  �ο�ʱ�䣬���ʱ��
       �����´��л��
   at_val  ���������
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ17 ����ʱ��***
   ac_ptr ����ָ��
   adt_in  �ο�ʱ�䣬���ʱ��
       ������л��
   at_val  ���������
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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
/***���ݸ�ʽ18 ����ʱ��***
   ac_ptr ����ָ��
   adt_in  �ο�ʱ�䣬���ʱ��
       �����´��л��
   at_val  ���������
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ19 ʱ��***
   ac_ptr ����ָ��
   at_val  �����ʱ�䣬����������
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ20 ����***
   ac_ptr ����ָ��
   at_val  ��������ڣ�������ʱ��
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ21 ����***
   ac_ptr ����ָ��
   adt_val  ��������ڣ�ֻ��������
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ22 ������***
   ac_ptr ����ָ��
   adb_val  �����ֵ
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ23 ������***
   ac_ptr ����ָ��
   adb_val  �����ֵ
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ24 ����ʱ��***
   ac_ptr ����ָ��
   adt_val  ���������ʱ��
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ25 ������ 20130506by Li haitao******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ26 ������ 20130506by Li haitao******
   ac_ptr ����ָ��
   adb_val  ����Ľ�����
   ai_step �ýṹ��ռ����
   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/***���ݸ�ʽ27 ***
   ac_ptr ����ָ��
   adt_val  ���������
   ai_step �ýṹ��ռ����

   ���ؽ��
        DATA_ISNOTNULL�����ݲ�Ϊ��
        DATA_ISNULL������Ϊ��
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

/*��ѹ���ݸ�ʽ01 ���ڵ�ѹ����ʾֵ����*/
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

/*��ѹ���ݸ�ʽ02 ���ڵ�ѹ��ѹ����*/
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

/*��ѹ���ݸ�ʽ03 ���ڵ�ѹ��������*/
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

/*��ѹ���ݸ�ʽ04 ���ڵ�ѹ��������*/
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

/*��ѹ���ݸ�ʽ05 ���ڵ�ѹ������������*/
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

/*��ѹ���ݸ�ʽʣ����� ���ڵ�ѹ�ӵ�����*/
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
        return 0; /*û�������߿��Ի�ȡ*/
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
        return 0; /*�Ѿ�ɨ����*/
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
            sprintf(as_FNname, "�ն�ͨ�Ų���");
            break;
        case 2:
            sprintf(as_FNname, "�ն��м�ת������");
            break;
        case 3:
            sprintf(as_FNname, "��վIP��ַ�Ͷ˿�");
            break;
        case 4:
            sprintf(as_FNname, "��վ�绰����Ͷ������ĺ���");
            break;
        case 5:
            sprintf(as_FNname, "�ն�����");
            break;
        case 6:
            sprintf(as_FNname, "�ն����ַ");
            break;
        case 7:
            sprintf(as_FNname, "�ն˳���������");
            break;
        case 8:
            sprintf(as_FNname, "�ն��¼���¼����");
            break;
        case 9:
            sprintf(as_FNname, "�ն�����������");
            break;
        case 10:
            sprintf(as_FNname, "�ն˵��ܱ�/��������װ������");
            break;
        case 11:
            sprintf(as_FNname, "�ն���������");
            break;
        case 12:
            sprintf(as_FNname, "�ն�״̬���������");
            break;
        case 13:
            sprintf(as_FNname, "�ն˵�ѹ����ģ��������");
            break;
        case 14:
            sprintf(as_FNname, "�ն��ܼ�������");
            break;
        case 15:
            sprintf(as_FNname, "�й��ܵ������Խ���¼�����");
            break;
        case 16:
            sprintf(as_FNname, "����ר���û���������");
            break;
        case 17:
            sprintf(as_FNname, "�ն˱�����ֵ");
            break;
        case 18:
            sprintf(as_FNname, "�ն˹���ʱ��");
            break;
        case 19:
            sprintf(as_FNname, "�ն�ʱ�ι��ض�ֵ����ϵ��");
            break;
        case 20:
            sprintf(as_FNname, "�ն��µ������ض�ֵ����ϵ��");
            break;
        case 21:
            sprintf(as_FNname, "�ն˵���������ʱ�κͷ�����");
            break;
        case 22:
            sprintf(as_FNname, "�ն˵���������");
            break;
        case 23:
            sprintf(as_FNname, "�ն˴߷Ѹ澯����");
            break;
        case 24:
            sprintf(as_FNname, "�ն˳���������");
            break;
        case 25:
            sprintf(as_FNname, "�������������");
            break;
        case 26:
            sprintf(as_FNname, "��������ֵ����");
            break;
        case 27:
            sprintf(as_FNname, "���������ݶ������");
            break;
        case 28:
            sprintf(as_FNname, "�����㹦�������ֶ���ֵ");
            break;
        case 33:
            sprintf(as_FNname, "�ܼ������ݶ������");
            break;
        case 41:
            sprintf(as_FNname, "ʱ�ι��ض�ֵ");
            break;
        case 42:
            sprintf(as_FNname, "���ݹ��ز���");
            break;
        case 43:
            sprintf(as_FNname, "���ʿ��ƵĹ��ʼ��㻬��ʱ��");
            break;
        case 44:
            sprintf(as_FNname, "Ӫҵ��ͣ�ز���");
            break;
        case 45:
            sprintf(as_FNname, "�����ִ��趨");
            break;
        case 46:
            sprintf(as_FNname, "�µ����ض�ֵ");
            break;
        case 47:
            sprintf(as_FNname, "�������ز���");
            break;
        case 48:
            sprintf(as_FNname, "����ִ��趨");
            break;
        case 49:
            sprintf(as_FNname, "���ظ澯ʱ��");
            break;
        case 57:
            sprintf(as_FNname, "�ն������澯����M��ֹ����");
            break;
        case 58:
            sprintf(as_FNname, "�ն��Զ��������");
            break;
        case 59:
            sprintf(as_FNname, "���ܱ��쳣�б���ֵ�趨");
            break;
        case 60:
            sprintf(as_FNname, "г����ֵ");
            break;
        case 61:
            sprintf(as_FNname, "ֱ��ģ�����������");
            break;
        case 62:
            sprintf(as_FNname, "����ר��������ʽ");
            break;
        case 63:
            sprintf(as_FNname, "���õ�ѹ���������");
            break;
        case 64:
            sprintf(as_FNname, "������ÿ��Ԥ����ʼʱ��");
            break;
        case 65:
            sprintf(as_FNname, "��ʱ����1��������������");
            break;
        case 66:
            sprintf(as_FNname, "��ʱ����2��������������");
            break;
        case 67:
            sprintf(as_FNname, "��ʱ����1��������������/ֹͣ����");
            break;
        case 68:
            sprintf(as_FNname, "��ʱ����2��������������/ֹͣ����");
            break;
        case 73:
            sprintf(as_FNname, "����������");
            break;
        case 74:
            sprintf(as_FNname, "������Ͷ�����в���");
            break;
        case 75:
            sprintf(as_FNname, "��������������");
            break;
        case 76:
            sprintf(as_FNname, "������Ͷ�п��Ʒ�ʽ");
            break;
        case 81:
            sprintf(as_FNname, "ֱ��ģ����������");
            break;
        case 82:
            sprintf(as_FNname, "ֱ��ģ������ֵ");
            break;
        case 83:
            sprintf(as_FNname, "ֱ��ģ�����������");
            break;
        case 85:
            sprintf(as_FNname, "��ѹ�����״̬����");
            break;
        case 89:
            sprintf(as_FNname, "����103��ԼͨѶ��������");
            break;
        case 90:
            sprintf(as_FNname, "����������ѡ�����");
            break;
        case 91:
            sprintf(as_FNname, "�ڶ�ͨѶͨ��������ʽ���ü�����ͨѶͨ�����ò���");
            break;
        case 105:
            sprintf(as_FNname, "�ն˹�����м�����ַ����");
            break;
        case 106:
            sprintf(as_FNname, "�ն˵��ܱ��м�·�����ò���");
            break;
        case 107:
            sprintf(as_FNname, "�������м�·�����ò���");
            break;
        default :
            sprintf(as_FNname, "��Լ��δ�����FN:%d", ai_FN);
            break;
    }
}

void get0E_ERCname(char *as_FNname, uchar ai_ERC)
{
    switch (ai_ERC)
    {
        case 1:
            sprintf(as_FNname, "���ݳ�ʼ���Ͱ汾�����¼");
            break;
        case 2:
            sprintf(as_FNname, "������ʧ��¼");
            break;
        case 3:
            sprintf(as_FNname, "���������¼");
            break;
        case 4:
            sprintf(as_FNname, "״̬����λ��");
            break;
        case 5:
            sprintf(as_FNname, "ң����բ��¼");
            break;
        case 6:
            sprintf(as_FNname, "������բ��¼");
            break;
        case 7:
            sprintf(as_FNname, "�����բ��¼");
            break;
        case 8:
            sprintf(as_FNname, "���ܱ�������");
            break;
        case 9:
            sprintf(as_FNname, "������·�쳣");
            break;
        case 10:
            sprintf(as_FNname, "��ѹ��·�쳣");
            break;
        case 11:
            sprintf(as_FNname, "�����쳣");
            break;
        case 12:
            sprintf(as_FNname, "���ܱ�ʱ�䳬��");
            break;
        case 13:
            sprintf(as_FNname, "��������Ϣ");
            break;
        case 14:
            sprintf(as_FNname, "�ն�ͣ/�ϵ��¼�");
            break;
        case 15:
            sprintf(as_FNname, "г��Խ�޸澯");
            break;
        case 16:
            sprintf(as_FNname, "ֱ��ģ����Խ�޼�¼");
            break;
        case 17:
            sprintf(as_FNname, "��ѹ/������ƽ���Խ�޼�¼");
            break;
        case 18:
            sprintf(as_FNname, "������Ͷ��������¼");
            break;
        case 19:
            sprintf(as_FNname, "����������ü�¼");
            break;
        case 20:
            sprintf(as_FNname, "��Ϣ��֤�����¼");
            break;
        case 21:
            sprintf(as_FNname, "�ն˹��ϼ�¼");
            break;
        case 22:
            sprintf(as_FNname, "�й��ܵ������Խ���¼���¼");
            break;
        case 24:
            sprintf(as_FNname, "��ѹԽ�޼�¼");
            break;
        case 25:
            sprintf(as_FNname, "����Խ�޼�¼");
            break;
        case 26:
            sprintf(as_FNname, "���ڹ���Խ�޼�¼");
            break;
        case 27:
            sprintf(as_FNname, "���ܱ�ʾ���½���¼");
            break;
        case 28:
            sprintf(as_FNname, "�����������¼");
            break;
        case 29:
            sprintf(as_FNname, "���ܱ���߼�¼");
            break;
        case 30:
            sprintf(as_FNname, "���ܱ�ͣ�߼�¼");
            break;
        default:
            sprintf(as_FNname, "��Լδ������¼�����");
            break;
    }
}

void geterrorname (char *as_errname, int ai_errindex)
{
    switch(ai_errindex)
    {
        case DECODE_ERROR:
            sprintf(as_errname, "�������");
            break;
        case ERROR_NOT_FOUND_TERMBH:
            sprintf(as_errname, "û���ҵ��ն��߼����");
            break;
        case ERROR_NOT_FOUND_CJDBH:
            sprintf(as_errname, "����֡�еĲ�����δ�ҵ���Ӧ�Ĳɼ��㵵��");
            break;
        case ERROR_NOT_FOUND_MNLBH:
            sprintf(as_errname, "û���ҵ�ģ�������");
            break;
        case ERROR_NOT_FOUND_GCID:
            sprintf(as_errname, "û���ҵ����̺�");
            break;
        case ERROR_NOT_FOUND_DAID:
            sprintf(as_errname, "û���ҵ�������");
            break;
        case ERROR_WRITE_DATA:
            sprintf(as_errname, "д������ʧ��");
            break;
        case ERROR_NOT_FOUND_SUMBH:
            sprintf(as_errname, "û���ҵ��ܼ����");
            break;
        case ERROR_READ_DATA:
            sprintf(as_errname, "��ȡ����ʧ��");
            break;
        case ERROR_NOT_FOUND_RECORD:
            sprintf(as_errname, "û���ҵ����ݼ�¼");
            break;
        case ERROR_FRAME_LENGTH:
            sprintf(as_errname, "���ĳ��Ȳ���");
            break;
        case ERROR_FRAME_CRC:
            sprintf(as_errname, "����CRCУ�鲻��");
            break;
        case ERROR_FRAME_DATA_LENGTH:
            sprintf(as_errname, "ERROR_FRAME_DATA_LENGTH");
            break;
        case ERROR_RANGE_DATETIME:
            sprintf(as_errname, "����ʱ�䳬����Χ");
            break;
        case ERROR_RANGE_DATA:
            sprintf(as_errname, "���ݳ�����Χ");
            break;
        case ERROR_RANGE_NUMBER:
            sprintf(as_errname, "���ݵ���Ч���ֳ�����Χ");
            break;
        case ERROR_DATA_INVALID:
            sprintf(as_errname, "�����������������Ч");
            break;
        case ERROR_RANGE_FN:
            sprintf(as_errname, "FN������Χ");
            break;
        case ERROR_RANGE_PN:
            sprintf(as_errname, "PN������Χ");
            break;
        case ERROR_NULL_TD:
            sprintf(as_errname, "ʱ��Ϊ��");
            break;
        case ERROR_NULL_DATE:
            sprintf(as_errname, "����Ϊ��");
            break;
        case ERROR_NULL_DENSITY:
            sprintf(as_errname, "�ܶ�Ϊ��");
            break;
        case ERROR_NULL_POINT:
            sprintf(as_errname, "����Ϊ��");
            break;
        case ERROR_NULL_DATA:
            sprintf(as_errname, "����Ϊ��");
            break;
        case ERROR_NULL_FLS:
            sprintf(as_errname, "������Ϊ��");
            break;
        case ERROR_NULL_XBCNT:
            sprintf(as_errname, "г������Ϊ��");
            break;
        case ERROR_DB_DISCONNECT:
            sprintf(as_errname, "���ݿ����ӶϿ�");
            break;
        case ERROR_PNISZERO_ERC:
            sprintf(as_errname, "����¼���PN=0");
            break;
        default:
            sprintf(as_errname, "δ����Ĵ���,�������:%d", ai_errindex);
            break;
    }
}

/*�Ƚ�����ʱ���С��time1>=time2����1,time1<time2����0*/
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
        /*�ն��¼�*/
        case 1:
        case 2:
        case 3:
        case 14:
        case 20:
        case 21:
        {
            return 1;
        }
        /*�ն��¼�*/
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


//�ж��Ƿ��ѹ������
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




