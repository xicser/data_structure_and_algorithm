#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
private:
    //检查当前窗口中, 任意两个元素之间的差值绝对值是否 <= limit
    bool check(multiset<int>& winNums, int limit) {
        int max = * (winNums.begin());
        int min = * (--winNums.end());
        return abs(max - min) <= limit;
    }

public:
    // nums = [8,2,4,7], limit = 4
    int longestSubarray(vector<int>& nums, int limit) {

        int left = 0, right = 0;
        int result = 0;

        //记录当前窗口中的数的下标
        multiset<int> winNums;

        while (right < nums.size()) {

            winNums.insert(nums[right]);
            right++;

            while (check(winNums, limit) == false) {
                multiset <int>::iterator pos = winNums.find(nums[left]);
                winNums.erase(pos);
                left++;
            }

            int winSize = right - left;
            result = max(result, winSize);
        }

        return result;
    }
};

/*
[4,2,2,2,4,4,2,2]
0
*/
int main()
{
    vector<int> nums = { 2,2,2,4,4,2,5,5,5,5,5,2 };
    Solution sol;
    
    std::cout << sol.longestSubarray(nums, 2) << endl;
}
