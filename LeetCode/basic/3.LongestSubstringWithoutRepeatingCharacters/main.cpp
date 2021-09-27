#include <iostream>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {

        if (s.size() == 1 || s.size() == 0) {
            return s.size();
        }

        unordered_map<char, int> window;        //<字符, 下标>

        unsigned int i = 0, j = 1;
        int maxLen = 1, maxLenRet = -1;

        window.insert(pair<char, int>(s[i], i));
        while (j < s.size()) {
            if (window.find(s[j]) == window.end()) {
                maxLen++;
                if (maxLenRet < maxLen) {
                    maxLenRet = maxLen;
                }

                window.insert(pair<char, int>(s[j], j));
                j++;
            }
            else {
                i = window[ s[j] ] + 1;
                window.clear();
                for (unsigned int k = i; k < j; k++) {
                    window.insert(pair<char, int>(s[k], k));
                }

                maxLen = j - i;
            }
        }

        return maxLenRet;
    }

    int lengthOfLongestSubstring2(string s) {

        unsigned int len = s.size();
        if (len <= 1) {
            return len;
        }

        unordered_map<char, unsigned int> window;        //<字符, 下标>

        unsigned int start = 0, e = 0;
        int maxLen = 0, maxLenRet = -1;

        while (e < len) {
            //在窗口里
            auto iter = window.find( s[e] );
            if (iter != window.end() && window[ s[e] ] >= start) {
                start = window[ s[e] ] + 1;
                window[ s[e] ] = e;
                maxLen = e - start + 1;
                if (maxLenRet < maxLen) {
                    maxLenRet = maxLen;
                }
            }
            else {
                window[ s[e] ] = e;
                maxLen++;
                if (maxLenRet < maxLen) {
                    maxLenRet = maxLen;
                }
            }
            e++;
        }

        return maxLenRet;
    }
};

int main()
{
    Solution solution;
    printf("%d\n", solution.lengthOfLongestSubstring1("abcabcbb"));
    printf("%d\n", solution.lengthOfLongestSubstring1("bbbbb"));

    printf("%d\n", solution.lengthOfLongestSubstring2("abcac"));
    printf("%d\n", solution.lengthOfLongestSubstring2("abba"));
    printf("%d\n", solution.lengthOfLongestSubstring2("pwwkew"));


    return 0;
}
