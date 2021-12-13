#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map< string, vector<string> > bucket;

        for (int i = 0; i < strs.size(); i++) {

            string key = strs[i];

            //同种异位词, 排序之后的结果是一样的, 可以作为map的key
            //同一个key上存储的是, 同种异位词
            sort(key.begin(), key.end());

            if (bucket.find(key) == bucket.end()) {
                vector<string> tmpVec;
                tmpVec.push_back(strs[i]);
                bucket[key] = tmpVec;
            }
            else {
                vector<string> tmpVec = bucket[key];
                tmpVec.push_back(strs[i]);
                bucket[key] = tmpVec;
            }
        }

        vector<vector<string>> result;
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            vector<string> tmpVec = it->second;
            result.push_back(tmpVec);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
