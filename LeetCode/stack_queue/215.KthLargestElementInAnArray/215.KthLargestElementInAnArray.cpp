
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //小根堆
        priority_queue <int, vector<int>, greater<int> > que;

        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]);
        }

        int times = nums.size() - k;
        while (times) {
            que.pop();
            times--;
        }

        return que.top();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
