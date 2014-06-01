#include <stdio.h>

int strCompare(char* s1, char* s2) //s1大返回1，s2大返回2，相同看长短，都相同返回0
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
			return 2;	//s2当前字母字母序大，s2大
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
		return 2;	//s1已到头，长的s2大
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
		return 2;	//s2已到头，s2大
	}
	#endif
	return 0;
}

int strCompareIgnoreCase(char* s1, char* s2) //s1大返回1，s2大返回2，相同看长短，都相同返回0
{
	int i,j;
	int max_l;
	char s1i,s2i;
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
		//都化为大写字母比较
		s1i=s1[i];
		s2i=s2[i];
		if(s1i>='a' && s1i<='z')
		{
			s1i -= 32;	//大写字母和小写的ASCII码差值
		}
		if(s2i>='a' && s2i<='z')
		{
			s2i -= 32;
		}

		if(s1i>s2i)
		{
			return 1;	//s1当前字母字母序大，s1大
		}
		else if(s1i<s2i)
		{
			return 2;	//s2当前字母字母序大，s2大
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
		return 2;	//s1已到头，长的s2大
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
		return 2;	//s2已到头，s2大
	}
	#endif
	return 0;
}

void strShellSort(char* a[], int n)	//从小到大
{
	int gap, i, j;
	char* key;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; ++i)
		{
			key = a[i];
			j = 0;
			for( j = i - gap; j >= 0 && 1 == strCompareIgnoreCase(a[j], key); j -= gap)
			{
				a[j+gap] = a[j];
			}  
			a[j+gap] = key;
		}
	}
	return;
}

int main()
{
	int i,n;
	char b = 'a';
	char z = 'z';

	char* a[] = {"CHINA","japan","USA","Germany","RuSsiA","China2"};

	n = 6;
	for (i=0;i<n;i++)
	{
		printf("%s ", a[i]);
	}
	printf("\n");

	strShellSort(a,n);
	for (i=0;i<n;i++)
	{
		printf("%s ", a[i]);
	}
	printf("\n");

}