#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (char c : s) {
            sMap[c]++;
        }
        for (char c : t) {
            tMap[c]++;
        }

        return sMap == tMap;
    }
};

int main()
{
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;
    cout << sol.isAnagram("rat", "car") << endl;

    return 0;
}
