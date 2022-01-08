#include <iostream>
#include "hanoi.h"

/* 把n个盘子, 借助middle, 从left挪到right */
void hanoi(int n, string &left, string &middle, string &right)
{
    if (n == 1) {
        cout << '(' << 1 << ')' << left << "-->" << right << endl;
        return;
    }

    //把第 1 ~ n-1 借助right挪到middle
    hanoi(n - 1, left, right, middle);

    //把第 n 从left直接挪到right
    cout << '(' << n << ')' << left << "-->" << right << endl;

    //把第 1 ~ n-1 借助left挪到right
    hanoi(n - 1, middle, left, right);
}
