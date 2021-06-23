/*
С����ƻ��
*/
#include <iostream>
#include <string>

using namespace std;

/* С����ƻ�������� */
int minBag(int appleCount)
{
    int bigCount = appleCount / 8;

    for (int i = bigCount; i >= 0; i--) {
        int copeCount = i * 8;
        int restCount = appleCount - copeCount;

        if (restCount % 6 != 0) {
            continue;
        }
        else {
            return i + restCount / 6;
        }
    }

    return -1;
}

/* �ҵ�����֮��ķ��� */
int minBagAwesome(int appleCount)
{
    if ((appleCount & 1) != 0) { // ���������, ����-1
        return -1;
    }
    if (appleCount < 18) {
        return appleCount == 0 ? 0 : (appleCount == 6 || appleCount == 8) ? 1
            : (appleCount == 12 || appleCount == 14 || appleCount == 16) ? 2 : -1;
    }
    return (appleCount - 18) / 8 + 3;
}

/* ţ�Բݱ����� */
string whoWin(int n)
{
    if (n < 5) {
        return (n == 0 || n == 2) ? "����" : "����";
    }
    int base = 1;
    while (base <= n) {
        if (whoWin(n - base) == "����") {
            return "����";
        }
        if (base > n / 4) { // ��ֹbase*4֮�����
            break;
        }
        base *= 4;
    }
    return "����";
}

/* ţ�Բ��ҵ����ɺ�ķ��� */
string whoWinAwesome(int n)
{
    int tmpRes = n % 5;
    if (tmpRes == 0 || tmpRes == 2) {
        return "����";
    }

    return "����";
}

/* �����������ĺ�, ������ */
bool isNumSum(int num)
{
    for (int i = 1; i < num; i++) {

        int sumTmp = 0;
        for (int j = i; j <= num; j++) {
            sumTmp += j;
            if (sumTmp == num) {
                return true;
            }
        }
    }

    return false;
}

/* �����������ĺ�, ��� */
bool isNumSumAwesome(int num)
{
    if (num == 1) {
        return false;
    }

    //num�ǲ���2��ĳ�η�
    // == 0 ��2��ĳ�η�
    // != 0 ����2��ĳ�η�
    return (num & (num - 1)) != 0;
}


int main()
{
//    //С����ƻ��
//    for (int apple = 1; apple < 500000; apple++) {
//        int res1 = minBag(apple);
//        int res2 = minBagAwesome(apple);
//        if (res1 != res2) {
//            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++");
//            break;
//        }
//        //printf("%d : %d    %d\n", apple, res1, res2);
//    }
//
//    printf("done\n");

//    //ţ�Բ�
//    for (int i = 0; i <= 50; i++) {
//        printf("%d : %s   %s\n", i, whoWin(i).data(), whoWinAwesome(i).data());
//    }

    //�����������ĺ�
    for (int i = 1; i <= 199; i++) {
        bool ret1 = isNumSum(i);
        bool ret2 = isNumSumAwesome(i);
        if (ret1 != ret2) {
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++");
            break;
        }
        printf("%d   ", i);
        if (ret1) {
            printf("true\n");
        }
        else {
            printf("false\n");
        }
    }

    return 0;
}
