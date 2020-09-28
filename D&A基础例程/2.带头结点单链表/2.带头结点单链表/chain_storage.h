#ifndef __CHAIN_STORAGE_H__
#define __CHAIN_STORAGE_H__

#include "sys.h"

//���Ա�Ԫ������
typedef int C_ElemType;

//��ƽ��Node�����Ա�ĵ�����洢�ṹ��
typedef struct tagNode
{
	C_ElemType      data;	//������
	struct tagNode *next;	//ָ����
}Node, *LinkList;


void C_ListCreateEmpty(LinkList *L);//����һ���ձ�
//�������Ա�
void C_ListCreateHead(LinkList *L, int n, void(*input)(C_ElemType *));//ͷ�巨
void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *));//β�巨

int  C_ListIsEmpty(LinkList L);//�ж����Ա��Ƿ�Ϊ�ձ�
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*));//�������Ա�
int  C_ListLength(LinkList L);//�������Ա���
void C_ListLink(LinkList L1, LinkList *L2);//���������Ա�L1��L2����
STATUS C_ListGetElem(LinkList L, int i, C_ElemType *e);//����i��Ԫ�ش���ʱ����ֵ����*e������0�����򷵻ط�0ֵ
//�������Ա��е�һ������compare()��ϵ��Ԫ�ص�λ��
int  C_ListLocateElem(LinkList L, C_ElemType e, int(*compare)(C_ElemType*, C_ElemType*));
STATUS C_ListInsert(LinkList *L, int i, C_ElemType e);//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
//�ڴ�ͷ���ĵ������Ա�L��ɾ����i��Ԫ�أ�����*e������ֵ
STATUS C_ListDelete(LinkList *L, int i, C_ElemType *e);
void C_ListDestroy(LinkList *L);//�������Ա�L
void C_ListClear(LinkList *L);//��L����Ϊ�ձ�
int  C_ListGetLastElem(LinkList L,C_ElemType *e);//��ȡ����β���Ԫ��
int  C_ListPriorElem(LinkList L,C_ElemType cur_e,C_ElemType *pre_e);//����������ָ��Ԫ�ص�ǰ��Ԫ��
int  C_ListNextElem(LinkList L,C_ElemType cur_e,C_ElemType *next_e);//����������ָ��Ԫ�صĺ��Ԫ��
STATUS GetMidNode(LinkList L, C_ElemType *e);//��ȡ�����м���Ԫ��ֵ


//ѡ������
LinkList C_ListSelectSort1(LinkList head);//�Ӵ�С
void C_ListSelectSort2(LinkList head);//��С����

#endif
