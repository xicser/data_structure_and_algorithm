#include <iostream>

using namespace std;


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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        this->val = val;
        process(root);
        return root;
    }

private:
    int val;
    void process(TreeNode*& root) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            root = node;
            return;
        }

        if (val > root->val) {
            process(root->right);
        }
        else if (val < root->val) {
            process(root->left);
        }
        else {
            return;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
