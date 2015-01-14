#include "public.h"


/* */ 
static char find_pos(char ch)   
{ 
    char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="; 
    char *ptr = (char*)strrchr(base, ch);//the last position (the only) in base[] 
    return (ptr - base); 
} 
/* */ 
int base64_decode(const char *src, int i_len,int *o_len,char *des)
{
	int ret_len = (i_len / 4) * 3;

    int equal_count = 0;
    //char *ret = NULL;
    //char *f = NULL;
    int tmp = 0;
    int temp = 0;
    char need[3];
    int prepare = 0;
    int i = 0;
	if ((src == NULL) || (des == NULL) || (o_len == NULL))
    {
        printf("No enough memory.\n");
        return 0;
    }

    if (*(src + i_len - 1) == '=')
    {
        equal_count += 1;
    }
    if (*(src + i_len - 2) == '=')
    {
        equal_count += 1;
    }
    if (*(src + i_len - 3) == '=')
    {
        equal_count += 1;
    }
	*o_len = ret_len - equal_count;
//    switch (equal_count)
//    {
//    case 0:
//        ret_len += 4;//3 + 1 [1 for NULL]
//        break;
//    case 1:
//        ret_len += 4;//Ceil((6*3)/8)+1
//        break;
//    case 2:
//       ret_len += 3;//Ceil((6*2)/8)+1
//        break;
//    case 3:
//        ret_len += 2;//Ceil((6*1)/8)+1
//        break;
//    }
	//ret = des;

    //memset(ret, 0, ret_len);

    //f = ret;
    while (tmp < (i_len - equal_count))
    {
        temp = 0;
        prepare = 0;
        memset(need, 0, 4);
        while (temp < 4)
        {
            if (tmp >= (i_len - equal_count))
            {
                break;
            }
            prepare = (prepare << 6) | (find_pos(src[tmp]));
            temp++;
            tmp++;
        }
        prepare = prepare << ((4-temp) * 6);
        for (i=0; i<3 ;i++ )
        {
            if (i == temp)
            {
                break;
            }
            *des = (char)((prepare>>((2-i)*8)) & 0xFF);
            des++;
        }
    }
    *des = '\0';

    return 1;
}

//base64加密算法
int base64_encode(char *src,int i_len,int *o_len,char *des)
{
	int prepare = 0;
    int ret_len;
    int temp = 0;
    //char *ret = NULL;
    //char *f = NULL;
    char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="; 
    int tmp = 0;
    char changed[4];
    int i = 0;

	if ((src == NULL) || (des == NULL) || (o_len == NULL))
    {
        printf("No enough memory.\n");
        return 0;
    }
    ret_len = i_len / 3;
    temp = i_len % 3;
    if (temp > 0)
    {
        ret_len += 1;
    }
    ret_len = ret_len*4 + 1;
	//ret = des;

    //memset(ret, 0, ret_len);
	*o_len = ret_len -1;

    //f = ret;
    while (tmp < i_len)
    {
        temp = 0;
        prepare = 0;
        memset(changed, '\0', 4);
        while (temp < 3)
        {
            if (tmp >= i_len)
            {
                break;
            }
            prepare = ((prepare << 8) | (src[tmp] & 0xFF));
            tmp++;
            temp++;
        }
        prepare = (prepare<<((3-temp)*8));
        for (i = 0; i < 4 ;i++ )
        {
            if (temp < i)
            {
                changed[i] = 0x40;
            }
            else
            {
                changed[i] = (prepare>>((3-i)*6)) & 0x3F;
            }
            *des= base[changed[i]];
            des++;
        }
    }
    *des = '\0';
    return 1;
}

/************* 将BCD码转换为数值 ***************
    ac_BCD BCD码
    返回：BCD码代表的数值
*******************************************/
uchar BCDByteToByte(uchar ac_BCD)
{
    uchar lc_val;
    lc_val = ac_BCD & 0xF0;
    lc_val >>=4;
    lc_val = (lc_val * 10) + (ac_BCD & 0x0F);
    return lc_val;
}

void f_get_week(datetime *adt_datetime, uchar *ac_week)
{
    int y, m, d, w;

    y = adt_datetime->year + 1900;
    m = adt_datetime->mon;
    d = adt_datetime->day;
    if (m <= 2)
    {
        y--;
        m += 12;
    }
    /*基姆拉尔森计算公式*/
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
    *ac_week = w;
}

int AddTP(uchar *astr_out, uchar pfc, int *ai_size)
{
    datetime dt;
    *astr_out = pfc;
    f_get_datetime(&dt);
    *(astr_out + 1) = ByteToBCDByte(dt.sec);
    *(astr_out + 2) = ByteToBCDByte(dt.min);
    *(astr_out + 3) = ByteToBCDByte(dt.hour);
    *(astr_out + 4) = ByteToBCDByte(dt.day);
    *(astr_out + 5) = 0;
    *ai_size = 6;
    return ERROR_SUCCESS;
}

int termal_info_key(uint termal_addr, char *key, int max_keylen)
{	
	char lc_i[256] = {0};
	
	sprintf(lc_i, "00_%012d_collect", termal_addr);
	if (max_keylen <= strlen(lc_i))
		return -1;
	strcpy(key, lc_i);
	
	return 1;
}




