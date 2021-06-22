/*
小虎买苹果
*/
#include <iostream>
#include <string>

using namespace std;

/* 小虎买苹果暴力法 */
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

/* 找到规律之后的方法 */
int minBagAwesome(int appleCount)
{
    if ((appleCount & 1) != 0) { // 如果是奇数, 返回-1
        return -1;
    }
    if (appleCount < 18) {
        return appleCount == 0 ? 0 : (appleCount == 6 || appleCount == 8) ? 1
            : (appleCount == 12 || appleCount == 14 || appleCount == 16) ? 2 : -1;
    }
    return (appleCount - 18) / 8 + 3;
}

/* 牛吃草暴力法 */
string whoWin(int n)
{
    if (n < 5) {
        return (n == 0 || n == 2) ? "后手" : "先手";
    }
    int base = 1;
    while (base <= n) {
        if (whoWin(n - base) == "后手") {
            return "先手";
        }
        if (base > n / 4) { // 防止base*4之后溢出
            break;
        }
        base *= 4;
    }
    return "后手";
}

/* 牛吃草找到规律后的方法 */
string whoWinAwesome(int n)
{
    int tmpRes = n % 5;
    if (tmpRes == 0 || tmpRes == 2) {
        return "后手";
    }

    return "先手";
}

int main()
{
    //小虎买苹果
    for (int apple = 1; apple < 500000; apple++) {
        int res1 = minBag(apple);
        int res2 = minBagAwesome(apple);
        if (res1 != res2) {
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++");
            break;
        }
        //printf("%d : %d    %d\n", apple, res1, res2);
    }

    printf("done\n");

//    //牛吃草
//    for (int i = 0; i <= 50; i++) {
//        printf("%d : %s   %s\n", i, whoWin(i).data(), whoWinAwesome(i).data());
//    }

    return 0;
}



