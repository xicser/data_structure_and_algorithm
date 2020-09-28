
/*

2017��12��7�գ�С������Ŭ����

��ʽ�������ʵ��

˵����

������һ���Ƚ��ȳ����Ա�,���������Ա���ػ�
Ҳ�������Ա�����ʷ�Ϊ��˳���������ʽ����
��ʽ���������Ա�ĵ���������ֻ������ʽ����ֻ
�����ͷ������ɾ����β�����в���.��ҪΪ��ʽ����
����һ��ͷ����������ָ��,ָ���ͷ��ָ��(front)
��ָ���β��ָ��(rear)��������ָ�����ʱ����Ϊ��

�����̴������������ͷ���

*/

#define _CRT_SECURE_NO_WARNINGS//��������꣬���ܱ���ͨ��

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "chainQueue.h"


//��ʼ������
void InitQueue(LinkQueue *q)
{
	//��ʼ����ͷ���β��ָ�붼ָ��ͷ���
	q->front = q->rear = (QuePtr)malloc(sizeof(QueNode));//����ͷ���
	q->front->next = NULL;
}
//��Ԫ��e����
void EnQueue(LinkQueue *q, ElemType e)
{
	QuePtr temp = (QuePtr)malloc(sizeof(QueNode));//�����½��
	if (temp)
	{
		temp->data = e;
		temp->next = NULL;//��һ������ʼ��ΪNULL
		q->rear->next = temp;
		q->rear = temp;
	}
}
//��������
void CreateQueue(LinkQueue *q)
{
	ElemType i,k,len;
	InitQueue(q);//��ʼ��

	printf("��������г�ʼ���ȣ�\n");
	scanf("%d",&len);

	printf("������%d��Ҫ���ӵ�Ԫ�أ�\n", len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &k);
		EnQueue(q, k);//k����
	}
}
//����
//��ͷ�Ľ�����,�����ӵĽ���Ԫ�ش���*e
void DeQueue(LinkQueue *q, ElemType *e)
{
	QuePtr temp = q->front->next; //��ʼ��tempΪҪ���ӵĽ���ָ��

	//����Ϊ��
	if (q->front == q->rear)return;
	
	//���Ҫ���ӵĽ��Ϊ���һ�����,ʹq->rearָ��ͷ����ֹ�������յ�ָ��
	if (q->front->next == q->rear)
	{
		q->rear = q->front;
	}

	*e = temp->data;//�����ӵ�����Ԫ�ش���*e
	q->front->next = temp->next;//ʹ��һ������Ϊ��ͷ,���û����һ�������ΪNULL
	free(temp);
}
//�ж϶����Ƿ�Ϊ��
//����ֵ������Ϊ�գ����ط�0�����򷵻�0
int IsEmpty(LinkQueue *q)
{
	return q->front == q->rear;
}
//���ض��еĳ���
int GetQueueLength(LinkQueue *q)
{
	QuePtr temp = q->front;//tempָ��ͷ���
	int i = 0;//iΪ������
	while (temp != q->rear)
	{
		++i;
		temp = temp->next;
	}
	return i;
}
//��ն���
//�ͷŶ��������н����ڴ�ռ�ã�����ͷ���
void Clear(LinkQueue *q)
{
	QuePtr temp = q->front->next;//tempָ����ж�ͷ���

	while (temp)//�ͷų�ͷ�����������н��
	{
		QuePtr tp = temp;
		temp = temp->next;
		free(tp);
	}
	temp = q->front;//tempָ��ͷ���
	q->front = q->rear = NULL;
	free(temp);//�ͷ�ͷ���
}
//��ӡ���е�Ԫ�أ��������У�
void Print(LinkQueue *q)
{
	QuePtr temp = q->front->next;//tempָ����ж�ͷ���

	//����Ϊ��
	if (q->front == q->rear)return;
	
	while (temp != q->rear)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d", temp->data);//��ӡ��β�������
	printf("\n");
}
//���ض�ͷ�Ľ��Ԫ�ش���*e
void TopQueue(LinkQueue *q, ElemType *e)
{
	//����Ϊ��
	if (q->front == q->rear)return;
	*e = q->front->next->data;
}
//���ض�β�Ľ��Ԫ�ش���*e
void BottomQueue(LinkQueue *q, ElemType *e)
{
	//����Ϊ��
	if (q->front == q->rear)return;
	*e = q->rear->data;
}

