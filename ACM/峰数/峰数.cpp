#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int solve(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isFengShu(i) == true) {
                count++;
            }
        }

        return count;
    }

private:
    int getBits(int n, vector<int>& array)
    {
        int bits = 0;

        while (n) {

            int ge = n % 10;
            array.push_back(ge);

            bits++;
            n /= 10;
        }

        reverse(array.begin(), array.end());

        return bits;
    }

    bool isFengShu(int n) {
        vector<int> array;
        int len = getBits(n, array);

        if (len % 2 == 0) {
            return false;
        }

        int mid = (len + 1) / 2;

        for (int i = 1; i < mid; i++) {
            if (array[i - 1] >= array[i + 1 - 1]) {
                return false;
            }
        }

        for (int i = mid; i < len; i++) {
            if (array[i - 1] <= array[i + 1 - 1]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{

}
