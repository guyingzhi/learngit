


/* Oracle数据库连接中断的检测条件 */
#define	NoConnectDB(a_sqlcode) (a_sqlcode>=-3115 && a_sqlcode<=-3113 || a_sqlcode==-12152 || a_sqlcode==-12571 || a_sqlcode==-3135)


#define	DB_NUM	32	/* 数据库数量 */
#define	DB_CJ	0	/* 采集数据库 */
#define	DB_YX	1	/* 营销数据库 */


int		gi_db_state[DB_NUM] ;	/* 数据库连接状态 0 未连接(或异常) 1 正常连接 */
char	gs_db[DB_NUM][8] ;		/* 数据库连接名 */


