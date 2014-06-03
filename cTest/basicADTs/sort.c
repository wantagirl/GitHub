#include "sort.h"

//交换类
void bubleSort(int a[], int n)	//从小到大
{
	int i,j,k;
	for(j=0;j<n;j++)   /* 气泡法要排序n次*/
	{
		for(i=0;i<n-j;i++)  /* 值比较大的元素沉下去后，只把剩下的元素中的最大值再沉下去就可以了 */
		{
			if(a[i]>a[i+1])  /* 把值比较大的元素沉到底 */
			{
				k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;
			}
		}
	}
}

//插入式排序
void shellSort(int a[], int n)	//从小到大
{
	int gap, key, i, j;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; ++i)
		{
			key = a[i];
			j = 0;
			for( j = i - gap; j >= 0 && a[j] > key; j -= gap)
			{
				a[j+gap] = a[j];
			}  
			a[j+gap] = key;
		}
	}
}

#if 0
//test code
#include <stdio.h>

int main()
{
	int a[]={5,4,7,33,24,8,3,9};
	int i;
	//排序
	shellSort(a,8);
	//输出结果
	for(i=0;i<8;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("FIN.");
}
#endif