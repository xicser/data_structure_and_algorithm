#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> tempArray;

    void mergeSort(vector<int>& nums, int left, int right) {

        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int i = left, j = mid + 1;
        int pos = left;
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) {
                tempArray[pos++] = nums[i];
                i++;
            }
            else {
                tempArray[pos++] = nums[j];
                j++;
            }
        }

        while (i <= mid) {
            tempArray[pos++] = nums[i];
            i++;
        }
        while (j <= right) {
            tempArray[pos++] = nums[j];
            j++;
        }

        copy(tempArray.begin() + left, tempArray.begin() + right + 1, nums.begin() + left);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        tempArray = nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    vector<int> nums = {5, 4, 3};
    Solution sol;
    vector<int> result = sol.sortArray(nums);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}
