


/*

线索二叉树相关实现

*/

#include <stdio.h>
#include <stdlib.h>
#include "BiThreadTree.h"


//非递归遍历：中序线索化的二叉树
//T指向 头结点 ，头结点的左链lchild指向根结点
void InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;//定义指向结点的指针

	p = T->lchild;	//p指向根结点
	while (p != T)	//空树或遍历结束时，p==T
	{
		while (p->LTag == Link)p = p->lchild;
		printf("%c ", p->data);//访问其左子树为空的结点

		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c ", p->data);//访问后继结点
		}
		p = p->rchild;
	}
}

//二叉树中序线索化
static void InThreading(BiThrTree p)
{
	BiThrTree pre=0;

	if (p)
	{
		InThreading(p->lchild);	//左子树线索化
		if (!p->lchild){ p->LTag = Thread; p->lchild = pre; }//前驱线索
		if (!pre->rchild){ pre->RTag = Thread; pre->rchild = p; }//后继线索
		pre = p;				//保持pre指向p的前驱
		InThreading(p->rchild); //右子树线索化
	}
}
//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
void InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	BiThrTree pre;

	(*Thrt) = (BiThrTree)malloc(sizeof(BiThrNode));
	if ((*Thrt) == NULL)return;

	(*Thrt)->LTag = Link; (*Thrt)->RTag = Thread;//建立头结点
	(*Thrt)->rchild = (*Thrt);//右指针回指
	if (!T)(*Thrt)->lchild = (*Thrt);//若二叉树为空，则左指针回指
	else
	{
		(*Thrt)->lchild = T; pre = (*Thrt);
		InThreading(T);//中序遍历进行中序线索化
		pre->rchild = (*Thrt); pre->RTag = Thread;//最后一个结点线索化
		(*Thrt)->rchild = pre;
	}
}






