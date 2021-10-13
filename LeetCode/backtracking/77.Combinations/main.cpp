#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result;  // 存放符合条件结果的集合
    vector<int> path;            // 存放符合条件结果

    void backtracking(int n, int k, int startIndex) {

        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // for (int i = startIndex; i <= n; i++) {
        for (int i = startIndex; k - path.size() <= n - i + 1; i++) {       // 剪枝优化
                                                                            // k - path.size() 还需要取几个
                                                                            // n - i + 1 最多还能取几个
            path.push_back(i);
            backtracking(n, k, i + 1);

            //回溯
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    sol.combine(4, 4);
    cout << "Hello world!" << endl;
    return 0;
}
