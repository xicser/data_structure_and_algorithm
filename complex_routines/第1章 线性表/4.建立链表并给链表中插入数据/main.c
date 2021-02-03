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
STATUS C_ListInsert(LinkList L, int i, C_ElemType e);
void   C_ListSelectSort2(LinkList head);


int main(void)
{
    C_ElemType ele6;
    LinkList L;

    //��������
    C_ListCreateTail(&L,5);

    //���벢�������������
    scanf("%d %f",&(ele6.JobNum),&(ele6.Salary));
    C_ListInsert(L,6,ele6);

    //����������
    C_ListSelectSort2(L);

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
//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
STATUS C_ListInsert(LinkList L, int i, C_ElemType e)
{
	LinkList p = L,s;
	int j = 0;

	while (p&&j < i - 1)//Ѱ�ҵ�i-1�����
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)return ERR1;//iС��1���ߴ��ڱ�+1
	s = (LinkList)malloc(sizeof(Node));//�����½��
	s->data = e; s->next = p->next;//����L��
	p->next = s;

	return FUN_OK;//�ɹ�
}
//ȡ�ô�ָ��p��ʼ�������м�¼����Сֵ
static LinkList getminkey(LinkList p)
{
	LinkList minp;
	minp = p;
	while (p->next){
		if ((minp->data.JobNum)>(p->next->data.JobNum)){
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
	int temp1;
	float temp2;
	for (; i->next != NULL; i = i->next){
		j = getminkey(i);
		if (i->data.JobNum != j->data.JobNum){
			temp1 = i->data.JobNum;
            temp2 = i->data.Salary;

			i->data.JobNum = j->data.JobNum;
            i->data.Salary = j->data.Salary;

			j->data.JobNum = temp1;
            j->data.Salary = temp2;
		}
	}
}
//101 580.50
//103 1000.08
//105 888.88
//107 1888.88
//109 518.23
//106 1988.00
