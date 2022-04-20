#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

#define N1 (1)
#define N2 (25)
#define N3 (25 * 25)
#define N4 (25 * 25 * 25)

#define C1 N1
#define C2 (N1 + N2)
#define C3 (N1 + N2 + N3)           //
#define C4 (N1 + N2 + N3 + N4)      //一个大块

using namespace std;

//baca
int main()
{
    string code;
    cin >> code;

    int index = 0;
    switch (code.size()) {
    case 4: {
        index += (code[0] - 'a') * C4;
        index += (code[1] - 'a') * C3 + 1;
        index += (code[2] - 'a') * C2 + 1;
        index += (code[3] - 'a') * C1 + 1;
        break;
    }
    case 3: {
        index += (code[0] - 'a') * C4;
        index += (code[1] - 'a') * C3 + 1;
        index += (code[2] - 'a') * C2 + 1;
        break;
    }
    case 2: {
        index += (code[0] - 'a') * C4;
        index += (code[1] - 'a') * C3 + 1;
        break;
    }
    case 1: {
        index += (code[0] - 'a') * C4;
        break;
    }

    default: break;
    }

    printf("%d\n", index);

    return 0;
}