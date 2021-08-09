/*

说反话

*/

#include <iostream>
#include <stdio.h>

using namespace std;

char str[100][100];
int index = 0;

int main()
{
    //统计有几个单词
    while (scanf("%s", str[index]) != EOF) {
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%s", str[i]);
        if (i == 0) printf("\n");
        else printf(" ");
    }

    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Hello World Here I Come
//Come I Here World Hello


int countSpace(char *str)
{
    int count = 0;
    int i;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == ' ') count++;
    }
    return count;
}

int main()
{
    int spaceCount, spaceCurrent = 0;
    int word_start, word_end, word_len = 0;

    int i, j;
    int len;
    char str[100] = {' '};
    gets(str + 1);
    len  = strlen(str);

    spaceCount = countSpace(str) - 1;

    word_start = word_end = len - 1;
    for (i = len - 1; i >= 0; i--) {

        if (str[i] != ' ') {
            word_start--;
            word_len++;
        } else {
            spaceCurrent++;
            for (j = word_start + 1; j <= word_start + word_len; j++) {
                printf("%c", str[j]);
            }
            if (spaceCurrent != spaceCount + 1) printf(" ");

            word_start = word_end = i - 1;
            word_len = 0;
        }
    }

    return 0;
}


*/
