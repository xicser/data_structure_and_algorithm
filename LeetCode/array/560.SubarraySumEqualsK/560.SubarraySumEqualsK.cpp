#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* nums = [1,2,3], k = 3 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int result = 0;

        unordered_map<int, int> preSumMap;  //记录每个前缀和数值出现的次数

        int preSum = 0;
        preSumMap[preSum] = 1;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            //如果之前出现过preSum - k的前缀和, 说明出现了和为k的连续子数组
            if (preSumMap.count(preSum - k) != 0) {
                result += preSumMap[preSum - k];
            }

            preSumMap[preSum]++;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = { 1,1,1 };
    Solution sol;
    
    std::cout << sol.subarraySum(nums, 2) << endl;
}
