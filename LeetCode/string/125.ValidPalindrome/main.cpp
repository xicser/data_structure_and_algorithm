#include <iostream>
#include <stdio.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            char cLeft, cRight;
            if (isAlphabetNumber(s[left]) == true) {
                cLeft = toLower(s[left]);
            } else {
                left++;
                continue;
            }

            if (isAlphabetNumber(s[right]) == true) {
                cRight = toLower(s[right]);
            } else {
                right--;
                continue;
            }

            if (cLeft != cRight) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool isAlphabetNumber(char c) {
        if ('a' <= c && c <= 'z') {
            return true;
        }
        if ('A' <= c && c <= 'Z') {
            return true;
        }
        if ('0' <= c && c <= '9') {
            return true;
        }

        return false;
    }

    char toLower(char c) {
        if ('a' <= c && c <= 'z') {
            return c;
        }
        else if ('A' <= c && c <= 'Z') {
            return c + 32;
        }
        else {
            return c;
        }
    }
};

int main()
{
    Solution sol;
//    printf("%c\n", sol.toLower('A'));
    printf("%d\n", sol.isPalindrome("A man, a plan, a canal: Panama"));
    printf("%d\n", sol.isPalindrome("0P"));

    return 0;
}
