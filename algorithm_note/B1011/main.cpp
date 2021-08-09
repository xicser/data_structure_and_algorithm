/* A + B 和 C */

#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long s64;


int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        s64 A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        if (A + B > C) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }


    return 0;
}
