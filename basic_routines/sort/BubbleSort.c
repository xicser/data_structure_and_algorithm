#include <stdio.h>
#include <stdlib.h>
#include "BubbleSort.h"


//ð������
//������������ð��ʵ�֣���ԭ���鱾���������ģ���������������
//����n - 1�αȽϾͿ���ɣ����ǵ��򣬱Ƚϴ���Ϊ n - 1 + n - 2 + ... + 1 = n(n - 1) / 2��
//���������ͱȽϴ�����ֵ��
void BubbleSort(int *Array, int ArrayLen)
{
	int i, j;
	int temp;

	//�趨һ����ǣ���Ϊ0�����ʾ�˴Σ����ˣ�ѭ��û�н��н�����Ҳ���Ǵ��������Ѿ�����������Ȼ��ɡ�
	int IsSort;

	for (i = 0; i < ArrayLen-1; i++)
	{
		IsSort = 0;//����Ϊ����ð��û�н���
		for (j = 0; j < ArrayLen -1 -i; j++)//����һ��
		{
			if (Array[j] > Array[j + 1])
			{
				temp = Array[j];//����
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
				IsSort = 1;
			}
		}
		if (IsSort==0)break;
	}
}
