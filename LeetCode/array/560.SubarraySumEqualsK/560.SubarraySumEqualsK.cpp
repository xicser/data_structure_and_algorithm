#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* nums = [1,2,3], k = 3 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        unordered_map<int, int> mapPreSum;

        int preSum = 0;
        mapPreSum[preSum] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i]; //计算当前前缀和

            //如果之前有preSum - k的前缀和, 说明出现了和为k的子数组
            if (mapPreSum.count(preSum - k) != 0) {
                int val = mapPreSum[preSum - k];
                count += val;
            }

            mapPreSum[preSum]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = { 1,1,1 };
    Solution sol;
    
    std::cout << sol.subarraySum(nums, 2) << endl;
}
