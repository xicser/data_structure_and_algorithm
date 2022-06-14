#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:
    Node* first = nullptr;
    Node* pre = nullptr;
    Node* cur = nullptr;

    void process(Node* node) {

        if (node == nullptr) {
            return;
        }

        process(node->left);

        if (pre == nullptr) {
            first = node;           //把第一个节点记下来
            pre = node;
        }
        else {
            cur = node;
            cur->left = pre;
            pre->right = cur;
            pre = cur;
        }

        process(node->right);
    }

public:
    Node* treeToDoublyList(Node* root) {

        if (root == nullptr) {
            return nullptr;
        }

        process(root);

        pre->right = first;
        first->left = pre;

        return first;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
