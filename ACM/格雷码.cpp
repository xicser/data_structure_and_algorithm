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
#include <algorithm>

using namespace std;

class GrayCode {
private:
    int n;
    string path;   //记录回溯路径
    vector<string> result; //记录结果

    void backtracking(bool dir) {

        if (path.size() == this->n) {
            //收集结果
            result.push_back(path);

            return;
        }

        //左边的回溯选择列表是[0, 1]
        if (dir == true) {
            vector<char> listLeft = { '0', '1' };
            for (int i = 0; i < listLeft.size(); i++) {
                path.push_back(listLeft[i]);
                if (i == 0) {
                    backtracking(true);
                }
                else {
                    backtracking(false);
                }

                path.pop_back();
            }
        }
        //右边的回溯选择列表是[1, 0]
        else {
            vector<char> listRight = { '1', '0' };
            for (int i = 0; i < listRight.size(); i++) {
                path.push_back(listRight[i]);
                if (i == 0) {
                    backtracking(true);
                }
                else {
                    backtracking(false);
                }

                path.pop_back();
            }
        }
    }

public:
    vector<string> getGray(int n) {
        this->n = n;
        backtracking(true); //第一个列表是[0, 1]

        return result;
    }
};

int main(int argc, char* argv[])
{
    GrayCode sol;
    vector<string> result = sol.getGray(1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}