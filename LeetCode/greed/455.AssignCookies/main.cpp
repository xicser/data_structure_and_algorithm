#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int lenG = g.size();
        int lenS = s.size();
        int cnt = 0;
        int i = 0, j = 0;
        while (i < lenG && j < lenS) {
            if (g[i] <= s[j]) {
                cnt++;
                i++;
                j++;
            }
            else {
                j++; //看一下下一块饼干能满足当前这个孩子的胃口
            }
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};

    cout << sol.findContentChildren(g, s) << endl;

    return 0;
}
