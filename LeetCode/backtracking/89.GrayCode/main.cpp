#include <iostream>
#include <vector>

using namespace std;

////数学方法
//class Solution {
//public:
//    vector<int> grayCode(int n) {
//
//        vector<int> result;
//        int pow = 1 << n;
//
//        for (int i = 0; i < pow; i++) {
//            result.push_back(i ^ (i >> 1));
//        }
//
//        return result;
//    }
//};

//回溯方法
class Solution {
private:
    int n;
    vector<int> path;   //记录回溯路径
    vector<int> result; //记录结果

    void backtracking(bool dir) {

        if (path.size() == this->n) {
            int pathResult = bin2Dec(path);
            //收集结果
            result.push_back(pathResult);

            return;
        }

        //左边的回溯选择列表是[0, 1]
        if (dir == true) {
            vector<int> listLeft = {0, 1};
            for (int i = 0; i < listLeft.size(); i++) {
                path.push_back(listLeft[i]);
                if (i == 0) {
                    backtracking(true);
                }
                else {
                    backtracking(false);
                }

                path.pop_back();
            }
        }
        //右边的回溯选择列表是[1, 0]
        else {
            vector<int> listRight = {1, 0};
            for (int i = 0; i < listRight.size(); i++) {
                path.push_back(listRight[i]);
                if (i == 0) {
                    backtracking(true);
                }
                else {
                    backtracking(false);
                }

                path.pop_back();
            }
        }
    }

    //把二进制序列转换成对应的证书
    int bin2Dec(vector<int> &binSeq) {
        int result = 0;
        int len = binSeq.size();

        for (int i = 0; i < len; i++) {
            if (binSeq[i] == 1) {
                result |= 1 << (len - i - 1);
            }
        }

        return result;
    }

public:
    vector<int> grayCode(int n) {
        this->n = n;
        backtracking(true); //第一个列表是[0, 1]

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.grayCode(1);

//    vector<int> binSeq = {1, 1, 1};
//    cout << sol.bin2Dec(binSeq) << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
