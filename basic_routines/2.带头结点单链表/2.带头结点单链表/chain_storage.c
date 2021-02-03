
//线性表 链式存储结构（带头结点的单链表） 的相关实现

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "sys.h"
#include "chain_storage.h"


//创建一个空表
//即创建一个空链表（没有数据结点）
void C_ListCreateEmpty(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));	//创建头结点，*L指向头结点
	(*L)->next = NULL;						//初始时为空表
}
//创建线性表
//头插法 创建带有头结点的单链表
//input函数用于输入数据
//n为线性表初始长度
void C_ListCreateHead(LinkList *L,int n,void(* input)(C_ElemType *))
{
	LinkList s;

	*L = (LinkList)malloc(sizeof(Node));	//创建头结点
	(*L)->next = NULL;						//初始时为空表
	for ( ;n > 0; n--)//创建有n个数据结点的链表
	{
		s = (LinkList)malloc(sizeof(Node)); //创建新结点
		input(&(s->data));					//调用input输入数据域
		s->next = (*L)->next;				//将s增加到开始结点之前
		(*L)->next = s;						//头结点之后
	}
}
//创建线性表
//尾插法 创建带有头结点的单链表
//input函数用于输入数据
//n为线性表初始长度
void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *))
{
	LinkList p, s;

	p = *L = (LinkList)malloc(sizeof(Node));//创建头结点，p也指向头结点
	for (; n > 0; n--)						//创建n个结点链表
	{
		s = (LinkList)malloc(sizeof(Node)); //创建新结点
		input(&(s->data));					//调用input输入数据域
		p->next = s, p = s;					//将s插入到当前链表末尾
	}
	p->next = NULL;							//尾结点
}
//判断线性表是否为空表
//若L为空，返回TRUE，否则返回FALSE
int C_ListIsEmpty(LinkList L)
{
	return (L->next == NULL);
}
//遍历线性表
//遍历线性表中的每个元素且调用函数visit访问它
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*))
{
	LinkList p = L->next;	//p初始指向开始结点
	while (p != NULL)		//若不是链尾则继续
	{
		visit(&(p->data));	//调用visit访问结点
		p = p->next;		//p指向直接后继结点
	}
}
//计算线性表长度
//返回L中数据元素的个数
int C_ListLength(LinkList L)
{
	int cnt = 0;			//计数器cnt初始值为0

	LinkList p = L->next;	//p指向线性表第一个元素
	while (p!=NULL)			//若不是链尾则继续
	{
		cnt++;				//计数器+1
		p = p->next;		//指向下一个结点
	}
	return cnt;				//返回元素个数
}
//将两个线性表L1，L2相连
void C_ListLink(LinkList L1, LinkList *L2)
{
	LinkList q = NULL, p = L1;		//p指向链表1的头结点
	while (p != NULL)				//若是链表1链尾则结束
	{
		q = p;
		p = p->next;		//指向下一个结点
	}//这个循环结束后，q指向L1尾结点
	if (q != NULL && (*L2) != NULL)
	{
		q->next = (*L2)->next;		//链表1的尾结点指向链表2的开始结点（第一个元素）
		free(*L2);					//释放链表2的头结点
		*L2 = NULL;
	}
}
//当第i个元素存在时，其值赋给*e并返回0，否则返回非0值
//L为带头结点的单链表的头指针
STATUS C_ListGetElem(LinkList L, int i, C_ElemType *e)
{
	int j;//计数器
	LinkList p;

	p = L->next; j = 1;//初始化，p指向第一个结点，j为计数器

	//顺指针向后查找，直到p指向第i个元素或p为NULL
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)return ERR1;//第i个元素不存在
	*e = p->data;//取第i个元素

	return FUN_OK;//成功
}
//返回线性表中第一个满足compare()关系的元素的位序
int C_ListLocateElem(LinkList L, C_ElemType e, int(*compare)(C_ElemType*, C_ElemType*))
{
	int i = 0;

	LinkList p=L->next;		//p指向开始结点
	while (p != NULL)		//若不是链尾则继续
	{
		i++;
		if (compare(&(p->data),&e))return i;//关系成立
		p = p->next;						//指向直接后继结点
	}

	return 0;//关系不存在返回0
}
//在带头结点的单链线性表L中第i个位置之前插入元素e
//返回值：0成功；非0失败
STATUS C_ListInsert(LinkList *L, int i, C_ElemType e)
{
	LinkList s, p = *L;//p指向头结点

	while (p != NULL&&i > 1)//寻找第i-1个结点
	{
		p = p->next;//p指向直接后继结点
		i--;
	}
	if (p == NULL || i < 1)return 1;//i值不合法

	s = (LinkList)malloc(sizeof(Node));
	if (s == NULL)return 2;//内存申请失败
	s->data = e;
	s->next = p->next, p->next = s;//插入结点

	return FUN_OK;//成功
}
//在带头结点的单链线性表L中删除第i个元素，并用*e返回其值
STATUS C_ListDelete(LinkList *L, int i, C_ElemType *e)
{
	LinkList p = NULL, q = *L;//q指向头结点

	while (q != NULL && i >= 1)//直到第i个结点
	{
		p = q;
		q = q->next;
		i--;
	}
	if (p == NULL || q == NULL)return 1;//i值不合法

	p->next = q->next;
	if (e != NULL)*e = q->data;//返回删除结点的值
	free(q);

	return FUN_OK;//成功
}
//销毁线性表L
//即销毁单链表
void C_ListDestroy(LinkList *L)
{
	LinkList q, p = *L;	//p指向头结点
	while (p != NULL)	//若不是链尾则继续
	{
		q = p->next;	//指向下一个结点
		free(p);		//释放结点空间
		p = q;			//直接后继结点
	}
	*L = NULL;			//置为空表
}
//将L重置为空表
void C_ListClear(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;		//p指向开始结点
	while (p != NULL)	//若不是链尾则继续
	{
		q = p->next;	//指向直接后继结点
		free(p);		//释放空间
		p = q;			//直接后继结点
	}
	(*L)->next = NULL;	//初始时为空表
}
//选择排序法(从大到小)
//将线性表中的元素排序
LinkList C_ListSelectSort1(LinkList head)
{
	LinkList p, other, maxNode;
	int temp;
	if (head == NULL) return head;  //空链表

	for (p = head; p->next != NULL; p = p->next)
	{
		maxNode = p;
		for (other = p->next; other != NULL; other = other->next)
		{
			if (other->data > maxNode->data)
			{
				maxNode = other;
			}
		}
		if (maxNode != p)
		{
			temp = p->data;
			p->data = maxNode->data;
			maxNode->data = temp;
		}
	}
	return head;
}
//取得从指针p开始的链表中记录的最小值
static LinkList getminkey(LinkList p)
{
	LinkList minp;
	minp = p;
	while (p->next){
		if ((minp->data)>(p->next->data)){
			minp = p->next;//minp是较小值的指针
		}
		p = p->next;
	}
	return minp;//返回较小值的指针
}
//选择排序（从小到大）
void C_ListSelectSort2(LinkList head)
{
	LinkList j, i = head->next;
	int temp;
	for (; i->next != NULL; i = i->next){
		j = getminkey(i);
		if (i->data != j->data){
			temp = i->data;
			i->data = j->data;
			j->data = temp;
		}
	}
}
//获取链表尾结点元素
//返回值：0成功，非0失败
int C_ListGetLastElem(LinkList L, C_ElemType *e)
{
	LinkList q = NULL, p = L;//p指向头结点
	while (p != NULL)//若不是链尾则继续
	{
		q = p;
		p = p->next;//p指向后继结点
	}//循环执行完后q指向尾结点
	if (q != NULL)
	{
		*e = q->data;
		return 0;//成功
	}

	return 1;//失败
}
//返回链表中指定元素的前驱元素
//用pre_e返回cur_e的前驱
//返回值：0成功；非0失败
int C_ListPriorElem(LinkList L, C_ElemType cur_e, C_ElemType *pre_e)
{
	LinkList q, p = L->next;//p指向开始结点
	while (p != NULL)//若不是链尾则继续
	{
		q = p->next;//q为p的直接后继结点
		if (q != NULL&&q->data == cur_e&&pre_e != NULL)
		{
			*pre_e = p->data;//*pre_e返回前驱元素
			return 0;//成功
		}
		p = q;//p指向直接后继结点
	}
	return 1;//失败
}
//返回链表中指定元素的后继元素
//用next_e返回cur_e的后继
//返回值：0成功；非0失败
int C_ListNextElem(LinkList L, C_ElemType cur_e, C_ElemType *next_e)
{
	LinkList p = L->next;//p指向开始结点
	while (p != NULL)//若不是链尾则继续
	{
		if (p->data == cur_e)
		{
			if (p->next != NULL&&next_e != NULL)
			{
				*next_e = p->next->data;//*next_e返回后继元素
				return 0;//成功
			}
		}
		p = p->next;//p指向直接后继结点
	}
	return 1;//不存在cur_e返回0
}
//获取链表中间结点元素值
//采用快慢指针法快速获取链表中间结点元素值
STATUS GetMidNode(LinkList L, C_ElemType *e)
{
	LinkList pFast = L, pSlow = L;//初始时快慢指针都指向头结点

	while (pFast->next != NULL)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
		pFast = pFast->next;
		if (pFast == NULL)break;//当pFast为空时，不能再回去判断pFast->next != NULL，
	}							//因为使用空指针指向时，会发生崩溃！！！
	*e = pSlow->data;//获取中间结点数据值

	return FUN_OK;
}
