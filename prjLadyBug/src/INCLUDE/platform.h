#ifndef _PLATFORM_H
#define _PLATFORM_H

/**********************
Platform dependent: PC
**********************/

//Standard I/O
#include <stdio.h>	

//Memory access
#include <stdlib.h>

//File I/O

//Time related
#include <time.h>
/*****************************
clock_t clock(void)	启动到现在的毫秒数
time_t time(time_t*)	epoch起到现在的秒数，参数为NULL得到当前机器时间，否则用该参数更新系统时间
	-->tm* localtime(time_t*)
		-->char* asctime(tm*)
	-->tm* gmtime(time_t*)
	-->char* ctime(time_t*)
double difftime(time_t t2, time_t t1)
*****************************/

//Math funcs
#include <math.h>
/*****************************
double ceil/floor(double)	舍入/舍出
double modf(double v, double* p)	拆分v，返回v小数部分，p指向整数部分
double fmod(double, double)	两书相除余数

int abs(int)	求绝对值
double fabs(double)
double cabs(complex)

double sin/cos/tan/asin/acos/atan/sinh/cosh/tanh(double)	三角函数
double log/log10(double)	求对数
double pow(double x, double y)/float powf(float x, float y)	x的y次幂
double exp(double)
double sqrt(double)
*****************************/
#include <stdlib.h>	//含有int rand()

#endif