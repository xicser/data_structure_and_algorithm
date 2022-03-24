#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {

        string result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 && j >= 0) {
            int val1 = num1[i] - 48;
            int val2 = num2[j] - 48;
            int sum = val1 + val2 + carry;

            int geBit = sum % 10;
            carry = sum / 10;

            result.push_back(geBit + 48);

            i--;
            j--;
        }

        while (i >= 0) {
            int val = num1[i] - 48;
            int sum = val + carry;

            int geBit = sum % 10;
            carry = sum / 10;

            result.push_back(geBit + 48);

            i--;
        }

        while (j >= 0) {
            int val = num2[j] - 48;
            int sum = val + carry;

            int geBit = sum % 10;
            carry = sum / 10;

            result.push_back(geBit + 48);

            j--;
        }

        if (carry != 0) {
            result.push_back(carry + 48);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.addStrings("11", "123") << endl;

    return 0;
}
