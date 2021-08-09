/*

World Cup Betting

*/

#include <iostream>

using namespace std;


int main()
{
    double out_array[3];
    int index = 0;

    for (int i = 0; i < 3; i++) {

        double max_value = -1;
        int max_index;
        for (int j = 0; j < 3; j++) {
            double tmp;
            scanf("%lf", &tmp);
            if (tmp > max_value) {
                max_value = tmp;
                max_index = j;
            }
        }
        switch (max_index) {
            case 0: printf("W "); break;
            case 1: printf("T "); break;
            case 2: printf("L "); break;
            default: break;
        }

        out_array[index++] = max_value;
    }


    //¼ÆËãÊä³ö
    printf("%.2lf\n", (out_array[0] * out_array[1] * out_array[2] * 0.65 - 1) * 2);

    return 0;
}
