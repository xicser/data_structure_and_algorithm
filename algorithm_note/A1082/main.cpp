/*

Read Number in Chinese

*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//数字
string num[]  = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

//单位
string unit[] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int myGets(char *out);

int main()
{
    char num_str[12];   //存放数字字符串
    int dig_cnt;        //记录数字位数

    int len = myGets(num_str);

    //先处理'-'
    if (num_str[0] == '-') {
        printf("Fu");
        for (int i = 0; i < len - 1; i++) {
            num_str[i] = num_str[i + 1];
        }
        num_str[len - 1] = 0;
        len -= 1;
    }
    dig_cnt = len;

    printf("\ndig_cnt = %d\n", dig_cnt);
/*
1   2   3   4   5         6   7   8  9
亿  千  百  十     (万)   千  百  十
*/

/* 下面按数的位数分类讨论 */

    if (dig_cnt <= 4) {




    } else if (4 < dig_cnt && dig_cnt <= 8) {

    } else {

    }

//    for (int  i = 1; i <= 9; i++) {
//        printf("%d", digits[i]);
//    }

    return 0;
}

int myGets(char *out)
{
    int i = 0;
    while (1) {
        char tmp = getchar();
        if (tmp == '\n') {
            break;
        } else {
            out[i++] = tmp;
        }
    }
    out[i] = 0;

    return i;
}
