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

void print(vector< vector<int> >& array) {

    for (int i = 0; i < array.size(); i++) {
        int len = array[i].size();
        for (int j = 0; j < len; j++) {
            printf("%d", array[i][j]);
            if (j != len - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int seq;
void fillLine(int left, int top, int right, int bottom, vector< vector<int> >& array) {

    while (left <= right && top <= bottom) {
        array[top][left] = seq++;

        top++;
        left++;
    }
}

void fill(int n)
{
    seq = 1;
    vector< vector<int> > array(n, vector<int>(n, 0));

    //先把对角线
    fillLine(0, 0, n - 1, n - 1, array);
    
    bool which = true; //true表示右上

    int Up_left, Up_top, Up_right, Up_bottom;
    int Down_left, Down_top, Down_right, Down_bottom;

    Up_left = 1;
    Up_top = 0;
    Up_right = n - 1;
    Up_bottom = n - 2;

    Down_left = 0;
    Down_top = n - 1;
    Down_right = 0;
    Down_bottom = n - 1;

    while (Up_left <= n - 1 || Down_right <= n - 2) {

        if (which) {
            which = false;

            fillLine(Up_left, Up_top, Up_right, Up_bottom, array);
            Up_left++;
            Up_bottom--;
        }
        else {
            which = true;

            fillLine(Down_left, Down_top, Down_right, Down_bottom, array);
            Down_top--;
            Down_right++;
        }
    }

    print(array);
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        fill(n);
    }
}
