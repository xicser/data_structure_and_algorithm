#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        qSort(nums, 0, nums.size() - 1);
    }

private:
    void qSort(vector<int>& nums, int left, int right) {

        if (right < left) {
            return;
        }

        int pos = partition(nums, left, right);
        qSort(nums, left, pos - 1);
        qSort(nums, pos + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        while (left < right) {

            while (left < right && nums[right] > temp) {
                right--;
            }
            nums[left] = nums[right];

            while (left < right && nums[left] <= temp) {
                left++;
            }
            nums[right] = nums[left];
        }

        nums[left] = temp;

        return left;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
