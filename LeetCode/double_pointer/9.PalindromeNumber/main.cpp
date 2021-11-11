#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string strNum = to_string(x);

        int left = 0, right = strNum.size() - 1;

        while (left < right) {
            if (strNum[left] != strNum[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPalindrome(121) << endl;

    return 0;
}
