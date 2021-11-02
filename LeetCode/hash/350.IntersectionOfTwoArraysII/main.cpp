#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mapNum1;
        for (int i = 0; i < nums1.size(); i++) {
            if (mapNum1.find(nums1[i]) != mapNum1.end()) {
                mapNum1[ nums1[i] ]++;
            }
            else {
                mapNum1[ nums1[i] ] = 1;
            }
        }

        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (mapNum1.find(nums2[i]) != mapNum1.end()) {
                if (mapNum1[ nums2[i] ] != 0) {
                    mapNum1[ nums2[i] ]--;
                    result.push_back(nums2[i]);
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = sol.intersect(nums1, nums2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
