#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

/*
* ��һ�������е����� ���� ���� ����ϲ���һ��
*
* ����˵����
*     a -- ���������������������
*     start -- ��1�������������ʼ��ַ���±꣩��
*     mid   -- ��1����������Ľ�����ַ���±꣩��Ҳ�ǵ�2�������������ʼ��ַ���±꣩��
*     end   -- ��2����������Ľ�����ַ���±꣩��
*/
static void MergeArray(int Array[], int start, int mid, int end)
{
	//tmp�ǻ���2������������ʱ����
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
	if (i == mid + 1)//����A��ȡ����
	{//��Bʣ�µ�Ԫ��ֱ�����θ���tmp���źõ�Ԫ�غ���
		while (j < end + 1)
		{
			tmp[k] = Array[j];
			k++;
			j++;
		}
	}else
	if (j == end + 1)//����B��ȡ����
	{//��Aʣ�µ�Ԫ��ֱ�����θ���tmp���źõ�Ԫ�غ���
		while (i < mid  + 1)
		{
			tmp[k] = Array[i];
			k++;
			i++;
		}
	}

	//tmp������ԭ����
	for (i = start; i < end + 1; i++)
	{
		Array[i] = tmp[i - start];
	}

	free(tmp);
}
/*
* �鲢����(�������£����õݹ�)
*
* ����˵����
*     Array -- �����������
*     start -- �������ʼ��ַ
*     end   -- ����Ľ�����ַ
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






























//����������A,B�ϲ���C�У���Ȼ��������
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
//	if (i == Alen)//����A��ȡ����
//	{//��Bʣ�µ�Ԫ��ֱ�����θ���C���źõ�Ԫ�غ���
//		while (j<Blen)
//		{
//			C[k] = B[j];
//			k++;
//			j++;
//		}
//	}
//	else if (j == Blen)//����B��ȡ����
//	{//��Aʣ�µ�Ԫ��ֱ�����θ���C���źõ�Ԫ�غ���
//		while (i<Alen)
//		{
//			C[k] = A[i];
//			k++;
//			i++;
//		}
//	}
//}
