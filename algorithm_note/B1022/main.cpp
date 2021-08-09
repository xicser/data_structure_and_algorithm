/*

D½øÖÆµÄA+B

*/

#include <iostream>

using namespace std;

int main()
{
    int A, B, D;

    cin >> A >> B >> D;

    A += B;

    int z[100], num = 0;
    do {
        z[num++] = A % D;
        A /= D;

    } while (A);

    for (int i = num - 1; i >= 0; i--) {
        printf("%d", z[i]);
    }

    return 0;
}
