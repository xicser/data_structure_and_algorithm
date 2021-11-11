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
        int Tlen = numRows + (numRows - 2);     //周期长度2n - 2
        int Tcnt = s.size() / Tlen + 1;         //周期个数
        int index;

        //遍历每一行
        for (int i = 0; i < numRows; i++) {

            //第一行和最后一行
            if (i == 0 || i == numRows - 1) {
                //遍历周期个数
                for (int j = 0; j < Tcnt; j++) {
                    index = i + j * Tlen;
                    if (index < s.size()) {
                        result.push_back(s[index]);
                    }
                }
            }
            //中间的行
            else {
                int indexLeft = i;
                int indexRight = 2 * numRows - 2 - i;

                //遍历周期个数
                for (int j = 0; j < Tcnt; j++) {
                    int index1 = indexLeft + j * Tlen;
                    int index2 = indexRight + j * Tlen;

                    if (index1 < s.size()) {
                        result.push_back(s[index1]);
                    }
                    if (index2 < s.size()) {
                        result.push_back(s[index2]);
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
