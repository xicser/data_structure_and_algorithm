/*

到底买不买

*/

#include <iostream>
#include <stdio.h>

using namespace std;


int owner[300] = {0};
int xiaohong[300] = {0};

char str[1005];

void myGets(char *out);
int main()
{
    int owner_cnt = 0;
    int xiaohong_cnt = 0;
    int less_cnt = 0;

    myGets(str);
    for (int i = 0; str[i]; i++) {
        owner[(int)str[i]]++;
        owner_cnt++;
    }

    myGets(str);
    for (int i = 0; str[i]; i++) {
        xiaohong[(int)str[i]]++;
        xiaohong_cnt++;
    }

/*
ppRYYGrrYBR2258
YrR8RrY
*/
    int i;
    bool can = true;
    for (i = 0; i < 300; i++) {
        if (owner[i] < xiaohong[i]) {
            less_cnt += xiaohong[i] - owner[i];
            can = false;
        }
    }

    if (can == true) {
        printf("Yes %d\n", owner_cnt - xiaohong_cnt);
    } else {
        printf("No %d\n", less_cnt);
    }

    return 0;
}

void myGets(char *out)
{
    int i = 0;
    while (1) {
        char tmp = getchar();
        if (tmp == '\n') {
            break;
        } else {
            out[i++] = tmp;
        }
    }
    out[i] = 0;
}
