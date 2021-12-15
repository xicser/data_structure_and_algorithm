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

        unordered_map<string, int> subCountMap; //��¼ÿ���Ӵ����ֵĴ���
        vector<string> result;

        for (int i = 0; i <= s.size() - 10; i++) {
            string sub = s.substr(i, 10);
            subCountMap[sub]++;

            //�������Ӵ����ִ���������1��
            if (subCountMap[sub] == 2) {
                result.push_back(sub); //������
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
