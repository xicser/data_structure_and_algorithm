#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {

        if (s.size() < k) {
            return 0;
        }

        //统计每个字符出现的次数
        unordered_map<char, int> charCnt;
        for (char c : s) {
            charCnt[c]++;
        }

        //如果每个字符出现的次数已经 >= k
        bool allBig = true;
        for (auto& it : charCnt) {
            if (it.second < k) {
                allBig = false;
                break;
            }
        }
        if (allBig == true) {
            return s.size();
        }

        int result = INT_MIN;
        int startPos = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int cnt = charCnt[c];

            //这个if必中
            if (cnt < k) {
                string substr = s.substr(startPos, i - startPos);
                startPos = i + 1;
                result = max(result, longestSubstring(substr, k));
            }
        }

        //最后那个字符不是出现次数少于k的字符
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
    cout << sol.longestSubstring("bbaaacbd", 3) << endl;
}