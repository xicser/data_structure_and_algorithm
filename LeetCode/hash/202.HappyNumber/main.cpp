#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> valueSet;
        while (1) {

            int sum = calSum(n);
            n = sum;
            if (sum == 1) {
                return true;
            }

            if (valueSet.find(sum) != valueSet.end()) {
                return false;
            }
            else {
                valueSet.insert(sum);
            }
        }
    }

private:
    int calSum(int n) {

        if (n == 0) {
            return 0;
        }

        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
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
