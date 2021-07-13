#include "permutation.h"


void swapChar(string &str, int i, int j)
{
    char tmp;
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

static void doPermutation(string &str, int index, int len)
{
    if (index == len) {
        //打印
        cout << str << endl;
        return;
    }

    for (int i = index; i < len; i++) {
        swapChar(str, i, index);
        doPermutation(str, index + 1, len);
        swapChar(str, i, index);
    }
}

/*
递归方法打印全排列

设 R = {r1, r2, ..., rn} 是要进行排列的n个元素，Ri = R - {ri}。集合 X 中元素的全排列记为Perm(X)。(ri)Perm(X) 表示在全排列 Perm(X) 的每一个排列前加上前缀 ri 得到的排列。R的全排列可归纳如下：

当 n = 1 时，Perm(R) = (r)，其中 r 是集合中唯一的元素；
当 n > 1 时，Perm(R) 由 (r1)Perm(R1), (r2)Perm(R2), (r3)Perm(R3), ..., (rn)Perm(Rn) 构成。

*/
void printPermutation(string str)
{
    doPermutation(str, 0, str.size());
}
