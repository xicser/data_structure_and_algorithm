#include <iostream>
#include <vector>

using namespace std;

//int 十进制：-2^31=-21 4748 3648 到 2^31-1=21 4748 3647。共10位，21亿
class Solution {
public:
    int reverse(int x) {

        int num = abs(x);
        int res = 0;
        int k = 1;

        vector<int> numbers;
        for (int i = 0; i < 10; i++) {
            numbers.push_back(num % 10);
            num /= 10;
        }

        for (int i = numbers.size() - 1; i >= 0; i--) {
            if (numbers[i] == 0) {
                continue;
            }
            else {
                for (int j = i; j >= 0; j--) {
                    res += numbers[j] * k;
                    k *= 10;
                }
                break;
            }
        }

        if (x < 0) {
            res *= -1;
        }

        if (res < -2147483648 || res > 2147483647) {
            return 0;
        }

        return res;
    }
};

int main()
{
    Solution sol;

    cout << sol.reverse(-123) << endl;
//    cout << sol.reverse(123) << endl;
//    cout << sol.reverse(120) << endl;
//    cout << sol.reverse(0) << endl;

    return 0;
}
