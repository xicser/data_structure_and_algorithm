#ifndef __CYCLE_DLIST_H__
#define __CYCLE_DLIST_H__

//״̬���
#define OK		1
#define ERROR	0
typedef int Status;

//Ԫ�����Ͷ���
typedef char ElemType;

//������
typedef struct DualNode
{
	ElemType		 data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DualLinkList;

Status InitList(DualLinkList *L);//��ʼ������


#endif
