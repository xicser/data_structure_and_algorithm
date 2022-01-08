
/*

2017��12��8�գ�С�������ܶ���

����ѭ����������ʵ�֣�
�����̵��������ͷ���

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "cycle_link_list.h"
#include "sys.h"



//��ʼ��һ��ѭ������
//�������������һ���յ����Ա�L
Status InitList_CL(LinkList *L)
{ 
	*L = (LinkList)malloc(sizeof(LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!*L)return ERR1;//�ڴ�����ʧ��

	(*L)->next = *L; /* ָ����ָ��ͷ��� */

	return OK;//�ɹ�
}
//����ѭ������
//����������������Ա�L
Status DestroyList_CL(LinkList *L)
{
	LinkList q, p = (*L)->next; /* pָ��ʼ��� */
	while (p != *L) /* û����β */
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(*L);//�ͷ�ͷ���
	*L = NULL;//��ֹͷָ������
	return OK;//�ɹ�
}
//�������
//��ʼ���������Ա�L�Ѵ���
//�����������L����Ϊ�ձ�
Status ClearList_CL(LinkList *L)
{
	LinkList q, p = (*L)->next; /* pָ��ʼ��� */
	while (p != *L) /* û����β */
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = *L; /* ͷ���ָ����ָ������ */

	return OK;//�ɹ�
}
//�ж������Ƿ�Ϊ��
//��ʼ���������Ա�L�Ѵ���
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
Status ListEmpty_CL(LinkList L)
{
	return L->next == L;
}
//����������Ԫ�ظ���
//��ʼ������L�Ѵ��ڡ�
//�������������L������Ԫ�ظ���
int ListLength_CL(LinkList L)
{
	int i = 0;//iΪ������
	LinkList p = L->next; /* pָ��ʼ��� */
	while (p != L) /* û����β */
	{
		i++;
		p = p->next;
	}
	return i;
}
//��ȡ�����е�i��Ԫ��
//����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR
Status GetElem_CL(LinkList L, int i, ElemType *e)
{
	int j = 1; /* ��ʼ��,jΪ������ */
	LinkList p = L->next; /* pָ��ʼ��� */

	if (i <= 0 || i>ListLength_CL(L))return ERR1;//i���Ϸ�

	while (j<i)
	{ /* ˳ָ��������,ֱ��pָ���i��Ԫ�� */
		p = p->next;
		j++;
	}
	*e = p->data; /* ȡ��i��Ԫ�� */

	return OK;
}
//����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//������������Ԫ�ز����ڣ��򷵻�ֵΪ0
//��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
int LocateElem_CL(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 0;
	LinkList p = L->next; /* pָ��ʼ��� */
	while (p != L)
	{
		i++;
		if (compare(p->data, e)) /* �����ϵ */
			return i;//����λ��
		p = p->next;
	}
	return 0;//Ԫ�ز�����
}
//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������*pre_e��������ǰ��
//��ʼ���������Ա�L�Ѵ���
//����ֵ��0�ɹ�����0ʧ��
Status PriorElem_CL(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	int len;
	LinkList q, p;

	len = ListLength_CL(L);
	if (len<=1)return ERR1;//��Ϊ�գ����Ϊ1ʱû��ǰ��

	p = L->next;//pָ��ʼ���
	while (p != L)//��������β�����
	{
		q = p->next;//qΪp��ֱ�Ӻ�̽��
		if (q != L && q->data == cur_e && pre_e != NULL)
		{
			*pre_e = p->data;//*pre_e����ǰ��Ԫ��
			return 0;//�ɹ�
		}
		p = q;//pָ��ֱ�Ӻ�̽��
	}
	return ERR2;//ʧ��
}
//��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��
//��ʼ���������Ա�L�Ѵ���
//����ֵ��0�ɹ�����0ʧ��
Status NextElem_CL(LinkList L, ElemType cur_e, ElemType *next_e)
{
	int len;
	LinkList p ;

	len = ListLength_CL(L);
	if (len <= 1)return ERR1;//��Ϊ�գ����Ϊ1ʱû�к��

	p = L->next;//pָ��ʼ���
	while (p != L)
	{
		if (p->data == cur_e)
		{
			if (p->next != L && next_e != NULL)
			{
				*next_e = p->next->data;//*next_e���غ��Ԫ��
				return OK;//�ɹ�
			}
		}
		p = p->next;//pָ��ֱ�Ӻ�̽��
	}
	return ERR2;//û�ҵ�
}
//������
//��L�ĵ�i��λ��֮ǰ����Ԫ��e
Status ListInsert_CL(LinkList *L, int i, ElemType e)
{
	int j = 0;
	LinkList p = (*L), s; /* pָ��ͷ��� */

	if (i <= 0 || i>ListLength_CL(*L) + 1)return ERR1;//i�ĺϷ��Լ��

	while (j<i - 1) /* Ѱ�ҵ�i-1����� */
	{
		p = p->next;
		j++;
	}
	s = (LinkList)malloc(sizeof(LNode)); /* �����½�� */
	if (s == NULL)return ERR2;

	s->data = e; /* ����L�� */
	s->next = p->next;
	p->next = s;

	return OK;
}
//ɾ�����
//ɾ��L�ĵ�i��Ԫ��,����e������ֵ
Status ListDelete_CL(LinkList *L, int i, ElemType *e)
{
	int j = 0;
	LinkList p = (*L), q; /* pָ��ͷ��� */

	if (i <= 0 || i>ListLength_CL(*L))return ERR1;//i�ĺϷ����ж�
		
	while (j<i - 1) /* Ѱ�ҵ�i-1����� */
	{
		p = p->next;
		j++;
	}
	q = p->next; /* qָ���ɾ����� */
	p->next = q->next;
	*e = q->data;
	//if (*L == q) /* ɾ�����Ǳ�βԪ�� */
		//*L = p;
	free(q); /* �ͷŴ�ɾ����� */
	return OK;
}
//��������
//����������L�Ѵ���
//������������ζ�L��ÿ������Ԫ�ص��ú���vi()
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
