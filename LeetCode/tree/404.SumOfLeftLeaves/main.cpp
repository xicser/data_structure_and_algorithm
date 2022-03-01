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
    int sumOfLeftLeaves(TreeNode* root) {
        val = 0;
        process(root);
        return val;
    }

private:
    int val;

    void process(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            val += root->left->val;
        }

        process(root->left);
        process(root->right);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
