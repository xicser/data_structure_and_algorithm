#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() : root(0, 0) {
    }
    ~Trie() {
        for (unsigned int i = 0; i < allNodes.size(); i++) {
            delete allNodes[i];
        }
    }

    void insert(string word) {

        if (word.size() == 0) {
            return;
        }

        root.pass++; //根节点的pass表示总共有几个字符串

        Node_t *pCur = &root;
        for (unsigned int i = 0; i < word.size(); i++) {

            int path = word[i] - 'a';

            //如果没有这条路
            if (pCur->nexts[path] == nullptr) {

                Node_t *newNode = new Node_t(1, 0);
                allNodes.push_back(newNode);
                pCur->nexts[path] = newNode;
                pCur = newNode;
            }
            //有这条路
            else {
                pCur = pCur->nexts[path];
                pCur->pass++;
            }
        }
        pCur->end++;
    }

    bool search(string word) {

        Node_t *pCur = &root;
        for (unsigned int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if (pCur->nexts[path] == nullptr) {
                return false;
            }
            else {
                pCur = pCur->nexts[path];
            }
        }

        if (pCur->end != 0) {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        Node_t *pCur = &root;
        for (unsigned int i = 0; i < prefix.size(); i++) {
            int path = prefix[i] - 'a';
            if (pCur->nexts[path] == nullptr) {
                return false;
            }
            else {
                pCur = pCur->nexts[path];
            }
        }
        if (pCur->pass != 0) {
            return true;
        }
        return false;
    }

private:
    typedef struct Node_t {
        int pass;           //pass表示有几个string经过过
        int end;            //end不等于0, 表示有以end结尾的string
        Node_t *nexts[26];  //最多有26个小写英文字母
        Node_t(int _pass, int _end) {
            pass = _pass;
            end = _end;
            for (int i = 0; i < 26; i++) {
                nexts[i] = nullptr;
            }
        }
    } Node_t;

    Node_t root;        //根节点的pass表示当前前缀树中加入了几个string
    vector<Node_t *> allNodes;
};

int main()
{
    return 0;
}
