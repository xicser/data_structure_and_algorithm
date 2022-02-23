#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        unordered_map<int, int> indexMap;   // <target - nums[i], index>

        for (int i = 0; i < nums.size(); i++) {
            if (indexMap.count(nums[i]) == 0) {
                indexMap.insert(pair<int, int>(target - nums[i], i));
            }
            else {
                result.push_back(indexMap[ nums[i] ]);
                result.push_back(i);
                break;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,7,11,15};
    vector<int> result = sol.twoSum(nums, 9);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
