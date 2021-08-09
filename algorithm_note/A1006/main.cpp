/*

Sign In and Sign Out

*/

#include <iostream>
#include <stdio.h>

using namespace std;


typedef struct {
    string name;
    string time_start, time_leave;
} People;

//把形如23:59:59的事件转换为秒数
int time2seconds(string time)
{
    int hour = (time[0] - 48) * 10 + (time[1] - 48);
    int minute = (time[3] - 48) * 10 + (time[4] - 48);
    int second = (time[6] - 48) * 10 + (time[7] - 48);

    return 3600 * hour + 60 * minute + second;
}

/* 比较两个人谁来的早 */
int cmp_who_early(People p1, People p2)
{
    int start_sec_p1, start_sec_p2;
    start_sec_p1 = time2seconds(p1.time_start);
    start_sec_p2 = time2seconds(p2.time_start);

    if (start_sec_p1 > start_sec_p2) {
        return 2;
    } else return 1;
}

/* 比较两个人谁走的晚 */
int cmp_who_late(People p1, People p2)
{
    int start_sec_p1, start_sec_p2;
    start_sec_p1 = time2seconds(p1.time_leave);
    start_sec_p2 = time2seconds(p2.time_leave);

    if (start_sec_p1 > start_sec_p2) {
        return 1;
    } else return 2;
}

int main()
{
    int N;
    scanf("%d", &N);
    People peoples[N];

    for (int i = 0; i < N; i++) {
        cin >> peoples[i].name >> peoples[i].time_start >> peoples[i].time_leave;
    }

    int start_earliest, leave_latest;
    People p_earliest, p_latest;
    p_earliest.time_start = "23:59:59";
    p_latest.time_leave = "00:00:00";

    for (int i = 0; i < N; i++) {
        //先找来的最早的
        if (cmp_who_early(peoples[i], p_earliest) == 1) {
            p_earliest = peoples[i];
            start_earliest = i;
        }

        //再找走的最晚的
        if (cmp_who_late(peoples[i], p_latest) == 1) {
            p_latest = peoples[i];
            leave_latest = i;
        }
    }

    cout << peoples[start_earliest].name << " " << peoples[leave_latest].name;

    return 0;
}
