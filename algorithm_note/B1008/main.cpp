/* 数组元素循环右移问题 */

#include <iostream>
#include <stdio.h>

using namespace std;

/*
6 2
1 2 3 4 5 6

5 6 1 2 3 4
*/
int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    int array_input[N];


    if (M > N) {
        M %= N;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &array_input[i]);
    }


    for (int i = N - M; i < N; i++) {
        printf("%d ", array_input[i]);
    }

    for (int i = 0; i < N - M; i++) {
        printf("%d", array_input[i]);
        if (i != N - M - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
