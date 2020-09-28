#ifndef __D_CHAIN_H__
#define __D_CHAIN_H__

//˫���������ݽṹ����

typedef int ElemType;//������Ԫ������

typedef struct tagDNode
{
	ElemType data;					//������
	struct tagDNode *prev, *next;	//ָ���򣺷ֱ�ָ��ǰ�����ͺ�̽��
}DNode;

typedef DNode* DLinkList;//ָ��˫��������Ľṹ��ָ

//ͷ�巨����˫����
void CreateDLinkHead(DLinkList *L, int n, void(* input)(ElemType*));
//β�巨����˫����
void CreateDLinkTail(DLinkList *L, int n, void(*input)(ElemType*));
//����һ���յ�˫������
void CreateEmptyDLinkList(DLinkList *L);
//˫���������
int  DLinkListInsert(DLinkList *L, int i, ElemType e);
//˫����ɾ�����
int  DLinkListDelete(DLinkList *L, int i, ElemType *ep);

#endif