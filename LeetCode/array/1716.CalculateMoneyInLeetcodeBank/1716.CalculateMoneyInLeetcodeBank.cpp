#include <iostream>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {

        int cnt = n / 7;
        int rest = n % 7;

        int start, end;
        int sum = 0;
        int i = 0;
        for (i = 0; i < cnt; i++) {

            start = 1 + i;
            end = start + 6;

            sum += (start + end) * 7 / 2;
        }
        
        start = i + 1;

        for (int i = 0; i < (n - 7 * cnt); i++) {
            sum += start;
            start++;
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.totalMoney(4) << endl;
}
