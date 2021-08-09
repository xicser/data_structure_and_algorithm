/*

A+B for Polynomials


2   1 2.4   0 3.2
2   2 1.5   1 0.5

*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int none_zero = 0;
    double polyA[1005] = {0};  //多项式A, 下标表示幂
    double polyB[1005] = {0};  //多项式B, 下标表示幂
    double polyOut[1005] = {0};//结果多项式, 下标表示幂

    //输入
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int index;
        double ratio;
        scanf("%d%lf", &index, &ratio);
        polyA[index] = ratio;
    }
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int index;
        double ratio;
        scanf("%d%lf", &index, &ratio);
        polyB[index] = ratio;
    }

    //计算
    for (int i = 0; i < 1005; i++) {
        polyOut[i] = polyA[i] + polyB[i];
        if (polyOut[i]) none_zero++;
    }

    //针对全部为0的特殊处理
    if (none_zero == 0) {
        printf("0\n");
        return 0;
    }
    //打印非0系数的项的个数
    printf("%d ", none_zero);

    //输出
    int out_cnt = 0;
    for (int i = 1005 - 1; i >= 0; i--) {

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
