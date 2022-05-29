#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:

    typedef struct Node_t {
        int key;
        int value;
        Node_t(int k, int v) {
            key = k;
            value = v;
        }
    } Node_t;

    list<Node_t> lst;
    unordered_map<int, list<Node_t>::iterator> map;
    int capacity;
    int size;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key) {
        if (map.count(key) == 0) {
            return -1;
        }

        list<Node_t>::iterator it = map[key];
        key = it->key;
        int value = it->value;
        
        lst.erase(it);
        lst.push_front(Node_t(key, value));

        map[key] = lst.begin();

        return value;
    }

    void put(int key, int value) {

        //已经存在
        if (map.count(key) != 0) {
            list<Node_t>::iterator it = map[key];
            int key = it->key;

            lst.erase(it);
            lst.push_front(Node_t(key, value));

            map[key] = lst.begin();
        }
        else {
            //满了
            if (this->size == this->capacity) {

                Node_t last = lst.back();
                int k = last.key;
                lst.pop_back();
                map.erase(k);

                this->size--;
            }

            lst.push_front(Node_t(key, value));
            map[key] = lst.begin();
            this->size++;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
