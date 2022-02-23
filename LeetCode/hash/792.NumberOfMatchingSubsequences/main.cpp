#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;


//"abcde", words = ["a","bb","acd","ace"]
class Solution {
public:
    //�ж�sub�Ƿ���str��������
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

        //ͳ��words��ÿ���ַ������ֵĴ���
        unordered_map<string, int> mapWordCount;
        for (string& word : words) {
            mapWordCount[word]++;
        }

        //���words[i]��s��������, �Ǹ�������
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
