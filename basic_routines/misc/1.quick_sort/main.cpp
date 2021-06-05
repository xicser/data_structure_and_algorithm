#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <math.h>

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

/* ����v2.0 */
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

        int lessIndex = left - 1;           //С������
        int moreIndex = right + 1;          //��������

        //ѡȡ��Ԫ
        int num = A[left];                  //[<num, ==num, >num]

        for (int i = left; i != moreIndex; ) {

            if (A[i] == num) {
                //���ʱֱ������
                i++;
            }
            else if (A[i] < num) {
                //A[i]��С��������һ������, С��������, i++
                swap(&A[i], &A[lessIndex + 1]);
                lessIndex++;
                i++;
            }
            else {
                //A[i]�����������һ������, ������������, i����
                swap(&A[i], &A[moreIndex - 1]);
                moreIndex--;
            }
        }

        //���ش��������С������ı߽�
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

/* ����v3.0 */
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

        int lessIndex = left - 1;           //С������
        int moreIndex = right + 1;          //��������

        //ѡȡ�����Ԫ
        int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);
        int num = A[p];

        for (int i = left; i != moreIndex; ) {

            if (A[i] == num) {
                //���ʱֱ������
                i++;
            }
            else if (A[i] < num) {
                //A[i]��С��������һ������, С��������, i++
                swap(&A[i], &A[lessIndex + 1]);
                lessIndex++;
                i++;
            }
            else {
                //A[i]�����������һ������, ������������, i����
                swap(&A[i], &A[moreIndex - 1]);
                moreIndex--;
            }
        }

        //���ش��������С������ı߽�
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

        Comparator::sortArray(arr1, arrayLength); //�ö��������������������, һ������ȷ��
        Sort2::qSort(arr2, arrayLength);          //���Լ�������������

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

        Comparator::sortArray(arr1, arrayLength); //�ö��������������������, һ������ȷ��
        Sort3::qSort(arr2, arrayLength);          //���Լ�������������

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
    srand((int)time(0));  // �����������

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
