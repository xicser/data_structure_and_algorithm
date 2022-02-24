#include <iostream>
#include <string>

using namespace std;


//s = "Hello how are you Contestant ", k = 4
class Solution {
public:
    string truncateSentence(string s, int k) {
        s += ' '; //追加一个空格方便处理

        int spaceCnt = 0;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == ' ') {
                spaceCnt++;
                if (spaceCnt == k) {
                    break;
                }
            }
            index++;
        }

        return s.substr(0, index);
    }
};

int main()
{
    Solution sol;

    cout << sol.truncateSentence("chopper is not a tanuki", 5) << endl;
    return 0;
}
