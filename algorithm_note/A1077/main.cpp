/*

Kuchiguse

*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void reverse(char *array, int len)
{
    int tmp;
    for (int i = 0; i < len / 2; i++) {
        tmp = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = tmp;
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

/*
2
1234441242
23234 234 234
*/
char out[280];
int out_index = 0;
int main()
{
    int min_len = 500;
    int N;
    scanf("%d", &N);
    getchar();
    char input_strs[N][280];
    for (int i = 0; i < N; i++) {
        myGets(input_strs[i]);
        int len_tmp = strlen(input_strs[i]);
        reverse(input_strs[i], len_tmp);
        if (min_len > len_tmp) {
            min_len = len_tmp;
        }
    }

    //开始找
    for (int i = 0; i < min_len; i++) {

        //检查所有字符串 当前位置是否相同
        int j;
        for (j = 0; j < N - 1; j++) {
            if (input_strs[j][i] != input_strs[j + 1][i]) {
                break;
            }
        }

        if (j == N - 1) { //都相同
            out[out_index++] = input_strs[j][i];
        } else break;
    }

    if (out_index == 0) {
        printf("nai\n");
        return 0;
    }

    reverse(out, out_index);
    out[out_index] = 0;
    printf("%s\n", out);

/*
~nayn iatI
~naynadayi aw nijniN
~nayn hhhu
*/

    return 0;
}
