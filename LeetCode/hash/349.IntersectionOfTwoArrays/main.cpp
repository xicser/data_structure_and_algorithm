#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        unordered_set<int> sNum1;
        for (int i = 0; i < nums1.size(); i++) {
            sNum1.insert(nums1[i]);
        }

        unordered_set<int> sResult;
        for (int i = 0; i < nums2.size(); i++) {
            if (sNum1.find(nums2[i]) != sNum1.end()) {
                sResult.insert(nums2[i]);
            }
        }

        for (auto it = sResult.begin(); it != sResult.end(); it++) {
            result.push_back(*it);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};
    vector<int> result = sol.intersection(nums1, nums2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
