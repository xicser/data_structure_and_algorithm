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
    int longestUnivaluePath(TreeNode* root) {
        this->maxLen = 0;
        process(root);

        return this->maxLen;
    }

private:
    int maxLen;
    //获取一边的最长等值路径(含根节点)
    int process(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int leftLen = process(root->left);
        int rightLen = process(root->right);

        if (root->left != nullptr && root->val == root->left->val) {
            leftLen++;
        }
        else {
            leftLen = 0;
        }

        if (root->right != nullptr && root->val == root->right->val) {
            rightLen++;
        }
        else {
            rightLen = 0;
        }

        //遍历过程中, 记录最大的长度值
        this->maxLen = max(this->maxLen, leftLen + rightLen);

        //返回
        return max(leftLen, rightLen);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
