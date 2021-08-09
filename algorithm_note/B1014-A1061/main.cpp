/*

福尔摩斯的约会(Dating)

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

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

int min (int a, int b)
{
    return a < b ? a : b;
}

void printWeek(int i)
{
    switch (i) {
        case 1: printf("MON "); break;
        case 2: printf("TUE "); break;
        case 3: printf("WED "); break;
        case 4: printf("THU "); break;
        case 5: printf("FRI "); break;
        case 6: printf("SAT "); break;
        case 7: printf("SUN "); break;
        default: break;
    }
}
int main()
{
    int len1, len2, len3, len4;
    char str1[100], str2[100], str3[100], str4[100];
    myGets(str1);
    myGets(str2);
    myGets(str3);
    myGets(str4);

    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(str3);
    len4 = strlen(str4);

    int flag = 0;
    for (int i = 0 ; i < min(len1, len2); i++) {
        if (flag == 0 && str1[i] == str2[i] && 'A' <= str1[i] && str1[i] <= 'G') {
            printWeek(str1[i] - 64);
            flag = 1;
            continue;
        }
        if (flag == 1 && str1[i] == str2[i]) {
            if ('A' <= str1[i] && str1[i] <= 'N') {
                printf("%02d:", str1[i] - 55);
                break;
            } else if ('0' <= str1[i] && str1[i] <= '9') {
                printf("%02d:", str1[i] - 48);
                break;
            }
        }
    }

    for (int i = 0 ; i < min(len3, len4); i++) {
        if (str3[i] == str4[i] &&
            (('a' <= str3[i] && str3[i] <= 'z') || ('A' <= str3[i] && str3[i] <= 'Z')) )
        {
            printf("%02d\n", i);
            break;
        }
    }

    return 0;
}
