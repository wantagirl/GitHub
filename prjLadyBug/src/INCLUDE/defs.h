#ifndef _DEFS_H
#define _DEFS_H

/**********************
Platform independent
**********************/

/**********************************
编程规范：
0. 命名使用camelCase

1. 预定义类型：推荐使用基本/通用预定义类型(全大写)定义变量和函数返回值
2. 自定义类型：
	加前缀：t_,_t,全大写
3. 自定义变量：
	加前缀：c,s,i,uc,us,ui,e(枚举),t(结构体),p(指针)
4. 函数名字：
	动词+名字+修饰/规则：del

5. 函数返回值：
	不需要检测状态，不需要返回值的函数	：避免写
	不需要检测状态，需要返回值的函数：返回值(除非函数难以失败，否则避免写)
	需要检测状态，不需要返回值的函数：返回状态为STATUS类型
	需要检测状态，需要返回值的函数：返回值，用特殊值表示状态

6. 函数参数：
	//顺序

**********************************/

/***************预定义类型：基本***************/
typedef char 			INT8;
typedef short			INT16;
typedef int 			INT32;

typedef unsigned char 	UINT8;
typedef unsigned short	UINT16;
typedef unsigned int 	UINT32;

typedef char 			CHAR;
typedef unsigned char 	UCHAR;
typedef short			SHORT;
typedef unsigned short 	USHORT;
typedef int 			INT;
typedef unsigned int 	UINT;

typedef unsigned char 	BYTE;


/***************预定义类型：通用****************/
typedef enum
{
	START_BOOL,	//invalid first
	NULL_BOOL,
	FALSE,
	TRUE,
	END_BOOL	//invalid last
}BOOL;

typedef enum
{
	START_COMPARE,
	NULL_COMPARE,
	EQUAL,
	BIG_1ST,
	BIG_2ND,
	BIG_3RD,
	END_COMPARE
}COMPARE;

typedef enum
{
	START_STATUS,	//invalid first
	NULL_STATUS,
	FAILED,
	SUCCESS,
	END_STATUS	//invalid last
}STATUS;

typedef enum
{
	START_TYPE,	//invalid first
	NULL_T,
	LISTHEAD,
	LISTTAIL,
	END_TYPE	//invalid last
}TYPES;


#endif