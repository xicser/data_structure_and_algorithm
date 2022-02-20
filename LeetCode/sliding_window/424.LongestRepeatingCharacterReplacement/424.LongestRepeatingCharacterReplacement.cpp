#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    //检查窗口中出现次数较少的字符能否
    bool check(unordered_map<char, int>& windowCnt, int k) {
        int allCnt = 0;
        int maxCnt = 0;

        for (auto &it : windowCnt) {
            char c = it.first;
            int cnt = it.second;
            allCnt += cnt;

            maxCnt = max(maxCnt, cnt);
        }

        int rest = allCnt - maxCnt;

        return k >= rest;
    }

public:
    //"ABABCDEFG", k = 2
    int characterReplacement(string s, int k) {

        int result = INT_MIN;
        unordered_map<char, int> windowCnt;

        int left = 0, right = 0;
        while (right < s.size()) {
            windowCnt[ s[right] ]++;
            right++;

            //如果窗口不满足了, 移动left, 直到窗口重新满足
            while (check(windowCnt, k) == false) {
                windowCnt[ s[left] ]--;
                left++;
            }

            //记录最大那个窗口
            int winSize = right - left;
            result = max(result, winSize);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.characterReplacement("AABABBA", 1) << endl;
}
