#include <iostream>
#include <stdlib.h>
#include "linkTree.h"

using namespace std;

int main()
{
	int level = 1;
	BiTree BinaryTree;//定义一个二叉树（本质是指向一个结点的指针）

	printf("请以先序遍历方式输入扩展二叉树结点元素值：\n");
	CreateBiTreeRecursion(BinaryTree);//先序创建二叉树
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

    printf("二叉树复制：\n");
	BiTree cpyTree;
	BiTreeCopyRecursion(BinaryTree, cpyTree);
	printf("非递归先序遍历结果：\n");
	PreOrderTraverse(cpyTree);

	printf("\n\n二叉树深度：%d\n", GetDepth(cpyTree));

	printf("\n二叉树结点个数：%d\n", GetNodeCount(cpyTree));

	printf("\n二叉树叶子结点个数：%d\n", GetLeafNodeCount(cpyTree));

	printf("\n最大宽度：%d\n", getMaxWidthUseMap(cpyTree));

    return 0;
}
