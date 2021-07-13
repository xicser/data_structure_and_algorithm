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
        //��ӡ
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
�ݹ鷽����ӡȫ����

�� R = {r1, r2, ..., rn} ��Ҫ�������е�n��Ԫ�أ�Ri = R - {ri}������ X ��Ԫ�ص�ȫ���м�ΪPerm(X)��(ri)Perm(X) ��ʾ��ȫ���� Perm(X) ��ÿһ������ǰ����ǰ׺ ri �õ������С�R��ȫ���пɹ������£�

�� n = 1 ʱ��Perm(R) = (r)������ r �Ǽ�����Ψһ��Ԫ�أ�
�� n > 1 ʱ��Perm(R) �� (r1)Perm(R1), (r2)Perm(R2), (r3)Perm(R3), ..., (rn)Perm(Rn) ���ɡ�

*/
void printPermutation(string str)
{
    doPermutation(str, 0, str.size());
}
