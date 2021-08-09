/*

打印沙漏

*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int N;
    char c;
    int used = 0;
    cin >> N >> c;

    int line_up = sqrt((N + 1) / 2);
    int up_cnt = 2 * line_up - 1;

    //先打印上三角
    for (int i = 0; i < line_up; i++) {
        for (int j = 0; j < up_cnt; j++) {

            if (j >= i && (i + j <= up_cnt - 1)) {
                printf("%c", c);
                used++;
            } else if (i > j) {  //注意*的右边不能有空格
                printf(" ");
            }
        }
        printf("\n");
    }

    //再打印下三角
    for (int i = 1; i < line_up; i++) {
        for (int j = 0; j < up_cnt; j++) {

            if ((j <= i + (up_cnt / 2)) && (i + j >= (up_cnt / 2))) {
                printf("%c", c);
                used++;
            } else if (i + j < (up_cnt / 2)) {  //注意*的右边不能有空格
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("%d", N - used);

    return 0;
}
