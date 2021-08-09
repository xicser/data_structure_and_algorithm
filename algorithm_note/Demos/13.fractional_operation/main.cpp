#include <iostream>

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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
