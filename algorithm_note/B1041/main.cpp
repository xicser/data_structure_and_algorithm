/*

考试座位号

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


typedef struct {
    char number[20];
    int exam_number;
} Student_t;

int main()
{
    int N, M;
    scanf("%d", &N);
    Student_t students[N + 5];

    for (int i = 0; i < N; i++) {
        char tmp_number[20];
        int  tmp_test_number;
        int  tmp_exam_number;
        scanf("%s %d %d", tmp_number, &tmp_test_number, &tmp_exam_number);
        strcpy(students[tmp_test_number].number, tmp_number);
        students[tmp_test_number].exam_number = tmp_exam_number;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int  tmp_test_number;
        scanf("%d", &tmp_test_number);
        printf("%s %d\n", students[tmp_test_number].number, students[tmp_test_number].exam_number);
    }

    return 0;
}
