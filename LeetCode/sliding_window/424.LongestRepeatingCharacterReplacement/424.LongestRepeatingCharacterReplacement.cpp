#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    //判断window中, 出现次数较少的字符的个数是否大于k
    bool check(unordered_map<char, int>& winMap, int k) {

        //记录出现次数最多的字符
        char c;
        int cnt = INT_MIN;
        int cntAll = 0;
        for (auto it : winMap) {
            char cTmp = it.first;
            int cntTmp = it.second;
            cntAll += cntTmp;

            if (cnt < cntTmp) {
                cnt = cntTmp;
                c = cTmp;
            }
        }
        int resCnt = cntAll - cnt;

        return resCnt > k;
    }

public:
    //"ABABCDEFG", k = 2
    int characterReplacement(string s, int k) {

        int result = 0;
        int left = 0, right = 0;
        int winCnt = 0;
        unordered_map<char, int> winMap;

        while (right < s.size()) {
            winMap[ s[right] ]++;
            right++;

            //如果窗口出现次数较少的字符的个数已经超过了k
            while (check(winMap, k) == true) {
                winMap[ s[left] ]--;
                left++;
            }

            //记录最大的
            int winSize = right - left;
            result = max(winSize, result);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.characterReplacement("AABABBA", 1) << endl;
}
