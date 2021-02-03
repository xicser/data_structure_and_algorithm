#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"


/*
 * ��������
 *
 * ����˵����
 *     a -- �����������
 *     l -- �������߽�(���磬����ʼλ�ÿ�ʼ������l=0)
 *     r -- ������ұ߽�(���磬�������������ĩβ����r=a.length-1)
 */
void QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int i,j,x;

        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while(i < j && a[j] > x)
                j--; // ���������ҵ�һ��С��x����
            if(i < j)
                a[i++] = a[j];

            while(i < j && a[i] < x)
                i++; // ���������ҵ�һ������x����
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;

        QuickSort(a, l, i-1); /* �ݹ���� */
        QuickSort(a, i+1, r); /* �ݹ���� */
    }
}


