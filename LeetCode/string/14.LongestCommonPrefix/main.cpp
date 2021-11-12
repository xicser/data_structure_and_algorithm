#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string result;
        int len = getMinLen(strs);
        if (len == 0) {
            return "";
        }

        for (int j = 0; j < len; j++) {
            int i = 0;
            for (; i < strs.size() - 1; i++) {
                if (strs[i][j] != strs[i + 1][j]) {
                    break;
                }
            }

            if (i == strs.size() - 1) {
                result.push_back(strs[0][j]);
            }
            else {
                break;
            }
        }

        return result;
    }

private:
    int getMinLen(vector<string>& strs) {
        int len = INT_MAX;

        for (int i = 0; i < strs.size(); i++) {
            if (len > strs[i].size()) {
                len = strs[i].size();
            }
        }

        return len;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"cir", "car"};
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}
