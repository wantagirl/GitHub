#include <stdio.h>

void str2int(char* s, int* i)
{
	//生成字符串的哈希值
}

int strCompare(char* s1, char* s2) //s1大返回正值，s2大返回负值，相同看长短，都相同返回0
{
	int i,j;
	int max_l;
	//得到每个字符串的长度
	for(i=0;s1[i]!='\0';i++){}
	for(j=0;s2[j]!='\0';j++){}
	//用比较短的字符串长度比较
	if(i<j)
	{
		max_l = i;
	}
	else
	{
		max_l = j;
	}
	for(i=0;i<max_l;i++)
	{
		if(s1[i]>s2[i])
		{
			return 1;	//s1当前字母字母序大，s1大
		}
		else if(s1[i]<s2[i])
		{
			return -1;	//s2当前字母字母序大，s2大
		}
		else
		{
			//继续比较下一个字符
		}
	}

	#if 1
	//长的大
	if('\0'==s1[max_l])
	{
		return -1;	//s1已到头，长的s2大
	}
	else if('\0'==s2[max_l])
	{
		return 1;	//s2已到头，长的s1大
	}
	#endif
	#if 0
	//短的大
	if('\0'==s1[max_l-1])
	{
		return 1;	//s1已到头，s1大
	}
	elif('\0'==s2[max_l-1])
	{
		return -1;	//s2已到头，s2大
	}
	#endif
	return 0;
}

int main()
{
	int i;
	i = strCompare("ba","a");
	printf("%d\n", i);
	printf("FIN.");
}