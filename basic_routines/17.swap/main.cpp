#include <iostream>
#include <stdio.h>

using namespace std;


/*

����������㽻���ɺͽ����
0 ^ N == N;
N ^ N == 0

*/

//ʹ����򽻻�
void swapXor(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//һ����������һ���������������Σ�������������ż���Σ���ô�ҵ�����ӡ�������
void printOddTimesNum1(int *arr, int len)
{
    int eor = 0;
    for (int i = 0; i < len; i++) {
        eor ^= arr[i];
    }
    printf("%d\n", eor);
}

//��ȡ��һ�����������Ҳ��1
// N & ((~N) + 1)
//һ��������, ��������������������, ��������������ż����, ��ô�ҵ�����ӡ��������

int main()
{
    int a = 12, b = 13;
    swapXor(a, b);

    cout << a << " " << b;

    return 0;
}
