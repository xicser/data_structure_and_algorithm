/*

The Best Rank

*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define STU_ARRAY_LEN (1000000)

typedef struct {
    int score;
    int rank;
    char name[3];
} Score_t;

typedef struct {
    Score_t scores[4];
//    C, M, E, A;
//    C_rank, M_rank, E_rank, A_rank;

    bool isExist;
} Student_t;

Student_t students[STU_ARRAY_LEN] = {0};  //数组下标表示id

bool cmp(Score_t sa, Score_t sb);
int myStrCmp(char *str1, char *str2);
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    //输入
    for (int i = 0; i < N; i++) {
        int tmp_id, tmp_C, tmp_M, tmp_E;
        scanf("%d %d %d %d", &tmp_id, &tmp_C, &tmp_M, &tmp_E);
        students[tmp_id].scores[0].score = tmp_C;
        strcpy(students[tmp_id].scores[0].name, "C");

        students[tmp_id].scores[1].score = tmp_M;
        strcpy(students[tmp_id].scores[1].name, "M");

        students[tmp_id].scores[2].score = tmp_E;
        strcpy(students[tmp_id].scores[2].name, "E");

        students[tmp_id].scores[3].score = (tmp_C + tmp_M + tmp_E) / 3;
        strcpy(students[tmp_id].scores[3].name, "A");

        students[tmp_id].isExist = true;
    }

    //M个查询
    for (int i = 0; i < M; i++) {
        int tmp_id;
        scanf("%d", &tmp_id);

        //如果数据不存在
        if (students[tmp_id].isExist == false) {
            printf("N/A\n");
            continue;
        }

        //先获取当前这个学生的C, M, E, A
        int cur_c = students[tmp_id].scores[0].score;
        int cur_m = students[tmp_id].scores[1].score;
        int cur_e = students[tmp_id].scores[2].score;
        int cur_a = students[tmp_id].scores[3].score;

        //默认都是第一名
        students[tmp_id].scores[0].rank = 1;
        students[tmp_id].scores[1].rank = 1;
        students[tmp_id].scores[2].rank = 1;
        students[tmp_id].scores[3].rank = 1;

        //开始查询整个数组以确定排名
        for (int j = 0; j < STU_ARRAY_LEN; j++) {
            if (students[j].isExist == true) {

                //C语言排名
                if (cur_c < students[j].scores[0].score) {
                    students[tmp_id].scores[0].rank++; //排名后退一下
                }

                //数学排名
                if (cur_m < students[j].scores[1].score) {
                    students[tmp_id].scores[1].rank++;
                }

                //英语排名
                if (cur_e < students[j].scores[2].score) {
                    students[tmp_id].scores[2].rank++;
                }

                //平均分排名
                if (cur_a < students[j].scores[3].score) {
                    students[tmp_id].scores[3].rank++;
                }
            }
        }

        //输出
        //先复制一份, 再排序
        Score_t scores[4];
        memcpy(scores, students[tmp_id].scores, sizeof(students[tmp_id].scores));
        sort(scores, scores + 4, cmp); //排序
        printf("%d %s\n", scores[0].rank, scores[0].name);
    }

    return 0;
}

bool cmp(Score_t sa, Score_t sb)
{
    if (sa.rank == sb.rank) {

        return myStrCmp(sa.name, sb.name) < 0;

    } else return sa.rank < sb.rank;
}

//自己实现的strcmp
int myStrCmp(char *str1, char *str2)
{
    //先转换为正常的字典序
    for (int i = 0; str1[i]; i++) {
        switch (str1[i]) {
            case 'A': str1[i] = 'A'; break;
            case 'C': str1[i] = 'B'; break;
            case 'M': str1[i] = 'C'; break;
            case 'E': str1[i] = 'D'; break;
            default: break;
        }

    }
    for (int i = 0; str2[i]; i++) {
        switch (str2[i]) {
            case 'A': str2[i] = 'A'; break;
            case 'C': str2[i] = 'B'; break;
            case 'M': str2[i] = 'C'; break;
            case 'E': str2[i] = 'D'; break;
            default: break;
        }
    }

    return strcmp(str1, str2);
}
