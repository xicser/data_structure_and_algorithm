/*
C语言-数字交换
*/

#include <iostream>

using namespace std;

int main()
{
    int input[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
    }

    //检查是否是降序的
    int j;
    for (j = 1; j < 10; j++) {
        if (input[j - 1] < input[j]) {
            break;
        }
    }
    if (j == 10) {
        printf("%d ", input[9]);
        for (int i = 1; i < 9; i++) {
            printf("%d ", input[i]);
        }
        printf("%d", input[0]);
        return 0;
    }

    int max_i = 0, min_i = 0;
    int maxValue = input[0], minValue = input[0];
    for (int i = 1; i < 10; i++) {
        if (maxValue < input[i]) {
            maxValue = input[i];
            max_i = i;
        }

        if (minValue > input[i]) {
            minValue = input[i];
            min_i = i;
        }
    }

    swap(input[0], input[min_i]);
    swap(input[9], input[max_i]);
    for (int i = 0; i < 10; i++) {
        printf("%d", input[i]);
        if (i == 9) {
            printf("\n");
        } else printf(" ");
    }

    return 0;
}
