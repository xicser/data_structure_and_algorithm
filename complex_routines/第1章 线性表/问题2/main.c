
/*

2017年11月30日，小王持续奋斗！

问题2：编写C程序，实现在带头结点的单链表中的12个基本运算

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char ElemType;

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
/*2.释放单链表L*/
void DestroyList(LinkList* L)
{
    LinkList *p=L,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);//是放最后一个结点
}
/*3.将L置为空表*/
void SetNull(LinkList *L)
{
    L->next=NULL;//纳尼？？？？不会内存泄漏吗！？
}
/*4.若L为空表，则返回TRUE,否则返回FALSE*/
int ListEmpty(LinkList *L)
{
    return (L->next==NULL);
}
/*5.求单链表L中元素的个数并返回之*/
int ListLength(LinkList *L)
{
    LinkList *p=L;
    int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
/*6.返回L中的第i个元素的值若操作失败则返回'F'*/
ElemType GetElem(LinkList *L,int i)
{
    int j=0;
    LinkList *p=L;
    ElemType e;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return 'F';
    else{e=p->data;return e;}
}
/*7.在单链表L中查找指定元素e，并返回它的位序（第一次出现的位序）
若L中没有元素e，则返回0。。。纳尼？如果这个元素就是0该咋办！？
*/
int LocateElem(LinkList *L,ElemType e)
{
    LinkList *p=L->next;//p指向开始结点
    int n=1;

    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        n++;
    }
    if(p==NULL)return 0;
    else return n;
}
/*
8.若cur_e是L中的数据元素且不是第一个，则返回它的前驱元素
否则操作失败返回'F'
操作前提：cur_e是L中的元素！
*/
ElemType PriorElem(LinkList *L,ElemType cur_e)
{
    LinkList *p=L->next;//p指向开始结点
    ElemType pre_e;

    if(p->data==cur_e)return 'F';//第一个元素没有前驱元素
    else
    {
        /*用p->next->data比较，前驱元素是p->data*/
        while(p->next->data!=cur_e)p=p->next;
        pre_e=p->data;
        return pre_e;
    }
}
/*
9.若cur_e是L中的数据元素且不是最后一个，则返回它的后继元素，
否则操作失败返回'F'
操作前提：cur_e是L中的元素！
*/
ElemType NextElem(LinkList *L,ElemType cur_e)
{
    LinkList *p=L->next,*q;
    ElemType next_e;

    if(p==NULL)return 'F';//表空
    else
    {
        while(p->data!=cur_e)p=p->next;
        q=p->next;
        if(q!=NULL)//后继元素存在
        {
            next_e=q->data;//提取后继元素
            return next_e;
        }
        else return 'F';
    }
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
/*
11.删除L中第i个元素，并返回其值
*/
ElemType ListDelete(LinkList *L,int i)
{
    int j=0;
    LinkList *p=L,*q;
    ElemType e;

    while(j<i-1&&p!=NULL)//查找第i-1个结点
    {
        j++;
        p=p->next;
    }//此循环执行完成后，如果正常，则p指向第i个结点的前一个结点
    if(p==NULL||j>i-1)return 'F';//删除位置i不合理
    else//找到了第i-1个结点
    {
        q=p->next;//q指向要删除的结点
        if(q==NULL)return 'F';//被删节点不存在
        e=q->data;
        p->next=q->next;//删除q结点
        free(q);
        return e;//返回被删结点的值
    }
}
/*12.输出单链表中所有元素的值（遍历）*/
void ListTraverse(LinkList *L)
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(void)
{
    ElemType e;
    LinkList *L=NULL;
    printf("(1)初始化单链表L\n");
    L=InitList();
    printf("(2)依次插入元素a,b,c,d,e\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("(3)输出单链表：");
    ListTraverse(L);
    printf("(4)单链表L的长度：%d\n",ListLength(L));
    printf("(5)单链表L为：%s\n",ListEmpty(L)?"空":"非空");
    e=GetElem(L,3);
    printf("(6)单链表L第3个元素：%c\n",e);
    printf("(7)元素a的位置：%d\n",LocateElem(L,'a'));
    e=PriorElem(L,'b');
    printf("(8)元素b的前驱为：%c\n",e);
    e=NextElem(L,'b');
    printf("(9)元素b的后继为：%c\n",e);
    printf("(10)在第四个位置插入f元素，并输出之：");
    ListInsert(L,4,'F');
    ListTraverse(L);
    printf("(11)删除第3个元素，并输出之：");
    e=ListDelete(L,3);
    ListTraverse(L);
    printf("(12)将L重置为空表\n");
    SetNull(L);
    printf("(13)单链表L为：%s\n",ListEmpty(L)?"空":"非空");
    printf("(14)释放单链表L\n");
    DestroyList(L);

    return 0;
}






