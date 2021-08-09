/*

List Sorting

*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

//学生
typedef struct {
    char id[10];
    char name[10];
    int score;
} Student_t;


Student_t students[100005];
int stu_index = 0;

bool cmp1(Student_t sa, Student_t sb)
{
    return strcmp(sa.id, sb.id) < 0;
}
bool cmp2(Student_t sa, Student_t sb)
{
    int res = strcmp(sa.name, sb.name);
    if (res == 0) {
        return strcmp(sa.id, sb.id);
    } return res < 0;
}
bool cmp3(Student_t sa, Student_t sb)
{
    if (sa.score == sb.score) {
        return strcmp(sa.id, sb.id) < 0;
    } else return sa.score < sb.score;
}
int main()
{
    int N;
    int C;
    bool (*cmp)(Student_t, Student_t);    //cmp函数

    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++) {
        scanf("%s %s %d", students[stu_index].id, students[stu_index].name, &students[stu_index].score);
        stu_index++;
    }

    switch (C) {
        case 1: cmp = cmp1; break;
        case 2: cmp = cmp2; break;
        case 3: cmp = cmp3; break;
        default: break;
    }

    sort(students, students + stu_index, cmp);
    for (int i = 0; i < N; i++) {
        printf("%s %s %d\n", students[i].id, students[i].name, students[i].score);
    }

    return 0;
}
