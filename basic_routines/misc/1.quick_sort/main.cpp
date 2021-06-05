#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <math.h>

using namespace std;

//对数器
class Comparator {

public:
	static void sortArray(int *arr, int len) {
		sort(arr, arr + len);
	}

	// 生成随机数组
	static int *generateRandomArray(int maxSize, int maxValue, int *arrayLength) {
		int arrayLen = rand() % maxSize + 1;
		int *arr = new int[arrayLen];
		for (int i = 0; i < arrayLen; i++) {
			arr[i] = rand() % maxValue;
		}
		*arrayLength = arrayLen;
		return arr;
	}

	// 复制数组
    static int *copyArray(int *arr, int len) {
		if (arr == nullptr) {
			return nullptr;
		}
		int *res = new int[len];
		for (int i = 0; i < len; i++) {
			res[i] = arr[i];
		}
		return res;
	}

	// 打印数组
	static void printArray(int *arr, int len) {
		if (arr == nullptr) {
			return;
		}
		for (int i = 0; i < len; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	// 检测两个数组是否相等
    static bool isEqual(int *arr1, int length1, int *arr2, int length2) {
		if ((arr1 == nullptr && arr2 != nullptr) || (arr1 != nullptr && arr2 == nullptr)) {
			return false;
		}
		if (arr1 == nullptr && arr2 == nullptr) {
			return true;
		}
		if (length1 != length2) {
			return false;
		}
		for (int i = 0; i < length1; i++) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}
};

/* 快排v1.0 */
class Sort1 {

public:
    static void qSort(int *A, int len) {
        if (len <= 0) {
            return;
        }

        process(A, 0, len - 1);
    }

private:
    static int partition(int *A, int left, int right) {
        int temp = A[right]; //把最右侧那个元素先记下来

        while (left < right) {
            while (left < right && A[left] <= temp) {
                left++;
            }
            A[right] = A[left];

            while (left < right && A[right] > temp) {
                right--;
            }
            A[left] = A[right];
        }

        A[left] = temp;

        return left;
    }

    static void process(int *A, int left, int right) {
        if (left >= right) {
            return;
        }

        int pos = partition(A, left, right);
        process(A, left, pos - 1);
        process(A, pos + 1, right);
    }
};

/* 快排v2.0 */
class Sort2 {

private:
    static void swap(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    static void qSort(int *A, int len) {
        if (len <= 0) {
            return;
        }

        process(A, 0, len - 1);
    }

    static void partition(int *A, int left, int right, int *left_pos, int *right_pos) {

        int lessIndex = left - 1;           //小于区域
        int moreIndex = right + 1;          //大于区域

        //选取主元
        int num = A[left];                  //[<num, ==num, >num]

        for (int i = left; i != moreIndex; ) {

            if (A[i] == num) {
                //相等时直接跳过
                i++;
            }
            else if (A[i] < num) {
                //A[i]与小于区域右一个交换, 小于区右扩, i++
                swap(&A[i], &A[lessIndex + 1]);
                lessIndex++;
                i++;
            }
            else {
                //A[i]与大于区域左一个交换, 大于区域左扩, i不动
                swap(&A[i], &A[moreIndex - 1]);
                moreIndex--;
            }
        }

        //返回大于区域和小于区域的边界
        *left_pos = lessIndex;
        *right_pos = moreIndex;
    }

    static void process(int *A, int left, int right) {
        if (left >= right) {
            return;
        }

        int left_pos, right_pos;
        partition(A, left, right, &left_pos, &right_pos);
        process(A, left, left_pos);
        process(A, right_pos, right);
    }
};

/* 快排v3.0 */
class Sort3 {

private:
    static void swap(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    static void qSort(int *A, int len) {
        if (len <= 0) {
            return;
        }

        process(A, 0, len - 1);
    }

    static void partition(int *A, int left, int right, int *left_pos, int *right_pos) {

        int lessIndex = left - 1;           //小于区域
        int moreIndex = right + 1;          //大于区域

        //选取随机主元
        int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);
        int num = A[p];

        for (int i = left; i != moreIndex; ) {

            if (A[i] == num) {
                //相等时直接跳过
                i++;
            }
            else if (A[i] < num) {
                //A[i]与小于区域右一个交换, 小于区右扩, i++
                swap(&A[i], &A[lessIndex + 1]);
                lessIndex++;
                i++;
            }
            else {
                //A[i]与大于区域左一个交换, 大于区域左扩, i不动
                swap(&A[i], &A[moreIndex - 1]);
                moreIndex--;
            }
        }

        //返回大于区域和小于区域的边界
        *left_pos = lessIndex;
        *right_pos = moreIndex;
    }

    static void process(int *A, int left, int right) {
        if (left >= right) {
            return;
        }

        int left_pos, right_pos;
        partition(A, left, right, &left_pos, &right_pos);
        process(A, left, left_pos);
        process(A, right_pos, right);
    }
};

void test1()
{
    int testTime = 500000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        int arrayLength;
        int *arr1 = Comparator::generateRandomArray(maxSize, maxValue, &arrayLength);
        int *arr2 = Comparator::copyArray(arr1, arrayLength);

        Comparator::sortArray(arr1, arrayLength); //用对数器里面的排序函数排序, 一定是正确的
        Sort1::qSort(arr2, arrayLength);          //用自己的排序函数排序

        if (Comparator::isEqual(arr1, arrayLength, arr2, arrayLength) == false) {
            succeed = false;
            Comparator::printArray(arr1, arrayLength);
            Comparator::printArray(arr2, arrayLength);

            delete []arr1;
            delete []arr2;
            break;
        }

        delete []arr1;
        delete []arr2;
    }
    printf(succeed == true ? "Nice!\n" : "Fucking fucked!\n");
}

void test2()
{
    int testTime = 500000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        int arrayLength;
        int *arr1 = Comparator::generateRandomArray(maxSize, maxValue, &arrayLength);
        int *arr2 = Comparator::copyArray(arr1, arrayLength);

        Comparator::sortArray(arr1, arrayLength); //用对数器里面的排序函数排序, 一定是正确的
        Sort2::qSort(arr2, arrayLength);          //用自己的排序函数排序

        if (Comparator::isEqual(arr1, arrayLength, arr2, arrayLength) == false) {
            succeed = false;
            Comparator::printArray(arr1, arrayLength);
            Comparator::printArray(arr2, arrayLength);

            delete []arr1;
            delete []arr2;
            break;
        }

        delete []arr1;
        delete []arr2;
    }
    printf(succeed == true ? "Nice!\n" : "Fucking fucked!\n");
}

void test3()
{
    int testTime = 500000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        int arrayLength;
        int *arr1 = Comparator::generateRandomArray(maxSize, maxValue, &arrayLength);
        int *arr2 = Comparator::copyArray(arr1, arrayLength);

        Comparator::sortArray(arr1, arrayLength); //用对数器里面的排序函数排序, 一定是正确的
        Sort3::qSort(arr2, arrayLength);          //用自己的排序函数排序

        if (Comparator::isEqual(arr1, arrayLength, arr2, arrayLength) == false) {
            succeed = false;
            Comparator::printArray(arr1, arrayLength);
            Comparator::printArray(arr2, arrayLength);

            delete []arr1;
            delete []arr2;
            break;
        }

        delete []arr1;
        delete []arr2;
    }
    printf(succeed == true ? "Nice!\n" : "Fucking fucked!\n");
}

int main()
{
    srand((int)time(0));  // 产生随机种子

//    int A[] = {35, 18, 16, 72, 24, 65, 35, 88, 46, 28, 35};
//    int left_pos, right_pos;
//    Sort2::partition(A, 0, sizeof(A) / sizeof(int) - 1, &left_pos, &right_pos);
//    Comparator::printArray(A, sizeof(A) / sizeof(int));
//    printf("%d %d", left_pos, right_pos);


    test1();
    test2();
    test3();

    return 0;
}
