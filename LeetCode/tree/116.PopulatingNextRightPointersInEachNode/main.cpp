#include <iostream>
#include <queue>
#include <vector>

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
        vector < vector<Node *> > result;

        while (!que.empty()) {
            int size = que.size();
            vector<Node *> vec;

            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();

                vec.push_back(node);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }

        for (unsigned int i = 0; i < result.size(); i++) {
            for (unsigned int j = 0; j < result[i].size(); j++) {
                if (j == result[i].size() - 1) {
                    result[i][j]->next = nullptr;
                } else {
                    result[i][j]->next = result[i][j + 1];
                }
            }
        }

        return result[0][0];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
