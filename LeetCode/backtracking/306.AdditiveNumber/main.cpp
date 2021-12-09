#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

//"112358"
class Solution {
private:
    vector<string> path;
    bool isAdditiveNum;

    void backtracking(int startIndex, string& num) {

        if (startIndex == num.size()) {

            if (path.size() > 2) {
                isAdditiveNum = true;
//                for (auto item : path) {
//                    cout << item << " ";
//                }
//                cout << endl;
            }

            return;
        }

        for (unsigned int i = startIndex; i < num.size(); i++) {
            //�ָ�������Ӵ�
            string sub = num.substr(startIndex, i - startIndex + 1);

            //��֦
            if (sub.size() >= 2 && sub[0] == '0') {
                continue;
            }

            //ǰ�����Ӵ�ֱ�ӷŽ�ȥ
            if (path.size() < 2) {
                path.push_back(sub);
            }
            else {

                unsigned long long lastLastVal = str2num(path[ path.size() - 2 ]);
                unsigned long long lastVal = str2num(path[ path.size() - 1 ]);
                unsigned long long nowVal = str2num(sub);
                if (nowVal != lastLastVal + lastVal) {
                    continue; //�˴��൱�ڼ�֦: ����ȵļ���
                }
                else {
                    path.push_back(sub);
                }
            }

            backtracking(i + 1, num);

            path.pop_back();
        }
    }

    //���ַ���strת���ɶ�Ӧ������
    unsigned long long str2num(string& str) {
        unsigned long long sum = 0;
        unsigned long long k = 1;
        for (int i = str.size() - 1; i >= 0; i--) {
            sum += (str[i] - 48) * k;
            k *= 10;
        }

        return sum;
    }

public:
    bool isAdditiveNumber(string num) {
        this->isAdditiveNum = false;
        backtracking(0, num);
        return isAdditiveNum;
    }
};

int main()
{
    Solution sol;
    string num = "101123581321345589144";
    printf("result = %d\n", sol.isAdditiveNumber(num));

    return 0;
}
