#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

void printStk(stack<char>& stk)
{
    while (stk.empty() == false) {
        char c = stk.top();
        printf("%c", c);
        stk.pop();
    }
    printf("\n");
}

//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        stack<char> stkS, stkT;
//
//        for (unsigned int i = 0; i < s.size(); i++) {
//            if (s[i] == '#' && stkS.empty() == true) {
//                continue;
//            }
//
//            if (s[i] == '#' && stkS.empty() == false) {
//                stkS.pop();
//            }
//            else {
//                stkS.push(s[i]);
//            }
//        }
//
//        for (unsigned int i = 0; i < t.size(); i++) {
//            if (t[i] == '#' && stkT.empty() == true) {
//                continue;
//            }
//
//            if (t[i] == '#' && stkT.empty() == false) {
//                stkT.pop();
//            }
//            else {
//                stkT.push(t[i]);
//            }
//        }
//
////        printStk(stkS);
////        printStk(stkT);
////        printf("\n");
//
//        if (stkS.size() != stkT.size()) {
//            return false;
//        }
//
//        while (stkS.empty() == false) {
//            char c1 = stkS.top();
//            stkS.pop();
//
//            char c2 = stkT.top();
//            stkT.pop();
//
//            if (c1 != c2) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//};


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sSkipNum = 0; // 记录S的#数量
        int tSkipNum = 0; // 记录T的#数量
        int i = S.size() - 1;
        int j = T.size() - 1;
        while (1) {
            while (i >= 0) { // 从后向前，消除S的#
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) { // 从后向前，消除T的#
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }

            // 后半部分#消除完了，接下来比较S[i] != T[j]
            if (i < 0 || j < 0) break; // S 或者T 遍历到头了
            if (S[i] != T[j]) return false;

            i--;
            j--;
        }

        // 说明S和T同时遍历完毕
        if (i == -1 && j == -1) return true;
        return false;
    }
};

int main()
{
    Solution sol;

    cout << sol.backspaceCompare("y#fo##f", "y#f#o##f") << endl;
    return 0;
}
