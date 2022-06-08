#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            if (arr[mid - 1] < arr[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};

int main()
{
    vector<int> arr = { 24,69,100,99,79,78,67,36,26,19 };
    Solution sol;

    std::cout << sol.peakIndexInMountainArray(arr) << endl;
}
