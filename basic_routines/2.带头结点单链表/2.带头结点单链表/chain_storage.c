
//���Ա� ��ʽ�洢�ṹ����ͷ���ĵ����� �����ʵ��

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "sys.h"
#include "chain_storage.h"


//����һ���ձ�
//������һ��������û�����ݽ�㣩
void C_ListCreateEmpty(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));	//����ͷ��㣬*Lָ��ͷ���
	(*L)->next = NULL;						//��ʼʱΪ�ձ�
}
//�������Ա�
//ͷ�巨 ��������ͷ���ĵ�����
//input����������������
//nΪ���Ա��ʼ����
void C_ListCreateHead(LinkList *L,int n,void(* input)(C_ElemType *))
{
	LinkList s;

	*L = (LinkList)malloc(sizeof(Node));	//����ͷ���
	(*L)->next = NULL;						//��ʼʱΪ�ձ�
	for ( ;n > 0; n--)//������n�����ݽ�������
	{
		s = (LinkList)malloc(sizeof(Node)); //�����½��
		input(&(s->data));					//����input����������
		s->next = (*L)->next;				//��s���ӵ���ʼ���֮ǰ
		(*L)->next = s;						//ͷ���֮��
	}
}
//�������Ա�
//β�巨 ��������ͷ���ĵ�����
//input����������������
//nΪ���Ա��ʼ����
void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *))
{
	LinkList p, s;

	p = *L = (LinkList)malloc(sizeof(Node));//����ͷ��㣬pҲָ��ͷ���
	for (; n > 0; n--)						//����n���������
	{
		s = (LinkList)malloc(sizeof(Node)); //�����½��
		input(&(s->data));					//����input����������
		p->next = s, p = s;					//��s���뵽��ǰ����ĩβ
	}
	p->next = NULL;							//β���
}
//�ж����Ա��Ƿ�Ϊ�ձ�
//��LΪ�գ�����TRUE�����򷵻�FALSE
int C_ListIsEmpty(LinkList L)
{
	return (L->next == NULL);
}
//�������Ա�
//�������Ա��е�ÿ��Ԫ���ҵ��ú���visit������
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*))
{
	LinkList p = L->next;	//p��ʼָ��ʼ���
	while (p != NULL)		//��������β�����
	{
		visit(&(p->data));	//����visit���ʽ��
		p = p->next;		//pָ��ֱ�Ӻ�̽��
	}
}
//�������Ա���
//����L������Ԫ�صĸ���
int C_ListLength(LinkList L)
{
	int cnt = 0;			//������cnt��ʼֵΪ0

	LinkList p = L->next;	//pָ�����Ա��һ��Ԫ��
	while (p!=NULL)			//��������β�����
	{
		cnt++;				//������+1
		p = p->next;		//ָ����һ�����
	}
	return cnt;				//����Ԫ�ظ���
}
//���������Ա�L1��L2����
void C_ListLink(LinkList L1, LinkList *L2)
{
	LinkList q = NULL, p = L1;		//pָ������1��ͷ���
	while (p != NULL)				//��������1��β�����
	{
		q = p;
		p = p->next;		//ָ����һ�����
	}//���ѭ��������qָ��L1β���
	if (q != NULL && (*L2) != NULL)
	{
		q->next = (*L2)->next;		//����1��β���ָ������2�Ŀ�ʼ��㣨��һ��Ԫ�أ�
		free(*L2);					//�ͷ�����2��ͷ���
		*L2 = NULL;
	}
}
//����i��Ԫ�ش���ʱ����ֵ����*e������0�����򷵻ط�0ֵ
//LΪ��ͷ���ĵ������ͷָ��
STATUS C_ListGetElem(LinkList L, int i, C_ElemType *e)
{
	int j;//������
	LinkList p;

	p = L->next; j = 1;//��ʼ����pָ���һ����㣬jΪ������

	//˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪNULL
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)return ERR1;//��i��Ԫ�ز�����
	*e = p->data;//ȡ��i��Ԫ��

	return FUN_OK;//�ɹ�
}
//�������Ա��е�һ������compare()��ϵ��Ԫ�ص�λ��
int C_ListLocateElem(LinkList L, C_ElemType e, int(*compare)(C_ElemType*, C_ElemType*))
{
	int i = 0;

	LinkList p=L->next;		//pָ��ʼ���
	while (p != NULL)		//��������β�����
	{
		i++;
		if (compare(&(p->data),&e))return i;//��ϵ����
		p = p->next;						//ָ��ֱ�Ӻ�̽��
	}

	return 0;//��ϵ�����ڷ���0
}
//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
//����ֵ��0�ɹ�����0ʧ��
STATUS C_ListInsert(LinkList *L, int i, C_ElemType e)
{
	LinkList s, p = *L;//pָ��ͷ���

	while (p != NULL&&i > 1)//Ѱ�ҵ�i-1�����
	{
		p = p->next;//pָ��ֱ�Ӻ�̽��
		i--;
	}
	if (p == NULL || i < 1)return 1;//iֵ���Ϸ�

	s = (LinkList)malloc(sizeof(Node));
	if (s == NULL)return 2;//�ڴ�����ʧ��
	s->data = e;
	s->next = p->next, p->next = s;//������

	return FUN_OK;//�ɹ�
}
//�ڴ�ͷ���ĵ������Ա�L��ɾ����i��Ԫ�أ�����*e������ֵ
STATUS C_ListDelete(LinkList *L, int i, C_ElemType *e)
{
	LinkList p = NULL, q = *L;//qָ��ͷ���

	while (q != NULL && i >= 1)//ֱ����i�����
	{
		p = q;
		q = q->next;
		i--;
	}
	if (p == NULL || q == NULL)return 1;//iֵ���Ϸ�

	p->next = q->next;
	if (e != NULL)*e = q->data;//����ɾ������ֵ
	free(q);

	return FUN_OK;//�ɹ�
}
//�������Ա�L
//�����ٵ�����
void C_ListDestroy(LinkList *L)
{
	LinkList q, p = *L;	//pָ��ͷ���
	while (p != NULL)	//��������β�����
	{
		q = p->next;	//ָ����һ�����
		free(p);		//�ͷŽ��ռ�
		p = q;			//ֱ�Ӻ�̽��
	}
	*L = NULL;			//��Ϊ�ձ�
}
//��L����Ϊ�ձ�
void C_ListClear(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;		//pָ��ʼ���
	while (p != NULL)	//��������β�����
	{
		q = p->next;	//ָ��ֱ�Ӻ�̽��
		free(p);		//�ͷſռ�
		p = q;			//ֱ�Ӻ�̽��
	}
	(*L)->next = NULL;	//��ʼʱΪ�ձ�
}
//ѡ������(�Ӵ�С)
//�����Ա��е�Ԫ������
LinkList C_ListSelectSort1(LinkList head)
{
	LinkList p, other, maxNode;
	int temp;
	if (head == NULL) return head;  //������

	for (p = head; p->next != NULL; p = p->next)
	{
		maxNode = p;
		for (other = p->next; other != NULL; other = other->next)
		{
			if (other->data > maxNode->data)
			{
				maxNode = other;
			}
		}
		if (maxNode != p)
		{
			temp = p->data;
			p->data = maxNode->data;
			maxNode->data = temp;
		}
	}
	return head;
}
//ȡ�ô�ָ��p��ʼ�������м�¼����Сֵ
static LinkList getminkey(LinkList p)
{
	LinkList minp;
	minp = p;
	while (p->next){
		if ((minp->data)>(p->next->data)){
			minp = p->next;//minp�ǽ�Сֵ��ָ��
		}
		p = p->next;
	}
	return minp;//���ؽ�Сֵ��ָ��
}
//ѡ�����򣨴�С����
void C_ListSelectSort2(LinkList head)
{
	LinkList j, i = head->next;
	int temp;
	for (; i->next != NULL; i = i->next){
		j = getminkey(i);
		if (i->data != j->data){
			temp = i->data;
			i->data = j->data;
			j->data = temp;
		}
	}
}
//��ȡ����β���Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int C_ListGetLastElem(LinkList L, C_ElemType *e)
{
	LinkList q = NULL, p = L;//pָ��ͷ���
	while (p != NULL)//��������β�����
	{
		q = p;
		p = p->next;//pָ���̽��
	}//ѭ��ִ�����qָ��β���
	if (q != NULL)
	{
		*e = q->data;
		return 0;//�ɹ�
	}

	return 1;//ʧ��
}
//����������ָ��Ԫ�ص�ǰ��Ԫ��
//��pre_e����cur_e��ǰ��
//����ֵ��0�ɹ�����0ʧ��
int C_ListPriorElem(LinkList L, C_ElemType cur_e, C_ElemType *pre_e)
{
	LinkList q, p = L->next;//pָ��ʼ���
	while (p != NULL)//��������β�����
	{
		q = p->next;//qΪp��ֱ�Ӻ�̽��
		if (q != NULL&&q->data == cur_e&&pre_e != NULL)
		{
			*pre_e = p->data;//*pre_e����ǰ��Ԫ��
			return 0;//�ɹ�
		}
		p = q;//pָ��ֱ�Ӻ�̽��
	}
	return 1;//ʧ��
}
//����������ָ��Ԫ�صĺ��Ԫ��
//��next_e����cur_e�ĺ��
//����ֵ��0�ɹ�����0ʧ��
int C_ListNextElem(LinkList L, C_ElemType cur_e, C_ElemType *next_e)
{
	LinkList p = L->next;//pָ��ʼ���
	while (p != NULL)//��������β�����
	{
		if (p->data == cur_e)
		{
			if (p->next != NULL&&next_e != NULL)
			{
				*next_e = p->next->data;//*next_e���غ��Ԫ��
				return 0;//�ɹ�
			}
		}
		p = p->next;//pָ��ֱ�Ӻ�̽��
	}
	return 1;//������cur_e����0
}
//��ȡ�����м���Ԫ��ֵ
//���ÿ���ָ�뷨���ٻ�ȡ�����м���Ԫ��ֵ
STATUS GetMidNode(LinkList L, C_ElemType *e)
{
	LinkList pFast = L, pSlow = L;//��ʼʱ����ָ�붼ָ��ͷ���

	while (pFast->next != NULL)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
		pFast = pFast->next;
		if (pFast == NULL)break;//��pFastΪ��ʱ�������ٻ�ȥ�ж�pFast->next != NULL��
	}							//��Ϊʹ�ÿ�ָ��ָ��ʱ���ᷢ������������
	*e = pSlow->data;//��ȡ�м�������ֵ

	return FUN_OK;
}
