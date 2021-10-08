#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [=](const vector<int> &I1, const vector<int> &I2){
            //先按照左端点从大到小
            if (I1[0] > I2[0]) {
                return true;
            }
            //若左端点相同, 则按照右端点从小到大
            else if (I1[0] == I2[0] && I1[1] < I2[1]) {
                return true;
            }
            return false;
        });

        int result = 1; //至少需要一支箭
        int lastLeft = intervals[0][0];
        for (unsigned int i = 1; i < intervals.size(); i++) {
            int right = intervals[i][1];
            if (right <= lastLeft) {
                result++;
                lastLeft = intervals[i][0];
            }
        }

        return intervals.size() - result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = { {1,2}, {2,3}, {3,4}, {1,3} };

    cout << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
