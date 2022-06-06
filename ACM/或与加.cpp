#include <iostream>

using namespace std;


/*
x对应位为1的数, y对应的位为0
*/
long long test1(long long x, long long k)
{
    long long y = 0;

    long long n = 0;
    long long val = k;

    for (int i = 0; i < 32; i++) {
        //如果这一位为0
        if ((x & (1LL << i)) == 0) {
            if (val & (1LL << n)) {
                y |= 1LL << i;
            }

            n++;
        }
    }

    return y;
}

long long test2(long long x, long long k)
{
    int which = 0;
    for (int y = 1; ; y++) {
        if ((x + y) == (x | y)) {
            which++;
            if (which == k) {
                return y;
            }
        }
    }

    return 0;
}


int main()
{
    long long x, k;
    srand((unsigned)time(NULL));
    while (1) {
        x = rand() * 9999;
        k = rand() * 9999;
        printf("x = %d, k = %d", x, k);
        long long val1 = test1(x, k);
        long long val2 = test2(x, k);
        if (val1 != val2) {
            printf("x = %d, k = %d, val1 = %d, val2 = %d\n", x, k, val1, val2);
            break;
        }

    }

    return 0;
}
