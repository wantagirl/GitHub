#ifndef _LIST_H
#define _LIST_H

#include "includes.h"
#include "defs.h"


typedef struct node 	//NODE:通用节点，头尾节点前后指针各有一个为NULL
{
	struct node *prev;
	struct node *next;
	TYPES type;
	void *load;
}NODE;

typedef NODE *LIST;	//LIST:链表，双向，有头尾节点，内容为指向头结点的指针

//Basic list opts
LIST makeList(void);	//分配内存的函数返回值为指针，NULL为执行失败
STATUS delList(LIST l);
STATUS unloadList(LIST l);
STATUS reverseList(LIST l);
/*sort:待实现，参考sort->strSort*/
STATUS countList(LIST l, int *cnt);	//求值函数通过指针传回返回值
STATUS sizeofList(LIST l, int *sz);
STATUS isListEmpty(LIST l, BOOL *retval);

//Basic node-list opts
NODE *insertNode(LIST l, int idx, TYPES tp, void *ld);
STATUS isSameNodeLoad(NODE *n1, NODE *n2, BOOL *retval);	//待修改
STATUS sizeofNodeLoad(NODE *n, int *sz);	//待修改
STATUS releaseNodeLoad(void *ld);	//待修改
STATUS delNode(LIST l, int idx);
STATUS delNodeByAddr(LIST l, NODE *n);

//find, get opts
NODE *findFirstNode(LIST l);
NODE *findLastNode(LIST l);


//for test
void showList(LIST l);
void testList(LIST l);

#endif