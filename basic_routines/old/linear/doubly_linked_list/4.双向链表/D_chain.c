#include <stdio.h>
#include <malloc.h>
#include "D_chain.h"


//头插法创建双链表
//input函数用于输入数据
void CreateDLinkHead(DLinkList *L, int n, void(*input)(ElemType*))
{
	DLinkList s;

	*L = (DLinkList)malloc(sizeof(DNode));//创建头结点
	(*L)->prev = (*L)->next = NULL;//初始时表为空

	for (; n > 0; n--)//创建n个结点
	{
		s = (DLinkList)malloc(sizeof(DNode));//创建一个新结点
		input(&s->data);//给这个新结点的数据域存数据
		s->next = (*L)->next;//将s增加到开始结点之前
		if ((*L)->next!=NULL)(*L)->next->prev = s;//开始结点之前是s
		(*L)->next = s, s->prev = *L;//头结点之后是s，s之前是头结点
	}
}
//尾插法创建双链表
//input函数用于输入数据
void CreateDLinkTail(DLinkList *L, int n, void(*input)(ElemType*))
{
	DLinkList p,s;

	p = *L = (DLinkList)malloc(sizeof(DNode));//创建头结点
	(*L)->prev = (*L)->next = NULL;//初始时表为空

	for (; n > 0; n--)//创建n个结点
	{
		s = (DLinkList)malloc(sizeof(DNode));//创建一个新结点
		input(&s->data);//给这个新结点的数据域存数据
		s->next = NULL;//当前结点是尾结点
		p->next = s, s->prev = p,p = s;//将s增加到链尾
	}
}
//创建一个空的双向链表
void CreateEmptyDLinkList(DLinkList *L)
{
	*L = (DLinkList)malloc(sizeof(DNode));//创建头结点
	(*L)->prev = (*L)->next = NULL;//初始时表为空
}
//双链表插入结点
//在双链表中第i个位置前插入元素e
//返回值：0正常，非0异常
int DLinkListInsert(DLinkList *L, int i, ElemType e)
{
	DLinkList s, p = *L;//p指向头结点

	while (p != NULL&&i > 1)//寻找第i-1个结点
	{
		p = p->next;//p指向直接后继结点
		i--;
	}
	if (p == NULL || i < 1)return 1;//i值不合法
	s = (DLinkList)malloc(sizeof(DNode));//创建新结点
	s->data = e;//存放要插入的数据
	s->next = p->next;//结点插入算法
	if (p->next != NULL)p->next->prev = s;
	s->prev = p, p->next = s;

	return 0;//正常
}
//双链表删除结点
//删除双链表中第i个位置的结点，并由*ep返回其值
//返回值：0正常，非0异常
int DLinkListDelete(DLinkList *L, int i, ElemType *ep)
{
	DLinkList p = NULL, q = *L;		//q指向头结点

	while (q!=NULL&&i>=1)//找到第i个结点
	{
		p = q;			//p是q的前驱
		q = q->next;	//q指向直接后继节点
		i--;
	}
	if (p == NULL || q == NULL)return 1;//i值不合法
	p->next = q->next;		//结点删除算法
	if (q->next != NULL)q->next->prev = p;
	if (ep != NULL)*ep = q->data;//删除结点由*ep返回其值
	free(q);

	return 0;//正常
}

