#ifndef ERROR_CODE_H_INCLUDED
#define ERROR_CODE_H_INCLUDED


/*数据判空*/
#define DATA_ISNULL     -1

/*数据判非空*/
#define DATA_ISNOTNULL  0


/**正常返回**/
#define ERROR_SUCCESS   1
/*不支持该数据项*/
#define NOT_DEFINE_DATA   2
/*解码错误*/
#define DECODE_ERROR   7
/*组码错误*/
#define ENCODE_ERROR   8

/**读写库表错误代码**/

/*没有找到终端逻辑编号*/
#define ERROR_NOT_FOUND_TERMBH   -1001

/*没有找到采集点号*/
#define ERROR_NOT_FOUND_CJDBH    -1002

/*没有找到过程号*/
#define ERROR_NOT_FOUND_GCID     -1003

/*没有找到档案号*/
#define ERROR_NOT_FOUND_DAID     -1004

/*写入数据失败*/
#define ERROR_WRITE_DATA         -1005

/*没有找到总加组号*/
#define ERROR_NOT_FOUND_SUMBH    -1006

/*读取数据失败*/
#define ERROR_READ_DATA          -1007

/*没有找到数据记录*/
#define ERROR_NOT_FOUND_RECORD   -1008

/*没有找到模拟量号*/
#define ERROR_NOT_FOUND_MNLBH    -1009

/*数据库连接断开*/
#define ERROR_DB_DISCONNECT    -1010

/*没有找到该地址终端*/
#define ERROR_NOT_FOUND_ADDR    -1011

/**解析报文错误代码**/

/*报文长度不对*/
#define ERROR_FRAME_LENGTH       -2001

/*报文CRC校验不对*/
#define ERROR_FRAME_CRC          -2002

/*报文数据长度不对*/
#define ERROR_FRAME_DATA_LENGTH  -2003

/**报文数据错误**/
/*日期时间超出范围*/
#define ERROR_RANGE_DATETIME     -3001

/*数据超出范围*/
#define ERROR_RANGE_DATA         -3002

/*数据的有效数字超出范围*/
#define ERROR_RANGE_NUMBER       -3003

/*报文数据体的数据无效*/
#define ERROR_DATA_INVALID       -3004

/*AFN超出范围*/
#define ERROR_RANGE_AFN           -3005

/*FN超出范围*/
#define ERROR_RANGE_FN           -3006

/*PN超出范围*/
#define ERROR_RANGE_PN           -3007

/*ERC超出范围*/
#define ERROR_RANGE_ERC           -3008

/*事件的PN=0*/
#define ERROR_PNISZERO_ERC           -3009

/*业务标识码错误*/
#define ERROR_YWBZM            -3010

/*数据空值*/
/*时标为空*/
#define ERROR_NULL_TD            -4001

/*日期为空*/
#define ERROR_NULL_DATE          -4002

/*密度为空*/
#define ERROR_NULL_DENSITY       -4003

/*点数为空*/
#define ERROR_NULL_POINT         -4004

/*数据为空*/
#define ERROR_NULL_DATA          -4005

/*费率数为空*/
#define ERROR_NULL_FLS           -4006

/*谐波次数为空*/
#define ERROR_NULL_XBCNT         -4007



#endif
