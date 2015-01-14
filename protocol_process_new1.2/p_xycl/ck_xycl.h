#ifndef CK_SJCJ_H_INCLUDE
#define CK_SJCJ_H_INCLUDE
#include "../p_com/common.h"
#include "../p_com/dbcommon.h"
#include "../p_com/redis_common.h"
#include "gwgy/encode_main.h"
#include "gwgy/decode_main.h"
#include "gwgy/public/public.h"

#define		INT_LEN		sizeof(int)			/* int 型数据的长度 */


#define		MAX_MNGR_CONNECT		50			/* 最大的调度程序连接数目 */
#define		MAX_QUEUE_PROCESS_GREEN		2		/* 最大绿色队列数目 */
#define		MAX_QUEUE_PROCESS		2			/* 最大普通队列数目 */

st_conn		gst_mngr_conn[MAX_MNGR_CONNECT];	/* 调度程序连接信息数组 */
int			gi_mngr_conn_max;					/* 调度程序连接信息数组当前已使用的最大下标数 */
int			gi_mngr_conn_p;						/* 调度程序连接信息数组当前使用的下标数 */

//uchar gc_queueout_type;						/*出队类型*/
//uchar gs_queueout_buf[16*1024];				/*出队缓冲*/
//int gi_queueout_len;						/*出队长度*/

int		gi_mngr_socket_listen;		/* 调度程序监听socket号 */
pthread_mutex_t	g_mngr_mux_accept;	/* 互斥锁，接受调度连接时传递参数用 */


//#define		MAX_QUEUE_UNIT	1024*1024*1		/* 队列的最大单元数目 */
//#define		QUEUE_UNIT_LEN	256				/* 队列中每个单元的长度 */
#define		MAX_LOG_TERM	100				/* 最大记录日志终端数*/

//char		gs_queue[MAX_QUEUE_UNIT][QUEUE_UNIT_LEN];	/* 数据处理队列 */
//int			gi_queue_max;								/* 队列已使用的最大下标 */
//int 		gi_queue_p;									/* 队列当前使用的下标 */
//uint		gi_queue_in_num,gi_queue_out_num;			/* 总入队数和总出队数，调试统计用 */
//pthread_mutex_t	g_queue_in;								/* 互斥锁，数据入队时用 */
//pthread_mutex_t	g_queue_out;							/* 互斥锁，数据出队时用 */

int         gi_logterm_arr[MAX_LOG_TERM];            /*记录日志的终端数组*/

short         gi_save_log;            /*记录日志开关*/
short         gi_save_data;            /*记录数据开关*/

typedef struct
{
	str_redis_info lstr_redis;
	int num_queue_green;
	int num_queue;
}xycl_redis_info;

/*extern xycl_redis_info lxycl_redis;*/

/************** 函数定义 ***************/

void f_exit();

void f_mngr_process(char *as_data,int ai_len);


//void f_process_000100(char *as_data,int ai_len);
//void f_process_000101(char *as_data,int ai_len);

//void f_process_000102(char *as_data,int ai_len);
//void f_get_log_info();
//void f_debug_process(char *as_cmd,char *as_data);



#endif

