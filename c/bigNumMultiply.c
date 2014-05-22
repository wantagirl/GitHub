#include <stdio.h>

void computing(int* array1,int* array2,int* array3,int array1_length,int array2_length,int array3_length)
{
    int i,j,k;
    for (i = array1_length - 1; i >= 0; i--)
    {
        k = array3_length - array1_length + i ;
        for (j = array2_length - 1; j >= 0; j--)
        {
            array3[k] = array3[k] + array1[j] * array2[i];
            if (array3[k] >= 10)   //进位
            {
                array3[k-1] = array3[k-1] + array3[k] / 10;
                array3[k] = array3[k] % 10;
            }
            k--;
        }
    }
}

int main(void)
{
    int array_1[31];//1234567891011121314151617181920
    int array_2[31];//2019181716151413121110987654321
    int array_3[100];

    int i,j;

    //初始化array_3
    for (i=0;i<100;i++)
    {
        array_3[i]=0;
    }
    //初始化array_1和array_2，声明时没有初始化，之后只能用循环
    for (i=1,j=-1;i<21;i++)
    {
        if (i<10)
        {
            j++;
            array_1[j]=i;
            array_2[30-j]=i;
        }
        else
        {
            j=j+2;
            array_1[j]=i%10;
            array_1[j-1]=i/10;
            array_2[30-j]=i/10;
            array_2[30-j+1]=i%10;
        }
    }

    //输出：array_1[]和array_2[]
    printf("array_1:");
    for (i=0;i<31;i++)
    {
        printf("%d",array_1[i]);
    }
    printf("\n");

    printf("array_2:");
    for (i=0;i<31;i++)
    {
        printf("%d",array_2[i]);
    }
    printf("\n");

    //计算
    computing(array_1,array_2,array_3,31,31,100);

    //输出array_3
    printf("%s","array_3:");
    for (i=0;i<100;i++)
    {
        if (array_3[i]>0)
        {
            int j=i;    //找到第一位不为0的数字
            for (j=i;j<100;j++) //从该数字开始打印
            {
                printf("%d",array_3[j]);
            }
            break; //不再找不为0的数字
        }
    }
    printf("\n");
    printf("FIN.");
}

