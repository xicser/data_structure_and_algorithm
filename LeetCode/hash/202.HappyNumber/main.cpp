#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> s;

        while (1) {
            int sum = calSum(n);
            n = sum;
            if (sum == 1) {
                return true;
            }

            if (s.count(sum) == 0) {
                s.insert(sum);
            }
            else {
                return false;
            }
        }
    }

private:
    //计算n这个数每一位的平方和
    int calSum(int n) {
        int sum = 0;

        while (n) {
            int bit = n % 10;
            sum += bit * bit;

            n /= 10;
        }

        return sum;
    }
};

int main()
{
    Solution sol;

    cout << sol.isHappy(19) << endl;

    return 0;
}
