#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//[-7,-8,7,5,7,1,6,0]
//单调栈做法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> que;

        int left = 0, right = 0;
        while (right < nums.size()) {
            //保持队列的单调递减
            while (que.empty() == false && que.back() < nums[right]) {
                que.pop_back();
            }
            que.push_back(nums[right]);

            right++;

            if (right - left == k) {
                result.push_back(que.front());

                if (nums[left] == que.front()) {
                    que.pop_front();
                }
                left++;
            }
        }

        return result;
    }
};

/*
//滑动窗口做法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        multiset<int> st;

        int left = 0, right = 0;
        while (right < nums.size()) {
            st.insert(nums[right]);
            right++;

            if (right - left == k) {
                result.push_back(*(--st.end()));

                auto it = st.find(nums[left]);

                st.erase(it);
                left++;
            }
        }

        return result;
    }
};
*/

int main()
{
    Solution sol;
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    vector<int> result = sol.maxSlidingWindow(nums, 4);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
