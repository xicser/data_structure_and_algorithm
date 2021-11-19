#include <iostream>
#include <vector>

using namespace std;


/*
1、交换律

2、结合律（即(a^b)^c == a^(b^c)）

3、对于任何数x，都有x^x=0，x^0=x

4、自反性 A XOR B XOR B = A xor  0 = A
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4,1,2,1,2};

    cout << sol.singleNumber(nums) << endl;

    return 0;
}
