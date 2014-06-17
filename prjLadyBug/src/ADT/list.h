#ifndef _LIST_H
#define _LIST_H

#include "includes.h"

/**********************************/
typedef struct t_node		
{
	struct t_node *prev;
	struct t_node *next;
	TYPES type;	//负载内容类型
	void *load;	//负载内容
}node_t;

typedef node_t* NODE;		//NODE:通用节点，头尾节点前后指针各有一个为NULL
typedef node_t* LIST;	//LIST:双向链表，带头尾节点，内容为指向头结点的指针

/**********************************/
LIST makeList(void);	//返回值为指向头结点的指针，NULL为执行失败
int countNodes(LIST l);	//失败返回-1，成功返回node数（不包括头尾节点）
BOOL isEmptyList(LIST l);	//失败返回NULL_BOOL，成功返回占用内存大小
int sizeofNode(NODE n);	//失败返回-1，成功返回节点大小（包括Load）
int sizeofList(LIST l);	//失败返回-1，成功返回链表大小
NODE addNode(LIST l, int idx, TYPES tp, void *ld);	//失败返回NULL，成功返回指向插入节点的指针
//safeAddNode
//NODE insertNode(LIST l, TYPES tp, void *ld);
//NODE appendNode(LIST l, TYPES tp, void *ld);

//COMPARE compareNode();STATUS isSameNodeLoad(NODE *n1, NODE *n2, BOOL *retval);	//待修改
STATUS reverseList(LIST l);
//sortList:基于compareNode实现

STATUS releaseNode(NODE n);	//释放节点负载，失败返回FAILED，成功返回SUCCESS
STATUS delNodeByIdx(LIST l, int idx);	//按节点索引删除节点，失败返回FAILED，成功返回SUCCESS
STATUS delNodeByAddr(LIST l, NODE n);	//按节点地址删除节点，失败返回FAILED，成功返回SUCCESS
//STATUS delNodeByLoad(LIST l, NODE n)//基于负载比对
STATUS releaseList(LIST l);	//释放负载，失败返回FAILED，成功返回SUCCESS
STATUS delList(LIST l);		//释放负载，删除链表，失败返回FAILED，成功返回SUCCESS

void showList(LIST l);
void testList(LIST l);



#if 0
//find
findFirstNode(LIST l);
findLastNode(LIST l);
findAddrbyIdx
findIdxbyAddr
findAddrbyNode
findNodebyAddr
findIdxByNode
findNodeByIdx
findbyAddr/isInList
//get=find+del
#endif

#endif