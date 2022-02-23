#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> result;
        unordered_map<int, int> nums1Map;
        for (int i : nums1) {
            nums1Map[i]++;
        }

        for (int i : nums2) {
            if (nums1Map.count(i) != 0) {
                if (nums1Map[i] > 0) {
                    nums1Map[i]--;
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result = sol.intersect(nums1, nums2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
