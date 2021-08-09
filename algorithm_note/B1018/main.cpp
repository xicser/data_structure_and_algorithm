/* 锤子剪刀布 */

#include <iostream>
#include <stdio.h>

using namespace std;

int findindex(int *array, int len) {

	int max_index = 0;
	for (int  i = 0; i < len; i++) {
		if (array[max_index] < array[i]) {
			max_index = i;
		}
	}

	return max_index;
}


void myGets(char *str)
{
    int i = 0;
    while (1) {
        char tmp = getchar();
        if (tmp != '\n') {
            str[i++] = tmp;
        } else break;
    }
    str[i] = 0;
}

int main(void)
{
    int i;
	int N;
	int A_win = 0, A_lose = 0, A_equal = 0;
	int B_win = 0, B_lose = 0, B_equal = 0;

	int A_wins[3] = {0}; //B C J
	int B_wins[3] = {0};

	scanf("%d", &N);
    getchar();

	for (i = 0; i < N; i++) {
		char str[10];
		myGets(str);
		char A_tmp = str[0], B_tmp = str[2];

		if (A_tmp == 'C' && B_tmp == 'C') {
			A_equal++;
			B_equal++;
		} else if (A_tmp == 'C' && B_tmp == 'J') {
			A_win++;
			A_wins[1]++;
			B_lose++;
		} else if (A_tmp == 'C' && B_tmp == 'B') {
			A_lose++;
			B_win++;
			B_wins[0]++;
		} else if (A_tmp == 'J' && B_tmp == 'C') {
			A_lose++;
			B_win++;
			B_wins[1]++;
		} else if (A_tmp == 'J' && B_tmp == 'J') {
			A_equal++;
			B_equal++;
		} else if (A_tmp == 'J' && B_tmp == 'B') {
			A_win++;
			A_wins[2]++;
			B_lose++;
		} else if (A_tmp == 'B' && B_tmp == 'C') {
			A_win++;
			A_wins[0]++;
			B_lose++;
		} else if (A_tmp == 'B' && B_tmp == 'J') {
			A_lose++;
			B_win++;
			B_wins[2]++;
		} else if (A_tmp == 'B' && B_tmp == 'B') {
			A_equal++;
			B_equal++;
		}
	}

	printf("%d %d %d\n%d %d %d\n", A_win, A_equal, A_lose, B_win, B_equal, B_lose);



	//printf("%d %d %d\n", A_wins[0], A_wins[1], A_wins[2]);
	//printf("%d %d %d", B_wins[0], B_wins[1], B_wins[2]);



	switch(findindex(A_wins, 3)) {
		case 0: printf("B"); break;
		case 1: printf("C"); break;
		case 2: printf("J"); break;
		default: break;
	}
	printf(" ");
	switch(findindex(B_wins, 3)) {
		case 0: printf("B"); break;
		case 1: printf("C"); break;
		case 2: printf("J"); break;
		default: break;
	}
	printf("\n");


    return 0;
}
