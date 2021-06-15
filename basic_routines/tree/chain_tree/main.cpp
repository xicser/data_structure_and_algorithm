#include <iostream>
#include <stdlib.h>
#include "linkTree.h"

using namespace std;

int main()
{
	int level = 1;
	BiTree BinaryTree;//����һ����������������ָ��һ������ָ�룩

	printf("�������������ʽ������չ���������Ԫ��ֵ��\n");
	CreateBiTreeRecursion(BinaryTree);//���򴴽�������
	printf("\n");

	//�������
	printf("�ǵݹ�������������\n");
	PreOrderTraverse(BinaryTree);
	printf("\n");
	printf("�ݹ�������������\n");
	PreOrderTraverseRecursion(BinaryTree, level);
	printf("\n\n");

	//�������
	printf("�ǵݹ�������������\n");
	InOrderTraverse(BinaryTree);
	printf("\n");
	printf("�ݹ�������������\n");
	InOrderTraverseRecursion(BinaryTree);
	printf("\n\n");

	//�������
	printf("�ǵݹ������������\n");
	PostOrderTraverse(BinaryTree);
	printf("\n");
	printf("�ݹ������������\n");
	PostOrderTraverseRecursion(BinaryTree);
	printf("\n\n");

	//�������
	printf("�ǵݹ������������\n");
	LevelOrderTraverse(BinaryTree);
	printf("\n\n");

    printf("���������ƣ�\n");
	BiTree cpyTree;
	BiTreeCopyRecursion(BinaryTree, cpyTree);
	printf("�ǵݹ�������������\n");
	PreOrderTraverse(cpyTree);

	printf("\n\n��������ȣ�%d\n", GetDepth(cpyTree));

	printf("\n��������������%d\n", GetNodeCount(cpyTree));

	printf("\n������Ҷ�ӽ�������%d\n", GetLeafNodeCount(cpyTree));

	printf("\n����ȣ�%d\n", getMaxWidthUseMap(cpyTree));

    return 0;
}
