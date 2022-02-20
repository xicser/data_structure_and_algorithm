#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

//Input: s1 = "adc", s2 = "dcda"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> needMap;
        unordered_map<char, int> winMap;

        //先统计s1中每个字符出现的次数
        for (char c : s1) {
            needMap[c]++;
        }

        int left = 0, right = 0;
        while (right < s2.size()) {
            winMap[ s2[right] ]++;
            right++;

            if (right - left == s1.size()) {
                if (needMap == winMap) {
                    return true;
                }
                else {
                    winMap[ s2[left] ]--;

                    //如果当前这个字符的计数变成0了, 那么说明他应经不存在了
                    if (winMap[s2[left]] == 0) {
                        winMap.erase(s2[left]);
                    }
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

    std::cout << sol.checkInclusion("ab", "cdabbb") << endl;
}