#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"



//����һ����ջS
//����ֵ��0�ɹ�����0ʧ��
int InitStack(Stack *S)
{
	S->base = (ElemType*)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	if (S->base == NULL)return 1;//ʧ��

	S->top = S->base;//��ʼʱջ��λ��
	S->size = STACK_INIT_SIZE;

	return 0;//�ɹ�
}
//����ջS���ͷ�ռ�õ��ڴ棩
void DestroyStack(Stack *S)
{
	free(S->base);//�ͷ��ڴ�
	S->base = S->top = NULL;
	S->size = 0;
}
//��S��Ϊ��ջ
void ClearStack(Stack *S)
{
	if (S != NULL)S->top = S->base;
}
//���S�Ƿ�Ϊ��ջ
//����ֵ����SΪ��ջ������TRUE����SΪ�ǿ�ջ������FALSE
int StackEmpty(Stack S)
{
	return S.top == S.base;
}
//����ջS�е�����Ԫ�ظ�������ջ�ĳ���
int StackLength(Stack S)
{
	return S.top - S.base;
}
//��e����S��ջ��Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int GetTop(Stack S,ElemType *e)
{
	if (S.top > S.base && e != NULL)//ջ�ǿ�
	{
		*e = *(S.top - 1);//����S��ջ��Ԫ��
		return 0;//�ɹ�
	}
	return 1;//ջΪ�գ�ʧ��
}
//ѹջ,����e��ջ������Ԫ��eΪ�µ�ջ��Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int Push(Stack *S, ElemType e)
{
	if (S->top - S->base >= S->size)//��ջ�ռ�����׷�Ӵ洢�ռ�
	{
		S->base = (ElemType*)realloc(S->base, (S->size + STACK_INCREASE)*sizeof(ElemType));
		if (S->base == NULL)return 1;//�ڴ����·���ʧ��
		S->top = S->base + S->size;//�µ�ջ����ַ
		S->size += STACK_INCREASE;//����ջ���������
	}
	*(S->top)++ = e;//e��ջ

	return 0;
}
//��ջ����ջ��Ϊ�գ�����*e����S��ջ��Ԫ��
//����ֵ��0�ɹ�����0ʧ��
int Pop(Stack *S, ElemType *e)
{
	if (S->top == S->base)return 1;//ջΪ��
	*e = *--(S->top);//��ջ��*e
	return 0;
}
//����ջ�е�Ԫ��
//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit������
void StackTraverse(Stack S, void(*visit)(ElemType *))
{
	while (S.top > S.base)visit(S.base++);
}
