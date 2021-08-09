/*

A+B Format

*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int out[1000];
int out_index = 0;

char out_true[1000];
int out_true_index = 0;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int sum = a + b;
    if (sum < 0) {
        printf("-");
        sum *= -1;
    }

    if (sum == 0) {
        printf("0");
        return 0;
    }
    while (sum) {
        out[out_index++] = sum % 10;
        sum /= 10;
    }

    int cnt = 0;
    for (int i = 0; i < out_index; i++) {
//        printf("%d", out[i]);
        out_true[out_true_index++] = out[i] + 48;
        cnt++;
        if (cnt == 3 && i != out_index - 1) {
            cnt = 0;
//            printf(",");
            out_true[out_true_index++] = ',';
        }
    }

    for (int i = out_true_index - 1; i >= 0; i--) {
        printf("%c", out_true[i]);
    }

    return 0;
}
