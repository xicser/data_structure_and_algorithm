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

int main(int argc, char* argv[])
{
    int N;

    while (cin >> N) {

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    map<int, int> valMap;

    //求最小差值
    int deltaMin = INT_MAX;
    for (int i = 0; i < N; i++) {
        valMap[arr[i]]++;

        if (i > 0) {
            deltaMin = min(deltaMin, arr[i] - arr[i - 1]);
        }
    }

    //最小
    int minRes = 0;
    int tempCnt = 1;
    for (int i = 1; i < N; i++) {
        if (deltaMin == arr[i] - arr[i - 1]) {
            tempCnt++;
        }
        else {
            minRes += tempCnt * (tempCnt - 1) / 2;
            tempCnt = 1;
        }
    }
    if (tempCnt != 1) {
        minRes += tempCnt * (tempCnt - 1) / 2;
    }

    cout << minRes << " ";

    //最大
    int first = (*valMap.begin()).second;
    int end = (*(--valMap.end())).second;
    cout << first * end << endl;

    }

    return 0;
}