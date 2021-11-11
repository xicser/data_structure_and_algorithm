#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        n -= 1;
        while (n--) {
            result = calNext(result);
        }

        return result;
    }
/*
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/
    //基于当前的str, 计算下一个str
    string calNext(string inStr) {

        string next;
        for (int i = 0; i < inStr.size(); ) {
            int cnt = 1;
            int j = i;
            while (j + 1 < inStr.size() && inStr[j] == inStr[j + 1]) {
                cnt++;
                j++;
            }
            next += to_string(cnt);
            next.push_back(inStr[i]);

            i = j + 1;
        }

        return next;
    }
};

int main()
{
    Solution sol;
    cout << sol.countAndSay(1) << endl;
    return 0;
}
