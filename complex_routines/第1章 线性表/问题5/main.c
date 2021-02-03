
/*

2017年12月2日，小王持续奋斗！

问题5：阅读下面的程序段(function1,2,3)，分析并简述它们的功能

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

//声明结点
typedef struct LNode
{
    ElemType data;          //数据域
    struct LNode* next;     //指针域
}LinkList;


/*1.初始化一个空的单链表*/
LinkList* InitList(void)
{
    LinkList* L;
    L=(LinkList*)malloc(sizeof(LinkList));//创建头结点
    L->next=NULL;
    return L;
}
/*12.输出单链表中所有元素的值（遍历）*/
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
10.在L中第i个位置之前插入新的元素e
插入成功返回1，否则返回0
*/
int ListInsert(LinkList *L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*s;

    while(j<i-1&&p!=NULL)//查找第i-1个结点
    {
        j++;
        p=p->next;
    }//此循环执行完成后，如果正常，则p指向第i个结点的前一个结点
    if(p==NULL||j>i-1)return 0;//未找到i-1结点，即i<1或大于表长
    else//找到i-1结点
    {
        s=(LinkList*)malloc(sizeof(LinkList));//生成一个新结点
        s->data=e;
        s->next=p->next;
        p->next=s;//将s插入到第i-1个结点之后

        return 1;
    }
}
void function1(LinkList *ha,LinkList *hb,LinkList **hc)
{//ha,hb是两个带头结点且有序的单链表的头指针，hc是新生成的表，初始为空
    LinkList *pa,*pb,*tc,*s;

    pa=ha->next;pb=hb->next;//初始时，pa,pb分别指向ha,hb的第一个结点
    *hc=(LinkList*)malloc(sizeof(LinkList));
    tc=*hc;//初始时，tc指向hc的头结点

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
LinkList *HC=NULL;//新生成的表hc

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
















