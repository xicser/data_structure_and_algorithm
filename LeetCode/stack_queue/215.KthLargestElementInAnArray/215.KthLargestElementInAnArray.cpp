
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

private:
    int partition(vector<int>& nums, int left, int right) {
        
        int len = right - left + 1;
        int index = rand() % len + left;

        swap(nums[left], nums[index]);

        int temp = nums[left];

        while (left < right) {

            while (left < right && nums[right] < temp) {
                right--;
            }
            nums[left] = nums[right];

            while (left < right && nums[left] >= temp) {
                left++;
            }
            nums[right] = nums[left];
        }

        nums[left] = temp;

        return left;
    }

    //求第k大的数
    int maxKth(vector<int>& nums, int left, int right, int k) {
        
        if (left == right) {
            return nums[left];
        }
        
        //pos（含）左边的都>=主元
        int pos = partition(nums, left, right);

        int leftCnt = pos - left + 1;

        if (leftCnt == k) {
            return nums[pos];
        }
        else if (leftCnt > k) {
            return maxKth(nums, left, pos - 1, k);
        }
        else {
            return maxKth(nums, pos + 1, right, k - leftCnt);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return maxKth(nums, 0, nums.size() - 1, k);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
