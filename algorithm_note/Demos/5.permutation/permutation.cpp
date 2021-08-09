#include <iostream>
#include <stdio.h>

using namespace std;


#define MAXN    (11)

int n = 10, P[MAXN];
bool hashTable[MAXN] = {false};

//生成全排列
void generateP(int index)
{
    if (index == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

static void reverseArr(int *arr, int start, int end);
static int returnIndex(int *arr, int arr_len);

//找到下一个排列
int findNearestNumber(int *arr_in, int arr_in_len)
{
    int index = returnIndex(arr_in, arr_in_len);
    if(index == 0) return 0; //没找到, 已经是最后一个了

    for(int i = arr_in_len - 1; i >= index; i--) {

        if(arr_in[index - 1] < arr_in[i]) {

            int tmp = arr_in[index - 1]; //交换
            arr_in[index - 1] = arr_in[i];
            arr_in[i] = tmp;
            break;
        }
    }

    reverseArr(arr_in, index, arr_in_len - 1);

    return 1;
}

//逆序
static void reverseArr(int *arr, int start, int end)
{
    while(start <= end) {
        int tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}
//从后向前遍历找出arr[i] > arr[i-1]的下标i
static int returnIndex(int *arr, int arr_len)
{
    for (int i = arr_len - 1; i > 0; i--) {
        if(arr[i] > arr[i-1]) {
            return i;
        }
    }
    return 0;
}
