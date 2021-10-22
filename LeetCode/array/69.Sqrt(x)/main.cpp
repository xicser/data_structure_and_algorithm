#include <iostream>

using namespace std;


// k^2 <= x ������kֵ
class Solution {
public:
    int mySqrt(int x) {

        if (x == 0) {
            return 0;
        }

        if (x == 1) {
            return 1;
        }

        int left = 0, right = x;  //��[0, 2]�϶���

        int root;
        while (left <= right) {

            int mid = (left + right) / 2;
            if ((long long)mid * mid <= x) {
                root = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return root;
    }
};

int main()
{
    Solution sol;

    cout << sol.mySqrt(2) << endl;
    return 0;
}
