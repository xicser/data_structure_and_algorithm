

/*

2017年12月7日，小王持续奋斗！

带头结点单链表相关实现

*/

#define _CRT_SECURE_NO_WARNINGS//加上这个宏，才能编译通过

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sys.h"
#include "chain_storage.h"


void input(C_ElemType *e)
{
	scanf("%d",e);
}
void visit(C_ElemType *e)
{
	printf("%d ", *e);
}

int main(void)
{
	LinkList L;//建立链表（定义头指针）
	C_ElemType e;
	int elem_num;

	//尾插法建立带头结点的单链表，初始长度为5
	printf("尾插法建立带头结点的单链表...\n");
	printf("请输入元素个数：");
	scanf("%d",&elem_num);
	printf("请依次输入%d个元素：", elem_num);
	C_ListCreateTail(&L, elem_num, input);
	
	printf("遍历输出：");
	C_ListTraverse(L, visit);
	printf("\n");

	printf("线性表长度%d\n", C_ListLength(L));

	printf("在第2个元素之前插入999\n");
	C_ListInsert(&L,2,999);

	printf("遍历输出：");
	C_ListTraverse(L, visit);
	printf("\n");

	printf("删除第4个结点\n");
	C_ListDelete(&L,4,&e);
	printf("被删元素为%d\n", e);
	printf("遍历输出：");
	C_ListTraverse(L, visit);
	printf("\n");

	printf("排序...\n");
	C_ListSelectSort2(L);
	printf("遍历输出：");
	C_ListTraverse(L, visit);
	printf("\n");

	GetMidNode(L, &e);
	printf("中间的元素为：%d\n\n",e);

	system("pause");
	return 0;
}



	
	