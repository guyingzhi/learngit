#include<stdio.h>
#include <stdlib.h>
int main (int argc,char *agrv[])
{
	char buf[120]= {0};
	int  buff;
	int  *p;
	p =a;
	printf("hello world!!");
	sscanf("123456 ", "%*4d%d", buf); 
	
	printf("%d\n",buf);
	buff = atoi(buf);
	printf("%d\n",buff);
	return 0;
}
