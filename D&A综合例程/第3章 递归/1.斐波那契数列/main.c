
/*

2017��12��13�գ�С������Ŭ����

쳲���������


*/

#include <stdio.h>
#include <stdlib.h>


int fib(int a)
{
    if(a==0)return 0;
    else if(a==1)return 1;
    else return fib(a-1)+fib(a-2);
}

int main(void)
{
    int i;
    for(i=0;;i++)
    {
        printf("%d\n",fib(i));
    }


    return 0;
}




















