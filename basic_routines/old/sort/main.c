#include <stdio.h>
#include <stdlib.h>

#include "BubbleSort.h"
#include "SelectSort.h"
#include "InsertSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

int head, tail;
int main(void)
{
	int i;
	//int A[] = {8,9,78,-8};

	int A[] = { 3, 1, 2, 8, 7, 5, 9, 4, 0, 6 };
	//≤‚ ‘≈≈–ÚÀ„∑®
	//BubbleSort(A,6);
	//SimpleSelectSort(A,6);
	//InsertSort(A, sizeof(A) / sizeof(int));
	//ShellSort(A, sizeof(A) / sizeof(int));
	head = 0, tail = sizeof(A) / sizeof(int) - 1;
	MergeSort(A, 0, sizeof(A) / sizeof(int) - 1);
	//QuickSort(A, 0, sizeof(A) / sizeof(int) - 1);


	for (i = 0; i < sizeof(A)/sizeof(int); i++)
		printf("%d ",A[i]);


	system("pause");
	return 0;
}
