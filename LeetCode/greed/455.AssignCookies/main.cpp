#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
g = [1,2],
s = [1,2,3]

*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int lenG = g.size();
        int lenS = s.size();

        int i = 0, j = 0;
        while (i < lenG && j < lenS) {

            if (s[j] >= g[i]) {
                result++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return result;
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
