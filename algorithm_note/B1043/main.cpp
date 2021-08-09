/*

输出PATest

*/

#include <iostream>
#include <stdio.h>

using namespace std;

void myGets(char *out);

char str[10005];

//PATest
int Count[255] = {0};
int main()
{
    myGets(str);

    for (int i = 0; str[i]; i++) {
        switch(str[i]) {
            case 'P': Count['P']++; break;
            case 'A': Count['A']++; break;
            case 'T': Count['T']++; break;
            case 'e': Count['e']++; break;
            case 's': Count['s']++; break;
            case 't': Count['t']++; break;
            default: break;
        }
    }

    while (Count['P'] || Count['A'] || Count['T'] || Count['e'] || Count['s'] || Count['t']) {
        if (Count['P']) {
            printf("P");
            Count['P']--;
        }
        if (Count['A']) {
            printf("A");
            Count['A']--;
        }
        if (Count['T']) {
            printf("T");
            Count['T']--;
        }
        if (Count['e']) {
            printf("e");
            Count['e']--;
        }
        if (Count['s']) {
            printf("s");
            Count['s']--;
        }
        if (Count['t']) {
            printf("t");
            Count['t']--;
        }
    }

    return 0;
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
