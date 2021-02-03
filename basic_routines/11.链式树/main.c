

/*

二叉链式树，二叉链表

*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkTree.h"

//ABDG##H###CE#I##F##
int main(void)
{
	int level = 1;
	BiTree BinaryTree;//定义一个二叉树（本质是指向一个结点的指针）

	printf("请以先序遍历方式输入扩展二叉树结点元素值：\n");
	CreateBiTreeRecursion(&BinaryTree);//先序创建二叉树
	printf("\n");

	//先序遍历
	printf("非递归先序遍历结果：\n");
	PreOrderTraverse(BinaryTree);
	printf("\n");
	printf("递归先序遍历结果：\n");
	PreOrderTraverseRecursion(BinaryTree, level);
	printf("\n\n");

	//中序遍历
	printf("非递归中序遍历结果：\n");
	InOrderTraverse(BinaryTree);
	printf("\n");
	printf("递归中序遍历结果：\n");
	InOrderTraverseRecursion(BinaryTree);
	printf("\n\n");

	//后序遍历
	printf("非递归后序遍历结果：\n");
	PostOrderTraverse(BinaryTree);
	printf("\n");
	printf("递归后序遍历结果：\n");
	PostOrderTraverseRecursion(BinaryTree);
	printf("\n\n");

	//层序遍历
	printf("非递归层序遍历结果：\n");
	LevelOrderTraverse(BinaryTree);
	printf("\n\n");


	system("pause");
	return 0;
}
