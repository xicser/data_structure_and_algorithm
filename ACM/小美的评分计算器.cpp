#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= 5; i++) {
        int val;
        cin >> val;
        cnt += val;
        sum += i * val;
    }

    double result = (double)sum / (double)cnt;
    result *= 10;
    int result_i = (int)result;

    printf("%.1f\n", result_i / 10.0);

    return 0;
}
