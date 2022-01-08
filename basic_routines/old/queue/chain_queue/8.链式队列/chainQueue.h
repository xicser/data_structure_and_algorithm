#ifndef __CHAINQUEUE_H__
#define __CHAINQUEUE_H__

//Ԫ�����Ͷ���
typedef int ElemType;

//������
typedef struct tagNode
{
	ElemType		data; //������
	struct tagNode *next; //ָ����
}QueNode, *QuePtr;

//������ʽ����
typedef struct
{
	QuePtr front;	//ָ���ͷ��ָ��
	QuePtr rear;	//ָ���β��ָ��
}LinkQueue;


void InitQueue(LinkQueue *q);//��ʼ������
void EnQueue(LinkQueue *q, ElemType e);//��Ԫ��e����
void DeQueue(LinkQueue *q, ElemType *e);//����
void CreateQueue(LinkQueue *q);//��������
int  IsEmpty(LinkQueue *q);//�ж϶����Ƿ�Ϊ��
int  GetQueueLength(LinkQueue *q);//���ض��еĳ���
void Clear(LinkQueue *q);//��ն���
void Print(LinkQueue *q);//��ӡ���е�Ԫ�أ��������У�
void TopQueue(LinkQueue *q, ElemType *e);//���ض�ͷ�Ľ��Ԫ�ش���*e
void BottomQueue(LinkQueue *q, ElemType *e);//���ض�β�Ľ��Ԫ�ش���*e



#endif

