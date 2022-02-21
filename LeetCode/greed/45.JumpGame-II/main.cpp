#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }

        int steps = 0;
        for (int i = 0; i < nums.size(); ) {

            //�ӵ�ǰλ���ܵ�����Զλ��
            int farestPos = i + nums[i];
            if (farestPos >= nums.size() - 1) {
                return steps + 1;
            }

            //��������Χ��, ����ȥ����Զ���Ǹ�λ��
            int farestIndex = -1;
            int nextIndex;
            for (int j = i; j <= farestPos; j++) {
                if (farestIndex < j + nums[j]) {
                    farestIndex = j + nums[j];
                    nextIndex = j;
                }
            }

            //Ȼ��ȥ���Ǹ�λ��
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
