#include <iostream>
#include <stdio.h>
#include "water_filling.h"
#include "math.h"

using namespace std;

#define eps (1e-5)
#define R   (10)
const double PI = acos(-1);

double funcRh(double h) {
    double alpha = 2 * acos((R - h) / R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    double S1 = alpha * R * R / 2 - L * (R - h) / 2;
    double S2 = PI * R * R / 2;

    return S1 / S2;
}

double getH(double r)
{
    double mid;
    double left = 0, right = R;

    while (right - left > eps) {
        mid = (left + right) / 2;
        if (funcRh(mid) > r) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return (left + right) / 2;
}
