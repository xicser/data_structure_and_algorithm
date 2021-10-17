#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {

        backtracking(0, s.size() - 1, s);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(int startPos, int endPos, string &str) {

        //截取到最后了
        if (startPos > endPos) {
            result.push_back(path);
            return;
        }

        for (int i = startPos; i <= endPos; i++) {

            string subStr = str.substr(startPos, i - startPos + 1);

            //剪枝
            if (isPalindrome(subStr) == false) {
                continue;
            }

            path.push_back(subStr);

            backtracking(i + 1, endPos, str);

            //回溯
            path.pop_back();
        }
    }

    //判断string是否是回文
    bool isPalindrome(const string& s) {
        int start = 0, end = s.size() - 1;
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> result = sol.partition("a");

    for (unsigned int i = 0 ; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
