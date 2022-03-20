#include <iostream>
#include <string>

using namespace std;

//text = "abdcadbc", pattern = "ac"
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {

        char firstChar = pattern[0];
        char secondChar = pattern[1];

        //如果两个相等
        if (firstChar == secondChar) {
            long long cnt = 0;
            for (char c : text) {
                if (c == firstChar) {
                    cnt++;
                }
            }

            //C(cnt + 1, 2);

            return (cnt + 1) * cnt / 2;
        }

        long long sum = 0;
        int firstCnt = 0;
        int secondCnt = 0;
        for (char c : text) {
            if (firstChar == c) {
                firstCnt++;
            }
            if (secondChar == c) {
                sum += firstCnt;
                secondCnt++;
            }
        }

        return max(sum + firstCnt,
                   sum + secondCnt);
    }
};

/*
"iekbksdsmuuzwxbpmcngsfkjvpzuknqguzvzik"
"mp"

"fwymvreuftzgrcrxczjacqovduqaiig"
"yy"
*/
int main()
{
    string text = "fwymvreuftzgrcrxczjacqovduqaiig";
    string pattern = "yy";
    Solution sol;
    cout <<  sol.maximumSubsequenceCount(text, pattern) << endl;
}
