#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

/*
主元的位置与排完序后该元素所在位置相同，
那么再满足它是它之前所有元素中最大的一个，
就可以断定它是主元
*/

int main()
{
    int a[100001], b[100001],
    c[100001]; //c[]用来记录可能的主元
    int n, cnt = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == b[i] && b[i] > max) {
            c[cnt++] = b[i];
        }
        if(b[i] > max) {
            max = b[i];
        }
    }

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", c[i]);
    }
    printf("\n");
}
