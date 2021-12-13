#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> times(26, 0);
        for (unsigned int i = 0; i < s.size(); i++) {
            times[s[i] - 'a']++;
        }

        for (unsigned int i = 0; i < t.size(); i++) {
            times[t[i] - 'a']--;
        }

        for (unsigned int i = 0; i < times.size(); i++) {
            if (times[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;
    cout << sol.isAnagram("rat", "car") << endl;

    return 0;
}
