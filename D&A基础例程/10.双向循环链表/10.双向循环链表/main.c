
/*

2017��12��8�գ�С������Ŭ����

˫��ѭ������


����������

Ҫ��ʵ���û�����һ����ʹ��26����ĸ�����з����仯��
�����û�����3����������

DEFGHIJKLMNOPQRSTUVWXYZABC

����-3��������Ϊ��
XYZABCDEFGHIJKLMNOPQRSTUVW


*/


#define _CRT_SECURE_NO_WARNINGS//��������꣬���ܱ���ͨ��

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Cycle_DList.h"


DualLinkList Caesar(DualLinkList L, int i)
{
	DualLinkList mov = L;//movָ��ʼ���

	//i���ڼ���mov��Ų����
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
	return mov;//������ʼ��ӡλ��
}

int main(void)
{
	int i, n;
	DualLinkList L, mov;

	InitList(&L);//�����������ú�Lָ��ʼ���

	printf("������һ��������");
	scanf("%d",&n);
	printf("\n");
	
	mov=Caesar(L, n);
	//��ӡ���
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
