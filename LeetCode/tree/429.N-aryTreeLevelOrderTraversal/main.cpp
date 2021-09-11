#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> que;
        if (root != NULL) que.push(root);
        vector < vector<int> > result;

        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;

            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);

                for (unsigned int i = 0; i < node->children.size(); i++) {
                    que.push(node->children[i]);
                }
            }
            result.push_back(vec);
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
