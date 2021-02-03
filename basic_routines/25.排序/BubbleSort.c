#include <stdio.h>
#include <stdlib.h>
#include "BubbleSort.h"


//冒泡排序
//根据上面这种冒泡实现，若原数组本身就是有序的（这是最好情况），
//仅需n - 1次比较就可完成；若是倒序，比较次数为 n - 1 + n - 2 + ... + 1 = n(n - 1) / 2，
//交换次数和比较次数等值。
void BubbleSort(int *Array, int ArrayLen)
{
	int i, j;
	int temp;

	//设定一个标记，若为0，则表示此次（本趟）循环没有进行交换，也就是待排序列已经有序，排序已然完成。
	int IsSort;

	for (i = 0; i < ArrayLen-1; i++)
	{
		IsSort = 0;//先认为本趟冒泡没有交换
		for (j = 0; j < ArrayLen -1 -i; j++)//沉底一个
		{
			if (Array[j] > Array[j + 1])
			{
				temp = Array[j];//交换
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
				IsSort = 1;
			}
		}
		if (IsSort==0)break;
	}
}
