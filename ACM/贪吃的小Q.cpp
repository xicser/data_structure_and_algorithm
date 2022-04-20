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
#include <map>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;

//第一天吃first个, 一共m个巧克力, 能不能吃够n天？
bool countTotal(int first, int n, int m)
{
    int i;
    for (i = 0; i < n; i++) {
        m -= first;
        if (m < 0) {
            break;
        }
        first = (first + 1) >> 1;
    }

    return i == n;
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = M; i >= 1; i--) {

        if (countTotal(i, N, M) == true) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
