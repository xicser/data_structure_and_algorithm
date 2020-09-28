
/*

2017年12月13日，小王持续努力！

汉诺塔问题：

有一个梵塔，塔内有三个座A、B、C，A座上有诺干个盘子，
盘子大小不等，大的在下，小的在上（如图）。
把这些个盘子从A座移到C座，中间可以借用B座但每次只能允许移动一个盘子，
并且在移动过程中，3个座上的盘子始终保持大盘在下，小盘在上。

描述简化：把A柱上的n个盘子移动到C柱，其中可以借用B柱。

*/

#include <stdio.h>
#include <stdlib.h>


int cnt=0;

//将 n 个盘子从 x 借助 y 移动到 z
void move(int n,char x,char y,char z)
{
    if(n==1)
    {
        cnt++;
        printf("%c-->%c\n", x, z);
    }
    else
    {
        move(n-1,x,z,y);//将n-1个盘子从x借助z移到y上
        cnt++;
        printf("%c-->%c\n", x, z);//将第n个盘子从x移到z上
        move(n-1,y,x,z);//将n-1个盘子从y借助x移到z上
    }
}
int main()
{
    int n;

    printf("请输入汉诺塔层数：\n");
    scanf("%d", &n);
    printf("移动步骤如下：\n");
    move(n,'X','Y','Z');
    printf("共需%d步\n",cnt);

    return 0;
}
