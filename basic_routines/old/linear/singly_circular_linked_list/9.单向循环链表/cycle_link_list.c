
/*

2017年12月8日，小王持续奋斗！

单向循环链表的相关实现，
此例程的链表带有头结点

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "cycle_link_list.h"
#include "sys.h"



//初始化一个循环链表
//操作结果：构造一个空的线性表L
Status InitList_CL(LinkList *L)
{ 
	*L = (LinkList)malloc(sizeof(LNode)); /* 产生头结点,并使L指向此头结点 */
	if (!*L)return ERR1;//内存申请失败

	(*L)->next = *L; /* 指针域指向头结点 */

	return OK;//成功
}
//销毁循环链表
//操作结果：销毁线性表L
Status DestroyList_CL(LinkList *L)
{
	LinkList q, p = (*L)->next; /* p指向开始结点 */
	while (p != *L) /* 没到表尾 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(*L);//释放头结点
	*L = NULL;//防止头指针悬空
	return OK;//成功
}
//清空链表
//初始条件：线性表L已存在
//操作结果：将L重置为空表
Status ClearList_CL(LinkList *L)
{
	LinkList q, p = (*L)->next; /* p指向开始结点 */
	while (p != *L) /* 没到表尾 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = *L; /* 头结点指针域指向自身 */

	return OK;//成功
}
//判断链表是否为空
//初始条件：线性表L已存在
//操作结果：若L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty_CL(LinkList L)
{
	return L->next == L;
}
//返回链表中元素个数
//初始条件：L已存在。
//操作结果：返回L中数据元素个数
int ListLength_CL(LinkList L)
{
	int i = 0;//i为计数器
	LinkList p = L->next; /* p指向开始结点 */
	while (p != L) /* 没到表尾 */
	{
		i++;
		p = p->next;
	}
	return i;
}
//获取链表中第i个元素
//当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR
Status GetElem_CL(LinkList L, int i, ElemType *e)
{
	int j = 1; /* 初始化,j为计数器 */
	LinkList p = L->next; /* p指向开始结点 */

	if (i <= 0 || i>ListLength_CL(L))return ERR1;//i不合法

	while (j<i)
	{ /* 顺指针向后查找,直到p指向第i个元素 */
		p = p->next;
		j++;
	}
	*e = p->data; /* 取第i个元素 */

	return OK;
}
//返回L中第1个与e满足关系compare()的数据元素的位序
//若这样的数据元素不存在，则返回值为0
//初始条件：线性表L已存在，compare()是数据元素判定函数
int LocateElem_CL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 0;
	LinkList p = L->next; /* p指向开始结点 */
	while (p != L)
	{
		i++;
		if (compare(p->data, e)) /* 满足关系 */
			return i;//返回位序
		p = p->next;
	}
	return 0;//元素不存在
}
//若cur_e是L的数据元素，且不是第一个，则用*pre_e返回它的前驱
//初始条件：线性表L已存在
//返回值：0成功；非0失败
Status PriorElem_CL(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	int len;
	LinkList q, p;

	len = ListLength_CL(L);
	if (len<=1)return ERR1;//表为空，或表长为1时没有前驱

	p = L->next;//p指向开始结点
	while (p != L)//若不是链尾则继续
	{
		q = p->next;//q为p的直接后继结点
		if (q != L && q->data == cur_e && pre_e != NULL)
		{
			*pre_e = p->data;//*pre_e返回前驱元素
			return 0;//成功
		}
		p = q;//p指向直接后继结点
	}
	return ERR2;//失败
}
//若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继
//初始条件：线性表L已存在
//返回值：0成功；非0失败
Status NextElem_CL(LinkList L, ElemType cur_e, ElemType *next_e)
{
	int len;
	LinkList p ;

	len = ListLength_CL(L);
	if (len <= 1)return ERR1;//表为空，或表长为1时没有后继

	p = L->next;//p指向开始结点
	while (p != L)
	{
		if (p->data == cur_e)
		{
			if (p->next != L && next_e != NULL)
			{
				*next_e = p->next->data;//*next_e返回后继元素
				return OK;//成功
			}
		}
		p = p->next;//p指向直接后继结点
	}
	return ERR2;//没找到
}
//插入结点
//在L的第i个位置之前插入元素e
Status ListInsert_CL(LinkList *L, int i, ElemType e)
{
	int j = 0;
	LinkList p = (*L), s; /* p指向头结点 */

	if (i <= 0 || i>ListLength_CL(*L) + 1)return ERR1;//i的合法性检查

	while (j<i - 1) /* 寻找第i-1个结点 */
	{
		p = p->next;
		j++;
	}
	s = (LinkList)malloc(sizeof(LNode)); /* 生成新结点 */
	if (s == NULL)return ERR2;

	s->data = e; /* 插入L中 */
	s->next = p->next;
	p->next = s;

	return OK;
}
//删除结点
//删除L的第i个元素,并由e返回其值
Status ListDelete_CL(LinkList *L, int i, ElemType *e)
{
	int j = 0;
	LinkList p = (*L), q; /* p指向头结点 */

	if (i <= 0 || i>ListLength_CL(*L))return ERR1;//i的合法性判断
		
	while (j<i - 1) /* 寻找第i-1个结点 */
	{
		p = p->next;
		j++;
	}
	q = p->next; /* q指向待删除结点 */
	p->next = q->next;
	*e = q->data;
	//if (*L == q) /* 删除的是表尾元素 */
		//*L = p;
	free(q); /* 释放待删除结点 */
	return OK;
}
//遍历链表
//操作条件：L已存在
//操作结果：依次对L的每个数据元素调用函数vi()
Status ListTraverse_CL(LinkList L, void(*vi)(ElemType))
{
	LinkList p = L->next;
	while (p != L)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
