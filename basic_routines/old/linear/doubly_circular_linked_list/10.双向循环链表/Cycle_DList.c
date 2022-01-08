
/*

2017��12��8�գ�С������Ŭ����

˫��ѭ���������������ɵ�˫��ѭ������ û�� ͷ��㡣
���ȴ����ˣ��ָ���free�ˣ�

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Cycle_DList.h"


//��ʼ������
//����26��Ӣ�ĵ��ʵ�˫��ѭ������
Status InitList(DualLinkList *L)
{
	int i;
	DualNode *p, *q;

	*L = (DualLinkList)malloc(sizeof(DualNode));
	if (*L == NULL)return ERROR;//�ڴ�����ʧ��

	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	for (i = 0; i < 26; i++)
	{
		q = (DualLinkList)malloc(sizeof(DualNode));
		if (q == NULL)return ERROR;//�ڴ�����ʧ��

		q->data = 'A' + i;
		q->prior = p;//������
		q->next = p->next;
		p->next = q;

		p = q;
	}
	p->next = (*L)->next;
	(*L)->next->prior = p;

	//�ͷŸտ�ʼ���ɵ�ͷ���
	free(*L);

	//*Lָ��ʼ���
	*L = p->next;

	return OK;
}


