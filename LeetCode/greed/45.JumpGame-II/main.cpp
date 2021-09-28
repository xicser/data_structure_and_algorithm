#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int lastIndex = nums.size() - 1;
        int steps = 0;
        for (int i = 0; i < nums.size() - 1; ) {

            // 当前所能覆盖的最远位置
            int farestAvailable = i + nums[i];
            if (farestAvailable >= lastIndex) {
                // 再跳最后那一步
                steps++;
                break;
            }

            // 在这个覆盖范围内, 找出能去到最远的那个位置, 然后跳到那里
            int nextIndex;
            int goFarestIndex = -1;
            for (int j = i + 1; j <= farestAvailable; j++) {
                if (nums[j] + j > goFarestIndex) {
                    goFarestIndex = nums[j] + j;
                    nextIndex = j;
                }
            }

            //跳到这个位置, 步数+1
            i = nextIndex;
            steps++;
        }

        return steps;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {2,3,0,1,4};

    cout << sol.jump(nums1) << endl;
    cout << sol.jump(nums2) << endl;

    return 0;
}
