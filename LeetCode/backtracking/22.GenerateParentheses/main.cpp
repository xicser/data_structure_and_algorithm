#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        allCnt = n * 2;
        leftCnt = rightCnt = 0;

        vector<char> arr = {'(', ')'};
        backTracking(arr);

        return result;
    }

private:
    int allCnt;    //总的括号个数
    int leftCnt;   //当前路径的左括号数量
    int rightCnt;  //当前路径的右括号数量
    string path;   //记录当前路径
    vector<string> result;  //最终结果

    void backTracking(const vector<char> &arr) {

        if (path.size() == allCnt) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] == '(') {
                if (leftCnt >= allCnt / 2) {  //剪枝: 左括号个数已经大于一半了
                    continue;
                }
                path.push_back(arr[i]);
                leftCnt++;
            }
            else {
                if (leftCnt <= rightCnt) {   //剪枝: 左括号个数小于右括号个数
                    continue;
                }
                path.push_back(arr[i]);
                rightCnt++;
            }

            backTracking(arr);

            if (arr[i] == '(') {
                leftCnt--;
                path.pop_back();
            }
            else {
                rightCnt--;
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
