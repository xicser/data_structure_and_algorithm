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
void Input(C_ElemType *e);
void Visit(C_ElemType *e);


int main(void)
{
    int n;
    LinkList L;

    scanf("%d",&n);//输入n

    //创建线性表
    C_ListCreateTail(&L,n,Input);

    //遍历线性表（打印输出）
    C_ListTraverse(L,Visit);

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
void Input(C_ElemType *e)
{
    scanf("%d",e);
}
void Visit(C_ElemType *e)
{
    printf("%d ",*e);
}
