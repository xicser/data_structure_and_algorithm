#include <iostream>
#include <queue>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return {};
        }

        queue<Node *> que;
        if (root != nullptr) que.push(root);

        while (!que.empty()) {
            int size = que.size();

            Node *pre;
            for (int i = 0; i < size; i++) {

                Node* node = que.front();
                que.pop();

                if (i == 0) {
                    pre = node;
                }
                else {
                    pre->next = node;
                    pre = node;
                    if (i == size - 1) {
                        node->next = nullptr;
                    }
                }

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return root;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
