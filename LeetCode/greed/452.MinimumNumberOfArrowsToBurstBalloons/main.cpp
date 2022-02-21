#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        //先按照左端点由大到小, 左端点相同则按照右端点由小到大
        sort(points.begin(), points.end(), [](const vector<int>& left, const vector<int>& right) {

             if (left[0] != right[0]) {
                return left[0] > right[0];
             }
             else {
                return left[1] < right[1];
             }
        });

        int result = 1;
        int lastLeft = points[0][0];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][1] < lastLeft) {
                result++;
                lastLeft = points[i][0];
            }
        }

        return result;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> points = {{10,16}, {2,8}, {7,6}, {7,12}};

    cout << sol.findMinArrowShots(points) << endl;

    return 0;
}
