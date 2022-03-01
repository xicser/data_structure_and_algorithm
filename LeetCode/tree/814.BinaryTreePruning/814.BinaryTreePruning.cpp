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
private:
    //判断一棵树root，是否为全是0的树，同时剪枝
    bool process(TreeNode* root) {
        
        if (root == nullptr) {
            return true;
        }

        int val = root->val;
        bool left = process(root->left);
        bool right = process(root->right);

        if (left == true) {
            root->left = nullptr;
        }
        if (right == true) {
            root->right = nullptr;
        }

        //左右子树均全为0且当前根节点的值为0, 则表明本树也是全为0的树
        if (left == true && right == true && val == 0) {
            return true;
        }

        return false;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        return process(root) == true ? nullptr : root;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
