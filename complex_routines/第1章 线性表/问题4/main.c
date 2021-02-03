
/*

2017年12月1日，小王持续奋斗！

问题4：编写C程序，实现在 带头结点 的 双向循环链表 中的插入和删除操作

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char ElemType;

//声明双向链表结点
typedef struct DNode
{
    ElemType data;//数据域
    struct DNode *prior;//前驱指针域
    struct DNode *next;//后继指针域
}DLinkList;

DLinkList *L;//定义结构指针类型



//初始化带有头结点的双向循环链表
//返回头指针
DLinkList *InitList(void)
{
    L=(DLinkList*)malloc(sizeof(DLinkList));//生成头结点
    L->prior=L;//循环双向链表
    L->next=L;
    L->data=-1;

    return L;//返回头指针
}
//在带有头结点的双向循环链表L中寻找第i个结点，
//找到返回其指针，找不到返回NULL
DLinkList* getelem(DLinkList *L,int i)
{
    DLinkList *p;
    int n;
    p=L->next;
    n=1;
    if(i<1)return NULL;//i太小
    while(p!=L&&n<i)//搜索链表，找到结点i
    {
        n++;
        p=p->next;
    }
    if(n==i)return p;//找到结点i返回其指针，包括返回头指针
    else return NULL;//i太大
}
//在带头结点的双向循环链表L中的第i个元素之前插入元素e
//i的范围：1<=i<=表长+1
void listinsert(DLinkList *L,int i,ElemType e)
{
    DLinkList *p,*s;

    p=getelem(L,i);//寻找第i个结点，返回其指针
    if(p!=NULL)//找到了第i个结点
    {
        s=(DLinkList*)malloc(sizeof(DLinkList));//生成一个新结点
        s->data=e;//填充新结点的数据
        p->prior->next=s;s->next=p;//添加这个新的结点
        s->prior=p->prior;p->prior=s;
    }
    else//没到第i个结点
    {
        printf("插入位置错误\n");
        return;
    }
}
//在带头结点的双向循环链表L中，删除第i个结点
//i的范围：1<=i<=表长
//返回值：被删结点的数据值
ElemType listdelete(DLinkList *L,int i)
{
    DLinkList *p;
    ElemType e;

    p=getelem(L,i);//寻找第i个结点，返回其指针
    if(p!=L&&p!=NULL)//i合法，找到了
    {
        e=p->data;//删除第i个结点
        p->prior->next=p->next;
        p->next->prior=p->prior;
        free(p);
        return e;//返回被删元素的值
    }
    else{printf("删除结点位置错误\n");return '*';}
}
//输出带有头结点的双向循环链表的各元素值
void print(DLinkList *L)
{
    DLinkList *p;
    p=L->next;//p指向开始结点
    while(p!=L)
    {
        printf("%3c",p->data);
        p=p->next;
    }
    printf("\n");
}
//撤销带头结点的双向循环链表L的空间
void destroylist(DLinkList *L)
{
    DLinkList *p=L,*q=p->next;//p指向头结点，q指向开始结点
    while(q!=NULL)//while(q!=L)？？？？
    {
        free(p);
        p=q;
        q=q->next;
    }
    free(q);
}

int main(void)
{
    ElemType e='a',De;
    int j,a;

    printf("(1)初始化双链表L\n");
    L=InitList();

    printf("(2)依次插入元素a,b,c,d,e\n");
    for(j=0;j<5;e++)listinsert(L,++j,e);

    printf("(3)输出双链表L：");
    print(L);

    printf("(4)请输入删除结点的序号：");
    scanf("%d",&a);
    De=listdelete(L,a);

    printf("(5)删除结点%c后的链表：",De);
    print(L);

    printf("(6)释放双链表\n");
   // destroylist(L);//尼玛？？一释放就出错？！

    return 0;
}















