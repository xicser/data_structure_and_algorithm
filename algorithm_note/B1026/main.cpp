/* 程序运行时间 */

#include <iostream>
#include <stdio.h>

using namespace std;


#define CLK_TICK (100)

int main()
{
    int seconds;
    double seconds_f;
    double C1, C2;

    scanf("%lf%lf", &C1, &C2);
    seconds_f = (C2 - C1) / CLK_TICK;
    seconds = (int)(seconds_f + 0.5);

    int hours;
    int minutes;

    hours = seconds / 3600;
    seconds %= 3600;

    minutes = seconds / 60;
    seconds %= 60;


    printf("%02d:%02d:%02d", hours, minutes, seconds);

    return 0;
}
