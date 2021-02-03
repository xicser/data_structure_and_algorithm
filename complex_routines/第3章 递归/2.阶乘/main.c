
/*

2017年12月13日，小王持续努力！

阶乘

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
















