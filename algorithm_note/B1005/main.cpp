/*

继续(3n+1)猜想

*/

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool Exist[100000] = {false};

void cal_steps(int n)
{
    while (n != 1) {

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }

        if (Exist[n] == false) {
            Exist[n] = true;
        }
    }
}
bool cmp(int a, int b)
{
    return a > b;
}
/*
6
3 5 6 7 8 11
*/
int main()
{
    int K;
    scanf("%d", &K);
    int input[K];
    int out[K];
    int out_index = 0;

    for (int i = 0; i < K; i++) {
        scanf("%d", &input[i]);
        cal_steps(input[i]);
    }

    for (int i = 0; i < K; i++) {
        if (Exist[ input[i] ] == false) {
            out[out_index] = input[i];
            out_index++;
        }
    }

    sort(out, out + out_index, cmp);
    for (int i = 0; i < out_index; i++) {
        printf("%d", out[i]);
        if (i == out_index - 1) printf("\n");
        else printf(" ");
    }

    return 0;
}
