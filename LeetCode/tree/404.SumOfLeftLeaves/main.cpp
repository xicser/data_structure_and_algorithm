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

        if (root == nullptr) {
            return 0;
        }

        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            return left + right + root->left->val;
        }

        return left + right;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
