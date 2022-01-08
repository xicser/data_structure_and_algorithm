
/*

2017年12月8日，小王持续努力！

双向循环链表，本例程生成的双向循环链表 没有 头结点。
（先创建了，又给它free了）

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Cycle_DList.h"


//初始化链表
//创建26个英文单词的双向循环链表
Status InitList(DualLinkList *L)
{
	int i;
	DualNode *p, *q;

	*L = (DualLinkList)malloc(sizeof(DualNode));
	if (*L == NULL)return ERROR;//内存申请失败

	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	for (i = 0; i < 26; i++)
	{
		q = (DualLinkList)malloc(sizeof(DualNode));
		if (q == NULL)return ERROR;//内存申请失败

		q->data = 'A' + i;
		q->prior = p;//插入结点
		q->next = p->next;
		p->next = q;

		p = q;
	}
	p->next = (*L)->next;
	(*L)->next->prior = p;

	//释放刚开始生成的头结点
	free(*L);

	//*L指向开始结点
	*L = p->next;

	return OK;
}


