#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> times(26, 0);

        for (int i = 0; i < ransomNote.size(); i++) {
            times[ransomNote[i] - 'a']++;
        }

        for (int i = 0; i < magazine.size(); i++) {

            //只判断ransomNote里面出现过的字母
            if (times[magazine[i] - 'a'] != 0) {
                times[magazine[i] - 'a']--;
            }
        }


        for (int i = 0; i < 26; i++) {
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
    cout << sol.canConstruct("aa", "aab") << endl;
    return 0;
}
