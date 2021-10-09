#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string number = to_string(n);
        int len = number.size();

        /*
        ����strNum[i - 1] > strNum[i]�����, ��strNum[i-1]--, Ȼ��strNum[i]��Ϊ9, ���Ա�֤����λ
        �����󵥵��������Ǽ�������
        */

        int idx = len;
        for (int i = len - 2; i >= 0; i--) {
            if (number[i] > number[i + 1]) {
                number[i]--;
                idx = i + 1;
            }
        }

        for (int i = idx; i < len; i++) {
            number[i] = '9';
        }

        return stoi(number);
    }
};

int main()
{
    Solution sol;

    cout << sol.monotoneIncreasingDigits(120) << endl;
    return 0;
}
