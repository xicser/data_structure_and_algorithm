#include "bigInteger.h"
#include <stdio.h>
#include <string.h>

BigInteger::BigInteger()
{
    memset(digits, 0, sizeof(digits));
    len = 0;
    r = 0;
}

/* 比较两个大数的大小 */
int BigInteger::compare(BigInteger n1, BigInteger n2)
{
    if (n1.len > n2.len) {
        return 1;
    }
    else if (n1.len < n2.len) {
        return -1;
    }
    else {
        for (int i = n1.len - 1; i >= 0; i--) {
            if (n1.digits[i] > n2.digits[i]) return 1;
            else if (n1.digits[i] < n2.digits[i]) return -1;
        }
        return 0; //两数相等
    }
}

/* 显示 */
void BigInteger::display(void)
{
    for (int i = this->len - 1; i >= 0; i--) {
        printf("%d", this->digits[i]);
    }
    printf("\n");
}

/* 把char*的字符串转换成大数 */
void operator<< (BigInteger &n, char *strNum)
{
    n.len = strlen(strNum);
    for (int i = 0; i < n.len; i++) {
        n.digits[i] = strNum[n.len - i - 1] - '0';
    }
}

BigInteger operator+ (BigInteger n1, BigInteger n2)
{
    BigInteger ret;

    int carry = 0; //进位
    for (int i = 0; i < n1.len || i < n2.len; i++) {
        int temp = n1.digits[i] + n2.digits[i] + carry;
        ret.digits[ret.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) { //最后进位不为0
        ret.digits[ret.len++] = carry;
    }

    return ret;
}

BigInteger operator- (BigInteger n1, BigInteger n2)
{
    BigInteger ret;

    for (int i = 0; i < n1.len || i < n2.len; i++) {
        if (n1.digits[i] < n2.digits[i]) {
            n1.digits[i + 1]--;
            n1.digits[i] += 10;
        }
        ret.digits[ret.len++] = n1.digits[i] - n2.digits[i];
    }
    while (ret.len - 1 >= 1 && ret.digits[ret.len - 1] == 0) {
        ret.len--;  //去除高位的0, 同时至少保留一位最低位
    }

    return ret;
}

BigInteger operator* (BigInteger n1, int n2)
{
    BigInteger ret;
    int carry = 0;  //进位
    for (int i = 0; i < n1.len; i++) {
        int temp = n1.digits[i] * n2 + carry;
        ret.digits[ret.len++] = temp % 10;      //个位作为该位结果
        carry = temp / 10;                      //高位部分作为新的进位
    }
    while (carry != 0) {
        ret.digits[ret.len++] = carry % 10;
        carry /= 10;
    }

    return ret;
}

BigInteger operator/ (BigInteger n1, int n2)
{
    BigInteger ret;
    ret.r = 0;
    ret.len = n1.len;
    for (int i = n1.len - 1; i >= 0; i--) {
        ret.r = ret.r * 10 + n1.digits[i];
        if (ret.r < n2) {
            ret.digits[i] = 0;
        } else {
            ret.digits[i] = ret.r / n2;
            ret.r = ret.r % n2;
        }
    }

    while (ret.len - 1 >= 1 && ret.digits[ret.len - 1] == 0) {
        ret.len--;
    }

    return ret;
}

/* 获取余数 */
int BigInteger::getRemainder(void)
{
    return this->r;
}
