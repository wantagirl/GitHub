#include "list.h"

LIST makeList(void)	
{
	NODE *h = NULL;
	NODE *t = NULL;

	//建立头尾结点
	h = (NODE *)calloc(1,sizeof(NODE));	//calloc可以初始化内存
	if(NULL == h)
	{
		return NULL;
	}
	t = (NODE *)calloc(1,sizeof(NODE));	//calloc可以初始化内存
	if(NULL == t)
	{
		free(h);	//释放已分配的头节点
		return NULL;
	}

	//初始化头节点和尾节点并链接
	h->prev = NULL;
	h->next = t;
	h->type = LISTHEAD;
	h->load = NULL;

	t->prev = h;
	t->next = NULL;
	t->type = LISTTAIL;
	t->load = NULL;

	return h;
}

STATUS countList(LIST l, int *cnt)
{
	int i = 0;
	NODE *n = NULL;

	if(NULL == l)	//链表指针不合法
	{
		return FAILED;
	}
	//数节点
	n = l->next;
	while(LISTTAIL != n->type) //不包括尾节点
	{
		i++;
		n = n->next;
	}
	*cnt = i; 
	return SUCCESS;
}
STATUS isListEmpty(LIST l, BOOL *retval)
{
	int cnt = 0;
	if(NULL == l)	//链表指针不合法
	{
		return FAILED;
	}
	countList(l,&cnt);
	if(cnt == 0)	//无内容节点
	{
		*retval = TRUE;
	}
	else
	{
		*retval = FALSE;
	}
	return SUCCESS;
}

STATUS sizeofNodeLoad(NODE *n, int *sz)
{
	if(NULL == n)	//空节点指针不合法
	{
		return FAILED;
	}
	//根据类型判断节点内容大小
	switch(n->type)
	{
		case NULL_T:
		case LISTHEAD:
		case LISTTAIL:	//无意义指针内容大小为0
			*sz = 0;
			break;
		default:
			*sz = 0;
			break;
	}
	return SUCCESS;
}

STATUS sizeofList(LIST l, int *sz)
{
	int cnt = 0;
	int size = 0;
	int i = 0;
	NODE *n = NULL;

	if(NULL == l)	//链表指针不合法
	{
		return FAILED;
	}
	
	//链表的大小
	countList(l, &cnt);
	size = (cnt+2)*sizeof(NODE);	//加上头尾节点
	//链表项的大小和
	n = l->next;
	while(LISTTAIL != n->type)
	{
		sizeofNodeLoad(n, &i);
		size += i;
		n = n->next;
	}
	*sz = size;
	return SUCCESS;
}

STATUS releaseNodeLoad(void *ld)
{
	free(ld);
	return SUCCESS;
}

STATUS delList(LIST l)
{
	NODE *n = NULL;

	if(NULL == l)	//链表不合法，视为成功
	{
		return SUCCESS;
	}

	n = l;
	while(LISTTAIL != n->type)
	{
		n = n->next;
		//printf("free:%d\n",n->prev);
		releaseNodeLoad(n->prev->load);	//释放载荷
		free(n->prev);	//释放节点
	}
	//printf("free:%d\n",n);
	releaseNodeLoad(n->load);	//释放载荷
	free(n);	//释放节点
	return SUCCESS;
}

NODE *insertNode(LIST l, int idx, TYPES tp, void *ld)	//分配内存的函数返回值为指针，NULL为执行失败
{
	NODE *newNode = NULL;
	NODE *curNode = NULL;
	int cnt = 0;
	int i = 0;

	//异常情况
	if(NULL == l || idx < 1)	//不合法索引值
	{
		return NULL;
	}
	countList(l, &cnt);
	if(idx > cnt+1)	//超出LIST长度，不合法；len+1是添加在链表末端
	{
		return NULL;	
	}
	newNode = (NODE *)calloc(1, sizeof(NODE));	//分配空间失败
	if(NULL == newNode)
	{
		return NULL;
	}
	//加载新节点
	newNode->type = tp;
	newNode->load = ld;
	//找到插入位置并插入
	curNode = l;
	for(i=0; i<idx; i++)
	{
		curNode = curNode->next;
	}
	newNode->prev = curNode->prev;
	newNode->next = curNode;
	curNode->prev->next = newNode;
	curNode->prev = newNode;
	
	return newNode;
}

STATUS delNode(LIST l, int idx)
{
	int cnt = 0;
	int i = 0;
	NODE *n = NULL;

	//异常情况
	if(NULL == l || idx < 1)	//不合法的索引值
	{
		return FAILED;
	}
	countList(l, &cnt);
	if(idx > cnt)
	{
		return FAILED;	//超出LIST长度，不合法
	}
	//找到要删除的节点
	n = l;
	for(i=0;i<idx;i++)
	{
		n=n->next;
	}
	//n此时指向要删除的节点
	n->prev->next = n->next;	//
	n->next->prev = n->prev;	//该节点脱链
	releaseNodeLoad(n->load);
	free(n);
	
	return SUCCESS;
}

STATUS delNodeByAddr(LIST l, NODE *n)
{
	int cnt = 0;
	NODE *curNode = NULL;

	//异常情况
	if(NULL == l||NULL == n)	//链表或节点指针不合法
	{
		return FAILED;
	}
	countList(l, &cnt);
	if(0 == cnt)	//链表无内容节点
	{
		return FAILED;
	}
	//
	curNode = l->next;
	while(LISTTAIL != curNode->type)
	{
		if(n == curNode)	//找到要删除的节点
		{
			curNode->prev->next = curNode->next;	//
			curNode->next->prev = curNode->prev;	//该节点脱链
			releaseNodeLoad(curNode->load);
			free(curNode);
			return SUCCESS;
		}
		curNode = curNode->next;
	}
	return SUCCESS;	//没有找到需要删除的节点，视为成功
}

STATUS unloadList(LIST l)
{
	NODE *n = NULL;

	//异常情况
	if(NULL == l)
	{
		return FAILED;
	}
	//从第一节点开始unload
	n = l->next;
	while(LISTTAIL != n->type)
	{
		releaseNodeLoad(n->load);
		n->load = NULL;
		n = n->next;
	}
	return SUCCESS;
}

STATUS reverseList(LIST l)
{
	NODE *n = NULL;
	NODE *swap = NULL;
	int cnt = 0;

	//异常情况
	if(NULL == l)
	{
		return FAILED;
	}
	//没有或只有一个节点不需要翻转
	countList(l,&cnt);
	if(cnt < 2)
	{
		return SUCCESS;
	}
	//至少两个节点，从第一节点开始reverse
	n = l->next;
	while(LISTTAIL != n->type)
	{
		swap = n->prev;
		n->prev = n->next;
		n->next = swap;
		n = n->prev;
	}
	//修改头尾节点指针
	swap = l->next;
	l->next = n->prev;
	n->prev = swap;
	//修改头尾内容节点指针
	l->next->prev = l;
	n->prev->next = n;
	return SUCCESS;
}

STATUS isSameNodeLoad(NODE *n1, NODE *n2, BOOL *retval)	//true: identical, false: different
{
	//按内存地址比较，可以有其他方式
	if(n1 == n2)	//内存地址一样
	{
		if(NULL == n1)	//两个NULL被认为是不同的，以满足初始化的比较
		{
			*retval = FALSE;
		}
		else
		{
			*retval = TRUE;
		}
	}
	else
	{
		*retval = FALSE;
	}
	return SUCCESS;
}

NODE *findFirstNode(LIST l)
{
	int cnt = 0;
	//异常情况
	if(NULL == l)
	{
		return NULL;
	}
	countList(l,&cnt);
	if(cnt == 0)	//空表
	{
		return NULL;
	}
	//至少有一个节点
	return l->next;
}

NODE *findLastNode(LIST l)
{
	NODE *n = NULL;
	int cnt = 0;

	//异常情况
	if(NULL == l)
	{
		return NULL;
	}
	countList(l,&cnt);
	if(cnt == 0)	//空表
	{
		return NULL;
	}
	//至少有一个节点
	n = l->next;
	while(LISTTAIL != n->type)
	{
		n = n->next;
	}
	//此时n指到尾节点
	return n->prev;
}


void showList(LIST l)
{
	NODE *n = NULL;
	int cnt = 0;
	int sz = 0;
	
	if(NULL == l)	//链表指针不合法
	{
		printf("NULL LIST\n");
		return;
	}

	//list info
	countList(l, &cnt);
	sizeofList(l, &sz);
	printf("List count:%d\tsize:%d\n",cnt,sz);
	
	//head info
	n = l;
	printf("headAddr:%d\tprev:%d\tnext:%d\ttype:%d\tloadAddr:%d\n",n,n->prev,n->next,n->type,n->load);
	n = n->next;
	//other node info
	while(LISTTAIL != n->type)
	{
		printf("nodeAddr:%d\tprev:%d\tnext:%d\ttype:%d\tloadAddr:%d\n",n,n->prev,n->next,n->type,n->load);
		n = n->next;
	}
	//tail info
	printf("tailAddr:%d\tprev:%d\tnext:%d\ttype:%d\tloadAddr:%d\n",n,n->prev,n->next,n->type,n->load);
	return;
}
void testList(LIST l)
{
	char c = 0;
	BOOL b = START_BOOL;	//invalid value
	int i = 0;

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
			case '5':
				printf("Addr of Node to be del:");
				scanf("%d", &i);
				delNodeByAddr(l,(NODE *)i);
				showList(l);
				break;
			case 'a':
				insertNode(l, 1, NULL_T, NULL);
				showList(l);
				break;
			case 'b':
				insertNode(l, 2, NULL_T, NULL);
				showList(l);
				break;
			case 'c':
				insertNode(l, 3, NULL_T, NULL);
				showList(l);
				break;
			case 'd':
				insertNode(l, 4, NULL_T, NULL);
				showList(l);
				break;
			case 'u':
				unloadList(l);
				showList(l);
				break;
			case 'r':
				reverseList(l);
				showList(l);
				break;
			case 'f':
				printf("FirstNode:%d\n",findFirstNode(l));
				break;
			case 'l':
				printf("LastNode:%d\n",findLastNode(l));
				break;
			case 'e':
				isListEmpty(l, &b);
				if(TRUE == b)
				{
					printf("List is empty\n");
				}
				else if(FALSE == b)
				{
					printf("List is not empty\n");
				}
				else
				{
					printf("unknownListStatus\n");
				}
				break;
			default:
				printf("unknown cmd\n");
		}
		c = getch();
	}
}