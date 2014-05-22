#include <stdio.h>

int main()
{
	int a[5];
	int i,j,k;
	//input
	scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	//find max
	j=a[0];
	k=0;
	for(i=1;i<5;i++)
	{
		if(j<a[i])
		{
			j=a[i];
			k=i;
		}
	}
	//printf("max:%d %d", j,k);
	//exchange
	i=a[4];
	a[4]=j;
	a[k]=i;
	//find min
	j=a[0];
	k=0;
	for(i=1;i<5;i++)
	{
		if(j>a[i])
		{
			j=a[i];
			k=i;
		}
	}
	//printf("min:%d %d", j,k);
	//exchange
	i=a[0];
	a[0]=j;
	a[k]=i;
	//output
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
}