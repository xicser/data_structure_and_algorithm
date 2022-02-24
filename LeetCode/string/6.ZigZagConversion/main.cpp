#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (s.size() == 1 || numRows == 1) {
            return s;
        }

        string result;

        int Tlen = 2 * numRows - 2;
        int Tcnt = s.size() / Tlen + 1;

        for (int row = 0; row < numRows; row++) {

            //第一行 和 最后一行
            if (row == 0 || row == numRows - 1) {
                for (int t = 0; t < Tcnt; t++) {
                    int index = row + Tlen * t;
                    if (index < s.size()) {
                        result.push_back(s[index]);
                    }
                }
            }
            //中间的行
            else {
                for (int t = 0; t < Tcnt; t++) {
                    int indexLeft = row + Tlen * t;
                    int indexRight = Tlen - row + Tlen * t;

                    if (indexLeft < s.size()) {
                        result.push_back(s[indexLeft]);
                    }
                    if (indexRight < s.size()) {
                        result.push_back(s[indexRight]);
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.convert("AB", 1) << endl;

    return 0;
}
