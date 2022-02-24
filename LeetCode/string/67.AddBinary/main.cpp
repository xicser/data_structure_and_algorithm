#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {

        string result;

        int carry = 0;     //进位

        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            int val = (a[i] - 48) + (b[j] - 48) + carry;
            result.push_back(val % 2 + 48);
            carry = val / 2;

            i--;
            j--;
        }

        if (i < 0 && j >= 0) {
            while (j >= 0) {
                int val = (b[j] - 48) + carry;
                result.push_back(val % 2 + 48);
                carry = val / 2;
                j--;
            }
        }
        else if (i >= 0 && j < 0) {
            while (i >= 0) {
                int val = (a[i] - 48) + carry;
                result.push_back(val % 2 + 48);
                carry = val / 2;
                i--;
            }
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
    cout << sol.addBinary("11", "1") << endl;

    return 0;
}
