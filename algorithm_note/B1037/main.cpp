/*

�ڻ����ִ�����Ǯ

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/*
P          A
10.16.27   14.1.28

Galleon.Sickle.Knut

ʮ�߸�������(Sickle)��һ����¡(Galleon)����ʮ�Ÿ�����(Knut)��һ�����ɣ������ס�
*/
int main()
{
    int P_Galleon, P_Sickle, P_Knut;
    int A_Galleon, A_Sickle, A_Knut;
    scanf("%d.%d.%d %d.%d.%d", &P_Galleon, &P_Sickle, &P_Knut, &A_Galleon, &A_Sickle, &A_Knut);

    int sum_P = 29 * P_Sickle + P_Knut + 29 * 17 * P_Galleon;
    int sum_A = 29 * A_Sickle + A_Knut + 29 * 17 * A_Galleon;
    int res;

    if (sum_P > sum_A) {
        printf("-");
    }
    res = abs(sum_P - sum_A);

    printf("%d.", res / (29 * 17));
    res = res % (29 * 17);
    printf("%d.", res / 29);
    res = res % 29;
    printf("%d", res);

    return 0;
}
