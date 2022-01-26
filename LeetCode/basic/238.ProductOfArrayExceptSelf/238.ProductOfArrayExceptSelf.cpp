#include <iostream>
#include <vector>

using namespace std;

//  1  2  5   4
//  1  1  2   10
//  

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        //先计算每个数左边的乘积
        int product = 1;
        result[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            product *= nums[i - 1];
            result[i] = product;
        }

        //再计算每个数右边的成绩
        product = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            product *= nums[i + 1];
            result[i] = product * result[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,  2,  5,   4 };
    sol.productExceptSelf(nums);
}
