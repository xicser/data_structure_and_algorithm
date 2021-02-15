
/*

静态链表相关实现

*/


#define _CRT_SECURE_NO_WARNINGS//加上这个宏，才能编译通过

#include <stdio.h>
#include <stdlib.h>
#include "StaticLinkList.h"


int main(void)
{
	int num, value, index;
	staticlink L;

	InitLink(L);

	printf("[create]enter num:");
	scanf("%d", &num);
	CreateValue(L, num);
	PrintLink(L);
	printf("长度=%d\n",GetLength(L));

	printf("[insert]enter index:");
	scanf("%d", &index);
	printf("[insert]enter value:");
	scanf("%d", &value);
	InsertNode(L, index, value);
	PrintLink(L);
	printf("长度=%d\n", GetLength(L));

	printf("[delete]enter index:");
	scanf("%d", &index);
	DeleteNode(L, index);
	PrintLink(L);
	printf("长度=%d\n", GetLength(L));

	system("pause");
	return 0;
}



