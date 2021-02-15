
/*

����������ʽ�洢ʵ��

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <queue>
#include "linkTree.h"


// ������� �ݹ������������н���ֵ, '^'�ַ���ʾ����
// ������������ʾ�Ķ�����T
void CreateBiTreeRecursion(BiTree &T)
{
	TElemType ch = getchar();
	fflush(stdin);
	if (ch == '^') {
        T = NULL;//��������֤��Ҷ�ӽ�㣬�ݹ��������
        return;
	}

	//���ɽ��
    T = (BiTNode *)malloc(sizeof(BiTNode));
    if (T == NULL) {
        return;
    }
    T->data = ch;

    //����������
    printf("����������:\n");
    CreateBiTreeRecursion(T->lchild);

    //����������
    printf("����������:\n");
    CreateBiTreeRecursion(T->rchild);
}

//�ݹ��������
//TΪָ�������������ָ��
//level����ָʾԪ������һ��
void PreOrderTraverseRecursion(BiTree T, int level)
{
	if (T == NULL)return;//�ݹ�����������ﵽ��Ҷ�ӽ��

	printf("%c�ڵ�%d��\n", T->data, level);//���ʸ����
	level++;
	PreOrderTraverseRecursion(T->lchild, level);//����������
	PreOrderTraverseRecursion(T->rchild, level);//����������
}

//�ݹ��������
//TΪָ�������������ָ��
void InOrderTraverseRecursion(BiTree T)
{
	if (T == NULL)return;//�ݹ�����������ﵽ��Ҷ�ӽ��

	InOrderTraverseRecursion(T->lchild);//����������
	printf("%c ", T->data);//���ʸ����
	InOrderTraverseRecursion(T->rchild);//����������
}

//�ݹ�������
//TΪָ�������������ָ��
void PostOrderTraverseRecursion(BiTree T)//�������
{
	if (T == NULL)return;//�ݹ�����������ﵽ��Ҷ�ӽ��

	PostOrderTraverseRecursion(T->lchild);//����������
	PostOrderTraverseRecursion(T->rchild);//����������
	printf("%c ", T->data);//���ʸ����
}

//�ǵݹ��������
//pTreeΪָ�������ָ��
void PreOrderTraverse(BiTree pTree)
{
//	stack<> ;
//
//	unsigned int temp;
//
//	BiTree pCur = pTree;//ָ��ǰ���ʽ���ָ��
//
//	//ֱ����ǰ�ڵ�pCurΪNULL��ջ��ʱ��ѭ������
//	while (pCur || !StackEmpty(stack))
//	{
//		//�Ӹ��ڵ㿪ʼ�������ǰ�ڵ㣬��������ջ
//		//ͬʱ��������Ϊ��ǰ�ڵ㣬ֱ����û�����ӣ�����ǰ�ڵ�ΪNULL
//		printf("%c ", pCur->data);//��ӡ���
//		Push(&stack, (unsigned int)pCur);//ѹջ
//		pCur = pCur->lchild;
//		//�����ǰ�ڵ�pCurΪNULL��ջ���գ���ջ���ڵ��ջ
//		//ͬʱ�����Һ���Ϊ��ǰ�ڵ�,ѭ���жϣ�ֱ��pCur��Ϊ��
//		while (!pCur && !StackEmpty(stack))
//		{
//			Pop(&stack, &temp);//��ջ
//			pCur = (BiTree)temp;
//			pCur = pCur->rchild;
//		}
//	}
}

//�ǵݹ��������
//pTreeΪָ�������ָ��
void InOrderTraverse(BiTree pTree)
{
//	stack<unsigned int> st;
//	unsigned int temp;
//	BiTree pCur = pTree; //ָ��ǰ���ʽ���ָ��
//
//	//ֱ����ǰ�ڵ�pCurΪNULL��ջ��ʱ��ѭ������
//	while (pCur || !StackEmpty(stack))
//	{
//		if (pCur->lchild)
//		{
//			//���pCur�����Ӳ�Ϊ�գ�������ջ������������Ϊ��ǰ�ڵ�
//			Push(&stack, (unsigned int)pCur);
//			pCur = pCur->lchild;
//		}
//		else
//		{
//			//���pCur������Ϊ�գ������pCur�ڵ㣬�������Һ�����Ϊ��ǰ�ڵ㣬�����Ƿ�Ϊ��
//			printf("%c ", pCur->data);
//			pCur = pCur->rchild;
//			//���Ϊ�գ���ջ���գ���ջ���ڵ��ջ��������ýڵ㣬
//			//ͬʱ�������Һ�����Ϊ��ǰ�ڵ㣬�����жϣ�ֱ����ǰ�ڵ㲻Ϊ��
//			while (!pCur && !StackEmpty(stack))
//			{
//				Pop(&stack, &temp);
//				pCur = (BiTree)temp;
//				printf("%c ", pCur->data);
//				pCur = pCur->rchild;
//			}
//		}
//	}
}

//�ǵݹ�������
//pTreeΪָ�������ָ��
void PostOrderTraverse(BiTree pTree)
{
//	Stack stack;
//	InitStack(&stack);//����һ����ջ
//	unsigned int temp;
//
//	BiTree pCur;              //����ָ�룬ָ��ǰ�ڵ�
//	BiTree pPre = NULL;       //����ָ�룬ָ����һ�����ʵĽڵ�
//
//	//�Ƚ����ĸ��ڵ���ջ
//	Push(&stack, (unsigned int)pTree);
//	//ֱ��ջ��ʱ������ѭ��
//	while (!StackEmpty(stack))
//	{
//		GetTop(stack, &temp);//��ǰ�ڵ���Ϊջ���ڵ�
//		pCur = (BiTree)temp;
//		if ((pCur->lchild == NULL && pCur->rchild == NULL) ||
//			(pPre != NULL && (pCur->lchild == pPre || pCur->rchild == pPre)))
//		{
//			//�����ǰ�ڵ�û�����Һ��ӣ����������ӻ��к��ӣ����Ѿ������������
//			//��ֱ������ýڵ㣬�����ջ��������Ϊ��һ�����ʵĽڵ�
//			printf("%c ", pCur->data);
//			Pop(&stack, &temp);
//			pPre = pCur;
//		}
//		else
//		{
//			//��������������������,�����Һ�������������ջ
//			if (pCur->rchild != NULL)
//				Push(&stack, (unsigned int)(pCur->rchild));
//			if (pCur->lchild != NULL)
//				Push(&stack, (unsigned int)(pCur->lchild));
//		}
//	}
//
//	//����ջ
//	DestroyStack(&stack);
}

//�������
//pTreeΪָ�������ָ��
/*
* 1�����������ĸ���������
* 2������ͷԪ�س�����
* 3��������ͷԪ�ص��������ĸ���㣨�ǿգ��������ĸ���㣨�ǿգ��ֱ������
* 4���ظ�2��3��ֱ��������û��Ԫ��
*/
void LevelOrderTraverse(BiTree pTree)
{
//	unsigned int temp;
//	Queue que;
//	BiTree pCur;
//
//	InitQueue(&que);//����һ������
//
//	EnQueue(&que, (unsigned int)pTree);//��������
//	while (!QueueEmpty(que))//�����зǿ�
//	{
//		DeQueue(&que, &temp);//��ͷԪ�س�����
//		pCur = (BiTree)temp;
//		printf("%c ", pCur->data);
//		if (pCur->lchild)
//			EnQueue(&que, (unsigned int)(pCur->lchild));
//		if (pCur->rchild)
//			EnQueue(&que, (unsigned int)(pCur->rchild));
//	}
//	//���ٶ���
//	DestroyQueue(&que);
}

