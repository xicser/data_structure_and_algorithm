#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = mapVal.find(key);
        if (it != mapVal.end()) {

            //把存在的这个元素拿下来, 然后放在头部
            list<int>::iterator lit;
            for (lit = listVal.begin(); lit != listVal.end(); lit++) {
                if (*lit == key) {
                    listVal.erase(lit);
                    break;
                }
            }
            //放在头部
            listVal.push_front(key);

            return mapVal[key];
        }
        return -1;
    }

    void put(int key, int value) {

        auto it = mapVal.find(key);

        //在里面
        if (it != mapVal.end()) {

            //先把原来那个删掉
            list<int>::iterator lit;
            for (lit = listVal.begin(); lit != listVal.end(); lit++) {
                if (*lit == key) {
                    break;
                }
            }
            listVal.erase(lit);
            mapVal.erase(key);

            //再重新插入
            listVal.push_front(key);
            mapVal[key] = value;
        }
        //不在里面
        else {
            if (listVal.size() < capacity) {
                listVal.push_front(key);
                mapVal[key] = value;
            }
            else {
                int key_back = listVal.back();

                //把尾部那个删了
                listVal.pop_back();
//                cout << listVal.size() << endl;

                mapVal.erase(key_back);
//                cout << mapVal.size() << endl;

                //再插入
                listVal.push_front(key);
                mapVal[key] = value;
            }
        }
    }

    void transList() {
        for(auto iter = listVal.begin(); iter != listVal.end(); iter++)
        {
            cout << *iter;
        }
        cout<<endl;
    }
    void transMap() {
        for(auto iter = mapVal.begin(); iter != mapVal.end(); iter++)
        {
            cout<< iter->first << " " << iter->second << endl;
        }
        cout<<endl;
    }

private:
    int capacity;
    list<int> listVal;
    unordered_map<int, int> mapVal;
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.transList(), cache.transMap();

    cache.put(2, 2);
    cache.transList(), cache.transMap();

    cache.get(1);       // 返回  1
    cache.transList(), cache.transMap();

    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.transList(), cache.transMap();

    cache.get(2);       // 返回 -1 (未找到)
    cache.transList(), cache.transMap();

    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.transList(), cache.transMap();

    cache.get(1);       // 返回 -1 (未找到)
    cache.transList(), cache.transMap();

    cache.get(3);       // 返回  3
    cache.transList(), cache.transMap();

    cache.get(4);       // 返回  4
    cache.transList(), cache.transMap();

    return 0;
}
