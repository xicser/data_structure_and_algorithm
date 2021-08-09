/* 划拳 */

#include <iostream>
#include <stdio.h>

using namespace std;
//甲喊 甲划 乙喊 乙划
//5
//8 10 9 12
//5 10 5 10
//3 8 5 12
//12 18 1 13
//4 16 12 15
int main()
{
    int Acount = 0;
    int Bcount = 0;

    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int Ahan, Ahua, Bhan, Bhua;
        scanf("%d%d%d%d", &Ahan, &Ahua, &Bhan, &Bhua);

        if ((Ahan + Bhan == Ahua) && (Ahan + Bhan != Bhua)) {
            Bcount++;
        } else if ((Ahan + Bhan != Ahua) && (Ahan + Bhan == Bhua)) {
            Acount++;
        }
    }

    printf("%d %d\n", Acount, Bcount);

    return 0;
}
