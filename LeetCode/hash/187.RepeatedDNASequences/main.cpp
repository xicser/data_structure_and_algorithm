#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string, int> strTimes;
        unordered_set<string> strSet;
        for (int i = 0; i < s.size(); i++) {
            string sub = s.substr(i, 10);
            strTimes[sub]++;

            if (strTimes[sub] >= 2) {
                strSet.insert(sub);
            }
        }

        vector<string> result(strSet.begin(), strSet.end());

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.findRepeatedDnaSequences("AAAAAAAAAAAAA");

    for (auto item : result) {
        cout << item << endl;
    }

    return 0;
}
