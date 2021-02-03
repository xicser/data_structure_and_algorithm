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
STATUS C_ListInsert(LinkList L, int i, C_ElemType e);
void   C_ListSelectSort2(LinkList head);


int main(void)
{
    C_ElemType ele6;
    LinkList L;

    //输入数据
    C_ListCreateTail(&L,5);

    //输入并插入第六个数据
    scanf("%d %f",&(ele6.JobNum),&(ele6.Salary));
    C_ListInsert(L,6,ele6);

    //按工号排序
    C_ListSelectSort2(L);

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
//在带头结点的单链线性表L中第i个位置之前插入元素e
STATUS C_ListInsert(LinkList L, int i, C_ElemType e)
{
	LinkList p = L,s;
	int j = 0;

	while (p&&j < i - 1)//寻找第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)return ERR1;//i小于1或者大于表长+1
	s = (LinkList)malloc(sizeof(Node));//生成新结点
	s->data = e; s->next = p->next;//插入L中
	p->next = s;

	return FUN_OK;//成功
}
//取得从指针p开始的链表中记录的最小值
static LinkList getminkey(LinkList p)
{
	LinkList minp;
	minp = p;
	while (p->next){
		if ((minp->data.JobNum)>(p->next->data.JobNum)){
			minp = p->next;//minp是较小值的指针
		}
		p = p->next;
	}
	return minp;//返回较小值的指针
}
//选择排序（从小到大）
void C_ListSelectSort2(LinkList head)
{
	LinkList j, i = head->next;
	int temp1;
	float temp2;
	for (; i->next != NULL; i = i->next){
		j = getminkey(i);
		if (i->data.JobNum != j->data.JobNum){
			temp1 = i->data.JobNum;
            temp2 = i->data.Salary;

			i->data.JobNum = j->data.JobNum;
            i->data.Salary = j->data.Salary;

			j->data.JobNum = temp1;
            j->data.Salary = temp2;
		}
	}
}
//101 580.50
//103 1000.08
//105 888.88
//107 1888.88
//109 518.23
//106 1988.00
