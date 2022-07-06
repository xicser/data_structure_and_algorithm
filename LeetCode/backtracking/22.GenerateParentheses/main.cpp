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
    int allCnt;    //�ܵ����Ÿ���
    int leftCnt;   //��ǰ·��������������
    int rightCnt;  //��ǰ·��������������
    string path;   //��¼��ǰ·��
    vector<string> result;  //���ս��

    void backTracking(const vector<char> &arr) {

        if (path.size() == allCnt) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] == '(') {
                if (leftCnt >= allCnt / 2) {  //��֦: �����Ÿ����Ѿ�����һ����
                    continue;
                }
                path.push_back(arr[i]);
                leftCnt++;
            }
            else {
                if (leftCnt <= rightCnt) {   //��֦: �����Ÿ���С�������Ÿ���
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
