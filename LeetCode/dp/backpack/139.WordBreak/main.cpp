#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        //dp[i] == true, 表示[0]->[i - 1]之间的这个子串, 能够拆分成wordDict中的单词
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (dp[j] == true && dict.count(sub) != 0) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main()
{
    Solution sol;
    sol.wordBreak();
    cout << "Hello world!" << endl;
    return 0;
}
