#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        int maxVal = max(p->val, q->val);
        int minVal = min(p->val, q->val);

        if (minVal < root->val && root->val < maxVal) {
            return root;
        }
        else if (minVal < root->val && maxVal < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
