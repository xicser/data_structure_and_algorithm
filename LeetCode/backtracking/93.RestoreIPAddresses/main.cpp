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
        backtracing(s, 0);

        for (int i = 0; i < result.size(); i++) {
            vector<string>& path = result[i];

            string resTemp;
            for (int j = 0; j < path.size(); j++) {
                resTemp += path[j];
                if (j != path.size() - 1) {
                    resTemp += ".";
                }
            }

            res.push_back(resTemp);
        }

        return res;
    }

private:
    vector< vector<string> > result;
    vector<string> path;

    void backtracing(string& str, int startIndex) {

        if (path.size() == 3) {
            string strLast = str.substr(startIndex, str.size() - startIndex);
            if (isValid(strLast) == false) {
                return;
            }

            path.push_back(strLast);
            result.push_back(path);
            path.pop_back();

            return;
        }

        for (int i = startIndex; i < str.size(); i++) {

            string subStr = str.substr(startIndex, i - startIndex + 1);
            if (isValid(subStr) == false) {
                continue;
            }

            path.push_back(subStr);

            backtracing(str, i + 1);

            path.pop_back();
        }
    }

    //判断给定str是否合法
    bool isValid(string& str) {

        if (str.size() == 0) {
            return false;
        }

        if (str.size() >= 2 && str[0] == '0') {
            return false;
        }

        int val;
        sscanf(str.c_str(), "%d", &val);

        if (0 <= val && val <= 255) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.restoreIpAddresses("101023");
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
