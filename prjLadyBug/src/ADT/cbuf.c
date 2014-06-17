#include "cbuf.h"

int wrap(int idx, int maxIdx)
{
	return (idx+1)%maxIdx;
}

STATUS addElement(CBUF b, ELEMENT e)
{
	if(NULL == b)	//不合法参数
	{
		return FAILED;
	}
	//如果缓冲区已满
	if(b->head == wrap(b->tail,BUFSIZE))
	{
		return FAILED;
	}
	else	//添加
	{
		b->buff[b->tail] = e;
		b->tail = wrap(b->tail,BUFSIZE);
	}
	return SUCCESS;
}

STATUS addElementReplace(CBUF b, ELEMENT e)
{
	if(NULL == b)	//不合法参数
	{
		return FAILED;
	}
	//如果缓冲区已满
	if(b->head == wrap(b->tail,BUFSIZE))
	{
		b->head = wrap(b->head,BUFSIZE);//弹出头部
		b->buff[b->tail] = e;
		b->tail = wrap(b->tail,BUFSIZE);
	}
	else	//添加
	{
		b->buff[b->tail] = e;
		b->tail = wrap(b->tail,BUFSIZE);
	}
	return SUCCESS;
}

STATUS delElement(CBUF b)
{
	if(NULL == b)	//不合法参数b
	{
		return FAILED;
	}
	//如果缓冲区为空
	if(b->head == b->tail)
	{
		return FAILED;
	}
	else	//删除
	{
		b->buff[b->head] = 0;//被删除槽可以不清0
		b->head = wrap(b->head,BUFSIZE);
	}
	return SUCCESS;
}

STATUS emptyCBuf(CBUF b)
{
	int i = 0;
	if(NULL == b)	//不合法参数
	{
		return FAILED;
	}
	//可以不清空
	for(i=0;i<BUFSIZE;i++)
	{
		b->buff[i] = 0;
	}
	//
	b->head = 0;
	b->tail = b->head;
	return SUCCESS;
}

int countElements(CBUF b)
{
	if(NULL == b)	//不合法参数
	{
		return -1;
	}
	if(b->tail == b->head)
	{
		return 0;
	}
	else if(b->tail > b->head)
	{
		return b->tail - b->head;
	}
	else if(b->tail < b->head)
	{
		return BUFSIZE + b->tail - b->head;
	}
}

ELEMENT findHeadElement(CBUF b)
{
	if(NULL == b || countElements(b) < 1)	//不合法参数或缓冲区为空
	{
		return NULL_ELEMENT;
	}
	return b->buff[b->head];
}

ELEMENT findTailElement(CBUF b)
{
	if(NULL == b || countElements(b) < 1)	//不合法参数或缓冲区为空
	{
		return NULL_ELEMENT;
	}
	return b->buff[b->tail];
}

//
void showCBuf(CBUF b)
{
	int i = 0;
	if(NULL == b)	//不合法参数
	{
		return;
	}
	printf("head:%d,tail:%d,count:%d\n",b->head,b->tail,countElements(b));
	for(i = 0; i < BUFSIZE; i++)
	{
		printf("element %d:%d\n",i,b->buff[i]);
	}
}

void testCBuf(CBUF b)
{
	BOOL bl = START_BOOL;	//invalid value
	char c = 0;
	int i = 0;

	showCBuf(b);
	c = getch();
	while(c != 'q')
	{
		switch(c)
		{
			case 's':
				showCBuf(b);
				break;
			case 'a':
				addElement(b,rand());
				showCBuf(b);
				break;
			case 'r':
				addElementReplace(b,rand());
				showCBuf(b);
				break;
			case 'd':
				delElement(b);
				showCBuf(b);
				break;
			case 'e':
				emptyCBuf(b);
				showCBuf(b);
				break;
			case 'f':
				printf("Element:%d\n",findHeadElement(b));
				break;
			default:
				printf("unknown cmd\n");
		}
		c = getch();
	}
}