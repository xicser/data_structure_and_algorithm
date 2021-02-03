
/*

2017��12��1�գ�С�������ܶ���

����3����дC����ʵ���ڲ���ͷ���ĵ������еĲ����ɾ������

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef char ElemType;

typedef struct LNode
{
    ElemType data;          //������
    struct LNode* next;     //ָ����
}LinkList;

//�ڲ���ͷ���ĵ�����L�е�λ��i������Ԫ��e
void Insert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList *s,*p;

    if(L->data==-1&&L->next==NULL)//������Ϊ��ʱ����Ľ����Ϊ��һ�����
    {
        L->data=e;
        L->next=NULL;
    }
    else
    {
        if(i==1)//�ڵ�һ�����ǰ����Ĵ���
        {
            s=(LinkList*)malloc(sizeof(LinkList));//�����½��
            s->data=e;
            s->next=L;
            L=s;
        }
        else//���������ǰ����Ĵ���
        {
            p=L;
            j=1;
            while(p&&j<i-1)//�ҵ�����λ��i��ǰһ�����
            {
                j++;
                p=p->next;
            }
            if(!p||j>i-1){printf("error\n");return;}//λ�ò��Ϸ�
            s=(LinkList*)malloc(sizeof(LinkList));//�����½��
            s->data=e;
            s->next=p->next;
            p->next=s;//��p�������s
        }
    }
}
//�ڲ���ͷ���ĵ�����L��ɾ����i��λ�õ�Ԫ��
//����ֵ���µ�����ĵ�һ��Ԫ�ص�ָ��
LinkList *Delete(LinkList *L,int i)
{
    int j;
    LinkList *p,*q;

    if(!L)printf("error\n");//������
    if(i==1)//ɾ�����ǵ�һ��Ԫ��
    {
        p=L;
        L=L->next;
        free(p);
    }
    else//ɾ���������
    {
        j=1;
        p=L;
        while(p->next&&j<i-1)//�ҵ�Ҫɾ������ǰһ�����
        {
            j++;
            p=p->next;
        }
        if(!p->next||j>i-1){printf("error\n");return NULL;}//λ�ò��Ϸ�
        q=p->next;
        p->next=q->next;//ɾ�����q
        free(q);
    }

    return L;
}
//���������
void print(LinkList *L)
{
    LinkList *p;
    p=L;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(void)
{
    LinkList *L;
    L=(LinkList*)malloc(sizeof(LinkList));//���ɿ�ʼ���

    L->data=-1;
    L->next=NULL;//���ÿձ�

    printf("(1)���β���Ԫ��a,b,c,d,e\n");
    Insert(L,1,'a');
    Insert(L,2,'b');
    Insert(L,3,'c');
    Insert(L,4,'d');
    Insert(L,5,'e');

    printf("(2)���������");
    print(L);

    printf("(3)ɾ��������ĵ�1��Ԫ��\n");
    L=Delete(L,1);

    printf("(4)���������");
    print(L);

    free(L);//�ͷŵ�����

    return 0;
}






















