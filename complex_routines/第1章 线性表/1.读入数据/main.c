#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//���Ա�Ԫ������
typedef int C_ElemType;

//��ƽ��Node�����Ա�ĵ�����洢�ṹ��
typedef struct tagNode
{
	C_ElemType      data;	//������
	struct tagNode *next;	//ָ����
}Node;
//ָ��Node���͵Ľṹ��ָ��LinkList
typedef Node* LinkList;

void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *));
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*));
void Input(C_ElemType *e);
void Visit(C_ElemType *e);


int main(void)
{
    int n;
    LinkList L;

    scanf("%d",&n);//����n

    //�������Ա�
    C_ListCreateTail(&L,n,Input);

    //�������Ա���ӡ�����
    C_ListTraverse(L,Visit);

    return 0;
}

//�������Ա�
//β�巨 ��������ͷ���ĵ�����
//input����������������
//nΪ���Ա��ʼ����
void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *))
{
	LinkList p, s;

	p = *L = (LinkList)malloc(sizeof(Node));//����ͷ���
	for (; n > 0; n--)						//����n���������
	{
		s = (LinkList)malloc(sizeof(Node)); //�����½��
		input(&(s->data));					//����input����������
		p->next = s, p = s;					//��s���뵽��ǰ����ĩβ
	}
	p->next = NULL;							//β���
}
//�������Ա�
//�������Ա��е�ÿ��Ԫ���ҵ��ú���visit������
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*))
{
	LinkList p = L->next;	//p��ʼָ��ʼ���
	while (p != NULL)		//��������β�����
	{
	    //if(p->next==NULL)printf("%d",p->data);
		visit(&(p->data));	//����visit���ʽ��
		//else printf("%d\n",p->data);

		p = p->next;		//pָ��ֱ�Ӻ�̽��
	}
}
void Input(C_ElemType *e)
{
    scanf("%d",e);
}
void Visit(C_ElemType *e)
{
    printf("%d ",*e);
}
