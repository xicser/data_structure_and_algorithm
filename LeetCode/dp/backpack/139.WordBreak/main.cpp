#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());  //字典

        //dp[i]表示, 字符串长度为i的话, dp[i]为true, 表示可以拆分为在字典中出现的单词
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        //遍历所有子串
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 0; j < i; j++) {

                 string subStr = s.substr(j, i - j);
                 if (dp[j] == true && dict.find(subStr) != dict.end()) {
                    dp[i] = true;
                 }
            }
        }

        return dp[s.size()];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
