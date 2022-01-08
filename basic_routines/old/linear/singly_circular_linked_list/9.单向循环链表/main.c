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

	i = InitList_CL(&L); /* ��ʼ����ѭ������L */
	printf("��ʼ����ѭ������L��%d��\n", i);

	i = ListEmpty_CL(L);
	printf("L�Ƿ�գ���%d��\n", i);/*�ж��Ƿ�Ϊ��*/

	printf("��L�����β���3,5\n");/* ��L�����β���3,5 */
	ListInsert_CL(&L, 1, 3); 
	ListInsert_CL(&L, 2, 5);
	printf("����һ�飺");
	ListTraverse_CL(L,visit);

	i = GetElem_CL(L, 1, &e);
	j = ListLength_CL(L);
	printf("L������Ԫ�ظ���=%d,��1��Ԫ�ص�ֵΪ%d\n", j, e);

	PriorElem_CL(L, 5, &e); /* ��Ԫ��5��ǰ�� */
	printf("5ǰ���Ԫ�ص�ֵΪ%d��\n", e);
	NextElem_CL(L, 3, &e); /* ��Ԫ��3�ĺ�� */
	printf("3�����Ԫ�ص�ֵΪ%d��\n", e);

	printf("L�Ƿ�գ���%d��\n", ListEmpty_CL(L));

	j = LocateElem_CL(L, 5, compare);
	if (j)printf("L�ĵ�%d��Ԫ��Ϊ5\n", j);
	else printf("������ֵΪ5��Ԫ��\n");

	i = ListDelete_CL(&L, 2, &e);
	printf("ɾ��L�ĵ�2��Ԫ�أ�\n");
	if (i==OK)
	{
		printf("ɾ����Ԫ��ֵΪ%d,����L�е�����Ԫ������Ϊ��", e);
		ListTraverse_CL(L, visit);
	}
	else printf("ɾ�����ɹ���\n");
	
	printf("���L����%d��\n", ClearList_CL(&L));
	printf("���L��L�Ƿ�գ���%d��\n", ListEmpty_CL(L));
	printf("����L����%d��\n", DestroyList_CL(&L));

	system("pause");
	return 0;
}


