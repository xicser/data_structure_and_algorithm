
/*

2017年12月1日，小王持续奋斗！

问题3：编写C程序，实现在不带头结点的单链表中的插入和删除操作

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef char ElemType;

typedef struct LNode
{
    ElemType data;          //数据域
    struct LNode* next;     //指针域
}LinkList;

//在不带头结点的单链表L中的位置i处插入元素e
void Insert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList *s,*p;

    if(L->data==-1&&L->next==NULL)//单链表为空时插入的结点作为第一个结点
    {
        L->data=e;
        L->next=NULL;
    }
    else
    {
        if(i==1)//在第一个结点前插入的处理
        {
            s=(LinkList*)malloc(sizeof(LinkList));//生成新结点
            s->data=e;
            s->next=L;
            L=s;
        }
        else//在其他结点前插入的处理
        {
            p=L;
            j=1;
            while(p&&j<i-1)//找到插入位置i的前一个结点
            {
                j++;
                p=p->next;
            }
            if(!p||j>i-1){printf("error\n");return;}//位置不合法
            s=(LinkList*)malloc(sizeof(LinkList));//生成新结点
            s->data=e;
            s->next=p->next;
            p->next=s;//在p后面插入s
        }
    }
}
//在不带头结点的单链表L中删除第i个位置的元素
//返回值：新的链表的第一个元素的指针
LinkList *Delete(LinkList *L,int i)
{
    int j;
    LinkList *p,*q;

    if(!L)printf("error\n");//空链表
    if(i==1)//删除的是第一个元素
    {
        p=L;
        L=L->next;
        free(p);
    }
    else//删除其他结点
    {
        j=1;
        p=L;
        while(p->next&&j<i-1)//找到要删除结点的前一个结点
        {
            j++;
            p=p->next;
        }
        if(!p->next||j>i-1){printf("error\n");return NULL;}//位置不合法
        q=p->next;
        p->next=q->next;//删除结点q
        free(q);
    }

    return L;
}
//输出单链表
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
    L=(LinkList*)malloc(sizeof(LinkList));//生成开始结点

    L->data=-1;
    L->next=NULL;//设置空表

    printf("(1)依次插入元素a,b,c,d,e\n");
    Insert(L,1,'a');
    Insert(L,2,'b');
    Insert(L,3,'c');
    Insert(L,4,'d');
    Insert(L,5,'e');

    printf("(2)输出单链表：");
    print(L);

    printf("(3)删除单链表的第1个元素\n");
    L=Delete(L,1);

    printf("(4)输出单链表：");
    print(L);

    free(L);//释放单链表

    return 0;
}






















