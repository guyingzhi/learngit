#ifndef ERROR_CODE_H_INCLUDED
#define ERROR_CODE_H_INCLUDED


/*�����п�*/
#define DATA_ISNULL     -1

/*�����зǿ�*/
#define DATA_ISNOTNULL  0


/**��������**/
#define ERROR_SUCCESS   1
/*��֧�ָ�������*/
#define NOT_DEFINE_DATA   2
/*�������*/
#define DECODE_ERROR   7
/*�������*/
#define ENCODE_ERROR   8

/**��д���������**/

/*û���ҵ��ն��߼����*/
#define ERROR_NOT_FOUND_TERMBH   -1001

/*û���ҵ��ɼ����*/
#define ERROR_NOT_FOUND_CJDBH    -1002

/*û���ҵ����̺�*/
#define ERROR_NOT_FOUND_GCID     -1003

/*û���ҵ�������*/
#define ERROR_NOT_FOUND_DAID     -1004

/*д������ʧ��*/
#define ERROR_WRITE_DATA         -1005

/*û���ҵ��ܼ����*/
#define ERROR_NOT_FOUND_SUMBH    -1006

/*��ȡ����ʧ��*/
#define ERROR_READ_DATA          -1007

/*û���ҵ����ݼ�¼*/
#define ERROR_NOT_FOUND_RECORD   -1008

/*û���ҵ�ģ������*/
#define ERROR_NOT_FOUND_MNLBH    -1009

/*���ݿ����ӶϿ�*/
#define ERROR_DB_DISCONNECT    -1010

/*û���ҵ��õ�ַ�ն�*/
#define ERROR_NOT_FOUND_ADDR    -1011

/**�������Ĵ������**/

/*���ĳ��Ȳ���*/
#define ERROR_FRAME_LENGTH       -2001

/*����CRCУ�鲻��*/
#define ERROR_FRAME_CRC          -2002

/*�������ݳ��Ȳ���*/
#define ERROR_FRAME_DATA_LENGTH  -2003

/**�������ݴ���**/
/*����ʱ�䳬����Χ*/
#define ERROR_RANGE_DATETIME     -3001

/*���ݳ�����Χ*/
#define ERROR_RANGE_DATA         -3002

/*���ݵ���Ч���ֳ�����Χ*/
#define ERROR_RANGE_NUMBER       -3003

/*�����������������Ч*/
#define ERROR_DATA_INVALID       -3004

/*AFN������Χ*/
#define ERROR_RANGE_AFN           -3005

/*FN������Χ*/
#define ERROR_RANGE_FN           -3006

/*PN������Χ*/
#define ERROR_RANGE_PN           -3007

/*ERC������Χ*/
#define ERROR_RANGE_ERC           -3008

/*�¼���PN=0*/
#define ERROR_PNISZERO_ERC           -3009

/*ҵ���ʶ�����*/
#define ERROR_YWBZM            -3010

/*���ݿ�ֵ*/
/*ʱ��Ϊ��*/
#define ERROR_NULL_TD            -4001

/*����Ϊ��*/
#define ERROR_NULL_DATE          -4002

/*�ܶ�Ϊ��*/
#define ERROR_NULL_DENSITY       -4003

/*����Ϊ��*/
#define ERROR_NULL_POINT         -4004

/*����Ϊ��*/
#define ERROR_NULL_DATA          -4005

/*������Ϊ��*/
#define ERROR_NULL_FLS           -4006

/*г������Ϊ��*/
#define ERROR_NULL_XBCNT         -4007



#endif
