
/*

2017��12��13�գ�С������Ŭ����

�׳�

*/


#include <stdio.h>
#include <stdlib.h>


int Factorial(int n)
{
    if(n==0)return 1;
    else return n*Factorial(n-1);
}

int main(void)
{
    printf("%d\n",Factorial(5));
    return 0;
}
















