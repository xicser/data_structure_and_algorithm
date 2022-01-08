#ifndef __STACK_H__
#define __STACK_H__

#define STACK_INIT_SIZE 100//˳��ջ����Ԫ�ش洢�ռ�ĳ�ʼ������
#define STACK_INCREASE  10 //˳��ջ����Ԫ�ش洢�ռ�ķ�������

//ջԪ�����Ͷ���
typedef int ElemType;

//˳��ջ���Ͷ���
typedef struct
{
	ElemType *top;		//ջ��ָ��
	ElemType *base;		//����Ԫ�ش洢�ռ����ַ
	int size;			//��ǰ�洢�ռ���������sizeof(ElemType)Ϊ��λ��ջ���ܴﵽ����󳤶ȣ�
}Stack;//StackΪ�ṹ������

int  InitStack(Stack *S);//����һ����ջS
void DestroyStack(Stack *S);//����ջS���ͷ�ռ�õ��ڴ棩
void ClearStack(Stack *S);//��S��Ϊ��ջ
int  StackEmpty(Stack S);//���S�Ƿ�Ϊ��ջ
int  StackLength(Stack S);//����ջS�е�����Ԫ�ظ�������ջ�ĳ���
int  GetTop(Stack S, ElemType *e);//��e����S��ջ��Ԫ��
int  Push(Stack *S, ElemType e);//ѹջ
int  Pop(Stack *S, ElemType *e);//��ջ
void StackTraverse(Stack S, void(*visit)(ElemType *));//����ջ�е�Ԫ��

#endif
