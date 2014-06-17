#ifndef _SORT_H
#define _SORT_H

#include "includes.h"

/*
交换类排序：
	1.冒泡
	2.快速（QSort），需要递归
插入式排序：
	1.直接插入（改进：折半插入）
	2.希尔排序
*/

//整数排序
void bubleSort(int a[], int n);	//交换类
void shellSort(int a[], int n);	//插入式排序
void testSort(void);	//test

//不同类型排序
#define ELEM int

COMPARE compareElem(ELEM e1, ELEM e2);
void bubleSortElem(ELEM a[], int n);
void testSortElem(void);

#endif