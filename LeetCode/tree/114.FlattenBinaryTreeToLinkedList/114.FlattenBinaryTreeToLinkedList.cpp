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
            //如果左子树为空, 说明当前根节点已经成链
            if (root->left == nullptr) {
                //则直接进到下一个节点
                root = root->right;
            }
            else {
                //先找到左子树的最右侧节点
                TreeNode* leftTreeRightestNode = root->left;
                while (leftTreeRightestNode->right != nullptr) {
                    leftTreeRightestNode = leftTreeRightestNode->right;
                }

                //把右子树接到左子树最右节点的右边
                leftTreeRightestNode->right = root->right;
                
                //把左子树挪到右子树
                root->right = root->left;
                
                //左子树变成空
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
