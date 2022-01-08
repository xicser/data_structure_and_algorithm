#include <iostream>
#include <stdio.h>

using namespace std;


/*

异或运算满足交换律和结合律
0 ^ N == N;
N ^ N == 0

*/

//使用异或交换
void swapXor(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//一个数组中有一种数出现了奇数次，其他数出现了偶数次，怎么找到并打印这个数？
void printOddTimesNum1(int *arr, int len)
{
    int eor = 0;
    for (int i = 0; i < len; i++) {
        eor ^= arr[i];
    }
    printf("%d\n", eor);
}

//提取出一个整形数最右侧的1
// N & ((~N) + 1)
//一个数组中, 有两种数出现了奇数次, 其他数都出现了偶数次, 怎么找到并打印这两种数

int main()
{
    int a = 12, b = 13;
    swapXor(a, b);

    cout << a << " " << b;

    return 0;
}
