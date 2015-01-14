/* 2009-12-29 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"



/* 写日志，参数用法同 printf */
void tracelog(char *fmt , ...)
{
	char	ls_buffer[2048];
	char	ls_file[256];
	char 	ls_datetime[16];
	FILE 	*fp ;
	va_list 	argp ;
	datetime	ldt_now;

	f_get_datetime(&ldt_now);

	sprintf(ls_datetime,"%02d%02d%02d %02d%02d%02d",(ldt_now.year + 1900) % 100,ldt_now.mon,ldt_now.day,ldt_now.hour,ldt_now.min,ldt_now.sec);
	
	sprintf(ls_file,"%s%04d-%02d_%s.log",gs_syslog,ldt_now.year + 1900,ldt_now.mon,gs_cxbh);


	va_start(argp,fmt);
	vsprintf(ls_buffer,fmt,argp);
	va_end(argp);

#if isUnix
	pthread_mutex_lock(&g_mux_tracelog);
#endif

	if((fp = fopen(ls_file,"a")) == NULL)
	{
		#if isUnix
			pthread_mutex_unlock(&g_mux_tracelog);
		#endif		

		return ;
	}

	fputs(ls_datetime,fp);
	fputs(" : ",fp );
	fputs(ls_buffer,fp);
	fputs("\n" ,fp);
	fclose(fp);
	
#if isUnix
	pthread_mutex_unlock(&g_mux_tracelog);
#endif
}


/* 得到 yyyy-mm-dd hh:mm:ss 格式的当前日期字符串 */
void f_get_datetime_str(char *as_datetime)
{
	datetime	ldt_now;

	f_get_datetime(&ldt_now);

	sprintf(as_datetime,"%04d-%02d-%02d %02d:%02d:%02d",ldt_now.year + 1900,ldt_now.mon,ldt_now.day,ldt_now.hour,ldt_now.min,ldt_now.sec);
}


/* 从输入的日期adt_in计算出 n 月后的日期adt_out,并返回整型的日期,ai_n可为负,参数只日期有效，时间部分无效 */
int after_month(datetime *adt_in , datetime *adt_out , int ai_n )
{
	int			li_year=0,li_month;
	datetime	ldt_tmp;

	ldt_tmp = *adt_in;

	li_month = adt_in->mon + ai_n - 1;

	if (li_month>=12)			/* 当年之后的日期 */
	{
		li_year = li_month / 12;
		li_month -= li_year * 12;
	}
	else if (li_month<0)		/* 当年之前的日期 */
	{
		li_year = li_month / 12 - 1;
		li_month += abs(li_year) * 12;
	}

	li_month++;
	ldt_tmp.year += li_year;
	ldt_tmp.mon   = li_month;

	if (li_month==2)
	{
		if (ldt_tmp.day>=29)
		{
			li_year = ldt_tmp.year + 1900;
			if ((li_year % 400) == 0 || (li_year % 4)==0 && (li_year % 100)!= 0 )	/*闰年*/
				ldt_tmp.day = 29;
			else
				ldt_tmp.day = 28;
		}

	}
	else if (li_month==4 || li_month==6 || li_month==9 || li_month==11)
	{
		if (ldt_tmp.day==31)
			ldt_tmp.day = 30;
	}

	*adt_out = ldt_tmp;

	return (ldt_tmp.year + 1900)*10000+ldt_tmp.mon*100+ldt_tmp.day;		/*返回整型的日期，用来方便计算*/
}


/* 从输入的日期adt_in计算出 n 天后的日期adt_out,并返回整型的日期,ai_n可为负,参数只日期有效，时间部分无效 */
int after_day(datetime *adt_in , datetime *adt_out , int ai_n )
{
	int		li_year,li_month,li_day,li_m;

	li_year = adt_in->year + 1900;
	li_month= adt_in->mon ;
	li_day	= adt_in->day + ai_n;

	if (ai_n>0)		/* 之后ai_n天 */
		do
		{
			switch(li_month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					li_m = 31;
					break;
				case 2:
					if ((li_year % 400) == 0 || (li_year % 4) == 0 && (li_year % 100)!= 0 )	/*闰年*/
						li_m = 29;
					else
						li_m = 28;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					li_m = 30;
					break;
			}

			if( li_day > li_m )
			{
				li_day -= li_m;
				if((li_month += 1) > 12)
				{
					li_month = 1;
					li_year += 1;
				}
			}
			else
				break ;

		} while (1);

	else		/* 之前ai_n天 */
		for( ; li_day <=0 ; )
		{
			if((li_month -= 1)<=0)
			{
				li_month += 12 ;
				li_year -= 1 ;
			}
			switch(li_month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					li_day += 31 ;
					break;
				case 2:
					if ((li_year % 400) == 0 || (li_year % 4) == 0 && (li_year % 100)!= 0 )	/*闰年*/
						li_day += 29 ;
					else
						li_day += 28 ;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					li_day += 30 ;
					break;
			}
		}

	li_year -= 1900;

	adt_out->year	= li_year;
	adt_out->mon	= li_month;
	adt_out->day	= li_day;
	adt_out->hour	= adt_in->hour;
	adt_out->min	= adt_in->min;
	adt_out->sec	= adt_in->sec;

	return (li_year+1900)*10000+li_month*100+li_day;		/*返回整型的日期，用来方便计算*/
}


/**** 计算两个日期间隔的天数,参数只日期有效，时间部分无效 ****/
int date_days(datetime adt_date1,datetime adt_date2)
{
	int		li_date1,li_date2,li_days=0;
	int		li_year1,li_year2,li_month1,li_month2,li_day1,li_day2;
	int		li_i,li_n;

	li_day1		= adt_date1.day;
	li_month1	= adt_date1.mon;
	li_year1 	= adt_date1.year + 1900;

	li_day2		= adt_date2.day;
	li_month2	= adt_date2.mon;
	li_year2	= adt_date2.year + 1900;

	li_date1	= li_year1 * 10000 + li_month1 * 100 + li_day1;
	li_date2	= li_year2 * 10000 + li_month2 * 100 + li_day2;

	for (li_i=1;li_i<li_month1;li_i++)
		switch(li_i)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					li_day1 += 31 ;
					break;
				case 2:
					if ((li_year1 % 400) == 0 || (li_year1 % 4) == 0 && (li_year1 % 100)!= 0 )	/*闰年*/
						li_day1 += 29 ;
					else
						li_day1 += 28 ;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					li_day1 += 30 ;
					break;
			}

	for (li_i=1;li_i<li_month2;li_i++)
		switch(li_i)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					li_day2 += 31 ;
					break;
				case 2:
					if ((li_year2 % 400) == 0 || (li_year2 % 4) == 0 && (li_year2 % 100)!= 0 )	/*闰年*/
						li_day2 += 29 ;
					else
						li_day2 += 28 ;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					li_day2 += 30 ;
					break;
			}

	if (li_year1==li_year2)
		return li_day2 - li_day1;

	li_i = (li_year1<li_year2?li_year1:li_year2)+1 ;
	li_n = (li_year1<li_year2?li_year2:li_year1) ;

	for (;li_i<li_n;li_i++)
		if ((li_i % 400) == 0 || (li_i % 4) == 0 && (li_i % 100)!= 0)	/*闰年*/
			li_days += 366 ;
		else
			li_days += 365 ;


	if (li_date1<li_date2)
	{
		li_days += (365 - li_day1) + li_day2;

		if ((li_year1 % 400) == 0 || (li_year1 % 4) == 0 && (li_year1 % 100)!=0)
			li_days ++;
	}
	else
	{
		li_days += (365 - li_day2) + li_day1;

		if ((li_year2 % 400) == 0 || (li_year2 % 4) == 0 && (li_year2 % 100)!=0)
			li_days ++;

		li_days = -li_days;
	}

	return li_days;
}


/* 从输入的日期adt_in计算出 n 秒后的日期adt_out,并返回整型的日期,al_n可为负 */
int after_time(datetime *adt_in , datetime *adt_out , long al_n )
{
	long		ll_seconds,ll_days;
	datetime	ldt_tmp;
	
	ldt_tmp = *adt_in;

	ll_seconds = adt_in->hour * 3600 + adt_in->min * 60 + adt_in->sec  +  al_n;

	if (ll_seconds>=86400)		/* 当天之后的日期 */
	{
		ll_days = ll_seconds / 86400;
		after_day(&ldt_tmp , &ldt_tmp , ll_days );
		ll_seconds -= ll_days * 86400;
	}
	else if (ll_seconds<0)		/* 当天之前的日期 */
	{
		ll_days = ll_seconds / 86400 - 1;
		after_day(&ldt_tmp , &ldt_tmp , ll_days );
		ll_seconds += abs(ll_days) * 86400;
	}

	ldt_tmp.hour= ll_seconds / 3600;
	ldt_tmp.min	= (ll_seconds % 3600) / 60;
	ldt_tmp.sec	= (ll_seconds % 3600) % 60;

	*adt_out = ldt_tmp;

	return (ldt_tmp.year+1900)*10000+ldt_tmp.mon*100+ldt_tmp.day;
}


/* 计算两个时间(hh24mmss)间隔的秒数，参数只时间有效，日期部分无效 */
int time_seconds(datetime adt_time1,datetime adt_time2)
{
	return (adt_time2.hour - adt_time1.hour) * 3600 + (adt_time2.min - adt_time1.min) * 60 + adt_time2.sec - adt_time1.sec;
}


/* 比较两个时间大小 */
int datetime_cmp(datetime adt_time1,datetime adt_time2)
{
	char	ls_date1[20],ls_date2[20];

	sprintf(ls_date1,"%04d%02d%02d %02d%02d%02d",adt_time1.year,adt_time1.mon,adt_time1.day,adt_time1.hour,adt_time1.min,adt_time1.sec);
	sprintf(ls_date2,"%04d%02d%02d %02d%02d%02d",adt_time2.year,adt_time2.mon,adt_time2.day,adt_time2.hour,adt_time2.min,adt_time2.sec);
	
	return strcmp(ls_date1,ls_date2);
}


/* 判断字符串是否全是由数字组成，返回 0 不是 1 是 */
int isnum(char *as_str)
{
	int		li_i;

	for (li_i=strlen(as_str)-1;li_i>=0;li_i--)
		if (!(isdigit(as_str[li_i])))
			return 0;

	return 1;
}

/*********** 判断字符串中的某个字符是否是中文 ********+****

	as_str	目标字符串
	ai_pos	要判断的字符位置,1开始计算
	
	返回：	-1	错误,(目标串是空串 or al_pos超过目标串长度范围)
			 0	是英文字符
			 1	是中文字符的第一个字节
			 2	是中文字符的第二个字节
*/
int ischinese(char *as_str,int ai_pos)
{
	register int	li_i;
	unsigned char	*p;
	
	li_i = strlen(as_str);
	
	if (li_i<=0 || ai_pos<=0 || ai_pos>li_i)
		return -1;
	
	ai_pos--;
	p = as_str;

	if (p[ai_pos]<=128)
		return 0;
	
	li_i = 0;
	while (li_i<=ai_pos)
	{
		if (p[li_i]>=129)
			li_i++;
		li_i++;
	}

	li_i -= ai_pos;
	
	if (li_i==1)
		return 2;
	else if (li_i==2)
		return 1;
	else
		return -1;
}



/* 返回 ad_x 保留ai_n位小数后的值，四舍五入法 */
double f_round(double adb_x,int ai_n)
{
	char	ls_fmt[8],ls_str[64],*p;

	if (ai_n<0)
		return 0;

	sprintf(ls_fmt,"%%.%dlf",ai_n);

	if (adb_x>=0)
		sprintf(ls_str,ls_fmt,adb_x+0.000000001);
	else
		sprintf(ls_str,ls_fmt,adb_x-0.000000001);

	return strtod(ls_str,&p);

}

/** 去除字符串中的空格 **/
char *strtrim(char *as_ss)
{
	char *p ,*q;
	for(p = as_ss + strlen(as_ss) ; (*p == ' ' || *p == '\0') && p >= as_ss ; p--);
	*(p+1) = 0;
	for(p = q = as_ss ; *p ==  ' ' ; p++);
	for( ; *p != '\0' ;*q++ = *p++);
	*q = 0;
	return as_ss ;
}

/** 把字符串中的小写字母转换成大写字母 **/
char *strupper(char *as_ss)
{
	char	*p;

	for (p = as_ss + strlen(as_ss) - 1; p>=as_ss; p--)
		if (*p>='a' && *p<='z')
			*p -= 32;

	return as_ss ;
}

/** 把字符串中的大写字母转换成小写字母 **/
char *strlower(char *as_ss)
{
	char	*p;

	for (p = as_ss + strlen(as_ss) - 1; p>=as_ss; p--)
		if (*p>='A' && *p<='Z')
			*p += 32;

	return as_ss ;
}


/**** 读取配置文件内容 ****/
int getiniinfo(char *filename,char *section,char *key,char *value)
{
	char tmp[20];
	char fileline[256];
	char *p;
	int i;
	FILE *fp;

	if((fp=fopen(filename,"r"))==NULL)
	{
		return -1;
	}

	while(fgets(fileline,256,fp))
	{
		p=strtrim(fileline);
		if(*(p+strlen(p)-2)!=10&&*(p+strlen(p)-2)!=13)// 10:\n, 13:\r
			*(p+strlen(p)-1)=0;
		else
			*(p+strlen(p)-2)=0;

		sprintf(tmp,"[%s]",section);
		if(strcmp(p,tmp)==0)
		{
			while(fgets(fileline,256,fp))
			{
				p=strtrim(fileline);

				if(*(p+strlen(p)-2)!=10&&*(p+strlen(p)-2)!=13)
					*(p+strlen(p)-1)=0;
				else
					*(p+strlen(p)-2)=0;

				if(strncmp(p,key,strlen(key))==0)
				{
					i=strcspn(p,"=");
					p+=++i;
					p=strtrim(p);
					strcpy(value,p);
				}
				else if(strncmp(fileline,"[END]",5)==0)
				{
					break;
				}

			}
			break;
		}
	}
	fclose(fp);

	return 1;
}


/**** 设置配置文件内容 ****/
int setiniinfo(char *filename,char *section,char *key,char *value)
{
	return 1;
}


/* 得到当前时间 */
void f_get_datetime(datetime *adt_datetime)
{
	static datetime	ldt_a={70,1,1,8,0,0};	/* 格林威治时间 1970-01-01 00:00:00，北京时间 1970-01-01 08:00:00 */

	/* time(NULL)，返回相对于格林威治时间 1970-01-01 00:00:00 到现在的秒数 */

	after_time(&ldt_a,adt_datetime,time(NULL));
}


/* 读入一个文件，存入as_data中，
	返回实际的数据长度，错误返回 -1
	使用数据后，需要用free释放as_data
*/
int f_file_read(char *as_file,char **as_data)
{
	int		li_len;
	char	*p;
	FILE 	*fp ;

	if((fp = fopen(as_file,"rb")) == NULL)
		return -1;

	fseek(fp,0,SEEK_END);   
  	li_len = ftell(fp);     	
  	rewind(fp);

	if (li_len<0 || li_len>1024*1024*8)		/* 当文件大于8M时，不执行 */
	{
		fclose(fp);
		return -1;
	}

	if ((p = (char *)malloc(li_len+128))==NULL)
	{
		fclose(fp);
		return -1;
	}

	li_len = fread(p, 1, li_len, fp);

	*as_data = p;

	fclose(fp);

	return li_len;
}


/* 把as_data内容写文件中，
	ai_data_len		as_data的长度，
	ai_replace		覆盖标志，1 覆盖原文件  0 在原文件上追加
	
	返回	-1 失败	 >0 写入数据后文件的总长度
*/
int f_file_write(char *as_file,char *as_data,int ai_data_len,int ai_replace)
{
	int		li_len;
	char	ls_tmp[8];
	FILE 	*fp ;
	
	if (ai_data_len<=0)
		return -1;

	if (ai_replace==0)
		strcpy(ls_tmp,"ab");
	else
		strcpy(ls_tmp,"wb");

	if((fp = fopen(as_file,ls_tmp)) == NULL)
	{
		fprintf(stderr,"打开文件 %s 失败\n",as_file);
		return -1;
	}

	li_len = fwrite(as_data, 1, ai_data_len, fp);

	if (li_len!=ai_data_len)
	{
		fclose(fp);
		return -1;
	}

	fseek(fp,0,SEEK_END);   
  	li_len = ftell(fp);     	
  	rewind(fp);

	fclose(fp);

	return li_len;
}

/* 删除文件 */
void filedelete(char *as_filename)
{
	char	ls_str[512];
	int		li_i;
	
	if (strlen(as_filename)>500)
		return;
	
	#if isUnix
		sprintf(ls_str,"rm %s",as_filename);
	#else
		sprintf(ls_str,"del %s",as_filename);
	#endif

	li_i = system(ls_str);

	return;

}


/* 分解字符串，字段分隔符为MSG_SEPARATOR */
int msg_get_array(char *as_ss,char *as_st[],int ai_max_field)
{
	char *p,*q;
	int  i=-1,field_len;

	if (as_ss==NULL || as_st==NULL)
		return -1;

	p = as_ss ;
	q = strstr(p,MSG_SEPARATOR) ;

	while(q!=NULL && i<ai_max_field)
	{
		as_st[++i] = (char *)malloc((field_len = q - p) + 1) ;
		memcpy(as_st[i],p,field_len);
		*(as_st[i]+field_len) = 0 ;

		p = q + MSG_SEPARATOR_LEN ;
		q = strstr(p,MSG_SEPARATOR) ;
	}
	
	as_st[++i] = (char *)malloc(2) ;
	as_st[i] = 0 ;

	return i;
}

/* 分解字符串，获取第 ai_n 个字段的内容 */
int msg_get_field(char *as_ss,int ai_n,char *as_st)
{
	char *p,*q;

	if (as_ss==NULL || as_st==NULL || ai_n<0)
		return -1;

	p = as_ss ;
	q = strstr(p,MSG_SEPARATOR);

	while(q!=NULL && ai_n--)
	{
		p = q + MSG_SEPARATOR_LEN ;
		q = strstr(p,MSG_SEPARATOR);
	}

	if (q==NULL)
		return -1 ;

	memcpy(as_st,p,q - p) ;
	as_st[q-p] = 0 ;
	return 1;

}

/* 释放由 msg_get_array 申请的内存*/
void msg_free_array(char *as_st[])
{
	int	i;

	for(i=0;as_st[i]!=NULL;i++)
		free(as_st[i]);
	
	free(as_st[i]);
}

/*********** 和校验函数 ***************/
uchar check_crc(uchar *as_data,int ai_len)
{
	uchar	lc_cs=0;

    for (ai_len=ai_len-1;ai_len>=0;ai_len--)
    	lc_cs += *(as_data+ai_len);

  	return lc_cs;
}

/* 获取唯一的报文任务编号 12位 */
void f_get_xh(char *as_rwbh)
{
	static uint	li_xh=0;

	sprintf(as_rwbh,"%-3s%c%c%02d%05d",gs_cxbh,gdt_now.day<10?gdt_now.day+48:gdt_now.day+55,gdt_now.hour<10?gdt_now.hour+48:gdt_now.hour+55,gdt_now.min,li_xh++ % 100000);
}


/*********** 解析报文的帧结构 *************

	astr_frame	帧结构体指针
	as_frame	帧数据

	返回：	 1	解析正常返回
			-1	不是合法的报文帧,无报文头
			-2	无报文结束符
			-3	报文校验未通过
			-4	终端地址无效
*******************************************/
int get_frame_struct(str_encode_param *astr_frame, uchar *as_frame, int in_len)
{
	int		li_i, li_n, li_m=0;
	uchar	*p,lc_c;

	p = as_frame;

	for (li_i = in_len; li_i >= 20; li_i--, p++){  //8+C+A+AFN+SEQ+DA+DT
		if (*p!=0x68 && *(p+5)!=0x68 && *(p+1)!=*(p+3) && *(p+2)!=*(p+4))
			continue;
		li_m = *(p+2);  //取数据长度
		li_m <<= 8;
		li_m |= *(p+1);
		li_m =  (li_m >> 2) & 0x3FFF;
		if ((li_m + 8) > li_i)  //剩余帧长度不够
			continue;
		if (*(p+li_m+7) != 0x16)  //无报文结束符
			continue;
		if (check_crc(p+6, li_m) != *(p+6+li_m))  //帧校验
			continue;

		astr_frame->frame_head = p;
		astr_frame->strl.len = li_m;
		astr_frame->strl.gy = *(p+1) & 0x03;  /*规约类型 1内蒙规约(2009)  2国网376.1  3内蒙规约(2012)*/
		memcpy(&astr_frame->c, p+6, 1);
		astr_frame->addr.a1_low = *(p+7);
		astr_frame->addr.a1_high = *(p+8);
		astr_frame->addr.a2_low = *(p+9);
		astr_frame->addr.a2_high = *(p+10);
		li_n = (astr_frame->addr.a2_high << 8) | astr_frame->addr.a2_low;
		if (li_n <= 0 || li_n > 65535)  /* 终端地址无效 */
			return -2;
		memcpy(&astr_frame->addr.a3, p+11, 1);
		astr_frame->afn = *(p+12);
		memcpy(&astr_frame->seq, p+13, 1);
		memcpy(astr_frame->dat, p+14, li_m-8);  //从DADT开始的数据内容,包含附加域
//		astr_frame->dat = p+14;
		return 1;		
	}

	return -1;
}


/* 写规约数据帧日志 as_text 为文字描述 astr_frame 为帧结构体 */
void datalog(char *as_text,str_encode_param *astr_frame)
{
	char	ls_file[256],ls_tmp[64];
	int		li_n,li_i, li_k;
	static uint	li_xh=0;
	uchar	*p;
	FILE 	*fp ;
	datetime	ldt_now;

	f_get_datetime(&ldt_now);
	
/*	sprintf(ls_file,"%s%04d%02d%02d_%s.log",gs_datalog,ldt_now.year + 1900,ldt_now.mon,ldt_now.day,gs_cxbh);
	sprintf(ls_tmp, "%02d%02d%02d",ldt_now.hour,ldt_now.min,ldt_now.sec);
*/
	li_k = BCDByteToByte(astr_frame->addr.a1_high)*10000000 + BCDByteToByte(astr_frame->addr.a1_low)*100000
		+ astr_frame->addr.a2_high*256 + astr_frame->addr.a2_low;
	sprintf(ls_file,"%s%09d.log",gs_datalog, li_k);
	sprintf(ls_tmp, "%02d%02d%02d %02d%02d%02d",(ldt_now.year + 1900) % 100,ldt_now.mon,ldt_now.day,ldt_now.hour,ldt_now.min,ldt_now.sec);

/*
#if isUnix
	pthread_mutex_lock(&g_mux_datalog);
#endif
*/
	if((fp = fopen(ls_file,"a")) == NULL)
		return ;

	p = astr_frame->frame_head;

	fprintf(fp,"%s-%s-%04d : %s\n-----------------------------------------------\n",ls_tmp,gs_cxbh,(li_xh++ % 10000),as_text);
	fprintf(fp,"  L = [%02X %02X] %d  gylx=%d\n",*(p+1),*(p+2),astr_frame->strl.len, astr_frame->strl.gy);
	fprintf(fp,"  C = [%02X] DIR=%d PRM=%d %s=%d FCV=%d FUNCCODE=%d\n",*(p+6),astr_frame->c.dir,astr_frame->c.prm,(astr_frame->c.dir)?"ACD":"FCB",astr_frame->c.fcb_acd,astr_frame->c.fcv_keep,astr_frame->c.fun);
	fprintf(fp," A1 = [%02X %02X]    A2 = [%02X %02X]  %d\n",astr_frame->addr.a1_low,astr_frame->addr.a1_high,astr_frame->addr.a2_low,astr_frame->addr.a2_high, li_k);
	memcpy(&li_k, &astr_frame->addr.a3, 1);
	li_k &= 0xFF;
	fprintf(fp," A3 = [%02X] AddressFlag=%s  MSA = %d\n",li_k,astr_frame->addr.a3.gpaddr_v?"组":"单",astr_frame->addr.a3.msa);
	fprintf(fp,"DAT = AFN=[%02X]\n",*(p+12));
	fprintf(fp,"      SEQ=[%02X]  DA1=%d  DA2=%d  DT1=%d  DT2=%d\n",*(p+13),*(p+14),*(p+15),*(p+16),*(p+17));
	fprintf(fp,"      TPV=%d  FIR=%d  FIN=%d  CON=%d  (P/R)SEQ=%d\n\n",astr_frame->seq.tpv,astr_frame->seq.fir,astr_frame->seq.fin,astr_frame->seq.con,astr_frame->seq.seq);

/*	fputs("-----------------------------------------------\n" ,fp);
*/
	li_n = (astr_frame->strl.len+8) / 32 - 1;
	for (li_i=0;li_i<=li_n;li_i++)
	{
		fprintf(fp,"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X-", *p,*(p+1),*(p+2),*(p+3),*(p+4),*(p+5),*(p+6),*(p+7),*(p+8),*(p+9),*(p+10),*(p+11),*(p+12),*(p+13),*(p+14),*(p+15));
		p += 16;
		fprintf(fp,"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",*p,*(p+1),*(p+2),*(p+3),*(p+4),*(p+5),*(p+6),*(p+7),*(p+8),*(p+9),*(p+10),*(p+11),*(p+12),*(p+13),*(p+14),*(p+15));
		p += 16;
	}
	
	li_n = (astr_frame->strl.len+8) % 32;
	for (li_i=0;li_i<li_n;li_i++)
		sprintf(ls_tmp+li_i*3,"%02X ",*(p+li_i));

	ls_tmp[li_n*3] 	= '\0';
	ls_tmp[16*3 - 1]= '-';
	fprintf(fp,"%s\n\n\n",ls_tmp);

	fclose(fp);
/*
#if isUnix
	pthread_mutex_unlock(&g_mux_datalog);
#endif
*/
}

void *f_thread_system_timer(void *pvParam)
{
	do
	{
		sleep(1);

		gi_seconds++;

		if ((gi_seconds % 3)==0)
			f_get_datetime(&gdt_now);

		if ((gi_seconds % 60)==0)
			gi_minutes++;

	}while(1);

}

int f_system_init()
{
	int		li_i;


	f_get_datetime(&gdt_now);

	gdt_start_datetime = gdt_now;
	
	gi_seconds = gi_minutes = 0;

	if (getiniinfo(INIFILE,"local_info","path_syslog",gs_syslog)<0)
		return -1;

	if (getiniinfo(INIFILE,"local_info","path_datalog",gs_datalog)<0)
		return -2;
	
	if (getiniinfo(INIFILE,"local_info","path_filecache",gs_filecache)<0)
		return -3;


#if isUnix

	pthread_mutex_init(&g_mux_tracelog,NULL);
	pthread_mutex_init(&g_mux_datalog,NULL);


	pthread_t	hThread;
	pthread_attr_t 	lattr;
	size_t 			lsize;


	/* 创建系统定时器线程 */

	lsize = 1024 * 16;
	pthread_attr_init(&lattr);  
	pthread_attr_setstacksize(&lattr,lsize); 	/* 设定栈大小为16K */

	li_i = pthread_create(&hThread ,&lattr ,f_thread_system_timer ,NULL);
	if(li_i != 0)
	{
		tracelog("创建系统定时器线程f_thread_system_timer失败,返回 %d",li_i);
		exit(0);
	}

	pthread_detach(hThread);
	pthread_attr_destroy(&lattr);

#endif

	return 1;
}


void f_system_end()
{

#if isUnix
	pthread_mutex_destroy(&g_mux_tracelog);
	pthread_mutex_destroy(&g_mux_datalog);
#endif

}


#if 0
/* 按内部规约处理接收到的数据 
	
	参数说明：	as_data		要处理的数据缓冲区
				*ai_max		数据缓冲区中数据的长度
				(*af_func)	处理正确报文的函数指针,
							此函数有两个参数：
							as_data	报文数据地址,含16字节的报文头(#^&!...)
							ai_len	报文数据内容长度,不含16字节的报文头，即as_data+16之后的数据内容长度

		返回：	解析出的正确的报文数量

	1、按数据传输格式解析出实际内容
	2、调用相应的函数处理解析出的报文内容
*/
int f_process_recv_data(char *as_buff,int *ai_max,void (*af_func)(char *as_data,int ai_len))
{
	int		li_i,li_n,li_len,li_max,li_bw=0;
	uchar	*p,*q;
	char	ls_tmp[32] = {0};

	li_max = *ai_max;

	if ((li_n=li_max - 21) < 0)  //长度不够
		return 0;

	q = as_buff;
	li_i = -1;

	while((++li_i) < li_n)
	{
		p = q + li_i;

		if (!(*p=='#' && *(p+1)=='^' && *(p+2)=='&' && *(p+3)=='!'))		/* 未找到报文头 */
			continue;
			
			printf("find frame head!\n");

		
		if (!(*(p+12)=='#' && *(p+13)=='^' && *(p+14)=='&' && *(p+15)=='!'))	/* 未找到报文头 */
			continue;

			printf("find frame head tail!\n");


		memcpy(ls_tmp, p+4, 8);
		ls_tmp[8] = 0;
		li_len = atoi(ls_tmp);				/* 取数据报文长度 */

		if ((li_max - li_i) < (li_len+21))		/* 报文未接收完整 */
			break;

		if (!(*(p+li_len+17)=='*' && *(p+li_len+18)=='^' && *(p+li_len+19)=='!' && *(p+li_len+20)=='#'))	/* 无报文结束符 */
			continue;

			printf("find frame tail!!\n");


		/* 校验未通过，抛弃此报文 */
		if (check_crc(p+16,li_len) != *(p+16+li_len))		
			continue;

			printf("cs is right!!\n");
	

		li_i += li_len + 21 - 1;						/* 指到下一个数据祯 */
		/* 下面是正确的报文处理 */
		li_bw++;		
		af_func(p, li_len);		/* li_len为数据内容的长度，数据内容从p+16开始 */
	}

	if (li_i>0)
	{
		li_max -= li_i;
		memmove(q, q+li_i, li_max);
		*ai_max = li_max;
	}

	return li_bw;
}
#endif

/* 按内部规约处理接收到的数据 
	
	参数说明：	as_data		要处理的数据缓冲区
				*ai_max		数据缓冲区中数据的长度
				(*af_func)	处理正确报文的函数指针,
							此函数有两个参数：
							as_data	报文数据地址,含16字节的报文头(#^&!...)
							ai_len	报文数据内容长度,不含16字节的报文头，即as_data+16之后的数据内容长度

		返回：	解析出的正确的报文数量

	1、按数据传输格式解析出实际内容
	2、调用相应的函数处理解析出的报文内容
*/
int f_process_recv_data(char *as_buff,int *ai_max,void (*af_func)(char *as_data,int ai_len))
{
	int		li_i,li_len,li_max,li_bw=0;
	uchar	*p,*q;
	char	ls_tmp[32] = {0};

	li_max = *ai_max;

	if ((li_max - 21) < 0)  /* 长度不够 */
		return 0;

	q = as_buff;
	li_i = -1;

	while((++li_i) < li_max)
	{
		p = q + li_i;

		if ((li_max - li_i) < 4)  /*数据长度不够 */
			break;
		if (!(*p=='#' && *(p+1)=='^' && *(p+2)=='&' && *(p+3)=='!'))		/* 未找到报文头 */
			continue;
			
		DEBUG("find frame head!\n");

		if ((li_max - li_i) < 16)  /* 数据长度不够 */
			break;
		if (!(*(p+12)=='#' && *(p+13)=='^' && *(p+14)=='&' && *(p+15)=='!'))	/* 未找到报文头 */
			continue;

		DEBUG("find frame head tail!\n");

		memcpy(ls_tmp, p+4, 8);
		ls_tmp[8] = 0;
		li_len = atoi(ls_tmp);				/* 取数据报文长度 */

		if ((li_max - li_i) < (li_len + 21))		/* 报文未接收完整 */
			break;

		if (!(*(p+li_len+17)=='*' && *(p+li_len+18)=='^' && *(p+li_len+19)=='!' && *(p+li_len+20)=='#'))	/* 无报文结束符 */
			continue;

		DEBUG("find frame tail!!\n");

		/* 校验未通过，抛弃此报文 */
		if (check_crc(p+16,li_len) != *(p+16+li_len))		
			continue;

		DEBUG("cs is right!!\n");

		li_i += li_len + 21 - 1;						/* 指到下一个数据祯 */
		/* 下面是正确的报文处理 */
		li_bw++;		
		af_func(p, li_len);		/* li_len为数据内容的长度，数据内容从p+16开始 */
	}

	if (li_i>0)
	{
		li_max -= li_i;
		memmove(q, q+li_i, li_max);
		*ai_max = li_max;
	}

	return li_bw;
}



/*十六进制字符转整数*/
short hex_to_int(char ac_val)
{
    switch (ac_val)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
             return ac_val - 48;
        }
        case 'a':
        case 'A':
        {
            return 10;
        }
        case 'b':
        case 'B':
        {
            return 11;
        }
        case 'c':
        case 'C':
        {
            return 12;
        }
        case 'd':
        case 'D':
        {
            return 13;
        }
        case 'e':
        case 'E':
        {
            return 14;
        }
        case 'f':
        case 'F':
        {
            return 15;
        }
    }
}

/************* 将数值转换为BCD码 ***************
    ac_BCD BCD码
    返回：BCD码代表的数值
*******************************************/
uchar ByteToBCDByte(uchar ac_byte)
{
    uchar lc_val;
    lc_val = ac_byte / 100 * 256 + (ac_byte %100) / 10 * 16 + ac_byte % 10;
    return lc_val;
}

/*系统异常回调函数*/
void sys_dump(int signo)
{
	char buf[1024];
	char cmd[1024];
	FILE *fh;

	snprintf(buf, sizeof(buf), "/proc/%d/cmdline", getpid());
	if(!(fh = fopen(buf, "r")))
	exit(0);
	if(!fgets(buf, sizeof(buf), fh))
	exit(0);
	fclose(fh);
	if(buf[strlen(buf)-1]=='n')
	{
	buf[strlen(buf)-1]=' ';
	}
	printf("%s\n",buf);
	snprintf(cmd,sizeof(cmd),"gdb %s %d ",buf,getpid());
	system(cmd);
}
/********信号初始化函数*********/
void f_signal_init()
{
	signal(SIGSEGV, &sys_dump);//Memory leaks
//	signal(SIGINT, &sys_dump);
//	signal(SIGQUIT, &sys_dump);
	signal(SIGILL, &sys_dump);
	signal(SIGTRAP, &sys_dump);
	signal(SIGABRT, &sys_dump);
	signal(SIGBUS, &sys_dump);
	signal(SIGFPE, &sys_dump);
//	signal(SIGKILL, &sys_dump);
	
	signal(SIGTERM, &sys_dump);
//	signal(SIGCHLD, &sys_dump);
//	signal(SIGCONT, &sys_dump);
//	signal(SIGSTOP, &sys_dump);
//	signal(SIGTSTP, &sys_dump);
	signal(SIGTTIN, &sys_dump);
	signal(SIGTTOU, &sys_dump);
	signal(SIGURG, &sys_dump);

	signal(SIGXCPU, &sys_dump);
	signal(SIGXFSZ, &sys_dump);
	signal(SIGPWR, &sys_dump);
	signal(SIGSYS, &sys_dump);
	
	signal(SIGPIPE, SIG_IGN);
}

/** @函数名 : char set_pthread_stack(int size,pthread_attr_t *thread_attr)
*
*  @函数功能: 设置线程栈空间大小函数
*
*  @param: 无
*		    
*  @return :无
*/
char set_pthread_stack(int size,pthread_attr_t *thread_attr)
  {
      /* 初始化线程属性并设置线程栈空间 */
	  char status = 0;
	  status = pthread_attr_init(thread_attr);
	  if ( 0 != status)
	  {
	  		printf("pthread_attr_init %d\n",status);	
			return 1;
	  }
	  else
	  {
		  status = pthread_attr_setstacksize(thread_attr, size);
		  if ( 0 != status)
		  {
			  printf("pthread_attr_setstacksize %d\n",status);
			  return 2;
		  }
	  
	  }
	  return 0;
  }

