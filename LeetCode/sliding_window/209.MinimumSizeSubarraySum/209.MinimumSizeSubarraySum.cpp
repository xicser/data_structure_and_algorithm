#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0, right = 0;
        int winSum = 0;

        int minLen = INT_MAX;

        while (right < nums.size()) {
            winSum += nums[right];
            right++;

            while (winSum >= target) {
                int winSize = right - left;
                if (minLen > winSize) {
                    minLen = winSize;
                }

                winSum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main()
{
    vector<int> nums = { 2,3,1,2,4,3 };
    Solution sol;
    
    std::cout << sol.minSubArrayLen(7, nums) << endl;
}
