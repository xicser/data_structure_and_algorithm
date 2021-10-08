#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        //先统计每个字符出现的最远位置
        unordered_map<char, int> farestIndex;
        for (int i = 0; i < s.size(); i++) {
            farestIndex[s[i]] = i;
        }

        vector<int> result;
        int left, right;
        left = right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, farestIndex[s[i]]);

            //如果之前遍历过的字符, 能到达的最远位置等于当前位置i, 说明是分割点
            if (right == i) {
                result.push_back(right - left + 1);
                left = i + 1;
                right = left;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> result = sol.partitionLabels("ababcbacadefegdehijhklij");
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
