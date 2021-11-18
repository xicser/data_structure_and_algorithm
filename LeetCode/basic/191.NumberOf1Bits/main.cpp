#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n != 0) {
            n = n & (n  - 1);   //n & (n  - 1) Çå³ýµô×îÓÒ±ßµÄ1
            cnt++;
        }

        return cnt;
    }
};

int main()
{
    Solution sol;

    cout << sol.hammingWeight(11) << endl;
    return 0;
}
