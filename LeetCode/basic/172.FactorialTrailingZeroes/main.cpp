#include <iostream>

using namespace std;


//数学问题: 统计一下n!中, 5这个因子的个数
class Solution {
public:
    int trailingZeroes(int n) {

        int p = 5;
        int ans = 0;
        while (n) {
            ans += n / p;
            n /= p;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    cout << sol.trailingZeroes(3) << endl;
//    sol.trailingZeroes(3);
//    cout << sol.trailingZeroes(5) << endl;
//    cout << sol.trailingZeroes(0) << endl;

    return 0;
}
