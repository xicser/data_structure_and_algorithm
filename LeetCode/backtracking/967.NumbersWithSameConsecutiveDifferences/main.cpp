#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
Input: n = 3, k = 7
Output: [181,292,707,818,929]
*/
class Solution {
private:
    vector<int> path;
    vector<int> result;

    int vecToInt(vector<int>& path) {
        int sum = 0, k = 1;

        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i] * k;
            k *= 10;
        }

        return sum;
    }
    void backtracking(int n, int k) {

        if (path.size() == n) {
            //�ռ����
            result.push_back(vecToInt(path));
            return;
        }

        for (int i = 0; i <= 9; i++) {

            //��һ�δ��, �϶���1��9
            if (path.size() == 0) {
                if (i != 0) {
                    path.push_back(i);
                    backtracking(n, k);
                    path.pop_back();
                }
                else {
                    continue;
                }
            }
            //�ӵڶ�����ʼ
            else {
                if (abs(path[path.size() - 1] - i) == k) {
                    path.push_back(i);
                    backtracking(n, k);
                    path.pop_back();
                }
            }
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        backtracking(n, k);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.numsSameConsecDiff(3, 7);

    for (auto item : result)
        cout << item << " ";

    cout << endl;

    return 0;
}
