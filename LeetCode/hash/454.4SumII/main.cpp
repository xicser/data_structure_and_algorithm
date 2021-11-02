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
                if (mapSumCount.find(a + b) != mapSumCount.end()) {
                    mapSumCount[ a + b ]++;
                }
                else {
                    mapSumCount[ a + b ] = 1;
                }
            }
        }

        int cnt = 0;
        //��ͳ��nums3��nums4����ÿ�� == 0 - (c + d) ��
        for (int c : nums3) {
            for (int d : nums4) {
                if (mapSumCount.find( 0 - (c + d) ) != mapSumCount.end()) {
                    cnt += mapSumCount[ 0 - (c + d) ];
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
