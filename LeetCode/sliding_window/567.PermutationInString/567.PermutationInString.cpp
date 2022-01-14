#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

//Input: s1 = "adc", s2 = "dcda"
class Solution {
private:
    bool check(string& s1, list<char>& sWin, unordered_map<char, int>& needMap) {
        if (s1.size() != sWin.size()) {
            return false;
        }

        unordered_map<char, int> winMap;
        for (char c : sWin) {
            winMap[c]++;
        }

        return winMap == needMap;
    }
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> needMap;
        for (char c : s1) {
            needMap[c]++;
        }

        list<char> winStr;

        int left = 0, right = 0;
        while (right < s2.size()) {
            winStr.push_back(s2[right]);
            right++;

            if (right - left == s1.size()) {
                if (check(s1, winStr, needMap) == true) {
                    return true;
                }
                else {
                    winStr.pop_front();
                    left++;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;


    //unordered_map<char, int> winMap = {{'a', 1}, {'c', 2}};
    //unordered_map<char, int> needMap = { {'a', 1}, {'c', 2} };

    //if (winMap == needMap) {
    //    cout << "aaa34535" << endl;
    //}
    //
    //winMap['a']--;
    //cout << winMap.size();

    std::cout << sol.checkInclusion("adc", "dcda") << endl;
}