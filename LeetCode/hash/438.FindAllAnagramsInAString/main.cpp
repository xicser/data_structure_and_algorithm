#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int lenS = s.size();
        int lenP = p.size();

        if (lenP > lenS) {
            return {};
        }

        vector<int> result;

        //先统计p中每个字母出现的次数
        vector<int> times(26, 0);
        for (unsigned int i = 0; i < p.size(); i++) {
            times[ p[i] - 'a' ]++;
        }


        //直接先把第一个窗口计算一下
        int left = 0, right = lenP - 1;
        vector<int> win(26, 0);
        for (int i = 0; i < lenP; i++) {
            win[ s[i] - 'a' ]++;
        }

        while (right < lenS) {
            if (times == win) {
                result.push_back(left);
            }
            win[ s[left] - 'a' ]--;
            left++;
            right++;
            if (right >= lenS) {
                break;
            }

            win[ s[right] - 'a' ]++;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.findAnagrams("abab", "ab");
                                         // s             p
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
