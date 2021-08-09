#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

bool origin[150] = {0};
bool actually[150] = {0};
bool is_printed_flag[150] = {0};

/*
7_This_is_a_test
_hs_s_a_es
*/
int main()
{
    char str1[85];
    char str2[85];

    myGets(str1);
    toHigherCase(str1);
    for (int i = 0; str1[i]; i++) {
        origin[(int)str1[i]] = true;
    }

    myGets(str2);
    toHigherCase(str2);
    for (int i = 0; str2[i]; i++) {
        actually[(int)str2[i]] = true;
    }

/*
7_This_is_a_test
_hs_s_a_es
*/

    for (int i = 0; str1[i] != 0; i++) {
        if (origin[(int)str1[i]] == true && actually[(int)str1[i]] == false
            && is_printed_flag[(int)str1[i]] == false) {

            printf("%c", str1[i]);
            is_printed_flag[(int)str1[i]] = true;
        }
    }

    printf("\n");
    return 0;
}
