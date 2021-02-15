#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

/*
* 将一个数组中的两个 相邻 有序 区间合并成一个
*
* 参数说明：
*     a -- 包含两个有序区间的数组
*     start -- 第1个有序区间的起始地址（下标）。
*     mid   -- 第1个有序区间的结束地址（下标）。也是第2个有序区间的起始地址（下标）。
*     end   -- 第2个有序区间的结束地址（下标）。
*/
static void MergeArray(int Array[], int start, int mid, int end)
{
	//tmp是汇总2个有序区的临时区域
	int *tmp = (int *)malloc((end - start + 1)*sizeof(int));
	int i = start;
	int j = mid + 1;
	int k = 0;

	for (; i != mid  + 1 && j != end + 1; k++)
	{
		if (Array[i] < Array[j])
		{
			tmp[k] = Array[i];
			i++;
		}
		else
		{
			tmp[k] = Array[j];
			j++;
		}
	}
	if (i == mid + 1)//数组A先取完了
	{//将B剩下的元素直接依次跟在tmp已排好的元素后面
		while (j < end + 1)
		{
			tmp[k] = Array[j];
			k++;
			j++;
		}
	}else
	if (j == end + 1)//数组B先取完了
	{//将A剩下的元素直接依次跟在tmp已排好的元素后面
		while (i < mid  + 1)
		{
			tmp[k] = Array[i];
			k++;
			i++;
		}
	}

	//tmp拷贝至原数组
	for (i = start; i < end + 1; i++)
	{
		Array[i] = tmp[i - start];
	}

	free(tmp);
}
/*
* 归并排序(从上往下，采用递归)
*
* 参数说明：
*     Array -- 待排序的数组
*     start -- 数组的起始地址
*     end   -- 数组的结束地址
*/

extern int head, tail;

void MergeSort(int *Array, int start, int end)
{
	int mid = (end + start) / 2;

	if (Array == NULL || start >= end)return;

	for (int i = head; i <= tail; i++) {
        printf("%d ", Array[i]);
	}
	printf("\n");

	MergeSort(Array, start, mid);
	MergeSort(Array, mid + 1, end);
	MergeArray(Array, start, mid, end);
}






























//将有序数组A,B合并到C中（依然保持有序）
//void MergeArray(int *A, int Alen, int *B, int Blen, int *C)
//{
//	int i, j, k;
//	for (i = 0, j = 0 ,k = 0; i != Alen && j != Blen ; k++ )
//	{
//		if (A[i] < B[j])
//		{
//			C[k] = A[i];
//			i++;
//		}
//		else
//		{
//			C[k] = B[j];
//			j++;
//		}
//	}
//	if (i == Alen)//数组A先取完了
//	{//将B剩下的元素直接依次跟在C已排好的元素后面
//		while (j<Blen)
//		{
//			C[k] = B[j];
//			k++;
//			j++;
//		}
//	}
//	else if (j == Blen)//数组B先取完了
//	{//将A剩下的元素直接依次跟在C已排好的元素后面
//		while (i<Alen)
//		{
//			C[k] = A[i];
//			k++;
//			i++;
//		}
//	}
//}
