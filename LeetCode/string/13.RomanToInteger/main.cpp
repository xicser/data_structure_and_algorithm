#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;
//I, V, X, L, C, D and M
class Solution {
public:
    int romanToInt(string s) {

        unordered_map<string, int> valMap = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
                                             {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900} };
        int result = 0;
        for (int i = 0; i < s.size(); ) {

            if (i + 2 <= s.size() && valMap.find(s.substr(i, 2)) != valMap.end()) {
                result += valMap[s.substr(i, 2)];
                i += 2;
            }
            else {
                result += valMap[s.substr(i, 1)];
                i++;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    cout << sol.romanToInt("MCDLXXVI") << endl;
    return 0;
}
