/*

The World's Richest

*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct {
    char name[10];
    int age;
    int worth;
} Person_t;

bool cmp(Person_t pa, Person_t pb);
int qcmp(const void *a, const void *b);
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    Person_t person[N];
    Person_t person_tmp[N];
    int tmp_index;

    //输入
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", person[i].name, &person[i].age, &person[i].worth);
    }

    //K个查询
    for (int i = 0; i < K; i++) {
        int M, Amin, Amax;
        scanf("%d %d %d", &M, &Amin, &Amax);

        tmp_index = 0;
        for (int j = 0; j < N; j++) {
            if (Amin <= person[j].age && person[j].age <= Amax) {
                person_tmp[tmp_index] = person[j];
                tmp_index++;
            }
        }

        //sort(person_tmp, person_tmp + tmp_index, cmp);
        qsort(person_tmp, tmp_index, sizeof(Person_t), qcmp);

        bool isPrint = false;
        int printCnt = 0;
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < tmp_index; j++) {
            if (printCnt < M) {
                printf("%s %d %d\n", person_tmp[j].name, person_tmp[j].age, person_tmp[j].worth);
                isPrint = true;
                printCnt++;
            } else {
                break;
            }
        }
        if (isPrint == false) {
            printf("None\n");
        }
    }

    return 0;
}

bool cmp(Person_t pa, Person_t pb)
{
    if (pa.worth == pb.worth) {

        if (pa.age == pb.age) {

            return strcmp(pa.name, pb.name) < 0;

        } else return pa.age < pb.age;

    } else return pa.worth > pb.worth;
}

int qcmp(const void *a, const void *b)
{
    Person_t *pa = (Person_t *)a;
    Person_t *pb = (Person_t *)b;

    if (pa->worth == pb->worth) {

        if (pa->age == pb->age) {

            return strcmp(pa->name, pb->name);

        } else return (pa->age < pb->age) ? -1 : 1;

    } else return (pa->worth > pb->worth) ? -1 : 1;
}
