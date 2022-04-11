#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string& word1, string& word2) {

        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        int len = word1.size();

        //dp[i]表示将word1[0:i]转换成word2[0:i]所需要的最小步骤
        vector<int> dp(len);
        dp[0] = abs(word1[0] - word2[0]);

        //dp数组初始化
        for (int i = 1; i < len; i++) {
            
            if (word1[i] == word2[i]) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1] + abs(word1[i] - word2[i]);
            }
        }

        return dp[len - 1];
    }
};

int main()
{
    int N;
    cin >> N;

    string str1, str2;
    cin >> str1 >> str2;

    Solution sol;
    cout << sol.minDistance(str1, str2) << endl;
}
