#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string result;

        vector<int> valVector = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        unordered_map<int, string> valMap = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };

        while (num) {
            int maxVal = findMax(valVector, num);
            result += valMap[maxVal];
            num -= maxVal;
        }

        return result;
    }

private:
    //在valVector中找出比num小的最大的数
    int findMax(vector<int>& valVector, int num) {

        for (int i = valVector.size() - 1; i >= 0; i--) {
            if (valVector[i] <= num) {
                return valVector[i];
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
