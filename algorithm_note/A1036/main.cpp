/*

Boys vs Girls

*/

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct {
    string name;
    char gender;
    string id;
    int grade;
} People;

int main()
{
    int N;
    scanf("%d", &N);

    People male_lowest, female_highest;
    male_lowest.grade = 101;
    female_highest.grade = -1;

    int male_cnt = 0, female_cnt = 0;
    for (int i = 0; i < N; i++) {
        People p_tmp;
        cin >> p_tmp.name >> p_tmp.gender >> p_tmp.id >> p_tmp.grade;

        if (p_tmp.gender == 'M') {
            male_cnt++;
            if (p_tmp.grade < male_lowest.grade) { //男生最低分
                male_lowest = p_tmp;
            }

        } else if (p_tmp.gender == 'F') {
            female_cnt++;
            if (p_tmp.grade > female_highest.grade) { //女生最高分
                female_highest = p_tmp;
            }
        }
    }

    if (male_cnt && female_cnt) {
        cout << female_highest.name << " " << female_highest.id << endl;
        cout << male_lowest.name << " " << male_lowest.id << endl;
        cout << female_highest.grade - male_lowest.grade << endl;

    } else if (male_cnt == 0 && female_cnt) {
        cout << female_highest.name << " " << female_highest.id << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    } else if (male_cnt && female_cnt == 0) {
        cout << "Absent" << endl;
        cout << male_lowest.name << " " << male_lowest.id << endl;
        cout << "NA" << endl;
    } else {
        cout << "Absent" << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    }

    return 0;
}
