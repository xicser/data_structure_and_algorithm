#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        long long power = n;

        if (x == 1) {
            return 1;
        }

        if (power > 0) {
            return calPow(x, power);
        }
        else {
            power = -power;
            return 1 / calPow(x, power);
        }
    }

    //快速幂
    double calPow(double x, long long n) {

        if (n == 0) {
            return 1;
        }

        //如果n是偶数
        if (n % 2 == 0) {
            double tmpVal = calPow(x, n / 2);
            return tmpVal * tmpVal;
        }
        else {
            return x * calPow(x, n - 1);
        }
    }
};

int main()
{
    Solution sol;

    cout << sol.myPow(2, -2147483648) << endl;

    return 0;
}
