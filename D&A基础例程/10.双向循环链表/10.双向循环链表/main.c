
/*

2017年12月8日，小王持续努力！

双向循环链表


问题描述：

要求实现用户输入一个数使得26个字母的排列发生变化，
例如用户输入3，输出结果：

DEFGHIJKLMNOPQRSTUVWXYZABC

输入-3，输出结果为：
XYZABCDEFGHIJKLMNOPQRSTUVW


*/


#define _CRT_SECURE_NO_WARNINGS//加上这个宏，才能编译通过

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Cycle_DList.h"


DualLinkList Caesar(DualLinkList L, int i)
{
	DualLinkList mov = L;//mov指向开始结点

	//i等于几，mov就挪几次
	if (i > 0)
	{
		do
		{
			mov = mov->next;
			i--;
		} while (i);
	}
	else if (i < 0)
	{
		do
		{
			mov = mov->prior;
			i++;
		} while (i);
	}
	return mov;//返回起始打印位置
}

int main(void)
{
	int i, n;
	DualLinkList L, mov;

	InitList(&L);//创建链表，调用后，L指向开始结点

	printf("请输入一个整数：");
	scanf("%d",&n);
	printf("\n");
	
	mov=Caesar(L, n);
	//打印输出
	for (i = 0; i < 26; i++)
	{
		printf("%c", mov->data);
		mov = mov->next;
	}

	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}
