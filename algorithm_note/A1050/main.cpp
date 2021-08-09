/*

String Subtraction

*/

#include <iostream>
#include <stdio.h>

using namespace std;


char input_str[10005];
bool deletes[300] = {false};

void myGets(char *out);
int main()
{
    myGets(input_str);
    while (1) {
        char tmp = getchar();
        if (tmp == '\n') {
            break;
        } else {
            deletes[(int)tmp] = true;
        }
    }

    for (int i = 0; input_str[i]; i++) {
        if (deletes[ (int)input_str[i] ] == false) {
            printf("%c", input_str[i]);
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
