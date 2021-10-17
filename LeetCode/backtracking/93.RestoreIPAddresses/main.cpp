#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
输入：s = "255 25 51 1135"
输出：["255.255.11.135","255.255.111.35"]
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> res;
        backtracing(0, s.size() - 1, s);

        //加工结果
        for (unsigned int i = 0 ; i < result.size(); i++) {
            string tmpStr;
            for (unsigned int j = 0; j < result[i].size(); j++) {
                if (j != result[i].size() - 1) {
                    tmpStr += result[i][j] + ".";
                }
                else {
                    tmpStr += result[i][j];
                }
            }
            res.push_back(tmpStr);
        }

        return res;
    }

private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracing(int startPos, int endPos, string& str) {

        //切割了3个了, 把最后那个直接放进去就行了
        if (path.size() == 3) {

            //但是要保证是合法的
            string subStr = str.substr(startPos, endPos - startPos + 1);
            if (checkNumStr(subStr) == true) {
                path.push_back(subStr);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }

        for (int i = startPos; i <= endPos; i++) {

            string subStr = str.substr(startPos, i - startPos + 1);

            //剪枝: 如果这次切割的不合法, 就舍弃
            if (checkNumStr(subStr) == false) {
                continue;
            }

            path.push_back(subStr);

            backtracing(i + 1, endPos, str);

            path.pop_back();
        }
    }

    //检测数字是否合法
    bool checkNumStr(const string& str) {

        //空串
        if (str.size() == 0) {
            return false;
        }

        //含有前导0
        if (str[0] == '0' && str.size() != 1) {
            return false;
        }

        int value;
        sscanf(str.data(), "%d", &value);

        if (0 <= value && value <= 255) {
            return true;
        }
        else {
            return false;
        }

    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.restoreIpAddresses("25525511135");
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
