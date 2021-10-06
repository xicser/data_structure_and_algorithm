#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;  //Ð¡¸ù¶Ñ
        for (unsigned int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
        }

        while (k > 0) {
            int t = heap.top();
            heap.pop();
            t = -t;
            heap.push(t);

            k--;
        }

        int sum = 0;
        while (heap.size() > 0) {
            sum += heap.top();
            heap.pop();
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4,2,3};
    vector<int> nums2 = {3,-1,0,2};
    vector<int> nums3 = {2,-3,-1,5,-4};

    cout << sol.largestSumAfterKNegations(nums1, 1) << endl;
    cout << sol.largestSumAfterKNegations(nums2, 3) << endl;
    cout << sol.largestSumAfterKNegations(nums3, 2) << endl;

    return 0;
}
