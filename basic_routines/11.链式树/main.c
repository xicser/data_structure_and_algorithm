

/*

������ʽ������������

*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkTree.h"

//ABDG##H###CE#I##F##
int main(void)
{
	int level = 1;
	BiTree BinaryTree;//����һ����������������ָ��һ������ָ�룩

	printf("�������������ʽ������չ���������Ԫ��ֵ��\n");
	CreateBiTreeRecursion(&BinaryTree);//���򴴽�������
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


	system("pause");
	return 0;
}
