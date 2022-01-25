#include <iostream>

class Solution {
public:
    int numberOfMatches(int n) {
        int times = 0;

        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
                times += n;
            }
            else {
                times += n / 2;
                n = n / 2 + 1;
            }
        }

        return times;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.numberOfMatches(7) << std::endl;
}
