#include "list.h"

/**************
规则:无内存分配操作的函数返回STATUS，返回值用指针参数带回
**************/

/**************
Func:
D.S. dep.: STATUS
Func dep.: free
**************/
STATUS releaseNode(void *content)
{
	free(content);
	return SUCCESS;
}

/**************
Func:
D.S. dep.: STATUS, NODE, LIST
Func dep.: free, releaseNode
**************/
STATUS delList(LIST l)
{
	NODE *n = NULL;

	if(NULL == l)
	{
		return SUCCESS;
	}

	n = l;
	while(NULL != n->next)
	{
		n = n->next;
		//printf("free:%d\n",n->prev);
		releaseNode(n->prev->content);	//释放载荷
		n->prev->content = NULL;
		free(n->prev);	//释放节点
		n->prev = NULL;
	}
	//printf("free:%d\n",n);
	releaseNode(n->content);	//释放载荷
	n->content = NULL;
	free(n);	//释放节点
	n = NULL;
	return SUCCESS;
}

/**************
Func:
D.S. dep.: STATUS, NODE, LIST
Func dep.: malloc, delList
**************/

LIST makeList(int nodeCount)	//分配内存的函数返回值为指针，NULL为执行失败
{
	LIST l = NULL;
	NODE *currentNode = NULL;
	NODE *newNode = NULL;
	int i = 0;
	
	//建立头结点
	l = (NODE *)malloc(sizeof(NODE));
	if(NULL == l)
	{
		return NULL;
	}
	l->prev = NULL;
	l->next = NULL;
	l->content = NULL;
	//printf("headAddr:%d\tprev:%d\n",l,l->prev);
	currentNode = l;
	
	//加入节点们
	for(i = 0;i<nodeCount;i++)
	{
		newNode = (NODE *)malloc(sizeof(NODE));
		if(NULL == newNode)	//这里可以通过i<max来限制链表最大节点数max
		{	
			delList(l);//删除之前创立的节点和头结点们
			return NULL;
		}
		newNode->prev = currentNode;
		newNode->next = NULL;
		newNode->content = NULL;
		//printf("nodeAddr:%d\tprev:%d\n",newNode,newNode->prev);
		currentNode->next = newNode;
		currentNode = newNode;
	}

	return l;
}

/**************
Func:
D.S. dep.: STATUS, NODE, LIST
Func dep.: 
**************/
STATUS countList(LIST l, int *len)
{
	int count = 0;
	NODE *n = NULL;

	if(NULL == l)
	{
		return FAILED;
	}
	n = l;

	while(NULL != n->next)
	{
		count++;
		n = n->next;
	}
	*len = count;
	return SUCCESS;
}

/**************
Func:
D.S. dep.: STATUS, NODE, LIST
Func dep.: countList, free, releaseNode
**************/
STATUS delNode(LIST l, int idx)
{
	int len = 0;
	int i = 0;
	NODE *n = NULL;

	if(NULL == l || idx < 1)	//不合法的索引值
	{
		return FAILED;
	}
	countList(l, &len);
	if(idx > len)
	{
		return FAILED;	//超出LIST长度，不合法
	}

	n = l;	//idx <= len
	for(i=0;i<idx;i++)
	{
		n=n->next;
	}
	//n此时指向要删除的节点
	if(NULL == n->next)	//该节点是尾节点
	{
		n->prev->next = NULL;//前一节点变成最后的节点
		releaseNode(n->content);
		n->content = NULL;
		free(n);
		n = NULL;
	}
	else	//该节点是非尾节点
	{
		n->prev->next = n->next;	//
		n->next->prev = n->prev;	//该节点脱链
		releaseNode(n->content);
		n->content = NULL;
		free(n);
		n = NULL;
	}
	return SUCCESS;
}

/**************
Func:
D.S. dep.: STATUS, NODE, LIST
Func dep.: countList, malloc
**************/
NODE *insertNode(LIST l, int idx, void *cntnt)	//分配内存的函数返回值为指针，NULL为执行失败
{
	NODE *n = NULL;
	NODE *currentNode = NULL;
	int len = 0;
	int i = 0;

	if(NULL == l || idx < 1)	//不合法索引值
	{
		return NULL;
	}
	countList(l, &len);
	if(idx > len+1)	//超出LIST长度，不合法；len+1是添加在链表末端
	{
		return NULL;	
	}
	n = (NODE *)malloc(sizeof(NODE));	//分配空间失败
	if(NULL == n)
	{
		return NULL;
	}
	n->content = cntnt;
	currentNode = l;
	if(idx == len+1)	//插在链表末端
	{
		for(i=0;i<len;i++)
		{
			currentNode = currentNode->next;
		}
		//currentNode此时指向链表末端
		currentNode->next = n;
		n->prev = currentNode;
		n->next = NULL;
	}
	else	//插在链表中，idx<len+1
	{
		for(i=0;i<idx;i++)
		{
			currentNode = currentNode->next;	
		}
		//currentNode此时指向链表中要插入位置
		n->prev = currentNode->prev;
		n->next = currentNode;
		currentNode->prev->next = n;
		currentNode->prev = n;
	}

	return n;
}

/**************
Func:
D.S. dep.: NODE, LIST
Func dep.: countList
**************/
void showList(LIST l)
{
	NODE *n = NULL;
	int i = 0;
	
	if(NULL == l)
	{
		printf("NULL LIST\n");
		return;
	}

	countList(l,&i);
	//headline
	printf("nodeSize:%d\tnodeCount:%d\n",sizeof(NODE),i);
	//head node info
	n = l;
	printf("headAddr:%d\t",n);
	printf("prev:%d\t",n->prev);
	printf("next:%d\t",n->next);
	printf("cont:%d\n",n->content);
	//other node info
	while(NULL != n->next)
	{
		n = n->next;
		printf("nodeAddr:%d\t",n);
		printf("prev:%d\t",n->prev);
		printf("next:%d\t",n->next);
		printf("cont:%d\n",n->content);
	}

	return;
}

/**************
Func: 循环；删除、插入节点功能测试
D.S. dep.: NODE, LIST
Func dep.: showList, delNode, insertNode
**************/
void testDelInsert(LIST l)
{
	char c = 0;

	showList(l);
	c = getch();
	while(c != 'q')
	{
		switch(c)
		{
			case '1':
				delNode(l,1);
				showList(l);
				break;
			case '2':
				delNode(l,2);
				showList(l);
				break;
			case '3':
				delNode(l,3);
				showList(l);
				break;
			case '4':
				delNode(l,4);
				showList(l);
				break;
			case 'a':
				insertNode(l, 1, NULL);
				showList(l);
				break;
			case 'b':
				insertNode(l, 2, NULL);
				showList(l);
				break;
			case 'c':
				insertNode(l, 3, NULL);
				showList(l);
				break;
			case 'd':
				insertNode(l, 4, NULL);
				showList(l);
				break;
			default:
				printf("unknown cmd\n");
		}
		c = getch();
	}
}

