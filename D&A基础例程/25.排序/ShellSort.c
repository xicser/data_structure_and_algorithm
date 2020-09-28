#include <stdio.h>
#include <stdlib.h>
#include "ShellSort.h"


/*
希尔排序：

先进行宏观调整，再进行微观调整
实质就是分组的插入排序

过程：
先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）
分别进行直接插入排序，然后依次缩减增量再进行排序，
待整个序列中的元素基本有序（增量足够小）时，
再对全体元素进行一次直接插入排序。
因为直接插入排序在元素基本有序的情况下（接近最好情况），
效率是很高的，因此希尔排序在时间效率上比前两种方法有较大提高
*/

void ShellSort(int *Array, int ArrayLen)
{
	int i, j, k, temp;
	int gap = 1;//初始化一个间隔
	//计算最大间隔
	while (gap < ArrayLen / 3) {
		gap = gap * 3 + 1;
	}
	for (; gap > 0; gap = (gap - 1) / 3)//采用不同的gap进行分组排序
	{
		for (i = 0; i < gap; i++)//对每组内部进行插入排序，gap的值等于分组数
		{
			//一次插入排序
			for (j = i + gap; j < ArrayLen; j = j + gap)
			{
				k = j;
				while (k > i && Array[k] > Array[k - gap])
				{
					temp = Array[k];//交换
					Array[k] = Array[k - gap];
					Array[k - gap] = temp;

					k = k - gap;
				}
			}
		}
	}
}
