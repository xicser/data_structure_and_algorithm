/*

Password

*/

#include <iostream>
#include <stdio.h>

using namespace std;


typedef struct {
    char name[100];
    char passwd[100];
} People_t;

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    People_t people[N];
    People_t people_modify[N];

    int modify_cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s%s", people[i].name, people[i].passwd);
        getchar();
    }

/*
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
*/

    for (int i = 0; i < N; i++) {

        //遍历密码
        bool is_modified = false;
        for (int j = 0; people[i].passwd[j] != 0; j++) {
            if (people[i].passwd[j] == '1') {
                people[i].passwd[j] = '@';
                is_modified = true;
            } else if (people[i].passwd[j] == '0') {
                people[i].passwd[j] = '%';
                is_modified = true;
            } else if (people[i].passwd[j] == 'l') {
                people[i].passwd[j] = 'L';
                is_modified = true;
            } else if (people[i].passwd[j] == 'O') {
                people[i].passwd[j] = 'o';
                is_modified = true;
            }
        }

        if (is_modified == true) {
            people_modify[modify_cnt++] = people[i];
        }
    }


    //没有修改过
    if (modify_cnt == 0) {
        if (N == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", N);
        }

        return 0;
    }

    printf("%d\n", modify_cnt);
    for (int i = 0; i < modify_cnt; i++) {
        printf("%s %s\n", people_modify[i].name, people_modify[i].passwd);
    }


    return 0;
}
