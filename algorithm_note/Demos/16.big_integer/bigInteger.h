#ifndef __BIG_INTEGER_H__
#define __BIG_INTEGER_H__

//大整数
class BigInteger {
public:
    BigInteger();
    int  compare(BigInteger n1, BigInteger n2);     //比较两个大数的大小
    void display(void);                             //显示
    int  getRemainder(void);                        //获取余数

private:
    int digits[1000];
    int len;
    int r;          //相除时的余数

    friend void operator<< (BigInteger &n, char *strNum);   //把char*的字符串转换成大数
    friend BigInteger operator+ (BigInteger n1, BigInteger n2);
    friend BigInteger operator- (BigInteger n1, BigInteger n2);
    friend BigInteger operator* (BigInteger n1, int n2);
    friend BigInteger operator/ (BigInteger n1, int n2);
};

#endif // __BIG_INTEGER_H__
