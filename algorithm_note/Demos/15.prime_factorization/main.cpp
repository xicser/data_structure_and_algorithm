/*
质因子分解
*/

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
const int maxn = 100001;        //表长
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

typedef struct {
    int x, cnt;
} factor;

factor fac[10] = {0};

int main()
{
    findPrime();
    int n;
    int num = 0;

    scanf("%d", &n);

    if (n == 1) {
        printf("1=1\n");
        return 0;
    }
    if (isPrime(n) == true) {
        printf("%d=%d", n, n);
        return 0;
    }

    printf("%d=", n);

    int sqr = sqrt(n);

    for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
        if (n % prime[i] == 0) {
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while (n % prime[i] == 0) {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }

        //n已经被除尽了, 退出
        if (n == 1) break;
    }

    //如果n无法被根号n以内的质因子除尽, 说明n有且仅有一个大于根号n的质因子
    if (n != 1) {
        fac[num].x = n;
        fac[num].cnt = 1;
        num++;
    }

    //输出
    for (int i = 0; i < num; i++) {
        if (i > 0) {
            printf("*");
        }
        printf("%d", fac[i].x);
        if (fac[i].cnt > 1) {
            printf("^%d", fac[i].cnt);
        }
    }

    return 0;
}
