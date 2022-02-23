#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> result;
        int times = nums.size() / 3;
        unordered_map<int, int> mapNumCnt;

        for (int i = 0; i < nums.size(); i++) {
            mapNumCnt[ nums[i] ]++;
        }

        for (auto it : mapNumCnt) {
            if (it.second > times) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 3, 4};

    vector<int> result = sol.majorityElement(nums);
    for (auto item : result) {
        cout << item << endl;
    }

    return 0;
}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// 1,1,1,3,3,2,2,2
//class Solution {
//public:
//    vector<int> majorityElement(vector<int>& nums) {
//
//        if (nums.size() == 1) {
//            return nums;
//        }
//
//        vector<int> result;
//
//        int candidate1 = 0, candCount1 = 0;
//        int candidate2 = 0, candCount2 = 0;
//
//        //摩尔投票法
//        for (int num : nums) {
//
//            if (candidate1 == num) {
//                candCount1++;
//            }
//            else if (candidate2 == num) {
//                candCount2++;
//            }
//            else {
//                if (candCount1 == 0) {
//                    candCount1 = 1;
//                    candidate1 = num;
//                }
//                else if (candidate2 == 0) {
//                    candCount2 = 1;
//                    candidate2 = num;
//                }
//                else {
//                    candCount1--;
//                    candidate2--;
//                }
//            }
//        }
//
//        //选出可能的众数之后, 进一步确认
//        int cnt1 = 0, cnt2 = 0;
//        for (int num : nums) {
//            if (num == candidate1) {
//                cnt1++;
//            }
//            if (num == candidate2) {
//                cnt2++;
//            }
//        }
//
////        cout << candidate1 << " " << cnt1 << endl;
////        cout << candidate2 << " " << cnt2 << endl;
//
//        //如果两个候选者一样, 返回一个就行
//        if (candidate1 == candidate2 && cnt1 > nums.size() / 3) {
//            result.push_back(candidate1);
//            return result;
//        }
//
//        if (cnt1 > nums.size() / 3) {
//            result.push_back(candidate1);
//        }
//        if (cnt2 > nums.size() / 3) {
//            result.push_back(candidate2);
//        }
//
//        return result;
//    }
//};
//
//int main()
//{
//    Solution sol;
//    vector<int> nums = {1, 3, 3, 4};
//
//    vector<int> result = sol.majorityElement(nums);
//    for (auto item : result) {
//        cout << item << endl;
//    }
//
//    return 0;
//}
