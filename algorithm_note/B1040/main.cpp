#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;



#define MAXN 1000100
#define MOD 1000000007

char str[MAXN];
int left_Ps[MAXN] = {0};
int right_Ts[MAXN] = {0};

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

int main()
{
    long long sum = 0;
    int len;
    myGets(str);
    len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (i != 0) {
            left_Ps[i] = left_Ps[i - 1];
        }

        if (str[i] == 'P') {
            left_Ps[i]++;
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        if (i != len - 1) {
            right_Ts[i] = right_Ts[i + 1];
        }

        if (str[i] == 'T') {
            right_Ts[i]++;
        }
    }


    for (int i = 0; i < len; i++) {
        if (str[i] == 'A') {
            sum += left_Ps[i] * right_Ts[i];
        }
    }

    printf("%ld\n", sum % MOD);
    return 0;
}
