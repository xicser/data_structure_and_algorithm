
/*

德才论 Talent and Virtue

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string.h>

using namespace std;

/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/

//学生信息
typedef struct {
    char id[10];
    int de_score;
    int cai_score;
    int sum_score;
    int flag;       //flag表示属于哪类考生
} Student_t;

Student_t students[100005];
int stu_index = 0;

bool cmp_flag(Student_t a, Student_t b);
bool cmp_class_1(Student_t a, Student_t b);

int main(void)
{
    int N, L, H;

    //记录每种学生的个数
    int class_1 = 0, class_2 = 0, class_3 = 0, class_4 = 0;

    scanf("%d%d%d", &N, &L, &H);
    getchar();

/*
即德分和才分均不低于 L 的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，
按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。
*/
    //输入
    for (int i = 0; i < N; i++) {
        Student_t stu_tmp;
        scanf("%s%d%d", stu_tmp.id, &stu_tmp.de_score, &stu_tmp.cai_score);
        getchar();

        //先滤掉不合格的
        if (stu_tmp.de_score < L || stu_tmp.cai_score < L) {
            continue;
        }

        //分类
        bool is_record = false;
        int _flag;
        if (stu_tmp.de_score >= H && stu_tmp.cai_score >= H) { //才德全尽
            is_record = true;
            _flag = 1;
            class_1++;
        } else if (stu_tmp.de_score >= H && stu_tmp.cai_score < H) { //德胜才
            is_record = true;
            _flag = 2;
            class_2++;
        } else if (stu_tmp.de_score < H && stu_tmp.cai_score < H && stu_tmp.de_score >= stu_tmp.cai_score)
        { //“才德兼亡”但尚有“德胜才”者
            is_record = true;
            _flag = 3;
            class_3++;
        } else { //其他
            is_record = true;
            _flag = 4;
            class_4++;
        }
        if (is_record) {
            strcpy(students[stu_index].id, stu_tmp.id);
            students[stu_index].de_score = stu_tmp.de_score;
            students[stu_index].cai_score = stu_tmp.cai_score;
            students[stu_index].sum_score = stu_tmp.de_score + stu_tmp.cai_score;
            students[stu_index].flag = _flag;
            stu_index++;
        }
    }

    //如果没有满足条件的人, 直接返回
    if (stu_index == 0) {
        printf("0\n");
        return 0;
    }

    //先按照flag排序
    sort(students, students + stu_index, cmp_flag);

    //每个级别的学生分别排序
    sort(students, students + class_1, cmp_class_1);
    sort(students + class_1, students + class_1 + class_2, cmp_class_1);
    sort(students + class_1 + class_2, students + class_1 + class_2 + class_3, cmp_class_1);
    sort(students + class_1 + class_2 + class_3, students + class_1 + class_2 + class_3 + class_4, cmp_class_1);

    //输出合格学生人数
    printf("%d\n", stu_index);
    for (int i = 0; i < stu_index; i++) {
        printf("%s %d %d\n", students[i].id, students[i].de_score, students[i].cai_score);
    }

    return 0;
}

bool cmp_flag(Student_t a, Student_t b)
{
    return a.flag < b.flag;
}
bool cmp_class_1(Student_t a, Student_t b)
{
    if (a.sum_score != b.sum_score) {
        return a.sum_score > b.sum_score;
    } else { //总分一样

        if (a.de_score != b.de_score) {
            return a.de_score > b.de_score;
        } else {
            //德分也一样
            return strcmp(a.id, b.id) < 0;
        }
    }
}
