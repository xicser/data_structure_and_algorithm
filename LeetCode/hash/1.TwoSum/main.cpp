#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;
        unordered_map<int, int> uMap;
        for (unsigned int i = 0; i < nums.size(); i++) {

            if (uMap.find(nums[i]) != uMap.end()) {
                result.push_back( uMap[ nums[i] ] );
                result.push_back(i);
                break;
            }

            uMap[ target - nums[i] ] = i;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3,3};
    vector<int> result = sol.twoSum(nums, 6);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
