#include <iostream>
#include <vector>

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
    int maxDepth(Node* root) {

        if (root == nullptr) {
            return 0;
        }

        int maxDeep = 0;
        for (unsigned int i = 0; i < root->children.size(); i++) {
            maxDeep = max(maxDepth(root->children[i]), maxDeep);
        }

        return maxDeep + 1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
