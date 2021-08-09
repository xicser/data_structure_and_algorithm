/*

字符统计

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

char toLowerCase(char c)
{
    return c + 32;
}

int input[255];
int main()
{
    char char_tmp;

    while (1) {

        scanf("%c", &char_tmp);
        if (char_tmp != '\n') {

            //大写字母统一转小写
            if ('A' <= char_tmp && char_tmp <= 'Z') {
                input[(int)toLowerCase(char_tmp)]++;
            } else if ('A' <= char_tmp && char_tmp <= 'z') {
                input[(int)char_tmp]++;
            }

        } else break;
    }

    int max_cnt_char = -1;
    int max_cnt_char_index;
    for (int i = 'a'; i <= 'z'; i++) {

        if (input[i] > max_cnt_char) {
            max_cnt_char = input[i];
            max_cnt_char_index = i;
        }
    }

    printf("%c %d\n", max_cnt_char_index, input[max_cnt_char_index]);
    return 0;
}
