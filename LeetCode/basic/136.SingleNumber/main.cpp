#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
1、交换律

2、结合律（即(a^b)^c == a^(b^c)）

3、对于任何数x，都有x^x=0，x^0=x

4、自反性 A XOR B XOR B = A xor  0 = A
*/
class Solution {
public:
//    int singleNumber(vector<int>& nums) {
//
//        int result = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            result ^= nums[i];
//        }
//
//        return result;
//    }

//    // -1 1 1 2 2 3 3 4 4 5 5
//    // 0  1 2 3 4 5 6 7 8 9 10
//    int singleNumber(vector<int>& nums) {
//
//        if (nums.size() == 1) {
//            return nums[0];
//        }
//
//        sort(nums.begin(), nums.end());
//
//        for (int i : nums) {
//            printf("%d ", i);
//        }
//        printf("\n");
//
//        int start = 0, end = nums.size() - 1;
//
//        while (start < end) {
//            int mid = start + ((end - start) >> 1);
//
//            if (end - start == 2) {
//                if (nums[mid] == nums[mid - 1]) {
//                    return nums[mid + 1];
//                }
//                else if (nums[mid] == nums[mid + 1]) {
//                    return nums[mid - 1];
//                }
//            }
//
//            if (nums[mid] == nums[mid - 1]) {
//                start = mid + 1;
//            }
//            else if (nums[mid] == nums[mid + 1]) {
//                end = mid - 1;
//            }
//        }
//
//        return nums[start];
//    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,1,2,3,4,5,4,5,3,-1,2};

    cout << sol.singleNumber(nums) << endl;

    return 0;
}
