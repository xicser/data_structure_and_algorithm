#include <iostream>
#include <vector>

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
    int rob(TreeNode* root) {
        vector<int> val = robTree(root);
        return max(val[0], val[1]);
    }

private:
    //[0]表示 不偷 当前子树根结点能偷到的 最大价值
    //[1]表示   偷 当前子树根结点能偷到的 最大价值
    vector<int> robTree(TreeNode *root) {

        if (root == nullptr) {
            return {0, 0};
        }

        //向左子树要信息
        vector<int> left = robTree(root->left);

        //向右子树要信息
        vector<int> right = robTree(root->right);

        //偷根节点
        int stealRootVal = root->val + left[0] + right[0];

        //不偷根节点
        int noStealRootVal = max(left[0], left[1]) + max(right[0], right[1]);

        return {noStealRootVal, stealRootVal};
    }
};


int main()
{
    return 0;
}
