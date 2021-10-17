#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
���룺s = "255 25 51 1135"
�����["255.255.11.135","255.255.111.35"]
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> res;
        backtracing(0, s.size() - 1, s);

        //�ӹ����
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

        //�и���3����, ������Ǹ�ֱ�ӷŽ�ȥ������
        if (path.size() == 3) {

            //����Ҫ��֤�ǺϷ���
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

            //��֦: �������и�Ĳ��Ϸ�, ������
            if (checkNumStr(subStr) == false) {
                continue;
            }

            path.push_back(subStr);

            backtracing(i + 1, endPos, str);

            path.pop_back();
        }
    }

    //��������Ƿ�Ϸ�
    bool checkNumStr(const string& str) {

        //�մ�
        if (str.size() == 0) {
            return false;
        }

        //����ǰ��0
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
