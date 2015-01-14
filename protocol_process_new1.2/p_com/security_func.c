/* 2006-09-15 */

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


#ifdef _WIN32
	#define	isUnix	0
#else
	#define	isUnix	1
#endif


int f_str_encrypt(char *as_str,char *as_retrun);
int f_str_decode(char *as_str,char *as_retrun);
int f_str_cracked(char *as_str,char *as_newpass);
int f_pwd_encrypt(char *as_str,char *as_retrun);
int f_pwd_decode(char *as_str,char *as_retrun);
int f_get_hostname(char *as_str);



int f_str_decode(char *as_str, char *as_return)
{
	char	ls_tmp;
	int		li_i, li_n, li_len;
	int		li_asc[512],li_tmp[4] ,li_k = 0;


	as_return[0] = 0;
	
	li_len = strlen(as_str);
	
	if (li_len <= 0 || li_len%4 != 0)
		return -1;


	for (li_i = li_len; li_i >= 1 ; li_i-- )
	{
		ls_tmp = as_str[li_i - 1];
		if (ls_tmp == '#')
		{
			li_asc[li_i] = 63;
		}
		else if (ls_tmp <= '9')
		{
			li_asc[li_i] = ls_tmp - 48;
		}
		else if (ls_tmp <= 'Z')
		{
			li_asc[li_i] = ls_tmp - 54;
		}
		else if (ls_tmp <= 'z')
		{
			li_asc[li_i] = ls_tmp - 60;
		}
	}
	
	li_len = li_len - 4;
	
	for (li_i = 0; li_i <= li_len; li_i=li_i + 4)
	{	
		li_n = li_asc[li_i + 4];
		li_tmp[3] = (li_n%4) * 64 + li_asc[li_i + 3];
		li_n = li_n / 4;
		li_tmp[2] = (li_n%4) * 64 + li_asc[li_i + 2];
		li_n = li_n / 4;
		li_tmp[1] = (li_n%4) * 64 + li_asc[li_i + 1];

		for (li_n = 1; li_n <= 3; li_n++)
		{
			as_return[li_k] = li_tmp[li_n];
			li_k++;
		}
	}

	as_return[li_k] = '\0';

	return li_k;

}




int f_str_encrypt(char *as_str,char *as_return)
{
	int		li_i,li_n,li_len,li_k = 0;
	int		li_asc[512],li_code[5];
	unsigned char	ch;

	as_return[0] = 0;
	
	li_len = strlen(as_str);
	
	if (li_len <= 0)
		return 0;
	else if (li_len >= 300)
		return -1;

	for (li_i = li_len; li_i >= 1; li_i--)
	{	
		ch =as_str[li_i - 1];
		li_asc[li_i] = ch;
	}

	li_i = li_len%3;
	if (li_i == 1)
	{
		li_asc[li_len+1] = 0;
		li_asc[li_len+2] = 0;
		li_len += 2;
	}
	else if (li_i == 2)
	{
		li_asc[li_len+1] = 0;
		li_len ++;
	}

	li_len -= 3;

	for (li_i = 0; li_i <= li_len; li_i=li_i + 3)
	{
		li_code[1] = li_asc[li_i+1]%64;
		li_code[2] = li_asc[li_i+2]%64;
		li_code[3] = li_asc[li_i+3]%64;
		li_code[4] = (int)(li_asc[li_i+1]/64) * 16 + (int)(li_asc[li_i+2]/64) * 4 + (int)(li_asc[li_i+3]/64);
		
		for (li_n = 1; li_n <= 4; li_n++)
		{
			if (li_code[li_n] <=9)
			{
				as_return[li_k] = li_code[li_n] + 48;
			}
			else if (li_code[li_n] <= 36)
			{
				as_return[li_k] = li_code[li_n] + 54;
			}
			else if (li_code[li_n] <= 62)
			{
				as_return[li_k] = li_code[li_n] + 60;
			}
			else if (li_code[li_n] == 63)
			{
				as_return[li_k] = '#';
			}
			li_k++;
		}
	}
	as_return[li_k] = '\0';

	return li_k;

}



int f_str_cracked(char *as_str,char *as_newpass)
{
	int	buf_len,mm,m,zh_con;
	int	li_i,li_j,li_n=-1;
	int	li_new_c,ls_li_new_c,li_old_c,li_new_s[512];
	int	li_bin,li_sum_bin,li_div,li_mod; 
	char ls_byte[512];


	buf_len = strlen(as_str);
	if(buf_len<=0)
		return 0;
	else if(buf_len>=512) 
		return -1;

	strcpy(ls_byte,as_str);
	as_newpass[0]=0;

	for( li_i=1;li_i <= buf_len;li_i++)
	{
		li_old_c = (int)ls_byte[li_i-1];
		if(li_old_c < 0)
		{
			zh_con=128;
			li_old_c = (int)(ls_byte[li_i-1]) & zh_con;
		}	
		if (li_old_c == 128)
		{
			li_i = li_i + 2;
			li_old_c = (int)ls_byte[li_i-1];
			li_mod   = li_old_c;
			if (li_mod==33 )
				li_mod = (int)ls_byte[li_i];
			li_sum_bin = 0;
			for(li_j=1; li_j<=8;li_j++)
			{
				li_sum_bin += li_mod % 2;
				li_mod /= 2;
			}
			li_div = (int)ls_byte[li_i-2] - li_sum_bin*10 - 40;
		}
		else
			li_div = 0;

		if(li_old_c==33)
		{
			li_i = li_i + 1;
			li_old_c = (int)ls_byte[li_i-1] - 34;
		}
		li_old_c += li_div*126;
	
		li_new_c = 0;
		for (li_j=1 ;li_j<= 8;li_j++)
		{
			li_bin = li_old_c%2;
			li_old_c /= 2;
			mm=1;
			for(m=1;m<=(8-li_j);m++)
				mm*=2;
			li_new_c += mm * li_bin;
		}
		li_n++;
		li_new_s[li_n] = li_new_c;
	
	}

	for(li_i=li_n; li_i>=0; li_i--)
	{
		li_new_c = li_new_s[li_i];
		ls_li_new_c = li_new_c;
		if (li_new_c > 126)
		{
			li_div = li_new_c/126;
			li_mod = li_new_c%126;
			li_new_c = li_mod;
			if (li_mod<34 )
				li_mod += 34;
			li_sum_bin = 0;
			for( li_j=1; li_j<=8;li_j++)
			{
				li_sum_bin += li_mod%2;
				li_mod /= 2;
			}
			sprintf(as_newpass,"%s%c%c",as_newpass,128,li_sum_bin*10+40+li_div);
			}
		if (li_new_c<34 )
		{
			sprintf(as_newpass,"%s%c",as_newpass,33);
			li_new_c += 34;
		}
		sprintf(as_newpass,"%s%c",as_newpass,li_new_c);
	}

	return strlen(as_newpass);

}



int f_pwd_encrypt(char *as_str,char *as_return)
{
	int		li_len;
	char	ls_str1[512],ls_str2[512];
	
	li_len = strlen(as_str);
	
	if (li_len<=0 || li_len>300)
		return 0;

	strcpy(ls_str2,as_str);

	if (f_str_cracked(ls_str2,ls_str1)<=0)
		return -1;

	if (f_str_encrypt(ls_str1,ls_str2)<=0)
		return -1;

	strcpy(as_return,ls_str2);
	
	return 1;
}


int f_pwd_decode(char *as_str,char *as_return)
{
	int		li_len;
	char	ls_str1[512],ls_str2[512];

	li_len = strlen(as_str);
	
	if (li_len<=0 || li_len>500)
		return 0;
	
	if (f_str_decode(as_str,ls_str1)<=0)
		return -1;

	if (f_str_cracked(ls_str1,ls_str2)<=0)
		return -1;
	
	strcpy(as_return,ls_str2);
	
	return 1;
}


int f_get_hostname(char *as_str)
{
	char	ls_str[256],ls_filename[64],ls_cmd[64];
	int		li_i;
	static int	li_xh=0;
	FILE	*fp;

	as_str[0] = 0;

	
	sprintf(ls_filename,"temp_%04d_%04d",li_xh++ % 10000,rand() % 10000);
	sprintf(ls_cmd,"hostname > %s",ls_filename);

	li_i = system(ls_cmd);

	#if isUnix
		sprintf(ls_cmd,"rm %s",ls_filename);
	#else
		sprintf(ls_cmd,"del %s",ls_filename);
	#endif

	for(li_i=1024*1024*100;li_i>=0;li_i--);		/* ÑÓÊ± */

	if ((fp = fopen(ls_filename, "r")) == NULL)
	{
		system(ls_cmd);
		return 0;
	}
	
	if (!(fgets(ls_str, 256, fp)))
	{
		fclose(fp);
		system(ls_cmd);
		return 0;
	}
	fclose(fp);

	li_i = strlen(ls_str);
	
	if (ls_str[li_i-1]=='\r' || ls_str[li_i-1]=='\n')
		ls_str[li_i-1]='\0';
	
	if (ls_str[li_i-2]=='\r' || ls_str[li_i-2]=='\n')
		ls_str[li_i-2]='\0';

	strcpy(as_str,ls_str);

	system(ls_cmd);

	return 1;

}
