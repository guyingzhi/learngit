#ifndef DECODE_PUBLIC_H_INCLUDED
#define DECODE_PUBLIC_H_INCLUDED

#include "public.h"

#define NMGY_DM  1
#define MIN_MSA  11
#define MAX_MSA  127
#define SET_TIME 180

/*************************************
    �ֽ����ͣ���ʾ��Լ���һ���ֽڣ�
    ��Ӧ����� unsigned char
    ��Pro*C���unsigned charʶ����ַ���
    �������ݻᱨ��Ϊ���ݶ����short
**************************************/
typedef short byte;

typedef struct str_MD_t
{
    byte  val;        /*�ܶ�ֵ*/
    short notdfine;   /*���ܶ��Ƿ񱻶���*/
}str_MD;
/*typedef struct str_LowPN_t
{*/
/*    ushort PN[2041];  /*LowPN���飬���2032��PN*/
/*    ushort PNLEN;     /*PN�����е���ЧPN����*/
/*}str_LowPN;*/


typedef struct str_AFN0C0D_QX_t
{
    int val_num;
    double val[255];
    short isnull[255];
    datetime val_time[255];
}str_AFN0C0D_QX;

typedef struct str_AFN0C0D_QXINONEDAY_t
{
    int intday;
    short val_num;
    double val[96];
    short isnull[96];
    short data_point[96];
}str_AFN0C0D_QXINONEDAY;
typedef struct str_add12_t
{
    uchar ADDRESS[12]; /*��λ�����λ����λ�����λ
                         �磺��ʾ123 Address[0] = 3;
                                     Address[1] = 2;
                                     Address[2] = 1;
                        */
}str_add12;



uchar getbytebybit(uchar ac_byte, uchar ac_pos, uchar ac_len);
str_MD setMD(uchar lc_val);
short dataisnull(uchar *P, int ac_len);
short lowdataisnull(uchar *P, int ac_len);
uchar BCDByteToByte(uchar ac_BCD);
//uchar ByteToBCDByte(uchar ac_byte);
str_pn get_PN(uchar ac_DA1, uchar ac_DA2);
str_fn get_FN(uchar ac_DT1, uchar ac_DT2);
short dataisnull(uchar *P, int ac_len);

short getdataformat01(uchar *ac_ptr, datetime *at_val, int *ai_step);
short getdataformat02(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat03(uchar *ac_ptr, int *al_val, uchar *ac_unit, int *ai_step);
short getdataformat04(uchar *ac_ptr, int *ai_val, int *ai_step);
short getdataformat05(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat06(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat07(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat08(uchar *ac_ptr, int *ai_val, int *ai_step);
short getdataformat09(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat10(uchar *ac_ptr, int *ai_val, int *ai_step);
short getdataformat11(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat12(uchar *ac_ptr, str_add12 *astr_val, int *ai_step);
short getdataformat13(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat14(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat15(uchar *ac_ptr, datetime *at_val, int *ai_step);
short getdataformat16(uchar *ac_ptr, datetime *adt_in, datetime *adt_val, int *ai_step);
short getdataformat17(uchar *ac_ptr, datetime *adt_in, datetime *adt_val, int *ai_step);
short getdataformat18(uchar *ac_ptr, datetime *adt_in, datetime *adt_val, int *ai_step);
short getdataformat19(uchar *ac_ptr, datetime *adt_val, int *ai_step);
short getdataformat20(uchar *ac_ptr, datetime *adt_val, int *ai_step);
short getdataformat21(uchar *ac_ptr, datetime *adt_val, int *ai_step);
short getdataformat22(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat23(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat24(uchar *ac_ptr, datetime *adt_val, int *ai_step);
short getdataformat25(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat26(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformat27(uchar *ac_ptr, int *ai_val, int *ai_step);
short getlowdataformatSYDL(uchar *ac_ptr, double *adb_val, int *ai_step);
short getdataformatYMD(uchar *ac_ptr, datetime *adt_val, int *ai_step);
/**��ѹ���ݸ�ʽ���ο�DL/T-645 1997�����ݸ�ʽ**/

/*��ѹ���ݸ�ʽ01 ���ڵ�ѹ����ʾֵ����*/
short getlowdataformat01(uchar *ac_ptr, double *adb_val, int *ai_step);
/*��ѹ���ݸ�ʽ02 ���ڵ�ѹ��ѹ����*/
short getlowdataformat02(uchar *ac_ptr, double *adb_val, int *ai_step);
/*��ѹ���ݸ�ʽ03 ���ڵ�ѹ��������*/
short getlowdataformat03(uchar *ac_ptr, double *adb_val, int *ai_step);
/*��ѹ���ݸ�ʽ04 ���ڵ�ѹ��������*/
short getlowdataformat04(uchar *ac_ptr, double *adb_val, int *ai_step);
/*��ѹ���ݸ�ʽ05 ���ڵ�ѹ������������*/
short getlowdataformat05(uchar *ac_ptr, double *adb_val, int *ai_step);

uchar getqxinoneday(str_AFN0C0D_QX *astr_qx, str_AFN0C0D_QXINONEDAY *astr_QX_inday, uchar startindex);
uchar gettime0inqx(str_AFN0C0D_QX *astr_qx, uchar startindex);
void get0A_FNname(char *as_FNname, uchar ai_FN);
void get0E_ERCname(char *as_FNname, uchar ai_ERC);
void geterrorname (char *as_errname, int ai_errindex);
uchar time_after_check(datetime *time1, datetime *time2);
short get_erc_type(short ai_erc);
void get_data_ec1(str_encode_param *astr_frame, uchar *ac_ec1);
/*void check_date_event(int ai_ret, int ai_addr, int ai_afn, int ai_fn, int ai_pn);*/
int f_get_losttype(uchar ai_afn,int ai_fn);
//void f_lostcheck_process(uchar ai_afn,int ai_addr,int ai_fn,int ai_pn,int ai_day);
#endif