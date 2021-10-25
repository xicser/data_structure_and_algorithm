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
        int sSkipNum = 0; // ��¼S��#����
        int tSkipNum = 0; // ��¼T��#����
        int i = S.size() - 1;
        int j = T.size() - 1;
        while (1) {
            while (i >= 0) { // �Ӻ���ǰ������S��#
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) { // �Ӻ���ǰ������T��#
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }

            // ��벿��#�������ˣ��������Ƚ�S[i] != T[j]
            if (i < 0 || j < 0) break; // S ����T ������ͷ��
            if (S[i] != T[j]) return false;

            i--;
            j--;
        }

        // ˵��S��Tͬʱ�������
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
