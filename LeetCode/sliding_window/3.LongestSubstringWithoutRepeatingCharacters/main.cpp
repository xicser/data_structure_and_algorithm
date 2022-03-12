#include <iostream>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool check(unordered_map<char, int>& window) {
        for (auto& it : window) {
            if (it.second > 1) {
                return false;
            }
        }

        return true;
    }

public:
    int lengthOfLongestSubstring(string s) {

        int result = 0;
        unordered_map<char, int> window;

        int left = 0, right = 0;
        while (right < s.size()) {
            window[ s[right] ]++;
            right++;

            //不满足了的话, 缩小左窗口
            while (check(window) == false) {
                window[ s[left] ]--;
                left++;
            }

            //记录最长的那个
            int winSize = right - left;
            result = max(result, winSize);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    printf("%d\n", solution.lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", solution.lengthOfLongestSubstring("bbbbb"));

    printf("%d\n", solution.lengthOfLongestSubstring("abcac"));
    printf("%d\n", solution.lengthOfLongestSubstring("abba"));
    printf("%d\n", solution.lengthOfLongestSubstring("pwwkew"));


    return 0;
}
