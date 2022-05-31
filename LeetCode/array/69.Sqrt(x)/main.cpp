#include <iostream>

using namespace std;


// k^2 <= x 的最大的k值
class Solution {
public:
    int mySqrt(int x) {

        int left = 1;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long val = (long long)mid * (long long)mid;
            if (val == x) {
                return mid;
            }
            else if (val > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left - 1;
    }
};

int main()
{
    Solution sol;

    cout << sol.mySqrt(4) << endl;
    return 0;
}
