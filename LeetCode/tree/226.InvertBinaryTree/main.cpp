#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *rootLeft = invertTree(root->left);
        TreeNode *rootRight = invertTree(root->right);

        root->left = rootRight;
        root->right = rootLeft;

        return root;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
