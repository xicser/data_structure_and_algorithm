#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
二分的三个点：
(1) while()
(2) 二分的判断条件
(3) 区间收缩的时候的+1问题
*/

//在严格递增的序列中查找target是否存在
int biSearchOrigin(vector<int>& array, int target)
{
    int left = 0, right = array.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        }

        if (array[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    //没找到
    return -1;
}


//在形如：1 2 3 3 3 3 4 4 5 6 8 的序列中，找第一个大于等于3的位置
int lowerSearch(vector<int>& array, int target)
{
    int left = 0, right = array.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] >= target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

//在形如：1 2 3 3 3 3 4 4 5 6 8 的序列中，找第一个大于3的位置
int upperSearch(vector<int>& array, int target)
{
    int left = 0, right = array.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (array[mid] > target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}


/*
lowerSearch和upperSearch的共性：寻找有序序列（元素可能重复）中从左到右，第一个满足某条件的位置
固定模板：
int solve(vector<int>& array, int target)
{
    int left = 0, right = array.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (条件成立) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}



*/


int main()
{
    //vector<int> array1 = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};
    //printf("%d %d\n", biSearchOrigin(array1, 6), biSearchOrigin(array1, 9));

    vector<int> array2 = {1, 3, 3, 3, 6};
    printf("%d %d %d\n", lowerSearch(array2, -1), lowerSearch(array2, 7), lowerSearch(array2, 3));

    vector<int> array3 = { 1, 3, 3, 3, 6 };
    printf("%d %d %d\n", upperSearch(array3, -1), upperSearch(array3, 7), upperSearch(array3, 3));
}
