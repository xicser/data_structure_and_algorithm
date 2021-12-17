#include <iostream>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>

using namespace std;


class RandomizedSet {
private:
    unordered_set<int> uSet;
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if (!uSet.count(val)) {
            uSet.insert(val);
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val) {
        if (uSet.count(val)) {
            uSet.erase(val);
            return true;
        }
        else {
            return false;
        }
    }

    int getRandom() {
        int cnt = uSet.size();
        int random = rand() % cnt;    //产生0 ~ (cnt - 1)的随机数

        auto it = uSet.begin();
        for (int i = 1; i <= random; i++) {
            it++;
        }

        return *it;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
