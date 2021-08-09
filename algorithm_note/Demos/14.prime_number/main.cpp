#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;


//常规方法
bool isPrime(int n)
{
    if (n <= 1) return false;
    int sqr = sqrt(n);

    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

//Eratosthenes筛法
const int maxn = 101;           //表长
int prime[maxn], pNum = 0;      //prime数组存放所有素数, pNum为素数个数
bool p[maxn] = {0};             //如果i为素数, 则p[i]为false; 否则, p[i]为true

void findPrime(void)
{
    for (int i = 2; i < maxn; i++) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main()
{
    printf("%d\n", isPrime(8));
    printf("%d\n", isPrime(1));

    findPrime();

    for (int i = 0; i < pNum; i++) {
        printf("%d ", prime[i]);
    }



    return 0;
}
