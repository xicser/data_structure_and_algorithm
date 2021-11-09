#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        vector<int> result;
        int carry = 0;
        int val = digits[ digits.size() - 1 ] + 1;
//        cout << val % 10;       //个位数(结果)
        result.push_back(val % 10);
        carry = val / 10;       //进位

        for (int i = digits.size() - 2; i >= 0; i--) {
            val = digits[i] + carry;
//            cout << val % 10;     //个位数(结果)
            result.push_back(val % 10);
            carry = val / 10;     //进位
        }
        if (carry != 0) {
//            cout << 1;
            result.push_back(1);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> digits = {9, 9, 9, 9};
    vector<int> result = sol.plusOne(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
