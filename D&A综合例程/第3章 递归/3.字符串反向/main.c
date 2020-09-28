
/*

2017年12月13日，小王持续努力！

字符串反向：
编写一个递归函数，实现将输入的任意长的字符串反向输出，
例如输入abc，输出cba，输入的字符串以#表示结束

*/

#include <stdio.h>
#include <stdlib.h>


void print()
{
    char a;

    scanf("%c", &a);
    if(a!='#')print();
    if(a!='#')printf("%c",a);
}

int main()
{

    print();
    return 0;
}








