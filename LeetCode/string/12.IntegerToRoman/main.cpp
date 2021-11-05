#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector< pair<string, int> > valVector = { {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100},
                                              {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000} };

        unordered_map<int, string> valMap = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
                                             {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"} };
        while (num) {
            int equalMax = findEmax(num, valVector); //找小于等于num的最大值

            result += valMap[equalMax];
            num -= equalMax;
        }

        return result;
    }

    int findEmax(int num, vector< pair<string, int> > &valVector) {
        for (int i = valVector.size() - 1; i >= 0; i--) {
            if (valVector[i].second <= num) {
                return valVector[i].second;
            }
        }

        return 1;
    }
};

int main()
{
    Solution sol;

    cout << sol.intToRoman(4) << endl;
    return 0;
}
