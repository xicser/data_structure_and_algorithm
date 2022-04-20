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

int main(void)
{
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end(), [](int a, int b) {
        return a > b;
    });

    bool which = true;
    int niuScore = 0, yangScore = 0;
    for (int i = 0; i < n; i++) {
        if (which) {
            niuScore += input[i];
            which = false;
        }
        else {
            yangScore += input[i];
            which = true;
        }
    }

    cout << niuScore - yangScore << endl;

    return 0;
}
