#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 1) {
            return intervals;
        }

        //按照左端点, 从小打到排序
        sort(intervals.begin(), intervals.end(), [=](const vector<int>& I1, const vector<int>& I2) {
            return I1[0] < I2[0];
        });

        vector<vector<int>> result;

        int newX, newY;
        int lastX = intervals[0][0], lastY = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            newX = intervals[i][0];
            newY = intervals[i][1];
            
            //分情况讨论右端点
            if (newX > lastY) {
                result.push_back({lastX, lastY});
                lastX = newX;
                lastY = newY;
            }
            //else if (newY <= lastY) {

            //}
            else if (newY > lastY && newX <= lastY) {
                lastY = newY;
            }
        }
        result.push_back({ lastX, lastY });

        return result;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> intervals = { {1,4} ,{2,3} };
    vector<vector<int>> result = sol.merge(intervals);

    for (auto& item : result) {
        printf("[%d, %d]\n", item[0], item[1]);
    }

}
