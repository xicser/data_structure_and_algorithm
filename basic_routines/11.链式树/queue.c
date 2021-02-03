

/*
���ζ��е����ʵ��

front=(front+1)%MAX_QSIZE//����ָ���1
rear=(rear+1)%MAX_QSIZE//��βָ���1

*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue.h"


//����һ���ն���
//����ֵ��0�ɹ�����0ʧ��
int InitQueue(Queue *Q)
{
	Q->base = (ElemType*)malloc(MAX_QSIZE * sizeof(ElemType));//Ϊ���з����ڴ�
	if (Q->base == NULL)return 1;//�ڴ�����ʧ��
	Q->front = Q->rear = 0;//��ʼʱ����ͷ��β��ȣ���Ϊ0

	return 0;//�ɹ�
}
//���ٶ���Q
void DestroyQueue(Queue *Q)
{
	if (Q->base)free(Q->base);//�ͷŶ�����ռ�ڴ�ռ�
	Q->base = NULL;//�ÿն�������Ԫ�ش洢�ռ����ַ
	Q->front = Q->rear = 0;
}
//��ն���Q
void ClearQueue(Queue *Q)
{
	Q->front = Q->rear = 0;//���пյı�־
}
//������Q�Ƿ�Ϊ�ն���
//����ֵ����QΪ�ն��У�����TRUE����QΪ�ǿգ�����FALSE
int QueueEmpty(Queue Q)
{
	return Q.front == Q.rear;//��QΪ��ʱ����Q.front == Q.rear����
}
//���ض���Q�ĳ��ȣ���Ԫ�ظ���
int QueueLength(Queue Q)
{
	return Q.rear - Q.front;
}
//��ȡ����Q�Ķ���Ԫ�أ���*e����
//����ֵ��0�ɹ�����0ʧ��
int GetHeadElem(Queue Q, ElemType *e)
{
	if (Q.front == Q.rear)return 1;//����Ϊ��
	if (e != NULL)*e = Q.base[Q.front];
	return 0;//�ɹ�
}
//����
//����Ԫ��eΪQ���¶�βԪ��
//����ֵ��0�ɹ�����0ʧ��
int EnQueue(Queue *Q, ElemType e)
{
	if ((Q->rear + 1) % MAX_QSIZE == Q->front)return 1;//�����������޷��ٲ���
	Q->rear = (Q->rear + 1) % MAX_QSIZE;//��βָ���1
	Q->base[Q->rear] = e;//����e
	return 0;//�����ɹ�
}
//����
//ɾ��Q�Ķ���Ԫ�أ�����*e����
//����ֵ��0�ɹ�����0ʧ��
int DeQueue(Queue *Q, ElemType *e)
{
	if (Q->front == Q->rear)return 1;//����Ϊ�գ��޷�����
	Q->front = (Q->front + 1) % MAX_QSIZE;//����ָ���1
	if (e != NULL)*e = Q->base[Q->front];//��*e������ֵ
	return 0;//�ɹ�
}
//��������Ԫ��
//�Ӷ��׵���β���ζԶ���Q�е�ÿ��Ԫ�ص���visit�������з���
void QueueTraverse(Queue Q, void(*visit)(ElemType *))
{
	int i = Q.front;//�Ӷ��׿�ʼ
	while (i != Q.rear)//ֱ����β����
	{
		visit(Q.base + i);//����
		i = (i + 1) % MAX_QSIZE;//���׼�1
	}
}
