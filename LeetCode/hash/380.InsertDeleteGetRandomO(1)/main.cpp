#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


class RandomizedSet {
private:
    unordered_map<int, int> valPos;
    vector<int> arr;

public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if (valPos.count(val) != 0) {
            return false;
        }

        valPos[val] = arr.size();  //��¼val���ֵ�������е�λ��
        arr.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (valPos.count(val) == 0) {
            return false;
        }

        int pos = valPos[val];
        if (pos != arr.size() - 1) {

            valPos.erase(arr[pos]);

            //������Ǹ���Ų����ǰҪɾ���Ǹ�����λ��
            arr[pos] = arr[arr.size() - 1];

            //����map
            valPos[ arr[pos] ] = pos;
        }
        else {
            valPos.erase(arr[arr.size() - 1]);
        }
        arr.pop_back();

        return true;
    }

    int getRandom() {
        return arr[ rand() % arr.size() ];
    }
};

/*
["RandomizedSet","insert","insert","insert","insert","insert","remove","insert","getRandom","insert","remove"]
    [[],           [0],       [2],    [1],     [1],     [1],     [0],     [0],      [],        [1],    [2]]

[null,              true,     true,   true,     false,  false,   true,    false,    2,          false,  true]
[null,              true,     true,   true,     false,  false,   true,    true,     2,          false,  true]
*/
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
