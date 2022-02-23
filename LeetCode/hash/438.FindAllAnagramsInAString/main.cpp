#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>

using namespace std;

//s = "cbaebabacd", p = "abc"
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int len = p.size();
        vector<int> result;
        unordered_map<char, int> needMap;
        unordered_map<char, int> winMap;

        for (char c : p) {
            needMap[c]++;
        }

        int left = 0, right = 0;
        while (right < s.size()) {
            winMap[ s[right] ]++;
            right++;

            if (right - left == len) {
                if (needMap == winMap) {
                    result.push_back(left);
                }
                winMap[ s[left] ]--;
                if (winMap[ s[left] ] == 0) {
                    winMap.erase(s[left]);
                }

                left++;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.findAnagrams("abab", "ab");
                                         // s             p
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
