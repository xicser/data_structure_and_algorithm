#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long long eor = 0;
        for (int i = 0; i < nums.size(); i++) {
            eor ^= nums[i];
        }
        //此时eor = a ^ b

        //提取最右侧的1
        long long rightOne = eor & ( (~eor) + 1 );

        long long eorA = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (rightOne & nums[i]) {
                eorA ^= nums[i];
            }
        }

        return {(int)eorA, int(eorA ^ eor)};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,1,0,-2147483648};
    vector<int> result = sol.singleNumber(nums);
    cout << result[0] << endl;
    cout << result[1] << endl;

    return 0;
}
