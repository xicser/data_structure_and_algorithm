#include <stdio.h>
#include <stdlib.h>
#include "ShellSort.h"


/*
ϣ������

�Ƚ��к�۵������ٽ���΢�۵���
ʵ�ʾ��Ƿ���Ĳ�������

���̣�
�Ƚ���������Ԫ�����зָ�����ɸ������У������ĳ������������Ԫ����ɵģ�
�ֱ����ֱ�Ӳ�������Ȼ���������������ٽ�������
�����������е�Ԫ�ػ������������㹻С��ʱ��
�ٶ�ȫ��Ԫ�ؽ���һ��ֱ�Ӳ�������
��Ϊֱ�Ӳ���������Ԫ�ػ������������£��ӽ�����������
Ч���Ǻܸߵģ����ϣ��������ʱ��Ч���ϱ�ǰ���ַ����нϴ����
*/

void ShellSort(int *Array, int ArrayLen)
{
	int i, j, k, temp;
	int gap = 1;//��ʼ��һ�����
	//���������
	while (gap < ArrayLen / 3) {
		gap = gap * 3 + 1;
	}
	for (; gap > 0; gap = (gap - 1) / 3)//���ò�ͬ��gap���з�������
	{
		for (i = 0; i < gap; i++)//��ÿ���ڲ����в�������gap��ֵ���ڷ�����
		{
			//һ�β�������
			for (j = i + gap; j < ArrayLen; j = j + gap)
			{
				k = j;
				while (k > i && Array[k] > Array[k - gap])
				{
					temp = Array[k];//����
					Array[k] = Array[k - gap];
					Array[k - gap] = temp;

					k = k - gap;
				}
			}
		}
	}
}
