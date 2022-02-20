#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//s = "ADOBEC ODEBANC", t = "ABC"
class Solution {
private:
    //检查当前的window能否满足need的要求
    bool check(unordered_map<char, int>& needWin,
               unordered_map<char, int>& curWin) {
        for (auto& it : needWin) {
            char c = it.first;
            int cnt = it.second;

            if (curWin.count(c) == 0 || curWin[c] < cnt) {
                return false;
            }
        }

        return true;
    }

public:
    string minWindow(string s, string t) {
        
        int left = 0, right = 0;
        int minLen = INT_MAX;
        string strRes;

        unordered_map<char, int> needWin;
        unordered_map<char, int> curWin;

        for (char c : t) {
            needWin[c]++;
        }

        //求“最小”，右指针最开始先一直往右找到第一个满足条件的，然后开始缩小左指针，直到不满足条件
        //期间记录最小满足条件的str
        while (right < s.size()) {
            curWin[ s[right] ]++;
            right++;

            while (check(needWin, curWin) == true) {

                int winSize = right - left;
                if (winSize < minLen) {
                    minLen = winSize;
                    strRes = s.substr(left, winSize);
                }

                curWin[ s[left] ]--;
                left++;
            }
        }

        return strRes;
    }
};

int main()
{
    Solution sol;
    cout << sol.minWindow("a", "aa") << endl;
}
