
/*

С�������ܶ���

��ʽջ�����ʵ��

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "chainStack.h"


//��ʼ��ջ
void InitStack(Stack* stack)
{
	stack->top /*= stack->base*/ = (Node*)malloc(sizeof(Node));
	stack->top->next = NULL;
}
//���ջ
//�ͷų���topָ����Ǹ����
void Clear(Stack* stack)
{
	Node* pNode, *tmp;

	pNode = stack->top->next;//ָ���һ�����

	//����ջ���ͷ�ÿһ��ڵ��ڴ棨����topָ����Ǹ���㣩
	while (pNode != NULL)
	{
		tmp = pNode;//��¼��Ҫ�ͷŵ��ڴ��ַ
		pNode = pNode->next;//��һ���ڵ�ĵ�ַ
		free((void*)tmp->valueAddr);//�ͷŽ����ϵ�����
		free(tmp);//�ͷŽ��
	}
	stack->top->next = NULL;
}
//����ջ
//�ͷ����н��
void Destroy(Stack* stack)
{
	Clear(stack);//�����ջ���ͷ��ڴ�
	free(stack->top);//�ͷ�topָ����Ǹ����
}
//�ж�ջ�Ƿ�Ϊ��
//ջΪ��ʱ����1���ǿ�ʱ����0
int isEmpty(Stack *stack)
{
    if(stack->top->next==NULL) return 1;
    else return 0;
}
//ѹջ
//float a = 10.3;
//Push(&linkStack, (u32)&a, DATA_FLOAT);
void Push(Stack *stack, u32 valAddr, int valType)
{
    float *tempFloat;
    int *tempInt;

    Node *nodeNew = (Node*)malloc(sizeof(Node));//�����½��
    //����������
    switch(valType) {
        case DATA_FLOAT://������ѹջ
            nodeNew->DataType = DATA_FLOAT;//�������ͱ�ʶ
            tempFloat = (float *)malloc(sizeof(float));
            *tempFloat = *((float *)valAddr);
            nodeNew->valueAddr = (u32)tempFloat;
            break;
        case DATA_INT://����ѹջ
            nodeNew->DataType = DATA_INT;//�������ͱ�ʶ
            tempInt = (int *)malloc(sizeof(int));
            *tempInt = *((int *)valAddr);
            nodeNew->valueAddr = (u32)tempInt;
            break;
        default: break;
    }
	nodeNew->next = stack->top->next;//��ջ�ڵ� nextָ��ԭջ��һ���ڵ�
	stack->top->next = nodeNew;//ջ��topָ�����ջ�ڵ�
}
//��ջ
//���ؽ�����ݵĵ�ַ�����ؽ���������ͱ�ʶ
void Pop(Stack* stack, u32 *valAddr, int *valType)
{
	Node* del = NULL;

	del = stack->top->next;//ջ������ַ
	if (del != NULL)//ջ�ǿ�
	{
		stack->top->next = del->next;//ָ��ڶ����ڵ㣨����ΪNULL��
	}
	*valAddr = del->valueAddr;//���ؽ�����ݵĵ�ַ
	*valType = del->DataType;//���ؽ���������ͱ�ʶ
    //�ͷŽ��
    free(del);
}
//��ȡջ����
int Length(Stack* stack)
{
	int i = 0;//iΪ������
	Node* pNode;

	pNode = stack->top->next;//ָ��ջ�ĵ�һ�����
	while (pNode != NULL)
	{
		i++;
		pNode = pNode->next;
	}
	return i;
}
//��ʾջ�ڵ�����
void NodeDisplay(Node* node)
{
    switch(node->DataType) {
        case DATA_FLOAT://����Ǹ�����
            printf("%.1f   ", *((float *)(node->valueAddr)));
            break;
        case DATA_INT://���������
            printf("%d   ", *((int *)(node->valueAddr)));
            break;
        default: break;
    }
}
//����ջ
void StackTraverse(Stack* stack)
{
	Node* pNode;
	pNode = stack->top->next;//pNodeָ���һ�����

	while (pNode != NULL)
	{
		NodeDisplay(pNode);
		pNode = pNode->next;
	}
}
