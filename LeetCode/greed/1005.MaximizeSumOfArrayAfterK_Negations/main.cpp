#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        priority_queue<int, vector<int>, greater<int>> heap;  //Ð¡¸ù¶Ñ
//        for (unsigned int i = 0; i < nums.size(); i++) {
//            heap.push(nums[i]);
//        }
//
//        while (k > 0) {
//            int t = heap.top();
//            heap.pop();
//            t = -t;
//            heap.push(t);
//
//            k--;
//        }
//
//        int sum = 0;
//        while (heap.size() > 0) {
//            sum += heap.top();
//            heap.pop();
//        }
//
//        return sum;
//    }
//};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end(), [=](int a, int b) {
            return abs(a) > abs(b);
        });

        for (int i = 0; i < nums.size(); i++) {
            if (k > 0 && nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
        }

        k %= 2;
        if (k > 0) {
            nums[nums.size() - 1] *= -1;
        }

        int sum = 0;
        for (int i : nums) {
            sum += i;
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
