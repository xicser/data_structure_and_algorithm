#include <iostream>
#include <stdlib.h>

using namespace std;


/*
调整数组中的元素位置,
使得A[1]的左侧所有元素都不超过A[1]
右侧所有元素都大于A[1]
*/
int Partition(int *A, int left, int right)
{
//    //随机选主元
//    int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);
//    swap(A[p], A[left]);

    int temp = A[left];

    while (left < right) {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;

    return left;
}

void qSort(int *A, int left, int right)
{
    if (left < right) {
        int pos = Partition(A, left, right);
        qSort(A, left, pos - 1);
        qSort(A, pos + 1, right);
    }
}

int main()
{
    int A[] = {34, 2, 54, 1, 0, -1, 5};

    qSort(A, 0, sizeof(A) / sizeof(int) - 1);
    for (unsigned int i = 0; i < sizeof(A) / sizeof(int); i++) {
        cout << A[i] << " ";
    }

    return 0;
}
