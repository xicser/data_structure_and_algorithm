#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//线性表元素类型
typedef struct
{
    int     JobNum;//工号
    float   Salary;//薪水
    //工资
}C_ElemType;

//设计结点Node（线性表的单链表存储结构）
typedef struct tagNode
{
	C_ElemType      data;	//数据域
	struct tagNode *next;	//指针域
}Node;
//指向Node类型的结构体指针LinkList
typedef Node* LinkList;

void C_ListCreateTail(LinkList *L, int n);
void C_ListTraverse(LinkList L);


int main()
{
    LinkList L;

    //输入数据
    C_ListCreateTail(&L,5);

    //输出数据
    C_ListTraverse(L);

    return 0;
}
//创建线性表
//尾插法 创建带有头结点的单链表
//input函数用于输入数据
//n为线性表初始长度
void C_ListCreateTail(LinkList *L, int n)
{
	LinkList p, s;

	p = *L = (LinkList)malloc(sizeof(Node));//创建头结点
	for (; n > 0; n--)						//创建n个结点链表
	{
		s = (LinkList)malloc(sizeof(Node)); //创建新结点

		scanf("%d %f",&(s->data.JobNum),&(s->data.Salary));

		p->next = s, p = s;					//将s插入到当前链表末尾
	}
	p->next = NULL;							//尾结点
}
//遍历线性表
//遍历线性表中的每个元素且调用函数visit访问它
void C_ListTraverse(LinkList L)
{
	LinkList p = L->next;	//p初始指向开始结点
	while (p != NULL)		//若不是链尾则继续
	{
	    //if(p->next==NULL)printf("%d",p->data);
		//visit(&(p->data));	//调用visit访问结点
		//else printf("%d\n",p->data);
		printf("%d\n%.2f\n",p->data.JobNum,p->data.Salary);

		p = p->next;		//p指向直接后继结点
	}
}
