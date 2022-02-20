#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    //s = "ababbaacbbb", k = 3
    int longestSubstring(string s, int k) {

        //s长度小于k, 必然不存在
        if (s.size() < k) {
            return 0;
        }

        //统计s中每个字符出现的次数
        unordered_map<char, int> charCnt;
        for (char c : s) {
            charCnt[c]++;
        }

        //检查每个字符出现次数是否已经>=k
        bool allBig = true;
        for (auto it : charCnt) {
            if (it.second < k) {
                allBig = false;
                break;
            }
        }
        if (allBig == true) {
            return s.size();
        }

        int startPos = 0;
        int result = -1;
        for (int i = 0; i < s.size(); i++) {
            
            char c = s[i];
            if (charCnt[c] < k) {
                string substr = s.substr(startPos, i - startPos);
                startPos = i + 1;

                result = max(result, longestSubstring(substr, k));
            }
        }

        //如果最后一个字符不是c
        if (startPos != s.size()) {
            string substr = s.substr(startPos, s.size() - startPos);
            result = max(result, longestSubstring(substr, k));
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestSubstring("bbaaa", 3) << endl;
}
