#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend_, int divisor_) {
        long long res = 0;
        bool neg = false;

        long long dividend = dividend_;
        long long divisor = divisor_;
        if ((double)dividend * (double)divisor < 0) {
            neg = true;
        }

        if (dividend < 0) {
            dividend *= -1;
        }
        if (divisor < 0) {
            divisor *= -1;
        }

        while ( dividend >= divisor ) {
            long long tmp = 1;
            long long dor = divisor;
            while (dividend >= dor) {
                dividend -= dor;
                res += tmp;

                dor <<= 2;
                tmp <<= 2;
            }
        }

        if (neg == true) {
            res *= -1;
            //最大只能到INT_MAX
            if (res <= INT_MIN) {
                res = INT_MIN;
            }
        }
        else {
            //最大只能到INT_MAX
            if (res >= INT_MAX) {
                res = INT_MAX;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    cout << sol.divide(-2147483648, -1) << endl;
    return 0;
}
