#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {

        backtracking(0, s);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(int startPos, string &str) {

        //�Ѿ��и�����
        if (startPos == str.size()) {
            result.push_back(path);
            return;
        }

        for (unsigned int i = startPos; i < str.size(); i++) {

            //�и����г��ȵ��Ӵ�
            string sub = str.substr(startPos, i - startPos + 1);

            //�������·����, ��һ�����ǻ��ĵ��Ӵ�, �ͼ�֦
            if (isPalindrome(sub) == false) {
                continue;
            }

            path.push_back(sub);
            backtracking(i + 1, str);
            path.pop_back();
        }
    }

    //�ж�string�Ƿ��ǻ���
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
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
