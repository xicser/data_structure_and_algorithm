#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
private:
    vector<int>& nums;
//public:
    //暴力法
//    Solution(vector<int>& nums) : nums(nums) {
//        srand((unsigned)time(NULL));
//    }
//
//    int pick(int target) {
//        vector<int> indexes;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == target) {
//                indexes.push_back(i);
//            }
//        }
//
//        int random = rand() % indexes.size();    //产生0 ~ (cnt - 1)的随机数
//
//        return indexes[random];
//    }

public:
    //蓄水池法
    Solution(vector<int>& nums) : nums(nums) {
        srand((unsigned)time(NULL));
    }

    int pick(int target) {

        int index = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt++; //记录当前找到了第几个target

                // 产生一个0到(cnt - 1)之间的一个随机数, 一共cnt个, 那个cnt == 0的概率就是 1 / cnt
                if ( rand() % cnt == 0 ) {
                    // 以 1 / cnt 的概率保留这个数
                    index = i;
                }
            }
        }

        return index;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
