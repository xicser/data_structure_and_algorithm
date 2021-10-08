#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), [=](const vector<int> &I1, const vector<int> &I2){
            //�Ȱ�����˵�Ӵ�С
            if (I1[0] > I2[0]) {
                return true;
            }
            //����˵���ͬ, �����Ҷ˵��С����
            else if (I1[0] == I2[0] && I1[1] < I2[1]) {
                return true;
            }
            return false;
        });

        int result = 1; //������Ҫһ֧��
        int lastLeft = points[0][0];
        for (unsigned int i = 1; i < points.size(); i++) {
            int right = points[i][1];
            if (right < lastLeft) {
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
