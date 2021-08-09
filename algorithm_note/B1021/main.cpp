/*

个位数统计

*/

#include <iostream>
#include <stdio.h>

using namespace std;


typedef struct {
    bool is_present;
    int cnt;
} Num_t;

Num_t num_cnt[10] = {0};
int main()
{
    while (1) {
        char char_tmp = getchar();
        if (char_tmp != '\n') {
            num_cnt[char_tmp - 48].cnt++;
            num_cnt[char_tmp - 48].is_present = true;
        } else break;
    }

    //输出
    for (int i = 0; i < 10; i++) {
        if (num_cnt[i].is_present == true) {
            printf("%d:%d\n", i, num_cnt[i].cnt);
        }
    }

    return 0;
}
