#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if (nums.size() <= 1) {
            return nums.size();
        }

        int curDiff = 0; // ��ǰ�Բ�ֵ
        int preDiff = 0; // ǰ�Բ�ֵ
        int result = 1;  // ��¼��ֵ����������Ĭ���������ұ��м�����ֵ
        for (unsigned int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // ���ַ�ֵ
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1 = {1,7,4,9,2,5};
    vector<int> nums2 = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums3 = {1,2,3,4,5,6,7,8,9};
    Solution sol;

    cout << sol.wiggleMaxLength(nums1) << endl;
    cout << sol.wiggleMaxLength(nums2) << endl;
    cout << sol.wiggleMaxLength(nums3) << endl;

    return 0;
}
