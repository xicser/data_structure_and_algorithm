#ifndef __D_CHAIN_H__
#define __D_CHAIN_H__

//双向链表数据结构定义

typedef int ElemType;//数据域元素类型

typedef struct tagDNode
{
	ElemType data;					//数据域
	struct tagDNode *prev, *next;	//指针域：分别指向前驱结点和后继结点
}DNode;

typedef DNode* DLinkList;//指向双向链表结点的结构体指

//头插法创建双链表
void CreateDLinkHead(DLinkList *L, int n, void(* input)(ElemType*));
//尾插法创建双链表
void CreateDLinkTail(DLinkList *L, int n, void(*input)(ElemType*));
//创建一个空的双向链表
void CreateEmptyDLinkList(DLinkList *L);
//双链表插入结点
int  DLinkListInsert(DLinkList *L, int i, ElemType e);
//双链表删除结点
int  DLinkListDelete(DLinkList *L, int i, ElemType *ep);

#endif