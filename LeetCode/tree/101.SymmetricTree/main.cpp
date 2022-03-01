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
    //如果left和right互为镜像, 返回true
    bool compare(TreeNode* left, TreeNode* right) {

        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr && right != nullptr) {
            return false;
        }
        if (left != nullptr && right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }

        return compare(left->left, right->right) == true &&
               compare(left->right, right->left) == true;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
