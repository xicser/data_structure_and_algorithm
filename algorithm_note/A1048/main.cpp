/*

Find Coins

*/

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int appearTimes[5005] = {0};

typedef struct {
    int v1;
    int v2;
} Value_t;

bool cmp(Value_t va, Value_t vb);
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    Value_t values[N];
    int v_index = 0;

    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        appearTimes[tmp]++;
    }
/*
8 15
1 2 8 7 2 4 11 15

7 14
1 8 7 2 4 11 15
*/
    bool exist = false;
    for (int i = 1; i <= M - 1; i++) {

        if (i != M - i) {
            if (appearTimes[i] && appearTimes[M - i]) {
                //找到一对先存起来
                values[v_index].v1 = min(i, M - i);
                values[v_index].v2 = max(i, M - i);
                v_index++;

                exist = true;
            }
        } else {
            if (appearTimes[i] >= 2) {
                //找到一对先存起来
                values[v_index].v1 = min(i, M - i);
                values[v_index].v2 = max(i, M - i);
                v_index++;

                exist = true;
            }
        }
    }

    if (exist == false) {
        printf("No Solution\n");
        return 0;
    }

    sort(values, values + v_index, cmp);
    printf("%d %d\n", values[0].v1, values[0].v2);

    return 0;
}

bool cmp(Value_t va, Value_t vb)
{
    return va.v1 < vb.v1;
}
