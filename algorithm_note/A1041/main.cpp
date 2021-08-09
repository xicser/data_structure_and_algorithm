/*

Be Unique

*/

#include <iostream>
#include <stdio.h>

using namespace std;


int number_cnt[10005] = {0};
int input[100005];
int main()
{
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
        number_cnt[ input[i] ]++;
    }

    bool is_none = true;
    for (int i = 0; i < N; i++) {
        if (number_cnt[ input[i] ] == 1) {
            printf("%d\n", input[i]);
            is_none = false;
            break;
        }
    }

    if (is_none == true) {
        printf("None\n");
    }

    return 0;
}
