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
private:
    int maxSum;

public:
    int maxPathSum(TreeNode* root) {
        this->maxSum = INT_MIN;
        process(root);
        return this->maxSum;
    }

    //函数含义: 返回一边包含root最大的
    int process(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int rootVal = root->val;
        int leftVal = max(process(root->left), 0);    //如果子树返回了负数, 那会越加越小, 那还不如不加, 即取0
        int rightVal = max(process(root->right), 0);

        //在遍历过程中更新maxSum
        this->maxSum = max(this->maxSum, rootVal + leftVal + rightVal);

        return max(leftVal + rootVal, rightVal + rootVal);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
