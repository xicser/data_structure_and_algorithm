#include <stdio.h>
#include <stdlib.h>
#include "InsertSort.h"


//≤Â»Î≈≈–Ú
void InsertSort(int *Array, int ArrayLen)
{
	int i, j;
	int temp;

	for (i = 1; i < ArrayLen; i++)
	{
		j = i;
		while (j > 0 && Array[j] < Array[j - 1])
		{
			temp = Array[j];
			Array[j] = Array[j - 1];
			Array[j - 1] = temp;

			j--;
		}
	}
}
