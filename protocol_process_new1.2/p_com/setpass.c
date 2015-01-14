#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct db_info_t
{
	char	db_str[256];
	int		db_ind;
} db_info;

db_info	g_db[32];
char	gs_line[4096][512];
int		gi_line=-1,gi_db=0;
int		gi_flag=0;


int f_pwd_encrypt(char *as_str,char *as_retrun);

int isnum(char *as_str);
int f_set_pwd(int ai_n);
void f_save();


int main(int argc, char *argv[])
{
	char	ls_str[513];
	int		li_i,li_n;
	FILE	*fp;
	
	argc = argc;
    argv = argv;
	
	
	if ((fp = fopen("sys.ini", "r")) == NULL)
	{
		printf("打开文件 sys.ini 失败!");
		return -1;
	}
	
	while(!feof(fp))
	{
		if (fgets(ls_str, 512, fp))
		{
			gi_line++;
			strcpy(gs_line[gi_line],ls_str);
			
			if (strncmp(ls_str, "[DB_",4) == 0)
			{
				gi_db ++;
				strcpy(g_db[gi_db].db_str,ls_str);
				g_db[gi_db].db_ind = gi_line;
			}
		}
	}
	
	fclose(fp);
	
	
	do
	{
		printf("\n\n");
		for (li_i = 1;li_i <= gi_db;li_i++)
			printf("%d  修改 %s",li_i,g_db[li_i].db_str);

		printf("0  退出\n\n");
		printf("请选择: ");
	
		scanf("%s",&ls_str);
		
		if (!(isnum(ls_str)))
		{
			printf("\n输入错误，请重新输入正确数字");
			continue;
		}
		
		li_n = atoi(ls_str);

		if (li_n==0)
		{
			f_save();
			return 0;
		}
		else if (li_n>gi_db)
		{
			printf("\n输入错误，请重新输入");
			continue;
		}
		
		f_set_pwd(li_n);
	}
	while (1);

}


int f_set_pwd(int ai_n)
{
	int		li_i,li_n,li_k=0;
	char	ls_str[256],ls_pwd[512];

	li_n = g_db[ai_n].db_ind;
	
	do
	{
		
		li_i = 0;
		printf("\n\n");
	
		while (li_i<10 && strncmp(gs_line[li_n+li_i],"[END]",5)!=0)
		{
			printf("%s",gs_line[li_n+li_i]);
			if (strncmp(gs_line[li_n+li_i],"password=",9)==0)
				li_k = li_n+li_i;
			li_i++;
		}
		printf("%s",gs_line[li_n+li_i]);
	
		if (li_k==0)
		{
			printf("文件信息有错误，未包含密码项");
			return 0;
		}

		printf("\n1  修改密码");
		printf("\n0  返回");
		printf("\n\n请选择 : ");

		scanf("%s",&ls_str);
		if (!(isnum(ls_str)))
		{
			printf("\n输入错误，请重新输入正确数字");
			continue;
		}

		li_i = atoi(ls_str);
		if (li_i==0)
			return 0;
		else if (li_i!=1)
			continue;

		printf("\n\n    请输入新密码 : ");
		scanf("%s",&ls_str);
		
		printf(  "\n请再次输入新密码 : ");
		scanf("%s",&ls_pwd);
		
		if (strcmp(ls_str,ls_pwd)!=0)
		{
			printf("\n两次输入的密码不匹配!");
			return 0;
		}

		if (strlen(ls_str)<=0 || strlen(ls_str)>=200)
		{
			printf("\n密码长度错误");
			return 0;
		}

		if(f_pwd_encrypt(ls_str,ls_pwd)<=0)
		{
			printf("\n密码加密失败!");
			return 0;
		}
		
		if (gs_line[li_k][strlen(gs_line[li_k])-1]=='\r')
			sprintf(gs_line[li_k],"password=%s\r\n",ls_pwd);
		else
			sprintf(gs_line[li_k],"password=%s\n",ls_pwd);
		
		gi_flag = 1;

	}
	while (1);

	return 1;
}



void f_save()
{
	char	ls_str[32];
	int		li_i;
	FILE	*fp;

	if (gi_flag==0)
		return;

	printf("\n\n文件内容已改变，是否需要保存?\n");

	do
	{
		printf("\n 1  保存");
		printf("\n 0  不保存");
		printf("\n\n 请选择: ");

		scanf("%s",&ls_str);
		if (!(isnum(ls_str)))
		{
			printf("\n输入错误，请重新输入正确数字");
			continue;
		}
		
		li_i = atoi(ls_str);
		if (li_i==0)
			return;
		else if(li_i!=1)
			continue;

		if((fp = fopen("sys.ini","w")) == NULL)
		{
			printf("打开文件 sys.ini 失败,保存失败!");
			return;
		}

		for (li_i=0;li_i<=gi_line;li_i++)
			fputs(gs_line[li_i],fp);
		
		fclose(fp);
		
		return;
		
	}
	while(1);

}




int isnum(char *as_str)
{
	int		li_i;

	for (li_i=strlen(as_str)-1;li_i>=0;li_i--)
	{
		if (!(isdigit(as_str[li_i])))
			return 0;
	}

	return 1;

}
