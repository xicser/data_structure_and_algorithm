/* 害死人不偿命的(3n+1)猜想 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int steps = 0;
    int n;

    scanf("%d", &n);

    while (n != 1) {
        steps++;

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
    }

    printf("%d", steps);

    return 0;
}
