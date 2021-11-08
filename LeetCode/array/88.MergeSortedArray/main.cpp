#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int idx = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] >= nums2[j]) {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
            else if (nums1[i] < nums2[j]) {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }

        if (i == -1 && j >= 0) {
            while (j >= 0) {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }
        else if (i >= 0 && j == -1) {
            while (i >= 0) {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {0}; int m = 0;
    vector<int> nums2 = {1}; int n = 1;

    sol.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
