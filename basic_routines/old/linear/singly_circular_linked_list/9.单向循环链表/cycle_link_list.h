#ifndef __CYCLE_LINK_LIST_H__
#define __CYCLE_LINK_LIST_H__

#include "sys.h"

//元素类型定义
typedef int ElemType;

//定义结点
typedef struct tagNode
{
	ElemType		data;//数据域
	struct tagNode *next;//指针域
}LNode, *LinkList;


Status InitList_CL(LinkList *L);//初始化一个循环链表
Status DestroyList_CL(LinkList *L);//销毁循环链表
Status ClearList_CL(LinkList *L);//清空链表
Status ListEmpty_CL(LinkList L);//判断链表是否为空
int    ListLength_CL(LinkList L);//返回链表中元素个数
Status GetElem_CL(LinkList L, int i, ElemType *e);//获取链表中第i个元素

//返回L中第1个与e满足关系compare()的数据元素的位序
int    LocateElem_CL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));

Status PriorElem_CL(LinkList L, ElemType cur_e, ElemType *pre_e);//返回指定元素的前驱
Status NextElem_CL(LinkList L, ElemType cur_e, ElemType *next_e);//返回指定元素的后继
Status ListInsert_CL(LinkList *L, int i, ElemType e);//插入结点
Status ListDelete_CL(LinkList *L, int i, ElemType *e);//删除结点
Status ListTraverse_CL(LinkList L, void(*vi)(ElemType));//遍历链表

#endif
