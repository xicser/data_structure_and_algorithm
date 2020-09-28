
/*

2017年12月7日，小王持续努力！

链式队列相关实现

说明：

队列是一种先进先出线性表,队列是线性表的特化
也具有线性表的性质分为：顺序队列与链式队列
链式队列与线性表的单链表相似只不过链式队列只
允许从头部进行删除、尾部进行插入.需要为链式队列
创建一个头结点包括两个指针,指向队头的指针(front)
与指向队尾的指针(rear)。当两个指针相等时队列为空

本例程创建的链表带有头结点

*/

#define _CRT_SECURE_NO_WARNINGS//加上这个宏，才能编译通过

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "chainQueue.h"


//初始化队列
void InitQueue(LinkQueue *q)
{
	//初始化队头与队尾的指针都指向头结点
	q->front = q->rear = (QuePtr)malloc(sizeof(QueNode));//生成头结点
	q->front->next = NULL;
}
//将元素e进队
void EnQueue(LinkQueue *q, ElemType e)
{
	QuePtr temp = (QuePtr)malloc(sizeof(QueNode));//创建新结点
	if (temp)
	{
		temp->data = e;
		temp->next = NULL;//下一个结点初始化为NULL
		q->rear->next = temp;
		q->rear = temp;
	}
}
//创建队列
void CreateQueue(LinkQueue *q)
{
	ElemType i,k,len;
	InitQueue(q);//初始化

	printf("请输入队列初始长度：\n");
	scanf("%d",&len);

	printf("请输入%d个要进队的元素：\n", len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &k);
		EnQueue(q, k);//k进队
	}
}
//出队
//队头的结点出队,将出队的结点的元素存入*e
void DeQueue(LinkQueue *q, ElemType *e)
{
	QuePtr temp = q->front->next; //初始化temp为要出队的结点的指针

	//队列为空
	if (q->front == q->rear)return;
	
	//如果要出队的结点为最后一个结点,使q->rear指向头结点防止出现悬空的指针
	if (q->front->next == q->rear)
	{
		q->rear = q->front;
	}

	*e = temp->data;//将出队的数据元素存入*e
	q->front->next = temp->next;//使下一个结点成为队头,如果没有下一个结点则为NULL
	free(temp);
}
//判断队列是否为空
//返回值：队列为空，返回非0；否则返回0
int IsEmpty(LinkQueue *q)
{
	return q->front == q->rear;
}
//返回队列的长度
int GetQueueLength(LinkQueue *q)
{
	QuePtr temp = q->front;//temp指向头结点
	int i = 0;//i为计数器
	while (temp != q->rear)
	{
		++i;
		temp = temp->next;
	}
	return i;
}
//清空队列
//释放队列中所有结点的内存占用，包括头结点
void Clear(LinkQueue *q)
{
	QuePtr temp = q->front->next;//temp指向队列队头结点

	while (temp)//释放除头结点以外的所有结点
	{
		QuePtr tp = temp;
		temp = temp->next;
		free(tp);
	}
	temp = q->front;//temp指向头结点
	q->front = q->rear = NULL;
	free(temp);//释放头结点
}
//打印队列的元素（遍历队列）
void Print(LinkQueue *q)
{
	QuePtr temp = q->front->next;//temp指向队列队头结点

	//队列为空
	if (q->front == q->rear)return;
	
	while (temp != q->rear)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d", temp->data);//打印队尾结点数据
	printf("\n");
}
//返回队头的结点元素存入*e
void TopQueue(LinkQueue *q, ElemType *e)
{
	//队列为空
	if (q->front == q->rear)return;
	*e = q->front->next->data;
}
//返回队尾的结点元素存入*e
void BottomQueue(LinkQueue *q, ElemType *e)
{
	//队列为空
	if (q->front == q->rear)return;
	*e = q->rear->data;
}

