#ifndef CK_SJCJ_H_INCLUDE
#define CK_SJCJ_H_INCLUDE
#include "../p_com/common.h"
#include "../p_com/dbcommon.h"
#include "../p_com/redis_common.h"
#include "gwgy/encode_main.h"
#include "gwgy/decode_main.h"
#include "gwgy/public/public.h"

#define		INT_LEN		sizeof(int)			/* int �����ݵĳ��� */


#define		MAX_MNGR_CONNECT		50			/* ���ĵ��ȳ���������Ŀ */
#define		MAX_QUEUE_PROCESS_GREEN		2		/* �����ɫ������Ŀ */
#define		MAX_QUEUE_PROCESS		2			/* �����ͨ������Ŀ */

st_conn		gst_mngr_conn[MAX_MNGR_CONNECT];	/* ���ȳ���������Ϣ���� */
int			gi_mngr_conn_max;					/* ���ȳ���������Ϣ���鵱ǰ��ʹ�õ�����±��� */
int			gi_mngr_conn_p;						/* ���ȳ���������Ϣ���鵱ǰʹ�õ��±��� */

//uchar gc_queueout_type;						/*��������*/
//uchar gs_queueout_buf[16*1024];				/*���ӻ���*/
//int gi_queueout_len;						/*���ӳ���*/

int		gi_mngr_socket_listen;		/* ���ȳ������socket�� */
pthread_mutex_t	g_mngr_mux_accept;	/* �����������ܵ�������ʱ���ݲ����� */


//#define		MAX_QUEUE_UNIT	1024*1024*1		/* ���е����Ԫ��Ŀ */
//#define		QUEUE_UNIT_LEN	256				/* ������ÿ����Ԫ�ĳ��� */
#define		MAX_LOG_TERM	100				/* ����¼��־�ն���*/

//char		gs_queue[MAX_QUEUE_UNIT][QUEUE_UNIT_LEN];	/* ���ݴ������ */
//int			gi_queue_max;								/* ������ʹ�õ�����±� */
//int 		gi_queue_p;									/* ���е�ǰʹ�õ��±� */
//uint		gi_queue_in_num,gi_queue_out_num;			/* ����������ܳ�����������ͳ���� */
//pthread_mutex_t	g_queue_in;								/* ���������������ʱ�� */
//pthread_mutex_t	g_queue_out;							/* �����������ݳ���ʱ�� */

int         gi_logterm_arr[MAX_LOG_TERM];            /*��¼��־���ն�����*/

short         gi_save_log;            /*��¼��־����*/
short         gi_save_data;            /*��¼���ݿ���*/

typedef struct
{
	str_redis_info lstr_redis;
	int num_queue_green;
	int num_queue;
}xycl_redis_info;

/*extern xycl_redis_info lxycl_redis;*/

/************** �������� ***************/

void f_exit();

void f_mngr_process(char *as_data,int ai_len);


//void f_process_000100(char *as_data,int ai_len);
//void f_process_000101(char *as_data,int ai_len);

//void f_process_000102(char *as_data,int ai_len);
//void f_get_log_info();
//void f_debug_process(char *as_cmd,char *as_data);



#endif

