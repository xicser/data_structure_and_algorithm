#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i : nums) {
            add(i);
        }
    }

    int add(int val) {
        que.push(val);
        if (que.size() > this->k) {
            que.pop();
        }
        return que.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int> > que;  //小根堆
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    std::cout << "Hello World!\n";
}
