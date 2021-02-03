
/*

2017��12��2�գ�С�������ܶ���

����5���Ķ�����ĳ����(function1,2,3)���������������ǵĹ���

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

//�������
typedef struct LNode
{
    ElemType data;          //������
    struct LNode* next;     //ָ����
}LinkList;


/*1.��ʼ��һ���յĵ�����*/
LinkList* InitList(void)
{
    LinkList* L;
    L=(LinkList*)malloc(sizeof(LinkList));//����ͷ���
    L->next=NULL;
    return L;
}
/*12.���������������Ԫ�ص�ֵ��������*/
void ListTraverse(LinkList *L)
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
/*
10.��L�е�i��λ��֮ǰ�����µ�Ԫ��e
����ɹ�����1�����򷵻�0
*/
int ListInsert(LinkList *L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*s;

    while(j<i-1&&p!=NULL)//���ҵ�i-1�����
    {
        j++;
        p=p->next;
    }//��ѭ��ִ����ɺ������������pָ���i������ǰһ�����
    if(p==NULL||j>i-1)return 0;//δ�ҵ�i-1��㣬��i<1����ڱ�
    else//�ҵ�i-1���
    {
        s=(LinkList*)malloc(sizeof(LinkList));//����һ���½��
        s->data=e;
        s->next=p->next;
        p->next=s;//��s���뵽��i-1�����֮��

        return 1;
    }
}
void function1(LinkList *ha,LinkList *hb,LinkList **hc)
{//ha,hb��������ͷ���������ĵ������ͷָ�룬hc�������ɵı���ʼΪ��
    LinkList *pa,*pb,*tc,*s;

    pa=ha->next;pb=hb->next;//��ʼʱ��pa,pb�ֱ�ָ��ha,hb�ĵ�һ�����
    *hc=(LinkList*)malloc(sizeof(LinkList));
    tc=*hc;//��ʼʱ��tcָ��hc��ͷ���

    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            s=(LinkList*)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
            pa=pa->next;
        }
        else if(pa->data>pb->data)
        {
            s=(LinkList*)malloc(sizeof(LinkList));
            s->data=pb->data;
            tc->next=s;
            tc=s;
            pb=pb->next;
        }
        else
        {
            s=(LinkList*)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
            pb=pb->next;
            pa=pa->next;
        }
        if(pb!=NULL)pa=pb;
        while(pa!=NULL)
        {
            s=(LinkList*)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
            pa=pa->next;
        }
        tc->next=NULL;
    }
}

LinkList *ha=NULL;
LinkList *hb=NULL;
LinkList *HC=NULL;//�����ɵı�hc

int main(void)
{
    ha=InitList();
    hb=InitList();
    HC=InitList();

    ListInsert(ha,1,1);
    ListInsert(ha,2,2);
    ListInsert(ha,3,3);
    ListTraverse(ha);

    ListInsert(hb,1,4);
    ListInsert(hb,2,5);
    ListInsert(hb,3,6);
    ListTraverse(hb);

    function1(ha,hb,&HC);
    ListTraverse(HC);


    printf("Hello world!\n");
    return 0;
}
















