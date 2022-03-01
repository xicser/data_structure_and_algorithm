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
    int sum;
    void changeTree(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        changeTree(root->right);
        sum += root->val;
        root->val = sum;
        changeTree(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        changeTree(root);
        return root;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
