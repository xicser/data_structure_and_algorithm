#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MAX_QSIZE 100//最大队列长度

//元素类型定义
typedef unsigned int ElemType;

//顺序队列类型
typedef struct
{
	ElemType *base; //数据元素存储空间基地址
	int front;		//队首指针，若队列不空，指向队首元素
	int rear;		//队尾指针，若队列不空，指向队尾元素的下一个位置
}Queue;


int  InitQueue(Queue *Q);//构造一个空队列
void DestroyQueue(Queue *Q);//销毁队列Q
void ClearQueue(Queue *Q);//清空队列Q
int  QueueEmpty(Queue Q);//检测队列Q是否为空队列
int  QueueLength(Queue Q);//返回队列Q的长度，即元素个数
int  GetHeadElem(Queue Q, ElemType *e);//获取队列Q的队首元素，用*e返回
int  EnQueue(Queue *Q, ElemType e);//进队
int  DeQueue(Queue *Q, ElemType *e);//出队
void QueueTraverse(Queue Q, void(*visit)(ElemType *));//遍历队列元素

#endif
