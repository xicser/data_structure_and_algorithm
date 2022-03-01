#include <iostream>


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
    void flatten(TreeNode* root) {
        
        while (root != nullptr) {

            if (root->left == nullptr) {
                root = root->right;
            }
            else {
                //得到左子树的最右侧节点
                TreeNode* nodeRightest = root->left;
                while (1) {
                    if (nodeRightest->right == nullptr) {
                        break;
                    }
                    nodeRightest = nodeRightest->right;
                }

                //右子树接到nodeRightest右侧
                nodeRightest->right = root->right;

                root->right = root->left;
                root->left = nullptr;

                root = root->right;
            }
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
