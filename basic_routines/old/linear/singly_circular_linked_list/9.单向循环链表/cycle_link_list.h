#ifndef __CYCLE_LINK_LIST_H__
#define __CYCLE_LINK_LIST_H__

#include "sys.h"

//Ԫ�����Ͷ���
typedef int ElemType;

//������
typedef struct tagNode
{
	ElemType		data;//������
	struct tagNode *next;//ָ����
}LNode, *LinkList;


Status InitList_CL(LinkList *L);//��ʼ��һ��ѭ������
Status DestroyList_CL(LinkList *L);//����ѭ������
Status ClearList_CL(LinkList *L);//�������
Status ListEmpty_CL(LinkList L);//�ж������Ƿ�Ϊ��
int    ListLength_CL(LinkList L);//����������Ԫ�ظ���
Status GetElem_CL(LinkList L, int i, ElemType *e);//��ȡ�����е�i��Ԫ��

//����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
int    LocateElem_CL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));

Status PriorElem_CL(LinkList L, ElemType cur_e, ElemType *pre_e);//����ָ��Ԫ�ص�ǰ��
Status NextElem_CL(LinkList L, ElemType cur_e, ElemType *next_e);//����ָ��Ԫ�صĺ��
Status ListInsert_CL(LinkList *L, int i, ElemType e);//������
Status ListDelete_CL(LinkList *L, int i, ElemType *e);//ɾ�����
Status ListTraverse_CL(LinkList L, void(*vi)(ElemType));//��������

#endif
