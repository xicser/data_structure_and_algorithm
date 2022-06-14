#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;

        int result = INT_MAX;
        int winSum = 0;
        while (right < nums.size()) {
            winSum += nums[right];
            right++;

            while (winSum >= target) {

                int winSize = right - left;
                result = min(result, winSize);

                winSum -= nums[left];
                left++;
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};

int main()
{
    vector<int> nums = { 2,3,1,2,4,3 };
    Solution sol;
    
    std::cout << sol.minSubArrayLen(7, nums) << endl;
}
