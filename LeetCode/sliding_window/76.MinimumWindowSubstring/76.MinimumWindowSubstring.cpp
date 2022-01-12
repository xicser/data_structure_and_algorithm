#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//s = "ADOBEC ODEBANC", t = "ABC"
class Solution {
private:
    //检查当前的window能否满足need的要求
    bool checkWindow(unordered_map<char, int>& window,
                     unordered_map<char, int>& need) {
        for (auto it : need) {
            char c = it.first;
            int cnt = it.second;

            if (window.count(c) == 0 || //当前窗口不存在need中的某个字符
                window[c] < cnt) {      //或者数量不够
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {

        int left = 0, right = 0;
        string result;   //记录结果
        int resultSize = INT_MAX; //结果长度

        unordered_map<char, int> window;  //当前窗口中每个字符出现的次数
        unordered_map<char, int> need;    //根据t计算的需要的字符个数
        for (char c : t) {
            need[c]++;
        }

        while (right < s.size()) {
            window[ s[right] ]++;
            right++;

            //当前窗口满足条件
            while (checkWindow(window, need) == true) {
                int winSize = right - left;
                if (winSize < resultSize) {
                    resultSize = winSize;
                    result = s.substr(left, winSize);
                }
                window[ s[left] ]--;
                left++;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.minWindow("a", "aa") << endl;
}
