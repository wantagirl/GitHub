#include "list.h"

LIST makeList(void)	
{
	NODE h = NULL;
	NODE t = NULL;

	//建立头尾节点
	h = (NODE)calloc(1,sizeof(node_t));	//calloc可以初始化内存
	if(NULL == h)
	{
		return NULL;
	}
	//建立尾节点
	t = (NODE)calloc(1,sizeof(node_t));	//calloc可以初始化内存
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

int countNodes(LIST l)
{
	NODE n = NULL;
	int i = 0;

	//链表指针不合法
	if(NULL == l)
	{
		return -1;	//失败返回-1
	}
	//数节点
	n = l->next;
	while(LISTTAIL != n->type) //不包括尾节点
	{
		i++;
		n = n->next;
	}
	return i;	//成功返回节点数
}

BOOL isEmptyList(LIST l)
{
	//链表指针不合法
	if(-1 == countNodes(l))
	{
		return NULL_BOOL;
	}
	else if(0 == countNodes(l))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int sizeofNode(NODE n)
{
	int size = 0;

	//空节点指针不合法
	if(NULL == n)
	{
		return -1;	//失败返回-1
	}
	//根据类型判断节点负载大小
	switch(n->type)
	{
		case NULL_T:
		case LISTHEAD:
		case LISTTAIL:	//无意义指针内容大小为0
		default:
			size = 0;
	}
	//加上节点元数据大小
	size += sizeof(node_t);
	return size;
}

int sizeofList(LIST l)
{
	int size = 0;
	NODE n = NULL;

	//链表指针不合法
	if(NULL == l)
	{
		return -1;
	}
	
	//链表项的大小和
	n = l;
	while(LISTTAIL != n->type)
	{
		size += sizeofNode(n);
		n = n->next;
	}
	size += sizeofNode(n);	//此时n指向尾节点
	return size;
}

NODE addNode(LIST l, int idx, TYPES tp, void *ld)
{
	NODE newNode = NULL;
	NODE curNode = NULL;

	int i = 0;

	//异常情况
	if(NULL == l || idx < 1)	//不合法索引值
	{
		return NULL;
	}
	if(idx > countNodes(l)+1)	//超出LIST长度，不合法；len+1是添加在链表末端，合法
	{
		return NULL;	
	}
	newNode = (NODE)calloc(1, sizeof(node_t));
	if(NULL == newNode)	//分配空间失败
	{
		return NULL;
	}
	//加载新节点
	newNode->type = tp;
	newNode->load = ld;
	//找到插入位置
	curNode = l;
	for(i=0; i<idx; i++)
	{
		curNode = curNode->next;
	}//此时curNode指向要插入的位置
	//插入
	newNode->prev = curNode->prev;
	newNode->next = curNode;
	curNode->prev->next = newNode;
	curNode->prev = newNode;
	
	return newNode;
}

STATUS reverseList(LIST l)
{
	NODE n = NULL;
	NODE swap = NULL;

	//异常情况
	if(NULL == l)
	{
		return FAILED;
	}
	//没有或只有一个节点不需要翻转
	if(countNodes(l) < 2)
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

STATUS releaseNode(NODE n)
{
	if(NULL == n)	//不合法NODE指针
	{
		return FAILED;
	}
	//根据节点类型释放节点
	switch(n->type)
	{
		case NULL_T:
		case LISTHEAD:
		case LISTTAIL:
		default:
			free(n->load);
	}
	n->load = NULL;
	n->type = NULL_T;
	return SUCCESS;
}

STATUS delNodeByIdx(LIST l, int idx)
{
	int i = 0;
	NODE n = NULL;

	//异常情况
	if(NULL == l || idx < 1)	//不合法的索引值
	{
		return FAILED;
	}
	if(idx > countNodes(l))
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
	n->prev->next = n->next;	//该节点脱链
	n->next->prev = n->prev;
	//释放负载与节点
	releaseNode(n);
	free(n);
	
	return SUCCESS;
}

STATUS delNodeByAddr(LIST l, NODE n)
{
	NODE curNode = NULL;

	//异常情况
	if(NULL == l||NULL == n)	//链表或节点指针不合法
	{
		return FAILED;
	}
	if(0 == countNodes(l))	//链表无内容节点
	{
		return FAILED;
	}
	//找到并删除节点
	curNode = l->next;
	while(LISTTAIL != curNode->type)
	{
		if(n == curNode)	//找到要删除的节点
		{
			curNode->prev->next = curNode->next;	//该节点脱链
			curNode->next->prev = curNode->prev;
			releaseNode(curNode);
			free(curNode);
			return SUCCESS;
		}
		curNode = curNode->next;	//继续按地址寻找
	}
	//没有找到需要删除的节点，视为成功
	return SUCCESS;
}

STATUS releaseList(LIST l)
{
	NODE n = NULL;

	//异常情况
	if(NULL == l)
	{
		return FAILED;
	}
	//从第一节点开始release
	n = l->next;
	while(LISTTAIL != n->type)
	{
		releaseNode(n);
		n = n->next;
	}
	return SUCCESS;
}

STATUS delList(LIST l)
{
	NODE n = NULL;

	if(NULL == l)	//链表不合法，视为成功
	{
		return SUCCESS;
	}

	n = l;
	while(LISTTAIL != n->type)
	{
		n = n->next;
		releaseNode(n->prev);	//释放载荷
		free(n->prev);	//释放节点
		printf("free:%d\n",n->prev);
	}//此时指向尾节点
	releaseNode(n);	//释放载荷
	free(n);	//释放节点
	printf("free:%d\n",n);
	return SUCCESS;
}




void showList(LIST l)
{
	NODE n = NULL;

	//链表指针不合法
	if(NULL == l)	
	{
		printf("NULL LIST\n");
		return;
	}

	//list info
	printf("List count:%d\tsize:%d\n",countNodes(l),sizeofList(l));
	
	//head info
	n = l;
	printf("headAddr:%d\tprev:%d\tnext:%d\ttype:%d\tloadAddr:%d\n",n,n->prev,n->next,n->type,n->load);
	//info of other nodes 
	n = n->next;
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
	BOOL b = START_BOOL;	//invalid value
	char c = 0;
	int i = 0;

	showList(l);
	c = getch();
	while(c != 'q')
	{
		switch(c)
		{
			case '1':
				delNodeByIdx(l,1);
				showList(l);
				break;
			case '2':
				delNodeByIdx(l,2);
				showList(l);
				break;
			case '3':
				delNodeByIdx(l,3);
				showList(l);
				break;
			case '4':
				delNodeByIdx(l,4);
				showList(l);
				break;
			case '5':
				printf("Addr of Node to be del:");
				scanf("%d", &i);
				delNodeByAddr(l,(NODE)i);
				showList(l);
				break;
			case 'a':
				addNode(l, 1, NULL_T, NULL);
				showList(l);
				break;
			case 'b':
				addNode(l, 2, NULL_T, NULL);
				showList(l);
				break;
			case 'c':
				addNode(l, 3, NULL_T, NULL);
				showList(l);
				break;
			case 'd':
				addNode(l, 4, NULL_T, NULL);
				showList(l);
				break;
			case 'u':
				releaseList(l);
				showList(l);
				break;
			case 'r':
				reverseList(l);
				showList(l);
				break;
			case 'k':
				delList(l);
				l = NULL;
				break;
			case 'f':
				//printf("FirstNode:%d\n",findFirstNode(l));
				break;
			case 'l':
				//printf("LastNode:%d\n",findLastNode(l));
				break;
			case 'e':
				#if 0
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
				#endif
			default:
				printf("unknown cmd\n");
		}
		c = getch();
	}
}


#if 0
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
#endif