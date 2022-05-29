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
        
        int left = max(0, process(root->left));
        int right = max(0, process(root->right));

        this->maxSum = max(this->maxSum, root->val + left + right);

        return max(left, right) + root->val;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
