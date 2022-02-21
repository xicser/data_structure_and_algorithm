#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        //先统计每个字符出现的最远位置
        unordered_map<char, int> farestPosMap;
        for (int i = 0; i < s.size(); i++) {

            if (farestPosMap.count(s[i]) == 0) {
                farestPosMap[s[i]] = i;
            }
            else {
                int pos = farestPosMap[ s[i] ];
                if (pos < i) {
                    farestPosMap[s[i]] = i;
                }
            }
        }

//        for (auto& it : farestPosMap) {
//            printf("%c %d\n", it.first, it.second);
//        }

        vector<int> result;

        //遍历字符串
        int far = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            far = max(farestPosMap[ s[i] ], far);
            if (far == i) {
                result.push_back(i - start + 1);
                start = i + 1;
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
