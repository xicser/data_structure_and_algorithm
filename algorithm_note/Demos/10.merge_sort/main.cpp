#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*
把数组A中, (L1, R1)和(L2, R2)合并成有序
其中R1 + 1 = L2, 即两个区间相邻
*/
int C[10000];
int mergeArray(int *A, int L1, int R1, int L2, int R2)
{
    int i = L1, j = L2, indexC = 0;
    while (i <= R1 && j <= R2) {
        if (A[i] <= A[j]) {
            C[indexC++] = A[i++];
        } else {
            C[indexC++] = A[j++];
        }
    }

    while (i <= R1) C[indexC++] = A[i++];
    while (j <= R2) C[indexC++] = A[j++];

    //拷贝回A里面
    for (int k = 0; k < indexC; k++) {
        A[k + L1] = C[k];
    }

    return indexC;
}

void mergeSort(int *A, int starti, int endi)
{
    if (starti < endi) {
        int mid = (starti + endi) / 2;
        mergeSort(A, starti, mid);
        mergeSort(A, mid + 1, endi);
        mergeArray(A, starti, mid, mid + 1, endi);
    }
}

int main()
{
    int A[] = {34, 2, 54, 1, 0, -1, 5};

    mergeSort(A, 0, sizeof(A) / sizeof(int) - 1);
    for (unsigned int i = 0; i < sizeof(A) / sizeof(int); i++) {
        cout << A[i] << " ";
    }

    return 0;
}
