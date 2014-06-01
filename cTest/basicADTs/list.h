#ifndef _LIST_H
#define _LIST_H

#include "includes.h"
#include "defs.h"

/**************
NODE:通用节点
LIST:带头结点的双向链表，指针型
**************/
typedef struct node
{
	struct node *prev;
	struct node *next;
	void *content;
}NODE;

typedef NODE *LIST;	//LIST就是指向头结点的指针

/**************
链表操作函数
**************/
LIST makeList(int nodeCount);
STATUS delList(LIST l);
STATUS countList(LIST l, int *len);

NODE *insertNode(LIST l, int idx, void *cntnt);
STATUS releaseNode(void *content);
STATUS delNode(LIST l, int idx);

//for test
void showList(LIST l);
void testDelInsert(LIST l);

//Todo
//advance list, 对指针的类型做说明，地址为何跳跃32?
STATUS findNodeIndex(void);
STATUS findNodeAtIndex(void);
STATUS FindPrevNode(void);
STATUS FindPrevNode(void);

STATUS ListFindIndex(void);
STATUS ListFindFirst(void);
STATUS ListFindLast(void);
STATUS isListEmpty(void);
STATUS isNodeLast(void);
STATUS isNodeFirst(void);

#endif