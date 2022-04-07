#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
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


using namespace std;

typedef struct {
    int left;
    int right;
} Interval_t;

int main()
{
    int n, L;
    cin >> n >> L;

    deque<Interval_t> intervals;
    for (int i = 0; i < n; i++) {
        Interval_t interval;
        cin >> interval.left >> interval.right;
        intervals.emplace_back(interval);
    }

    sort(intervals.begin(), intervals.end(), [](const Interval_t& I1, const Interval_t& I2) {
        return I1.left < I2.left;
    });

    ////先把用不到的区间给去掉
    //while (1) {
    //    Interval_t back = intervals.back();
    //    if (back.left >= L) {
    //        intervals.pop_back();
    //    }
    //    else {
    //        break;
    //    }
    //}
    //while (1) {
    //    Interval_t front = intervals.front();
    //    if (front.right <= 0) {
    //        intervals.pop_front();
    //    }
    //    else {
    //        break;
    //    }
    //}

    //开始找
    int cnt = 1;
    int lastX = intervals[0].left;
    int lastY = intervals[0].right;

    for (int i = 0; i < intervals.size(); ) {
        bool entered = false;
        int farest = -1;
        int j;
        for (j = i + 1; j < intervals.size(); j++) {
            if (intervals[j].left <= lastY) {
                //记下来最远那个
                farest = max(farest, intervals[j].right);
                entered = true;
            }
            else {
                break;
            }
        }

        //无法覆盖
        if (entered == false) {
            cout << -1 << endl;
            return 0;
        }
        else {
            cnt++;
        }

        lastY = farest;
        i = j - 1;

        if (lastY >= L) {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}
