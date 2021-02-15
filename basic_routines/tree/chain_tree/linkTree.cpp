
/*

二叉树的链式存储实现

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <queue>
#include "linkTree.h"


// 先序次序 递归地输入二叉树中结点的值, '^'字符表示空树
// 构造二叉链表表示的二叉树T
void CreateBiTreeRecursion(BiTree &T)
{
	TElemType ch = getchar();
	fflush(stdin);
	if (ch == '^') {
        T = NULL;//空树，保证是叶子结点，递归结束条件
        return;
	}

	//生成结点
    T = (BiTNode *)malloc(sizeof(BiTNode));
    if (T == NULL) {
        return;
    }
    T->data = ch;

    //构造左子树
    printf("输入左子树:\n");
    CreateBiTreeRecursion(T->lchild);

    //构造右子树
    printf("输入右子树:\n");
    CreateBiTreeRecursion(T->rchild);
}

//递归先序遍历
//T为指向二叉树根结点的指针
//level用于指示元素在哪一层
void PreOrderTraverseRecursion(BiTree T, int level)
{
	if (T == NULL)return;//递归结束条件：达到了叶子结点

	printf("%c在第%d层\n", T->data, level);//访问根结点
	level++;
	PreOrderTraverseRecursion(T->lchild, level);//遍历左子树
	PreOrderTraverseRecursion(T->rchild, level);//遍历右子树
}

//递归中序遍历
//T为指向二叉树根结点的指针
void InOrderTraverseRecursion(BiTree T)
{
	if (T == NULL)return;//递归结束条件：达到了叶子结点

	InOrderTraverseRecursion(T->lchild);//访问左子树
	printf("%c ", T->data);//访问根结点
	InOrderTraverseRecursion(T->rchild);//访问右子树
}

//递归后序遍历
//T为指向二叉树根结点的指针
void PostOrderTraverseRecursion(BiTree T)//后序遍历
{
	if (T == NULL)return;//递归结束条件：达到了叶子结点

	PostOrderTraverseRecursion(T->lchild);//访问左子树
	PostOrderTraverseRecursion(T->rchild);//访问右子树
	printf("%c ", T->data);//访问根结点
}

//非递归先序遍历
//pTree为指向根结点地指针
void PreOrderTraverse(BiTree pTree)
{
//	stack<> ;
//
//	unsigned int temp;
//
//	BiTree pCur = pTree;//指向当前访问结点的指针
//
//	//直到当前节点pCur为NULL且栈空时，循环结束
//	while (pCur || !StackEmpty(stack))
//	{
//		//从根节点开始，输出当前节点，并将其入栈
//		//同时置其左孩子为当前节点，直至其没有左孩子，即当前节点为NULL
//		printf("%c ", pCur->data);//打印输出
//		Push(&stack, (unsigned int)pCur);//压栈
//		pCur = pCur->lchild;
//		//如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈
//		//同时置其右孩子为当前节点,循环判断，直至pCur不为空
//		while (!pCur && !StackEmpty(stack))
//		{
//			Pop(&stack, &temp);//弹栈
//			pCur = (BiTree)temp;
//			pCur = pCur->rchild;
//		}
//	}
}

//非递归中序遍历
//pTree为指向根结点地指针
void InOrderTraverse(BiTree pTree)
{
//	stack<unsigned int> st;
//	unsigned int temp;
//	BiTree pCur = pTree; //指向当前访问结点的指针
//
//	//直到当前节点pCur为NULL且栈空时，循环结束
//	while (pCur || !StackEmpty(stack))
//	{
//		if (pCur->lchild)
//		{
//			//如果pCur的左孩子不为空，则将其入栈，并置其左孩子为当前节点
//			Push(&stack, (unsigned int)pCur);
//			pCur = pCur->lchild;
//		}
//		else
//		{
//			//如果pCur的左孩子为空，则输出pCur节点，并将其右孩子设为当前节点，看其是否为空
//			printf("%c ", pCur->data);
//			pCur = pCur->rchild;
//			//如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，
//			//同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空
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

//非递归后序遍历
//pTree为指向根结点地指针
void PostOrderTraverse(BiTree pTree)
{
//	Stack stack;
//	InitStack(&stack);//创建一个空栈
//	unsigned int temp;
//
//	BiTree pCur;              //定义指针，指向当前节点
//	BiTree pPre = NULL;       //定义指针，指向上一各访问的节点
//
//	//先将树的根节点入栈
//	Push(&stack, (unsigned int)pTree);
//	//直到栈空时，结束循环
//	while (!StackEmpty(stack))
//	{
//		GetTop(stack, &temp);//当前节点置为栈顶节点
//		pCur = (BiTree)temp;
//		if ((pCur->lchild == NULL && pCur->rchild == NULL) ||
//			(pPre != NULL && (pCur->lchild == pPre || pCur->rchild == pPre)))
//		{
//			//如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，
//			//则直接输出该节点，将其出栈，将其设为上一个访问的节点
//			printf("%c ", pCur->data);
//			Pop(&stack, &temp);
//			pPre = pCur;
//		}
//		else
//		{
//			//如果不满足上面两种情况,则将其右孩子左孩子依次入栈
//			if (pCur->rchild != NULL)
//				Push(&stack, (unsigned int)(pCur->rchild));
//			if (pCur->lchild != NULL)
//				Push(&stack, (unsigned int)(pCur->lchild));
//		}
//	}
//
//	//销毁栈
//	DestroyStack(&stack);
}

//层序遍历
//pTree为指向根结点地指针
/*
* 1、将二叉树的根结点入队列
* 2、将队头元素出队列
* 3、并将队头元素的左子树的根结点（非空）右子树的根结点（非空）分别入队列
* 4、重复2、3，直至队列中没有元素
*/
void LevelOrderTraverse(BiTree pTree)
{
//	unsigned int temp;
//	Queue que;
//	BiTree pCur;
//
//	InitQueue(&que);//创建一个队列
//
//	EnQueue(&que, (unsigned int)pTree);//根结点入队
//	while (!QueueEmpty(que))//若队列非空
//	{
//		DeQueue(&que, &temp);//队头元素出队列
//		pCur = (BiTree)temp;
//		printf("%c ", pCur->data);
//		if (pCur->lchild)
//			EnQueue(&que, (unsigned int)(pCur->lchild));
//		if (pCur->rchild)
//			EnQueue(&que, (unsigned int)(pCur->rchild));
//	}
//	//销毁队列
//	DestroyQueue(&que);
}

