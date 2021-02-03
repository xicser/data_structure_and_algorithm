#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//函数执行状态枚举
typedef enum {
	FUN_OK = 0,				/* (0) Succeeded */
	ERR1,					/* (1) 错误码1   */
	ERR2,					/* (2) 错误码2   */
	ERR3,					/* (3) 错误码3   */
	ERR4,					/* (4) 错误码4   */
	ERR5,					/* (5) 错误码5   */
} STATUS;

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

void   C_ListCreateTail(LinkList *L, int n);
void   C_ListTraverse(LinkList L);
int    C_ListLocateElem(LinkList L, C_ElemType e);
STATUS C_ListDelete(LinkList L, int i, C_ElemType *e);


int main(void)
{
    LinkList L;
    int i;
    C_ElemType ele_del,ret;

    //创建线性表同时输入数据
    C_ListCreateTail(&L,5);

    //输入要删除人员的工号
    scanf("%d",&(ele_del.JobNum));

    //确定该工号的位序是多少
    i=C_ListLocateElem(L,ele_del);

    //删除该结点
    C_ListDelete(L,i,&ret);

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
//在带头结点的单链线性表L中删除第i个元素，并用*e返回其值
STATUS C_ListDelete(LinkList L, int i, C_ElemType *e)
{
	LinkList p = L,q;
	int j = 0;

	while (p->next&&j < i - 1)//寻找第i个结点，并令p指向其前趋
	{
		p = p->next; j++;
	}
	if (!(p->next) || j>i - 1)return ERR1;//删除位置不合理

	q = p->next; p->next = q->next;//删除并释放结点


	(*e).JobNum = q->data.JobNum;
	(*e).Salary = q->data.Salary;



	free(q);

	return FUN_OK;//成功
}
//返回线性表中第一个与e满足compare()关系的元素的位序
int C_ListLocateElem(LinkList L, C_ElemType e)
{
	int i = 0;

	LinkList p=L->next;		//p指向开始结点
	while (p != NULL)		//若不是链尾则继续
	{
		i++;
		if (p->data.JobNum==e.JobNum)return i;
		p = p->next;//指向直接后继结点
	}

	return 0;//关系不存在返回0
}
//101 580.50
//103 1000.08
//105 888.88
//107 1888.88
//109 518.23
