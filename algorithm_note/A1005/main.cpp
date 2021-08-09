/*

Spell It Right

*/

#include <iostream>
#include <stdio.h>

using namespace std;

string bits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

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
int main()
{
    int sum = 0;
    char num[1000];
    myGets(num);

    for (int i = 0; num[i] != 0; i++) {
        sum += num[i] - 48;
    }

    int ge = sum % 10;
    int shi = sum / 10 % 10;
    int bai = sum / 100 % 10;

    if (bai) {
        cout << bits[bai] << " ";
        cout << bits[shi] << " ";
        cout << bits[ge];

    } else if (bai == 0 && shi) {
        cout << bits[shi] << " ";
        cout << bits[ge];
    } else if (bai == 0 && shi == 0 && ge) {
        cout << bits[ge];
    } else {
        cout << bits[0];
    }

    return 0;
}
