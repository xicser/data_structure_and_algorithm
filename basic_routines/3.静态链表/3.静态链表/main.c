
/*

��̬�������ʵ��

*/


#define _CRT_SECURE_NO_WARNINGS//��������꣬���ܱ���ͨ��

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
	printf("����=%d\n",GetLength(L));

	printf("[insert]enter index:");
	scanf("%d", &index);
	printf("[insert]enter value:");
	scanf("%d", &value);
	InsertNode(L, index, value);
	PrintLink(L);
	printf("����=%d\n", GetLength(L));

	printf("[delete]enter index:");
	scanf("%d", &index);
	DeleteNode(L, index);
	PrintLink(L);
	printf("����=%d\n", GetLength(L));

	system("pause");
	return 0;
}



