#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class LRUCache {
private:
    int capacity;
    list< pair<int, int> > listVal;                                  //<key, value>
    unordered_map<int, list< pair<int, int> >::iterator> mapVal;     //<key, key对应value在list中的迭代器>

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mapVal.count(key) == 0) {
            return -1;
        }

        //先把值取出来
        list< pair<int, int> >::iterator it = mapVal[key];
        int value = (*it).second;

        //然后放在list最前面, 表示这个value刚用过
        listVal.erase(it);
        listVal.push_front(pair<int, int>(key, value));

        //更新map
        mapVal[key] = listVal.begin();

        return value;
    }

    void put(int key, int value) {

        //满了, 且要插入新值
        if (mapVal.size() == this->capacity && mapVal.count(key) == 0) {

            pair<int, int> last = listVal.back();
            int key = last.first;
            listVal.pop_back();
            mapVal.erase(key);
        }

        //插入
        if (mapVal.count(key) == 0) {
            listVal.push_front(pair<int, int>(key, value));
            mapVal[key] = listVal.begin();
        }
        //更新
        else {
            //先把原来那个值在链表中删除
            list< pair<int, int> >::iterator it = mapVal[key];
            listVal.erase(it);

            //新值放在最开始
            listVal.push_front(pair<int, int>(key, value));

            //更新map
            mapVal[key] = listVal.begin();
        }
    }

    void transList() {
//        for(auto iter = listVal.begin(); iter != listVal.end(); iter++)
//        {
//            cout << *iter;
//        }
//        cout<<endl;
    }
    void transMap() {
//        for(auto iter = mapVal.begin(); iter != mapVal.end(); iter++)
//        {
//            cout<< iter->first << " " << iter->second << endl;
//        }
//        cout<<endl;
    }
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
