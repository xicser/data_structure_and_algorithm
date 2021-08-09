/*

成绩排名

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
*/

typedef struct {
    char name[11];
    char id[11];
    int grade;
} Student_t;


int main()
{
    int grade_max, grade_min;
    int max_index = 0, min_index = 0;
    int i;
    int N;
    Student_t *students;

    scanf("%d", &N);
    students = (Student_t *)malloc(sizeof(Student_t) * N);

    for (i = 0; i < N; i++) {
        scanf("%s %s %d", students[i].name, students[i].id, &students[i].grade);
    }

    grade_max = grade_min = students[0].grade;
    for (i = 0; i < N; i++) {
        if (students[i].grade > grade_max) { //找最大的
            grade_max = students[i].grade;
            max_index = i;
        }
        if (students[i].grade < grade_min) { //找最小的
            grade_min = students[i].grade;
            min_index = i;
        }
    }

    printf("%s %s\n", students[max_index].name, students[max_index].id);
    printf("%s %s\n", students[min_index].name, students[min_index].id);

    return 0;
}
