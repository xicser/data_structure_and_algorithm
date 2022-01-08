#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "cycle_link_list.h"

Status compare(ElemType c1, ElemType c2)
{
	if (c1 == c2)return 1;
	else return 0; 
}
void visit(ElemType c)
{
	printf("%d ", c);
}

int main(void)
{
	int j;
	LinkList L;
	ElemType e;
	Status i;

	i = InitList_CL(&L); /* 初始化单循环链表L */
	printf("初始化单循环链表L（%d）\n", i);

	i = ListEmpty_CL(L);
	printf("L是否空？（%d）\n", i);/*判断是否为空*/

	printf("在L中依次插入3,5\n");/* 在L中依次插入3,5 */
	ListInsert_CL(&L, 1, 3); 
	ListInsert_CL(&L, 2, 5);
	printf("遍历一遍：");
	ListTraverse_CL(L,visit);

	i = GetElem_CL(L, 1, &e);
	j = ListLength_CL(L);
	printf("L中数据元素个数=%d,第1个元素的值为%d\n", j, e);

	PriorElem_CL(L, 5, &e); /* 求元素5的前驱 */
	printf("5前面的元素的值为%d。\n", e);
	NextElem_CL(L, 3, &e); /* 求元素3的后继 */
	printf("3后面的元素的值为%d。\n", e);

	printf("L是否空？（%d）\n", ListEmpty_CL(L));

	j = LocateElem_CL(L, 5, compare);
	if (j)printf("L的第%d个元素为5\n", j);
	else printf("不存在值为5的元素\n");

	i = ListDelete_CL(&L, 2, &e);
	printf("删除L的第2个元素：\n");
	if (i==OK)
	{
		printf("删除的元素值为%d,现在L中的数据元素依次为：", e);
		ListTraverse_CL(L, visit);
	}
	else printf("删除不成功！\n");
	
	printf("清空L：（%d）\n", ClearList_CL(&L));
	printf("清空L后，L是否空：（%d）\n", ListEmpty_CL(L));
	printf("销毁L：（%d）\n", DestroyList_CL(&L));

	system("pause");
	return 0;
}


