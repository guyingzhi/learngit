#include "encode_AFN0A_FN1_150.h"

int  encode_frameAAF10(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0, li_i=0;
    uchar *p=buf;

    li_i = (*(p + 1) << 8) | *p;  /*本次查询数量*/
    len_out = (li_i << 1) + 2;   /*左移一位等同与乘以2*/
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH;
    memcpy(data, p, len_out);
    return len_out;
}

int  encode_frameAAF11(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *p + 1;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}

int  encode_frameAAF13(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *p + 1;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
int  encode_frameAAF14(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *p + 1;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
int  encode_frameAAF15(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *p + 1;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
int  encode_frameAAF33(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *p + 1;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
int  encode_frameAAF34(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *p + 1;
    if (len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
int  encode_frameAAF38(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *(p+1) + 2;
    if ( len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
int  encode_frameAAF39(uchar *buf, uint len_in ,uchar *data)
{
    int len_out=0;
    uchar *p=buf;

    len_out = *(p+1) + 2;
    if ( len_in < len_out)
        return ERROR_FRAME_DATA_LENGTH  ;
    memcpy(data, p, len_out);
    return len_out;
}
