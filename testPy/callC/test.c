#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int proc_num(int a,int b)
{
    return a+b;
}

//modify buf method 1
char *proc_str1(char *str)
{
	char *p = (char *)malloc(3);
	p[0]=str[0];
	return p;
}
//modify buf method 2
int proc_str2(char *str)
{
	//printf("asdf\n");
    str[0] += 1;
    return 0;
}
