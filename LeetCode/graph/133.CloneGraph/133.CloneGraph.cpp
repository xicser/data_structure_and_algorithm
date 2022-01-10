#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    ////使用广度优先
    //Node* cloneGraph(Node* node) {
    //    if (node == nullptr) {
    //        return nullptr;
    //    }

    //    queue<Node*> que;
    //    unordered_map<Node*, Node*> hasVisited;  //标记是否被访问过<原node, 拷贝出的node>

    //    Node* pCur = node;
    //    que.push(pCur);
    //    hasVisited[pCur] = new Node(pCur->val);

    //    while (!que.empty()) {

    //        pCur = que.front();
    //        que.pop();  //弹出就打印

    //        for (unsigned int i = 0; i < pCur->neighbors.size(); i++) {
    //            //如果没有被访问过
    //            if (hasVisited.find(pCur->neighbors[i]) == hasVisited.end()) {
    //                que.push(pCur->neighbors[i]);
    //                hasVisited[ pCur->neighbors[i] ] = new Node(pCur->neighbors[i]->val);
    //            }
    //            hasVisited[pCur]->neighbors.push_back( hasVisited[pCur->neighbors[i]] );
    //        }
    //    }

    //    return hasVisited[node];
    //}

    //使用深度优先
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        //如果当前这个节点已经被访问过了(已经被复制过了)
        if (hasVisited.find(node) != hasVisited.end()) {
            return hasVisited[node]; //返回node对应的复制node
        }

        Node* nodeNew = new Node(node->val);
        hasVisited[node] = nodeNew;

        for (Node* nextNode : node->neighbors) {
            nodeNew->neighbors.push_back( cloneGraph(nextNode) );
        }

        return nodeNew;
    }
private:
    unordered_map<Node*, Node*> hasVisited;  //标记是否被访问过<原node, 拷贝出的node>
};

int main()
{
    std::cout << "Hello World!\n";
}
