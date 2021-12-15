#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        if (s.size() < 10) {
            return {};
        }

        unordered_map<string, int> subCountMap; //记录每个子串出现的次数
        vector<string> result;

        for (int i = 0; i <= s.size() - 10; i++) {
            string sub = s.substr(i, 10);
            subCountMap[sub]++;

            //如果这个子串出现次数超过了1次
            if (subCountMap[sub] == 2) {
                result.push_back(sub); //记下来
            }
        }

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
