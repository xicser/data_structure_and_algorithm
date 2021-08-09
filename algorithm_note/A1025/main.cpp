/*

PAT Ranking

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct {
    char id[20];
    int score;
    int lacation;
    int local_rank;
    int final_rank;
} Student_t;


bool cmp(Student_t sa, Student_t sb)
{
    if (sa.score == sb.score) {

        return strcmp(sa.id, sb.id) < 0;

    } else return sa.score > sb.score;
}


Student_t students[30005];
int start_index = 0;
int stu_index = 0;
int main()
{
    int N;
    int cnt_all = 0;
    scanf("%d", &N);
/*
1234567890005 100       1
1234567890001 95        2
1234567890003 95        2
1234567890002 77        4
1234567890004 85        5
*/
    int cnt;
    for (int i = 0; i < N; i++) {   //N个考场

        scanf("%d", &cnt);  //考场人数
        cnt_all += cnt;

        for (int j = 0; j < cnt; j++) {
            scanf("%s %d", students[stu_index].id, &students[stu_index].score);
            students[stu_index].lacation = i + 1;
            stu_index++;
        }
        sort(students + start_index, students + start_index + cnt, cmp);  //先在各个考场内排名

        //确定每个考生在本考场的排名
        int people_pre = 1;
        students[start_index].local_rank = 1;  //本考场第一名
        for (int j = start_index + 1; j < start_index + cnt; j++) {
            people_pre++;
            if (students[j].score == students[j - 1].score) {
                students[j].local_rank = students[j - 1].local_rank;
            } else {
                students[j].local_rank = people_pre;
            }
        }

        start_index = stu_index;
    }

    //然后总排名
    sort(students, students + stu_index, cmp);

    //确定总排名
    int people_pre = 1;
    students[0].final_rank = 1;  //总排名第一名
    for (int j = 1; j < stu_index; j++) {
        people_pre++;
        if (students[j].score == students[j - 1].score) {
            students[j].final_rank = students[j - 1].final_rank;
        } else {
            students[j].final_rank = people_pre;
        }
    }

    //输出
    printf("%d\n", cnt_all);
    for (int i = 0; i < stu_index; i++) {
        printf("%s %d %d %d\n", students[i].id,
               students[i].final_rank,
               students[i].lacation,
               students[i].local_rank);
    }

    return 0;
}
