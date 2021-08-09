/*
求最小公倍数
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int array[100000];
int index;

int lcm(int a, int b);


/*
2
2 3 5
3 4 6 12
*/
int main()
{
    int T, N;

    while (scanf("%d", &T) != EOF) {
        while (T > 0) {
            T--;

            int n;
            scanf("%d", &n);

            index = 0;
            for (int j = 0; j < n; j++) {
                scanf("%d", &array[index]);
                index++;
            }

            if (index == 1) {
                printf("%d\n", array[0]);
                continue;
            }

            int value = array[0];
            for (int k = 1; k < index; k++) {
                value = lcm(value, array[k]);
            }
            printf("%d\n", value);
        }
    }

    return 0;
}

//最大公约数
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

//最小公倍数
int lcm(int a, int b)
{
    int d = gcd(a, b);
//    return a * b / d; //容易溢出
    return a / d * b;
}
