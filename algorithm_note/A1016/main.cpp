/*

Phone Bills

*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;


//费用
int expenses[24];
int fee_per_day = 0;        //一天打满电话的费用

//每条记录
typedef struct {
    char name[25];
    int month;
    int day;
    int hour;
    int minute;
    char status[10];
} Record_t;


bool cmp(Record_t ra, Record_t rb);
void cal_time_money(Record_t *ra, Record_t *rb, int *time, double *money);
int main()
{
    int N;

    //输入费用
    for (int i = 0; i < 24; i++) {
        scanf("%d", &expenses[i]);
        fee_per_day += expenses[i] * 60;
    }

    //输入记录
    scanf("%d", &N);
    Record_t records[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d:%d %s",
              records[i].name,
              &records[i].month, &records[i].day,
              &records[i].hour, &records[i].minute,
              records[i].status);
    }

    //先排序
    sort(records, records + N, cmp);

    int next;
    for (int i = 0; i < N; i += next) {

        //先判断有没有有效通话时间
        int needPrint = 0;
        next = 0;
        for (int j = i; strcmp(records[j].name, records[i].name) == 0; j++) {
            if (needPrint == 0 && strcmp(records[j].status, "on-line") == 0) {
                needPrint = 1;
            } else if (needPrint == 1 && strcmp(records[j].status, "off-line") == 0) {
                needPrint = 2;
            }
            next++;
        }

        if (needPrint == 2) { // = 2表明有有效通话时间
            printf("%s %02d\n", records[i].name, records[i].month); //先输出姓名和月份

            double total = 0;
            //开始查找并输出
            for (int j = i; j < i + next - 1; j++) {
                if (strcmp(records[j].status, "on-line") == 0 &&
                    strcmp(records[j + 1].status, "off-line") == 0) {

                    int time;
                    double money;
                    cal_time_money(&records[j], &records[j + 1], &time, &money); //计算时间和费用
                    total += money;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
                           records[j].day, records[j].hour, records[j].minute,
                           records[j + 1].day, records[j + 1].hour, records[j + 1].minute,
                           time, money);
                }
            }
            printf("Total amount: $%.2lf\n", total);
        }
    }

    return 0;
}

bool cmp(Record_t ra, Record_t rb)
{
    int res = strcmp(ra.name, rb.name);

    if (res != 0) return res < 0;
    else if (ra.month != rb.month) return ra.month < rb.month;
    else if (ra.day != rb.day) return ra.day < rb.day;
    else if (ra.hour != rb.hour) return ra.hour < rb.hour;
    else return ra.minute < rb.minute;
}

//01:05:59
//01:07:00
//61
//$12.10
void cal_time_money(Record_t *ra, Record_t *rb, int *time, double *money)
{
    int sum_a = 0, sum_b = 0;
    double sum_fee_a = 0, sum_fee_b = 0;

    //先计算从0时间一直通话到ra的时间所用费用
    int i;
    for (i = 0; i < ra->hour; i++) {
        sum_a += 60;
        sum_fee_a += expenses[i] * 60;
    }
    sum_a += ra->minute;
    sum_fee_a += expenses[i] * ra->minute;


    //再计算从0时间一直通话到rb的时间所用费用
    for (i = 0; i < rb->hour; i++) {
        sum_b += 60;
        sum_fee_b += expenses[i] * 60;
    }

    sum_b += rb->minute;
    sum_fee_b += expenses[i] * rb->minute;

    //如果不是同一天
    if (ra->day != rb->day) {
        sum_b += (rb->day - ra->day) * 24 * 60;
        sum_fee_b += fee_per_day * (rb->day - ra->day);
    }

    //相减得到结果
    *time = sum_b - sum_a;
    *money = (sum_fee_b - sum_fee_a) / 100;
}
