/*

旧键盘打字

*/

#include <iostream>
#include <stdio.h>

using namespace std;

char str1[100005];
char str2[100005];
char str_tmp[100005];

bool broken[256] = {0};


void toHigherCase(char *str);
void myGets(char *out);
int main()
{
    bool is_printed = false;
    myGets(str1);
    toHigherCase(str1);
    for (int i = 0; str1[i]; i++) {
        broken[(int)str1[i]] = true;
    }

    myGets(str2);
    for (int i = 0; str2[i]; i++) {

        if ('a' <= str2[i] && str2[i] <= 'z') {
            char tmp_upper = str2[i] - 32;
            if (broken[(int)tmp_upper] == false) {
                printf("%c", str2[i]);
                is_printed = true;
            }
        } else if ('A' <= str2[i] && str2[i] <= 'Z') {

            if (broken[(int)'+'] == false && broken[str2[i]] == false) {
                printf("%c", str2[i]);
                is_printed = true;
            }

        } else if (broken[(int)str2[i]] == false) { //没坏
            printf("%c", str2[i]);
            is_printed = true;
        }
    }

    if (is_printed == false) {
        printf("\n");
    }

    return 0;
}

void toHigherCase(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void myGets(char *out)
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
}
