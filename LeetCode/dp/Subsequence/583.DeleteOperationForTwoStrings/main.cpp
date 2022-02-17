#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        // dp[i][j] ��ʾA������iλ��(��)֮ǰ
		// ��
		// B������jλ��(��)֮ǰ
		// ��word1���word2����С����
		// ������word1ǰ���word2ǰ���һ����ȵ��ַ�, �Ҹ��ַ����κ�һֱ�ַ��������
		// ���������ַ���Ӱ����
        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0) );

        //dp�����ʼ��
        for (int i = 0; i < len1 + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < len2 + 1; j++) {
            dp[0][j] = j;
        }

        //����dp
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 2,    //ͬʱɾ
                                   min(dp[i - 1][j] + 1,    //ֻɾ��word1
                                   dp[i][j - 1] + 1));      //ֻɾ��word2
                }
            }
        }

        return dp[len1][len2];
    }
};

int main()
{
    Solution sol;
//    string text1 = "bl", text2 = "yby";
    string text1 = "sea", text2 = "eat";
//    string text1 = "leetcode", text2 = "etco";

    cout << sol.minDistance(text1, text2) << endl;

    return 0;
}
