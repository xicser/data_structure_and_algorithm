#include <iostream>
#include <vector>

using namespace std;

////��ѧ����
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

//���ݷ���
class Solution {
private:
    int n;
    vector<int> path;   //��¼����·��
    vector<int> result; //��¼���

    void backtracking(bool dir) {

        if (path.size() == this->n) {
            int pathResult = bin2Dec(path);
            //�ռ����
            result.push_back(pathResult);

            return;
        }

        //��ߵĻ���ѡ���б���[0, 1]
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
        //�ұߵĻ���ѡ���б���[1, 0]
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

    //�Ѷ���������ת���ɶ�Ӧ��֤��
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
        backtracking(true); //��һ���б���[0, 1]

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
