#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    //s = "ababbc aacbbb", k = 3
    int longestSubstring(string s, int k) {

        if (s.size() < k) {
            return 0;
        }

        //统计s中每个字符出现的次数
        unordered_map<char, int> charCntMap;
        for (char c : s) {
            charCntMap[c]++;
        }
        //先检查传入的字符是否满足要求
        bool isAll = true;
        for (auto it : charCntMap) {
            if (it.second < k) {
                isAll = false;
                break;
            }
        }
        if (isAll == true) {
            return s.size();  //满足的话, 直接返回长度
        }

        int result = -1;
        int startPos = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (charCntMap[c] < k) {
                string sub = s.substr(startPos, i - startPos);
                startPos = i + 1;

                result = max(longestSubstring(sub, k), result);
            }
        }
        //防止如果结尾的字串, 直接就满足要求（尾部没有出现次数小于k的字符了）, 那么要加进来
        //bbaaa,  k = 3
        if (startPos != s.size()) {
            string sub = s.substr(startPos, s.size() - startPos);
            result = max(longestSubstring(sub, k), result);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestSubstring("bbaaa", 3) << endl;
}
