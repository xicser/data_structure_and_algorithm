#include <iostream>
#include <stdio.h>

using namespace std;


/*
给定一个递增的正整数序列和一个正整数m，
求序列中两个不同位置的数a和b，使得他们的和恰好为M
输出所有满足条件的方案
*/
void towPointers(int *A, int starti, int endi, int m)
{
    int i = starti;
    int j = endi;

    while (i < j) {
        int tmpSum = A[i] + A[j];
        if (tmpSum == m) {
            printf("%d %d\n", i, j);
            i++;
            j--;
        } else if (tmpSum < m) {
            i++;
        } else {
            j--;
        }
    }
}

/*
合并两个升序数组到C, 返回C的元素个数
*/
int mergeArray(int *A, int *B, int *C, int n, int m)
{
    int i = 0, j = 0, index = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            C[index++] = A[i++];
        } else {
            C[index++] = B[j++];
        }
    }

    while (i < n) C[index++] = A[i++];
    while (j < m) C[index++] = B[j++];

    return index;
}

int main()
{

    return 0;
}
