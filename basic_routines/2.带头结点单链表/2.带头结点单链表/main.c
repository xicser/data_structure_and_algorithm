

/*

2017��12��7�գ�С�������ܶ���

��ͷ��㵥�������ʵ��

*/

#define _CRT_SECURE_NO_WARNINGS//��������꣬���ܱ���ͨ��

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
	LinkList L;//������������ͷָ�룩
	C_ElemType e;
	int elem_num;

	//β�巨������ͷ���ĵ�������ʼ����Ϊ5
	printf("β�巨������ͷ���ĵ�����...\n");
	printf("������Ԫ�ظ�����");
	scanf("%d",&elem_num);
	printf("����������%d��Ԫ�أ�", elem_num);
	C_ListCreateTail(&L, elem_num, input);
	
	printf("���������");
	C_ListTraverse(L, visit);
	printf("\n");

	printf("���Ա���%d\n", C_ListLength(L));

	printf("�ڵ�2��Ԫ��֮ǰ����999\n");
	C_ListInsert(&L,2,999);

	printf("���������");
	C_ListTraverse(L, visit);
	printf("\n");

	printf("ɾ����4�����\n");
	C_ListDelete(&L,4,&e);
	printf("��ɾԪ��Ϊ%d\n", e);
	printf("���������");
	C_ListTraverse(L, visit);
	printf("\n");

	printf("����...\n");
	C_ListSelectSort2(L);
	printf("���������");
	C_ListTraverse(L, visit);
	printf("\n");

	GetMidNode(L, &e);
	printf("�м��Ԫ��Ϊ��%d\n\n",e);

	system("pause");
	return 0;
}



	
	