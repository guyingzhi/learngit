


/* Oracle���ݿ������жϵļ������ */
#define	NoConnectDB(a_sqlcode) (a_sqlcode>=-3115 && a_sqlcode<=-3113 || a_sqlcode==-12152 || a_sqlcode==-12571 || a_sqlcode==-3135)


#define	DB_NUM	32	/* ���ݿ����� */
#define	DB_CJ	0	/* �ɼ����ݿ� */
#define	DB_YX	1	/* Ӫ�����ݿ� */


int		gi_db_state[DB_NUM] ;	/* ���ݿ�����״̬ 0 δ����(���쳣) 1 �������� */
char	gs_db[DB_NUM][8] ;		/* ���ݿ������� */


