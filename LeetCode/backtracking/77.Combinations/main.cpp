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
    vector<vector<int>> result;  // ��ŷ�����������ļ���
    vector<int> path;            // ��ŷ����������

    void backtracking(int n, int k, int startIndex) {

        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // for (int i = startIndex; i <= n; i++) {
        for (int i = startIndex; k - path.size() <= n - i + 1; i++) {       // ��֦�Ż�
                                                                            // k - path.size() ����Ҫȡ����
                                                                            // n - i + 1 ��໹��ȡ����
            path.push_back(i);
            backtracking(n, k, i + 1);

            //����
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
