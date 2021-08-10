#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {

        vector<int> res;
        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int j = 0; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target && i != j) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        return res;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {

        unordered_map <int, int> map; //记录已经遍历过的数, 它和谁匹配
        vector<int> res;
        for(unsigned int i = 0; i < nums.size(); i++) {

            auto iter = map.find(nums[i]);
            if(iter != map.end()) {
                res.push_back(iter->second);
                res.push_back(i);
                return res;
            }
            map.insert(pair<int, int>(target - nums[i], i));
        }
        return res;
    }
};

int main()
{
    int number[] = {2,7,11,15};
    int target = 9;
    vector<int> nums;
    for (unsigned int i = 0; i < sizeof(number) / sizeof(int); i++) {
        nums.push_back(number[i]);
    }

    Solution solution;

    vector<int> res;
    res = solution.twoSum1(nums, target);
    for (unsigned int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }

    res = solution.twoSum2(nums, target);
    for (unsigned int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }

    return 0;
}
