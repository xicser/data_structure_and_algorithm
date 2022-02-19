#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int result = -1;

        int left = 0, right = height.size() - 1;
        while (left < right) {
            int S = (right - left) * min(height[left], height[right]);
            result = max(result, S);

            // 每次都把短板向内移动,
            // 因为移动短板有可能使乘的水变多, 移动长板一定会使乘的水变少
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;

    cout << sol.maxArea(height) << endl;
    return 0;
}
