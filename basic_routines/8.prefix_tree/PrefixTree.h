#ifndef PREFIXTREE_H
#define PREFIXTREE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//节点
class Node {
public:
    int pass;
    int end;
    Node *nexts[26];     //暂定所有的字符只包含26个小写字母

    Node(int pass, int end) {
        this->pass = pass;
        this->end = end;

        for (int i = 0; i < 26; i++) {
            nexts[i] = nullptr;
        }
        cout << this << " created" << endl;
    }
    ~Node() {
        cout << this << " deleted" << endl;
    }
};

class PrefixTree
{
public:
    PrefixTree();
    ~PrefixTree();

    void insertString(string str);              //添加一个字符串
    void deleteString(string str);
    int  searchStringCount(string str);         //检查str之前被加入过几次
    int  prefixStringCount(string prefix);      //所有加入的字符串中, 有几个是以pre这个字符串作为前缀

private:
    Node *root; //根节点
    vector<Node *> allNodes;
    void removeNodeFromList(Node *nodePtr);     //移除allNodes里某个节点地址

};

#endif // PREFIXTREE_H
