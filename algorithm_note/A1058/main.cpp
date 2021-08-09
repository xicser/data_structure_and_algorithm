/*

A+B in Hogwarts

*/

#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/*
P          A
10.16.27   14.1.28

Galleon.Sickle.Knut

十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。
*/
int main()
{
    long long P_Galleon, P_Sickle, P_Knut;
    long long A_Galleon, A_Sickle, A_Knut;
    scanf("%ld.%ld.%ld %ld.%ld.%ld", &P_Galleon, &P_Sickle, &P_Knut, &A_Galleon, &A_Sickle, &A_Knut);

    long long sum_P = 29 * P_Sickle + P_Knut + 29 * 17 * P_Galleon;
    long long sum_A = 29 * A_Sickle + A_Knut + 29 * 17 * A_Galleon;
    long long res;

    res = sum_P + sum_A;

    printf("%d.", res / (29 * 17));
    res = res % (29 * 17);
    printf("%d.", res / 29);
    res = res % 29;
    printf("%d", res);

    return 0;
}
