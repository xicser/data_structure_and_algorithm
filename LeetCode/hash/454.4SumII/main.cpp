#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> mapSumCount;

        // ��ͳ��nums1��nums2����ÿ�� a + b �Ľ�����ֵĴ���
        for (int a : nums1) {
            for (int b : nums2) {
                mapSumCount[ a + b ]++;
            }
        }

        int cnt = 0;
        //��ͳ��nums3��nums4����ÿ�� == 0 - (c + d) ��
        for (int c : nums3) {
            for (int d : nums4) {
                if (mapSumCount.count(0 - (c + d)) != 0) {
                    cnt += mapSumCount[0 - (c + d)];
                }
            }
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};

    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl;

    return 0;
}
