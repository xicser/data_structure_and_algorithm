#include <iostream>
#include <vector>

using namespace std;

//n = 4
//1 2 3 4
//k = 3
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int start) {

        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {

            //剪纸优化: 如果剩余的元素个数已经小于需要的个数了, 就没有必要搜索了
            int restNeed = k - path.size();
            if (n - i + 1 < restNeed) {
                continue;
            }

            path.push_back(i);

            backtracking(n, k, i + 1);

            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> result = sol.combine(4, 4);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
