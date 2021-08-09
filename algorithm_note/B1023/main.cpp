/*

组个最小数

*/

#include <iostream>
#include <stdio.h>

using namespace std;


int Count[10] = {0};
int main()
{
    int zero_count = 0;
    for (int i = 0; i < 10; i++) {
        int tmp;
        scanf("%d", &tmp);
        Count[i] = tmp;
    }
    zero_count = Count[0];

    if (zero_count == 0) {
        for (int j = 0; j < Count[1]; j++) {
            printf("1");
        }
    } else {

        int index; //先找到除了0以外, 最小的那个数
        for (index = 1; index < 10; index++) {
            if (Count[index]) break;
        }

        printf("%d", index);
        Count[index]--;

        for (int j = 0; j < Count[0]; j++) {
            printf("0");
        }

        for (int j = 0; j < Count[index]; j++) {
            printf("%d", index);
        }
    }

    for (int i = 2; i < 10; i++) {
        for (int j = 0; j < Count[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}
