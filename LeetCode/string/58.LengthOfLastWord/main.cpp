#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {

        long long endIndex = s.size() - 1;
        long long posRight;

        //先越过末尾的空格
        while (endIndex >= 0 && s[endIndex] == ' ') {
            endIndex--;
        }
        posRight = endIndex;

        while (endIndex >= 0 && s[endIndex] != ' ') {
            endIndex--;
        }

        return abs(endIndex - posRight);
    }
};

int main()
{
    Solution sol;

    cout << sol.lengthOfLastWord("a") << endl;
    cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << sol.lengthOfLastWord("luffy is still joyboy") << endl;


    return 0;
}
