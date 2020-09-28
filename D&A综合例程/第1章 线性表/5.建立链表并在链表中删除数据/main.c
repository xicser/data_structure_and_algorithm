#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//����ִ��״̬ö��
typedef enum {
	FUN_OK = 0,				/* (0) Succeeded */
	ERR1,					/* (1) ������1   */
	ERR2,					/* (2) ������2   */
	ERR3,					/* (3) ������3   */
	ERR4,					/* (4) ������4   */
	ERR5,					/* (5) ������5   */
} STATUS;

//���Ա�Ԫ������
typedef struct
{
    int     JobNum;//����
    float   Salary;//нˮ
    //����
}C_ElemType;

//��ƽ��Node�����Ա�ĵ�����洢�ṹ��
typedef struct tagNode
{
	C_ElemType      data;	//������
	struct tagNode *next;	//ָ����
}Node;
//ָ��Node���͵Ľṹ��ָ��LinkList
typedef Node* LinkList;

void   C_ListCreateTail(LinkList *L, int n);
void   C_ListTraverse(LinkList L);
int    C_ListLocateElem(LinkList L, C_ElemType e);
STATUS C_ListDelete(LinkList L, int i, C_ElemType *e);


int main(void)
{
    LinkList L;
    int i;
    C_ElemType ele_del,ret;

    //�������Ա�ͬʱ��������
    C_ListCreateTail(&L,5);

    //����Ҫɾ����Ա�Ĺ���
    scanf("%d",&(ele_del.JobNum));

    //ȷ���ù��ŵ�λ���Ƕ���
    i=C_ListLocateElem(L,ele_del);

    //ɾ���ý��
    C_ListDelete(L,i,&ret);

    //�������
    C_ListTraverse(L);

    return 0;
}
//�������Ա�
//β�巨 ��������ͷ���ĵ�����
//input����������������
//nΪ���Ա��ʼ����
void C_ListCreateTail(LinkList *L, int n)
{
	LinkList p, s;

	p = *L = (LinkList)malloc(sizeof(Node));//����ͷ���
	for (; n > 0; n--)						//����n���������
	{
		s = (LinkList)malloc(sizeof(Node)); //�����½��

		scanf("%d %f",&(s->data.JobNum),&(s->data.Salary));

		p->next = s, p = s;					//��s���뵽��ǰ����ĩβ
	}
	p->next = NULL;							//β���
}
//�������Ա�
//�������Ա��е�ÿ��Ԫ���ҵ��ú���visit������
void C_ListTraverse(LinkList L)
{
	LinkList p = L->next;	//p��ʼָ��ʼ���
	while (p != NULL)		//��������β�����
	{
	    //if(p->next==NULL)printf("%d",p->data);
		//visit(&(p->data));	//����visit���ʽ��
		//else printf("%d\n",p->data);
		printf("%d\n%.2f\n",p->data.JobNum,p->data.Salary);

		p = p->next;		//pָ��ֱ�Ӻ�̽��
	}
}
//�ڴ�ͷ���ĵ������Ա�L��ɾ����i��Ԫ�أ�����*e������ֵ
STATUS C_ListDelete(LinkList L, int i, C_ElemType *e)
{
	LinkList p = L,q;
	int j = 0;

	while (p->next&&j < i - 1)//Ѱ�ҵ�i����㣬����pָ����ǰ��
	{
		p = p->next; j++;
	}
	if (!(p->next) || j>i - 1)return ERR1;//ɾ��λ�ò�����

	q = p->next; p->next = q->next;//ɾ�����ͷŽ��


	(*e).JobNum = q->data.JobNum;
	(*e).Salary = q->data.Salary;



	free(q);

	return FUN_OK;//�ɹ�
}
//�������Ա��е�һ����e����compare()��ϵ��Ԫ�ص�λ��
int C_ListLocateElem(LinkList L, C_ElemType e)
{
	int i = 0;

	LinkList p=L->next;		//pָ��ʼ���
	while (p != NULL)		//��������β�����
	{
		i++;
		if (p->data.JobNum==e.JobNum)return i;
		p = p->next;//ָ��ֱ�Ӻ�̽��
	}

	return 0;//��ϵ�����ڷ���0
}
//101 580.50
//103 1000.08
//105 888.88
//107 1888.88
//109 518.23
