/*

Product of Polynomials

*/


#include <iostream>
#include <stdio.h>

using namespace std;

#define ARRAY_SIZE (2005)

typedef struct {
    int index;     //指数
    double ratio;  //系数
} Iterm_t;

int main()
{
    int none_zero = 0;
    double polyOut[ARRAY_SIZE] = {0};//结果多项式, 下标表示幂

    //输入
    int cnt_A;
    scanf("%d", &cnt_A);
    Iterm_t polyA[cnt_A] = {0};  //多项式A
    for (int i = 0; i < cnt_A; i++) {
        scanf("%d%lf", &polyA[i].index, &polyA[i].ratio);
    }

    int cnt_B;
    scanf("%d", &cnt_B);
    for (int i = 0; i < cnt_B; i++) {
        int index;
        double ratio;
        scanf("%d%lf", &index, &ratio);

        //顺便就计算
        for (int j = 0; j < cnt_A; j++) {
            polyOut[index + polyA[j].index] += ratio * polyA[j].ratio;
        }
    }

    //计算非0项的个数
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (polyOut[i]) none_zero++;
    }

    //针对全部为0的特殊处理
    if (none_zero == 0) {
        printf("0\n");
        return 0;
    }

    //输出
    printf("%d ", none_zero);
    int out_cnt = 0;
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {

        //先找到第一个非0的项
        if (polyOut[i] != 0) {
            printf("%d %.1lf", i, polyOut[i]);

            out_cnt++;
            if (out_cnt == none_zero) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}
