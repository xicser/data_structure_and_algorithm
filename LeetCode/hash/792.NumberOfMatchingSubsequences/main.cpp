#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;


//"abcde", words = ["a","bb","acd","ace"]
class Solution {
public:
    //判断sub是否是str的子序列
    bool isSubsequence(string& str, string& sub) {

        if (str.size() < sub.size()) {
            return false;
        }

        int indexStr = 0, indexSub = 0;

        while (indexStr < str.size() && indexSub < sub.size()) {
            if (str[indexStr] == sub[indexSub]) {
                indexStr++;
                indexSub++;
            }
            else {
                indexStr++;
            }
        }

        return indexSub == sub.size();
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {

        int result = 0;

        //统计words中每个字符串出现的次数
        unordered_map<string, int> mapWordCount;
        for (string& word : words) {
            mapWordCount[word]++;
        }

        //如果words[i]是s的子序列, 那个计入结果
        for (auto it : mapWordCount) {
            string word = it.first;
            if (isSubsequence(s, word) == true) {
                result += mapWordCount[word];
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};

    cout << sol.numMatchingSubseq(s, words) << endl;

    return 0;
}
