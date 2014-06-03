#ifndef _SORT_H
#define _SORT_H

/*
交换类排序：
	1.冒泡
	2.快速（QSort），需要递归
插入式排序：
	1.直接插入（改进：折半插入）
	2.希尔排序
*/

//交换类
void bubleSort(int a[], int n);

//插入式排序
void shellSort(int a[], int n);

#endif