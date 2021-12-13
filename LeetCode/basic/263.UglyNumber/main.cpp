#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {

        if (n == 0) {
            return false;
        }

        if (n == 1) {
            return true;
        }

        int mod2 = n % 2;
        int mod3 = n % 3;
        int mod5 = n % 5;

        if (mod2 == 0) {
            return isUgly(n / 2);
        }
        else if (mod3 == 0) {
            return isUgly(n / 3);
        }
        else if (mod5 == 0) {
            return isUgly(n / 5);
        }
        else {
            return false;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.isUgly(0) << endl;

    return 0;
}
