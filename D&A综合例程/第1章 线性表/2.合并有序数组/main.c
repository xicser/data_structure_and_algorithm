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
void C_ListLink(LinkList L1, LinkList *L2);
void C_ListSelectSort(LinkList head);
void Input(C_ElemType *e);
void Visit(C_ElemType *e);

int main()
{
    int m,n;
    LinkList L1,L2;

    //�������Ա�L1
    scanf("%d",&n);
    C_ListCreateTail(&L1,n,Input);

    //�������Ա�L2
    scanf("%d",&m);
    C_ListCreateTail(&L2,m,Input);

    //����
    C_ListLink(L1,&L2);

    //����
    C_ListSelectSort(L1);

    //�������
    C_ListTraverse(L1,Visit);

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
//���������Ա�L1��L2����
void C_ListLink(LinkList L1, LinkList *L2)
{
	LinkList q = NULL, p = L1;		//pָ������1��ͷ���
	while (p != NULL)				//��������1��β�����
	{
		q = p;
		p = p->next;		//ָ����һ�����
	}
	if (q != NULL && (*L2) != NULL)
	{
		q->next = (*L2)->next;		//����1��β���ָ������2�Ŀ�ʼ��㣨��һ��Ԫ�أ�
		free(*L2);					//�ͷ�����2��ͷ���
		*L2 = NULL;
	}
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
LinkList LinkSort(LinkList head) //ѡ������(�Ӵ�С)
{
    LinkList p,other,maxNode;
    int temp;
    if(head == NULL) return head;  //������

    for(p = head; p->next != NULL; p = p->next)
    {
        maxNode=p;
        for(other = p->next; other != NULL; other = other->next)
        {
            if(other->data > maxNode->data)
            {
                maxNode = other;
            }
        }
        if(maxNode != p)
        {
            temp = p->data;
            p->data = maxNode->data;
            maxNode->data = temp;
        }
    }
    return head;
}
void Input(C_ElemType *e)
{
    scanf("%d",e);
}
void Visit(C_ElemType *e)
{
    printf("%d\n",*e);
}
//ȡ�ô�ָ��p��ʼ�������м�¼����Сֵ
LinkList getminkey(LinkList p){
    LinkList minp;
    minp = p;
    while(p->next){
        if((minp->data)>(p->next->data)){
           minp = p->next;//minp�ǽ�Сֵ��ָ��
            }
        p = p->next;
        }
    return minp;//���ؽ�Сֵ��ָ��
    }
//ѡ������
void C_ListSelectSort(LinkList head){
      LinkList j,i=head->next;
      int temp;
      for(;i->next!=NULL;i = i->next){
          j=getminkey(i);
          if(i->data != j->data){
               temp = i->data;
               i->data = j->data;
               j->data = temp;
              }
          }
}
