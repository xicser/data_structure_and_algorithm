/*

求f(x) = 0, 在区间[a, b]上的近似根, 其中f(x)单调

例:
假设f(x) = x * x - 2;
[a, b] = [0, 2]

*/

#include <iostream>
#include "func_root.h"
#include <stdio.h>

using namespace std;


double func(double x)
{
    return x * x - 2;
}

#define eps (1e-5)

double getRoot(double a, double b)
{
    double mid;
    while (b - a > eps) {
        mid = (a + b) / 2;
        if (func(mid) < 0) {
            a = mid;
        } else {
            b = mid;
        }
    }

    return (a + b) / 2;
    //return mid;
}
