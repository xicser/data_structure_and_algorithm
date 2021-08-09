/* 部分A + B */

#include <iostream>
#include <stdio.h>

using namespace std;

//3862767 6 13530293 3
int main()
{
    int Pa = 0, Pb = 0;
    int Da, Db;
    int step = 1;
    char input[100];
    int aArray[11] = {0};
    int bArray[11] = {0};

//    fgets(input, 100, stdin);
    gets(input);
    printf("%s", input);


    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    for (int i = 0; input[i] != 0; i++) {

        switch (step) {
        case 1:
            if (input[i] != ' ') {
                aArray[ input[i] - 48 ]++;
            } else {
                step++;
            }
            break;
        case 2:
            if (input[i] != ' ') {
                Da = input[i] - 48;
            } else {
                step++;
            }
            break;
        case 3:
            if (input[i] != ' ') {
                bArray[ input[i] - 48 ]++;
            } else {
                step++;
            }
            break;
        case 4:
            if (input[i] != ' ') {
                Db = input[i] - 48;
            }
        }
    }

    //求Pa
    for (int i = 0, k = 1; i < aArray[Da]; i++) {
        Pa += Da * k;
        k *= 10;
    }

    //求Pb
    for (int i = 0, k = 1; i < bArray[Db]; i++) {
        Pb += Db * k;
        k *= 10;
    }


    printf("%d", Pa + Pb);



    return 0;
}
