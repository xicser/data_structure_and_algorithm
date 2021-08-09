#include <iostream>
#include "bigInteger.h"
#include <string.h>
#include <stdio.h>

using namespace std;

char input1[1000];
char input2[1000];
int main()
{
    gets(input1);
    gets(input2);
    int n2;
    scanf("%d", &n2);
    BigInteger i1, i2, iRes;
    i1 << input1;
    i2 << input2;

    //+
    iRes = i1 + i2;
    iRes.display();

    //-
    iRes = i1 - i2;
    iRes.display();

    //*
    iRes = i1 * n2;
    iRes.display();

    // /
    iRes = i1 / n2;
    iRes.display();
    printf("%d\n", iRes.getRemainder());

    return 0;
}
