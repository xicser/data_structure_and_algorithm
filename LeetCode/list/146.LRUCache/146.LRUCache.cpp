#include <iostream>
#include <list>
#include <unordered_map>


using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> map; //key, value是list中元素的迭代器
    list<pair<int, int>> list;  //pair<key, value>

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.count(key) != 0) {
            
            //map[key]是对应值再list中的迭代器位置
            auto pos = map[key];
            int value = (*pos).second;

            //更新
            list.erase(pos);
            list.push_front(pair<int, int>(key, value));
            map[key] = list.begin();

            return value;
        }
        return -1;
    }

    void put(int key, int value) {

        //如果key已经存在
        if (map.count(key) != 0) {
            auto pos = map[key];
            list.erase(pos);

            list.push_front(pair<int, int>(key, value));
            map[key] = list.begin();
        }
        else {
            if (map.size() == capacity) {
                pair<int, int> last = list.back();
                
                //先把最后那个删除
                list.pop_back();
                map.erase(last.first);

                list.push_front(pair<int, int>(key, value));
                map[key] = list.begin();
            }
            else {
                list.push_front(pair<int, int>(key, value));
                map[key] = list.begin();
            }
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

