#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MAX_QSIZE 100//�����г���

//Ԫ�����Ͷ���
typedef unsigned int ElemType;

//˳���������
typedef struct
{
	ElemType *base; //����Ԫ�ش洢�ռ����ַ
	int front;		//����ָ�룬�����в��գ�ָ�����Ԫ��
	int rear;		//��βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ��
}Queue;


int  InitQueue(Queue *Q);//����һ���ն���
void DestroyQueue(Queue *Q);//���ٶ���Q
void ClearQueue(Queue *Q);//��ն���Q
int  QueueEmpty(Queue Q);//������Q�Ƿ�Ϊ�ն���
int  QueueLength(Queue Q);//���ض���Q�ĳ��ȣ���Ԫ�ظ���
int  GetHeadElem(Queue Q, ElemType *e);//��ȡ����Q�Ķ���Ԫ�أ���*e����
int  EnQueue(Queue *Q, ElemType e);//����
int  DeQueue(Queue *Q, ElemType *e);//����
void QueueTraverse(Queue Q, void(*visit)(ElemType *));//��������Ԫ��

#endif
