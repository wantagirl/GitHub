#ifndef _CBUF_H
#define _CBUF_H

#include "includes.h"

/**********************************/
#define ELEMENT int
#define NULL_ELEMENT -1
#define BUFSIZE 5

typedef struct
{
	int head;
	int tail;	//如果与head位置相同buff为空，如果下一位置是head则buff为满
	ELEMENT buff[BUFSIZE];
}cbuf_t;

typedef cbuf_t* CBUF;	//只能在尾部添加，头部删除

/**********************************/
//不考虑内存分配，cbuff_t声明自动完成

STATUS addElement(CBUF b, ELEMENT e);	//b不合法，缓冲区已满：失败返回FAILED；成功返回SUCCESS
STATUS addElementReplace(CBUF b, ELEMENT e); //覆盖性add，只有b不合法才失败
STATUS delElement(CBUF b);
STATUS emptyCBuf(CBUF b);
int countElements(CBUF b);	//失败返回-1，成功返回元素数
ELEMENT findHeadElement(CBUF b);	//失败返回-1，成功返回头元素
ELEMENT findTailElement(CBUF b);	//失败返回-1，成功返回尾元素

void showCBuf(CBUF b);
void testCBuf(CBUF b);

#endif