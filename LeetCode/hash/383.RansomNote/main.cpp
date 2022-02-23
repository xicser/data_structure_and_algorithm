#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> magMap;
        for (char c : magazine) {
            magMap[c]++;
        }

        for (char c : ransomNote) {
            if (magMap[c] > 0) {
                magMap[c]--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.canConstruct("aa", "aab") << endl;
    return 0;
}
