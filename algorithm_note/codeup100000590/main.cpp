#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

//分数
class Fraction {
public:
    Fraction() {}
    Fraction(long long _up, long long _down) {
        up = _up;
        down = _down;
    }
    long long up, down;
} ;

//最大公约数
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

//分数化简
Fraction reduce(Fraction f)
{
    if (f.down < 0) {
        f.up = -f.up;
        f.down = -f.down;
    }

    if (f.up == 0) {
        f.down = 1;
    } else {
        int d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }

    return f;
}

//分数相加
Fraction addFrac(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down + f1.down * f2.up;
    result.down = f1.down * f2.down;
    return reduce(result);
}


double calculate(int n)
{
    Fraction sumFrac;

    if (n == 0) {
        return 0;
    }

    //共n行
    for (int i = 1; i <= n; i++) {

        //先计算左边的
        Fraction frac(1, i);
        for (int j = 1; j < i; j++) {
            frac = addFrac(frac, Fraction(1, j));
        }

        //再计算右边的
        for (int j = 2; j <= n - i + 1; j++) {
            frac = addFrac(frac, Fraction(1, j));
        }

        if (i == 1) {
            sumFrac = frac;
        } else {
            sumFrac = addFrac(sumFrac, frac);
        }
    }

    return (double)sumFrac.up / (double)sumFrac.down;
}

/*
1
2
3
4
0

1.00
3.00
5.67
8.83
*/
int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) break;
        printf("%.2lf\n", calculate(n));
    }

    return 0;
}
