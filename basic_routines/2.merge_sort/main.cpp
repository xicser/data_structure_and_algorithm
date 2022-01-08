#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

class Sort {
public:

    //合并有序数组
    static void merge(int *A, int left, int mid, int right) {

        if (left == mid && mid == right) {
            return;
        }

        int *help = new int[right - left + 1];
        int helpIndex = 0;

        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (A[i] <= A[j]) {
                help[helpIndex++] = A[i++];
            } else {
                help[helpIndex++] = A[j++];
            }
        }
        while (i <= mid) help[helpIndex++] = A[i++];
        while (j <= right) help[helpIndex++] = A[j++];

        //拷贝回A里面
        for (int k = 0; k < helpIndex; k++) {
            A[k + left] = help[k];
        }

        delete []help;
    }

    //递归方式
    static void mSortR(int *A, int len) {
        if (A == nullptr || len <= 1) {
            return;
        }

        //递归求解
        processR(A, 0, len - 1);
    }
    static void processR(int *A, int left, int right) {

        if (left >= right) {
            return;
        }

        int mid = (right - left) / 2 + left;
        processR(A, left, mid);
        processR(A, mid + 1, right);
        merge(A, left, mid, right);
    }

    //非递归方式
    static void mSortNoR(int *A, int len) {
        if (A == nullptr || len <= 1) {
            return;
        }

        int step = 2; //合并步长
        while (step / 2 <= len) {

            int times = len / step;
            for (int i = 0; i < times; i++) {

                merge(A, i * step,
                         i * step + step / 2 - 1,
                         i * step + step - 1);
            }

            step *= 2;
        }

        if (len % 2 != 0) {
            merge(A, 0, len - 2, len - 1);
        }
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
        Sort::mSortR(arr2, arrayLength);          //用自己的排序函数排序

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
        int *arr3 = Comparator::copyArray(arr1, arrayLength);;

        Comparator::sortArray(arr1, arrayLength); //用对数器里面的排序函数排序, 一定是正确的
        Sort::mSortNoR(arr2, arrayLength);        //用自己的排序函数排序

        if (Comparator::isEqual(arr1, arrayLength, arr2, arrayLength) == false) {
            succeed = false;
            Comparator::printArray(arr3, arrayLength);
            Comparator::printArray(arr1, arrayLength);
            Comparator::printArray(arr2, arrayLength);

            delete []arr1;
            delete []arr2;
            delete []arr3;
            break;
        }

        delete []arr1;
        delete []arr2;
        delete []arr3;
    }
    printf(succeed == true ? "Nice!\n" : "Fucking fucked!\n");
}

int main()
{
    srand((int)time(0));  // 产生随机种子

//42 12 21 44 90 90 31 26 40 39 24 52 94 11 98
//11 12 21 24 26 31 39 40 42 44 52 90 90 94 98
//12 21 26 31 42 44 90 90 24 39 40 52 11 94 98

    int A[] = {42, 12, 21, 44, 90, 90, 31, 26, 40, 39, 24, 52, 94, 11};
    Sort::mSortNoR(A, sizeof(A) / sizeof(int));
    //Sort::merge(A, 1, 1, 1);
    Comparator::printArray(A, sizeof(A) / sizeof(int));

//    test1();
//    test2();

    return 0;
}
