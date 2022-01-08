#ifndef __CHAINQUEUE_H__
#define __CHAINQUEUE_H__

//元素类型定义
typedef int ElemType;

//定义结点
typedef struct tagNode
{
	ElemType		data; //数据域
	struct tagNode *next; //指针域
}QueNode, *QuePtr;

//定义链式队列
typedef struct
{
	QuePtr front;	//指向队头的指针
	QuePtr rear;	//指向队尾的指针
}LinkQueue;


void InitQueue(LinkQueue *q);//初始化队列
void EnQueue(LinkQueue *q, ElemType e);//将元素e进队
void DeQueue(LinkQueue *q, ElemType *e);//出队
void CreateQueue(LinkQueue *q);//创建队列
int  IsEmpty(LinkQueue *q);//判断队列是否为空
int  GetQueueLength(LinkQueue *q);//返回队列的长度
void Clear(LinkQueue *q);//清空队列
void Print(LinkQueue *q);//打印队列的元素（遍历队列）
void TopQueue(LinkQueue *q, ElemType *e);//返回队头的结点元素存入*e
void BottomQueue(LinkQueue *q, ElemType *e);//返回队尾的结点元素存入*e



#endif

