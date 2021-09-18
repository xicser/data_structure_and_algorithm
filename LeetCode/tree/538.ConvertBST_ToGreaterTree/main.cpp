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
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        process(root);
        return root;
    }

private:
    int sum;
    void process(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        process(root->right);
        sum += root->val;
        root->val = sum;
        process(root->left);
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
