#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        if (num == 1) {
            return true;
        }

        int left = 1, right = num;
        while (left <= right) {

            int mid = left + (right - left) / 2;

            if ((long long)mid * mid == num) {
                return true;
            }
            else if ((long long)mid * mid > num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    cout << sol.isPerfectSquare(104976) << endl;
    cout << sol.isPerfectSquare(2) << endl;

    return 0;
}
