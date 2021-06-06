#include <iostream>
#include <algorithm>

using namespace std;

// �󶥶�ʵ��
class MaxHeap {

public:

    static void heapSort(int *A, int len) {
        if (A == nullptr || len < 2) {
            return;
        }

        process(A, len);
    }

private:

    static void process(int *A, int len) {

        //�����ɴ����O(N * logN)
//        for (int i = 0; i < len; i++) {
//            heapInsert(A, i);
//        }
        //�����ɴ����O(N)
        for (int i = len - 1; i >= 0; i--) {
            heapify(A, i, len);
        }

		int heapSize = len;
		heapSize--;
		swap(A, 0, heapSize);
		// O(N*logN)
		while (heapSize > 0) { // O(N)
			heapify(A, 0, heapSize); // O(logN)
			swap(A, 0, --heapSize);  // O(1)
		}
    }

    // ���󶥶��������һ���ڵ�(�ϸ�)
    static void heapInsert(int *heapArray, int heapIndex) {
        if (heapIndex == 0) {
            return;
        }

        int father = (heapIndex - 1) / 2;
        while (1) {

            if (heapArray[father] < heapArray[heapIndex]) {
                swap(heapArray, father, heapIndex);
                heapIndex = father;
                //�����˸��ڵ�
                if (heapIndex == 0) {
                    break;
                }
            } else {
                break;
            }

            father = (father - 1) / 2;
        }
    }

    // �Ӹ��ڵ�λ��, ���¿�, ���ϵ��³�
    static void heapify(int *heapArray, int index, int heapSize) {

        if (heapSize == 0) {
            return;
        }

        int left = index * 2 + 1;
        while (left < heapSize) { // ���������, ��û���Һ���, �����п���û��
            // �ѽϴ��ӵ��±�, ��largest
            int largest = left + 1 < heapSize && heapArray[left + 1] > heapArray[left] ? left + 1 : left;
            largest = heapArray[largest] > heapArray[index] ? largest : index;
            if (largest == index) {
                break;
            }
            // index�ͽϴ���, Ҫ����
            swap(heapArray, largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }

    static void swap(int *arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

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

void test1()
{
    int testTime = 1000000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        int arrayLength;
        int *arr1 = Comparator::generateRandomArray(maxSize, maxValue, &arrayLength);
        int *arr2 = Comparator::copyArray(arr1, arrayLength);
        int *arr3 = Comparator::copyArray(arr1, arrayLength);;

        Comparator::sortArray(arr1, arrayLength); //�ö��������������������, һ������ȷ��
        MaxHeap::heapSort(arr2, arrayLength);     //���Լ�������������

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
    test1();

    return 0;
}
