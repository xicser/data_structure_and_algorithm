#include <iostream>
#include <stdio.h>
#include "func_root.h"
#include "water_filling.h"

using namespace std;

/* 二分法(要求序列严格单调) */
int biSearch(int *A, int left, int right, int x)
{
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;      //防溢出mid = left + (right - left) / 2;
        if (A[mid] == x) return mid;
        else if (A[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    //没找到
    return -1;
}

int main()
{
    int A[10] = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};

    printf("%d %d\n", biSearch(A, 0, 9, 6), biSearch(A, 0, 9, 9));

    cout << getRoot(0, 2) << endl;
    cout << getH(0.5) << endl;

    return 0;
}
