#ifndef __CYCLE_DLIST_H__
#define __CYCLE_DLIST_H__

//状态标记
#define OK		1
#define ERROR	0
typedef int Status;

//元素类型定义
typedef char ElemType;

//定义结点
typedef struct DualNode
{
	ElemType		 data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DualLinkList;

Status InitList(DualLinkList *L);//初始化链表


#endif
