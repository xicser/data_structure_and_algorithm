#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string number = std::to_string(n);

        /*
        ����strNum[i - 1] > strNum[i]�����, ��strNum[i-1]--, Ȼ��strNum[i]��Ϊ9, ���Ա�֤����λ
        �����󵥵��������Ǽ�������
        */

        int index = -1;
        for (int i = number.size() - 2; i >= 0; i--) {
            if (number[i] > number[i + 1]) {
                number[i]--;
                index = i + 1;
            }
        }

        if (index != -1) {
            for (int i = index; i < number.size(); i++) {
                number[i] = '9';
            }
        }

        return atoi(number.c_str());
    }
};

int main()
{
    Solution sol;

    cout << sol.monotoneIncreasingDigits(1234) << endl;
    return 0;
}
