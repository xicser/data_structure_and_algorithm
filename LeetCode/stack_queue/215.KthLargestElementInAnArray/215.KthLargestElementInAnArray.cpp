
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //大根堆
        priority_queue<int, vector<int>, less<int>> que;

        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]);
        }

        k--;
        while (k--) {
            que.pop();
        }

        return que.top();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
