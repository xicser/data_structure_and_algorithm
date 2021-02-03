#include <stdio.h>
#include <stdlib.h>
#include "SelectSort.h"


//简单选择排序
void SimpleSelectSort(int *Array, int ArrayLen)
{
	int i, j, temp;
	int minIndex;//记录最小元素的索引

	for (i = 0; i < ArrayLen - 1; i++)
	{
		minIndex = i;
		for (j = i+1; j < ArrayLen; j++)
		{
			if (Array[minIndex] > Array[j])minIndex = j;
		}
		if (minIndex != i)
		{//交换
			temp = Array[minIndex];
			Array[minIndex] = Array[i];
			Array[i] = temp;
		}
	}
}

