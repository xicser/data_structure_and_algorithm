/*

Colors in Mars

*/

#include <iostream>
#include <stdio.h>

using namespace std;

#define radix (13)

int main()
{
    int input[3];
    cin >> input[0] >> input[1] >> input[2];
    printf("#");

    int z[1000], num;
    for (int i = 0; i < 3; i++) {

        //要补0的情况
        if (input[i] == 12) {
            printf("0C", input[i]);
            continue;
        } else if (input[i] == 11) {
            printf("0B", input[i]);
            continue;
        } else if (input[i] == 10) {
            printf("0A", input[i]);
            continue;
        } else if (input[i] < 10) {
            printf("0%d", input[i]);
            continue;
        }

        num = 0;
        do {
            z[num++] = input[i] % radix;
            input[i] /= radix;

        } while (input[i]);

        for (int j = num - 1; j >= 0; j--) {
            if (z[j] == 10) {
                printf("A");
            } else if (z[j] == 11) {
                printf("B");
            } else if (z[j] == 12) {
                printf("C");
            } else {
                printf("%d", z[j]);
            }
        }
    }

    return 0;
}
