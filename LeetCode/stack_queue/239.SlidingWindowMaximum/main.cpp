#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class IncreasingQueue {
public:
    void pop(int val) {
        if (dque.empty() == false && dque.front() == val) {
            dque.pop_front();
        }
    }

    void push(int val) {

        while (dque.empty() == false && val > dque.back()) {
            dque.pop_back();
        }

        dque.push_back(val);
    }

    int getMax() {
        return dque.front();
    }

private:
    deque<int> dque;
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        for (int i = 0; i < k; i++) {
            increasingQueue.push(nums[i]);
        }
        result.push_back(increasingQueue.getMax());

        for (unsigned int i = 1, j = k; j < nums.size(); ) {
            increasingQueue.pop(nums[i - 1]);
            increasingQueue.push(nums[j]);
            result.push_back(increasingQueue.getMax());

            i++;
            j++;
        }

        return result;
    }


private:
    IncreasingQueue increasingQueue;
};

int main()
{
    Solution sol;
    vector<int> nums = {4,-2};
    vector<int> result = sol.maxSlidingWindow(nums, 2);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
