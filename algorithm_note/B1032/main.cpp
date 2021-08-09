/*

挖掘机技术哪家强

*/

#include <iostream>
#include <stdio.h>

using namespace std;



#define SCHOOL_NUM (100005)

int scores[SCHOOL_NUM] = {0};


int main()
{
    int N;
    int max_index = -1;

    scanf("%d", &N);

    //输入
    for (int i = 0; i < N; i++) {
        int tmp_school, tmp_score;
        scanf("%d %d", &tmp_school, &tmp_score);
        scores[tmp_school] += tmp_score;
        if (tmp_school > max_index) {  //记录最大的索引
            max_index = tmp_school;
        }
    }

    //找到得分最高的
    int max_value = -1;
    int max_i;
    for (int i = 0; i <= max_index; i++) {
        if (scores[i] > max_value) {
            max_value = scores[i];
            max_i = i;
        }
    }

    printf("%d %d\n", max_i, max_value);

    return 0;
}
