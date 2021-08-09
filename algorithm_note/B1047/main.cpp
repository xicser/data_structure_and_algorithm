
/*

编程团体赛

*/

#include <iostream>
#include <stdio.h>

using namespace std;


int team[1005] = {0};
int main()
{
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int tmp_team, tmp_people, tmp_score;
        scanf("%d-%d %d", &tmp_team, &tmp_people, &tmp_score);
        team[tmp_team] += tmp_score;
    }

    int max_index;
    int max_value = -1;
    for (int i = 0; i < 1005; i++) {
        if (max_value < team[i]) {
            max_value = team[i];
            max_index = i;
        }
    }

    printf("%d %d\n", max_index, max_value);


    return 0;
}
