#include <iostream>
#include <stdio.h>

using namespace std;

//最大公约数
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

//最小公倍数
int lcm(int a, int b)
{
    int d = gcd(a, b);
//    return a * b / d; //容易溢出
    return a / d * b;
}

int main()
{
    printf("%d\n", gcd(3, 9));
    printf("%d\n", lcm(3, 9));

    return 0;
}
