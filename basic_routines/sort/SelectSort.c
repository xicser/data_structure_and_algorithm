#include <stdio.h>
#include <stdlib.h>
#include "SelectSort.h"


//��ѡ������
void SimpleSelectSort(int *Array, int ArrayLen)
{
	int i, j, temp;
	int minIndex;//��¼��СԪ�ص�����

	for (i = 0; i < ArrayLen - 1; i++)
	{
		minIndex = i;
		for (j = i+1; j < ArrayLen; j++)
		{
			if (Array[minIndex] > Array[j])minIndex = j;
		}
		if (minIndex != i)
		{//����
			temp = Array[minIndex];
			Array[minIndex] = Array[i];
			Array[i] = temp;
		}
	}
}

