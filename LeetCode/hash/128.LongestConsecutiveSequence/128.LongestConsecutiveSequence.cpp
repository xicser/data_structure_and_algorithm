#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0;
        }

        set<int> st;
        for (int val : nums) {
            st.insert(val);
        }

        int result = 1;
        for (int i = 0; i < nums.size(); i++) {

            //如果nums[i] - 1不在set中, 说明nums[i]是起点
            if (st.count(nums[i] - 1) == 0) {

                //开始遍历, set本身就是有序的
                auto it = st.find(nums[i]);
                int last = nums[i];
                int len = 1;
                it++;
                for (; it != st.end(); it++) {
                    int val = *it;
                    if (val - last == 1) {
                        len++;
                        result = max(result, len);
                        last = val;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 0, 0 };

    std::cout << sol.longestConsecutive(nums) << endl;

    return 0;
}
