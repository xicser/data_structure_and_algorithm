

/*
环形队列的相关实现

front=(front+1)%MAX_QSIZE//队首指针加1
rear=(rear+1)%MAX_QSIZE//队尾指针加1

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue.h"


//构造一个空队列
//返回值：0成功；非0失败
int InitQueue(Queue *Q)
{
	Q->base = (ElemType*)malloc(MAX_QSIZE * sizeof(ElemType));//为队列分配内存
	if (Q->base == NULL)return 1;//内存申请失败
	Q->front = Q->rear = 0;//初始时，队头队尾相等，且为0

	return 0;//成功
}
//销毁队列Q
void DestroyQueue(Queue *Q)
{
	if (Q->base)free(Q->base);//释放队列所占内存空间
	Q->base = NULL;//置空队列数据元素存储空间基地址
	Q->front = Q->rear = 0;
}
//清空队列Q
void ClearQueue(Queue *Q)
{
	Q->front = Q->rear = 0;//队列空的标志
}
//检测队列Q是否为空队列
//返回值：若Q为空队列，返回TRUE，若Q为非空，返回FALSE
int QueueEmpty(Queue Q)
{
	return Q.front == Q.rear;//当Q为空时，有Q.front == Q.rear成立
}
//返回队列Q的长度，即元素个数
int QueueLength(Queue Q)
{
	return Q.rear - Q.front;
}
//获取队列Q的队首元素，用*e返回
//返回值：0成功；非0失败
int GetHeadElem(Queue Q, ElemType *e)
{
	if (Q.front == Q.rear)return 1;//队列为空
	if (e != NULL)*e = Q.base[Q.front];
	return 0;//成功
}
//进队
//插入元素e为Q的新队尾元素
//返回值：0成功；非0失败
int EnQueue(Queue *Q, ElemType e)
{
	if ((Q->rear + 1) % MAX_QSIZE == Q->front)return 1;//队列已满，无法再插入
	Q->rear = (Q->rear + 1) % MAX_QSIZE;//队尾指针加1
	Q->base[Q->rear] = e;//插入e
	return 0;//操作成功
}
//出队
//删除Q的队首元素，且用*e返回
//返回值：0成功；非0失败
int DeQueue(Queue *Q, ElemType *e)
{
	if (Q->front == Q->rear)return 1;//队列为空，无法出队
	Q->front = (Q->front + 1) % MAX_QSIZE;//队首指针加1
	if (e != NULL)*e = Q->base[Q->front];//用*e返回其值
	return 0;//成功
}
//遍历队列元素
//从队首到队尾依次对队列Q中的每个元素调用visit函数进行访问
void QueueTraverse(Queue Q, void(*visit)(ElemType *))
{
	int i = Q.front;//从队首开始
	while (i != Q.rear)//直到队尾结束
	{
		visit(Q.base + i);//访问
		i = (i + 1) % MAX_QSIZE;//队首加1
	}
}
