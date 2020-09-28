#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//线性表元素类型
typedef int C_ElemType;

//设计结点Node（线性表的单链表存储结构）
typedef struct tagNode
{
	C_ElemType      data;	//数据域
	struct tagNode *next;	//指针域
}Node;
//指向Node类型的结构体指针LinkList
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

    //创建线性表L1
    scanf("%d",&n);
    C_ListCreateTail(&L1,n,Input);

    //创建线性表L2
    scanf("%d",&m);
    C_ListCreateTail(&L2,m,Input);

    //相连
    C_ListLink(L1,&L2);

    //排序
    C_ListSelectSort(L1);

    //遍历输出
    C_ListTraverse(L1,Visit);

    return 0;
}
//创建线性表
//尾插法 创建带有头结点的单链表
//input函数用于输入数据
//n为线性表初始长度
void C_ListCreateTail(LinkList *L, int n, void(*input)(C_ElemType *))
{
	LinkList p, s;

	p = *L = (LinkList)malloc(sizeof(Node));//创建头结点
	for (; n > 0; n--)						//创建n个结点链表
	{
		s = (LinkList)malloc(sizeof(Node)); //创建新结点
		input(&(s->data));					//调用input输入数据域
		p->next = s, p = s;					//将s插入到当前链表末尾
	}
	p->next = NULL;							//尾结点
}
//将两个线性表L1，L2相连
void C_ListLink(LinkList L1, LinkList *L2)
{
	LinkList q = NULL, p = L1;		//p指向链表1的头结点
	while (p != NULL)				//若是链表1链尾则结束
	{
		q = p;
		p = p->next;		//指向下一个结点
	}
	if (q != NULL && (*L2) != NULL)
	{
		q->next = (*L2)->next;		//链表1的尾结点指向链表2的开始结点（第一个元素）
		free(*L2);					//释放链表2的头结点
		*L2 = NULL;
	}
}
//遍历线性表
//遍历线性表中的每个元素且调用函数visit访问它
void C_ListTraverse(LinkList L, void(*visit)(C_ElemType*))
{
	LinkList p = L->next;	//p初始指向开始结点
	while (p != NULL)		//若不是链尾则继续
	{
	    //if(p->next==NULL)printf("%d",p->data);
		visit(&(p->data));	//调用visit访问结点
		//else printf("%d\n",p->data);

		p = p->next;		//p指向直接后继结点
	}
}
LinkList LinkSort(LinkList head) //选择排序法(从大到小)
{
    LinkList p,other,maxNode;
    int temp;
    if(head == NULL) return head;  //空链表

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
//取得从指针p开始的链表中记录的最小值
LinkList getminkey(LinkList p){
    LinkList minp;
    minp = p;
    while(p->next){
        if((minp->data)>(p->next->data)){
           minp = p->next;//minp是较小值的指针
            }
        p = p->next;
        }
    return minp;//返回较小值的指针
    }
//选择排序
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
