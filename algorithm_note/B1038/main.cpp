/*

统计同成绩学生

*/


#include <iostream>
#include <stdio.h>

using namespace std;

int score[105] = {0};
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        score[ tmp ]++;
    }

    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d", score[tmp]);
        if (i != K - 1) printf(" ");
        else printf("\n");
    }

    return 0;
}
