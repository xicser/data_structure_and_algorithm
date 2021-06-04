#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

//������
class Comparator {

public:
	static void sortArray(int *arr, int len) {
		sort(arr, arr + len);
	}

	// �����������
	static int *generateRandomArray(int maxSize, int maxValue, int *arrayLength) {
		int arrayLen = rand() % maxSize + 1;
		int *arr = new int[arrayLen];
		for (int i = 0; i < arrayLen; i++) {
			arr[i] = rand() % maxValue;
		}
		*arrayLength = arrayLen;
		return arr;
	}

	// ��������
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

	// ��ӡ����
	static void printArray(int *arr, int len) {
		if (arr == nullptr) {
			return;
		}
		for (int i = 0; i < len; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	// ������������Ƿ����
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

/* ����v1.0 */
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
        int temp = A[right]; //�����Ҳ��Ǹ�Ԫ���ȼ�����

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

int main()
{
    srand((int)time(0));  // �����������

    int testTime = 500000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    int arrayLength;
    for (int i = 0; i < testTime; i++) {
        int arrayLength;
        int *arr1 = Comparator::generateRandomArray(maxSize, maxValue, &arrayLength);
        int *arr2 = Comparator::copyArray(arr1, arrayLength);

        Comparator::sortArray(arr1, arrayLength); //�ö��������������������, һ������ȷ��
        Sort1::qSort(arr2, arrayLength);          //���Լ�������������

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

    int *arr = Comparator::generateRandomArray(maxSize, maxValue, &arrayLength);
    Comparator::printArray(arr, arrayLength);
    Sort1::qSort(arr, arrayLength);
    printf("\n");
    Comparator::printArray(arr, arrayLength);

    delete []arr;
    return 0;
}
