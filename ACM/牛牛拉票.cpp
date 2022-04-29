#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;

//6 2 2 1
bool check(int L, int D, int S, int C) {
    
    long long last = S;
    D--;

    if (D == 0 && last >= L) {
        return true;
    }

    while (D) {
        long long now = last * C + last;
        if (now >= L) {
            return true;
        }
        last = now;

        D--;
    }

    return false;
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int L, D, S, C;
        scanf("%d %d %d %d", &L, &D, &S, &C);

        if (check(L, D, S, C) == true) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}
