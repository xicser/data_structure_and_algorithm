#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0) {
            return {};
        }

        this->digitsLen = digits.size();
        this->digits = digits;
        backtracking(0);

        return result;
    }

private:

    //index是digits的字母位置
    void backtracking(int index) {

        if (path.size() == this->digitsLen) {
            result.push_back(path);
            return;
        }

        //当前按下的数字
        char cDigit = this->digits[index];

        //遍历当前选中的字符串
        for (unsigned int i = 0; i < strMap[cDigit].size(); i++) {

            path.push_back(strMap[cDigit][i]);

            backtracking(index + 1);

            //回溯
            path.pop_back();
        }
    }

    int digitsLen;
    string digits;
    string path;
    vector<string> result;

    //字母映射表
    map<char, string> strMap = {
        {'0', ""},                      // 0
        {'1', ""},                      // 1
        {'2', "abc"},                   // 2
        {'3', "def"},                   // 3
        {'4', "ghi"},                   // 4
        {'5', "jkl"},                   // 5
        {'6', "mno"},                   // 6
        {'7', "pqrs"},                  // 7
        {'8', "tuv"},                   // 8
        {'9', "wxyz"}                   // 9
    };
};

int main()
{
    Solution sol;
    vector<string> result = sol.letterCombinations("23");

    for (unsigned int i = 0 ; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
