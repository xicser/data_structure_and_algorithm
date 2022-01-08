#include <stdio.h>
#include <malloc.h>
#include "D_chain.h"


//ͷ�巨����˫����
//input����������������
void CreateDLinkHead(DLinkList *L, int n, void(*input)(ElemType*))
{
	DLinkList s;

	*L = (DLinkList)malloc(sizeof(DNode));//����ͷ���
	(*L)->prev = (*L)->next = NULL;//��ʼʱ��Ϊ��

	for (; n > 0; n--)//����n�����
	{
		s = (DLinkList)malloc(sizeof(DNode));//����һ���½��
		input(&s->data);//������½��������������
		s->next = (*L)->next;//��s���ӵ���ʼ���֮ǰ
		if ((*L)->next!=NULL)(*L)->next->prev = s;//��ʼ���֮ǰ��s
		(*L)->next = s, s->prev = *L;//ͷ���֮����s��s֮ǰ��ͷ���
	}
}
//β�巨����˫����
//input����������������
void CreateDLinkTail(DLinkList *L, int n, void(*input)(ElemType*))
{
	DLinkList p,s;

	p = *L = (DLinkList)malloc(sizeof(DNode));//����ͷ���
	(*L)->prev = (*L)->next = NULL;//��ʼʱ��Ϊ��

	for (; n > 0; n--)//����n�����
	{
		s = (DLinkList)malloc(sizeof(DNode));//����һ���½��
		input(&s->data);//������½��������������
		s->next = NULL;//��ǰ�����β���
		p->next = s, s->prev = p,p = s;//��s���ӵ���β
	}
}
//����һ���յ�˫������
void CreateEmptyDLinkList(DLinkList *L)
{
	*L = (DLinkList)malloc(sizeof(DNode));//����ͷ���
	(*L)->prev = (*L)->next = NULL;//��ʼʱ��Ϊ��
}
//˫���������
//��˫�����е�i��λ��ǰ����Ԫ��e
//����ֵ��0��������0�쳣
int DLinkListInsert(DLinkList *L, int i, ElemType e)
{
	DLinkList s, p = *L;//pָ��ͷ���

	while (p != NULL&&i > 1)//Ѱ�ҵ�i-1�����
	{
		p = p->next;//pָ��ֱ�Ӻ�̽��
		i--;
	}
	if (p == NULL || i < 1)return 1;//iֵ���Ϸ�
	s = (DLinkList)malloc(sizeof(DNode));//�����½��
	s->data = e;//���Ҫ���������
	s->next = p->next;//�������㷨
	if (p->next != NULL)p->next->prev = s;
	s->prev = p, p->next = s;

	return 0;//����
}
//˫����ɾ�����
//ɾ��˫�����е�i��λ�õĽ�㣬����*ep������ֵ
//����ֵ��0��������0�쳣
int DLinkListDelete(DLinkList *L, int i, ElemType *ep)
{
	DLinkList p = NULL, q = *L;		//qָ��ͷ���

	while (q!=NULL&&i>=1)//�ҵ���i�����
	{
		p = q;			//p��q��ǰ��
		q = q->next;	//qָ��ֱ�Ӻ�̽ڵ�
		i--;
	}
	if (p == NULL || q == NULL)return 1;//iֵ���Ϸ�
	p->next = q->next;		//���ɾ���㷨
	if (q->next != NULL)q->next->prev = p;
	if (ep != NULL)*ep = q->data;//ɾ�������*ep������ֵ
	free(q);

	return 0;//����
}

